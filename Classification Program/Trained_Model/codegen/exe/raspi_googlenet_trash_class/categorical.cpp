//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  categorical.cpp
//
//  Code generation for function 'categorical'
//


// Include files
#include "categorical.h"
#include "anonymous_function.h"
#include "introsort.h"
#include "raspi_googlenet_trash_class_types.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "strtrim.h"
#include "coder_array.h"
#include <cstring>

// Function Declarations
static int MultiWord2sLong(const unsigned int u[]);
static void MultiWordAdd(const unsigned int u1[], const unsigned int u2[],
  unsigned int y[], int n);
static void sLong2uMultiWordSat(int u1, unsigned int y[], int n);
static void sMultiWord2uMultiWordSat(const unsigned int u1[], int n1, unsigned
  int y[], int n);
static void uMultiWord2MultiWord(const unsigned int u1[], int n1, unsigned int
  y[], int n);
static void uMultiWord2uMultiWordSat(const unsigned int u1[], int n1, unsigned
  int y[], int n);

// Function Definitions
static int MultiWord2sLong(const unsigned int u[])
{
  return static_cast<int>(u[0]);
}

static void MultiWordAdd(const unsigned int u1[], const unsigned int u2[],
  unsigned int y[], int n)
{
  int carry = 0;
  for (int i = 0; i < n; i++) {
    unsigned int u1i;
    unsigned int yi;
    u1i = u1[i];
    yi = (u1i + u2[i]) + carry;
    y[i] = yi;
    if (static_cast<unsigned int>(carry) != 0U) {
      carry = (yi <= u1i);
    } else {
      carry = (yi < u1i);
    }
  }
}

static void sLong2uMultiWordSat(int u1, unsigned int y[], int n)
{
  unsigned int u;
  u = static_cast<unsigned int>(u1);
  sMultiWord2uMultiWordSat((unsigned int *)&u, 1, y, n);
}

static void sMultiWord2uMultiWordSat(const unsigned int u1[], int n1, unsigned
  int y[], int n)
{
  int i;
  unsigned int ys;
  bool doSaturation;
  if ((u1[n1 - 1] & 2147483648U) != 0U) {
    ys = MAX_uint32_T;
  } else {
    ys = 0U;
  }

  doSaturation = (ys != 0U);
  i = n1 - 1;
  while ((!doSaturation) && (i >= n)) {
    doSaturation = (u1[i] != 0U);
    i--;
  }

  if (doSaturation) {
    ys = ~ys;
    for (i = 0; i < n; i++) {
      y[i] = ys;
    }
  } else {
    int nc;
    if (n1 < n) {
      nc = n1;
    } else {
      nc = n;
    }

    if (0 <= nc - 1) {
      std::memcpy(&y[0], &u1[0], nc * sizeof(unsigned int));
    }

    for (i = 0; i < nc; i++) {
    }

    while (i < n) {
      y[i] = ys;
      i++;
    }
  }
}

static void uMultiWord2MultiWord(const unsigned int u1[], int n1, unsigned int
  y[], int n)
{
  int nm;
  if (n1 < n) {
    nm = n1;
  } else {
    nm = n;
  }

  if (0 <= nm - 1) {
    std::memcpy(&y[0], &u1[0], nm * sizeof(unsigned int));
  }

  if ((n > n1) && (nm <= n - 1)) {
    std::memset(&y[nm], 0, (n - nm) * sizeof(unsigned int));
  }
}

static void uMultiWord2uMultiWordSat(const unsigned int u1[], int n1, unsigned
  int y[], int n)
{
  int i;
  bool doSaturation = false;
  i = n1 - 1;
  while ((!doSaturation) && (i >= n)) {
    doSaturation = (u1[i] != 0U);
    i--;
  }

  if (doSaturation) {
    for (i = 0; i < n; i++) {
      y[i] = MAX_uint32_T;
    }
  } else {
    int nc;
    if (n1 < n) {
      nc = n1;
    } else {
      nc = n;
    }

    if (0 <= nc - 1) {
      std::memcpy(&y[0], &u1[0], nc * sizeof(unsigned int));
    }

    for (i = 0; i < nc; i++) {
    }

    while (i < n) {
      y[i] = 0U;
      i++;
    }
  }
}

namespace coder
{
  void categorical::cellstr(cell_wrap_7 b[1]) const
  {
    static const uint64m_T r2 = { { 1U, 0U }// chunks
    };

    static const char cv[11] = { '<', 'u', 'n', 'd', 'e', 'f', 'i', 'n', 'e',
      'd', '>' };

    bounded_array<cell_wrap_7, 3U, 1U> names;
    uint64m_T r5;
    uint64m_T r6;
    uint96m_T r;
    uint96m_T r3;
    uint96m_T r4;
    int i;
    int loop_ub;
    names.size[0] = this->categoryNames.size[0] + 1;
    names.data[0].f1.set_size(1, 11);
    for (i = 0; i < 11; i++) {
      names.data[0].f1[i] = cv[i];
    }

    i = this->categoryNames.size[0];
    for (int b_i = 0; b_i < i; b_i++) {
      names.data[b_i + 1].f1.set_size(1, this->categoryNames.data[b_i].f1.size(1));
      loop_ub = this->categoryNames.data[b_i].f1.size(0) *
        this->categoryNames.data[b_i].f1.size(1);
      for (int i1 = 0; i1 < loop_ub; i1++) {
        names.data[b_i + 1].f1[i1] = this->categoryNames.data[b_i].f1[i1];
      }
    }

    uint64m_T r1;
    uMultiWord2MultiWord((unsigned int *)&this->codes.chunks[0U], 2, (unsigned
      int *)&r.chunks[0U], 3);
    r1 = r2;
    uMultiWord2MultiWord((unsigned int *)&r2.chunks[0U], 2, (unsigned int *)
                         &r3.chunks[0U], 3);
    MultiWordAdd((unsigned int *)&r.chunks[0U], (unsigned int *)&r3.chunks[0U],
                 (unsigned int *)&r4.chunks[0U], 3);
    uMultiWord2uMultiWordSat((unsigned int *)&r4.chunks[0U], 3, (unsigned int *)
      &r5.chunks[0U], 2);
    b[0].f1.set_size(1, names.data[MultiWord2sLong((unsigned int *)&r5.chunks[0U])
                     - 1].f1.size(1));
    uMultiWord2MultiWord((unsigned int *)&this->codes.chunks[0U], 2, (unsigned
      int *)&r.chunks[0U], 3);
    r5 = r2;
    uMultiWord2MultiWord((unsigned int *)&r2.chunks[0U], 2, (unsigned int *)
                         &r3.chunks[0U], 3);
    MultiWordAdd((unsigned int *)&r.chunks[0U], (unsigned int *)&r3.chunks[0U],
                 (unsigned int *)&r4.chunks[0U], 3);
    uMultiWord2uMultiWordSat((unsigned int *)&r4.chunks[0U], 3, (unsigned int *)
      &r1.chunks[0U], 2);
    uMultiWord2MultiWord((unsigned int *)&this->codes.chunks[0U], 2, (unsigned
      int *)&r.chunks[0U], 3);
    r6 = r2;
    uMultiWord2MultiWord((unsigned int *)&r2.chunks[0U], 2, (unsigned int *)
                         &r3.chunks[0U], 3);
    MultiWordAdd((unsigned int *)&r.chunks[0U], (unsigned int *)&r3.chunks[0U],
                 (unsigned int *)&r4.chunks[0U], 3);
    uMultiWord2uMultiWordSat((unsigned int *)&r4.chunks[0U], 3, (unsigned int *)
      &r5.chunks[0U], 2);
    loop_ub = names.data[MultiWord2sLong((unsigned int *)&r1.chunks[0U]) - 1].
      f1.size(0) * names.data[MultiWord2sLong((unsigned int *)&r5.chunks[0U]) -
      1].f1.size(1);
    for (i = 0; i < loop_ub; i++) {
      uMultiWord2MultiWord((unsigned int *)&this->codes.chunks[0U], 2, (unsigned
        int *)&r.chunks[0U], 3);
      uMultiWord2MultiWord((unsigned int *)&r2.chunks[0U], 2, (unsigned int *)
                           &r3.chunks[0U], 3);
      MultiWordAdd((unsigned int *)&r.chunks[0U], (unsigned int *)&r3.chunks[0U],
                   (unsigned int *)&r4.chunks[0U], 3);
      uMultiWord2uMultiWordSat((unsigned int *)&r4.chunks[0U], 3, (unsigned int *)
        &r6.chunks[0U], 2);
      b[0].f1[i] = names.data[MultiWord2sLong((unsigned int *)&r6.chunks[0U]) -
        1].f1[i];
    }
  }

  void categorical::init(const cell_wrap_7 inputData[1], const cell_wrap_7
    varargin_1_data[], const int varargin_1_size[2])
  {
    anonymous_function b_this;
    bounded_array<cell_wrap_7, 2U, 2U> r;
    cell_wrap_7 inData[1];
    uint64m_T r1;
    int idx_data[2];
    int tmp_size[2];
    int i;
    int k;
    int n;
    int yk;
    char tmp_data[9];
    bool exitg1;
    strtrim((char *)((::coder::array<char, 2U> *)&inputData[0].f1)->data(), ((::
              coder::array<char, 2U> *)&inputData[0].f1)->size(), tmp_data,
            tmp_size);
    inData[0].f1.set_size(1, tmp_size[1]);
    n = tmp_size[0] * tmp_size[1];
    for (i = 0; i < n; i++) {
      inData[0].f1[i] = tmp_data[i];
    }

    if (varargin_1_size[1] != 0) {
      r.size[0] = varargin_1_size[0];
      r.size[1] = varargin_1_size[1];
      i = varargin_1_size[1];
      for (yk = 0; yk < i; yk++) {
        strtrim((char *)((::coder::array<char, 2U> *)&varargin_1_data[yk].f1)
                ->data(), ((::coder::array<char, 2U> *)&varargin_1_data[yk].f1
                )->size(), tmp_data, tmp_size);
        r.data[r.size[0] * yk].f1.set_size(1, tmp_size[1]);
        n = tmp_size[0] * tmp_size[1];
        for (k = 0; k < n; k++) {
          r.data[yk].f1[k] = tmp_data[k];
        }
      }

      b_this.tunableEnvironment[0].f1.size[0] = varargin_1_size[1];
      n = varargin_1_size[1];
      for (i = 0; i < n; i++) {
        b_this.tunableEnvironment[0].f1.data[i] = r.data[i];
      }
    } else {
      b_this.tunableEnvironment[0].f1.size[0] = 0;
    }

    if (b_this.tunableEnvironment[0].f1.size[0] != 0) {
      n = b_this.tunableEnvironment[0].f1.size[0];
      tmp_size[0] = 1;
      yk = 1;
      for (k = 2; k <= n; k++) {
        yk++;
        tmp_size[1] = yk;
      }

      n = b_this.tunableEnvironment[0].f1.size[0];
      if (0 <= n - 1) {
        std::memcpy(&idx_data[0], &tmp_size[0], n * sizeof(int));
      }

      internal::introsort(idx_data, b_this.tunableEnvironment[0].f1.size[0],
                          &b_this);
    }

    if (b_this.tunableEnvironment[0].f1.size[0] != 0) {
      i = b_this.tunableEnvironment[0].f1.size[0];
      this->categoryNames.size[0] = b_this.tunableEnvironment[0].f1.size[0];
      for (yk = 0; yk < i; yk++) {
        this->categoryNames.data[yk].f1.set_size(1, b_this.tunableEnvironment[0]
          .f1.data[yk].f1.size(1));
        n = b_this.tunableEnvironment[0].f1.data[yk].f1.size(0) *
          b_this.tunableEnvironment[0].f1.data[yk].f1.size(1);
        for (k = 0; k < n; k++) {
          this->categoryNames.data[yk].f1[k] = b_this.tunableEnvironment[0].
            f1.data[yk].f1[k];
        }
      }
    } else {
      this->categoryNames.size[0] = 0;
    }

    i = 0;
    n = 0;
    exitg1 = false;
    while ((!exitg1) && (n <= b_this.tunableEnvironment[0].f1.size[0] - 1)) {
      if (internal::b_strcmp((char *)inData[0].f1.data(), inData[0].f1.size(),
                             (char *)b_this.tunableEnvironment[0].f1.data[n].
                             f1.data(), b_this.tunableEnvironment[0].f1.data[n].
                             f1.size())) {
        i = n + 1;
        exitg1 = true;
      } else {
        n++;
      }
    }

    sLong2uMultiWordSat(i, (unsigned int *)&r1.chunks[0U], 2);
    this->codes = r1;
  }
}

// End of code generation (categorical.cpp)
