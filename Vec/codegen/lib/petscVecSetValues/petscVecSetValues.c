#include "petscVecSetValues.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "VecSetValues returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static void emxFreeStruct_struct0_T(struct0_T *pStruct)
{
  emxFree_uint8_T(&pStruct->data);
  emxFree_char_T(&pStruct->type);
}

static void emxInitStruct_struct0_T(struct0_T *pStruct)
{
  emxInit_uint8_T(&pStruct->data, 1);
  emxInit_char_T(&pStruct->type, 2);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  const char * msgid;
  const char * fmt;
  int i0;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected Vec.\n";
  i0 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i0, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_varargin_3->data[i0] = varargin_3->data[i0];
  }

  M2C_error(msgid, fmt, &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInitArray_int32_T(emxArray_int32_T **pEmxArray, int numDimensions)
{
  emxInit_int32_T(pEmxArray, numDimensions);
}

void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions)
{
  emxInit_real_T(pEmxArray, numDimensions);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

void petscVecSetValues(const struct0_T *vec, int ni, const emxArray_int32_T *ix,
  const emxArray_real_T *y, int iroa, int *errCode, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_vec;
  static const char cv0[3] = { 'V', 'e', 'c' };

  emxArray_uint8_T *data;
  int loop_ub;
  Vec t_vec;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      if (vec->type->size[k] != 1 + (k << 1)) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(vec->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(vec->type->data[k] == cv0[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_vec, 2);
    k = b_vec->size[0] * b_vec->size[1];
    b_vec->size[0] = 1;
    b_vec->size[1] = vec->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_vec, k, (int)sizeof(char));
    loop_ub = vec->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_vec->data[b_vec->size[0] * k] = vec->type->data[vec->type->size[0] * k];
    }

    b_vec->data[b_vec->size[0] * vec->type->size[1]] = '\x00';
    m2c_error(b_vec);
    emxFree_char_T(&b_vec);
  }

  emxInit_uint8_T(&data, 1);
  k = data->size[0];
  data->size[0] = vec->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, k, (int)sizeof(unsigned char));
  loop_ub = vec->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = vec->data->data[k];
  }

  t_vec = *(Vec*)(&data->data[0]);
  *errCode = VecSetValues(t_vec, ni, &ix->data[0], &y->data[0], iroa);
  *toplevel = true;
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
}

void petscVecSetValues_Insert(const struct0_T *vec, int ni, const
  emxArray_int32_T *ix, const emxArray_real_T *y, int *errCode, boolean_T
  *toplevel)
{
  int iroa;
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_vec;
  static const char cv1[3] = { 'V', 'e', 'c' };

  emxArray_uint8_T *data;
  int loop_ub;
  Vec t_vec;
  iroa = (INSERT_VALUES);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      if (vec->type->size[k] != 1 + (k << 1)) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(vec->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(vec->type->data[k] == cv1[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_vec, 2);
    k = b_vec->size[0] * b_vec->size[1];
    b_vec->size[0] = 1;
    b_vec->size[1] = vec->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_vec, k, (int)sizeof(char));
    loop_ub = vec->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_vec->data[b_vec->size[0] * k] = vec->type->data[vec->type->size[0] * k];
    }

    b_vec->data[b_vec->size[0] * vec->type->size[1]] = '\x00';
    m2c_error(b_vec);
    emxFree_char_T(&b_vec);
  }

  emxInit_uint8_T(&data, 1);
  k = data->size[0];
  data->size[0] = vec->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, k, (int)sizeof(unsigned char));
  loop_ub = vec->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = vec->data->data[k];
  }

  t_vec = *(Vec*)(&data->data[0]);
  *errCode = VecSetValues(t_vec, ni, &ix->data[0], &y->data[0], iroa);
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }

  *toplevel = true;
}

void petscVecSetValues_initialize(void)
{
}

void petscVecSetValues_terminate(void)
{
}
