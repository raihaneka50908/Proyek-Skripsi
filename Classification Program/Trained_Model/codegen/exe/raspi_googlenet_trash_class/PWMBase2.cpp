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
#include "rt_nonfinite.h"
#include "MW_pigs.h"

// Function Definitions
namespace coder
{
  namespace raspi
  {
    namespace internal
    {
      int PWMBase2::terminatePWM()
      {
        return EXT_PWMBlock_terminate(20U);
      }
    }
  }
}

// End of code generation (PWMBase2.cpp)
