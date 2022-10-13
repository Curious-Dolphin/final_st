#ifndef XIMEA_CAMERA_H
#define XIMEA_CAMERA_H

// external include
#include "common/common.h"
#include "pid_controller.h"
#include "grey_alg.h"
#include "xiApiPlusOcv.hpp"
#include <chrono>


# define N_EXPECTED_IMG 500

class Ximea_Camera
{
public:
    Ximea_Camera();
    Ximea_Camera(Grey_Alg* ptr_alg);

    void                        init();
    void                        join();
    const threadTime            getTimeZero() {return m_t_cam_thread;}

    enum class                  Acquisition_State{STOPPED=0, MEASURE=1};

private:
    void*           acquire();
    int             calculateAutoExposure(cv::Point p_seamI);
    void            setAutoExposure(cv::Point p_seamI);
    void            useRoi();
    static void*    acquire_pwrapper(void*  obj)       { return ((Ximea_Camera*)obj)->acquire(); }

    int                      m_buff_size_MB {100};
    int                      m_buff_size_pics {100};  // -1 means as many as possible
    int                      m_x_roi;//{1150}; //TODO occhio alla ROI
    int                      m_y_roi;//{644};
    int                      m_w_roi;//{784};
    int                      m_h_roi;//{600};
    HANDLE                   m_hCam;
    xiAPIplusCameraOcv       m_cam;

    Acquisition_State                               m_acquisition_state;
    pthread_t                                       m_thread_cam;
    std::string                                     m_abs_save_folder;
    uint                                            m_refresh_cam_ms {1};
    float                                           m_frequency{100};
    threadTime                                      m_t_cam_thread;
    uint64_t                                        m_t_stamp0_ns;
    uint64_t                                        m_tCam0_us;
    Grey_Alg*                                       m_ptr_alg {nullptr};

    int             m_roi_aeag_w {100};
    int             m_roi_aeag_h {300};
    int             m_roi_aeag_x {g_roi_CI.width-100};
    int             m_roi_aeag_y {(g_roi_CI.height - m_roi_aeag_h) / 2};
    cv::Rect        m_roi_aeag{m_roi_aeag_x, m_roi_aeag_y, m_roi_aeag_w, m_roi_aeag_h};
    cv::Mat         m_img_aeag{m_roi_aeag_w, m_roi_aeag_h, CV_8U};

    // Automatic Exposure
    int             m_exposure_max_us {800};
    int             m_exposure_min_us {50};
                                          //Kp, Ti,   Td,  sat_i, sat,   deadzone_in, deadzone_out
    PID_Parameters_t        m_pid_par_aeag{0.5, 15.0, 0.0, 200.0, 800.0, 0,           5};
    PID_Controller          m_PID_aeag{m_pid_par_aeag};
    int             m_exposure_us {400};
    int             m_target_aeag_perc {50}; //55 for AISI304LN, 45 for AW6005A-T6

    boost::circular_buffer<uint64_t>  m_t_stamp_us_b{2};

    // prova
    xiAPIplus_Image m_img_plus; //TODO: initialise these two
    cv::Mat         m_img_mat;

};

#endif // XIMEA_CAMERA_H
