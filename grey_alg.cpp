#include "grey_alg.h"

#include <boost/filesystem.hpp>
#include <boost/exception/all.hpp>
#include <exception>

// -----------------------------------------------------------------------------------------------------------------
Grey_Alg::Grey_Alg()
{
    try  {
        // save ROI
        m_x_roi = g_roi_IR.x;
        m_y_roi = g_roi_IR.y;
        m_w_roi = g_roi_IR.width;
        m_h_roi = g_roi_IR.height;

        // initialise img_roi
        m_img_roi.create(m_h_roi, m_w_roi, CV_8U);
        m_img_roi = cv::Scalar::all(0);
        // initialise img_blur
        m_img_blur.create(m_h_roi, m_w_roi, CV_8U);
        m_img_blur = cv::Scalar::all(0);
        // initialise img_xdir
        m_img_xdir.create(m_h_roi, m_w_roi, CV_16SC1);
        m_img_xdir = cv::Scalar::all(0);
        // initialise img_ydir
        m_img_ydir.create(m_h_roi, m_w_roi, CV_16SC1);
        m_img_ydir = cv::Scalar::all(0);
        // initialise img_deri
        m_img_deri.create(m_h_roi, m_w_roi, CV_16SC1);
        m_img_deri = cv::Scalar::all(0);
        // initialise img_canny
        m_img_cann.create(m_h_roi, m_w_roi, CV_8U);
        m_img_deri = cv::Scalar::all(0);

        m_min_len_canny = cvRound(m_w_roi*0.4);

        // create save folders
        if(m_debug_mode)
        {
            boost::filesystem::path dir_seam("/srv/ftp/seam-tracker/img/seam"); boost::filesystem::create_directory(dir_seam);
            boost::filesystem::path dir_orig("/srv/ftp/seam-tracker/img/orig"); boost::filesystem::create_directory(dir_orig);
            boost::filesystem::path dir_doug("/srv/ftp/seam-tracker/img/doug"); boost::filesystem::create_directory(dir_doug);
            boost::filesystem::path dir_dist("/srv/ftp/seam-tracker/img/dist"); boost::filesystem::create_directory(dir_dist);
            boost::filesystem::path dir_line("/srv/ftp/seam-tracker/img/line"); boost::filesystem::create_directory(dir_line);
            boost::filesystem::path dir_spot("/srv/ftp/seam-tracker/img/spot"); boost::filesystem::create_directory(dir_spot);
        }

        m_log_file.open(m_abs_save_folder + "/img/" + m_log_file_name, std::ios::app);
        if (m_log_file.is_open() )
        {
            m_log_file << " #1) m_count_frame"<< '\t' << "2) theta_fitI_avg " << '\t' << "3) theta_fitI_std" <<'\n';
            m_log_file.close();
        }

        std::cout << "Algorithm built!\n";

    } catch (std::exception & e){ std::cout << " Grey_Alg::Grey_Alg(): "<< e.what() << std::endl; }

}

// -----------------------------------------------------------------------------------------------------------------
Grey_Alg* Grey_Alg::get_ptr()
{
    try  {
        return this;
    } catch (std::exception & e){ std::cout << " Grey_Alg::get_ptr(): "<< e.what() << std::endl; return nullptr; }
}

// -----------------------------------------------------------------------------------------------------------------
bool Grey_Alg::getNextEstimate(seamEstimate &estimate)
{
    // returns true only if m_fit_locked
    // TODO: insert producer/consumer buffer
    bool ret = false;
    if (m_is_estimate_next)
    {
        estimate = m_estimate;
        m_is_estimate_next = false;
        ret = true;
    }
    return ret;
}

// -----------------------------------------------------------------------------------------------------------------
void Grey_Alg::add_rob_pose(robCartesian p_robW, robEuler o_robW, uint64_t t_rob_us_syn)
{
    try{
        {
            std::unique_lock<std::mutex> lck(m_mtx_rob);
            m_p_robW_b.push_back(p_robW);
            m_o_robW_b.push_back(o_robW);
            m_t_rob_us_b.push_back(t_rob_us_syn);
            //std::cout << "ROB --- Rob pose n. " << m_t_rob_us_b.size() << " at " << t_rob_us_syn << std::endl;
        }
    }
    catch (std::exception & e){ std::cout << " Grey_Alg::add_rob_pose(): "<< e.what() << std::endl; }
}

// -----------------------------------------------------------------------------------------------------------------
cv::Point Grey_Alg::analyse_image(const cv::Mat &img, uint64_t t_img_us_syn)
{
    // Takes in : full image;
    //            time of the image with respect to CPU time of threads' start but measured by camera.
    // Returns  : position of seam in the full image
    try {
        // --- INTERPOLATE ROBOT POSITION ---
        double theta_experimental_baby = 0.0; // mod 20210830
        uint idx_pos_sup = 0;
        uint idx_pos_inf = 0;
        robCartesian p_robW_int;
        robEuler o_robW_int;
        {
            std::cout << "ALG --- Image n. " << m_count_frame << " at " << t_img_us_syn << "\n";
            double alpha = 0;
            std::unique_lock<std::mutex> lck(m_mtx_rob);

            idx_pos_sup = std::distance(m_t_rob_us_b.begin(), std::upper_bound(m_t_rob_us_b.begin(), m_t_rob_us_b.end(), t_img_us_syn) );
            idx_pos_inf = idx_pos_sup-1;
            alpha = ( t_img_us_syn - m_t_rob_us_b.at(idx_pos_inf) )*1.0 / ((m_t_rob_us_b.at(idx_pos_sup) - m_t_rob_us_b.at(idx_pos_inf))*1.0);
            for (uint i= 0; i<3; i++)
            {
                p_robW_int.at(i) = alpha * m_p_robW_b.at(idx_pos_sup).at(i) + (1-alpha) * m_p_robW_b.at(idx_pos_inf).at(i);
                o_robW_int.at(i) = alpha * m_o_robW_b.at(idx_pos_sup).at(i) + (1-alpha) * m_o_robW_b.at(idx_pos_inf).at(i);
            }
            for (int i=0; i<idx_pos_inf; i++)
            {
                m_t_rob_us_b.pop_front();
                m_p_robW_b.pop_front();
                m_o_robW_b.pop_front();
            }
        }


        double x_robW  = p_robW_int.at(0);
        double y_robW  = p_robW_int.at(1);
        double tz_robW  = 3.0/2.0* CV_PI - o_robW_int.at(2);

        // --- ROI ---
        m_img_roi = img(g_roi_IR).clone(); //TODO con clone() copio i dati, sennò solo puntatore

        // --- SPOT ROI ---
        //saveSpot(img, m_count_frame); // clones a ROI of img internally

        // --- GAUSSIAN SMOOTHING ---
        cv::GaussianBlur(m_img_roi, m_img_blur, cv::Size(m_k_blur, m_k_blur), 0);

        // --- DERIVATIVE ---
        // std::cout << "ALG --- Derivative\n";
        cv::Sobel(m_img_blur,m_img_ydir, CV_16SC1,m_sobel_x_ord,m_sobel_y_ord,m_sobel_d_ker); //ksize=-1: scharr 3x3 filter
        // absolute ---
        m_img_ydir = cv::abs(m_img_ydir);
        m_img_deri = m_img_ydir.clone();
        // convert ---
        m_img_deri.convertTo(m_img_deri,CV_16U);

        // --- HISTOGRAMS ON DERIVATIVE ---
        // std::cout << "ALG --- Histogram\n";
        double maximum;
        cv::minMaxIdx(m_img_deri, nullptr, &maximum);
        cv::Mat d_hist;
        int d_histSize = m_d_hist_max/m_bin_wid_d;
        float d_range[] = { 0, 500 }; // TODO why does it not accept m_d_hist_max
        const float* d_histRange = { d_range };
        cv::calcHist( &m_img_deri, 1, nullptr, cv::Mat(), d_hist, 1, &d_histSize, &d_histRange, true, false );

        // --- ADAPTIVE THRESHOLDS ---
        double th_canny_grow = Perc2Thresh(d_hist, m_perc_canny_grow) * m_bin_wid_d;
        double th_canny_enuc = Perc2Thresh(d_hist, m_perc_canny_enuc) * m_bin_wid_d;
        th_canny_grow += m_corr_cann * (th_canny_grow/th_canny_enuc); // occhio
        th_canny_enuc += m_corr_cann;

        // --- plot ---
        if (m_debug_mode)
        {
            int img_hist_w = 512, img_hist_h = 400;
            cv::Mat img_dist(img_hist_h, img_hist_w, CV_8UC3, cv::Scalar(255,255,255));
            HistPlot(d_hist, img_dist);
            cv::line(img_dist, cv::Point(cvRound(th_canny_grow /m_bin_wid_d*(img_hist_w/d_histSize)), 0),
                     cv::Point(cvRound(th_canny_grow /m_bin_wid_d*(img_hist_w/d_histSize)), img_hist_h), cv::Scalar(0,0,255), 2);
            cv::line(img_dist, cv::Point(cvRound(th_canny_enuc/m_bin_wid_d*(img_hist_w/d_histSize)), 0),
                     cv::Point(cvRound(th_canny_enuc/m_bin_wid_d*(img_hist_w/d_histSize)), img_hist_h), cv::Scalar(0,0,255), 2);
            cv::putText(img_dist, "Grow: " + std::to_string(cvRound(th_canny_grow)) + "(" + std::to_string(cvRound(m_corr_cann * (th_canny_grow/th_canny_enuc))) + ")", cv::Point(img_dist.cols*1/3, img_dist.rows*1/4),
                        cv::FONT_HERSHEY_DUPLEX, 1, CV_RGB(118, 185, 0), 2);
            cv::putText(img_dist, "Enuc: " + std::to_string(cvRound(th_canny_enuc)) + "(" + std::to_string(cvRound(m_corr_cann)) + ")", cv::Point(img_dist.cols*1/3, img_dist.rows*1/2),
                        cv::FONT_HERSHEY_DUPLEX, 1, CV_RGB(118, 185, 0), 2);
            std::string file_name = "/srv/ftp/seam-tracker/img/dist/img_" + std::to_string(m_count_frame) + "-ts_" + std::to_string(t_img_us_syn) + ".bmp";
            // imwrite(file_name, img_dist);
        }

        // --- CANNY ---
        // std::cout << "ALG --- Canny\n";
        m_img_xdir = cv::Scalar::all(0);
        m_img_cann = cv::Scalar::all(0);
        cv::Canny(m_img_xdir, m_img_ydir, m_img_cann, th_canny_grow, th_canny_enuc, false);
        if(/* DISABLES CODE */ (false)){
            std::string file_name = "/srv/ftp/seam-tracker/img/cann/img_" + std::to_string(m_count_frame) + "-ts_" + std::to_string(t_img_us_syn) + ".bmp";
            imwrite(file_name, m_img_cann);
        }

        // --- HOUGH ON DERIVATIVE ---
        cv::Mat img_doug;
        cv::cvtColor(m_img_cann,img_doug,cv::COLOR_GRAY2BGR);
        std::vector<uint> idx_line_kept;
        std::vector<cv::Vec2f> lines_der; // will hold the results of the detection
        cv::HoughLines(m_img_cann, lines_der, 1, CV_PI/180, m_min_len_canny, 0,0, m_min_theta, m_max_theta );

        // --- LINE SELECTION ---
        //std::cout << "ALG --- Line Selection\n";
        cv::Point p_edgeR = cv::Point(0,0);
        float x_edge_lineR = m_w_roi/2;
        p_edgeR.x = cvRound(x_edge_lineR);
        int n_lines = lines_der.size();
        uint i_line = 0;
        uint n_line_kept = 0;

        while (i_line < n_lines && n_line_kept==0)
        {
            bool keep_line = false;
            float rho = lines_der[i_line][0], theta = lines_der[i_line][1];

            // filters out upper border effect
            if (rho <= 5 && theta < 100.0/180.0*CV_PI && theta > 80.0/180.0*CV_PI)
            { i_line++;continue;} // line caused by border effects

            // filters out lower border effect
            if (rho >= g_roi_IR.height - 10 && theta < 100.0/180.0*CV_PI && theta > 80.0/180.0*CV_PI)
            { i_line++;continue;} // line caused by border effects


            // calculate line
            float cos_t = cos(theta), sin_t = sin(theta);
            float x0 = cos_t*rho, y0 = sin_t*rho;
            cv::Point pt1 (cvRound(x0 + 1000*(-sin_t)), cvRound(y0 + 1000*(cos_t)));
            cv::Point pt2 (cvRound(x0 - 1000*(-sin_t)), cvRound(y0 - 1000*(cos_t)));
            int y_edge_lineR = cvRound(y0 - (p_edgeR.x - x0) * cos_t / sin_t);

            // looks for first line
            if (m_count_frame == 0) // first frame
            {
                if (abs(y_edge_lineR-m_h_roi/2)<m_d_max)
                    keep_line = true;
            }
            else if (not(m_is_fitting) && not(m_fit_locked))
                keep_line = true;

            // TODO faccio due volte la stessa cosa: prima controllo che la linea sia nel fit
            // poi sotto aggiungo l'ultimo punto al fit (se era buono)
            // poi ricontrollo che il punto al centro della linea sia ancora nel fit aggiornato !!!
            else if(m_fit_locked)
            {
                if (abs(y_edge_lineR-(m_y_edge_fitI - g_roi_IR.y))<m_d_max_fit)
                    keep_line = true;
            }
            else {// is fitting OR m_count_frame > 0 OCCHIO
                if (abs(y_edge_lineR-(m_y_edge_fitI - g_roi_IR.y))<m_d_max_fit)
                    keep_line = true;
            }

            if (keep_line)
            {
                if(m_debug_mode)
                    cv::line(img_doug, pt1, pt2, cv::Scalar(0,0,255), 1, cv::LINE_AA);

                // save line
                n_line_kept++;
                p_edgeR.y = y_edge_lineR;    // 1-add average
                p_edgeR.x = cvRound(x_edge_lineR);
                theta_experimental_baby = theta;

            }
            i_line++;

        } // while (line_kept<1)

        // mod 20210830
        m_theta_fitI_b.push_back(theta_experimental_baby);
        // log
        m_log_file.open(m_abs_save_folder + "/img/" + m_log_file_name, std::ios::app);
        if (m_log_file.is_open())
        {
            if (m_count_frame>50)
                m_log_file << m_count_frame << '\t' << theta_experimental_baby*RAD2DEG << '\t' ;
            else
                m_log_file << m_count_frame << '\t' << theta_experimental_baby*RAD2DEG << '\n' ;

            m_log_file.close();
        }

        // if no line kept, plot them all
        if(m_debug_mode) {
            if ( n_line_kept == 0) {
                for (uint i_line = 0; i_line < lines_der.size(); i_line++) {
                    float rho = lines_der[i_line][0], theta = lines_der[i_line][1];
                    // calculate line
                    float cos_t = cos(theta), sin_t = sin(theta);
                    float x0 = cos_t*rho, y0 = sin_t*rho;
                    cv::Point pt1 (cvRound(x0 + 1000*(-sin_t)), cvRound(y0 + 1000*(cos_t)));
                    cv::Point pt2 (cvRound(x0 - 1000*(-sin_t)), cvRound(y0 - 1000*(cos_t)));
                    cv::line(img_doug, pt1, pt2, cv::Scalar(0,255,0), 1, cv::LINE_AA);

                }

                // plot  minimum angle
                double rho = m_h_roi/2;
                double cos_t = cos(m_min_theta),  sin_t = sin(m_min_theta);
                double x0 = cos_t*rho, y0 = sin_t*rho;

                cv::rectangle(img_doug,cv::Point(cvRound(x0)-3,cvRound(y0)-3),cv::Point(cvRound(x0)+3,cvRound(y0)+3),cv::Scalar(80,127,255),-1);
                cv::Point pt_angle1 (cvRound(x0 + 1000*(-sin_t)), cvRound(y0 + 1000*(cos_t)));
                cv::Point pt_angle2 (cvRound(x0 - 1000*(-sin_t)), cvRound(y0 - 1000*(cos_t)));
                cv::line(img_doug, pt_angle1, pt_angle2, cv::Scalar(80,127,255), 1, cv::LINE_AA);

                // plot maximum angle
                cos_t = cos(m_max_theta); sin_t = sin(m_max_theta);
                x0 = cos_t*rho; y0 = sin_t*rho;

                cv::rectangle(img_doug,cv::Point(cvRound(x0)-3,cvRound(y0)-3),cv::Point(cvRound(x0)+3,cvRound(y0)+3),cv::Scalar(80,127,255),-1);
                pt_angle1 = cv::Point(cvRound(x0 + 1000*(-sin_t)), cvRound(y0 + 1000*(cos_t)));
                pt_angle2 = cv::Point(cvRound(x0 - 1000*(-sin_t)), cvRound(y0 - 1000*(cos_t)));
                cv::line(img_doug, pt_angle1, pt_angle2, cv::Scalar(80,127,255), 1, cv::LINE_AA);
            }

            cv::putText(img_doug, std::to_string(lines_der.size()) + "(" + std::to_string(n_line_kept) + ")", cv::Point(10, img.rows / 2),
                        cv::FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(0, 0, 255), 2);
            cv::putText(img_doug, std::to_string(m_count_frame), cv::Point(10, img.rows / 4),
                        cv::FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(118, 185, 0), 2);
            std::string file_name = "/srv/ftp/seam-tracker/img/doug/img_" + std::to_string(m_count_frame) + "-ts_" + std::to_string(t_img_us_syn) + ".bmp";
            // imwrite(file_name, img_doug);
        }

        // --- ADAPTIVE CANNY THRESHOLD PT2 ---

        // Illuminator missed camera trigger
        if (th_canny_enuc < 35)
            std::cout << "ALG --- " << m_count_frame << " illumination missed camera trigger" << std::endl;

        // Correctly illuminated image
        else
        {
            int th_low_corr = 50;
            // no lines found
            if (lines_der.size() == 0)
            {
                if (m_corr_cann > th_low_corr)
                    m_corr_cann -= abs(m_corr_cann) * 0.15;
                else
                    m_corr_cann -= th_canny_enuc * 0.15;
            }

            // no line kept: -10% on correction
            else if (n_line_kept == 0)
            {
                if (m_corr_cann > th_low_corr)
                    m_corr_cann -= abs(m_corr_cann)*0.1; // -10 % in una bbotta
                else
                    m_corr_cann -= th_canny_enuc * 0.1;
            }

            // more lines found and one kept
            else
            {
                int err_lines = ((int)lines_der.size() - m_ref_lines_cann) > 5 ? 5 : ((int)lines_der.size() - m_ref_lines_cann);
                if (abs(m_corr_cann) < th_low_corr)
                    m_corr_cann += m_gain_lines_cann * err_lines;
                else
                    m_corr_cann += 5 * err_lines * abs(m_corr_cann) / 100.0;
            }

            // Avoid saturation
            if (abs(m_corr_cann)>0.75*th_canny_enuc)
            {
                int corr_sign = m_corr_cann >= 0 ? 1 : -1;
                m_corr_cann = corr_sign * 0.75 * th_canny_enuc;
            }
        }


        // --- SEAM RECOGNITION ---
        //std::cout << "ALG --- Linear fitting\n";
        cv::Mat img_seam;
        if (m_debug_mode) {cv::cvtColor(img,img_seam,cv::COLOR_GRAY2BGR);}

        // Coordinates of seam in image
        double x_edgeI = p_edgeR.x + g_roi_IR.x, y_edgeI = 0;
        if (p_edgeR.y != 0 )
            y_edgeI = p_edgeR.y + g_roi_IR.y;
        else if (m_fit_locked)
            y_edgeI = m_y_edge_fitI;

        double x_edgeW, y_edgeW;
        RotoTranI2W(x_robW, y_robW, tz_robW, x_edgeW, y_edgeW, cvRound(x_edgeI), cvRound(y_edgeI));

        // Linear regression filtering ---
        uint n_good_edge = 0;
        uint n_good_edge_recent = 0;
        m_is_fitting = false;

        // if first frame seen
        if (m_count_frame < 1){
            m_good_edge_b.push_back(true);
            m_y_edgeW_b.push_back(y_edgeW);
        }
        else
        {
            // plots central gaps points
            cv::Scalar seam_color;
            auto i_gap_x = m_x_gapW_b.begin(), i_gap_y = m_y_gapW_b.begin();
            auto i_gap_good = m_good_gap_b.begin();
            for (; i_gap_y != m_y_gapW_b.end(); i_gap_x++, i_gap_y++, i_gap_good++)
            {
                if(m_debug_mode){
                    int x_gapI_j, y_gapI_j;
                    RotoTranW2I(x_robW, y_robW, tz_robW, *i_gap_x, *i_gap_y, x_gapI_j, y_gapI_j);

                    if (*i_gap_good)
                        seam_color = cv::Scalar(255,255,0);
                    else
                        seam_color = cv::Scalar(127,0,127);

                    cv::circle(img_seam, cv::Point(x_gapI_j, y_gapI_j), 4, seam_color, 1);
                }
            }

            // counts good edges
            uint idx_fit_mid = (m_y_edgeW_b.size() > m_n_fit_recent) ? m_y_edgeW_b.size() - m_n_fit_recent : 0;
            m_y_edge_fitW = 0;
            std::vector<uint> idx_good_edge_v;
            uint idx_buffer = 0;
            auto i_edge_x = m_x_edgeW_b.begin(), i_edge_y = m_y_edgeW_b.begin();
            for ( auto i_edge_good = m_good_edge_b.begin(); i_edge_good != m_good_edge_b.end();
                  i_edge_good++, idx_buffer++, i_edge_x++, i_edge_y++)
            {
                if (*i_edge_good)
                {
                    idx_good_edge_v.push_back(idx_buffer);
                    n_good_edge ++;
                    seam_color = cv::Scalar(255,255,255);
                    if (idx_buffer > idx_fit_mid)
                        n_good_edge_recent ++;
                }
                else
                    seam_color = cv::Scalar(0,0,255);

                if(m_debug_mode){
                    int x_edgeI_j, y_edgeI_j;
                    RotoTranW2I(x_robW, y_robW, tz_robW, *i_edge_x, *i_edge_y, x_edgeI_j, y_edgeI_j);
                    cv::circle(img_seam, cv::Point(x_edgeI_j, y_edgeI_j), 4, seam_color, 1);
                }
            }

            // --- DOES GOOD THINGS WITH GOOD POINTS ---
            // 1) --- just old good points: forgets them, keeps new one
            if (not(m_fit_locked) && n_good_edge >= m_n_good_edge_min && n_good_edge_recent==0)
            {
                for (uint idx_good_j : idx_good_edge_v)
                {
                    m_good_edge_b.at(idx_good_j) = false;
                    if(m_debug_mode)
                    {
//                        cv::circle(img_seam, cv::Point(cvRound( x_seamI + x_rob_pxW - m_x_rob_pxW_b.at(idx_good_j) ),
//                                                    cvRound( m_y_seamI_b.at(idx_good_j)) ), 5, cv::Scalar(127,0,127),1);
                    }
                }
                m_y_edgeW_b.push_back(y_edgeW);
                m_good_edge_b.push_back(true);
                n_good_edge = 1;
            }

            // 2) --- enough good points: fits
            if (n_good_edge >= m_n_good_edge_min)
            {
                // modifies fit if not locked yet or if locked-in but with enough recent good points
                if (not(m_fit_locked) || n_good_edge_recent>=1){
                    LinearFit(m_x_edgeW_b,m_y_edgeW_b,m_good_edge_b,m_m_edgeW2W,m_q_edgeW2W,0);
                }

                // fits point
                m_y_edge_fitW = m_m_edgeW2W * x_edgeW + m_q_edgeW2W;
                int x_edge_fitI;
                RotoTranW2I(x_robW, y_robW, tz_robW, x_edgeW, m_y_edge_fitW, x_edge_fitI, m_y_edge_fitI);
                if (m_count_frame > 25)
                    m_is_fitting = true;

                // locks-in fitting
                if (m_n_fitted_points > m_n_fitted_points_min && m_count_frame > 30)
                {
                    m_fit_locked = true;
                    if(m_debug_mode)
                    {cv::putText(img_seam, "LKD", cv::Point(img_seam.cols*4/5, 30),cv::FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(255, 255,0), 2);}
                }

                if (m_debug_mode){
                    double x_fit_startW = m_x_edgeW_b.front();
                    double y_fit_startW = m_m_edgeW2W * x_fit_startW + m_q_edgeW2W;
                    int x_fit_startI, y_fit_startI;

                    RotoTranW2I(x_robW, y_robW, tz_robW, x_fit_startW, y_fit_startW, x_fit_startI, y_fit_startI);
                    cv::rectangle(img_seam, cv::Point(cvRound(x_edge_fitI) -5, m_y_edge_fitI-m_d_max_fit),
                                            cv::Point(cvRound(x_edge_fitI) +5, m_y_edge_fitI+m_d_max_fit), cv::Scalar(255,255,255),1);
                    cv::line(img_seam, cv::Point(cvRound(x_edge_fitI), m_y_edge_fitI),
                                       cv::Point(cvRound(x_fit_startI), cvRound(y_fit_startI) ),cv::Scalar(255,255,255),1);
                }

                // evaluates new point VS fit point
                if (n_lines != 0 && abs(m_y_edge_fitI - y_edgeI) <= m_d_max_fit && p_edgeR.y != 0)
                {m_y_edgeW_b.push_back(y_edgeW);       m_good_edge_b.push_back(true); m_n_fitted_points++; }
                else
                {m_y_edgeW_b.push_back(m_y_edge_fitW); y_edgeI = m_y_edge_fitI; m_good_edge_b.push_back(false);}
            } // if(n_good_seam > m_n_good_seam_min)

            // 3) --- not enough good points but locked-in: holds on to fit
            else if (m_fit_locked)
            {
                // fits with old parametres
                m_y_edge_fitW = m_m_edgeW2W * x_edgeW + m_q_edgeW2W;
                int x_edge_fitI;
                RotoTranW2I(x_robW, y_robW, tz_robW, x_edgeW, m_y_edge_fitW, x_edge_fitI, m_y_edge_fitI);

                if(m_debug_mode){
                    double x_fit_startW = m_x_edgeW_b.front();
                    double y_fit_startW = m_m_edgeW2W * x_fit_startW + m_q_edgeW2W;
                    int x_fit_startI, y_fit_startI;
                    RotoTranW2I(x_robW, y_robW, tz_robW, x_fit_startW, y_fit_startW, x_fit_startI, y_fit_startI);

                    cv::putText(img_seam, "LKD", cv::Point(img_seam.cols*4/5-5, 20),cv::FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(255, 255,0), 2);

                    cv::rectangle(img_seam, cv::Point(cvRound(x_edge_fitI)-5, m_y_edge_fitI-m_d_max_fit),
                                  cv::Point(cvRound(x_edge_fitI)+5, m_y_edge_fitI+m_d_max_fit), cv::Scalar(0,255,255),1);

                    cv::line(img_seam,cv::Point(cvRound(x_edge_fitI),m_y_edge_fitI),
                             cv::Point(cvRound(x_fit_startI), cvRound(y_fit_startI)),cv::Scalar(0,255,255),2);
                }

                if (n_lines != 0 && abs(m_y_edge_fitI - y_edgeI) <= m_d_max_fit && p_edgeR.y != 0)
                {m_y_edgeW_b.push_back(y_edgeW);       m_good_edge_b.push_back(true);}
                else
                {m_y_edgeW_b.push_back(m_y_edge_fitW); y_edgeI = m_y_edge_fitI; m_good_edge_b.push_back(false);} // OCCHIO
            } // else if (m_fit_locked)

            // 4) --- not enough good points and not locked-in
            else
            {
                m_n_fitted_points = 0; // TODO: what if same good fit gets interrupted, I should keep old points

                // 4a) --- two good points
                if (n_good_edge == 2)
                {
                    if(m_debug_mode)
                    {
                        cv::rectangle(img_seam, cv::Point(cvRound(x_edgeI)-5, cvRound(y_edgeI) + m_d_max),
                                   cv::Point(cvRound(x_edgeI)+5, cvRound(y_edgeI) - m_d_max), cv::Scalar(0,255,255),2);
                    }

                    bool is_it_good = true;
                    for (auto iter_good = idx_good_edge_v.begin(); iter_good != idx_good_edge_v.end(); iter_good++)   // if the new one is close, keep all three
                    {
                        int x_edgeI_j, y_edgeI_j;
                        RotoTranW2I(x_robW, y_robW, tz_robW, m_x_edgeW_b.at(*iter_good), m_y_edgeW_b.at(*iter_good), x_edgeI_j, y_edgeI_j);

                        if(m_debug_mode)
                        {
                            cv::rectangle(img_seam, cv::Point(cvRound(x_edgeI)-10, y_edgeI_j + 3),
                                                    cv::Point(cvRound(x_edgeI)+10, y_edgeI_j - 3), cv::Scalar(0,255,0),2);
                        }

                        if (abs(y_edgeI_j - y_edgeI ) >= m_d_max || p_edgeR.y == 0)
                            is_it_good = false;
                    }
                    // if the other points are old, forget them and keep new one instead
                    if (not(is_it_good) && (m_good_edge_b.size() - idx_good_edge_v.at(1)) > 2 && p_edgeR.y != 0)
                    {
                        is_it_good = true;  // keep new point
                        for (auto iter = idx_good_edge_v.begin(); iter != idx_good_edge_v.end(); iter++)
                            m_good_edge_b.at(*iter) = false;
                    }
                    m_y_edgeW_b.push_back(y_edgeW);
                    m_good_edge_b.push_back(is_it_good);
                }

                // 4b) --- one good point
                else if (n_good_edge == 1)
                {
                    int x_edgeI_0, y_edgeI_0;
                    RotoTranW2I(x_robW, y_robW, tz_robW, m_x_edgeW_b.at(idx_good_edge_v.at(0)),
                                                             m_y_edgeW_b.at(idx_good_edge_v.at(0)), x_edgeI_0, y_edgeI_0);

                    if(m_debug_mode){
                        cv::rectangle(img_seam, cv::Point(cvRound(x_edgeI)-5, cvRound(y_edgeI) + m_d_max),
                                      cv::Point(cvRound(x_edgeI)+5, cvRound(y_edgeI) - m_d_max), cv::Scalar(0,0,255),2);

                        cv::rectangle(img_seam, cv::Point(x_edgeI_0-10, y_edgeI_0 + 3),
                                                cv::Point(x_edgeI_0+10, y_edgeI_0 - 3), cv::Scalar(0,255,255),2);
                    }

                    if (abs(y_edgeI_0 - y_edgeI ) < m_d_max && p_edgeR.y != 0){
                        m_y_edgeW_b.push_back(y_edgeW);
                        m_good_edge_b.push_back(true);
                    }
                    else if (p_edgeR.y == 0){
                        m_y_edgeW_b.push_back(y_edgeW);
                        m_good_edge_b.push_back(false);
                    }
                    else{
                        m_good_edge_b.at(idx_good_edge_v.at(0)) = false;
                        m_y_edgeW_b.push_back(y_edgeW);
                        m_good_edge_b.push_back(true);
                    }
                }

                // 4c) --- no previous good point
                else {
                    m_y_edgeW_b.push_back(y_edgeW);
                    m_good_edge_b.push_back(p_edgeR.y != 0);
                }

            }// not locked and no enough good points
        }// not first frame


        // --- WIDTH ESTIMATE ---
        //std::cout << "ALG --- Width Estimate\n";
        /* Gap has to lay either over or below recognised line along trasversal direction
         * Procedure:
         * 1) calculate gradient along trasversal direction
         * 2) select verse according to more negative gradient
         * 3) estimate width as the distance between dark points (not gradient)
        */

        // Trasversal direction
        int x_gapI = cvRound(x_edge_lineR) + g_roi_IR.x;
        int w_gapI = 0, y_gapI = 0;
        double x_gapW = 0, y_gapW = 0;
        try
        {
            int d_seam_max = cvRound(1.0*1000.0/g_px_res);
            int y_p1_R = cvRound(y_edgeI - g_roi_IR.y) - (d_seam_max); //y_p1_R = 0;        // MOD 20210702
            int y_p2_R = cvRound(y_edgeI - g_roi_IR.y) + (d_seam_max); //y_p2_R = g_roi_IR.height;
            if (y_p1_R < 0)
            {y_p1_R = 0; y_p2_R = d_seam_max*2;}
            cv::Point p1_R(cvRound(x_edge_lineR), y_p1_R); // TODO perpendicular to fitted line
            cv::Point p2_R(cvRound(x_edge_lineR), y_p2_R);

            if (m_debug_mode)
            {
                int img_hist_w = 512, img_hist_h = 400;
                cv::Mat img_line(img_hist_h, img_hist_w, CV_8UC3, cv::Scalar(255,255,255));

                std::array<cv::Point,2> p_widthI =
                        LinePlot2(p1_R, p2_R, 5,  img_line, cv::Scalar(255,255,0), m_good_edge_b.back(), cvRound(y_edgeI - g_roi_IR.y));

                cv::putText(img_line, std::to_string(m_count_frame), cv::Point(img_line.cols - 100, img_line.rows / 8),
                            cv::FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(118, 185, 0), 2);
                

                // mod I mod II
                w_gapI = cv::abs(p_widthI.at(0).y - p_widthI.at(1).y);
                y_gapI = ( p_widthI.at(0).y + p_widthI.at(1).y ) / 2;

                double w_gap_meanI = 0;
                bool w_gap_good = false, y_gap_good = false;

                auto it_good = m_good_gap_b.end() - m_w_gapI_b.size();
                if (it_good < m_good_gap_b.begin())
                    throw (std::string("Too few points for seam gap estimate"));

                int count_good = 0;
                auto it_cen = m_y_gapW_b.begin();
                for (auto it_wid = m_w_gapI_b.begin() ; it_wid != m_w_gapI_b.end(); it_wid++, it_good++)
                {
                    if (*it_good)
                    {
                        count_good++;
                        w_gap_meanI = w_gap_meanI * (count_good-1)/count_good + *it_wid/count_good;
                    }
                }

                //cv::putText(img_seam, std::to_string(int(w_gap_meanI)), cv::Point(img_seam.cols*3/5, 100),cv::FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(255, 255,0), 2);
                //cv::putText(img_seam, std::to_string(w_gapI), cv::Point(img_seam.cols*3/5, 150),cv::FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(255, 255,0), 2);

                if (count_good == 0)
                    w_gap_good = true;
                else
                    w_gap_good = cv::abs(w_gapI - w_gap_meanI) < 10;

                if (y_gapI <= g_roi_IR.y)
                    y_gap_good = false;
                else if (count_good == 0 && m_m_fit_gap_W2W == 0.0 && m_q_fit_gap_W2W == 0.0)
                {
                    y_gap_good = true;
                    //cv::putText(img_seam, "Sorrt", cv::Point(img_seam.cols*4/5, 100),cv::FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(0, 0,255), 2);
                }
                else
                {
                    if (cv::abs(y_gapI - m_y_edge_fitI) < m_d_max_fit+10){
                        y_gap_good = true;
                    //    cv::putText(img_seam, std::to_string(cv::abs(y_gapI - m_y_edge_fitI)), cv::Point(img_seam.cols*4/5, 100),cv::FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(0, 0,255), 2);
                    }
                    else {
                        y_gap_good = false;
                    }
                }
                if (w_gap_good && y_gap_good) {
                    m_good_gap_b.push_back(true);
                    m_w_gapI_b.push_back(w_gapI);
                    m_y_gapI_b.push_back(y_gapI);
                }
                // TODO if you cannot find the gap where it should be, maybe there isn't any so use line estimate
                else {
                    // calculate fit
                    int x_gap_fitI_tmp = 0, y_gap_fitI_tmp = 0;
                    if (m_fit_locked && m_count_frame > 50){
                        double x_gap_fitW_tmp = *(m_x_gapW_b.end()-1) + (x_robW-m_x_robW_bef);
                        double y_gap_fitW_tmp = m_m_fit_gap_W2W* x_gap_fitW_tmp + m_q_fit_gap_W2W;
                        RotoTranW2I(x_robW, y_robW, tz_robW, x_gap_fitW_tmp, y_gap_fitW_tmp, x_gap_fitI_tmp, y_gap_fitI_tmp);
                    }
                    else
                        y_gap_fitI_tmp = y_gapI;

                    // push-back
                    m_good_gap_b.push_back(false);
                    m_w_gapI_b.push_back(cvRound(w_gap_meanI));
                    m_y_gapI_b.push_back(cvRound(y_gap_fitI_tmp));
                }

                RotoTranI2W(x_robW, y_robW, tz_robW, x_gapW, y_gapW, x_gapI, m_y_gapI_b.back());

                m_x_gapW_b.push_back(x_gapW);
                m_y_gapW_b.push_back(y_gapW);

                // Save
                std::string file_name = "/srv/ftp/seam-tracker/img/line/img_" + std::to_string(m_count_frame) + "-ts_" + std::to_string(t_img_us_syn) + ".bmp";
                //imwrite(file_name, img_line);

                cv::line(img_seam, p_widthI.at(0),                p_widthI.at(1),                cv::Scalar(0,w_gap_good,1-w_gap_good)*255,2);
                cv::line(img_seam, p_widthI.at(0)-cv::Point(3,0), p_widthI.at(0)+cv::Point(3,0), cv::Scalar(0,w_gap_good,1-w_gap_good)*255,2);
                cv::line(img_seam, p_widthI.at(1)-cv::Point(3,0), p_widthI.at(1)+cv::Point(3,0), cv::Scalar(0,w_gap_good,1-w_gap_good)*255,2);

            }
        }
        catch (boost::exception const & e){ std::cout << "Grey_Alg::analyse_image(): width estimate"<< boost::diagnostic_information(e) << std::endl;
                                            m_good_gap_b.push_back(false); m_w_gapI_b.push_back(0); m_y_gapI_b.push_back(0); m_x_gapW_b.push_back(0); m_y_gapW_b.push_back(0);}
        catch (std::exception const & e){ std::cout << "Grey_Alg::analyse_image(): width estimate"<< e.what() << " at line " << '__LINE__' << std::endl;
                                          m_good_gap_b.push_back(false); m_w_gapI_b.push_back(0); m_y_gapI_b.push_back(0); m_x_gapW_b.push_back(0); m_y_gapW_b.push_back(0);}

        // --- HOUGH ANGLE UPDATE ---
        if (m_fit_locked && m_count_frame > 50){

            // Seam centre line fit
            uint8_t buffers_offset = m_x_gapW_b.size() - m_x_edgeW_b.size();
            uint n_good_gaps = std::accumulate(m_good_gap_b.begin()+buffers_offset,m_good_gap_b.end(),0);
            if (n_good_gaps>2)
                LinearFit(m_x_gapW_b, m_y_gapW_b, m_good_gap_b, m_m_fit_gap_W2W, m_q_fit_gap_W2W, buffers_offset);

            double x_fit_gap_startW = *(m_x_gapW_b.begin() + buffers_offset); // mod 20210830
            double y_fit_gap_startW = m_m_fit_gap_W2W*x_fit_gap_startW + m_q_fit_gap_W2W;
            double x_fit_gap_endW = *(m_x_gapW_b.end()-1);
            double y_fit_gap_endW = m_m_fit_gap_W2W*x_fit_gap_endW + m_q_fit_gap_W2W;

            // Seam edge line fit
            double m_fit_edge_W2W, q_fit_edge_W2W;
            if ( std::accumulate(m_good_edge_b.begin(),m_good_edge_b.end(),0) > 2 )
                LinearFit(m_x_edgeW_b, m_y_edgeW_b, m_good_edge_b, m_fit_edge_W2W, q_fit_edge_W2W, 0);

            double x_fit_edge_startW = *(m_x_edgeW_b.begin());
            double y_fit_edge_startW = m_fit_edge_W2W*x_fit_edge_startW + q_fit_edge_W2W;
            double x_fit_edge_endW = *(m_x_edgeW_b.end()-1);
            double y_fit_edge_endW = m_fit_edge_W2W*y_fit_edge_endW + q_fit_edge_W2W;

            // World angle for seam-tracker
            double theta_fitW_tmp = atan(m_m_fit_gap_W2W); // mod 20210830
            // double theta_fitW_tmp = atan(m_fit_edge_W2W);
            m_theta_fitW_b.push_back(theta_fitW_tmp);
            m_theta_fitW = std::accumulate(m_theta_fitW_b.begin(),m_theta_fitW_b.end(),0.0)/m_theta_fitW_b.size();

            // Image angle for algorithm
            int x_fit_edge_startI, y_fit_edge_startI;
            RotoTranW2I(x_robW, y_robW, tz_robW, x_fit_edge_startW, y_fit_edge_startW, x_fit_edge_startI, y_fit_edge_startI);
            int x_fit_edge_endI, y_fit_edge_endI;
            RotoTranW2I(x_robW, y_robW, tz_robW, x_fit_edge_endW,   y_fit_edge_endW,   x_fit_edge_endI, y_fit_edge_endI);

            // mod 20210830
            int offset_baby = m_good_edge_b.size() - m_theta_fitI_b.size();
            uint n_good_edges = std::accumulate(m_good_edge_b.begin()+offset_baby,m_good_edge_b.end(),0);
            double theta_fitI_tmp = tan( 1.0*(y_fit_edge_startI - y_fit_edge_endI) / (x_fit_edge_startI - x_fit_edge_endI) ) + CV_PI/2.0; // TODO è un buon modo questo?
            // m_theta_fitI_b.push_back(theta_fitI_tmp);   // mod 20210830
            // double theta_fitI_avg = std::accumulate(m_theta_fitI_b.begin(),m_theta_fitI_b.end(),0.0)/m_theta_fitI_b.size(); // mod 20210830

            // AVERAGE // mod 20210830
            double theta_fitI_avg = 0.0;
            for (int i = 0; i < m_theta_fitI_b.size(); i++)
            {
                if (m_good_edge_b.at(i+offset_baby))
                    theta_fitI_avg += m_theta_fitI_b.at(i);
            }

            if (n_good_edges > 1)
                theta_fitI_avg /= n_good_edges;
            else
                theta_fitI_avg = theta_fitI_tmp;//tz_robW - CV_PI/2 - atan(m_fit_edge_W2W);

            // STANDARD DEVIATION // mod 20210830
            double theta_fitI_std = 0.0;
            for (int i = 0; i < m_theta_fitI_b.size(); i++)
            {
                if (m_good_edge_b.at(i+offset_baby))
                    theta_fitI_std += pow(m_theta_fitI_b.at(i)-theta_fitI_avg,2.0);
            }
            if (n_good_edges > 1)
                theta_fitI_std = pow(theta_fitI_std/n_good_edges,0.5); // mod 20210830
            else
                theta_fitI_std = 2.0;

            // log
            m_log_file.open(m_abs_save_folder + "/img/" + m_log_file_name, std::ios::app);
            if (m_log_file.is_open())
            {
                m_log_file << m_count_frame << '\t' << theta_fitI_avg*RAD2DEG << '\t' << theta_fitI_std*RAD2DEG << '\t' << '\n' ;
                m_log_file.close();
            }

            if ( not isnan(theta_fitI_avg) )
            {
                m_max_theta = theta_fitI_avg + (5.0 * DEG2RAD + theta_fitI_std/1.5); // OCCHIO A CAMBIARLI CHE CAMBI ANCHE w_gap*cos(theta)
                m_min_theta = theta_fitI_avg - (5.0 * DEG2RAD + theta_fitI_std/1.5);
            }

            // Plot gap centre line fit
            int x_fit_gap_startI, y_fit_gap_startI;
            RotoTranW2I(x_robW, y_robW, tz_robW, x_fit_gap_startW, y_fit_gap_startW, x_fit_gap_startI, y_fit_gap_startI);
            int x_fit_gap_endI, y_fit_gap_endI;
            RotoTranW2I(x_robW, y_robW, tz_robW, x_fit_gap_endW,   y_fit_gap_endW,   x_fit_gap_endI, y_fit_gap_endI);
            cv::line(img_seam, cv::Point(x_fit_gap_endI,    y_fit_gap_endI),
                               cv::Point(x_fit_gap_startI,  y_fit_gap_startI ),cv::Scalar(255,255,0),1);

            // FIT ALSO ON GAP
            if (abs(y_fit_gap_endI - m_y_gapI_b.back()) > 15)
            {
                m_y_gapI_b.back() = y_fit_gap_endI;
                m_good_gap_b.back() = false;
            }

//            if (m_debug_mode)
//            {
//                cv::putText(img_seam, std::to_string(int(m_theta_fitW*RAD2DEG)) + "(" + std::to_string(theta_fitW_tmp) + ")", cv::Point(img_seam.cols*3/5, 100),cv::FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(0, 0,255), 2);
//                cv::putText(img_seam, std::to_string(int(theta_fitI_avg*RAD2DEG))+ "(" + std::to_string(theta_fitI_tmp) + ")", cv::Point(img_seam.cols*3/5, 150),cv::FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(0, 0,255), 2);
//            }
        }
        //cv::putText(img_seam,std::to_string(p_edgeR.y), cv::Point(img_seam.cols*3/5, 100), cv::FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(0, 0, 255), 2);


        // --- UPDATE ---
        //std::cout << "ALG --- Update\n";
        // Do this last otherwise calls to buffer.front() or buffer.back() will produce different results in different points
        m_x_edgeW_b.push_back(x_edgeW);
        m_x_robW_bef = x_robW;
        cv::Point p_seamI = cv::Point(cvRound(x_gapI), cvRound(m_y_gapI_b.back())); // mod V

        if(m_debug_mode)
        {
            // Seam drawing ---
            cv::rectangle(img_seam,cv::Point(m_x_roi,m_y_roi),cv::Point(m_x_roi+m_w_roi,m_y_roi+m_h_roi),cv::Scalar(255,255,0),1);
            if (m_good_gap_b.back()) // mod V
                cv::circle(img_seam, p_seamI, 4, cv::Scalar(255,255,0),2);
            else
                cv::circle(img_seam, p_seamI, 4, cv::Scalar(0,0,255),2);

            cv::putText(img_seam, std::to_string(m_count_frame), cv::Point(10, 30),
                        cv::FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(118, 185, 0), 2);

            // Draw Spot
            cv::Point p_spotI = cv::Point(g_spotC.x - g_roi_CI.x, g_spotC.y - g_roi_CI.y); // TODO this is centre of ROI
            cv::circle(img_seam, p_spotI,7,cv::Scalar(0,0,255),-1);

            // Save
            std::string file_name = "/srv/ftp/seam-tracker/img/seam/img_" + std::to_string(m_count_frame) + "-ts_" + std::to_string(t_img_us_syn) + ".bmp";
            imwrite(file_name, img_seam);
        }

        // Save estimate for robot and return
        cv::Point p_seamC = cv::Point(p_seamI.x + g_roi_CI.x, p_seamI.y + g_roi_CI.y);

        robCartesian p_gapW {x_gapW, y_gapW, p_robW_int.at(2)};
        robCartesian p_edgeW {x_edgeW, y_edgeW, p_robW_int.at(2)};      //sostituito

        double w_gapW = m_w_gapI_b.back()*g_px_res/1000.0*cos( (m_max_theta + m_min_theta)/2 - CV_PI/2);
        {
            std::unique_lock<std::mutex> lck(g_mtx_seam);
            m_estimate.p_seamC = p_seamC;
            m_estimate.p_robW_int = p_robW_int;
            m_estimate.p_seamW = p_edgeW;        // mod V
            m_estimate.t_img_sync_us = t_img_us_syn;
            m_estimate.theta_z_fitW = m_theta_fitW;
            m_estimate.w_gapW = w_gapW;

            // Estimate is used only if algorithm has locked
            if (m_fit_locked)   m_is_estimate_next = true;
            else                m_is_estimate_next = false;
        }
        m_count_frame++;
        return p_seamI;
    }
    catch (boost::exception const & e){ std::cout << "Grey_Alg::analyse_image(): "<< boost::diagnostic_information(e) << std::endl;    m_count_frame++;}
    catch (std::exception const & e){ std::cout << "Grey_Alg::analyse_image(): "<< e.what() << " at line " << '__LINE__' << std::endl; m_count_frame++;}
}

// -----------------------------------------------------------------------------------------------------------------
double Grey_Alg::Perc2Thresh(cv::Mat histogram, double percent)
{
    double thresh = 0;
    int start_offset = 3;
    auto it_beg = histogram.begin<float>()+start_offset, it_end = histogram.end<float>();
    int sum_hist = std::accumulate(it_beg, it_end,0);
    double sum_tmp = 0;
    int histSize = histogram.size[0];
    for (int idx = start_offset; idx < histSize; idx++)
    {
        sum_tmp += cvRound(histogram.at<float>(idx));
        if (sum_tmp>sum_hist*percent)
        {thresh = idx; break;}
    }
    return thresh;
}

// -----------------------------------------------------------------------------------------------------------------
void Grey_Alg::HistPlot(cv::Mat hist, cv::Mat& img, cv::Scalar color)
{
    int histSize = hist.size[0];
    int hist_h = img.size().height;
    int hist_w = img.size().width;

    // Normalise
    double maximum;
    cv::minMaxIdx(hist, nullptr, &maximum);
    cv::normalize(hist, hist, 0, hist_h, cv::NORM_MINMAX, -1, cv::Mat() );
    double bin_w = cvRound( hist_w*1.0 / (histSize*1.0) );

    // Grid
    cv::line(img, cv::Point(cvRound(100.0*bin_w),0), cv::Point(cvRound(100.0*bin_w),hist_h), cv::Scalar(0,0,0), 1);
    cv::line(img, cv::Point(cvRound(200.0*bin_w),0), cv::Point(cvRound(200.0*bin_w),hist_h), cv::Scalar(0,0,0), 1);
    cv::line(img, cv::Point(0,100), cv::Point(hist_w,100), cv::Scalar(0,0,0), 1);
    cv::line(img, cv::Point(0,200), cv::Point(hist_w,200), cv::Scalar(0,0,0), 1);
    cv::line(img, cv::Point(0,300), cv::Point(hist_w,300), cv::Scalar(0,0,0), 1);

    // Data Plot
    for( int i = 1; i < histSize; i++ )
    {
        cv::line(img,
                 cv::Point( cvRound(bin_w*(i-1)), hist_h - cvRound(hist.at<float>(i-1)) ),
                 cv::Point( cvRound(bin_w*(i)),   hist_h - cvRound(hist.at<float>(i)) ),
                 color, 2, 8, 0  );
    }
}

// -----------------------------------------------------------------------------------------------------------------
std::array<cv::Point,2> Grey_Alg::LinePlot(cv::Point p1, cv::Point p2, int w_mean, cv::Mat& img, cv::Scalar color, bool good_point, int y_seamR)
{
    cv::LineIterator line_iter(m_img_blur, p1, p2);

    cv::Point p1_p1 = p1 + cv::Point(2,0);
    cv::Point p2_p1 = p2 + cv::Point(2,0);
    cv::LineIterator line_iter_p1(m_img_blur, p1_p1, p2_p1);

    cv::Point p1_m1 = p1 + cv::Point(-2,0);
    cv::Point p2_m1 = p2 + cv::Point(-2,0);
    cv::LineIterator line_iter_m1(m_img_blur, p1_m1, p2_m1);

    cv::LineIterator line_iter2 = line_iter;
    int line_len = line_iter.count;

    std::vector<int> line;
    std::vector<int> line_der;

    int img_h = img.size().height;
    int img_w = img.size().width;

    // Normalise Y
    // double maximum;
    // cv::minMaxIdx(line_iter, nullptr, &maximum);
    // cv::normalize(hist, hist, 0, hist_h, cv::NORM_MINMAX, -1, cv::Mat() );

    // Normalise X
    double bin_w = cvRound( 1.0*img_w / (line_len*1.0) );

    // Grid
    cv::line(img, cv::Point(0,100), cv::Point(img_w,100), cv::Scalar(0,0,0), 1);
    cv::line(img, cv::Point(0,200), cv::Point(img_w,200), cv::Scalar(0,0,0), 1);
    cv::line(img, cv::Point(0,300), cv::Point(img_w,300), cv::Scalar(0,0,0), 1);

    cv::Scalar seam_line_color = cv::Scalar(0, good_point, not(good_point))*255;

    // Data Plot
    int i_min = -1;
    int minimum = 9999;
    line_der.push_back(0);
    for( uint i = 1; i < line_len; i++)
    {
        // current pixel
        int pixel = ((int)* (*line_iter++) + (int)* (*line_iter_p1++) + (int)* (*line_iter_m1++)) / 3;
        line.push_back(pixel);

        // derivative
        int next_pixel = ((int)* (*line_iter) + (int)* (*line_iter_p1) + (int)* (*line_iter_m1)) / 3;
        line_der.push_back(next_pixel - pixel);

        // store minimum
        if (pixel < minimum) {minimum = pixel; i_min = i-1;}

        // Plot pixels
        cv::line(img, cv::Point( cvRound(bin_w*(i-1)), img_h - pixel),
                      cv::Point( cvRound(bin_w*(i)),   img_h - next_pixel ), color, 2, 8, 0);

        // Plot derivative
        cv::line(img, cv::Point( cvRound(bin_w*(i-1)), img_h -300 - line_der.at(i-1) ),
                      cv::Point( cvRound(bin_w*(i)),   img_h -300 - line_der.at(i) ), cv::Scalar(255,0,0), 2, 8, 0);

        // Line at seam pixel
        if (line_iter.pos().y == y_seamR)
            cv::line(img, cv::Point(cvRound(bin_w*(i)),0), cv::Point(cvRound(bin_w*(i)),img_h), seam_line_color, 2);
    }

    // Gradient Descent
    // i_min = GradDescent(line, line_der, line_len/2, 0.2, 2, line_len/2);
    // minimum = line.at(i_min);

    // Line at minimum pixel
    cv::line(img, cv::Point( cvRound(bin_w * i_min), 0),
                  cv::Point( cvRound(bin_w * i_min), img_h ), cv::Scalar(0,0,0), 2, 8, 0);

    // Find lesser border of gap
    int idx_border_lesser = 0;
    int px_border_lesser = 0;
    int delta_min = 5 < minimum*0.20 ? 5 : minimum*0.20;
    for (auto it_der = line_der.begin() + i_min, it = line.begin() + i_min;
              it_der != line_der.begin();
              it_der--, it--)
    {
        if ( ((*(it_der) * *(it_der+1)) <= 0) && (*it - minimum > delta_min) )
        {
            idx_border_lesser = std::distance(line_der.begin(), it_der)+1;
            px_border_lesser = *(it+1);
            break;
        }
    }

    // Find bigger border of gap
    int idx_border_bigger = 0;
    int px_border_bigger = 0;
    bool found_bigger_border = false;
    for (auto it_der = line_der.begin() + i_min, it = line.begin() + i_min;
              it_der != line_der.end()-1;
              it_der++, it++)
    {
        if ( ((*(it_der) * *(it_der+1)) <= 0) && (*it - minimum > delta_min) )
        {
            idx_border_bigger = std::distance(line_der.begin(), it_der)-1;
            px_border_bigger = *(it-1);
            found_bigger_border = true;
            break;
        }
    }
    if (not(found_bigger_border))
    {
        idx_border_bigger = line_len-2; // 2 per sicurezza ;)
        px_border_bigger = *(line.begin()+idx_border_bigger);
    }

    cv::line(img, cv::Point( cvRound(bin_w * idx_border_lesser), 0),
                  cv::Point( cvRound(bin_w * idx_border_lesser), img_h ), cv::Scalar(255,255,0), 2, 8, 0);
    cv::line(img, cv::Point( cvRound(bin_w * idx_border_bigger), 0),
                  cv::Point( cvRound(bin_w * idx_border_bigger), img_h ), cv::Scalar(80,127,255), 2, 8, 0);

    // Equalise prominence to smaller one
    if (px_border_bigger > px_border_lesser) {
        for (auto it = line.begin()+idx_border_bigger; it != line.begin() + i_min; it--) {
            if (*it<px_border_lesser) {
                idx_border_bigger = std::distance(line.begin(),it);
                break;
            }
        }
    }
    else {
        for (auto it = line.begin()+idx_border_lesser; it != line.begin() + i_min; it++) {
            if (*it<px_border_bigger) {
                idx_border_lesser = std::distance(line.begin(),it);
                break;
            }
        }
    }

    // Plot extremes of seam
    cv::line(img, cv::Point( cvRound(bin_w * idx_border_lesser), 0),
                  cv::Point( cvRound(bin_w * idx_border_lesser), img_h ), cv::Scalar(255,0,0), 2, 8, 0);
    cv::line(img, cv::Point( cvRound(bin_w * idx_border_bigger), 0),
                  cv::Point( cvRound(bin_w * idx_border_bigger), img_h ), cv::Scalar(0,255,255), 2, 8, 0);

    // Find corresponding points
    cv::Point p_bigger(g_roi_IR.x,g_roi_IR.y),  p_lesser(g_roi_IR.x,g_roi_IR.y);
    int idx_max = idx_border_bigger > idx_border_lesser ? idx_border_bigger : idx_border_lesser;
    for (int idx = 0; idx <= idx_max; idx++, line_iter2++)
    {
        if (idx == idx_border_bigger)
            p_bigger += line_iter2.pos();
        else if (idx == idx_border_lesser)
            p_lesser += line_iter2.pos();
    }

    std::array<cv::Point,2> p_widthI {p_bigger, p_lesser};
    return p_widthI;
}

// -----------------------------------------------------------------------------------------------------------------
std::array<cv::Point,2> Grey_Alg::LinePlot2(cv::Point p1, cv::Point p2, int w_mean, cv::Mat& img, cv::Scalar color, bool good_point, int y_seamR)
{
    cv::LineIterator line_iter(m_img_blur, p1, p2);

    cv::Point p1_p1 = p1 + cv::Point(2,0);
    cv::Point p2_p1 = p2 + cv::Point(2,0);
    cv::LineIterator line_iter_p1(m_img_blur, p1_p1, p2_p1);

    cv::Point p1_m1 = p1 + cv::Point(-2,0);
    cv::Point p2_m1 = p2 + cv::Point(-2,0);
    cv::LineIterator line_iter_m1(m_img_blur, p1_m1, p2_m1);

    cv::LineIterator line_iter2 = line_iter;

    int line_len = line_iter.count;
    double res = pow(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2),0.5)/line_len;
    int max_half_wid = cvRound(1000/g_px_res/res);

    std::vector<int> grey(line_len);
    std::vector<int> deri(line_len);
    std::vector<int> dder(line_len);

    int img_h = img.size().height;
    int img_w = img.size().width;

    // Normalise X
    double bin_w = cvRound( 1.0*img_w / (line_len*1.0) );

    // Grid
    cv::line(img, cv::Point(0,100), cv::Point(img_w,100), cv::Scalar(0,0,0), 1);
    cv::line(img, cv::Point(0,200), cv::Point(img_w,200), cv::Scalar(0,0,0), 1);
    cv::line(img, cv::Point(0,300), cv::Point(img_w,300), cv::Scalar(0,0,0), 1);
    cv::Scalar seam_line_color = cv::Scalar(0, good_point, not(good_point))*255;

    // Data Plot
    int i_min = -1;
    int minimum = 9999;
    int i = 0;
    for( auto iter = grey.begin(); iter < grey.end(); iter++, i++)
    {
        // current pixel
        int pixel = ((int)* (*line_iter++) + (int)* (*line_iter_p1++) + (int)* (*line_iter_m1++)) / 3;
        *iter = pixel;

        // store minimum
        if (pixel < minimum) {minimum = pixel; i_min = std::distance(grey.begin(),iter);}

        // Plot pixels
        if(i>0)
        {
            cv::line(img, cv::Point( cvRound(bin_w*(i-1)), img_h - *(iter-1)),
                          cv::Point( cvRound(bin_w*(i)),   img_h - pixel ), color, 2, 8, 0);
        }

        // Line at seam pixel
        if (line_iter.pos().y == y_seamR)
            cv::line(img, cv::Point(cvRound(bin_w*(i)),0), cv::Point(cvRound(bin_w*(i)),img_h), seam_line_color, 2);
    }

    // Line at minimum pixel
    cv::line(img, cv::Point( cvRound(bin_w * i_min), 0),
                  cv::Point( cvRound(bin_w * i_min), img_h ), cv::Scalar(0,0,0), 2, 8, 0);

    // Derivatives
    for (auto it  = grey.begin()+1, it_d = deri.begin()+1, it_dd = dder.begin()+1;
              it != grey.end()-1;
              it++, it_d++, it_dd++)
    {
        *it_d   = *(it+1) - *(it-1);
        *it_dd  = *(it+1) - 2* *(it) + *(it-1);
    }
    deri.at(0) = 0; deri.at(line_len-1) = 0;
    dder.at(0) = 0; dder.at(line_len-1) = 0;

    // Plot derivative
    int idx = 1;
    for ( auto it_d = deri.begin()+1, it_dd = dder.begin()+1;
               it_d != deri.end();
               it_d++, it_dd++, idx++)
    {
        cv::line(img, cv::Point( cvRound(bin_w*(idx-1)), img_h -300 - *(it_dd-1) ),
                      cv::Point( cvRound(bin_w*(idx)),   img_h -300 - *(it_dd) ), cv::Scalar(0,255,0), 2, 8, 0);
        cv::line(img, cv::Point( cvRound(bin_w*(idx-1)), img_h -300 - *(it_d-1) ),
                      cv::Point( cvRound(bin_w*(idx)),   img_h -300 - *(it_d) ), cv::Scalar(255,0,0), 2, 8, 0);
    }

    // Find lesser border of gap
    int delta_min = 5 < minimum*0.20 ? 5 : minimum*0.20;
    int idx_border_lesser = 0;
    int px_border_lesser = 0;
    idx = i_min ;
    int min_der = 999;
    int min_off = i_min > max_half_wid ? i_min - max_half_wid : 0;
    bool found_critic_point = false;
    for (auto it = grey.begin() + i_min, it_d = deri.begin() + i_min;
              it_d != deri.begin() + min_off;
              it_d--, idx--, it--)
    {
        if ( (*it_d < min_der) && (*it - minimum > delta_min) )
        {
            idx_border_lesser   = idx;
            min_der             = *it_d;
            found_critic_point = true;
        }
        if (found_critic_point && *it_d > min_der + 5)
            break;
    }
    px_border_lesser    = grey.at(idx_border_lesser);

    // Find bigger border of gap
    int idx_border_bigger = line_len -2;
    int px_border_bigger = 0;
    idx = i_min;
    int max_der = -999;
    int max_off = i_min + max_half_wid < line_len - 1 ? i_min + max_half_wid - 1 : line_len - 1;
    found_critic_point = false;
    for (auto it = grey.begin() + i_min, it_d = deri.begin() + i_min;
              it_d != deri.begin() + max_off;
              it_d++, idx++, it++)
    {
        if ( (*it_d > max_der) && (*it - minimum > delta_min) )
        {
            idx_border_bigger   = idx;
            max_der             = *it_d;
            found_critic_point = true;
        }
        if (found_critic_point && *it_d < max_der - 5)
            break;
    }
    px_border_bigger = grey.at(idx_border_bigger);

    cv::line(img, cv::Point( cvRound(bin_w * idx_border_lesser), 0),
                  cv::Point( cvRound(bin_w * idx_border_lesser), img_h ), cv::Scalar(255,255,0), 2, 8, 0);
    cv::line(img, cv::Point( cvRound(bin_w * idx_border_bigger), 0),
                  cv::Point( cvRound(bin_w * idx_border_bigger), img_h ), cv::Scalar(80,127,255), 2, 8, 0);

    // Equalise prominence to smaller one
    /*if (px_border_bigger > px_border_lesser) {
        idx = idx_border_bigger;
        for (auto it  = grey.begin() + idx;
                  idx > i_min;
                  it--, idx--) {
            if (*it < px_border_lesser) {
                idx_border_bigger = idx;
                break;
            }
        }
    }
    else {
        idx = idx_border_lesser;
        for (auto it  = grey.begin() + idx;
                  idx < i_min;
                  it++, idx++) {
            if (*it < px_border_bigger) {
                idx_border_lesser = idx;
                break;
            }
        }
    }

    cv::line(img, cv::Point( cvRound(bin_w * idx_border_lesser), 0),
                  cv::Point( cvRound(bin_w * idx_border_lesser), img_h ), cv::Scalar(255,0,0), 2, 8, 0);
    cv::line(img, cv::Point( cvRound(bin_w * idx_border_bigger), 0),
                  cv::Point( cvRound(bin_w * idx_border_bigger), img_h ), cv::Scalar(0,255,255), 2, 8, 0);*/

    // Find corresponding points
    cv::Point p_bigger(g_roi_IR.x,g_roi_IR.y),  p_lesser(g_roi_IR.x,g_roi_IR.y);
    int idx_max = idx_border_bigger > idx_border_lesser ? idx_border_bigger : idx_border_lesser;
    for (int idx = 0; idx <= idx_max; idx++, line_iter2++)
    {
        if (idx == idx_border_bigger)
            p_bigger += line_iter2.pos();
        else if (idx == idx_border_lesser)
            p_lesser += line_iter2.pos();
    }

    std::array<cv::Point,2> p_widthI {p_bigger, p_lesser};
    return p_widthI;
}

// -----------------------------------------------------------------------------------------------------------------
std::array<cv::Point,2> Grey_Alg::DetectGap(cv::LineIterator line_iter, cv::Mat& img, bool add_plot)
{
    cv::LineIterator line_iter2 = line_iter;
    uint line_len = line_iter.count;

    std::vector<int> line(line_len);
    std::vector<int> line_d(line_len);
    std::vector<int> line_dd(line_len);

    int img_h = img.size().height;
    int img_w = img.size().width;

    int i_min = -1;
    int minimum = 9999;
    int y_offset_plot_d  = 300;
    int y_offset_plot_dd = 300;
    double bin_w = cvRound( 1.0*img_w / (line_len*1.0) );

    int px = 0;
    int px_d = 0;
    int px_dd = 0;

    auto it = line.begin(), it_d = line_d.begin(), it_dd = line_dd.begin();
    for( uint i = 0; i < line_len; i++, it++, it_d++, it_dd++, line_iter++)
    {

        *it     = (int)* (*line_iter);
        *it_d   = *it - px;
        *it_dd  = *it_d - px_d;


        // store minimum pixel
        if (px < minimum) {minimum = px; i_min = i-1;}

        // Plot
        if (add_plot){
            // 1st derivative
            cv::line(img, cv::Point( cvRound(bin_w*(i-1)), img_h - y_offset_plot_d  - px_d ),
                          cv::Point( cvRound(bin_w*(i)),   img_h - y_offset_plot_d  - *it_d ), cv::Scalar(255,0,0), 2, 8, 0);
            // 2nd derivative
            cv::line(img, cv::Point( cvRound(bin_w*(i-1)), img_h - y_offset_plot_dd - px_dd ),
                          cv::Point( cvRound(bin_w*(i)),   img_h - y_offset_plot_dd - *it_dd ), cv::Scalar(0,0,0), 2, 8, 0);
        }

        // update
        px_dd   = *it;
        px_d    = *it_d;
        px      = *it_dd;

    }

    // Line at minimum pixel
    if (add_plot){
        cv::line(img, cv::Point( cvRound(bin_w * i_min), 0),
                      cv::Point( cvRound(bin_w * i_min), img_h ), cv::Scalar(0,0,0), 2, 8, 0);
    }

    // Find lesser border of gap
    int idx_border_lesser = 0;
    int px_border_lesser = 0;
    int delta_min = 5 > minimum*0.20 ? 5 : minimum*0.20;

    for (auto it_dd = line_dd.begin() + i_min, it = line.begin() + i_min;
              it_dd != line_dd.begin();
              it_dd--, it--)
    {
        if ( ((*(it_dd) * *(it_dd+1)) <= 0) && (*it - minimum > delta_min) )
        {
            idx_border_lesser = std::distance(line_dd.begin(), it_dd)+1;
            px_border_lesser = *(it+1);
            break;
        }
    }

    // Find bigger border of gap
    int idx_border_bigger = 0;
    int px_border_bigger = 0;
    for (auto it_dd = line_dd.begin() + i_min, it = line.begin() + i_min;
              it_dd != line_dd.end();
              it_dd++, it++)
    {
        if ( ((*(it_dd) * *(it_dd+1)) <= 0) && (*it - minimum > delta_min) )
        {
            idx_border_bigger = std::distance(line_dd.begin(), it_dd)-1;
            px_border_bigger = *(it-1);
            break;
        }
    }

    // Equalise prominence to smaller one
    if (px_border_bigger > px_border_lesser) {
        for (auto it = line.begin()+idx_border_bigger; it != line.begin(); it--) {
            if (*it<px_border_lesser) {
                idx_border_bigger = std::distance(line.begin(),it);
                break;
            }
        }
    }
    else {
        for (auto it = line.begin()+idx_border_lesser; it != line.end(); it++) {
            if (*it<px_border_bigger) {
                idx_border_lesser = std::distance(line.begin(),it);
                break;
            }
        }
    }

    // Plot extremes of seam
    if (add_plot){
        cv::line(img, cv::Point( cvRound(bin_w * idx_border_lesser), 0),
                 cv::Point( cvRound(bin_w * idx_border_lesser), img_h ), cv::Scalar(255,0,0), 2, 8, 0);
        cv::line(img, cv::Point( cvRound(bin_w * idx_border_bigger), 0),
                 cv::Point( cvRound(bin_w * idx_border_bigger), img_h ), cv::Scalar(0,255,255), 2, 8, 0);
    }

    // Find corresponding points
    cv::Point p_biggerI(g_roi_IR.x,g_roi_IR.y),  p_lesserI(g_roi_IR.x,g_roi_IR.y);
    int idx_max = idx_border_bigger > idx_border_lesser ? idx_border_bigger : idx_border_lesser;

    for (int idx = 0; idx <= idx_max; idx++, line_iter2++)
    {
        if (idx == idx_border_bigger)
            p_biggerI += line_iter2.pos();

        else if (idx == idx_border_lesser)
            p_lesserI += line_iter2.pos();
    }

    std::array<cv::Point,2> p_widthI {p_biggerI, p_lesserI};
    return p_widthI;
}


// -----------------------------------------------------------------------------------------------------------------
void Grey_Alg::LineIterPlot(cv::LineIterator line_iter, cv::Mat& img, cv::Scalar color, bool good_point, int y_vlineR)
{
    int line_len = line_iter.count;

    int img_h = img.size().height;
    int img_w = img.size().width;

    // Normalise Y
    // double maximum;
    // cv::minMaxIdx(line_iter, nullptr, &maximum);
    // cv::normalize(hist, hist, 0, hist_h, cv::NORM_MINMAX, -1, cv::Mat() );

    // Normalise X
    double bin_w = cvRound( 1.0*img_w / (line_len*1.0) );

    // Grid
    for (int i_grid = 1; i_grid < img_h/100; i_grid++)
        cv::line(img, cv::Point(0,i_grid*100), cv::Point(img_w,i_grid*100), cv::Scalar(0,0,0), 1);

    cv::Scalar seam_line_color = cv::Scalar(0, good_point, not(good_point))*255;

    // Data Plot
    for( uint i = 1; i < line_len; i++)
    {
        // current pixel
        int pixel = (int)* (*line_iter++);

        // Plot pixels
        cv::line(img, cv::Point( cvRound(bin_w*(i-1)), img_h -  pixel),
                      cv::Point( cvRound(bin_w*(i)),   img_h - (int)* (*line_iter) ), color, 2, 8, 0);

        // Line at seam pixel
        if (line_iter.pos().y == y_vlineR)
            cv::line(img, cv::Point(cvRound(bin_w*(i)),0), cv::Point(cvRound(bin_w*(i)),img_h), seam_line_color, 2);
    }

}


// -----------------------------------------------------------------------------------------------------------------
void Grey_Alg::saveSpot(const cv::Mat& img, uint n_img)
{
    // spot ROI
    int w_roi_spot      = 80;
    int h_roi_spot      = 120;
    int x_roi_spot_IS   = 0;
    int y_roi_spot_IS   = g_roi_CI.height/2 - h_roi_spot/2;
    cv::Rect roi_spot_IS {x_roi_spot_IS, y_roi_spot_IS, w_roi_spot, h_roi_spot};

    // trim image
    cv::Mat img_spot;
    cvtColor(img(roi_spot_IS), img_spot, cv::COLOR_GRAY2BGR);

    // Add spot
    cv::circle(img_spot,cv::Point(g_spotC.x - g_roi_CI.x - roi_spot_IS.x,
                                  g_spotC.y - g_roi_CI.y - roi_spot_IS.y),3,cv::Scalar(0,0,255),-1);

    // Add number
    cv::putText(img_spot, std::to_string(n_img),cv::Point(5, h_roi_spot/4),cv::FONT_HERSHEY_DUPLEX, 1, CV_RGB(118, 185, 0), 2);

    // save image
    std::string file_name = "img_" +  std::to_string(n_img) + ".bmp";
    boost::filesystem::path spot_save_dir ("/srv/ftp/seam-tracker/img/spot");
    std::string  abs_save_path = spot_save_dir.string() + "/" + file_name;
    imwrite(abs_save_path, img_spot);
}

// -----------------------------------------------------------------------------------------------------------------
void Grey_Alg::LinearFit(const boost::circular_buffer<double>& x_buff, const boost::circular_buffer<double> &y_buff, const boost::circular_buffer<bool>& good_buff, double &m_par, double &q_par, uint idx_start)
{
    try
    {
    // linear fits of X,Y buffers applying "good_buff" mask for valid and invalid points
    // returns nothing for the moment

    uint idx_buffer = idx_start;
    std::vector<uint> idx_good_v;
    double xsum = 0, ysum = 0, x2sum = 0, xysum = 0;
    int n_good_seam = 0;

    auto i_good = good_buff.begin() + idx_start;
    for ( auto i_seam_x = x_buff.begin() + idx_start, i_seam_y = y_buff.begin() + idx_start;
          i_seam_x != x_buff.end();
          i_seam_x++, i_seam_y++, i_good++, idx_buffer++ )
    {
        if (*i_good)
        {
            idx_good_v.push_back(idx_buffer);
            xsum += *i_seam_x;
            ysum += *i_seam_y;
            x2sum += pow(*i_seam_x,2);
            xysum += (*i_seam_x) * (*i_seam_y);
            n_good_seam++;
        }
    }

    m_par = (n_good_seam*xysum-xsum*ysum)/(n_good_seam*x2sum-xsum*xsum);    //calculate slope
    q_par = (x2sum*ysum-xsum*xysum)/(x2sum*n_good_seam-xsum*xsum);          //calculate intercept
    }
    catch (boost::exception const & e){ std::cout << "Grey_Alg::Linear_Fit(): "<< boost::diagnostic_information(e) << std::endl; }
    catch (std::exception const & e){ std::cout << "Grey_Alg::Linear_Fit(): "<< e.what() << " at line " << '__LINE__' << std::endl; }
}


// -----------------------------------------------------------------------------------------------------------------
uint Grey_Alg::GradDescent(const std::vector<int>& val, std::vector<int>& der, uint idx_start, double step, int convergence, uint n_iter_max)
{
    double error = 999;
    uint idx_min = idx_start;
    uint idx = idx_min;
    int val_min = val.at(idx_min);
    uint n_iter = 0;

    while (abs(error) > convergence && n_iter < n_iter_max)
    {
        // Descends gradient
        int grad_sign = der.at(idx) >= 0 ? 1 : -1;
        int grad = der.at(idx - grad_sign); // account for the fact that gradient is descrete: you see a peak in the next pixel
        int idx_step = cvRound(step * grad);

        // Move at least one step each time
        if (abs(idx_step)>=1)
            idx -= idx_step;
        else
            idx -= grad_sign;

        // Evaluates new minimum
        int val_tmp = val.at(idx);
        error = abs(val_tmp - val_min);

        if (val_tmp < val_min)
        {
            val_min = val_tmp;
            idx_min = idx;
        }

        n_iter++;
    }
    return idx_min;
}
