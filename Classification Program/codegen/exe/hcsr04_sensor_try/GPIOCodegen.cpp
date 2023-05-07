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
#include "hcsr04_sensor_try_rtwutil.h"
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

      int GPIOCodegen::initGPIO(double pinNumber, double direction)
      {
        static const char cv1[30] = "Unable to configure pin %u \\n";
        double d;
        double d1;
        int ret;
        unsigned int u;
        char cv[30];
        unsigned char u1;
        d = rt_roundd_snf(pinNumber);
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

        d1 = rt_roundd_snf(direction);
        if (d1 < 256.0) {
          if (d1 >= 0.0) {
            u1 = static_cast<unsigned char>(d1);
          } else {
            u1 = 0U;
          }
        } else if (d1 >= 256.0) {
          u1 = MAX_uint8_T;
        } else {
          u1 = 0U;
        }

        ret = EXT_GPIO_init(u, u1);
        if (ret != 0) {
          for (int i = 0; i < 30; i++) {
            cv[i] = cv1[i];
          }

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

          printf(&cv[0], u);
        }

        return ret;
      }

      bool GPIOCodegen::readGPIO(double pinNumber)
      {
        static const char cv1[27] = "Error in reading pin %u \\n";
        double d;
        int ret;
        unsigned int u;
        char cv[27];
        bool value;
        d = rt_roundd_snf(pinNumber);
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

        ret = EXT_GPIO_read(u, &value);
        if (ret != 0) {
          for (ret = 0; ret < 27; ret++) {
            cv[ret] = cv1[ret];
          }

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

          printf(&cv[0], u);
        }

        return value;
      }

      int GPIOCodegen::terminateGPIO(double pinNumber)
      {
        static const char cv1[34] = "Error in unsetting GPIO pin %u \\n";
        double d;
        int ret;
        unsigned int u;
        char cv[34];
        d = rt_roundd_snf(pinNumber);
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

        ret = EXT_GPIO_terminate(u);
        if (ret != 0) {
          for (int i = 0; i < 34; i++) {
            cv[i] = cv1[i];
          }

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

          printf(&cv[0], u);
        }

        return ret;
      }

      void GPIOCodegen::writeGPIO(double pinNumber, double value)
      {
        static const char cv1[26] = "Unable to write pin %u \\n";
        double d;
        double d1;
        int ret;
        unsigned int u;
        char cv[26];
        unsigned char u1;
        d = rt_roundd_snf(pinNumber);
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

        d1 = rt_roundd_snf(value);
        if (d1 < 256.0) {
          if (d1 >= 0.0) {
            u1 = static_cast<unsigned char>(d1);
          } else {
            u1 = 0U;
          }
        } else if (d1 >= 256.0) {
          u1 = MAX_uint8_T;
        } else {
          u1 = 0U;
        }

        ret = EXT_GPIO_write(u, u1);
        if (ret != 0) {
          for (ret = 0; ret < 26; ret++) {
            cv[ret] = cv1[ret];
          }

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

          printf(&cv[0], u);
        }
      }
    }
  }
}

// End of code generation (GPIOCodegen.cpp)
