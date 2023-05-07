//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  GPIOCodegen.h
//
//  Code generation for function 'GPIOCodegen'
//


#ifndef GPIOCODEGEN_H
#define GPIOCODEGEN_H

// Include files
#include "rtwtypes.h"
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
      class GPIOCodegen
      {
       public:
        GPIOCodegen *init();
        static int terminateGPIO(double pinNumber);
        static int initGPIO(double pinNumber, double direction);
        static bool readGPIO(double pinNumber);
        static void writeGPIO(double pinNumber, double value);
      };
    }
  }
}

#endif

// End of code generation (GPIOCodegen.h)
