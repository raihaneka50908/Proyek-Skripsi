//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  SDLVideoDisplay.h
//
//  Code generation for function 'SDLVideoDisplay'
//


#ifndef SDLVIDEODISPLAY_H
#define SDLVIDEODISPLAY_H

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
      namespace codegen
      {
        class SDLVideoDisplay
        {
         public:
          SDLVideoDisplay *init();
          void matlabCodegenDestructor();
          void release();
          ~SDLVideoDisplay();
          SDLVideoDisplay();
          bool matlabCodegenIsDeleted;
         private:
          int isInitialized;
        };
      }
    }
  }
}

#endif

// End of code generation (SDLVideoDisplay.h)
