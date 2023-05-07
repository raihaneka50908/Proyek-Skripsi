//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  webcam.cpp
//
//  Code generation for function 'webcam'
//


// Include files
#include "webcam.h"
#include "SystemProp.h"
#include "rt_nonfinite.h"
#include "availableWebcam.h"
#include "stdio.h"
#include "v4l2_cam.h"

// Function Definitions
namespace coder
{
  namespace raspi
  {
    namespace internal
    {
      namespace codegen
      {
        void webcam::SystemCore_delete()
        {
          this->release();
        }

        void webcam::matlabCodegenDestructor()
        {
          if (!this->matlabCodegenIsDeleted) {
            this->matlabCodegenIsDeleted = true;
            this->SystemCore_delete();
          }
        }

        void webcam::release()
        {
          if (this->isInitialized == 1) {
            this->isInitialized = 2;
            this->releaseWrapper();
          }
        }

        void webcam::releaseImpl() const
        {
          if (this->Initialized) {
            EXT_webcamTerminate(1, this->DeviceNumber);
          }
        }

        void webcam::releaseWrapper() const
        {
          if (this->isSetupComplete) {
            this->releaseImpl();
          }
        }

        void webcam::setup()
        {
          static const char cv2[22] = "Error opening camera.";
          int status;
          char cv1[22];
          char cv[11];
          unsigned char resolutionStatus;
          this->isSetupComplete = false;
          this->isInitialized = 1;
          getCameraList();
          if (this->searchMode != 0.0) {
            for (status = 0; status < 11; status++) {
              cv[status] = this->DeviceName[status];
            }

            this->DeviceNumber = getCameraAddrIndex(&cv[0], 11U);
          }

          resolutionStatus = validateResolution(this->DeviceNumber, 320, 240);
          if (resolutionStatus != 0) {
            status = EXT_webcamInit(1, this->DeviceNumber, 0, 0, 0, 0, 320U,
              240U, 2U, 2U, 1U, 0.033333333333333333);
            if (status == 0) {
              this->Initialized = true;
            } else {
              for (status = 0; status < 22; status++) {
                cv1[status] = cv2[status];
              }

              printf(&cv1[0]);
            }
          }

          this->isSetupComplete = true;
        }

        void webcam::setupAndReset()
        {
          this->setup();
        }

        void webcam::step(unsigned char varargout_1[230400], double *varargout_2)
        {
          static unsigned char pln0[76800];
          unsigned char pln1[76800];
          unsigned char pln2[76800];
          if (this->isInitialized != 1) {
            this->setupAndReset();
          }

          *varargout_2 = 0.0;
          if (this->Initialized) {
            EXT_webcamCapture(1, this->DeviceNumber, varargout_2, &pln0[0],
                              &pln1[0], &pln2[0]);
            for (int i = 0; i < 320; i++) {
              for (int i1 = 0; i1 < 240; i1++) {
                int b_varargout_1_tmp;
                int varargout_1_tmp;
                varargout_1_tmp = i + 320 * i1;
                b_varargout_1_tmp = i1 + 240 * i;
                varargout_1[b_varargout_1_tmp] = pln0[varargout_1_tmp];
                varargout_1[b_varargout_1_tmp + 76800] = pln1[varargout_1_tmp];
                varargout_1[b_varargout_1_tmp + 153600] = pln2[varargout_1_tmp];
              }
            }
          }
        }

        webcam::webcam()
        {
          this->matlabCodegenIsDeleted = true;
        }

        webcam::~webcam()
        {
          this->matlabCodegenDestructor();
        }

        ::coder::raspi::internal::codegen::webcam *webcam::init()
        {
          static const char cv[11] = { '/', 'd', 'e', 'v', '/', 'v', 'i', 'd',
            'e', 'o', '0' };

          ::coder::raspi::internal::codegen::webcam *obj;
          obj = this;
          obj->Initialized = false;
          for (int i = 0; i < 11; i++) {
            obj->DeviceName[i] = cv[i];
          }

          obj->isInitialized = 0;
          obj->DeviceNumber = 1U;
          matlab::system::coder::SystemProp::matlabCodegenNotifyAnyProp(obj);
          obj->searchMode = 0.0;
          obj->matlabCodegenIsDeleted = false;
          return obj;
        }

        bool webcam::isLockedAndNotReleased() const
        {
          return this->isInitialized == 1;
        }

        void webcam::snapshot(unsigned char image[230400])
        {
          double ts;
          this->step(image, &ts);
        }
      }
    }
  }
}

// End of code generation (webcam.cpp)
