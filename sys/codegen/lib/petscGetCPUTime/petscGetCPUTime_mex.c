/*
 * sys/codegen/lib/petscGetCPUTime/petscGetCPUTime_mex.c
 *
 * Auxiliary code for mexFunction of petscGetCPUTime
 *
 * C source code generated by m2c.
 * %#m2c options:6ec1719cd584b7aa77f123feb18c4ab9
 *
 */

#include "mex.h"
#if !defined(MATLAB_MEX_FILE) && defined(printf)
#undef printf
#endif
/* Include the C header file generated by codegen in lib mode */
#include "petscGetCPUTime.h"
#include "petscGetCPUTime_types.h"
#include "m2c.c"

/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"


static void __petscGetCPUTime_api(mxArray **plhs, const mxArray ** prhs) {
    real64_T            *t;
    int32_T             *errCode;
    boolean_T           *toplevel;

    /* Marshall in inputs and preallocate outputs */
    t = (real64_T*)mxMalloc(sizeof(real64_T));

    errCode = (int32_T*)mxMalloc(sizeof(int32_T));

    toplevel = (boolean_T*)mxMalloc(sizeof(boolean_T));

    /* Invoke the target function */
    petscGetCPUTime(t, errCode, toplevel);

    /* Deallocate input and marshall out function outputs */
    plhs[0] = move_scalar_to_mxArray(t, mxDOUBLE_CLASS);
    plhs[1] = move_scalar_to_mxArray(errCode, mxINT32_CLASS);
    plhs[2] = move_scalar_to_mxArray(toplevel, mxLOGICAL_CLASS);

}


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[3] = {NULL, NULL, NULL};
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 0) {
        if (nlhs > 3)
            mexErrMsgIdAndTxt("petscGetCPUTime:TooManyOutputArguments",
                "Too many output arguments for entry-point petscGetCPUTime.\n");
        /* Call the API function. */
        __petscGetCPUTime_api(outputs, prhs);
    }
    else
        mexErrMsgIdAndTxt("petscGetCPUTime:WrongNumberOfInputs",
            "Incorrect number of input variables for entry-point petscGetCPUTime.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}
