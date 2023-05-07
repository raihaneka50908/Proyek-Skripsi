//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  GPIOCodegen.cpp
//
//  Code generation for function 'GPIOCodegen'
//


// Include files
#include "GPIOCodegen.h"
#include "rt_nonfinite.h"
#include "GPIO.h"

// Function Definitions
namespace coder
{
  namespace raspi
  {
    namespace internal
    {
      GPIOCodegen *GPIOCodegen::init()
      {
        return this;
      }

      int GPIOCodegen::initGPIO()
      {
        static const char cv1[30] = "Unable to configure pin %u \\n";
        int ret;
        char cv[30];
        ret = EXT_GPIO_init(20U, 0);
        if (ret != 0) {
          for (int i = 0; i < 30; i++) {
            cv[i] = cv1[i];
          }

          printf(&cv[0], 20U);
        }

        return ret;
      }

      bool GPIOCodegen::readGPIO()
      {
        static const char cv1[27] = "Error in reading pin %u \\n";
        int ret;
        char cv[27];
        bool value;
        ret = EXT_GPIO_read(20U, &value);
        if (ret != 0) {
          for (ret = 0; ret < 27; ret++) {
            cv[ret] = cv1[ret];
          }

          printf(&cv[0], 20U);
        }

        return value;
      }

      int GPIOCodegen::terminateGPIO()
      {
        static const char cv1[34] = "Error in unsetting GPIO pin %u \\n";
        int ret;
        char cv[34];
        ret = EXT_GPIO_terminate(20U);
        if (ret != 0) {
          for (int i = 0; i < 34; i++) {
            cv[i] = cv1[i];
          }

          printf(&cv[0], 20U);
        }

        return ret;
      }
    }
  }
}

// End of code generation (GPIOCodegen.cpp)
