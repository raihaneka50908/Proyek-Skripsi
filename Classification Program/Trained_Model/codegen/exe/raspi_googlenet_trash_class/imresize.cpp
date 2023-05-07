//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  imresize.cpp
//
//  Code generation for function 'imresize'
//


// Include files
#include "imresize.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <cstring>

// Function Declarations
static double rt_powd_snf(double u0, double u1);
static double rt_roundd_snf(double u);

// Function Definitions
static double rt_powd_snf(double u0, double u1)
{
  double y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else {
    double d;
    double d1;
    d = std::abs(u0);
    d1 = std::abs(u1);
    if (rtIsInf(u1)) {
      if (d == 1.0) {
        y = 1.0;
      } else if (d > 1.0) {
        if (u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (d1 == 0.0) {
      y = 1.0;
    } else if (d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
      y = rtNaN;
    } else {
      y = std::pow(u0, u1);
    }
  }

  return y;
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
  void imresize(const unsigned char Ain[230400], unsigned char Bout[150528])
  {
    static const double dv[224] = { 1.2142857142857144, 2.6428571428571428,
      4.0714285714285712, 5.5, 6.9285714285714288, 8.3571428571428577,
      9.7857142857142865, 11.214285714285715, 12.642857142857144,
      14.071428571428573, 15.500000000000002, 16.928571428571427,
      18.357142857142858, 19.785714285714285, 21.214285714285715,
      22.642857142857142, 24.071428571428573, 25.5, 26.928571428571431,
      28.357142857142858, 29.785714285714288, 31.214285714285715,
      32.642857142857146, 34.071428571428569, 35.5, 36.928571428571431,
      38.357142857142861, 39.785714285714285, 41.214285714285715,
      42.642857142857146, 44.071428571428577, 45.5, 46.928571428571431,
      48.357142857142861, 49.785714285714285, 51.214285714285715,
      52.642857142857146, 54.071428571428577, 55.5, 56.928571428571431,
      58.357142857142861, 59.785714285714292, 61.214285714285715,
      62.642857142857146, 64.071428571428584, 65.500000000000014,
      66.928571428571445, 68.357142857142861, 69.785714285714292,
      71.214285714285722, 72.642857142857153, 74.071428571428584,
      75.500000000000014, 76.928571428571445, 78.357142857142861,
      79.785714285714292, 81.214285714285722, 82.642857142857153,
      84.071428571428584, 85.500000000000014, 86.928571428571445,
      88.357142857142875, 89.785714285714292, 91.214285714285722,
      92.642857142857153, 94.071428571428584, 95.500000000000014,
      96.928571428571445, 98.357142857142875, 99.785714285714292,
      101.21428571428572, 102.64285714285715, 104.07142857142858,
      105.50000000000001, 106.92857142857144, 108.35714285714288,
      109.78571428571429, 111.21428571428572, 112.64285714285715,
      114.07142857142858, 115.50000000000001, 116.92857142857144,
      118.35714285714288, 119.78571428571431, 121.21428571428572,
      122.64285714285715, 124.07142857142858, 125.50000000000001,
      126.92857142857144, 128.35714285714286, 129.78571428571428,
      131.21428571428572, 132.64285714285714, 134.07142857142858, 135.5,
      136.92857142857142, 138.35714285714286, 139.78571428571428,
      141.21428571428572, 142.64285714285714, 144.07142857142858, 145.5,
      146.92857142857142, 148.35714285714286, 149.78571428571428,
      151.21428571428572, 152.64285714285714, 154.07142857142858, 155.5,
      156.92857142857142, 158.35714285714286, 159.78571428571428,
      161.21428571428572, 162.64285714285714, 164.07142857142858, 165.5,
      166.92857142857144, 168.35714285714286, 169.78571428571428,
      171.21428571428572, 172.64285714285714, 174.07142857142858, 175.5,
      176.92857142857144, 178.35714285714286, 179.78571428571428,
      181.21428571428572, 182.64285714285714, 184.07142857142858, 185.5,
      186.92857142857144, 188.35714285714286, 189.78571428571428,
      191.21428571428572, 192.64285714285714, 194.07142857142858, 195.5,
      196.92857142857144, 198.35714285714286, 199.78571428571428,
      201.21428571428572, 202.64285714285714, 204.07142857142858, 205.5,
      206.92857142857144, 208.35714285714286, 209.78571428571428,
      211.21428571428572, 212.64285714285714, 214.07142857142858, 215.5,
      216.92857142857144, 218.35714285714286, 219.78571428571428,
      221.21428571428572, 222.64285714285714, 224.07142857142858, 225.5,
      226.92857142857144, 228.35714285714286, 229.78571428571431,
      231.21428571428572, 232.64285714285714, 234.07142857142858, 235.5,
      236.92857142857144, 238.35714285714286, 239.78571428571431,
      241.21428571428572, 242.64285714285714, 244.07142857142858, 245.5,
      246.92857142857144, 248.35714285714286, 249.78571428571431,
      251.21428571428572, 252.64285714285714, 254.07142857142858, 255.5,
      256.92857142857144, 258.35714285714289, 259.78571428571428,
      261.21428571428572, 262.64285714285717, 264.07142857142856, 265.5,
      266.92857142857144, 268.35714285714289, 269.78571428571428,
      271.21428571428572, 272.64285714285717, 274.07142857142856, 275.5,
      276.92857142857144, 278.35714285714289, 279.78571428571428,
      281.21428571428572, 282.64285714285717, 284.07142857142856, 285.5,
      286.92857142857144, 288.35714285714289, 289.78571428571428,
      291.21428571428572, 292.64285714285717, 294.07142857142856, 295.5,
      296.92857142857144, 298.35714285714289, 299.78571428571428,
      301.21428571428572, 302.64285714285717, 304.07142857142856, 305.5,
      306.92857142857144, 308.35714285714289, 309.78571428571428,
      311.21428571428572, 312.64285714285717, 314.07142857142856, 315.5,
      316.92857142857144, 318.35714285714289, 319.78571428571428 };

    static const double dv1[224] = { 1.0357142857142856, 2.1071428571428572,
      3.1785714285714288, 4.25, 5.3214285714285712, 6.3928571428571432,
      7.4642857142857144, 8.5357142857142847, 9.6071428571428559,
      10.678571428571427, 11.749999999999998, 12.821428571428571,
      13.892857142857142, 14.964285714285714, 16.035714285714285,
      17.107142857142858, 18.178571428571431, 19.25, 20.321428571428573,
      21.392857142857142, 22.464285714285715, 23.535714285714285,
      24.607142857142858, 25.678571428571431, 26.75, 27.821428571428573,
      28.892857142857142, 29.964285714285715, 31.035714285714285,
      32.107142857142854, 33.178571428571431, 34.25, 35.321428571428569,
      36.392857142857146, 37.464285714285715, 38.535714285714285,
      39.607142857142854, 40.678571428571431, 41.75, 42.821428571428569,
      43.892857142857146, 44.964285714285715, 46.035714285714285,
      47.107142857142854, 48.178571428571431, 49.25, 50.321428571428569,
      51.392857142857146, 52.464285714285715, 53.535714285714285,
      54.607142857142854, 55.678571428571431, 56.75, 57.821428571428569,
      58.892857142857146, 59.964285714285715, 61.035714285714285,
      62.107142857142854, 63.178571428571431, 64.249999999999986,
      65.321428571428569, 66.392857142857139, 67.464285714285708,
      68.535714285714278, 69.607142857142847, 70.678571428571416,
      71.749999999999986, 72.821428571428569, 73.892857142857139,
      74.964285714285708, 76.035714285714278, 77.107142857142847,
      78.178571428571416, 79.249999999999986, 80.321428571428569,
      81.392857142857139, 82.464285714285708, 83.535714285714278,
      84.607142857142847, 85.678571428571416, 86.749999999999986,
      87.821428571428569, 88.892857142857139, 89.964285714285708,
      91.035714285714278, 92.107142857142847, 93.178571428571416,
      94.249999999999986, 95.321428571428569, 96.392857142857139,
      97.464285714285708, 98.535714285714278, 99.607142857142847,
      100.67857142857142, 101.74999999999999, 102.82142857142857,
      103.89285714285714, 104.96428571428571, 106.03571428571428,
      107.10714285714285, 108.17857142857142, 109.24999999999999,
      110.32142857142857, 111.39285714285714, 112.46428571428571,
      113.53571428571428, 114.60714285714285, 115.67857142857142,
      116.74999999999999, 117.82142857142857, 118.89285714285714,
      119.96428571428571, 121.03571428571428, 122.10714285714285,
      123.17857142857142, 124.24999999999999, 125.32142857142857,
      126.39285714285714, 127.46428571428571, 128.53571428571428,
      129.60714285714286, 130.67857142857144, 131.75, 132.82142857142858,
      133.89285714285714, 134.96428571428572, 136.03571428571428,
      137.10714285714286, 138.17857142857144, 139.25, 140.32142857142858,
      141.39285714285714, 142.46428571428572, 143.53571428571428,
      144.60714285714286, 145.67857142857144, 146.75, 147.82142857142858,
      148.89285714285714, 149.96428571428572, 151.03571428571428,
      152.10714285714286, 153.17857142857144, 154.25, 155.32142857142858,
      156.39285714285714, 157.46428571428572, 158.53571428571428,
      159.60714285714286, 160.67857142857144, 161.75, 162.82142857142858,
      163.89285714285714, 164.96428571428572, 166.03571428571428,
      167.10714285714286, 168.17857142857144, 169.25, 170.32142857142858,
      171.39285714285714, 172.46428571428572, 173.53571428571428,
      174.60714285714286, 175.67857142857144, 176.75, 177.82142857142858,
      178.89285714285714, 179.96428571428572, 181.03571428571428,
      182.10714285714286, 183.17857142857144, 184.25, 185.32142857142858,
      186.39285714285714, 187.46428571428572, 188.53571428571428,
      189.60714285714286, 190.67857142857144, 191.75, 192.82142857142858,
      193.89285714285714, 194.96428571428572, 196.03571428571428,
      197.10714285714286, 198.17857142857144, 199.25, 200.32142857142858,
      201.39285714285714, 202.46428571428572, 203.53571428571428,
      204.60714285714286, 205.67857142857144, 206.75, 207.82142857142858,
      208.89285714285714, 209.96428571428572, 211.03571428571428,
      212.10714285714286, 213.17857142857144, 214.25, 215.32142857142858,
      216.39285714285714, 217.46428571428572, 218.53571428571428,
      219.60714285714286, 220.67857142857144, 221.75, 222.82142857142858,
      223.89285714285714, 224.96428571428572, 226.03571428571428,
      227.10714285714286, 228.17857142857144, 229.25, 230.32142857142858,
      231.39285714285714, 232.46428571428572, 233.53571428571428,
      234.60714285714286, 235.67857142857144, 236.75, 237.82142857142858,
      238.89285714285714, 239.96428571428572 };

    static const short b_iv[224] = { -2, -1, 1, 2, 4, 5, 6, 8, 9, 11, 12, 14, 15,
      16, 18, 19, 21, 22, 24, 25, 26, 28, 29, 31, 32, 34, 35, 36, 38, 39, 41, 42,
      44, 45, 46, 48, 49, 51, 52, 54, 55, 56, 58, 59, 61, 62, 64, 65, 66, 68, 69,
      71, 72, 74, 75, 76, 78, 79, 81, 82, 84, 85, 86, 88, 89, 91, 92, 94, 95, 96,
      98, 99, 101, 102, 104, 105, 106, 108, 109, 111, 112, 114, 115, 116, 118,
      119, 121, 122, 124, 125, 126, 128, 129, 131, 132, 134, 135, 136, 138, 139,
      141, 142, 144, 145, 146, 148, 149, 151, 152, 154, 155, 156, 158, 159, 161,
      162, 164, 165, 166, 168, 169, 171, 172, 174, 175, 176, 178, 179, 181, 182,
      184, 185, 186, 188, 189, 191, 192, 194, 195, 196, 198, 199, 201, 202, 204,
      205, 206, 208, 209, 211, 212, 214, 215, 216, 218, 219, 221, 222, 224, 225,
      226, 228, 229, 231, 232, 234, 235, 236, 238, 239, 241, 242, 244, 245, 246,
      248, 249, 251, 252, 254, 255, 256, 258, 259, 261, 262, 264, 265, 266, 268,
      269, 271, 272, 274, 275, 276, 278, 279, 281, 282, 284, 285, 286, 288, 289,
      291, 292, 294, 295, 296, 298, 299, 301, 302, 304, 305, 306, 308, 309, 311,
      312, 314, 315, 316 };

    static const short iv1[224] = { -2, -1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
      12, 13, 14, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 31, 32,
      33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 46, 47, 48, 49, 50, 51, 52,
      53, 54, 55, 56, 57, 58, 59, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72,
      73, 74, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 91, 92, 93,
      94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 106, 107, 108, 109, 110,
      111, 112, 113, 114, 115, 116, 117, 118, 119, 121, 122, 123, 124, 125, 126,
      127, 128, 129, 130, 131, 132, 133, 134, 136, 137, 138, 139, 140, 141, 142,
      143, 144, 145, 146, 147, 148, 149, 151, 152, 153, 154, 155, 156, 157, 158,
      159, 160, 161, 162, 163, 164, 166, 167, 168, 169, 170, 171, 172, 173, 174,
      175, 176, 177, 178, 179, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190,
      191, 192, 193, 194, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206,
      207, 208, 209, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222,
      223, 224, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237 };

    static unsigned char APartialResize[161280];
    double absx2[1792];
    double x[1792];
    double b_absx2[1568];
    double b_x[1568];
    double y[224];
    double d;
    double d1;
    double sumVal1;
    int indices[1792];
    int indices_data[1792];
    int b_indices[1568];
    int b_indices_data[1568];
    int aux[640];
    int b_aux[480];
    int a;
    int i2;
    int ix;
    int k;
    int linearInds;
    int trueCount;
    int xoffset;
    signed char b_tmp_data[8];
    signed char tmp_data[8];
    signed char c_tmp_data[7];
    signed char d_tmp_data[7];
    unsigned char u;
    bool copyCols[8];
    bool b_copyCols[7];
    bool exitg1;

    //  Contributions, using pixel indices
    for (k = 0; k < 8; k++) {
      for (xoffset = 0; xoffset < 224; xoffset++) {
        indices[xoffset + 224 * k] = b_iv[xoffset] + k;
      }
    }

    for (i2 = 0; i2 < 1792; i2++) {
      absx2[i2] = indices[i2];
    }

    for (k = 0; k < 8; k++) {
      for (xoffset = 0; xoffset < 224; xoffset++) {
        i2 = xoffset + 224 * k;
        x[i2] = dv[xoffset] - absx2[i2];
      }
    }

    for (k = 0; k < 1792; k++) {
      sumVal1 = std::abs(0.7 * x[k]);
      d = rt_powd_snf(sumVal1, 3.0);
      d1 = 2.5 * (sumVal1 * sumVal1);
      d = 0.7 * (((1.5 * d - d1) + 1.0) * static_cast<double>(sumVal1 <= 1.0) +
                 (((-0.5 * d + d1) - 4.0 * sumVal1) + 2.0) * static_cast<double>
                 ((1.0 < sumVal1) && (sumVal1 <= 2.0)));
      x[k] = d;
    }

    std::memcpy(&y[0], &x[0], 224U * sizeof(double));
    for (k = 0; k < 7; k++) {
      xoffset = (k + 1) * 224;
      for (i2 = 0; i2 < 224; i2++) {
        y[i2] += x[xoffset + i2];
      }
    }

    std::memcpy(&absx2[0], &x[0], 1792U * sizeof(double));
    for (k = 0; k < 8; k++) {
      for (xoffset = 0; xoffset < 224; xoffset++) {
        i2 = xoffset + 224 * k;
        x[i2] = absx2[i2] / y[xoffset];
      }
    }

    //  Create the auxiliary matrix:
    aux[0] = 1;
    aux[320] = 320;
    for (linearInds = 0; linearInds < 319; linearInds++) {
      aux[linearInds + 1] = aux[linearInds] + 1;
      aux[linearInds + 321] = aux[linearInds + 320] - 1;
    }

    //  Mirror the out-of-bounds indices using mod:
    for (linearInds = 0; linearInds < 1792; linearInds++) {
      sumVal1 = static_cast<double>(indices[linearInds]) - 1.0;
      if (sumVal1 == 0.0) {
        k = 0;
      } else {
        k = static_cast<int>(std::fmod(sumVal1, 640.0));
        if (k == 0) {
          k = 0;
        } else {
          if (sumVal1 < 0.0) {
            k += 640;
          }
        }
      }

      indices[linearInds] = aux[k];
    }

    for (i2 = 0; i2 < 8; i2++) {
      copyCols[i2] = false;
    }

    i2 = 0;
    xoffset = -1;
    for (linearInds = 0; linearInds < 8; linearInds++) {
      a = i2 + 224;
      ix = i2;
      i2 += 224;
      xoffset++;
      exitg1 = false;
      while ((!exitg1) && (ix + 1 <= a)) {
        if ((x[ix] == 0.0) || rtIsNaN(x[ix])) {
          ix++;
        } else {
          copyCols[xoffset] = true;
          exitg1 = true;
        }
      }
    }

    trueCount = 0;
    i2 = 0;
    for (linearInds = 0; linearInds < 8; linearInds++) {
      if (copyCols[linearInds]) {
        trueCount++;
        tmp_data[i2] = static_cast<signed char>(linearInds + 1);
        i2++;
      }
    }

    for (i2 = 0; i2 < 224; i2++) {
      for (xoffset = 0; xoffset < trueCount; xoffset++) {
        absx2[xoffset + trueCount * i2] = x[i2 + 224 * (tmp_data[xoffset] - 1)];
      }
    }

    a = 0;
    i2 = 0;
    for (linearInds = 0; linearInds < 8; linearInds++) {
      if (copyCols[linearInds]) {
        a++;
        b_tmp_data[i2] = static_cast<signed char>(linearInds + 1);
        i2++;
      }
    }

    for (i2 = 0; i2 < 224; i2++) {
      for (xoffset = 0; xoffset < a; xoffset++) {
        indices_data[xoffset + a * i2] = indices[i2 + 224 * (b_tmp_data[xoffset]
          - 1)];
      }
    }

    for (xoffset = 0; xoffset < 3; xoffset++) {
      for (i2 = 0; i2 < 240; i2++) {
        a = i2 + 76800 * xoffset;
        for (ix = 0; ix < 224; ix++) {
          sumVal1 = 0.0;

          //  Core - second dimension
          linearInds = static_cast<unsigned char>(trueCount) * ix;
          for (k = 0; k < trueCount; k++) {
            sumVal1 += absx2[linearInds] * static_cast<double>(Ain[a +
              (indices_data[linearInds] - 1) * 240]);
            linearInds++;
          }

          sumVal1 = rt_roundd_snf(sumVal1);
          if (sumVal1 < 256.0) {
            if (sumVal1 >= 0.0) {
              u = static_cast<unsigned char>(sumVal1);
            } else {
              u = 0U;
            }
          } else if (sumVal1 >= 256.0) {
            u = MAX_uint8_T;
          } else {
            u = 0U;
          }

          APartialResize[(i2 + 240 * ix) + 53760 * xoffset] = u;
        }
      }
    }

    //  Resize second dimension
    //  Contributions, using pixel indices
    for (k = 0; k < 7; k++) {
      for (xoffset = 0; xoffset < 224; xoffset++) {
        b_indices[xoffset + 224 * k] = iv1[xoffset] + k;
      }
    }

    for (i2 = 0; i2 < 1568; i2++) {
      b_absx2[i2] = b_indices[i2];
    }

    for (k = 0; k < 7; k++) {
      for (xoffset = 0; xoffset < 224; xoffset++) {
        i2 = xoffset + 224 * k;
        b_x[i2] = dv1[xoffset] - b_absx2[i2];
      }
    }

    for (k = 0; k < 1568; k++) {
      sumVal1 = std::abs(0.93333333333333335 * b_x[k]);
      d = rt_powd_snf(sumVal1, 3.0);
      d1 = 2.5 * (sumVal1 * sumVal1);
      d = 0.93333333333333335 * (((1.5 * d - d1) + 1.0) * static_cast<double>
        (sumVal1 <= 1.0) + (((-0.5 * d + d1) - 4.0 * sumVal1) + 2.0) *
        static_cast<double>((1.0 < sumVal1) && (sumVal1 <= 2.0)));
      b_x[k] = d;
    }

    std::memcpy(&y[0], &b_x[0], 224U * sizeof(double));
    for (k = 0; k < 6; k++) {
      xoffset = (k + 1) * 224;
      for (i2 = 0; i2 < 224; i2++) {
        y[i2] += b_x[xoffset + i2];
      }
    }

    std::memcpy(&b_absx2[0], &b_x[0], 1568U * sizeof(double));
    for (k = 0; k < 7; k++) {
      for (xoffset = 0; xoffset < 224; xoffset++) {
        i2 = xoffset + 224 * k;
        b_x[i2] = b_absx2[i2] / y[xoffset];
      }
    }

    //  Create the auxiliary matrix:
    b_aux[0] = 1;
    b_aux[240] = 240;
    for (linearInds = 0; linearInds < 239; linearInds++) {
      b_aux[linearInds + 1] = b_aux[linearInds] + 1;
      b_aux[linearInds + 241] = b_aux[linearInds + 240] - 1;
    }

    //  Mirror the out-of-bounds indices using mod:
    for (linearInds = 0; linearInds < 1568; linearInds++) {
      sumVal1 = static_cast<double>(b_indices[linearInds]) - 1.0;
      if (sumVal1 == 0.0) {
        k = 0;
      } else {
        k = static_cast<int>(std::fmod(sumVal1, 480.0));
        if (k == 0) {
          k = 0;
        } else {
          if (sumVal1 < 0.0) {
            k += 480;
          }
        }
      }

      b_indices[linearInds] = b_aux[k];
    }

    for (i2 = 0; i2 < 7; i2++) {
      b_copyCols[i2] = false;
    }

    i2 = 0;
    xoffset = -1;
    for (linearInds = 0; linearInds < 7; linearInds++) {
      a = i2 + 224;
      ix = i2;
      i2 += 224;
      xoffset++;
      exitg1 = false;
      while ((!exitg1) && (ix + 1 <= a)) {
        if ((b_x[ix] == 0.0) || rtIsNaN(b_x[ix])) {
          ix++;
        } else {
          b_copyCols[xoffset] = true;
          exitg1 = true;
        }
      }
    }

    trueCount = 0;
    i2 = 0;
    for (linearInds = 0; linearInds < 7; linearInds++) {
      if (b_copyCols[linearInds]) {
        trueCount++;
        c_tmp_data[i2] = static_cast<signed char>(linearInds + 1);
        i2++;
      }
    }

    for (i2 = 0; i2 < 224; i2++) {
      for (xoffset = 0; xoffset < trueCount; xoffset++) {
        b_absx2[xoffset + trueCount * i2] = b_x[i2 + 224 * (c_tmp_data[xoffset]
          - 1)];
      }
    }

    a = 0;
    i2 = 0;
    for (linearInds = 0; linearInds < 7; linearInds++) {
      if (b_copyCols[linearInds]) {
        a++;
        d_tmp_data[i2] = static_cast<signed char>(linearInds + 1);
        i2++;
      }
    }

    for (i2 = 0; i2 < 224; i2++) {
      for (xoffset = 0; xoffset < a; xoffset++) {
        b_indices_data[xoffset + a * i2] = b_indices[i2 + 224 *
          (d_tmp_data[xoffset] - 1)];
      }
    }

    for (xoffset = 0; xoffset < 672; xoffset++) {
      for (i2 = 0; i2 < 224; i2++) {
        sumVal1 = 0.0;
        linearInds = static_cast<unsigned char>(trueCount) * i2;

        //  Core - first dimension
        for (k = 0; k < trueCount; k++) {
          sumVal1 += b_absx2[linearInds] * static_cast<double>(APartialResize
            [(b_indices_data[linearInds] + 240 * xoffset) - 1]);
          linearInds++;
        }

        sumVal1 = rt_roundd_snf(sumVal1);
        if (sumVal1 < 256.0) {
          if (sumVal1 >= 0.0) {
            u = static_cast<unsigned char>(sumVal1);
          } else {
            u = 0U;
          }
        } else if (sumVal1 >= 256.0) {
          u = MAX_uint8_T;
        } else {
          u = 0U;
        }

        Bout[i2 + 224 * xoffset] = u;
      }
    }
  }
}

// End of code generation (imresize.cpp)