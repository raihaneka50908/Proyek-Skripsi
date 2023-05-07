//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  PWMBase2.h
//
//  Code generation for function 'PWMBase2'
//


#ifndef PWMBASE2_H
#define PWMBASE2_H

// Include files
#include "rtwtypes.h"
#include "MW_pigs.h"
#include <cstddef>
#include <cstdlib>

// Custom Header Code
#include "MW_raspi_init.h"
#include "MW_Pyserver_control.h"

// Type Definitions
namespace coder
{
  namespace raspi
  {
    namespace internal
    {
      class PWMBase2
      {
       public:
        static int terminatePWM();
      };
    }
  }
}

#endif

// End of code generation (PWMBase2.h)
