#include "pthread_creator.h"

#include <mutex>
#include <cstring>

void create_thread_ex(pthread_t * thread, int inherit_sched, int policy, int priority, void *(*start_routine)(void*), void *arg, std::string name)
{
    pthread_attr_t thread_attr;
    if(int rc = pthread_attr_init(&thread_attr))
        throw std::runtime_error(std::string("pthread_attr_setinheritsched: ") + strerror(rc));
    if(int rc = pthread_attr_setinheritsched(&thread_attr, inherit_sched))
        throw std::runtime_error(std::string("pthread_attr_setinheritsched: ") + strerror(rc));
    if(int rc = pthread_attr_setschedpolicy(&thread_attr, policy))
        throw std::runtime_error(std::string("pthread_attr_setschedpolicy: ") + strerror(rc));
    sched_param schedparam; schedparam.sched_priority = priority;
    if(int rc = pthread_attr_setschedparam(&thread_attr, &schedparam))
        throw std::runtime_error(std::string("pthread_attr_setschedpolicy: ") + strerror(rc));

    if(int rc = pthread_create(thread, &thread_attr, start_routine, arg))
        throw std::runtime_error(std::string("pthread_create: ") + strerror(rc));
    if(int rc = pthread_attr_destroy(&thread_attr))
        throw std::runtime_error(std::string("pthread_attr_destroy: ") + strerror(rc));
    if(name.length()) if(int rc = pthread_setname_np(*thread, name.c_str()))
        throw std::runtime_error(std::string("pthread_setname_np: ") + strerror(rc));
}
