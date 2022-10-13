#include "common/pthread_creator.h"
#include "ximea_camera.h"

#include <boost/filesystem.hpp>
#include <iostream>
#include <unistd.h>

// Project Extern Variables

using namespace cv;

// -----------------------------------------------------------------------------------------------------------------
Ximea_Camera::Ximea_Camera():
    m_abs_save_folder("/srv/ftp/seam-tracker/img/orig")
{
    try{
        std::cout << "Ximea Camera Building... " << std::endl;

        // Retrieving a handle to the camera device
        m_cam.OpenFirst();
        m_hCam = m_cam.GetCameraHandle();
        std::cout << "camera handle" << std::endl;
        // set image format
        m_cam.SetImageDataFormat(XI_RAW8);
        std::cout << "2" << std::endl;
        // Set factory correction list
        m_cam.SetSensorDefectsCorrectionListSelector(XI_SENS_DEFFECTS_CORR_LIST_SEL_FACTORY);
        std::cout << "3" << std::endl;
        // set acquisition mode
        xiSetParamInt(m_hCam,XI_PRM_ACQ_TIMING_MODE, XI_ACQ_TIMING_MODE_FRAME_RATE_LIMIT);
        std::cout << "4" << std::endl;
        // set framerate
        xiSetParamFloat(m_hCam,XI_PRM_FRAMERATE, m_frequency);
        std::cout << "5" << std::endl;
        // set exposure time
        xiSetParamInt(m_hCam,XI_PRM_EXPOSURE, m_exposure_us);
        std::cout << "6" << std::endl;

        // Select output port
        m_cam.SetGPOSelector(XI_GPO_PORT1);
        // select output signal
        xiSetParamInt(m_hCam,XI_PRM_GPO_MODE, XI_GPO_EXPOSURE_ACTIVE);

        // Increase image recieve timeout
        int t_timeout_ms = 1000*1000;
        m_cam.SetNextImageTimeout_ms(t_timeout_ms);

        // HDR OFF
        if ( m_cam.IsHDR() )
            m_cam.DisableHDR();

        // Buffer
        xiSetParamInt(m_hCam, XI_PRM_ACQ_TRANSPORT_BUFFER_COMMIT, 32);
        xiSetParamInt(m_hCam, XI_PRM_ACQ_BUFFER_SIZE_UNIT, 1024*1024);      // MiB
        xiSetParamInt(m_hCam, XI_PRM_ACQ_BUFFER_SIZE, m_buff_size_MB);      // MiB
        xiSetParamInt(m_hCam, XI_PRM_BUFFERS_QUEUE_SIZE, m_buff_size_pics); // as many images are kept as possible
        xiSetParamInt(m_hCam, XI_PRM_BUFFER_POLICY, XI_BP_UNSAFE);          // get pointer to internal ring buffer

        // Take next available image (not latest)
        xiSetParamInt(m_hCam, XI_PRM_RECENT_FRAME, XI_OFF);

        // ROI
        m_x_roi = g_roi_CI.x;
        m_y_roi = g_roi_CI.y;
        m_w_roi = g_roi_CI.width;
        m_h_roi = g_roi_CI.height;
        useRoi();

        // Save folder
        boost::filesystem::path save_dir (m_abs_save_folder);
        boost::filesystem::create_directory(save_dir);
        boost::filesystem::permissions(save_dir, boost::filesystem::all_all);

        std::cout << "Camera Built! " << std::endl;
    }
    catch(std::exception & e){ std::cout << " Error in Ximea_Camera::Ximea_Camera(): "<< e.what() << std::endl; }
}

// -----------------------------------------------------------------------------------------------------------------
Ximea_Camera::Ximea_Camera(Grey_Alg *ptr_alg): Ximea_Camera::Ximea_Camera()
{
    try{
        m_ptr_alg = ptr_alg;
        std::cout << "Algorithm Built in Camera! " << std::endl;
    }
    catch(std::exception & e){ std::cout << " Error in Ximea_Camera::Ximea_Camera(Grey_Alg *ptr_alg): "<< e.what() << std::endl; }
}

// -----------------------------------------------------------------------------------------------------------------
void Ximea_Camera::init()
{
    try{
        create_thread_ex(&m_thread_cam, PTHREAD_EXPLICIT_SCHED, SCHED_OTHER, g_priority_std, &Ximea_Camera::acquire_pwrapper, this, "camera_thread");
    }
    catch(std::exception & e){ std::cout << " Error in Ximea_Camera::init(): "<< e.what() << std::endl; }
}

// -----------------------------------------------------------------------------------------------------------------
void Ximea_Camera::join()
{
    try{
        pthread_join(m_thread_cam, nullptr);
    }
    catch(std::exception & e){ std::cout << " Error in Ximea_Camera::join(): "<< e.what() << std::endl; }
}

// -----------------------------------------------------------------------------------------------------------------
void Ximea_Camera::useRoi()
{
    try{
        int h_inc = m_cam.GetHeight_Increment();
        int w_inc = m_cam.GetWidth_Increment();
        int x_inc = m_cam.GetOffsetX_Increment();
        int y_inc = m_cam.GetOffsetY_Increment();

        int tmp;

        // --- HEIGHT ---
        if (xiSetParamInt(m_hCam, XI_PRM_HEIGHT, (m_h_roi/h_inc)*h_inc))
            std::cout << "XI_PRM_HEIGHT " << (m_h_roi/h_inc)*h_inc << " not accepted"<< std::endl;

        xiGetParamInt(m_hCam, XI_PRM_HEIGHT, &tmp);
        std::cout << "XI_PRM_HEIGHT set to " << tmp << std::endl;
        g_roi_CI.height = tmp;

        // --- WIDTH ---
        if (xiSetParamInt(m_hCam, XI_PRM_WIDTH, (m_w_roi/w_inc)*w_inc))
            std::cout << "XI_PRM_WIDTH " << (m_w_roi/w_inc)*w_inc << " not accepted"<< std::endl;

        xiGetParamInt(m_hCam, XI_PRM_WIDTH, &tmp);
        std::cout << "XI_PRM_WIDTH set to " << tmp << std::endl;
        g_roi_CI.width = tmp;

        // --- X OFFSET ---
        if (xiSetParamInt(m_hCam, XI_PRM_OFFSET_X, (m_x_roi/x_inc)*x_inc))
            std::cout << "XI_PRM_OFFSET_X " << (m_x_roi/x_inc)*x_inc << " not accepted" << std::endl;

        xiGetParamInt(m_hCam, XI_PRM_OFFSET_X, &tmp);
        std::cout << "XI_PRM_OFFSET_X set to " << tmp << std::endl;
        g_roi_CI.x = tmp;

        // --- Y OFFSET ---
        if (xiSetParamInt(m_hCam, XI_PRM_OFFSET_Y, (m_y_roi/y_inc)*y_inc))
            std::cout << "XI_PRM_OFFSET_Y " << (m_y_roi/y_inc)*y_inc << " not accepted" << std::endl;

        xiGetParamInt(m_hCam, XI_PRM_OFFSET_Y, &tmp);
        std::cout << "XI_PRM_OFFSET_Y set to " << tmp << std::endl;
        g_roi_CI.y = tmp;
    }
    catch(std::exception & e){ std::cout << " Error in Ximea_Camera::useRoi(): "<< e.what() << std::endl; }
}

// -----------------------------------------------------------------------------------------------------------------
void* Ximea_Camera::acquire()
{
    // Takes Pictures
    {std::unique_lock<std::mutex> lc (g_state_mtx); m_acquisition_state = Acquisition_State::MEASURE;}
    try
    {
        if (m_acquisition_state == Acquisition_State::MEASURE)
        {
            // Synching
            DWORD size = sizeof(m_t_stamp0_ns);
            XI_PRM_TYPE type = xiTypeInteger64;
            {
                std::unique_lock<std::mutex> lck(g_mtx);
                std::cout << "Camera Synching ..." << std::endl;
                g_cam_ready.store(true);
                g_cv.wait(lck, [] { return (g_rob_ready.load()  && g_cam_ready.load());});
            }

            // Thread clock
            std::chrono::steady_clock::time_point t0_cam = std::chrono::steady_clock::now();
            m_t_cam_thread.setZero(t0_cam);

            // Camera internal clock
            xiGetParam(m_hCam, XI_PRM_TIMESTAMP, &m_t_stamp0_ns, &size, &type);
            uint64_t lag_ximea_us = m_t_cam_thread.getTime();
            m_t_stamp0_ns -= lag_ximea_us*1000ull*2; // TODO sta porcata qui non so quanto vada bene


            std::cout << "camera lag " << lag_ximea_us << " us (stamp " << m_t_stamp0_ns << " ns)" <<std::endl;
            std::cout << "---- /// CAMERA READY /// ----" << std::endl;

            // stuff
            int x,y,w,h;
            int x_,y_,w_,h_;
            x = m_cam.GetOffsetX();   x_ = m_cam.GetAutoExposureAutoGainROIoffsetX();
            y = m_cam.GetOffsetY();   y_ = m_cam.GetAutoExposureAutoGainROIoffsetY();
            w = m_cam.GetWidth();     w_ = m_cam.GetAutoExposureAutoGainROIWidth();
            h = m_cam.GetHeight();    h_ = m_cam.GetAutoExposureAutoGainROIHeight();
            std::cout << "xigetparam = (" << w << ", " << h  << ")" <<std::endl;

            // --- ALTERNATIVA LIVE STREAM ---
            uint n_img = 0;
            uint64_t t_exp, t_stamp_ns;

            boost::filesystem::path save_dir (m_abs_save_folder);
            std::string abs_save_path;

            while(g_egm_state != Egm_State::GUIDE)
                usleep(1000*m_refresh_cam_ms);

            std::cout << "Aquisition started" << std::endl;
            {std::unique_lock<std::mutex> lck(g_state_mtx); g_cam_state = Cam_State::RUNNING;}
            m_cam.StartAcquisition();
            std::cout << "Aquisition started for real" << std::endl;
            DWORD n_img_cam0 = 0;
            std::chrono::steady_clock::time_point t_acq_start = std::chrono::steady_clock::now();
            while(n_img < N_EXPECTED_IMG && g_cam_state == Cam_State::RUNNING && g_egm_state == Egm_State::GUIDE)
            {
                // read image
                //xiGetParam(m_hCam, XI_PRM_TIMESTAMP, &t_stamp_ns, &size, &type);
                try {m_cam.GetNextImage(&m_img_plus);} catch(...) {std::cout << "QUALCOSA NON QUADRA";}
                DWORD n_img_cam; n_img_cam = m_img_plus.GetXI_IMG()->nframe;
                if (n_img == 0) {n_img_cam0 = n_img_cam;}

                // WTF ARE YOU DOING TODO togliere ste schifezze
                w = m_img_plus.GetWidth();  // w = m_cam.GetWidth();
                h = m_img_plus.GetHeight(); // h = m_cam.GetHeight();
                std::cout << "Image " << n_img << " (" << n_img_cam-n_img_cam0 << "): size = (" << w << ", " << h  << ")" <<std::endl;

                uint64_t alg_start = GetTickCountUs(m_t_cam_thread.getZero());

                // extract image from buffer
                m_img_mat = m_cam.ConvertOcvMat(&m_img_plus);
                t_exp = m_img_plus.GetXI_IMG()->exposure_time_us;

                // time of image taken
                uint64_t t_img_taken_us = m_img_plus.GetXI_IMG()->tsSec*1000ull * 1000ull +
                                          m_img_plus.GetXI_IMG()->tsUSec - m_t_stamp0_ns/1000ull +
                                          m_img_plus.GetXI_IMG()->exposure_time_us/2ull;     // TODO this is the time image is TAKEN
                m_t_stamp_us_b.push_back(t_img_taken_us);
//                uint64_t t_img_taken_us = (t_stamp_ns - m_t_stamp0_ns)/1000ull + m_img_plus.GetXI_IMG()->exposure_time_us/2ull;

                // save
                std::string file_name = "img_" +  std::to_string(n_img) + "_ts-" + std::to_string(t_img_taken_us) +
                                        "_exp-" + std::to_string(t_exp) + "_x-" +  std::to_string(0) + "_y-" + std::to_string(0) +".bmp";
                abs_save_path = save_dir.string() + "/" + file_name;
                imwrite(abs_save_path, m_img_mat);

                // extract centre line
                cv::Point p_seamI = m_ptr_alg->analyse_image(m_img_mat, t_img_taken_us);

                // auto-exposure
                setAutoExposure(p_seamI);
                //xiSetParamInt(m_hCam,XI_PRM_EXPOSURE, 360);

                // time end
                uint64_t alg_end = GetTickCountUs(m_t_cam_thread.getZero());
                uint64_t alg_time_us = alg_end - alg_start;
                if (alg_time_us > 1000ull*1000ull/m_frequency)
                    std::cout << "Algorithm is slow (" << n_img << "): " << alg_time_us - 1000ull*1000ull/m_frequency << " extra us elapsed" << std::endl;

                // update
                n_img ++;
                std::cout << std::endl;
            }
            double elapsed_time = GetTickCountMs(t_acq_start);
            std::cout << "rate is " << n_img/(elapsed_time)*1000 << "Hz" <<std::endl;

            m_cam.StopAcquisition();
            m_cam.Close();
            {std::unique_lock<std::mutex> lck(g_state_mtx); g_cam_state = Cam_State::STOPPED;}
        }
        else if (m_acquisition_state == Acquisition_State::STOPPED)
        {
            usleep(m_refresh_cam_ms*1000);
        }
    }
    catch(std::exception & e){
        std::cout << "Error in Ximea_Camera::acquire: "<< e.what() << std::endl;
        m_cam.StopAcquisition();
        m_cam.Close();
    }
}

// -----------------------------------------------------------------------------------------------------------------
int Ximea_Camera::calculateAutoExposure(cv::Point p_seamI)
{
    // Sony IMX252 exp_min: 19 µs delta_exp = 5.29 µs exp_max = 3 sec

//    if (p_seamI.y <= 0)
//        m_roi_aeag.y = m_roi_aeag_y;
//    else if (p_seamI.y + m_roi_aeag_h/2 < g_roi_CI.height)
//        m_roi_aeag.y = p_seamI.y - m_roi_aeag_h/2;
//    else
//        m_roi_aeag.y = g_roi_CI.height - m_roi_aeag_h;
//    std::cout << "AEAG ROI - " << m_roi_aeag_x << " " << m_roi_aeag_y << " " << m_roi_aeag_w << " " << m_roi_aeag_h << std::endl;

    m_img_aeag = m_img_mat(m_roi_aeag);

    int auto_exposure_us = m_exposure_us;
    double img_mean = cv::mean(m_img_aeag)[0];
    if (false){
        double error_aeag = img_mean/255.0*100.0 - m_target_aeag_perc;
        // limit maximum correction
        if (error_aeag > 10 || error_aeag < -10){
            int error_sign = (error_aeag > 0) - (error_aeag < 0);
            auto_exposure_us = cvRound(m_exposure_us * (1.0-error_sign*0.10));
        }

        // limit minimum correction
        else if (error_aeag > 5 || error_aeag < -5)
            auto_exposure_us = cvRound(m_exposure_us*(1.0 - error_aeag/100.0));

        // limit extreme values
        auto_exposure_us = auto_exposure_us > m_exposure_max_us ? m_exposure_max_us : auto_exposure_us;
        auto_exposure_us = auto_exposure_us < m_exposure_min_us ? m_exposure_min_us : auto_exposure_us;
    }

    if(m_t_stamp_us_b.size() > 1){
        double dt_ms = (m_t_stamp_us_b.at(1)- m_t_stamp_us_b.at(0))/1000.0;
        auto_exposure_us += m_PID_aeag.update(img_mean/255.0*100.0 , m_target_aeag_perc, 1);
    }
    // limit extreme values
    auto_exposure_us = auto_exposure_us > m_exposure_max_us ? m_exposure_max_us : auto_exposure_us;
    auto_exposure_us = auto_exposure_us < m_exposure_min_us ? m_exposure_min_us : auto_exposure_us;

    return auto_exposure_us;
}

// -----------------------------------------------------------------------------------------------------------------
void Ximea_Camera::setAutoExposure(cv::Point p_seamI)
{
    int auto_exposure_us = calculateAutoExposure(p_seamI);
    m_exposure_us = auto_exposure_us;
    xiSetParamInt(m_hCam,XI_PRM_EXPOSURE, m_exposure_us);
}


