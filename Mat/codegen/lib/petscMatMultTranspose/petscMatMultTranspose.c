#include "petscMatMultTranspose.h"
#include "m2c.h"
#include "petsc4m.h"

static Vec b_m2c_castdata(const emxArray_uint8_T *data);
static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(int varargin_3);
static Mat m2c_castdata(const emxArray_uint8_T *data);
static void m2c_error(const emxArray_char_T *varargin_3);
static Vec b_m2c_castdata(const emxArray_uint8_T *data)
{
  return *(Vec*)(&data->data[0]);
}

static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  const char * msgid;
  const char * fmt;
  int i;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected Vec.\n";
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }

  M2C_error(msgid, fmt, &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void c_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "MatMultTranspose returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static Mat m2c_castdata(const emxArray_uint8_T *data)
{
  return *(Mat*)(&data->data[0]);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  const char * msgid;
  const char * fmt;
  int i;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected Mat.\n";
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }

  M2C_error(msgid, fmt, &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void petscMatMultTranspose(const struct0_T *A, const struct0_T *x, const
  struct0_T *y, int *errCode, boolean_T *toplevel)
{
  boolean_T p;
  int k;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_A;
  int i;
  static const char cv[3] = { 'M', 'a', 't' };

  Mat mat;
  Vec vec;
  static const char cv1[3] = { 'V', 'e', 'c' };

  Vec b_vec;
  p = (A->type->size[1] == 3);
  if (p && (A->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(A->type->data[k] == cv[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  b_p = (int)p;
  emxInit_char_T(&b_A, 2);
  if (!b_p) {
    i = b_A->size[0] * b_A->size[1];
    b_A->size[0] = 1;
    b_A->size[1] = A->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_A, i);
    k = A->type->size[1];
    for (i = 0; i < k; i++) {
      b_A->data[i] = A->type->data[i];
    }

    b_A->data[A->type->size[1]] = '\x00';
    m2c_error(b_A);
  }

  mat = m2c_castdata(A->data);
  p = (x->type->size[1] == 3);
  if (p && (x->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(x->type->data[k] == cv1[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    i = b_A->size[0] * b_A->size[1];
    b_A->size[0] = 1;
    b_A->size[1] = x->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_A, i);
    k = x->type->size[1];
    for (i = 0; i < k; i++) {
      b_A->data[i] = x->type->data[i];
    }

    b_A->data[x->type->size[1]] = '\x00';
    b_m2c_error(b_A);
  }

  vec = b_m2c_castdata(x->data);
  p = (y->type->size[1] == 3);
  if (p && (y->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(y->type->data[k] == cv1[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    i = b_A->size[0] * b_A->size[1];
    b_A->size[0] = 1;
    b_A->size[1] = y->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_A, i);
    k = y->type->size[1];
    for (i = 0; i < k; i++) {
      b_A->data[i] = y->type->data[i];
    }

    b_A->data[y->type->size[1]] = '\x00';
    b_m2c_error(b_A);
  }

  emxFree_char_T(&b_A);
  b_vec = b_m2c_castdata(y->data);
  *errCode = MatMultTranspose(mat, vec, b_vec);
  *toplevel = true;
  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }
}

void petscMatMultTranspose_initialize(void)
{
}

void petscMatMultTranspose_terminate(void)
{
}
