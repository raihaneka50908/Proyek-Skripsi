/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * _coder_raspi_googlenet_trash_class_mex.c
 *
 * Code generation for function 'raspi_googlenet_trash_class'
 *
 */

/* Include files */
#include "_coder_raspi_googlenet_trash_class_mex.h"
#include "_coder_raspi_googlenet_trash_class_api.h"

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  (void)plhs;
  (void)prhs;
  mexAtExit(&raspi_googlenet_trash_class_atexit);

  /* Module initialization. */
  raspi_googlenet_trash_class_initialize();
  try {
    emlrtShouldCleanupOnError(emlrtRootTLSGlobal, false);

    /* Dispatch the entry-point. */
    raspi_googlenet_trash_class_mexFunction(nlhs, nrhs);

    /* Module termination. */
    raspi_googlenet_trash_class_terminate();
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

void raspi_googlenet_trash_class_mexFunction(int32_T nlhs, int32_T nrhs)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 0, 4,
                        27, "raspi_googlenet_trash_class");
  }

  if (nlhs > 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 27,
                        "raspi_googlenet_trash_class");
  }

  /* Call the function. */
  raspi_googlenet_trash_class_api();
}

/* End of code generation (_coder_raspi_googlenet_trash_class_mex.c) */
