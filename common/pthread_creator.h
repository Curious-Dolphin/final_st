#ifndef PTHREAD_CREATOR_H
#define PTHREAD_CREATOR_H

#include <pthread.h>
#include <string>

void create_thread_ex(pthread_t * thread, int inherit_sched, int policy, int priority, void *(*start_routine)(void*), void *arg, std::string name);

#endif // PTHREAD_CREATOR_H
