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
#include "rt_nonfinite.h"
#include "MW_video_display.h"
#include <cstring>

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
            this->releaseWrapper();
          }
        }

        void SDLVideoDisplay::releaseImpl()
        {
          MW_SDL_videoDisplayTerminate(0, 0);
        }

        void SDLVideoDisplay::releaseWrapper() const
        {
          if (this->isSetupComplete) {
            SDLVideoDisplay::releaseImpl();
          }
        }

        void SDLVideoDisplay::setWindowTitle()
        {
          static const char cv1[21] = "Raspberry Pi Display";
          char cv[21];
          const char * icon;
          icon = (const char *)('\x00');
          for (int i = 0; i < 21; i++) {
            cv[i] = cv1[i];
          }

          SDL_WM_SetCaption(&cv[0], icon);
        }

        void SDLVideoDisplay::setup()
        {
          this->isSetupComplete = false;
          this->isInitialized = 1;
          this->PixelFormatEnum = 1;
          MW_SDL_videoDisplayInit(this->PixelFormatEnum, 1, 1, 320.0, 240.0);
          this->isSetupComplete = true;
        }

        void SDLVideoDisplay::setupAndReset()
        {
          this->setup();
        }

        void SDLVideoDisplay::step(const unsigned char varargin_1[76800], const
          unsigned char varargin_2[76800], const unsigned char varargin_3[76800])
        {
          static unsigned char pln1[76800];
          unsigned char pln2[76800];
          unsigned char pln3[76800];
          if (this->isInitialized != 1) {
            this->setupAndReset();
          }

          std::memcpy(&pln1[0], &varargin_1[0], 76800U * sizeof(unsigned char));
          std::memcpy(&pln2[0], &varargin_2[0], 76800U * sizeof(unsigned char));
          std::memcpy(&pln3[0], &varargin_3[0], 76800U * sizeof(unsigned char));
          MW_SDL_videoDisplayOutput(&pln1[0], &pln2[0], &pln3[0]);
        }

        SDLVideoDisplay::SDLVideoDisplay()
        {
          this->matlabCodegenIsDeleted = true;
        }

        SDLVideoDisplay::~SDLVideoDisplay()
        {
          this->matlabCodegenDestructor();
        }

        void SDLVideoDisplay::displayImage(const unsigned char img[230400])
        {
          static unsigned char b_img[76800];
          static unsigned char c_img[76800];
          static unsigned char d_img[76800];
          for (int i = 0; i < 240; i++) {
            for (int i1 = 0; i1 < 320; i1++) {
              int b_img_tmp;
              int img_tmp;
              img_tmp = i + 240 * i1;
              b_img_tmp = i1 + 320 * i;
              b_img[b_img_tmp] = img[img_tmp];
              c_img[b_img_tmp] = img[img_tmp + 76800];
              d_img[b_img_tmp] = img[img_tmp + 153600];
            }
          }

          this->step(b_img, c_img, d_img);
        }

        SDLVideoDisplay *SDLVideoDisplay::init()
        {
          SDLVideoDisplay *obj;
          obj = this;
          obj->isInitialized = 0;
          obj->matlabCodegenIsDeleted = false;
          return obj;
        }

        bool SDLVideoDisplay::isLockedAndNotReleased() const
        {
          return this->isInitialized == 1;
        }

        void SDLVideoDisplay::set_windowTitle()
        {
          SDLVideoDisplay::setWindowTitle();
        }
      }
    }
  }
}

// End of code generation (SDLVideoDisplay.cpp)
