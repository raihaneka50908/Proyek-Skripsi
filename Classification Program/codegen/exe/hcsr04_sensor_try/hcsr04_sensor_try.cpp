//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  hcsr04_sensor_try.cpp
//
//  Code generation for function 'hcsr04_sensor_try'
//


// Include files
#include "hcsr04_sensor_try.h"
#include "SDLVideoDisplay.h"
#include "fileManager.h"
#include "hcsr04_sensor_try_data.h"
#include "hcsr04_sensor_try_initialize.h"
#include "pause.h"
#include "raspi.h"
#include "rt_nonfinite.h"
#include "tic.h"
#include "toc.h"
#include <stdio.h>

// Function Definitions
void hcsr04_sensor_try()
{
  coder::b_raspi oR;
  double duration;
  double start_tv_nsec;
  signed char fileid;
  if (!isInitialized_hcsr04_sensor_try) {
    hcsr04_sensor_try_initialize();
  }

  oR.RaspiDisplay.matlabCodegenIsDeleted = true;
  oR.matlabCodegenIsDeleted = true;
  oR.init();
  oR.configurePin();
  oR.b_configurePin();
  oR.writeDigitalPin();
  fileid = coder::cfopen("sample.txt", "wb+");
  for (int i = 0; i < 1000; i++) {
    FILE * filestar;
    signed char b_fileid;
    bool autoflush;
    oR.writeDigitalPin();
    coder::pause(2.0);
    oR.b_writeDigitalPin();
    coder::pause(0.0001);
    oR.writeDigitalPin();
    coder::tic(&duration, &start_tv_nsec);
    while (!oR.readDigitalPin()) {
    }

    while (oR.readDigitalPin()) {
    }

    duration = coder::toc(duration, start_tv_nsec);
    b_fileid = fileid;
    if ((fileid > 22) || (fileid < 0)) {
      b_fileid = -1;
    }

    if (b_fileid >= 3) {
      filestar = eml_openfiles[b_fileid - 3];
      autoflush = eml_autoflush[b_fileid - 3];
    } else if (b_fileid == 0) {
      filestar = stdin;
      autoflush = true;
    } else if (b_fileid == 1) {
      filestar = stdout;
      autoflush = true;
    } else if (b_fileid == 2) {
      filestar = stderr;
      autoflush = true;
    } else {
      filestar = NULL;
      autoflush = true;
    }

    if (!(filestar == NULL)) {
      fprintf(filestar, "Jarak = %f \n", duration * 17150.0 / 2.0);
      if (autoflush) {
        fflush(filestar);
      }
    }
  }

  coder::cfclose(static_cast<double>(fileid));
  oR.matlabCodegenDestructor();
  oR.RaspiDisplay.matlabCodegenDestructor();
}

// End of code generation (hcsr04_sensor_try.cpp)
