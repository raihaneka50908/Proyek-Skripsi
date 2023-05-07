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
#include <cmath>

// Function Declarations
static double rt_roundd_snf(double u);

// Function Definitions
namespace coder
{
  namespace raspi
  {
    namespace internal
    {
      void ServoBlock::release()
      {
        if (this->isInitialized == 1) {
          this->isInitialized = 2;
        }
      }
    }
  }
}

static double rt_roundd_snf(double u)
{
  double y;
  if (std::abs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = std::floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = std::ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

namespace coder
{
  namespace raspi
  {
    namespace internal
    {
      void ServoBlock::ServoBase2_writePosition()
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

      void ServoBlock::matlabCodegenDestructor()
      {
        if (!this->matlabCodegenIsDeleted) {
          this->matlabCodegenIsDeleted = true;
          this->release();
        }
      }

      void ServoBlock::set_PinNumber(double value)
      {
        double d;
        unsigned int u;
        d = rt_roundd_snf(value);
        if (d < 4.294967296E+9) {
          if (d >= 0.0) {
            u = static_cast<unsigned int>(d);
          } else {
            u = 0U;
          }
        } else if (d >= 4.294967296E+9) {
          u = MAX_uint32_T;
        } else {
          u = 0U;
        }

        this->PinNumber = u;
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
