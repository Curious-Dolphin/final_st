#ifndef COMMON_H
#define COMMON_H

#include <opencv2/opencv.hpp>
#include <atomic>
#include <fstream>
#include <condition_variable>
#include <mutex>

#define DEG2RAD CV_PI/180.0
#define RAD2DEG 180.0/CV_PI

enum class      Egm_State{STOPPED=0, SIMULATE=1, STREAM=2, GUIDE=3};
enum class      Cam_State{STOPPED=0, RUNNING=1, };
class           threadTime;

// Mutexes
extern std::mutex g_state_mtx;
extern std::mutex g_mtx;
extern std::mutex g_mtx_seam;

// States
extern Egm_State g_egm_state; // not implemented really
extern Cam_State g_cam_state; // not implemented really

// Multi-threading
extern std::condition_variable g_cv;
extern std::atomic<bool>    g_ready;
extern std::atomic<bool>    g_cam_ready;
extern std::atomic<bool>    g_rob_ready;
extern std::atomic<bool>    g_udp_ready;
extern std::atomic<bool>    g_can_it_lase;
extern int                  g_priority_std;
extern threadTime           g_tThread_main;

// Camera
extern double      g_px_res;    // [µm/px]
extern cv::Rect g_roi_CI;
extern cv::Rect g_roi_IR;
extern cv::Point g_spotC;

// Data types
class               timeZeroThread;
struct              seamEstimate;
typedef std::array<double,3> robCartesian;
typedef std::array<double,4> robQuaternion;
typedef std::array<double,3> robEuler;

static uint64_t GetTickCountUs(uint64_t t0_sec = 0, uint64_t t0_nsec = 0);
static uint64_t GetTickCountUs(std::chrono::steady_clock::time_point t_ref);
static double GetTickCountMs(std::chrono::steady_clock::time_point t_ref);


// -----------------------------------------------------------------------------------------------------------------
void RotoTranW2I(double x_robW, double y_robW, double t_robW, double x_seamW, double y_seamW, int &x_seamI, int &y_seamI);
void RotoTranI2W(double x_robW, double y_robW, double t_robW, double &x_seamW, double &y_seamW, int x_seamI, int y_seamI);


// -----------------------------------------------------------------------------------------------------------------
static uint64_t GetTickCountUs(uint64_t t0_sec, uint64_t t0_nsec)
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint64_t)(((uint64_t) ts.tv_nsec - t0_nsec)/1000ull) + (uint64_t)(((uint64_t)ts.tv_sec - t0_sec)* 1000ull * 1000ul );
}


// -----------------------------------------------------------------------------------------------------------------
static uint64_t GetTickCountUs(std::chrono::steady_clock::time_point t_ref)
{
    std::chrono::steady_clock::time_point t_now = std::chrono::steady_clock::now();
    std::chrono::microseconds t_us = std::chrono::duration_cast<std::chrono::microseconds>(t_now - t_ref);
    std::chrono::duration<uint64_t, std::micro> t_us_u = t_us;
    return t_us_u.count();
}


// -----------------------------------------------------------------------------------------------------------------
static double GetTickCountMs(std::chrono::steady_clock::time_point t_ref)
{
    std::chrono::steady_clock::time_point t_now = std::chrono::steady_clock::now();
    double t_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t_now - t_ref).count();
    return t_ms;
}


// -----------------------------------------------------------------------------------------------------------------
class threadTime{
public:
    threadTime() {is_initialised = false;}
    void setZero(std::chrono::steady_clock::time_point zero) {t0 = zero; is_initialised = true;}
    void unsetZero() {is_initialised = false;}
    const std::chrono::steady_clock::time_point getZero() {if (is_initialised) {return t0;} }
    uint64_t getTime() {if (is_initialised) {return GetTickCountUs(t0);} }
    bool isInitialised() {if (is_initialised) {return true;} else {return false;}}

private:
    std::chrono::steady_clock::time_point t0;
    bool is_initialised;
};


// -----------------------------------------------------------------------------------------------------------------
struct seamEstimate{
public:
    cv::Point       p_seamC;            // position of seam in full camera frame [px]
    uint64_t        t_img_sync_us;      // synchronised image time [µs]
    robCartesian    p_robW_int;         // position of robot in world referene at image time (interpolated)
    robCartesian    p_seamW;            // position of seam in world reference at image time
    double          theta_z_fitW;       // angle of fit line around z axis (estimated through m_par of linear fit)
    double          w_gapW;             // width of the gap as identified by the grey_alg expressed in mm
};


#endif // COMMON_H


