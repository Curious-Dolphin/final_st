/* PID controller inspired by Matteo Pacher
 * Available features:
 * - anti wind-up
 * - saturation
 * Author: Davide Boldrin
 */
#include "pid_controller.h"

// ----------------------------------------------------------------------------------------------------------
double PID_Controller::update(double input, double reference, double dt) {

    // error computation
  double error = reference - input; // sign of feedback action is already inverted

  // deadzone for the error
  if(abs(error) < _params.deadzone_in){
    error = 0.0;
  }

  // proportional term
  _p_term = _params.Kp * error;

  // integral term
  _error_i += error * dt;
  _error_i  = _constrain(_error_i, -_params.sat_i, +_params.sat_i);
  _i_term   = _error_i * (_params.Kp / _params.Ti);

  // derivative term
  _error_d  = (error - _error_p)/dt;
  _error_p  = error;
  _d_term   = _error_d * (_params.Td * _params.Kp);

  // PID
  _output = _constrain( _p_term + _i_term + _d_term, -_params.sat, _params.sat);

  // deadzone for the cotrol input
  if(abs(_output) < _params.deadzone_out){
    _output = 0.0;
  }

  if (m_log_enabled)
  {
      m_log_file.open(m_save_abs_path, std::ios::app);
      if(m_log_file.is_open() )
      {
          m_log_file << reference << '\t' << input << '\t'
                     << _p_term << '\t' << _d_term << '\t' << _i_term << '\t'
                     << _error_p << '\t' << _error_d << '\t' << _error_i << '\t'
                     << _output <<'\n';
          m_log_file.close();
      }
  }

  return _output;
}

// ----------------------------------------------------------------------------------------------------------
bool PID_Controller::enable_log(std::string save_abs_path)
{
    m_save_abs_path = save_abs_path;
    m_log_file.open(m_save_abs_path, std::ios::app);
    m_log_enabled = true;
    if (m_log_file.is_open() )
    {
        m_log_file << "#1) ref" << '\t' << "2) input" << '\t'
                   << "3) p_term" << '\t' << "4) d_term" << '\t' << "5) _i_term" << '\t'
                   << "6) error" << '\t' << "7) error_d" << '\t' << "8) error_p" << '\t'
                   << "9) output" <<'\n';
        m_log_file.close();
        return true;
    }
    return false;
}

// ----------------------------------------------------------------------------------------------------------
double PID_Controller::_constrain(double val, double min_val, double max_val){
  double output = 0;
  output = std::max(val, min_val);
  output = std::min(output, max_val);
  return output;
}
