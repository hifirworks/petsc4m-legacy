/*
 * sys/codegen/lib/petscOptionsInsertString/petscOptionsInsertString_mex.c
 *
 * Auxiliary code for mexFunction of petscOptionsInsertString
 *
 * C source code generated by m2c.
 * %#m2c options:b0dbc60ffeb4c257884d12bf1b7be1e6
 *
 */

#include "mex.h"
#if !defined(MATLAB_MEX_FILE) && defined(printf)
#undef printf
#endif
/* Include the C header file generated by codegen in lib mode */
#include "petscOptionsInsertString.h"
#include "petscOptionsInsertString_types.h"
#include "m2c.c"

/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"


static void __petscOptionsInsertString_api(mxArray **plhs, const mxArray ** prhs) {
    emxArray_char_T      in_str;
    int32_T             *errCode;
    boolean_T           *toplevel;

    /* Marshall in inputs and preallocate outputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscOptionsInsertString:WrongInputType",
            "Input argument in_str has incorrect data type; char is expected.");
    if (mxGetNumberOfElements(prhs[0]) && mxGetDimensions(prhs[0])[0] != 1) 
        mexErrMsgIdAndTxt("petscOptionsInsertString:WrongSizeOfInputArg",
            "Dimension 1 of in_str should be equal to 1.");
    alias_mxArray_to_emxArray(prhs[0], (emxArray__common *)(&in_str), "in_str", 2);

    errCode = (int32_T*)mxMalloc(sizeof(int32_T));

    toplevel = (boolean_T*)mxMalloc(sizeof(boolean_T));

    /* Invoke the target function */
    petscOptionsInsertString(&in_str, errCode, toplevel);

    /* Deallocate input and marshall out function outputs */
    free_emxArray((emxArray__common*)(&in_str));
    plhs[0] = move_scalar_to_mxArray(errCode, mxINT32_CLASS);
    plhs[1] = move_scalar_to_mxArray(toplevel, mxLOGICAL_CLASS);

}


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[2] = {NULL, NULL};
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 1) {
        if (nlhs > 2)
            mexErrMsgIdAndTxt("petscOptionsInsertString:TooManyOutputArguments",
                "Too many output arguments for entry-point petscOptionsInsertString.\n");
        /* Call the API function. */
        __petscOptionsInsertString_api(outputs, prhs);
    }
    else
        mexErrMsgIdAndTxt("petscOptionsInsertString:WrongNumberOfInputs",
            "Incorrect number of input variables for entry-point petscOptionsInsertString.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}
