//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  ProcessConstructorArguments.cpp
//
//  Code generation for function 'ProcessConstructorArguments'
//


// Include files
#include "ProcessConstructorArguments.h"
#include "ServoBlock.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace coder
{
  namespace matlab
  {
    namespace system
    {
      namespace coder
      {
        void ProcessConstructorArguments::b_do(raspi::internal::ServoBlock *obj)
        {
          obj->set_PinNumber(12.0);
          obj->MinPulseDuration = 0.001;
          obj->MaxPulseDuration = 0.002;
        }
      }
    }
  }
}

// End of code generation (ProcessConstructorArguments.cpp)
