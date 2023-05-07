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
          bool isLockedAndNotReleased() const;
          static void set_windowTitle();
          static void setWindowTitle();
          void displayImage(const unsigned char img[230400]);
          void step(const unsigned char varargin_1[76800], const unsigned char
                    varargin_2[76800], const unsigned char varargin_3[76800]);
          void setupAndReset();
          void setup();
          void matlabCodegenDestructor();
          void release();
          void releaseWrapper() const;
          ~SDLVideoDisplay();
          SDLVideoDisplay();
         protected:
          static void releaseImpl();
         private:
          void SystemCore_delete();
         public:
          bool matlabCodegenIsDeleted;
         private:
          int isInitialized;
          bool isSetupComplete;
          int PixelFormatEnum;
        };
      }
    }
  }
}

#endif

// End of code generation (SDLVideoDisplay.h)
