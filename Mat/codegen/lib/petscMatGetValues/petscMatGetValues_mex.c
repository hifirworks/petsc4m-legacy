/*
 * Mat/codegen/lib/petscMatGetValues/petscMatGetValues_mex.c
 *
 * Auxiliary code for mexFunction of petscMatGetValues
 *
 * C source code generated by m2c.
 * %#m2c options:07434d231b8cce26ff5bffc8c10f1719
 *
 */

#include "mex.h"
#if !defined(MATLAB_MEX_FILE) && defined(printf)
#undef printf
#endif
/* Include the C header file generated by codegen in lib mode */
#include "petscMatGetValues.h"
#include "m2c.c"

/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"


static void marshallin_const_struct0_T(struct0_T *pStruct, const mxArray *mx, const char *mname) {
    mxArray             *sub_mx;

    if (!mxIsStruct(mx))
        M2C_error("marshallin_const_struct0_T:WrongType",
            "Input argument %s has incorrect data type; struct is expected.", mname);
    if (!mxGetField(mx, 0, "data"))
        M2C_error("marshallin_const_struct0_T:WrongType",
            "Input argument %s is missing the field data.", mname);
    if (!mxGetField(mx, 0, "type"))
        M2C_error("marshallin_const_struct0_T:WrongType",
            "Input argument %s is missing the field type.", mname);
    if (!mxGetField(mx, 0, "nitems"))
        M2C_error("marshallin_const_struct0_T:WrongType",
            "Input argument %s is missing the field nitems.", mname);
    if (mxGetNumberOfFields(mx) > 3)
        M2C_warn("marshallin_const_struct0_T:ExtraFields",
            "Extra fields in %s and are ignored.", mname);

    sub_mx = mxGetField(mx, 0, "data");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_struct0_T:WrongInputType",
            "Input argument data has incorrect data type; uint8 is expected.");
    if (mxGetNumberOfElements(sub_mx) && mxGetDimensions(sub_mx)[1] != 1) 
        mexErrMsgIdAndTxt("marshallin_const_struct0_T:WrongSizeOfInputArg",
            "Dimension 2 of data should be equal to 1.");
    pStruct->data = mxMalloc(sizeof(emxArray_uint8_T));
    init_emxArray((emxArray__common*)(pStruct->data), 1);
    alias_mxArray_to_emxArray(sub_mx, (emxArray__common *)(pStruct->data), "data", 1);

    sub_mx = mxGetField(mx, 0, "type");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_struct0_T:WrongInputType",
            "Input argument type has incorrect data type; char is expected.");
    if (mxGetNumberOfElements(sub_mx) && mxGetDimensions(sub_mx)[0] != 1) 
        mexErrMsgIdAndTxt("marshallin_const_struct0_T:WrongSizeOfInputArg",
            "Dimension 1 of type should be equal to 1.");
    pStruct->type = mxMalloc(sizeof(emxArray_char_T));
    init_emxArray((emxArray__common*)(pStruct->type), 2);
    alias_mxArray_to_emxArray(sub_mx, (emxArray__common *)(pStruct->type), "type", 2);

    sub_mx = mxGetField(mx, 0, "nitems");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_struct0_T:WrongInputType",
            "Input argument nitems has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(sub_mx) != 1)
        mexErrMsgIdAndTxt("marshallin_const_struct0_T:WrongSizeOfInputArg",
            "Argument nitems should be a scalar.");
    pStruct->nitems = *(int32_T*)mxGetData(sub_mx);
}
static void destroy_struct0_T(struct0_T *pStruct) {

    free_emxArray((emxArray__common*)(pStruct->data));
    mxFree(pStruct->data);

    free_emxArray((emxArray__common*)(pStruct->type));
    mxFree(pStruct->type);


}


static void __petscMatGetValues_api(mxArray **plhs, const mxArray ** prhs) {
    struct0_T            mat;
    int32_T              ni;
    emxArray_int32_T     ix;
    int32_T              nj;
    emxArray_int32_T     jx;
    emxArray_real_T      v;
    int32_T             *errCode;
    boolean_T           *toplevel;

    /* Marshall in inputs and preallocate outputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxSTRUCT_CLASS)
        mexErrMsgIdAndTxt("petscMatGetValues:WrongInputType",
            "Input argument mat has incorrect data type; struct is expected.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscMatGetValues:WrongSizeOfInputArg",
            "Argument mat should be a scalar.");
    marshallin_const_struct0_T(&mat, prhs[0], "mat");

    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatGetValues:WrongInputType",
            "Input argument ni has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(prhs[1]) != 1)
        mexErrMsgIdAndTxt("petscMatGetValues:WrongSizeOfInputArg",
            "Argument ni should be a scalar.");
    ni = *(int32_T*)mxGetData(prhs[1]);

    if (mxGetNumberOfElements(prhs[2]) && mxGetClassID(prhs[2]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatGetValues:WrongInputType",
            "Input argument ix has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(prhs[2]) && mxGetDimensions(prhs[2])[1] != 1) 
        mexErrMsgIdAndTxt("petscMatGetValues:WrongSizeOfInputArg",
            "Dimension 2 of ix should be equal to 1.");
    alias_mxArray_to_emxArray(prhs[2], (emxArray__common *)(&ix), "ix", 1);

    if (mxGetNumberOfElements(prhs[3]) && mxGetClassID(prhs[3]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatGetValues:WrongInputType",
            "Input argument nj has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(prhs[3]) != 1)
        mexErrMsgIdAndTxt("petscMatGetValues:WrongSizeOfInputArg",
            "Argument nj should be a scalar.");
    nj = *(int32_T*)mxGetData(prhs[3]);

    if (mxGetNumberOfElements(prhs[4]) && mxGetClassID(prhs[4]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatGetValues:WrongInputType",
            "Input argument jx has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(prhs[4]) && mxGetDimensions(prhs[4])[1] != 1) 
        mexErrMsgIdAndTxt("petscMatGetValues:WrongSizeOfInputArg",
            "Dimension 2 of jx should be equal to 1.");
    alias_mxArray_to_emxArray(prhs[4], (emxArray__common *)(&jx), "jx", 1);

    if (mxGetNumberOfElements(prhs[5]) && mxGetClassID(prhs[5]) != mxDOUBLE_CLASS)
        mexErrMsgIdAndTxt("petscMatGetValues:WrongInputType",
            "Input argument v has incorrect data type; double is expected.");
    if (mxGetNumberOfElements(prhs[5]) && mxGetDimensions(prhs[5])[1] != 1) 
        mexErrMsgIdAndTxt("petscMatGetValues:WrongSizeOfInputArg",
            "Dimension 2 of v should be equal to 1.");
    copy_mxArray_to_emxArray(prhs[5], (emxArray__common *)(&v), "v", 1);

    errCode = mxMalloc(sizeof(int32_T));

    toplevel = mxMalloc(sizeof(boolean_T));

    /* Invoke the target function */
    petscMatGetValues(&mat, ni, &ix, nj, &jx, &v, errCode, toplevel);

    /* Deallocate input and marshall out function outputs */
    destroy_struct0_T(&mat);
    /* Nothing to be done for ni */
    free_emxArray((emxArray__common*)(&ix));
    /* Nothing to be done for nj */
    free_emxArray((emxArray__common*)(&jx));
    plhs[0] = move_emxArray_to_mxArray((emxArray__common*)(&v), mxDOUBLE_CLASS);
    mxFree(v.size);
    plhs[1] = move_scalar_to_mxArray(errCode, mxINT32_CLASS);
    plhs[2] = move_scalar_to_mxArray(toplevel, mxLOGICAL_CLASS);

}

static void __petscMatGetValues_Alloc_api(mxArray **plhs, const mxArray ** prhs) {
    struct0_T            mat;
    int32_T              ni;
    emxArray_int32_T     ix;
    int32_T              nj;
    emxArray_int32_T     jx;
    emxArray_real_T      v;
    int32_T             *errCode;
    boolean_T           *toplevel;

    /* Marshall in inputs and preallocate outputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxSTRUCT_CLASS)
        mexErrMsgIdAndTxt("petscMatGetValues_Alloc:WrongInputType",
            "Input argument mat has incorrect data type; struct is expected.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscMatGetValues_Alloc:WrongSizeOfInputArg",
            "Argument mat should be a scalar.");
    marshallin_const_struct0_T(&mat, prhs[0], "mat");

    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatGetValues_Alloc:WrongInputType",
            "Input argument ni has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(prhs[1]) != 1)
        mexErrMsgIdAndTxt("petscMatGetValues_Alloc:WrongSizeOfInputArg",
            "Argument ni should be a scalar.");
    ni = *(int32_T*)mxGetData(prhs[1]);

    if (mxGetNumberOfElements(prhs[2]) && mxGetClassID(prhs[2]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatGetValues_Alloc:WrongInputType",
            "Input argument ix has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(prhs[2]) && mxGetDimensions(prhs[2])[1] != 1) 
        mexErrMsgIdAndTxt("petscMatGetValues_Alloc:WrongSizeOfInputArg",
            "Dimension 2 of ix should be equal to 1.");
    alias_mxArray_to_emxArray(prhs[2], (emxArray__common *)(&ix), "ix", 1);

    if (mxGetNumberOfElements(prhs[3]) && mxGetClassID(prhs[3]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatGetValues_Alloc:WrongInputType",
            "Input argument nj has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(prhs[3]) != 1)
        mexErrMsgIdAndTxt("petscMatGetValues_Alloc:WrongSizeOfInputArg",
            "Argument nj should be a scalar.");
    nj = *(int32_T*)mxGetData(prhs[3]);

    if (mxGetNumberOfElements(prhs[4]) && mxGetClassID(prhs[4]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatGetValues_Alloc:WrongInputType",
            "Input argument jx has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(prhs[4]) && mxGetDimensions(prhs[4])[1] != 1) 
        mexErrMsgIdAndTxt("petscMatGetValues_Alloc:WrongSizeOfInputArg",
            "Dimension 2 of jx should be equal to 1.");
    alias_mxArray_to_emxArray(prhs[4], (emxArray__common *)(&jx), "jx", 1);
    init_emxArray((emxArray__common*)(&v), 1);

    errCode = mxMalloc(sizeof(int32_T));

    toplevel = mxMalloc(sizeof(boolean_T));

    /* Invoke the target function */
    petscMatGetValues_Alloc(&mat, ni, &ix, nj, &jx, &v, errCode, toplevel);

    /* Deallocate input and marshall out function outputs */
    destroy_struct0_T(&mat);
    /* Nothing to be done for ni */
    free_emxArray((emxArray__common*)(&ix));
    /* Nothing to be done for nj */
    free_emxArray((emxArray__common*)(&jx));
    plhs[0] = move_emxArray_to_mxArray((emxArray__common*)(&v), mxDOUBLE_CLASS);
    mxFree(v.size);
    plhs[1] = move_scalar_to_mxArray(errCode, mxINT32_CLASS);
    plhs[2] = move_scalar_to_mxArray(toplevel, mxLOGICAL_CLASS);

}


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[3] = {NULL, NULL, NULL};
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 6) {
        if (nlhs > 3)
            mexErrMsgIdAndTxt("petscMatGetValues:TooManyOutputArguments",
                "Too many output arguments for entry-point petscMatGetValues.\n");
        /* Call the API function. */
        __petscMatGetValues_api(outputs, prhs);
    }
    else if (nrhs == 5) {
        if (nlhs > 3)
            mexErrMsgIdAndTxt("petscMatGetValues_Alloc:TooManyOutputArguments",
                "Too many output arguments for entry-point petscMatGetValues_Alloc.\n");
        /* Call the API function. */
        __petscMatGetValues_Alloc_api(outputs, prhs);
    }
    else
        mexErrMsgIdAndTxt("petscMatGetValues:WrongNumberOfInputs",
            "Incorrect number of input variables for entry-point petscMatGetValues.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}
