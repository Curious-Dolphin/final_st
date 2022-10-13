/* EGM sensor endnode:
 * 1) communication
 * 1.a) robot:
 * - establishes communication on UDP socket to robot
 * - serialises communications with Google ProtoBuffers
 * 1.b) MCU:
 * - launches USB communication as specified in "wobble_controller.h"
 *
 * 2) base robot trajectory
 * - moves along x axis with trapezoidal motion
 * - adds corrections determined as follows
 *
 * 3) robot corrections
 * - recieves feedback poses from the robot controller
 * - passes them over to vision algorithm
 * - recieves seam position in world reference system (RS) from the algorithm
 * - bufferises seam poses and calculates corrections for advanced TCP pose via interpolation (see chapter 6 of thesis)
 * - sends correction to robot controller thru EGM
 *
 * 4) wobble control
 * - recieves width estimates from algorithm
 * - bufferises seam widths and calculates the parameters for current TCP pose via interpolation (see chapter 6 of thesis)
 */

#ifndef EGM_SENSOR_H
#define EGM_SENSOR_H

// My headers
#include "common/common.h"
#include "egm.pb.h"
#include "grey_alg.h"
#include "pid_controller.h"
#include "wobble_controller.h"

// C++ includes
#include <arpa/inet.h>
#include <sys/socket.h>


#define PORT 6510
#define ROBBUFSIZE 1400

using namespace abb::egm;



// -----------------------------------------------------------------------------------------------------------------
class Egm_Sensor
{
public:
    Egm_Sensor();
    Egm_Sensor(Grey_Alg* ptr_alg);

    void init();
    void join();
    const threadTime    getTimeZero() {return m_t_rob_thread;}

private:
    void    SetPositionCorrections(EgmSensor* pSensorMessage,  const EgmRobot* pRobotMessage, double dx, double dy, double dz, double dtz_euler_deg=0);
    void    SetVelocity(EgmSensor* pSensorMessage, double vx, double vy, double vz);
    void    DisplayRobotMessage(EgmRobot* pRobotMessage);
    void    CycloidalAdimensionalLaw(double xi, double& pos, double& vel, double& acc);
    void    FishTrajectory();
    void    TrapezoidalAdimensionalLaw(double xi, double eps, double& pos, double& vel, double& acc);
    void    DimensionalMotionLaw(double rise, double time, double& pos, double& vel, double &acc);
    void*   guide();

    bool    addSeams2SpotImage(double x_robW, double y_robW, double tz_robW, double x_seamW, double y_seamW);

    std::array<uint,2>      InterpolateX(double x_query, double& alpha_int);
    std::array<uint,2>      Interpolate2X(double x_query, double& alpha_int);
    std::array<uint,2>      InterpolateT(double x_egm, double delay_ms, double& alpha_int);

    static void* guide_pwrapper(void*  obj)       { return ((Egm_Sensor*)obj)->guide(); }

    // EGM socket
    struct sockaddr_in      m_serverAddr;
    struct sockaddr_in      m_robotAddr;
    char                    m_protoMessage[ROBBUFSIZE]; // this way I can modify the string later
    pthread_t               m_thread_rob;
    int                     m_socket;

    Egm_State       m_egm_state {Egm_State::STOPPED};
    std::string     m_abs_save_folder;
    threadTime      m_t_rob_thread;
    Grey_Alg*       m_ptr_alg {nullptr};

    // Bufferz
    boost::circular_buffer<double>          m_x_seamW_b{100};  //TODO determine right buffer dimension
    boost::circular_buffer<double>          m_y_seamW_b{100};       //cambiato dimensione da 100 a 200
    boost::circular_buffer<double>          m_z_seamW_b{100};
    boost::circular_buffer<double>          m_tz_seamW_b{100};
    boost::circular_buffer<uint64_t>        m_t_img_sync_us_b{100};
    boost::circular_buffer<double>          m_w_gapW_b{100};

    // Trajectory
    double          m_rise_move{-200};                                          // [mm]
    double          m_v_steady{35};                                             // [mm/s]
    double          m_eps{0.1};                                               // trapezoidal law epsilon
    double          m_time_move {1/(1-m_eps) * abs(m_rise_move) / m_v_steady};  // motion duration
    double          m_f_egm {250};                                              // communication refresh time
    double          m_delay_egm_ms {30};
    std::array<cv::Point3i>  IdealTrajectory{};

    // PID controller
    //Kp, Ti,   Td,  sat_i, sat,   deadzone_in, deadzone_out
    PID_Parameters_t        m_pid_par_y;
    PID_Parameters_t        m_pid_par_tz;
    PID_Controller          m_PID_y{m_pid_par_y};
    PID_Controller          m_PID_tz{m_pid_par_tz};
    double                  m_y_corr_max{2};            // [mm]
    double                  m_tz_corr_max{1*DEG2RAD}; // [rad]

    // Wobble Controller
    Wobble_Controller       m_wob_ctrl;
    char                    m_wobble_serial_name[13] {"/dev/ttyACM0"};

    // logging
    std::ofstream           m_log_file;
    std::string             m_log_file_name {"log_egm"};

    uint                    m_refresh_rob_ms {1};

};

#endif // EGM_SENSOR_H
