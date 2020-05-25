#include "petscVecAXPY.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);
static Vec m2c_castdata(const emxArray_uint8_T *data);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "VecAXPY returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static Vec m2c_castdata(const emxArray_uint8_T *data)
{
  return *(Vec*)(&data->data[0]);
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

void petscVecAXPY(const struct0_T *y, double a, const struct0_T *x, int *errCode,
                  boolean_T *toplevel)
{
  boolean_T p;
  int k;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_y;
  int i;
  static const char cv[3] = { 'V', 'e', 'c' };

  Vec vec;
  Vec b_vec;
  p = (y->type->size[1] == 3);
  if (p && (y->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(y->type->data[k] == cv[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  b_p = (int)p;
  emxInit_char_T(&b_y, 2);
  if (!b_p) {
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = y->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_y, i);
    k = y->type->size[1];
    for (i = 0; i < k; i++) {
      b_y->data[i] = y->type->data[i];
    }

    b_y->data[y->type->size[1]] = '\x00';
    m2c_error(b_y);
  }

  vec = m2c_castdata(y->data);
  p = (x->type->size[1] == 3);
  if (p && (x->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(x->type->data[k] == cv[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = x->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_y, i);
    k = x->type->size[1];
    for (i = 0; i < k; i++) {
      b_y->data[i] = x->type->data[i];
    }

    b_y->data[x->type->size[1]] = '\x00';
    m2c_error(b_y);
  }

  emxFree_char_T(&b_y);
  b_vec = m2c_castdata(x->data);
  *errCode = VecAXPY(vec, a, b_vec);
  *toplevel = true;
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
}

void petscVecAXPY_initialize(void)
{
}

void petscVecAXPY_terminate(void)
{
}
