//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  PWMBase2.cpp
//
//  Code generation for function 'PWMBase2'
//


// Include files
#include "PWMBase2.h"
#include "hcsr04_sensor_try_rtwutil.h"
#include "rt_nonfinite.h"
#include "MW_pigs.h"

// Function Definitions
namespace coder
{
  namespace raspi
  {
    namespace internal
    {
      int PWMBase2::terminatePWM(double pinNumber)
      {
        double d;
        unsigned int u;
        d = rt_roundd_snf(pinNumber);
        if (d < 4.294967296E+9) {
          if (d >= 0.0) {
            u = static_cast<unsigned int>(d);
          } else {
            u = 0U;
          }
        } else if (d >= 4.294967296E+9) {
          u = MAX_uint32_T;
        } else {
          u = 0U;
        }

        return EXT_PWMBlock_terminate(u);
      }
    }
  }
}

// End of code generation (PWMBase2.cpp)
