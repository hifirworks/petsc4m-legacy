/*
 * petsc/codegen/lib/petscMatGetRow/petscMatGetRow_mex.c
 *
 * Auxiliary code for mexFunction of petscMatGetRow
 *
 * C source code generated by m2c.
 * %#m2c options: codegenArgs=-args {PetscMat, int32(0)}  enableInline=1 withPetsc=1
 *
 */

#ifdef MATLAB_MEX_FILE
#include "mex.h"
#else
#include "matrix.h"
#endif
/* Include the C file generated by codegen in lib mode */
#include "petscMatGetRow.h"
#include "m2c.c"
/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"

void petscMatGetRow_api(const mxArray ** prhs, const mxArray **plhs) {

    emxArray_int32_T     cols;
    emxArray_real_T      vals;

    struct0_T            mat;
    mxArray              *_sub_mx1;

    int32_T              row;
    int32_T              *ncols;
    int32_T              *errCode;
    boolean_T            *toplevel;

    /* Marshall in function inputs */

    if (!mxIsStruct(prhs[0]))
        mexErrMsgIdAndTxt("petscMatGetRow:WrongInputType",
            "Input argument mat has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[0])!=3)
        mexErrMsgIdAndTxt("petscMatGetRow:InputStructWrongFields",
            "Input argument mat has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscMatGetRow:WrongSizeOfInputArg",
            "Argument mat must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[0], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatGetRow:WrongInputStruct",
            "Input argument mat does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscMatGetRow:WrongInputType",
            "Input argument mat.data has incorrect data type. uint8 is expected.");
    *(void**)&mat.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)mat.data, "mat.data", 1);
    _sub_mx1 = mxGetField(prhs[0], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatGetRow:WrongInputStruct",
            "Input argument mat does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscMatGetRow:WrongInputType",
            "Input argument mat.type has incorrect data type. char is expected.");
    *(void**)&mat.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)mat.type, "mat.type", 2);
    _sub_mx1 = mxGetField(prhs[0], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatGetRow:WrongInputStruct",
            "Input argument mat does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatGetRow:WrongInputType",
            "Input argument mat.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscMatGetRow:WrongSizeOfInputArg",
            "Argument mat.nitems should be a scalar.");
    mat.nitems = *(int32_T*)mxGetData(_sub_mx1);
    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatGetRow:WrongInputType",
            "Input argument row has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(prhs[1]) != 1)
        mexErrMsgIdAndTxt("petscMatGetRow:WrongSizeOfInputArg",
            "Argument row should be a scalar.");
    row = *(int32_T*)mxGetData(prhs[1]);

    /* Preallocate output variables */
    {mwSize l_size[] = {1, 1};
    *(void **)&ncols = prealloc_mxArray((mxArray**)&plhs[0], mxINT32_CLASS, 2, l_size); }
    init_emxArray((emxArray__common*)&cols, 1);
    init_emxArray((emxArray__common*)&vals, 1);
    {mwSize l_size[] = {1, 1};
    *(void **)&errCode = prealloc_mxArray((mxArray**)&plhs[3], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[4], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    petscMatGetRow_initialize();

    petscMatGetRow(&mat, row, ncols, &cols, &vals, errCode, toplevel);

    petscMatGetRow_terminate();

    /* Marshall out function outputs */
    /* Nothing to do for plhs[0] */
    plhs[1] = move_emxArray_to_mxArray((emxArray__common*)&cols, mxINT32_CLASS);
    plhs[2] = move_emxArray_to_mxArray((emxArray__common*)&vals, mxDOUBLE_CLASS);
    /* Nothing to do for plhs[3] */
    /* Nothing to do for plhs[4] */

    /* Free temporary variables */
    free_emxArray((emxArray__common*)mat.type); mxFree(mat.type);
    free_emxArray((emxArray__common*)mat.data); mxFree(mat.data);

    free_emxArray((emxArray__common*)&cols);
    free_emxArray((emxArray__common*)&vals);
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[5];
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 2) {
        if (nlhs > 5)
            mexErrMsgIdAndTxt("petscMatGetRow:TooManyOutputArguments","Too many output arguments for entry-point petscMatGetRow.");
        /* Call the API function. */
        petscMatGetRow_api(prhs, (const mxArray**)outputs);
    }
    else
        mexErrMsgIdAndTxt("petscMatGetRow:WrongNumberOfInputs","Incorrect number of input variables for entry-point petscMatGetRow.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}