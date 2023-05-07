//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  insertText.cpp
//
//  Code generation for function 'insertText'
//


// Include files
#include "insertText.h"
#include "raspi_googlenet_trash_class_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace coder
{
  void insertTextBox(unsigned char RGB[230400], const ::coder::array<unsigned
                     short, 2U> &ucTextU16, int *textLocationXY_x, int
                     *textLocationXY_y)
  {
    static const unsigned char b_uv[3] = { MAX_uint8_T, MAX_uint8_T, 0U };

    array<unsigned int, 2U> idxNewlineChar;
    array<int, 2U> ii;
    array<unsigned short, 2U> thisCharcodes_1b;
    array<signed char, 2U> b_x;
    array<bool, 2U> x;
    double d;
    double lenFirstSegment;
    double y;
    int b_i;
    int b_nz;
    int i;
    int idx;
    int maxLen;
    int nx;
    int nz;
    bool exitg1;
    x.set_size(1, ucTextU16.size(1));
    nx = ucTextU16.size(0) * ucTextU16.size(1);
    for (i = 0; i < nx; i++) {
      x[i] = (ucTextU16[i] == 10);
    }

    nx = x.size(1);
    idx = 0;
    ii.set_size(1, x.size(1));
    nz = 0;
    exitg1 = false;
    while ((!exitg1) && (nz <= nx - 1)) {
      if (x[nz]) {
        idx++;
        ii[idx - 1] = nz + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          nz++;
        }
      } else {
        nz++;
      }
    }

    if (x.size(1) == 1) {
      if (idx == 0) {
        ii.set_size(1, 0);
      }
    } else {
      if (1 > idx) {
        idx = 0;
      }

      ii.set_size(ii.size(0), idx);
    }

    idxNewlineChar.set_size(1, ii.size(1));
    nx = ii.size(0) * ii.size(1);
    for (i = 0; i < nx; i++) {
      idxNewlineChar[i] = static_cast<unsigned int>(ii[i]);
    }

    if (idxNewlineChar.size(1) == 0) {
      thisCharcodes_1b.set_size(1, ucTextU16.size(1));
      nx = ucTextU16.size(0) * ucTextU16.size(1);
      for (i = 0; i < nx; i++) {
        unsigned int u;
        u = ucTextU16[i] + 1U;
        if (u > 65535U) {
          u = 65535U;
        }

        thisCharcodes_1b[i] = static_cast<unsigned short>(u);
      }

      x.set_size(1, thisCharcodes_1b.size(1));
      nx = thisCharcodes_1b.size(0) * thisCharcodes_1b.size(1);
      for (i = 0; i < nx; i++) {
        x[i] = (uv[thisCharcodes_1b[i] - 1] == 0);
      }

      nx = x.size(1);
      if (x.size(1) == 0) {
        b_nz = 0;
      } else {
        b_nz = x[0];
        for (idx = 2; idx <= nx; idx++) {
          b_nz += x[idx - 1];
        }
      }

      b_x.set_size(1, thisCharcodes_1b.size(1));
      nx = thisCharcodes_1b.size(0) * thisCharcodes_1b.size(1);
      for (i = 0; i < nx; i++) {
        b_x[i] = iv[uv[thisCharcodes_1b[i] - 1]];
      }

      nx = b_x.size(1);
      if (b_x.size(1) == 0) {
        y = 0.0;
      } else {
        y = b_x[0];
        for (idx = 2; idx <= nx; idx++) {
          y += static_cast<double>(b_x[idx - 1]);
        }
      }

      if (y < 2.147483648E+9) {
        if (y >= -2.147483648E+9) {
          idx = static_cast<int>(y);
        } else {
          idx = MIN_int32_T;
        }
      } else {
        idx = MAX_int32_T;
      }

      d = static_cast<double>(b_nz) * 4.0;
      if (d < 2.147483648E+9) {
        if (d >= -2.147483648E+9) {
          nx = static_cast<int>(d);
        } else {
          nx = MIN_int32_T;
        }
      } else {
        nx = MAX_int32_T;
      }

      if ((idx < 0) && (nx < MIN_int32_T - idx)) {
        maxLen = MIN_int32_T;
      } else if ((idx > 0) && (nx > MAX_int32_T - idx)) {
        maxLen = MAX_int32_T;
      } else {
        maxLen = idx + nx;
      }
    } else {
      int i1;
      unsigned int u;
      nx = static_cast<int>(idxNewlineChar[0]) - 1;
      if (1 > nx) {
        nx = 0;
      }

      thisCharcodes_1b.set_size(1, nx);
      for (i = 0; i < nx; i++) {
        u = ucTextU16[i] + 1U;
        if (u > 65535U) {
          u = 65535U;
        }

        thisCharcodes_1b[i] = static_cast<unsigned short>(u);
      }

      b_x.set_size(1, thisCharcodes_1b.size(1));
      nx = thisCharcodes_1b.size(0) * thisCharcodes_1b.size(1);
      for (i = 0; i < nx; i++) {
        b_x[i] = iv[uv[thisCharcodes_1b[i] - 1]];
      }

      nx = b_x.size(1);
      if (b_x.size(1) == 0) {
        lenFirstSegment = 0.0;
      } else {
        lenFirstSegment = b_x[0];
        for (idx = 2; idx <= nx; idx++) {
          lenFirstSegment += static_cast<double>(b_x[idx - 1]);
        }
      }

      x.set_size(1, thisCharcodes_1b.size(1));
      nx = thisCharcodes_1b.size(0) * thisCharcodes_1b.size(1);
      for (i = 0; i < nx; i++) {
        x[i] = (uv[thisCharcodes_1b[i] - 1] == 0);
      }

      nx = x.size(1);
      if (x.size(1) == 0) {
        b_nz = 0;
      } else {
        b_nz = x[0];
        for (idx = 2; idx <= nx; idx++) {
          b_nz += x[idx - 1];
        }
      }

      maxLen = 0;
      i = idxNewlineChar.size(1);
      for (b_i = 0; b_i <= i - 3; b_i++) {
        unsigned int u1;
        u = idxNewlineChar[b_i + 1];
        u1 = idxNewlineChar[b_i + 2];
        if (u + 1U > static_cast<unsigned int>(static_cast<int>(u1) - 1)) {
          i1 = 0;
          idx = 0;
        } else {
          i1 = static_cast<int>(u);
          idx = static_cast<int>(u1) - 1;
        }

        nx = idx - i1;
        thisCharcodes_1b.set_size(1, nx);
        for (idx = 0; idx < nx; idx++) {
          u = ucTextU16[i1 + idx] + 1U;
          if (u > 65535U) {
            u = 65535U;
          }

          thisCharcodes_1b[idx] = static_cast<unsigned short>(u);
        }

        x.set_size(1, thisCharcodes_1b.size(1));
        nx = thisCharcodes_1b.size(0) * thisCharcodes_1b.size(1);
        for (i1 = 0; i1 < nx; i1++) {
          x[i1] = (uv[thisCharcodes_1b[i1] - 1] == 0);
        }

        nx = x.size(1);
        if (x.size(1) == 0) {
          nz = 0;
        } else {
          nz = x[0];
          for (idx = 2; idx <= nx; idx++) {
            nz += x[idx - 1];
          }
        }

        b_x.set_size(1, thisCharcodes_1b.size(1));
        nx = thisCharcodes_1b.size(0) * thisCharcodes_1b.size(1);
        for (i1 = 0; i1 < nx; i1++) {
          b_x[i1] = iv[uv[thisCharcodes_1b[i1] - 1]];
        }

        nx = b_x.size(1);
        if (b_x.size(1) == 0) {
          y = 0.0;
        } else {
          y = b_x[0];
          for (idx = 2; idx <= nx; idx++) {
            y += static_cast<double>(b_x[idx - 1]);
          }
        }

        d = static_cast<double>(nz) * 4.0;
        if (d < 2.147483648E+9) {
          if (d >= -2.147483648E+9) {
            i1 = static_cast<int>(d);
          } else {
            i1 = MIN_int32_T;
          }
        } else {
          i1 = MAX_int32_T;
        }

        d = y + static_cast<double>(i1);
        if (d < 2.147483648E+9) {
          if (d >= -2.147483648E+9) {
            i1 = static_cast<int>(d);
          } else {
            i1 = MIN_int32_T;
          }
        } else {
          i1 = MAX_int32_T;
        }

        if (i1 > maxLen) {
          maxLen = i1;
        }
      }

      if (idxNewlineChar[idxNewlineChar.size(1) - 1] + 1U > static_cast<unsigned
          int>(ucTextU16.size(1))) {
        i = 0;
        i1 = 0;
      } else {
        i = static_cast<int>(idxNewlineChar[idxNewlineChar.size(1) - 1]);
        i1 = ucTextU16.size(1);
      }

      nx = i1 - i;
      thisCharcodes_1b.set_size(1, nx);
      for (i1 = 0; i1 < nx; i1++) {
        u = ucTextU16[i + i1] + 1U;
        if (u > 65535U) {
          u = 65535U;
        }

        thisCharcodes_1b[i1] = static_cast<unsigned short>(u);
      }

      x.set_size(1, thisCharcodes_1b.size(1));
      nx = thisCharcodes_1b.size(0) * thisCharcodes_1b.size(1);
      for (i = 0; i < nx; i++) {
        x[i] = (uv[thisCharcodes_1b[i] - 1] == 0);
      }

      nx = x.size(1);
      if (x.size(1) == 0) {
        nz = 0;
      } else {
        nz = x[0];
        for (idx = 2; idx <= nx; idx++) {
          nz += x[idx - 1];
        }
      }

      b_x.set_size(1, thisCharcodes_1b.size(1));
      nx = thisCharcodes_1b.size(0) * thisCharcodes_1b.size(1);
      for (i = 0; i < nx; i++) {
        b_x[i] = iv[uv[thisCharcodes_1b[i] - 1]];
      }

      nx = b_x.size(1);
      if (b_x.size(1) == 0) {
        y = 0.0;
      } else {
        y = b_x[0];
        for (idx = 2; idx <= nx; idx++) {
          y += static_cast<double>(b_x[idx - 1]);
        }
      }

      d = static_cast<double>(b_nz) * 4.0;
      if (d < 2.147483648E+9) {
        if (d >= -2.147483648E+9) {
          i = static_cast<int>(d);
        } else {
          i = MIN_int32_T;
        }
      } else {
        i = MAX_int32_T;
      }

      d = lenFirstSegment + static_cast<double>(i);
      if (d < 2.147483648E+9) {
        if (d >= -2.147483648E+9) {
          i = static_cast<int>(d);
        } else {
          i = MIN_int32_T;
        }
      } else {
        i = MAX_int32_T;
      }

      nx = maxLen;
      d = static_cast<double>(nz) * 4.0;
      if (d < 2.147483648E+9) {
        if (d >= -2.147483648E+9) {
          i1 = static_cast<int>(d);
        } else {
          i1 = MIN_int32_T;
        }
      } else {
        i1 = MAX_int32_T;
      }

      d = y + static_cast<double>(i1);
      if (d < 2.147483648E+9) {
        if (d >= -2.147483648E+9) {
          i1 = static_cast<int>(d);
        } else {
          i1 = MIN_int32_T;
        }
      } else {
        i1 = MAX_int32_T;
      }

      maxLen = i;
      if (i < nx) {
        maxLen = nx;
      }

      if (maxLen < i1) {
        maxLen = i1;
      }
    }

    if (maxLen < 0) {
      maxLen = 0;
    }

    if (maxLen > 0) {
      if (maxLen > 2147483639) {
        maxLen = MAX_int32_T;
      } else {
        maxLen += 8;
      }
    }

    d = 14.0 * ((static_cast<double>(idxNewlineChar.size(1)) + 1.0) - 1.0);
    if (d < 2.147483648E+9) {
      if (d >= -2.147483648E+9) {
        idx = static_cast<int>(d);
      } else {
        idx = MIN_int32_T;
      }
    } else {
      idx = MAX_int32_T;
    }

    if (idx > 2147483632) {
      nx = MAX_int32_T;
    } else {
      nx = idx + 15;
    }

    if (nx > 2147483639) {
      nx = MAX_int32_T;
    } else {
      nx += 8;
    }

    idx = nx - 1;
    nz = maxLen - 1;
    if (maxLen - 1 >= 1) {
      if (nx - 1 > 240) {
        idx = 240;
      }

      if (maxLen - 1 > 320) {
        nz = 320;
      }

      for (b_i = 0; b_i < 3; b_i++) {
        for (nx = 1; nx <= nz; nx++) {
          for (b_nz = 1; b_nz <= idx; b_nz++) {
            unsigned char tmp11;
            unsigned char tmp22;
            tmp11 = (uint8_T)(0.6 * static_cast<double>(b_uv[b_i]) + 0.5);
            tmp22 = (uint8_T)(0.4 * static_cast<double>(RGB[((b_nz + 240 * (nx -
              1)) + 76800 * b_i) - 1]) + 0.5);
            i = static_cast<int>(static_cast<unsigned int>(tmp11) + tmp22);
            if (static_cast<unsigned int>(i) > 255U) {
              i = 255;
            }

            RGB[((b_nz + 240 * (nx - 1)) + 76800 * b_i) - 1] = static_cast<
              unsigned char>(i);
          }
        }
      }
    }

    *textLocationXY_x = 4;
    *textLocationXY_y = 4;
  }
}

// End of code generation (insertText.cpp)
