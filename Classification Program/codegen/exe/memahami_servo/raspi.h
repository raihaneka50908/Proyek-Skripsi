//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  raspi.h
//
//  Code generation for function 'raspi'
//


#ifndef RASPI_H
#define RASPI_H

// Include files
#include "SDLVideoDisplay.h"
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
      class ServoBlock;
    }
  }
}

// Type Definitions
namespace coder
{
  class b_raspi
  {
   public:
    b_raspi *init();
    static raspi::internal::ServoBlock *servo(raspi::internal::ServoBlock
      *iobj_0);
    void matlabCodegenDestructor();
    ~b_raspi();
    b_raspi();
    bool matlabCodegenIsDeleted;
    raspi::internal::codegen::SDLVideoDisplay RaspiDisplay;
  };
}

#endif

// End of code generation (raspi.h)
