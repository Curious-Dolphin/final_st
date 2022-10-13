#ifndef UDP_SERVER_H
#define UDP_SERVER_H

#include <arpa/inet.h>
#include <sys/socket.h>
#include "grey_alg.h"

#define PORT 6511
#define UDPBUFSIZE 1

class Udp_Server
{
public:
    Udp_Server();
    Udp_Server(Grey_Alg *ptr_alg);

    void init();
    void join();

private:
    void                                    *communicate();
    static void*                            communicate_pwrapper(void*  obj)       { return ((Udp_Server*)obj)->communicate(); }

    struct sockaddr_in                      m_serverAddr;
    struct sockaddr_in                      m_robotAddr;
    int                                     m_socket;
    char                                    m_UDPmessage [UDPBUFSIZE];
    std::string                             m_abs_save_folder;
    Grey_Alg*                               m_ptr_alg {nullptr};
    pthread_t                               m_thread_udp;
};

#endif // UDP_SERVER_H
