/*
 * Vec/codegen/lib/petscVecSetValues/petscVecSetValues_mex.c
 *
 * Auxiliary code for mexFunction of petscVecSetValues
 *
 * C source code generated by m2c.
 * %#m2c options:40f9612f181276d8a1afc0f98dde114f
 *
 */

#include "mex.h"
#if !defined(MATLAB_MEX_FILE) && defined(printf)
#undef printf
#endif
/* Include the C header file generated by codegen in lib mode */
#include "petscVecSetValues.h"
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


static void __petscVecSetValues_api(mxArray **plhs, const mxArray ** prhs) {
    struct0_T            vec;
    int32_T              ni;
    emxArray_int32_T     ix;
    emxArray_real_T      y;
    int32_T              iroa;
    int32_T             *errCode;
    boolean_T           *toplevel;

    /* Marshall in inputs and preallocate outputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxSTRUCT_CLASS)
        mexErrMsgIdAndTxt("petscVecSetValues:WrongInputType",
            "Input argument vec has incorrect data type; struct is expected.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscVecSetValues:WrongSizeOfInputArg",
            "Argument vec should be a scalar.");
    marshallin_const_struct0_T(&vec, prhs[0], "vec");

    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscVecSetValues:WrongInputType",
            "Input argument ni has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(prhs[1]) != 1)
        mexErrMsgIdAndTxt("petscVecSetValues:WrongSizeOfInputArg",
            "Argument ni should be a scalar.");
    ni = *(int32_T*)mxGetData(prhs[1]);

    if (mxGetNumberOfElements(prhs[2]) && mxGetClassID(prhs[2]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscVecSetValues:WrongInputType",
            "Input argument ix has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(prhs[2]) && mxGetDimensions(prhs[2])[1] != 1) 
        mexErrMsgIdAndTxt("petscVecSetValues:WrongSizeOfInputArg",
            "Dimension 2 of ix should be equal to 1.");
    alias_mxArray_to_emxArray(prhs[2], (emxArray__common *)(&ix), "ix", 1);

    if (mxGetNumberOfElements(prhs[3]) && mxGetClassID(prhs[3]) != mxDOUBLE_CLASS)
        mexErrMsgIdAndTxt("petscVecSetValues:WrongInputType",
            "Input argument y has incorrect data type; double is expected.");
    if (mxGetNumberOfElements(prhs[3]) && mxGetDimensions(prhs[3])[1] != 1) 
        mexErrMsgIdAndTxt("petscVecSetValues:WrongSizeOfInputArg",
            "Dimension 2 of y should be equal to 1.");
    alias_mxArray_to_emxArray(prhs[3], (emxArray__common *)(&y), "y", 1);

    if (mxGetNumberOfElements(prhs[4]) && mxGetClassID(prhs[4]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscVecSetValues:WrongInputType",
            "Input argument iroa has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(prhs[4]) != 1)
        mexErrMsgIdAndTxt("petscVecSetValues:WrongSizeOfInputArg",
            "Argument iroa should be a scalar.");
    iroa = *(int32_T*)mxGetData(prhs[4]);

    errCode = mxMalloc(sizeof(int32_T));

    toplevel = mxMalloc(sizeof(boolean_T));

    /* Invoke the target function */
    petscVecSetValues(&vec, ni, &ix, &y, iroa, errCode, toplevel);

    /* Deallocate input and marshall out function outputs */
    destroy_struct0_T(&vec);
    /* Nothing to be done for ni */
    free_emxArray((emxArray__common*)(&ix));
    free_emxArray((emxArray__common*)(&y));
    /* Nothing to be done for iroa */
    plhs[0] = move_scalar_to_mxArray(errCode, mxINT32_CLASS);
    plhs[1] = move_scalar_to_mxArray(toplevel, mxLOGICAL_CLASS);

}

static void __petscVecSetValues_Insert_api(mxArray **plhs, const mxArray ** prhs) {
    struct0_T            vec;
    int32_T              ni;
    emxArray_int32_T     ix;
    emxArray_real_T      y;
    int32_T             *errCode;
    boolean_T           *toplevel;

    /* Marshall in inputs and preallocate outputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxSTRUCT_CLASS)
        mexErrMsgIdAndTxt("petscVecSetValues_Insert:WrongInputType",
            "Input argument vec has incorrect data type; struct is expected.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscVecSetValues_Insert:WrongSizeOfInputArg",
            "Argument vec should be a scalar.");
    marshallin_const_struct0_T(&vec, prhs[0], "vec");

    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscVecSetValues_Insert:WrongInputType",
            "Input argument ni has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(prhs[1]) != 1)
        mexErrMsgIdAndTxt("petscVecSetValues_Insert:WrongSizeOfInputArg",
            "Argument ni should be a scalar.");
    ni = *(int32_T*)mxGetData(prhs[1]);

    if (mxGetNumberOfElements(prhs[2]) && mxGetClassID(prhs[2]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscVecSetValues_Insert:WrongInputType",
            "Input argument ix has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(prhs[2]) && mxGetDimensions(prhs[2])[1] != 1) 
        mexErrMsgIdAndTxt("petscVecSetValues_Insert:WrongSizeOfInputArg",
            "Dimension 2 of ix should be equal to 1.");
    alias_mxArray_to_emxArray(prhs[2], (emxArray__common *)(&ix), "ix", 1);

    if (mxGetNumberOfElements(prhs[3]) && mxGetClassID(prhs[3]) != mxDOUBLE_CLASS)
        mexErrMsgIdAndTxt("petscVecSetValues_Insert:WrongInputType",
            "Input argument y has incorrect data type; double is expected.");
    if (mxGetNumberOfElements(prhs[3]) && mxGetDimensions(prhs[3])[1] != 1) 
        mexErrMsgIdAndTxt("petscVecSetValues_Insert:WrongSizeOfInputArg",
            "Dimension 2 of y should be equal to 1.");
    alias_mxArray_to_emxArray(prhs[3], (emxArray__common *)(&y), "y", 1);

    errCode = mxMalloc(sizeof(int32_T));

    toplevel = mxMalloc(sizeof(boolean_T));

    /* Invoke the target function */
    petscVecSetValues_Insert(&vec, ni, &ix, &y, errCode, toplevel);

    /* Deallocate input and marshall out function outputs */
    destroy_struct0_T(&vec);
    /* Nothing to be done for ni */
    free_emxArray((emxArray__common*)(&ix));
    free_emxArray((emxArray__common*)(&y));
    plhs[0] = move_scalar_to_mxArray(errCode, mxINT32_CLASS);
    plhs[1] = move_scalar_to_mxArray(toplevel, mxLOGICAL_CLASS);

}


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[2] = {NULL, NULL};
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 5) {
        if (nlhs > 2)
            mexErrMsgIdAndTxt("petscVecSetValues:TooManyOutputArguments",
                "Too many output arguments for entry-point petscVecSetValues.\n");
        /* Call the API function. */
        __petscVecSetValues_api(outputs, prhs);
    }
    else if (nrhs == 4) {
        if (nlhs > 2)
            mexErrMsgIdAndTxt("petscVecSetValues_Insert:TooManyOutputArguments",
                "Too many output arguments for entry-point petscVecSetValues_Insert.\n");
        /* Call the API function. */
        __petscVecSetValues_Insert_api(outputs, prhs);
    }
    else
        mexErrMsgIdAndTxt("petscVecSetValues:WrongNumberOfInputs",
            "Incorrect number of input variables for entry-point petscVecSetValues.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}
