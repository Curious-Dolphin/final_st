#include "common/common.h"
#include "common/pthread_creator.h"
#include "udp_server.h"

#include <sys/types.h>
#include <unistd.h>

// -----------------------------------------------------------------------------------------------------------------
Udp_Server::Udp_Server():
    m_abs_save_folder("/srv/ftp/seam-tracker")
{
    try{
        std::cout << "Building Udp_Server... " << std::endl;
        { std::unique_lock<std::mutex> lk (g_state_mtx); g_egm_state = Egm_State::STOPPED; }

        // --- Define socket ---
        socklen_t addrlen = sizeof(m_serverAddr);
        memset((char *)&m_serverAddr, 0, addrlen);
        m_serverAddr.sin_family = AF_INET;
        m_serverAddr.sin_addr.s_addr = inet_addr("10.168.214.25");  // computer address
        m_serverAddr.sin_port = htons(PORT);                        // computer port
        m_socket = socket(AF_INET, SOCK_DGRAM, 0);
        const int enable = 1;
        if (setsockopt(m_socket, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
            std::cout << "Unable to reuse address" <<"\n";
        if (setsockopt(m_socket, SOL_SOCKET, SO_REUSEPORT, (const char*)&enable, sizeof(enable)) < 0) 
            perror("setsockopt(SO_REUSEPORT) failed");

        std::cout << "Server Built!" << std::endl;
    }
    catch(std::exception & e){ std::cout << " Udp_Server::Udp_Server(): "<< e.what() << std::endl; }
}

// -----------------------------------------------------------------------------------------------------------------
Udp_Server::Udp_Server(Grey_Alg *ptr_alg): Udp_Server::Udp_Server()
{
    try{
        m_ptr_alg = ptr_alg;
        std::cout << "Algorithm Built in Sensor!" << std::endl;
    }
    catch(std::exception & e){ std::cout << " Udp_Server::Egm_Sensor(): "<< e.what() << std::endl; }
}

// -----------------------------------------------------------------------------------------------------------------
void Udp_Server::init()
{
    try{
        std::cout << "Initialising Udp_Server... " << std::endl;
        create_thread_ex(&m_thread_udp, PTHREAD_EXPLICIT_SCHED, SCHED_OTHER, g_priority_std, &Udp_Server::communicate_pwrapper, this, "udp_thread");
    }
    catch(std::exception & e){ std::cout << " Error in Udp_Server::init(): "<< e.what() << std::endl; }
}

// -----------------------------------------------------------------------------------------------------------------
void Udp_Server::join()
{
    try{
        pthread_join(m_thread_udp, nullptr);
    }
    catch(std::exception & e){ std::cout << " Error in Udp_Server::join(): "<< e.what() << std::endl; }
}

// -----------------------------------------------------------------------------------------------------------------
void* Udp_Server::communicate()
{
    try{
        { std::unique_lock<std::mutex> lk (g_state_mtx); g_egm_state = Egm_State::STOPPED; }
        socklen_t addrlen = sizeof(m_serverAddr);
        // --- Bind socket ---
        printf("Binding UDP socket to address %s - port %d\n",inet_ntoa(m_serverAddr.sin_addr),ntohs(m_serverAddr.sin_port));
        if (bind(m_socket, (struct sockaddr *)&m_serverAddr, sizeof(m_serverAddr)) < 0) {
            perror("Bind has failed");
            return 0;
        }

        // SYNCHING
        // std::unique_lock<std::mutex> lck(g_mtx);
        // std::cout << "Udp Server Synching ..." << std::endl;
        // g_udp_ready.store(true);
        // g_cv.wait(lck, []() { return (g_rob_ready && g_udp_ready && g_cam_ready);});

        std::cout << "---- /// UDP_SERVER READY ///----" << std::endl;
        int n = recvfrom(m_socket, m_UDPmessage, UDPBUFSIZE, 0, (struct sockaddr *)&m_robotAddr, &addrlen);
        std::cout << "UDP Server: recieved first message" << std::endl;

        uint count = 0;
        bool said_laserOFF = false;
        std::chrono::steady_clock::time_point t_bef = std::chrono::steady_clock::now();
        while (true)
        {
            // --- Controls Laser ---
            char messageBuffer[UDPBUFSIZE];
            if (g_can_it_lase.load() == false){
                *messageBuffer = '0';
                if (!said_laserOFF) {
                    std::cout << "UDP Server: laser OFF" << std::endl;
                    said_laserOFF = true;
                }
            }
            else {
                *messageBuffer = '1';
                if (said_laserOFF)
                {
                    std::cout << "UDP Server: laser ON" << std::endl;
                    said_laserOFF = false;
                }
            }

            // --- Sent Message ---
            n = sendto(m_socket, messageBuffer, UDPBUFSIZE, 0, (struct sockaddr *)&m_robotAddr, sizeof(m_robotAddr));
            if (n < 0) {printf("Error send message %d\n", count);}
            usleep(1000*10);
        }
    }
    catch(std::exception & e){ std::cout << " Error in Udp_Server::communicate(): "<< e.what() << std::endl; g_can_it_lase.store(false);}
}
