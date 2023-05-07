//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  hcsr04_sensor_try_rtwutil.cpp
//
//  Code generation for function 'hcsr04_sensor_try_rtwutil'
//


// Include files
#include "hcsr04_sensor_try_rtwutil.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
double rt_roundd_snf(double u)
{
  double y;
  if (std::abs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = std::floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = std::ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

// End of code generation (hcsr04_sensor_try_rtwutil.cpp)
