//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  rt_nonfinite.h
//
//  Code generation for function 'hcsr04_sensor_try'
//


#ifndef RT_NONFINITE_H
#define RT_NONFINITE_H

// Include files
#include "rtwtypes.h"

// Custom Header Code
#include "MW_raspi_init.h"
#include "MW_Pyserver_control.h"
#ifdef __cplusplus

extern "C" {

#endif

  extern real_T rtInf;
  extern real_T rtMinusInf;
  extern real_T rtNaN;
  extern real32_T rtInfF;
  extern real32_T rtMinusInfF;
  extern real32_T rtNaNF;
  extern boolean_T rtIsInf(real_T value);
  extern boolean_T rtIsInfF(real32_T value);
  extern boolean_T rtIsNaN(real_T value);
  extern boolean_T rtIsNaNF(real32_T value);

#ifdef __cplusplus

}
#endif
#endif

// End of code generation (rt_nonfinite.h)
