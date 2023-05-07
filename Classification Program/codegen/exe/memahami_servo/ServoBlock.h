//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  ServoBlock.h
//
//  Code generation for function 'ServoBlock'
//


#ifndef SERVOBLOCK_H
#define SERVOBLOCK_H

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
      class ServoBlock
      {
       public:
        ServoBlock *init();
        void set_PinNumber(double value);
        void initServo();
        void writePosition();
        void ServoBase2_writePosition();
        void matlabCodegenDestructor();
        void release();
        ~ServoBlock();
        ServoBlock();
        bool matlabCodegenIsDeleted;
        unsigned int PinNumber;
        double MinPulseDuration;
        double MaxPulseDuration;
       protected:
        bool Initialized;
       private:
        int isInitialized;
      };
    }
  }
}

#endif

// End of code generation (ServoBlock.h)
