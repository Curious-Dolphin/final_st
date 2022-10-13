#include "common/pthread_creator.h"
#include "egm_sensor.h"

// Third party headers
#include "boost/filesystem.hpp"
#include <boost/algorithm/string.hpp>

// Standard library headers
#include <string.h>
#include <fstream>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>

static unsigned int g_idx_rob = 0;

// -----------------------------------------------------------------------------------------------------------------
Egm_Sensor::Egm_Sensor():
    m_abs_save_folder("/srv/ftp/seam-tracker")
{
    try{
        std::cout << "Building Egm_Sensor... " << std::endl;
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
            std::cout << "Unable to reuse Address" <<"\n";
        if (setsockopt(m_socket, SOL_SOCKET, SO_REUSEPORT, (const char*)&enable, sizeof(enable)) < 0) 
            perror("setsockopt(SO_REUSEPORT) failed");

        // --- PID controller Y coordinate ---
        m_pid_par_y.Kp = 1.25; // era 1.25 // Kp = 0.7 era prima della modifica
        m_pid_par_y.Td = 0;
        m_pid_par_y.Ti = 300; // Ti = 30
        m_pid_par_y.sat = m_y_corr_max;
        m_pid_par_y.sat_i = m_y_corr_max*m_pid_par_y.Ti/10;
        m_pid_par_y.deadzone_in = 0;
        m_pid_par_y.deadzone_out = 0;
        m_PID_y.set_params(m_pid_par_y);

        // --- PID controller theta_z coordinate ---
        m_pid_par_tz.Kp = 0.125; // era 0.075
        m_pid_par_tz.Td = 0;
        m_pid_par_tz.Ti = 25; // Ti = 20
        m_pid_par_tz.sat = m_tz_corr_max;
        m_pid_par_tz.sat_i = m_tz_corr_max;
        m_pid_par_tz.deadzone_in = 0;
        m_pid_par_tz.deadzone_out = 0;
        m_PID_tz.set_params(m_pid_par_tz);

        // --- SETUP logging ----
        m_PID_y.enable_log(m_abs_save_folder + "/img/log_pid_y");
        m_PID_tz.enable_log(m_abs_save_folder + "/img/log_pid_tz");

        std::cout << "Sensor Built!" << std::endl;
    }
    catch(std::exception & e){ std::cout << " Egm_Sensor::Egm_Sensor(): "<< e.what() << std::endl; }
}

// -----------------------------------------------------------------------------------------------------------------
Egm_Sensor::Egm_Sensor(Grey_Alg *ptr_alg): Egm_Sensor::Egm_Sensor()
{
    try{
        m_ptr_alg = ptr_alg;
        std::cout << "Algorithm Built in Sensor!" << std::endl;
    }
    catch(std::exception & e){ std::cout << " Egm_Sensor::Egm_Sensor(): "<< e.what() << std::endl; }
}

// -----------------------------------------------------------------------------------------------------------------
void Egm_Sensor::init()
{
    try{
        std::cout << "Initialising Egm_Sensor... " << std::endl;

        // --- Wobble Controller ---
        // uncomment if you need to launch the controller
        //m_wob_ctrl.init(m_wobble_serial_name);

        // --- Log file header ---
        m_log_file.open(m_abs_save_folder + "/img/" + m_log_file_name, std::ios::app);
        if (m_log_file.is_open() )
        {
            m_log_file << "#1) g_idx_rob" << '\t' << "2) t_rob_syn_us" << '\t'
                            << "3) x_egm" << '\t' << "4) y_egm" << '\t' << "5) tz_egm" << '\t'
                            << "6) dx" << '\t' << "7) dy" << '\t' << "8) dtz" << '\t'
                            << "9) y_error" <<'\t'<< "10) tz_error" <<'\t'
                            << "11) tz_seamW_avg" << '\t'<< "12) pos " <<  '\t'
                            << "13) w_gapW_int " << '\t' << "14) a_stm " <<'\n';
            m_log_file.close();
        }

        create_thread_ex(&m_thread_rob, PTHREAD_EXPLICIT_SCHED, SCHED_OTHER, g_priority_std, &Egm_Sensor::guide_pwrapper, this, "sensor_thread");
    }
    catch(std::exception & e){ std::cout << " Error in Egm_Sensor::init(): "<< e.what() << std::endl; }
}

// -----------------------------------------------------------------------------------------------------------------
void Egm_Sensor::join()
{
    try{
        pthread_join(m_thread_rob, nullptr);
    }
    catch(std::exception & e){ std::cout << " Error in Egm_Sensor::join(): "<< e.what() << std::endl; }
}

// -----------------------------------------------------------------------------------------------------------------
void* Egm_Sensor::guide()
{
    try{
        { std::unique_lock<std::mutex> lk (g_state_mtx); g_egm_state = Egm_State::STOPPED; }
        socklen_t addrlen = sizeof(m_serverAddr);
        // --- Bind socket ---
        printf("Binding EGM socket to address %s - port %d\n",inet_ntoa(m_serverAddr.sin_addr),ntohs(m_serverAddr.sin_port));
        if (bind(m_socket, (struct sockaddr *)&m_serverAddr, sizeof(m_serverAddr)) < 0) {
            perror("Bind has failed");
            throw std::string("EGM socket bind has failed");
        }

        // --- PARAMETRES INITIALISATION ---
        bool first_time = true;
        double x_start;
        double x_egm, y_egm, z_egm;
        double tz_egm;

        uint idx_start = 100;
        uint idx_len = m_time_move * m_f_egm;
        uint idx_end = idx_len + idx_start;
        bool comm_active = true;
        uint64_t t_rob_syn_us = 0, t_ctrl_us = 0;
        uint64_t t_rob_start_us = 0;
        double pos_bef = 0;

        // Synching
        usleep(1000*1000);
        while(!g_cam_ready)
            usleep(1000);
        g_rob_ready.store(true);
        g_cv.notify_all();

        // Start time
        std::chrono::steady_clock::time_point t0_egm = std::chrono::steady_clock::now();
        uint64_t Delta_t_egm = g_tThread_main.getTime();
        m_t_rob_thread.setZero(t0_egm);

        std::cout << "robot thread starts at " << Delta_t_egm << " us" << std::endl;
        std::cout << "Synching DONE" << std::endl;
        std::cout << "---- /// ROBOT READY /// ----" << std::endl;

        // --- CONTROL LOOP ---
        // goes on until theoretical motion stops
        while(comm_active)
        {
            if (g_egm_state != Egm_State::SIMULATE) {

                // --- Recieve Robot Message ---
                int n = recvfrom(m_socket, m_protoMessage, ROBBUFSIZE, 0, (struct sockaddr *)&m_robotAddr, &addrlen);
                uint64_t t_rob_syn_us_now = m_t_rob_thread.getTime();
                double dt_ms = (t_rob_syn_us_now - t_rob_syn_us)/1000.0;
                t_rob_syn_us = t_rob_syn_us_now;

                if (first_time)
                {std::unique_lock<std::mutex> lk (g_state_mtx); g_egm_state = Egm_State::GUIDE;}

                //printf(" from host %s on port %d",inet_ntoa(robotAddr.sin_addr),ntohs(robotAddr.sin_port));
                if (n < 0){printf(": ERROR while recieving"); continue;}

                // deserialize Robot message
                EgmRobot *pRobotMessage = new EgmRobot();
                pRobotMessage->ParseFromArray(m_protoMessage, n);

                x_egm = pRobotMessage->feedback().cartesian().pos().x();
                y_egm = pRobotMessage->feedback().cartesian().pos().y();
                z_egm = pRobotMessage->feedback().cartesian().pos().z();

                tz_egm = pRobotMessage->feedback().cartesian().euler().z()*DEG2RAD;

                // Write position to algorithm
                if (m_ptr_alg != nullptr)
                    m_ptr_alg->add_rob_pose(robCartesian{x_egm,y_egm,z_egm}, robEuler{0,0,tz_egm}, t_rob_syn_us_now);

                // Check for available seam position from algorithm and store it in buffer of world coordinate
                seamEstimate seam_estimate;
                bool got_estimate = false;
                if (m_ptr_alg != nullptr){
                    std::unique_lock<std::mutex> lck(g_mtx_seam);
                    got_estimate = m_ptr_alg->getNextEstimate(seam_estimate);
                }
                if(got_estimate)
                {
                    double x_seamW =  seam_estimate.p_seamW.at(0);
                    m_x_seamW_b.push_back( x_seamW );
                    m_y_seamW_b.push_back( seam_estimate.p_seamW.at(1) );
                    m_z_seamW_b.push_back( seam_estimate.p_seamW.at(2) );
                    m_tz_seamW_b.push_back(seam_estimate.theta_z_fitW);
                    m_w_gapW_b.push_back( seam_estimate.w_gapW );

                    m_t_img_sync_us_b.push_back( seam_estimate.t_img_sync_us );
                    //std::cout << "ROB --- seam buffer (" << m_x_seamW_b.size() << "): " << x_seamW << std::endl;
                }

                // --- Save Start Position ---
                if (first_time)
                {x_start = x_egm;}

                // --- Theoretical Trajectory with Trapezoidal Motion Law ---
                double pos = 0, vel = 0, acc = 0;
                if (g_idx_rob >= idx_start && g_idx_rob <= idx_end)
                {
                    if (g_idx_rob == idx_start)
                        t_rob_start_us = t_rob_syn_us_now;

                    //double xi = 1.0*(g_idx_rob - idx_start) / (1.0*idx_len);
                    double xi = 1.0 * (t_rob_syn_us_now-t_rob_start_us) / (m_time_move*1000.0*1000.0);
                    TrapezoidalAdimensionalLaw(xi, m_eps, pos, vel, acc);
                    DimensionalMotionLaw(m_rise_move, m_time_move, pos, vel, acc);
                }
                else if (g_idx_rob > idx_end && g_idx_rob <= idx_end + 10)
                    pos = m_rise_move;
                else if (g_idx_rob > idx_end + 10)
                { std::unique_lock<std::mutex> lk (g_state_mtx); g_egm_state = Egm_State::STOPPED; }


                // Calculate corrections
                double dx = 0, dy = 0, dz = 0;
                double a_wob = 0;
                double dtz = 0;
                double vx = 0, vy = 0, vz = 0;
                double y_error, tz_error;
                EgmSensor *pSensorMessage = new EgmSensor();
                double x_seamW_int = 0.0, y_seamW_int = 0.0, tz_seamW_avg = 0.0;
                double w_gapW_int = 0.0;

                if (g_egm_state == Egm_State::GUIDE)
                {
                    // --- Set Theoretical X trajectory ---
                    if (g_egm_state == Egm_State::GUIDE)
                    {
                        dx = x_start + pos - x_egm;
                        vx = vel;
                    }

                    // --- Checks for too high X corrections
                    if (dx > 2 && dx < -2)
                        throw std::string("dx is too high: missed datagrams");

                    // --- Turns on Laser ---
                    if (acc == 0.0 && vel != 0.0 && pos != 0.0 && m_ptr_alg->is_locked())
                    {
                        g_can_it_lase.store(true);
                        std::cout << "EGM - Laser ON \n";
                    }
                    else
                        g_can_it_lase.store(false);

                    // --- Interpolate current X and set Corrections ---
                    x_seamW_int = 0.0; y_seamW_int = 0.0; tz_seamW_avg = 0.0;
                    w_gapW_int = 0.0;

                    try {
                        if (m_x_seamW_b.size()>1) //TODO ascissa curvilinea
                        {
                            double alpha_int = 0.0;
                            double verse_x_motion = m_rise_move >= 0 ? 1.0: -1.0;
                            double x_adv = x_egm + verse_x_motion * m_v_steady * m_delay_egm_ms / 1000.0;
                            std::array<uint,2> idxs = Interpolate2X(x_adv, alpha_int);
                            //std::array<uint,2> idxs = InterpolateT(x_egm, m_delay_egm, alpha_int);

                            uint idx_pos_inf = idxs.at(0) , idx_pos_sup = idxs.at(1);

                            x_seamW_int = alpha_int * m_x_seamW_b.at(idx_pos_sup) + (1-alpha_int) * m_x_seamW_b.at(idx_pos_inf);
                            y_seamW_int = alpha_int * m_y_seamW_b.at(idx_pos_sup) + (1-alpha_int) * m_y_seamW_b.at(idx_pos_inf);
                            w_gapW_int =  alpha_int * m_w_gapW_b.at(idx_pos_sup)  + (1-alpha_int) * m_w_gapW_b.at(idx_pos_inf);
                            //tz_seamW_int = alpha_int * m_tz_seamW_b.at(idx_pos_sup) + (1-alpha_int) * m_tz_seamW_b.at(idx_pos_inf);

                            // Median filtering for theta_Z correction
                            auto it_end = m_tz_seamW_b.begin() + idx_pos_sup + 5;
                            auto it_beg = m_tz_seamW_b.begin() + idx_pos_inf - 5;
                            if (it_end > m_tz_seamW_b.end()-1 || it_beg <  m_tz_seamW_b.begin())
                                throw std::string("Too few points for theta_z average");
                            tz_seamW_avg = std::accumulate(it_beg, it_end,0.0) / std::distance(it_beg,it_end);

                            // Position control timing
                            uint64_t t_ctrl_now_us = m_t_rob_thread.getTime();
                            double dt_ctrl_ms;
                            if (t_ctrl_us != 0)
                                dt_ctrl_ms = (t_ctrl_now_us - t_ctrl_us)/1000.0;
                            else
                                dt_ctrl_ms = 0;
                            t_ctrl_us = t_ctrl_now_us;

                            // Control action of Y coordinate
                            //if (acc==0.0)
                            dy = m_PID_y.update(y_egm, y_seamW_int, dt_ctrl_ms);
                            //dy=0;
                            if (dy>m_y_corr_max || dy<-m_y_corr_max) {dy *= m_y_corr_max/abs(dy); std::cout << "Occio che il PID sbarella su Y\n";}

                            // Control action of theta_z
                            //if (acc==0.0)
                            dtz = m_PID_tz.update(tz_egm, tz_seamW_avg + CV_PI / 2.0, dt_ctrl_ms);
                            //dtz=0;                                                                          
                            if (dtz>m_tz_corr_max || dtz<-m_tz_corr_max) {dtz *= m_tz_corr_max/abs(dtz); std::cout << "Occio che il PID sbarella su theta_z\n";}

                            // Control action of wobble
                            a_wob = w_gapW_int;
                            if(a_wob > 3.0) {a_wob = 3; std::cout << "Occio che sbarella il gap\n";}
                            if(isnan(dy))       {dy=0;}
                            if(isnan(dtz))      {dtz=0;}
                            // Adds interpolated seam position to image of spot area
                            //bool addedSeam = addSeams2SpotImage(x_egm, y_egm, tz_egm, x_seamW_int, y_seamW_int);

                            // log interpolation indexes
 /*                          if (is_logging_buffers)
                            {
                                buffer_log_file.open(m_abs_save_folder + "/img/log_buff", std::ios::app);
                                if (buffer_log_file.is_open()){
                                    buffer_log_file  << idx_pos_sup << "_ " << idx_pos_inf << "_ " << m_x_seamW_b.at(idx_pos_sup) << "_ " << m_x_seamW_b.at(idx_pos_inf) << "_ "
                                                     << tz_egm << "_ " << tz_seamW_avg << "_ " << dtz*RAD2DEG << "_ "  ;
                                    buffer_log_file.close();
                                }
                            }


                            if(isnan(a_wob))    {a_wob=0;}
                        }
                        else {
                            if (is_logging_buffers)
                            {
                                buffer_log_file.open(m_abs_save_folder + "/img/log_buff", std::ios::app);
                                if (buffer_log_file.is_open()){
                                    buffer_log_file << "_ ";
                                    buffer_log_file.close();
                                }
                            }*/
                        }
                    } // try interpolate
                    catch(std::exception const & e){std::cout << "ROB --- Buffer error: " << e.what() << std::endl;  dy = 0; }
                    catch(std::string e){std::cout << "ROB --- " << e << std::endl; dy = 0; }

                    // --- Calculate Y and Z error
                    y_error = 0; tz_error = 0;
                    try {
                        double alpha_int = 0.0;
                        std::array<uint,2> idxs = InterpolateX(x_egm, alpha_int);

                        uint idx_pos_inf = idxs.at(0) , idx_pos_sup = idxs.at(1);

                        double y_seamW_spot =  alpha_int * m_y_seamW_b.at(idx_pos_sup)  + (1-alpha_int) * m_y_seamW_b.at(idx_pos_inf);
                        double tz_seamW_spot = alpha_int * m_tz_seamW_b.at(idx_pos_sup) + (1-alpha_int) * m_tz_seamW_b.at(idx_pos_inf);

                        y_error =   y_egm - y_seamW_spot;
                        std:: cout<<"dy: " << y_error << "\n";

                        tz_error =  tz_egm - (tz_seamW_spot + CV_PI / 2.0);
                        std::cout <<"dtz: " << tz_error<< "\n";
                    }
                    catch(std::exception const & e){std::cout << "ROB --- Buffer error: " << e.what() << std::endl;  dy = 0; }
                    catch(std::string e){std::cout << "ROB --- " << e << std::endl; dy = 0; }

                    // close buffer file
 /*                   if (is_logging_buffers)
                    {
                        buffer_log_file.open(m_abs_save_folder + "/img/log_buff", std::ios::app);
                        if (buffer_log_file.is_open()){
                            buffer_log_file << std::endl;
                            buffer_log_file.close();
                        }
                    }*/
                } // if (g_egm_state == Egm_State::GUIDE)

                // --- Write Message to Robot ---
                SetPositionCorrections(pSensorMessage, pRobotMessage, dx, dy, dz, dtz *RAD2DEG);
                //SetVelocity(pSensorMessage, vx, vy, vz);
                std::string messageBuffer;
                pSensorMessage->SerializeToString(&messageBuffer);

                // --- Send Message ---
                n = sendto(m_socket, messageBuffer.c_str(), messageBuffer.length(), 0, (struct sockaddr *)&m_robotAddr, sizeof(m_robotAddr));
                // printf("%d bytes sent\n", n);
                if (n < 0) {printf("Error send message\n");}

                // --- Control Wobble ---
                int a_stm = 0;
                //a_stm = m_wob_ctrl.communicate(a_wob);

                // --- Log corrections ---
                m_log_file.open(m_abs_save_folder + "/img/" + m_log_file_name, std::ios::app);
                if (m_log_file.is_open() && g_idx_rob >= idx_start && g_idx_rob < idx_end + 100 )
                {
                    m_log_file << g_idx_rob << '\t' << t_rob_syn_us_now << '\t'
                                    << x_egm << '\t' <<   y_egm << '\t' << tz_egm*RAD2DEG << '\t'
                                    << dx << '\t' << dy << '\t' << dtz*RAD2DEG << '\t'
                                    << y_error << '\t' << tz_error*RAD2DEG << '\t'
                                    << tz_seamW_avg*RAD2DEG << '\t' << pos << '\t'
                                    << w_gapW_int << '\t' << a_stm << '\n';
                    m_log_file.close();
                }

                // --- Release heap and set what needs be set ---
                delete pSensorMessage;
                delete pRobotMessage;
                first_time = false;
                g_idx_rob ++;
            }
            else {
                first_time = true;
                usleep(1000*m_refresh_rob_ms);
                if ((g_idx_rob++ % 1000) == 0)
                    std::cout << "Egm_State is STOPPED" << std::endl;
            }
        }
    }
    catch(std::exception & e){ std::cout << " Error in Egm_Sensor::guide(): "<< e.what() << std::endl; g_can_it_lase.store(false);}
}

// -----------------------------------------------------------------------------------------------------------------
void Egm_Sensor::SetPositionCorrections(EgmSensor* pSensorMessage,  const EgmRobot* pRobotMessage, double dx, double dy, double dz, double dtz_euler_deg)
{
    EgmHeader* header = new EgmHeader();

    header->set_mtype(EgmHeader_MessageType_MSGTYPE_CORRECTION);
    header->set_seqno(g_idx_rob);
    header->set_tm(GetTickCountUs()/1000ull);
    pSensorMessage->set_allocated_header(header);

    // Save cartesian position
    double x_old = pRobotMessage->feedback().cartesian().pos().x();
    double y_old = pRobotMessage->feedback().cartesian().pos().y();
    double z_old = pRobotMessage->feedback().cartesian().pos().z();

    // Save orientation Euler
    double tx_old = pRobotMessage->feedback().cartesian().euler().x();
    double ty_old = pRobotMessage->feedback().cartesian().euler().y();
    double tz_old = pRobotMessage->feedback().cartesian().euler().z();
    //std::cout << "ROB --- t_old = " << tz_old << std::endl;

    // Correct
    double x_new = dx + x_old;
    double y_new = dy + y_old;
    double z_new = dz + z_old;
    double tz_new = dtz_euler_deg + tz_old;

    // Position
    EgmCartesian *pc = new EgmCartesian();
    pc->set_x(x_new);
    pc->set_y(y_new);
    pc->set_z(z_new);

    // Orientation
    EgmEuler *pe = new EgmEuler();
    pe->set_x(tx_old);
    pe->set_y(ty_old);
    pe->set_z(tz_new);

    // Pose
    EgmPose *pcartesian = new EgmPose();
    pcartesian->set_allocated_euler(pe);
    pcartesian->set_allocated_pos(pc);

    // Planned
    EgmPlanned *planned = new EgmPlanned();
    planned->set_allocated_cartesian(pcartesian);
    pSensorMessage->set_allocated_planned(planned);
}

// -----------------------------------------------------------------------------------------------------------------
void Egm_Sensor::SetVelocity(EgmSensor* pSensorMessage, double vx, double vy, double vz)
{
    EgmCartesianSpeed *pcartesian = new EgmCartesianSpeed();
    pcartesian->add_value(vx);
    pcartesian->add_value(vy);
    pcartesian->add_value(vz);
    //pcartesian->add_value(0);
    //pcartesian->add_value(0);
    //pcartesian->add_value(0);

    EgmSpeedRef *pspeed = new EgmSpeedRef();
    pspeed->set_allocated_cartesians(pcartesian);

    pSensorMessage->set_allocated_speedref(pspeed);
}

// -----------------------------------------------------------------------------------------------------------------
void Egm_Sensor::DisplayRobotMessage(EgmRobot *pRobotMessage)
{
    if (pRobotMessage->has_header() && pRobotMessage->header().has_seqno() && pRobotMessage->header().has_tm() && pRobotMessage->header().has_mtype())
    {
        // printf("SeqNo=%d Tm=%u Type=%d\n", pRobotMessage->header().seqno(), pRobotMessage->header().tm(), pRobotMessage->header().mtype());
        if (pRobotMessage->has_feedback() && pRobotMessage->feedback().has_cartesian() && pRobotMessage->feedback().cartesian().has_pos())
        {
            double x_now = 9999.99, y_now = 9999.99, z_now = 9999.99;
            if (pRobotMessage->feedback().cartesian().pos().has_x() )
                x_now = pRobotMessage->feedback().cartesian().pos().x();
            if (pRobotMessage->feedback().cartesian().pos().has_y() )
                y_now = pRobotMessage->feedback().cartesian().pos().y();
            if (pRobotMessage->feedback().cartesian().pos().has_z() )
                z_now = pRobotMessage->feedback().cartesian().pos().z();
            printf("Robot position: [%.2f %.2f, %.2f]\n", x_now, y_now, z_now);
        }
        else
            printf("No position in message\n");
    }
    else
        printf("No header in message\n");
}

// -----------------------------------------------------------------------------------------------------------------
void Egm_Sensor::CycloidalAdimensionalLaw(double xi, double& pos, double& vel, double& acc)
{
    pos = xi - 1 / (2 * M_PI) * sin(2 * M_PI * xi);
    vel = 1 - cos(2 * M_PI * xi);
    acc = 2 * M_PI * sin(2 * M_PI * xi);
}

// -----------------------------------------------------------------------------------------------------------------
void Egm_Sensor::TrapezoidalAdimensionalLaw(double xi, double eps, double& pos, double& vel, double& acc)
{
    double cv = 1/(1-eps);
    double ca = cv/eps;

    if (xi <= eps)
    {
        acc = ca;
        vel = ca*xi;
        pos = 0.5*ca*xi*xi;
    }
    else if (xi < 1-eps)
    {
        acc = 0;
        vel = cv;
        pos = 0.5*ca*pow(eps,2) + cv*(xi-eps);
    }
    else if (xi >= 1-eps)
    {
        acc = -ca;
        vel = eps*ca-(xi-eps-(1-2*eps))*ca;
        pos = 0.5*ca*pow(eps,2)+eps*ca*(1-2*eps)+cv*(xi-(1-eps))-0.5*ca*pow(xi-(1-eps),2);
    }
}

// -----------------------------------------------------------------------------------------------------------------
void Egm_Sensor::DimensionalMotionLaw(double rise, double time, double& pos, double& vel, double &acc)
{
    pos = rise * pos;
    vel = rise / time * vel;
    acc = rise / time / time * acc;
}

// -----------------------------------------------------------------------------------------------------------------
bool Egm_Sensor::addSeams2SpotImage(double x_robW, double y_robW, double tz_robW, double x_seamW, double y_seamW)
{
    namespace fs = boost::filesystem;

    static int idx_last_image = 0;
    fs::path p ("/srv/ftp/seam_tracker/img/spot");
    fs::directory_iterator end_itr;
    int idx_image =  -1;
    bool found_new_img = false;
    std::string new_file;

    // Look for newer image
    for (fs::directory_iterator itr(p); itr != end_itr; ++itr){

        if (is_regular_file(itr->path())) {
            // assign current file name to current_file and echo it out to the console.
            std::string current_file = itr->path().string();

            std::vector<std::string> bof;
            std::string idx_str = boost::split(bof, current_file, boost::is_any_of("_."))[1];
            idx_image = std::stoi(idx_str);
            if (idx_image > idx_last_image)
            {
                found_new_img = true;
                new_file = current_file;
                idx_last_image = idx_image;
                break;
            }
        }
    }

    // Loads newest image
    cv::Mat img_spot;
    if (found_new_img)
        img_spot = cv::imread(new_file, cv::IMREAD_COLOR);
    else
        img_spot = cv::imread("/srv/ftp/seam_tracker/img/spot/img_" + std::to_string(idx_last_image) + ".bmp", cv::IMREAD_COLOR);

    // Draws last point on it
    int x_circle, y_circle;
    RotoTranW2I(x_robW, y_robW, tz_robW, x_seamW, y_seamW, x_circle, y_circle);
    cv::circle(img_spot, cv::Point(x_circle, y_circle), 3, cv::Scalar(0,255,0), 2);

    return found_new_img;
}


// -----------------------------------------------------------------------------------------------------------------
std::array<uint,2> Egm_Sensor::InterpolateX(double x_query, double& alpha_int)
{
        boost::circular_buffer<double>::iterator it_inf, it_sup;
        bool is_decreasing = (m_rise_move < 0);

        if(is_decreasing) {
            it_inf = std::lower_bound(m_x_seamW_b.begin(), m_x_seamW_b.end(), x_query, std::greater<double>()); // last value that is not greater than x_egm
            if (it_inf != m_x_seamW_b.begin()       // first element
                    && it_inf != m_x_seamW_b.end()) // not found
                it_sup = it_inf - 1;
            else
                throw std::string("x has not been seen yet (decrease)");
        }
        else {
            it_sup = std::lower_bound(m_x_seamW_b.begin(), m_x_seamW_b.end(), x_query, std::less<double>()); // last value that is not less than x_egm
            if (it_sup != m_x_seamW_b.begin()       // first element
                    && it_sup != m_x_seamW_b.end()) // not found
                it_inf = it_sup - 1;
            else
                throw std::string("x has not been seen yet (increase)");
        }

        // TODO che senso hanno sti controlli? se la triettoria X non è monotona
        if (it_sup == m_x_seamW_b.begin())
        {
            if (*(it_sup+1) < x_query) // decreasing vector
                it_inf = it_sup + 1;
            else
                throw std::string("x has not been seen yet: " + std::to_string(*it_sup) + " " + std::to_string(x_query));
        }
        else if (it_sup == m_x_seamW_b.end()-1)
        {
            if (x_query > *(it_sup-1)) // increasing vector
                it_inf = it_sup -1;
            else
                throw std::string("x has not been seen yet: " + std::to_string(*it_sup) + " " + std::to_string(x_query));
        }
        else if (it_sup == m_x_seamW_b.end())
            throw std::string("x has not been seen yet: it.begin() " + std::to_string(*m_x_seamW_b.begin()) + "egm " + std::to_string(x_query)) + " it.end()" + std::to_string(*(m_x_seamW_b.end()-1)) ;
        else
        {
            if (x_query > *(it_sup-1)) // increasing vector
                it_inf = it_sup - 1;
            else
                it_inf = it_sup + 1;
        }

        alpha_int = 1.0 * ( x_query - *it_inf ) / (*it_sup - *it_inf);

        uint idx_pos_sup = std::distance(m_x_seamW_b.begin(), it_sup);
        uint idx_pos_inf = std::distance(m_x_seamW_b.begin(), it_inf);

        return {idx_pos_inf, idx_pos_sup};
}

// -----------------------------------------------------------------------------------------------------------------
std::array<uint,2> Egm_Sensor::Interpolate2X(double x_query, double& alpha_int)
{
    double diff_min;
    auto it_inf = m_x_seamW_b.end();    // iterator with smaller index
    auto it_sup = m_x_seamW_b.end();    // iterator with higher index
    auto it_tmp = m_x_seamW_b.end();    // temporary iterator

    bool is_decreasing = (m_rise_move < 0);

    if(is_decreasing) // look for closest point that is smaller
    {
        diff_min = -999;
        for (auto it = m_x_seamW_b.begin(); it!= m_x_seamW_b.end(); it++)
        {
            double diff = *it - x_query;
            if (diff <= 0 && diff > diff_min)
            {
                diff_min = diff;
                it_tmp = it;
            }
        }

        if (it_tmp != m_x_seamW_b.end()) // found something
        {
            if (it_tmp != m_x_seamW_b.begin() && *(it_tmp-1) > x_query)
            {
                it_inf = it_tmp-1;
                it_sup = it_tmp;
            }
            else if (it_tmp != m_x_seamW_b.end()-1 && *(it_tmp + 1) > x_query)
            {
                it_inf = it_tmp;
                it_sup = it_tmp + 1;
            }
            else
                throw std::string("x has not been seen yet");
        }
        else
            throw std::string("x has not been seen yet");
    }

    else // look for closest point that is bigger than query
    {
        diff_min = 999;
        for (auto it = m_x_seamW_b.begin(); it!= m_x_seamW_b.end(); it++)
        {
            double diff = *it - x_query;
            if (diff >= 0 && diff < diff_min)
            {
                diff_min = diff;
                it_tmp = it;
            }
        }

        if (it_tmp != m_x_seamW_b.end()) // found something
        {
            if (it_tmp != m_x_seamW_b.begin() && *(it_tmp-1) < x_query)
            {
                it_inf = it_tmp-1;
                it_sup = it_tmp;
            }
            else if (it_tmp != m_x_seamW_b.end()-1 && *(it_tmp+1) < x_query)
            {
                it_inf = it_tmp;
                it_sup = it_tmp + 1;
            }
            else
                throw std::string("x has not been seen yet");
        }
        else
            throw std::string("x has not been seen yet");
    }

    uint idx_pos_sup = std::distance(m_x_seamW_b.begin(), it_sup);
    uint idx_pos_inf = std::distance(m_x_seamW_b.begin(), it_inf);

    alpha_int = 1.0 * ( x_query - *it_inf ) / (*it_sup - *it_inf);

    return {idx_pos_inf, idx_pos_sup};
}

// -----------------------------------------------------------------------------------------------------------------
std::array<uint,2> Egm_Sensor::InterpolateT(double x_egm, double delay_ms,  double& alpha_int)
{
    // find time of image of the seam corresponding to current tool location
    double alpha_x = 0.0;
    uint idx_pos_inf, idx_pos_sup;
    try {
        std::array<uint,2> idxs_x = InterpolateX(x_egm, alpha_x);
        idx_pos_inf = idxs_x.at(0);
        idx_pos_sup = idxs_x.at(1);
    }
    catch (...) {throw;}

    uint64_t t_seam_now_us = alpha_x * m_t_img_sync_us_b.at(idx_pos_sup)  + (1-alpha_x) * m_t_img_sync_us_b.at(idx_pos_inf);

    // find indexes of the point in advance of current position by delay
    uint64_t t_seam_adv_us = t_seam_now_us + delay_ms * 1000;

    boost::circular_buffer<uint64_t>::iterator it_sup, it_inf;

    it_sup = std::lower_bound(m_t_img_sync_us_b.begin(), m_t_img_sync_us_b.end(), t_seam_adv_us, std::less<double>()); // last value that is not less than x_egm

    if (it_sup != m_t_img_sync_us_b.begin()       // first element
            && it_sup != m_t_img_sync_us_b.end()) // not found
        it_inf = it_sup - 1;
    else
        throw std::string("x has not been seen yet (increase)");

    // TODO che senso hanno sti controlli doppi? il vettore del tempo è monotonao per forza
    if (it_sup == m_t_img_sync_us_b.begin())
    {
        if (*(it_sup+1) < x_egm) // decreasing vector
            it_inf = it_sup + 1;
        else
            throw std::string("x has not been seen yet: " + std::to_string(*it_sup) + " " + std::to_string(x_egm));
    }
    else if (it_sup == m_t_img_sync_us_b.end()-1)
    {
        if (x_egm > *(it_sup-1)) // increasing vector
            it_inf = it_sup -1;
        else
            throw std::string("x has not been seen yet: " + std::to_string(*it_sup) + " " + std::to_string(x_egm));
    }
    else if (it_sup == m_t_img_sync_us_b.end())
        throw std::string("x has not been seen yet: it.begin() " + std::to_string(*m_x_seamW_b.begin()) + "egm " + std::to_string(x_egm)) + " it.end()" + std::to_string(*(m_x_seamW_b.end()-1)) ;
    else
    {
        if (x_egm > *(it_sup-1)) // increasing vector
            it_inf = it_sup - 1;
        else
            it_inf = it_sup + 1;
    }

    alpha_int = 1.0 * ( x_egm - *it_inf ) / (*it_sup - *it_inf);

    idx_pos_sup = std::distance(m_t_img_sync_us_b.begin(), it_sup);
    idx_pos_inf = std::distance(m_t_img_sync_us_b.begin(), it_inf);

    return {idx_pos_inf, idx_pos_sup};
}
