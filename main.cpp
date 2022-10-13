// My headers
#include "common/common.h"
#include "ximea_camera.h"
#include "egm_sensor.h"
#include "udp_server.h"
#include "termios.h"
#include <boost/filesystem.hpp>

// Namespace
using namespace abb::egm;

// Extern variables grabbing
std::mutex g_state_mtx;
std::mutex g_mtx;
std::mutex g_mtx_seam;
Egm_State g_egm_state;
Cam_State g_cam_state;
std::atomic<bool> g_ready;
std::atomic<bool> g_cam_ready {false};
std::atomic<bool> g_rob_ready {false};
std::atomic<bool> g_udp_ready {false};
std::atomic<bool> g_can_it_lase {false};
int g_priority_std = 0;
std::condition_variable g_cv;

threadTime g_tThread_main;

double g_px_res = 18.228283734; //[µm/px]

//cv::Point g_spotC(1244,       919);
//cv::Rect g_roi_CI(g_spotC.x + 220, g_spotC.y - 250, 200, 500);    //55px = 1mm
//cv::Rect g_roi_IR(100,          50,       100, 400);

cv::Point g_spotC(1244,       750); // - (40,250)
cv::Rect g_roi_CI(g_spotC.x - 40, g_spotC.y - 250, 200 + 240 + 40, 500);    //55px = 1mm
cv::Rect g_roi_IR(100 + 240 + 40, 100,              100,            300);

/* If you want to change verse (towards negative/positive) along X direction:
 * 1) change g_roi_CI(g_spotC.x +220/-320, ...
 * 2) change g_roi_IR(100/0, ...
 * 3) change sign of move_rise in egm_sensor.cpp (-/+270)
 * 4) change sign of forerun in calculation of x_seamW in grey_alg.cpp ( +/- ( x_ ...
 */

// TODO
// 1) passare p_robW_int a grey_alg
// 2) Plottare la posizione del giunto riconosciuto sulla immagine dello spot
int main()
{
    std::cout << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::cout << "-- SEAM TRACKER / WELCOME --" << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::cout << std::endl;

    // erase save folder
    std::cout << "Erasing image folder... ";
    system("exec rm -r /srv/ftp/seam-tracker/img/*");
    boost::filesystem::create_directories("/srv/ftp/seam-tracker/img/*");

    g_tThread_main.setZero(std::chrono::steady_clock::now());

    Grey_Alg algorithm;  //TODO: set ROI better than this plz
    Grey_Alg* alg_ptr = algorithm.get_ptr();

    Ximea_Camera camera(alg_ptr);
    Egm_Sensor sensor(alg_ptr);
    Udp_Server server;

    camera.init();      // initialise before EGM (synching)
    sensor.init();
    server.init();      // initialise after EGM (synching)

    camera.join();
    sensor.join();
    server.join();

    std::cout << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::cout << "-- SEAM TRACKER / GOODBYE --" << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::cout << std::endl;

    return 0;
}
