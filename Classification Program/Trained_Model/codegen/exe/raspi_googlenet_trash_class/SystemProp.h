//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  SystemProp.h
//
//  Code generation for function 'SystemProp'
//


#ifndef SYSTEMPROP_H
#define SYSTEMPROP_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Custom Header Code
#include "MW_raspi_init.h"
#include "MW_Pyserver_control.h"

// Type Declarations
namespace coder
{
  namespace raspi
  {
    namespace internal
    {
      namespace codegen
      {
        class webcam;
        class SDLVideoDisplay;
      }
    }
  }
}

// Type Definitions
namespace coder
{
  namespace matlab
  {
    namespace system
    {
      namespace coder
      {
        class SystemProp
        {
         public:
          static void matlabCodegenNotifyAnyProp(const ::coder::raspi::internal::
            codegen::webcam *obj);
          static void matlabCodegenNotifyAnyProp(const raspi::internal::codegen::
            SDLVideoDisplay *obj);
        };
      }
    }
  }
}

#endif

// End of code generation (SystemProp.h)
