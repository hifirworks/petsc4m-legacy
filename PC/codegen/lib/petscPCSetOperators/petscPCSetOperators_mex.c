/*
 * PC/codegen/lib/petscPCSetOperators/petscPCSetOperators_mex.c
 *
 * Auxiliary code for mexFunction of petscPCSetOperators
 *
 * C source code generated by m2c.
 * %#m2c options:f4860d65943555666ca542c753ab8df9
 *
 */

#include "mex.h"
#if !defined(MATLAB_MEX_FILE) && defined(printf)
#undef printf
#endif
/* Include the C header file generated by codegen in lib mode */
#include "petscPCSetOperators.h"
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


static void __petscPCSetOperators_api(mxArray **plhs, const mxArray ** prhs) {
    struct0_T            pc;
    struct0_T            Amat;
    struct0_T            Pmat;
    int32_T             *errCode;
    boolean_T           *toplevel;

    /* Marshall in inputs and preallocate outputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxSTRUCT_CLASS)
        mexErrMsgIdAndTxt("petscPCSetOperators:WrongInputType",
            "Input argument pc has incorrect data type; struct is expected.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscPCSetOperators:WrongSizeOfInputArg",
            "Argument pc should be a scalar.");
    marshallin_const_struct0_T(&pc, prhs[0], "pc");

    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxSTRUCT_CLASS)
        mexErrMsgIdAndTxt("petscPCSetOperators:WrongInputType",
            "Input argument Amat has incorrect data type; struct is expected.");
    if (mxGetNumberOfElements(prhs[1]) != 1)
        mexErrMsgIdAndTxt("petscPCSetOperators:WrongSizeOfInputArg",
            "Argument Amat should be a scalar.");
    marshallin_const_struct0_T(&Amat, prhs[1], "Amat");

    if (mxGetNumberOfElements(prhs[2]) && mxGetClassID(prhs[2]) != mxSTRUCT_CLASS)
        mexErrMsgIdAndTxt("petscPCSetOperators:WrongInputType",
            "Input argument Pmat has incorrect data type; struct is expected.");
    if (mxGetNumberOfElements(prhs[2]) != 1)
        mexErrMsgIdAndTxt("petscPCSetOperators:WrongSizeOfInputArg",
            "Argument Pmat should be a scalar.");
    marshallin_const_struct0_T(&Pmat, prhs[2], "Pmat");

    errCode = mxMalloc(sizeof(int32_T));

    toplevel = mxMalloc(sizeof(boolean_T));

    /* Invoke the target function */
    petscPCSetOperators(&pc, &Amat, &Pmat, errCode, toplevel);

    /* Deallocate input and marshall out function outputs */
    destroy_struct0_T(&pc);
    destroy_struct0_T(&Amat);
    destroy_struct0_T(&Pmat);
    plhs[0] = move_scalar_to_mxArray(errCode, mxINT32_CLASS);
    plhs[1] = move_scalar_to_mxArray(toplevel, mxLOGICAL_CLASS);

}

static void __petscPCSetOperators_AforP_api(mxArray **plhs, const mxArray ** prhs) {
    struct0_T            ksp;
    struct0_T            Amat;
    int32_T             *errCode;
    boolean_T           *toplevel;

    /* Marshall in inputs and preallocate outputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxSTRUCT_CLASS)
        mexErrMsgIdAndTxt("petscPCSetOperators_AforP:WrongInputType",
            "Input argument ksp has incorrect data type; struct is expected.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscPCSetOperators_AforP:WrongSizeOfInputArg",
            "Argument ksp should be a scalar.");
    marshallin_const_struct0_T(&ksp, prhs[0], "ksp");

    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxSTRUCT_CLASS)
        mexErrMsgIdAndTxt("petscPCSetOperators_AforP:WrongInputType",
            "Input argument Amat has incorrect data type; struct is expected.");
    if (mxGetNumberOfElements(prhs[1]) != 1)
        mexErrMsgIdAndTxt("petscPCSetOperators_AforP:WrongSizeOfInputArg",
            "Argument Amat should be a scalar.");
    marshallin_const_struct0_T(&Amat, prhs[1], "Amat");

    errCode = mxMalloc(sizeof(int32_T));

    toplevel = mxMalloc(sizeof(boolean_T));

    /* Invoke the target function */
    petscPCSetOperators_AforP(&ksp, &Amat, errCode, toplevel);

    /* Deallocate input and marshall out function outputs */
    destroy_struct0_T(&ksp);
    destroy_struct0_T(&Amat);
    plhs[0] = move_scalar_to_mxArray(errCode, mxINT32_CLASS);
    plhs[1] = move_scalar_to_mxArray(toplevel, mxLOGICAL_CLASS);

}


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[2] = {NULL, NULL};
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 3) {
        if (nlhs > 2)
            mexErrMsgIdAndTxt("petscPCSetOperators:TooManyOutputArguments",
                "Too many output arguments for entry-point petscPCSetOperators.\n");
        /* Call the API function. */
        __petscPCSetOperators_api(outputs, prhs);
    }
    else if (nrhs == 2) {
        if (nlhs > 2)
            mexErrMsgIdAndTxt("petscPCSetOperators_AforP:TooManyOutputArguments",
                "Too many output arguments for entry-point petscPCSetOperators_AforP.\n");
        /* Call the API function. */
        __petscPCSetOperators_AforP_api(outputs, prhs);
    }
    else
        mexErrMsgIdAndTxt("petscPCSetOperators:WrongNumberOfInputs",
            "Incorrect number of input variables for entry-point petscPCSetOperators.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}
