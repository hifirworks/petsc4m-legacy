#include "petscMatNullSpaceCreate.h"
#include "petscMatNullSpaceCreate_types.h"
#include "m2c.h"
#include "mpi.h"
#include "petsc4m.h"

static const char cv[12] = {'M', 'a', 't', 'N', 'u', 'l',
                            'l', 'S', 'p', 'a', 'c', 'e'};

static void b_m2c_error(const emxArray_char_T *varargin_3);

static void c_m2c_error(int varargin_3);

static void m2c_error(const emxArray_char_T *varargin_3);

static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  const char *fmt;
  const char *msgid;
  emxArray_char_T *b_varargin_3;
  int i;
  int loop_ub;
  const char *varargin_3_data;
  char *b_varargin_3_data;
  varargin_3_data = varargin_3->data;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_array:TypeMismatch";
  fmt = "Incorrect data type &s. Expected %s.\n";
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  b_varargin_3_data = b_varargin_3->data;
  loop_ub = varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3_data[i] = varargin_3_data[i];
  }
  char varargin_4[4];
  varargin_4[0] = 'V';
  varargin_4[1] = 'e';
  varargin_4[2] = 'c';
  varargin_4[3] = '\x00';
  M2C_error(msgid, fmt, &b_varargin_3_data[0], &varargin_4[0]);
  emxFree_char_T(&b_varargin_3);
}

static void c_m2c_error(int varargin_3)
{
  const char *fmt;
  const char *msgid;
  msgid = "petsc:RuntimeError";
  fmt = "MatNullSpaceCreate returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  const char *fmt;
  const char *msgid;
  emxArray_char_T *b_varargin_3;
  int i;
  int loop_ub;
  const char *varargin_3_data;
  char *b_varargin_3_data;
  varargin_3_data = varargin_3->data;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected MPI_Comm.\n";
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  b_varargin_3_data = b_varargin_3->data;
  loop_ub = varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3_data[i] = varargin_3_data[i];
  }
  M2C_error(msgid, fmt, &b_varargin_3_data[0]);
  emxFree_char_T(&b_varargin_3);
}

void petscMatNullSpaceCreate(const M2C_OpaqueType *comm, int has_cnst, int n,
                             const M2C_OpaqueType *vecs, M2C_OpaqueType *nullsp,
                             int *errCode, boolean_T *toplevel)
{
  static const char b_cv[8] = {'M', 'P', 'I', '_', 'C', 'o', 'm', 'm'};
  static const char cv1[3] = {'V', 'e', 'c'};
  MPI_Comm t_comm;
  MatNullSpace arg;
  Vec *ptr;
  emxArray_char_T *b_comm;
  int i;
  int sizepe;
  const char *varargin_1_data;
  char *b_ptr;
  char *comm_data;
  boolean_T exitg1;
  boolean_T p;
  emxInit_char_T(&b_comm, 2);
  varargin_1_data = comm->type->data;
  p = (comm->type->size[1] == 8);
  if (p && (comm->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 8)) {
      if (varargin_1_data[sizepe] != b_cv[sizepe]) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }
  if (!p) {
    i = b_comm->size[0] * b_comm->size[1];
    b_comm->size[0] = 1;
    b_comm->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_comm, i);
    comm_data = b_comm->data;
    sizepe = comm->type->size[1];
    for (i = 0; i < sizepe; i++) {
      comm_data[i] = comm->type->data[i];
    }
    comm_data[comm->type->size[1]] = '\x00';
    m2c_error(b_comm);
  }
  t_comm = *(MPI_Comm *)(&comm->data->data[0]);
  p = (vecs->type->size[1] == 3);
  if (p && (vecs->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 3)) {
      if (vecs->type->data[sizepe] != cv1[sizepe]) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }
  if (!p) {
    i = b_comm->size[0] * b_comm->size[1];
    b_comm->size[0] = 1;
    b_comm->size[1] = vecs->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_comm, i);
    comm_data = b_comm->data;
    sizepe = vecs->type->size[1];
    for (i = 0; i < sizepe; i++) {
      comm_data[i] = vecs->type->data[i];
    }
    comm_data[vecs->type->size[1]] = '\x00';
    b_m2c_error(b_comm);
  }
  emxFree_char_T(&b_comm);
  ptr = (Vec *)(&vecs->data->data[0]);
  *errCode = MatNullSpaceCreate(t_comm, has_cnst, n, ptr, &arg);
  sizepe = sizeof(MatNullSpace);
  i = nullsp->data->size[0];
  nullsp->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(nullsp->data, i);
  i = nullsp->type->size[0] * nullsp->type->size[1];
  nullsp->type->size[0] = 1;
  nullsp->type->size[1] = 12;
  emxEnsureCapacity_char_T(nullsp->type, i);
  for (i = 0; i < 12; i++) {
    nullsp->type->data[i] = cv[i];
  }
  nullsp->nitems = 1;
  b_ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    nullsp->data->data[i] = *(b_ptr);
    b_ptr = b_ptr + 1;
  }
  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }
  *toplevel = true;
}

void petscMatNullSpaceCreate_2args(const M2C_OpaqueType *comm, int has_cnst,
                                   M2C_OpaqueType *nullsp, int *errCode,
                                   boolean_T *toplevel)
{
  static const char b_cv[8] = {'M', 'P', 'I', '_', 'C', 'o', 'm', 'm'};
  MPI_Comm t_comm;
  MatNullSpace arg;
  Vec *ptr;
  emxArray_char_T *b_comm;
  int i;
  int sizepe;
  const char *varargin_1_data;
  char *b_ptr;
  char *comm_data;
  boolean_T p;
  varargin_1_data = comm->type->data;
  p = (comm->type->size[1] == 8);
  if (p && (comm->type->size[1] != 0)) {
    boolean_T exitg1;
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 8)) {
      if (varargin_1_data[sizepe] != b_cv[sizepe]) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }
  if (!p) {
    emxInit_char_T(&b_comm, 2);
    i = b_comm->size[0] * b_comm->size[1];
    b_comm->size[0] = 1;
    b_comm->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_comm, i);
    comm_data = b_comm->data;
    sizepe = comm->type->size[1];
    for (i = 0; i < sizepe; i++) {
      comm_data[i] = comm->type->data[i];
    }
    comm_data[comm->type->size[1]] = '\x00';
    m2c_error(b_comm);
    emxFree_char_T(&b_comm);
  }
  t_comm = *(MPI_Comm *)(&comm->data->data[0]);
  ptr = NULL;
  *errCode = MatNullSpaceCreate(t_comm, has_cnst, 0, ptr, &arg);
  sizepe = sizeof(MatNullSpace);
  i = nullsp->data->size[0];
  nullsp->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(nullsp->data, i);
  i = nullsp->type->size[0] * nullsp->type->size[1];
  nullsp->type->size[0] = 1;
  nullsp->type->size[1] = 12;
  emxEnsureCapacity_char_T(nullsp->type, i);
  for (i = 0; i < 12; i++) {
    nullsp->type->data[i] = cv[i];
  }
  nullsp->nitems = 1;
  b_ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    nullsp->data->data[i] = *(b_ptr);
    b_ptr = b_ptr + 1;
  }
  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }
  *toplevel = true;
}

void petscMatNullSpaceCreate_initialize(void)
{
}

void petscMatNullSpaceCreate_terminate(void)
{
}
