#ifndef GREY_ALG_H
#define GREY_ALG_H

#include "common/common.h"
#include <boost/circular_buffer.hpp>
#include <numeric>

class Grey_Alg
{
public:
    Grey_Alg();

    void            add_rob_pose(robCartesian p_robW, robEuler o_robW, uint64_t t_rob_us_syn);
    cv::Point       analyse_image(const cv::Mat &img, uint64_t t_img_us_syn);
    Grey_Alg*       get_ptr();
    bool            getNextEstimate(seamEstimate& estimate);
    bool            is_locked() {bool alg_is_locked = m_fit_locked; return alg_is_locked;}
    void            saveSpot(const cv::Mat& img, uint n_img);
    //cv::Point get_seam_centre();

private:
    double  Perc2Thresh(cv::Mat histogram, double percent);
    void    HistPlot(cv::Mat hist, cv::Mat& img, cv::Scalar color=cv::Scalar(255,0,0));

    std::array<cv::Point,2> LinePlot(cv::Point p1, cv::Point p2, int w_mean, cv::Mat& img, cv::Scalar color, bool good_point, int y_seamR);// non serve ad una sega
    std::array<cv::Point,2> LinePlot2(cv::Point p1, cv::Point p2, int w_mean, cv::Mat& img, cv::Scalar color, bool good_point, int y_seamR);
    void                    LineIterPlot(cv::LineIterator line_iter, cv::Mat& img, cv::Scalar color, bool good_point, int y_vlineR = -1);
    std::array<cv::Point,2> DetectGap(cv::LineIterator line_iter, cv::Mat& img, bool add_plot);

    void LinearFit(const boost::circular_buffer<double>& x_buff, const boost::circular_buffer<double> &y_buff, const boost::circular_buffer<bool>& good_buff, double &m_par, double &q_par, uint idx_start = 0);
    uint GradDescent(const std::vector<int>& val, std::vector<int>& der, uint idx_start, double step, int convergence, uint n_iter_max);
    // ROI
    int         m_w_roi;
    int         m_h_roi;
    int         m_x_roi;
    int         m_y_roi;
    // blurring
    int         m_k_blur = 3;
    // sobel
    int         m_sobel_x_ord = 0;
    int         m_sobel_y_ord = 2;
    int         m_sobel_d_ker = 5;
    // canny
    double      m_corr_cann = 0;
    int         m_ref_lines_cann = 3;
    double      m_gain_lines_cann = 1.5;
    double      m_perc_canny_grow = 0.925;//0.875;
    double      m_perc_canny_enuc = 0.99; //0.975;
    int         m_bin_wid_d = 2;
    const int   m_d_hist_max = 500;
    int         m_min_len_canny;
    // hough
    double      m_min_theta = 75.0*CV_PI/180.0;
    double      m_max_theta = 105.0*CV_PI/180.0;
    double      m_theta_fitW = 0;
    float       m_d_rho_min = 2;  // 40 µm
    float       m_d_rho_max = 10; // 200 µm
    uint        m_n_line2keep = 2;
    // fit
    uint        m_n_fit = 10;
    uint        m_n_fit_recent = 5;
    int         m_d_max = 25;
    int         m_d_max_fit = 25;
    uint        m_n_good_edge_min {3}; // numero minimo di punti per fittare
    bool        m_is_fitting = false;
    int         m_n_fitted_points = 0;
    int         m_n_fitted_points_min = 10;
    double      m_y_edge_fitW;
    int         m_y_edge_fitI = -1;
    double      m_x_robW_bef;
    double      m_m_edgeW2W;
    double      m_q_edgeW2W;
    std::atomic<bool> m_fit_locked {false};
    // bufferz
    boost::circular_buffer<double>       m_x_edgeW_b{m_n_fit+2};
    boost::circular_buffer<double>       m_y_edgeW_b{m_n_fit+2};
    boost::circular_buffer<bool>         m_good_edge_b{m_n_fit+2};
    // modifica 20210702
    boost::circular_buffer<double>       m_x_gapW_b{m_n_fit*3};
    boost::circular_buffer<double>       m_y_gapW_b{m_n_fit*3};
    boost::circular_buffer<bool>         m_good_gap_b{m_n_fit*3};

    boost::circular_buffer<ulong>        m_t_rob_us_b{m_n_fit*4};
    boost::circular_buffer<robCartesian> m_p_robW_b{m_n_fit*4};
    boost::circular_buffer<robEuler>     m_o_robW_b{m_n_fit*4};

    uint                                 theta_avg_count {10};
    boost::circular_buffer<double>       m_theta_fitW_b{theta_avg_count};
    boost::circular_buffer<double>       m_theta_fitI_b{theta_avg_count};

    boost::circular_buffer<int>        m_w_gapI_b{5}; // mod I
    boost::circular_buffer<int>        m_y_gapI_b{5}; // mod II
    // logging
    std::string             m_abs_save_folder {"/srv/ftp/seam-tracker"};
    std::ofstream           m_log_file;
    std::string             m_log_file_name {"log_alg"};
    // images
    cv::Mat     m_img_roi;
    cv::Mat     m_img_blur;
    cv::Mat     m_img_deri;
    cv::Mat     m_img_xdir;
    cv::Mat     m_img_ydir;
    cv::Mat     m_img_cann;
    // robot logging
    seamEstimate    m_estimate;
    bool            m_is_estimate_next{false};
    // other
    uint        m_count_frame = 0;
    uint        count_poses = 0;
    uint        idx_0;
    std::mutex  m_mtx_rob;
    bool        m_debug_mode = true;  

    double      m_m_fit_gap_W2W {0};
    double      m_q_fit_gap_W2W {0};
};

#endif // GREY_ALG_H
