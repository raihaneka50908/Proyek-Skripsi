//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  ServoBlock.cpp
//
//  Code generation for function 'ServoBlock'
//


// Include files
#include "ServoBlock.h"
#include "ProcessConstructorArguments.h"
#include "rt_nonfinite.h"
#include "MW_pigs.h"

// Function Definitions
namespace coder
{
  namespace raspi
  {
    namespace internal
    {
      void ServoBlock::SystemCore_delete()
      {
        this->release();
      }

      void ServoBlock::matlabCodegenDestructor()
      {
        if (!this->matlabCodegenIsDeleted) {
          this->matlabCodegenIsDeleted = true;
          this->SystemCore_delete();
        }
      }

      void ServoBlock::release()
      {
        if (this->isInitialized == 1) {
          this->isInitialized = 2;
        }
      }

      void ServoBlock::ServoBase2_writePosition()
      {
        if (!this->Initialized) {
          this->initServo();
        }

        EXT_SERVO_write(this->PinNumber, 0.0, 1.0E+6 * this->MinPulseDuration,
                        1.0E+6 * this->MaxPulseDuration);
      }

      void ServoBlock::b_ServoBase2_writePosition()
      {
        if (!this->Initialized) {
          this->initServo();
        }

        EXT_SERVO_write(this->PinNumber, 180.0, 1.0E+6 * this->MinPulseDuration,
                        1.0E+6 * this->MaxPulseDuration);
      }

      ServoBlock::ServoBlock()
      {
        this->matlabCodegenIsDeleted = true;
      }

      ServoBlock::~ServoBlock()
      {
        this->matlabCodegenDestructor();
      }

      ServoBlock *ServoBlock::init()
      {
        ServoBlock *obj;
        obj = this;
        obj->Initialized = false;
        matlab::system::coder::ProcessConstructorArguments::b_do(obj);
        obj->matlabCodegenIsDeleted = false;
        return obj;
      }

      void ServoBlock::initServo()
      {
        static const char cv1[53] =
          "Unable to configure pin %u for servo pulse output.\\n";
        int ret;
        char cv[53];
        ret = EXT_SERVO_init(this->PinNumber);
        if (ret == 0) {
          this->Initialized = true;
        } else {
          for (ret = 0; ret < 53; ret++) {
            cv[ret] = cv1[ret];
          }

          printf(&cv[0], this->PinNumber);
        }
      }

      void ServoBlock::set_PinNumber()
      {
        this->PinNumber = 12U;
      }

      void ServoBlock::writePosition()
      {
        if (!this->Initialized) {
          this->initServo();
        }

        EXT_SERVO_write(this->PinNumber, 90.0, 1.0E+6 * this->MinPulseDuration,
                        1.0E+6 * this->MaxPulseDuration);
      }
    }
  }
}

// End of code generation (ServoBlock.cpp)
