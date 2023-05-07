//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  SystemProp.cpp
//
//  Code generation for function 'SystemProp'
//


// Include files
#include "SystemProp.h"
#include "SDLVideoDisplay.h"
#include "rt_nonfinite.h"
#include "webcam.h"

// Function Definitions
namespace coder
{
  namespace matlab
  {
    namespace system
    {
      namespace coder
      {
        void SystemProp::matlabCodegenNotifyAnyProp(const ::coder::raspi::
          internal::codegen::webcam *obj)
        {
          obj->isLockedAndNotReleased();
        }

        void SystemProp::matlabCodegenNotifyAnyProp(const raspi::internal::
          codegen::SDLVideoDisplay *obj)
        {
          obj->isLockedAndNotReleased();
        }
      }
    }
  }
}

// End of code generation (SystemProp.cpp)
