//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  fileManager.cpp
//
//  Code generation for function 'fileManager'
//


// Include files
#include "fileManager.h"
#include "hcsr04_sensor_try_data.h"
#include "hcsr04_sensor_try_rtwutil.h"
#include "rt_nonfinite.h"
#include <stdio.h>

// Function Declarations
namespace coder
{
  static signed char filedata();
}

// Function Definitions
namespace coder
{
  static signed char filedata()
  {
    int k;
    signed char f;
    bool exitg1;
    f = 0;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 20)) {
      if (eml_openfiles[k] == NULL) {
        f = static_cast<signed char>(k + 1);
        exitg1 = true;
      } else {
        k++;
      }
    }

    return f;
  }

  int cfclose(double fid)
  {
    FILE * filestar;
    int st;
    signed char b_fileid;
    signed char fileid;
    st = -1;
    fileid = static_cast<signed char>(rt_roundd_snf(fid));
    if ((fileid > 22) || (fileid < 0) || (fid != fileid)) {
      fileid = -1;
    }

    b_fileid = fileid;
    if (fileid < 0) {
      b_fileid = -1;
    }

    if (b_fileid >= 3) {
      filestar = eml_openfiles[b_fileid - 3];
    } else if (b_fileid == 0) {
      filestar = stdin;
    } else if (b_fileid == 1) {
      filestar = stdout;
    } else if (b_fileid == 2) {
      filestar = stderr;
    } else {
      filestar = NULL;
    }

    if ((filestar != NULL) && (fileid >= 3)) {
      int cst;
      cst = fclose(filestar);
      if (cst == 0) {
        st = 0;
        eml_openfiles[fileid - 3] = NULL;
        eml_autoflush[fileid - 3] = true;
      }
    }

    return st;
  }

  signed char cfopen(const char *cfilename, const char *cpermission)
  {
    signed char fileid;
    signed char j;
    fileid = -1;
    j = filedata();
    if (j >= 1) {
      FILE * filestar;
      filestar = fopen(cfilename, cpermission);
      if (filestar != NULL) {
        int i;
        eml_openfiles[j - 1] = filestar;
        eml_autoflush[j - 1] = true;
        i = j + 2;
        if (j + 2 > 127) {
          i = 127;
        }

        fileid = static_cast<signed char>(i);
      }
    }

    return fileid;
  }
}

void filedata_init()
{
  FILE * a;
  a = NULL;
  for (int i = 0; i < 20; i++) {
    eml_autoflush[i] = false;
    eml_openfiles[i] = a;
  }
}

// End of code generation (fileManager.cpp)
