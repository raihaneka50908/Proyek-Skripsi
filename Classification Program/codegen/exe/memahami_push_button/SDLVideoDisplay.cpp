//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  SDLVideoDisplay.cpp
//
//  Code generation for function 'SDLVideoDisplay'
//


// Include files
#include "SDLVideoDisplay.h"

// Function Definitions
namespace coder
{
  namespace raspi
  {
    namespace internal
    {
      namespace codegen
      {
        void SDLVideoDisplay::SystemCore_delete()
        {
          this->release();
        }

        void SDLVideoDisplay::matlabCodegenDestructor()
        {
          if (!this->matlabCodegenIsDeleted) {
            this->matlabCodegenIsDeleted = true;
            this->SystemCore_delete();
          }
        }

        void SDLVideoDisplay::release()
        {
          if (this->isInitialized == 1) {
            this->isInitialized = 2;
          }
        }

        SDLVideoDisplay::SDLVideoDisplay()
        {
          this->matlabCodegenIsDeleted = true;
        }

        SDLVideoDisplay::~SDLVideoDisplay()
        {
          this->matlabCodegenDestructor();
        }

        SDLVideoDisplay *SDLVideoDisplay::init()
        {
          SDLVideoDisplay *obj;
          obj = this;
          obj->matlabCodegenIsDeleted = false;
          return obj;
        }
      }
    }
  }
}

// End of code generation (SDLVideoDisplay.cpp)
