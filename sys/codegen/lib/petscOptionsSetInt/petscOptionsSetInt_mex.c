/*
 * sys/codegen/lib/petscOptionsSetInt/petscOptionsSetInt_mex.c
 *
 * Auxiliary code for mexFunction of petscOptionsSetInt
 *
 * C source code generated by m2c.
 * %#m2c options: codegenArgs=-args {coder.typeof(char(0), [1,inf]), int32(0)}  enableInline=1 withPetsc=1
 *
 */

#ifdef MATLAB_MEX_FILE
#include "mex.h"
#else
#include "matrix.h"
#endif
/* Include the C file generated by codegen in lib mode */
#include "petscOptionsSetInt.h"
#include "m2c.c"
/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"

void petscOptionsSetInt_api(const mxArray ** prhs, const mxArray **plhs) {

    emxArray_char_T      iname;

    int32_T              value;
    int32_T              *errCode;
    boolean_T            *toplevel;

    /* Marshall in function inputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscOptionsSetInt:WrongInputType",
            "Input argument iname has incorrect data type. char is expected.");
    alias_mxArray_to_emxArray(prhs[0], (emxArray__common *)&iname, "iname", 2);
    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscOptionsSetInt:WrongInputType",
            "Input argument value has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(prhs[1]) != 1)
        mexErrMsgIdAndTxt("petscOptionsSetInt:WrongSizeOfInputArg",
            "Argument value should be a scalar.");
    value = *(int32_T*)mxGetData(prhs[1]);

    /* Preallocate output variables */
    {mwSize l_size[] = {1, 1};
    *(void **)&errCode = prealloc_mxArray((mxArray**)&plhs[0], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[1], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    petscOptionsSetInt_initialize();

    petscOptionsSetInt(&iname, value, errCode, toplevel);

    petscOptionsSetInt_terminate();

    /* Marshall out function outputs */
    /* Nothing to do for plhs[0] */
    /* Nothing to do for plhs[1] */

    /* Free temporary variables */
    free_emxArray((emxArray__common*)&iname);
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[2];
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 2) {
        if (nlhs > 2)
            mexErrMsgIdAndTxt("petscOptionsSetInt:TooManyOutputArguments","Too many output arguments for entry-point petscOptionsSetInt.");
        /* Call the API function. */
        petscOptionsSetInt_api(prhs, (const mxArray**)outputs);
    }
    else
        mexErrMsgIdAndTxt("petscOptionsSetInt:WrongNumberOfInputs","Incorrect number of input variables for entry-point petscOptionsSetInt.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}