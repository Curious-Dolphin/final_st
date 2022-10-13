/* PID controller inspired by Matteo Pacher
 * Available features:
 * - anti wind-up
 * - saturation
 * Author: Davide Boldrin
 */

#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

#include <algorithm>
#include <math.h>
#include <string>
#include "common/common.h"

struct PID_Parameters_t {
  // PID gains
  double Kp;
  double Ti;
  double Td;

  // saturation of the integral term (anti wind up)
  double sat_i;

  // PID saturation
  double sat;

  // control variable deadzone
  double deadzone_in;
  double deadzone_out;
};

class PID_Controller
{
public:

    PID_Controller(PID_Parameters_t params)  {_params = params;}
    void set_params(PID_Parameters_t params) {_params = params;}
    double update(double input, double reference, double dt);
    bool enable_log(std::string save_abs_path);

    void set_pid_gains(double Kp, double Ti, double Td) {_params.Kp = Kp; _params.Ti = Ti; _params.Td = Td;}
    double output()     {return _output;}
    double error()      {return _error_p;}
    double error_dot()  {return _error_d;}
    double error_int()  {return _error_i;}

private:
    double _output;                 // controller output
    PID_Parameters_t _params;       // PID parameters structure

    // P,I,D terms
    double _p_term;                 // proportional part of the output
    double _i_term;                 // integral part of the output
    double _d_term;                 // derivative part of the output
    double _error_i {0};            // integral  error
    double _error_d {0};            // derivative error
    double _error_p {0};            // previous error (used to compute derivative error)
    double _t;                      // time

    bool            m_log_enabled {false};
    std::ofstream   m_log_file;
    std::string     m_save_abs_path;

    double _constrain(double x, double a, double b);

};

#endif // PID_CONTROLLER_H
