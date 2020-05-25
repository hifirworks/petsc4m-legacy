#include "petscMatDuplicate.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);
static Mat m2c_castdata(const emxArray_uint8_T *data);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "Petsc4m:petscMatDuplicate:RuntimeError";
  fmt = "MatDuplicate returned error code %d\n";
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

void petscMatDuplicate(const struct0_T *mat_in, int op, struct0_T *mat_out, int *
  errCode, boolean_T *toplevel)
{
  boolean_T p;
  int sizepe;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_mat_in;
  emxArray_uint8_T *data0;
  int i;
  static const char cv[3] = { 'M', 'a', 't' };

  Mat mat;
  Mat arg;
  char * ptr;
  p = (mat_in->type->size[1] == 3);
  if (p && (mat_in->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 3)) {
      if (!(mat_in->type->data[sizepe] == cv[sizepe])) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    emxInit_char_T(&b_mat_in, 2);
    i = b_mat_in->size[0] * b_mat_in->size[1];
    b_mat_in->size[0] = 1;
    b_mat_in->size[1] = mat_in->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_mat_in, i);
    sizepe = mat_in->type->size[1];
    for (i = 0; i < sizepe; i++) {
      b_mat_in->data[i] = mat_in->type->data[i];
    }

    b_mat_in->data[mat_in->type->size[1]] = '\x00';
    m2c_error(b_mat_in);
    emxFree_char_T(&b_mat_in);
  }

  emxInit_uint8_T(&data0, 1);
  mat = m2c_castdata(mat_in->data);
  *errCode = MatDuplicate(mat, op, &arg);
  sizepe = sizeof(Mat);
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, i);
  i = mat_out->data->size[0];
  mat_out->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(mat_out->data, i);
  for (i = 0; i < sizepe; i++) {
    mat_out->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  i = mat_out->type->size[0] * mat_out->type->size[1];
  mat_out->type->size[0] = 1;
  mat_out->type->size[1] = 3;
  emxEnsureCapacity_char_T(mat_out->type, i);
  mat_out->type->data[0] = 'M';
  mat_out->type->data[1] = 'a';
  mat_out->type->data[2] = 't';
  mat_out->nitems = 1;
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    mat_out->data->data[i] = *(ptr);
    ptr = ptr + 1;
  }

  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }

  *toplevel = true;
}

void petscMatDuplicate_initialize(void)
{
}

void petscMatDuplicate_terminate(void)
{
}
