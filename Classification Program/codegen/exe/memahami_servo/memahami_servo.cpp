//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  memahami_servo.cpp
//
//  Code generation for function 'memahami_servo'
//


// Include files
#include "memahami_servo.h"
#include "SDLVideoDisplay.h"
#include "ServoBlock.h"
#include "memahami_servo_data.h"
#include "memahami_servo_initialize.h"
#include "pause.h"
#include "raspi.h"
#include "rt_nonfinite.h"

// Function Definitions
void memahami_servo()
{
  coder::b_raspi my_pi;
  coder::raspi::internal::ServoBlock s;
  if (!isInitialized_memahami_servo) {
    memahami_servo_initialize();
  }

  my_pi.RaspiDisplay.matlabCodegenIsDeleted = true;
  my_pi.matlabCodegenIsDeleted = true;
  s.matlabCodegenIsDeleted = true;
  my_pi.init();
  coder::b_raspi::servo(&s);
  s.writePosition();
  coder::pause(1.0);

  // Initial Sensor Position = 90
  // Posisi Untuk Organik = 0
  //  Posisi Untuk Anorganik = 180
  s.writePosition();
  coder::pause(1.0);

  // sprintf("Servo Position = %f\n",readPosition(s));
  s.ServoBase2_writePosition();
  coder::pause(1.0);

  // sprintf("Servo Position = %f\n",readPosition(s));
  s.writePosition();
  coder::pause(1.0);
  s.writePosition();
  s.matlabCodegenDestructor();
  my_pi.matlabCodegenDestructor();
  my_pi.RaspiDisplay.matlabCodegenDestructor();
}

// End of code generation (memahami_servo.cpp)
