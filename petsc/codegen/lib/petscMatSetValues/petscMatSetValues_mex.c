/*
 * petsc/codegen/lib/petscMatSetValues/petscMatSetValues_mex.c
 *
 * Auxiliary code for mexFunction of petscMatSetValues
 *
 * C source code generated by m2c.
 * %#m2c options: codegenArgs=-args {PetscMat, int32(0), coder.typeof(int32(0), [inf,1]), int32(0), coder.typeof(int32(0), [inf,1]), coder.typeof(0, [inf,1]), int32(0)} petscMatSetValues_Insert -args {PetscMat, int32(0), coder.typeof(int32(0), [inf,1]), int32(0), coder.typeof(int32(0), [inf,1]), coder.typeof(0, [inf,1])}  enableInline=1 withPetsc=1
 *
 */

#ifdef MATLAB_MEX_FILE
#include "mex.h"
#else
#include "matrix.h"
#endif
/* Include the C file generated by codegen in lib mode */
#include "petscMatSetValues.h"
#include "m2c.c"
/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"

void petscMatSetValues_api(const mxArray ** prhs, const mxArray **plhs) {

    emxArray_int32_T     ix;
    emxArray_int32_T     jx;
    emxArray_real_T      v;

    struct0_T            mat;
    mxArray              *_sub_mx1;

    int32_T              ni;
    int32_T              nj;
    int32_T              iroa;
    int32_T              *errCode;
    boolean_T            *toplevel;

    /* Marshall in function inputs */

    if (!mxIsStruct(prhs[0]))
        mexErrMsgIdAndTxt("petscMatSetValues:WrongInputType",
            "Input argument mat has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[0])!=3)
        mexErrMsgIdAndTxt("petscMatSetValues:InputStructWrongFields",
            "Input argument mat has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscMatSetValues:WrongSizeOfInputArg",
            "Argument mat must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[0], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatSetValues:WrongInputStruct",
            "Input argument mat does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscMatSetValues:WrongInputType",
            "Input argument mat.data has incorrect data type. uint8 is expected.");
    *(void**)&mat.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)mat.data, "mat.data", 1);
    _sub_mx1 = mxGetField(prhs[0], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatSetValues:WrongInputStruct",
            "Input argument mat does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscMatSetValues:WrongInputType",
            "Input argument mat.type has incorrect data type. char is expected.");
    *(void**)&mat.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)mat.type, "mat.type", 2);
    _sub_mx1 = mxGetField(prhs[0], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatSetValues:WrongInputStruct",
            "Input argument mat does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatSetValues:WrongInputType",
            "Input argument mat.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscMatSetValues:WrongSizeOfInputArg",
            "Argument mat.nitems should be a scalar.");
    mat.nitems = *(int32_T*)mxGetData(_sub_mx1);
    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatSetValues:WrongInputType",
            "Input argument ni has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(prhs[1]) != 1)
        mexErrMsgIdAndTxt("petscMatSetValues:WrongSizeOfInputArg",
            "Argument ni should be a scalar.");
    ni = *(int32_T*)mxGetData(prhs[1]);
    if (mxGetNumberOfElements(prhs[2]) && mxGetClassID(prhs[2]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatSetValues:WrongInputType",
            "Input argument ix has incorrect data type. int32 is expected.");
    alias_mxArray_to_emxArray(prhs[2], (emxArray__common *)&ix, "ix", 1);
    if (mxGetNumberOfElements(prhs[3]) && mxGetClassID(prhs[3]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatSetValues:WrongInputType",
            "Input argument nj has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(prhs[3]) != 1)
        mexErrMsgIdAndTxt("petscMatSetValues:WrongSizeOfInputArg",
            "Argument nj should be a scalar.");
    nj = *(int32_T*)mxGetData(prhs[3]);
    if (mxGetNumberOfElements(prhs[4]) && mxGetClassID(prhs[4]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatSetValues:WrongInputType",
            "Input argument jx has incorrect data type. int32 is expected.");
    alias_mxArray_to_emxArray(prhs[4], (emxArray__common *)&jx, "jx", 1);
    if (mxGetNumberOfElements(prhs[5]) && mxGetClassID(prhs[5]) != mxDOUBLE_CLASS)
        mexErrMsgIdAndTxt("petscMatSetValues:WrongInputType",
            "Input argument v has incorrect data type. double is expected.");
    alias_mxArray_to_emxArray(prhs[5], (emxArray__common *)&v, "v", 1);
    if (mxGetNumberOfElements(prhs[6]) && mxGetClassID(prhs[6]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatSetValues:WrongInputType",
            "Input argument iroa has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(prhs[6]) != 1)
        mexErrMsgIdAndTxt("petscMatSetValues:WrongSizeOfInputArg",
            "Argument iroa should be a scalar.");
    iroa = *(int32_T*)mxGetData(prhs[6]);

    /* Preallocate output variables */
    {mwSize l_size[] = {1, 1};
    *(void **)&errCode = prealloc_mxArray((mxArray**)&plhs[0], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[1], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    petscMatSetValues_initialize();

    petscMatSetValues(&mat, ni, &ix, nj, &jx, &v, iroa, errCode, toplevel);

    petscMatSetValues_terminate();

    /* Marshall out function outputs */
    /* Nothing to do for plhs[0] */
    /* Nothing to do for plhs[1] */

    /* Free temporary variables */
    free_emxArray((emxArray__common*)mat.type); mxFree(mat.type);
    free_emxArray((emxArray__common*)mat.data); mxFree(mat.data);

    free_emxArray((emxArray__common*)&ix);
    free_emxArray((emxArray__common*)&jx);
    free_emxArray((emxArray__common*)&v);
}
void petscMatSetValues_Insert_api(const mxArray ** prhs, const mxArray **plhs) {

    emxArray_int32_T     ix;
    emxArray_int32_T     jx;
    emxArray_real_T      v;

    struct0_T            mat;
    mxArray              *_sub_mx1;

    int32_T              ni;
    int32_T              nj;
    int32_T              errCode;

    /* Marshall in function inputs */

    if (!mxIsStruct(prhs[0]))
        mexErrMsgIdAndTxt("petscMatSetValues_Insert:WrongInputType",
            "Input argument mat has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[0])!=3)
        mexErrMsgIdAndTxt("petscMatSetValues_Insert:InputStructWrongFields",
            "Input argument mat has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscMatSetValues_Insert:WrongSizeOfInputArg",
            "Argument mat must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[0], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatSetValues_Insert:WrongInputStruct",
            "Input argument mat does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscMatSetValues_Insert:WrongInputType",
            "Input argument mat.data has incorrect data type. uint8 is expected.");
    *(void**)&mat.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)mat.data, "mat.data", 1);
    _sub_mx1 = mxGetField(prhs[0], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatSetValues_Insert:WrongInputStruct",
            "Input argument mat does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscMatSetValues_Insert:WrongInputType",
            "Input argument mat.type has incorrect data type. char is expected.");
    *(void**)&mat.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)mat.type, "mat.type", 2);
    _sub_mx1 = mxGetField(prhs[0], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatSetValues_Insert:WrongInputStruct",
            "Input argument mat does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatSetValues_Insert:WrongInputType",
            "Input argument mat.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscMatSetValues_Insert:WrongSizeOfInputArg",
            "Argument mat.nitems should be a scalar.");
    mat.nitems = *(int32_T*)mxGetData(_sub_mx1);
    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatSetValues_Insert:WrongInputType",
            "Input argument ni has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(prhs[1]) != 1)
        mexErrMsgIdAndTxt("petscMatSetValues_Insert:WrongSizeOfInputArg",
            "Argument ni should be a scalar.");
    ni = *(int32_T*)mxGetData(prhs[1]);
    if (mxGetNumberOfElements(prhs[2]) && mxGetClassID(prhs[2]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatSetValues_Insert:WrongInputType",
            "Input argument ix has incorrect data type. int32 is expected.");
    alias_mxArray_to_emxArray(prhs[2], (emxArray__common *)&ix, "ix", 1);
    if (mxGetNumberOfElements(prhs[3]) && mxGetClassID(prhs[3]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatSetValues_Insert:WrongInputType",
            "Input argument nj has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(prhs[3]) != 1)
        mexErrMsgIdAndTxt("petscMatSetValues_Insert:WrongSizeOfInputArg",
            "Argument nj should be a scalar.");
    nj = *(int32_T*)mxGetData(prhs[3]);
    if (mxGetNumberOfElements(prhs[4]) && mxGetClassID(prhs[4]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatSetValues_Insert:WrongInputType",
            "Input argument jx has incorrect data type. int32 is expected.");
    alias_mxArray_to_emxArray(prhs[4], (emxArray__common *)&jx, "jx", 1);
    if (mxGetNumberOfElements(prhs[5]) && mxGetClassID(prhs[5]) != mxDOUBLE_CLASS)
        mexErrMsgIdAndTxt("petscMatSetValues_Insert:WrongInputType",
            "Input argument v has incorrect data type. double is expected.");
    alias_mxArray_to_emxArray(prhs[5], (emxArray__common *)&v, "v", 1);

    /* Preallocate output variables */

    /* Invoke the target function */
    petscMatSetValues_initialize();

    errCode = petscMatSetValues_Insert(&mat, ni, &ix, nj, &jx, &v);

    petscMatSetValues_terminate();

    /* Marshall out function outputs */
    plhs[0] = copy_scalar_to_mxArray(&errCode, mxINT32_CLASS);

    /* Free temporary variables */
    free_emxArray((emxArray__common*)mat.type); mxFree(mat.type);
    free_emxArray((emxArray__common*)mat.data); mxFree(mat.data);

    free_emxArray((emxArray__common*)&ix);
    free_emxArray((emxArray__common*)&jx);
    free_emxArray((emxArray__common*)&v);
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[2];
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 7) {
        if (nlhs > 2)
            mexErrMsgIdAndTxt("petscMatSetValues:TooManyOutputArguments","Too many output arguments for entry-point petscMatSetValues.");
        /* Call the API function. */
        petscMatSetValues_api(prhs, (const mxArray**)outputs);
    }
    else if (nrhs == 6) {
        if (nlhs > 1)
            mexErrMsgIdAndTxt("petscMatSetValues_Insert:TooManyOutputArguments","Too many output arguments for entry-point petscMatSetValues_Insert.");
        /* Call the API function. */
        petscMatSetValues_Insert_api(prhs, (const mxArray**)outputs);
    }
    else
        mexErrMsgIdAndTxt("petscMatSetValues:WrongNumberOfInputs","Incorrect number of input variables for entry-point petscMatSetValues.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}