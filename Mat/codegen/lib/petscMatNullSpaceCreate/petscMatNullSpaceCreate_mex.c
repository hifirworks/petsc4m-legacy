/*
 * Mat/codegen/lib/petscMatNullSpaceCreate/petscMatNullSpaceCreate_mex.c
 *
 * Auxiliary code for mexFunction of petscMatNullSpaceCreate
 *
 * C source code generated by m2c.
 * %#m2c options:314456e20e0d38b6ab355d86f5b0f27b
 *
 */

#include "mex.h"
#if !defined(MATLAB_MEX_FILE) && defined(printf)
#undef printf
#endif
/* Include the C header file generated by codegen in lib mode */
#include "petscMatNullSpaceCreate.h"
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
static void prealloc_struct0_T(struct0_T *pStruct) {


    pStruct->data = mxMalloc(sizeof(emxArray_uint8_T));
    init_emxArray((emxArray__common*)(pStruct->data), 1);

    pStruct->type = mxMalloc(sizeof(emxArray_char_T));
    init_emxArray((emxArray__common*)(pStruct->type), 2);

}
static mxArray *marshallout_struct0_T(struct0_T *pStruct) {
    const char           *fields[] = {"data", "type", "nitems"};
    int                  one=1;
    mxArray              *mx = create_struct_mxArray(1, &one, 3, fields);

    mxSetField(mx, 0, "data", move_emxArray_to_mxArray((emxArray__common*)(pStruct->data), mxUINT8_CLASS));
    mxFree(pStruct->data->size);
    mxFree(pStruct->data);

    mxSetField(mx, 0, "type", move_emxArray_to_mxArray((emxArray__common*)(pStruct->type), mxCHAR_CLASS));
    mxFree(pStruct->type->size);
    mxFree(pStruct->type);

    mxSetField(mx, 0, "nitems", copy_scalar_to_mxArray(&pStruct->nitems, mxINT32_CLASS));
    return mx;
}
static void destroy_struct0_T(struct0_T *pStruct) {

    free_emxArray((emxArray__common*)(pStruct->data));
    mxFree(pStruct->data);

    free_emxArray((emxArray__common*)(pStruct->type));
    mxFree(pStruct->type);


}


static void __petscMatNullSpaceCreate_api(mxArray **plhs, const mxArray ** prhs) {
    struct0_T            comm;
    int32_T              has_cnst;
    int32_T              n;
    struct0_T            vecs;
    struct0_T            nullsp;
    int32_T             *errCode;
    boolean_T           *toplevel;

    /* Marshall in inputs and preallocate outputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxSTRUCT_CLASS)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:WrongInputType",
            "Input argument comm has incorrect data type; struct is expected.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:WrongSizeOfInputArg",
            "Argument comm should be a scalar.");
    marshallin_const_struct0_T(&comm, prhs[0], "comm");

    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:WrongInputType",
            "Input argument has_cnst has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(prhs[1]) != 1)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:WrongSizeOfInputArg",
            "Argument has_cnst should be a scalar.");
    has_cnst = *(int32_T*)mxGetData(prhs[1]);

    if (mxGetNumberOfElements(prhs[2]) && mxGetClassID(prhs[2]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:WrongInputType",
            "Input argument n has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(prhs[2]) != 1)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:WrongSizeOfInputArg",
            "Argument n should be a scalar.");
    n = *(int32_T*)mxGetData(prhs[2]);

    if (mxGetNumberOfElements(prhs[3]) && mxGetClassID(prhs[3]) != mxSTRUCT_CLASS)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:WrongInputType",
            "Input argument vecs has incorrect data type; struct is expected.");
    if (mxGetNumberOfElements(prhs[3]) != 1)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:WrongSizeOfInputArg",
            "Argument vecs should be a scalar.");
    marshallin_const_struct0_T(&vecs, prhs[3], "vecs");
    prealloc_struct0_T(&nullsp);

    errCode = mxMalloc(sizeof(int32_T));

    toplevel = mxMalloc(sizeof(boolean_T));

    /* Invoke the target function */
    petscMatNullSpaceCreate(&comm, has_cnst, n, &vecs, &nullsp, errCode, toplevel);

    /* Deallocate input and marshall out function outputs */
    destroy_struct0_T(&comm);
    /* Nothing to be done for has_cnst */
    /* Nothing to be done for n */
    destroy_struct0_T(&vecs);
    plhs[0] = marshallout_struct0_T(&nullsp);
    plhs[1] = move_scalar_to_mxArray(errCode, mxINT32_CLASS);
    plhs[2] = move_scalar_to_mxArray(toplevel, mxLOGICAL_CLASS);

}

static void __petscMatNullSpaceCreate_2args_api(mxArray **plhs, const mxArray ** prhs) {
    struct0_T            comm;
    int32_T              has_cnst;
    struct0_T            nullsp;
    int32_T             *errCode;
    boolean_T           *toplevel;

    /* Marshall in inputs and preallocate outputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxSTRUCT_CLASS)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate_2args:WrongInputType",
            "Input argument comm has incorrect data type; struct is expected.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate_2args:WrongSizeOfInputArg",
            "Argument comm should be a scalar.");
    marshallin_const_struct0_T(&comm, prhs[0], "comm");

    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate_2args:WrongInputType",
            "Input argument has_cnst has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(prhs[1]) != 1)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate_2args:WrongSizeOfInputArg",
            "Argument has_cnst should be a scalar.");
    has_cnst = *(int32_T*)mxGetData(prhs[1]);
    prealloc_struct0_T(&nullsp);

    errCode = mxMalloc(sizeof(int32_T));

    toplevel = mxMalloc(sizeof(boolean_T));

    /* Invoke the target function */
    petscMatNullSpaceCreate_2args(&comm, has_cnst, &nullsp, errCode, toplevel);

    /* Deallocate input and marshall out function outputs */
    destroy_struct0_T(&comm);
    /* Nothing to be done for has_cnst */
    plhs[0] = marshallout_struct0_T(&nullsp);
    plhs[1] = move_scalar_to_mxArray(errCode, mxINT32_CLASS);
    plhs[2] = move_scalar_to_mxArray(toplevel, mxLOGICAL_CLASS);

}


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[3] = {NULL, NULL, NULL};
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 4) {
        if (nlhs > 3)
            mexErrMsgIdAndTxt("petscMatNullSpaceCreate:TooManyOutputArguments",
                "Too many output arguments for entry-point petscMatNullSpaceCreate.\n");
        /* Call the API function. */
        __petscMatNullSpaceCreate_api(outputs, prhs);
    }
    else if (nrhs == 2) {
        if (nlhs > 3)
            mexErrMsgIdAndTxt("petscMatNullSpaceCreate_2args:TooManyOutputArguments",
                "Too many output arguments for entry-point petscMatNullSpaceCreate_2args.\n");
        /* Call the API function. */
        __petscMatNullSpaceCreate_2args_api(outputs, prhs);
    }
    else
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:WrongNumberOfInputs",
            "Incorrect number of input variables for entry-point petscMatNullSpaceCreate.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}
