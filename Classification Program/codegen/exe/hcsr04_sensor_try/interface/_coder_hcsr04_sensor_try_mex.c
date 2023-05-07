/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * _coder_hcsr04_sensor_try_mex.c
 *
 * Code generation for function 'hcsr04_sensor_try'
 *
 */

/* Include files */
#include "_coder_hcsr04_sensor_try_mex.h"
#include "_coder_hcsr04_sensor_try_api.h"

/* Function Definitions */
void hcsr04_sensor_try_mexFunction(int32_T nlhs, int32_T nrhs)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 0, 4,
                        17, "hcsr04_sensor_try");
  }

  if (nlhs > 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 17,
                        "hcsr04_sensor_try");
  }

  /* Call the function. */
  hcsr04_sensor_try_api();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  (void)plhs;
  (void)prhs;
  mexAtExit(&hcsr04_sensor_try_atexit);

  /* Module initialization. */
  hcsr04_sensor_try_initialize();
  try {
    emlrtShouldCleanupOnError(emlrtRootTLSGlobal, false);

    /* Dispatch the entry-point. */
    hcsr04_sensor_try_mexFunction(nlhs, nrhs);

    /* Module termination. */
    hcsr04_sensor_try_terminate();
  } catch (...) {
    emlrtCleanupOnException(emlrtRootTLSGlobal);
    throw;
  }
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_hcsr04_sensor_try_mex.c) */
