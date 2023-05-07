//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  webcam.h
//
//  Code generation for function 'webcam'
//


#ifndef WEBCAM_H
#define WEBCAM_H

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
        class webcam
        {
         public:
          ::coder::raspi::internal::codegen::webcam *init();
          bool isLockedAndNotReleased() const;
          void snapshot(unsigned char image[230400]);
          void step(unsigned char varargout_1[230400], double *varargout_2);
          void setupAndReset();
          void setup();
          void matlabCodegenDestructor();
          void release();
          void releaseWrapper() const;
          ~webcam();
          webcam();
         protected:
          void releaseImpl() const;
         private:
          void SystemCore_delete();
         public:
          bool matlabCodegenIsDeleted;
          double searchMode;
          char DeviceName[11];
         private:
          int isInitialized;
          bool isSetupComplete;
          bool Initialized;
          unsigned char DeviceNumber;
        };
      }
    }
  }
}

#endif

// End of code generation (webcam.h)
