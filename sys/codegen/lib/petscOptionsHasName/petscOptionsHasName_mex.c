/*
 * sys/codegen/lib/petscOptionsHasName/petscOptionsHasName_mex.c
 *
 * Auxiliary code for mexFunction of petscOptionsHasName
 *
 * C source code generated by m2c.
 * %#m2c options: codegenArgs=-args {PetscOptions, coder.typeof(char(0), [1,inf]), coder.typeof(char(0), [1,inf])}  enableInline=1 withPetsc=1
 *
 */

#ifdef MATLAB_MEX_FILE
#include "mex.h"
#else
#include "matrix.h"
#endif
/* Include the C file generated by codegen in lib mode */
#include "petscOptionsHasName.h"
#include "m2c.c"
/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"

void petscOptionsHasName_api(const mxArray ** prhs, const mxArray **plhs) {

    emxArray_char_T      pre;
    emxArray_char_T      name;

    struct0_T            options;
    mxArray              *_sub_mx1;

    int32_T              *found;
    int32_T              *errCode;
    boolean_T            *toplevel;

    /* Marshall in function inputs */

    if (!mxIsStruct(prhs[0]))
        mexErrMsgIdAndTxt("petscOptionsHasName:WrongInputType",
            "Input argument options has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[0])!=3)
        mexErrMsgIdAndTxt("petscOptionsHasName:InputStructWrongFields",
            "Input argument options has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscOptionsHasName:WrongSizeOfInputArg",
            "Argument options must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[0], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscOptionsHasName:WrongInputStruct",
            "Input argument options does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscOptionsHasName:WrongInputType",
            "Input argument options.data has incorrect data type. uint8 is expected.");
    *(void**)&options.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)options.data, "options.data", 1);
    _sub_mx1 = mxGetField(prhs[0], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscOptionsHasName:WrongInputStruct",
            "Input argument options does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscOptionsHasName:WrongInputType",
            "Input argument options.type has incorrect data type. char is expected.");
    *(void**)&options.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)options.type, "options.type", 2);
    _sub_mx1 = mxGetField(prhs[0], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscOptionsHasName:WrongInputStruct",
            "Input argument options does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscOptionsHasName:WrongInputType",
            "Input argument options.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscOptionsHasName:WrongSizeOfInputArg",
            "Argument options.nitems should be a scalar.");
    options.nitems = *(int32_T*)mxGetData(_sub_mx1);
    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscOptionsHasName:WrongInputType",
            "Input argument pre has incorrect data type. char is expected.");
    alias_mxArray_to_emxArray(prhs[1], (emxArray__common *)&pre, "pre", 2);
    if (mxGetNumberOfElements(prhs[2]) && mxGetClassID(prhs[2]) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscOptionsHasName:WrongInputType",
            "Input argument name has incorrect data type. char is expected.");
    alias_mxArray_to_emxArray(prhs[2], (emxArray__common *)&name, "name", 2);

    /* Preallocate output variables */
    {mwSize l_size[] = {1, 1};
    *(void **)&found = prealloc_mxArray((mxArray**)&plhs[0], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&errCode = prealloc_mxArray((mxArray**)&plhs[1], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[2], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    petscOptionsHasName_initialize();

    petscOptionsHasName(&options, &pre, &name, found, errCode, toplevel);

    petscOptionsHasName_terminate();

    /* Marshall out function outputs */
    /* Nothing to do for plhs[0] */
    /* Nothing to do for plhs[1] */
    /* Nothing to do for plhs[2] */

    /* Free temporary variables */
    free_emxArray((emxArray__common*)options.type); mxFree(options.type);
    free_emxArray((emxArray__common*)options.data); mxFree(options.data);

    free_emxArray((emxArray__common*)&pre);
    free_emxArray((emxArray__common*)&name);
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[3];
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 3) {
        if (nlhs > 3)
            mexErrMsgIdAndTxt("petscOptionsHasName:TooManyOutputArguments","Too many output arguments for entry-point petscOptionsHasName.");
        /* Call the API function. */
        petscOptionsHasName_api(prhs, (const mxArray**)outputs);
    }
    else
        mexErrMsgIdAndTxt("petscOptionsHasName:WrongNumberOfInputs","Incorrect number of input variables for entry-point petscOptionsHasName.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}