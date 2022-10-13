#include "common.h"

// -----------------------------------------------------------------------------------------------------------------
void RotoTranW2I(double x_robW, double y_robW, double t_robW, double x_seamW, double y_seamW, int &x_seamI, int &y_seamI)
{
    /* ROTO-TRANSLATE from world coordinate into image coordinate
     * takes world position of seam and robot and theta_z of robot (radians)
     * returns position in pixels of seam (by reference)
    */

    double a = (x_seamW - x_robW)*1000.0/g_px_res;
    double b = (y_seamW - y_robW)*1000.0/g_px_res;
    double cos_t = cos(t_robW);
    double sin_t = sin(t_robW);

    x_seamI = cvRound(  a * cos_t - b * sin_t + g_spotC.x - g_roi_CI.x);
    y_seamI = cvRound(- a * sin_t - b * cos_t + g_spotC.y - g_roi_CI.y);
}


// -----------------------------------------------------------------------------------------------------------------
void RotoTranI2W(double x_robW, double y_robW, double t_robW, double &x_seamW, double &y_seamW, int x_seamI, int y_seamI)
{
    int x_forerunC = ( x_seamI + g_roi_CI.x - g_spotC.x );    // [px] forerun
    int y_forerunC = ( y_seamI + g_roi_CI.y - g_spotC.y );    // [px] lateral displacement

    x_seamW = x_robW + ( cos(t_robW) * x_forerunC - sin(t_robW) * y_forerunC ) / 1000.0 * g_px_res;
    y_seamW = y_robW - ( sin(t_robW) * x_forerunC + cos(t_robW) * y_forerunC ) / 1000.0 * g_px_res;
}
