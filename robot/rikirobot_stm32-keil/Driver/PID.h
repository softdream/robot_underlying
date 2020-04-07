#ifndef PID_H
#define PID_H

#include "config.h"

#define constrain(amt,low,high) \
	((amt)<(low)?(low):((amt)>(high)?(high):(amt)))

class PID
{
  public:
    PID(float min_val, float max_val, float kp, float ki, float kd);
    double compute(float setpoint, float measured_value);
    void updateConstants(float kp, float ki, float kd);

  private:
    float min_val_;
    float max_val_;
    float kp_;
    float ki_;
    float kd_;
    double integral_;
    double derivative_;
    double prev_error_;
};

#endif
