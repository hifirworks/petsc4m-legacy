#include "petscObjectGetComm.h"
#include "petscObjectGetComm_types.h"
#include "m2c.h"
#include "mpi.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);

static void m2c_error(const emxArray_char_T *varargin_3);

static void b_m2c_error(int varargin_3)
{
  const char *fmt;
  const char *msgid;
  msgid = "petsc:RuntimeError";
  fmt = "PetscObjectGetComm returned error code %d\n";
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
  msgid = "PetscObject:WrongType";
  fmt = "Incorrect data type %s. Expected PetscObject.";
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

void petscObjectGetComm(const M2C_OpaqueType *obj, M2C_OpaqueType *comm,
                        int *errCode, boolean_T *toplevel)
{
  static const char cv[11] = {'P', 'e', 't', 's', 'c', 'O',
                              'b', 'j', 'e', 'c', 't'};
  static const char cv4[8] = {'M', 'P', 'I', '_', 'C', 'o', 'm', 'm'};
  static const char cv1[3] = {'M', 'a', 't'};
  static const char cv2[3] = {'V', 'e', 'c'};
  static const char cv3[3] = {'K', 'S', 'P'};
  static const char cv5[2] = {'P', 'C'};
  MPI_Comm arg;
  PetscObject t_obj;
  char *ptr;
  emxArray_char_T *b_obj;
  int i;
  int sizepe;
  char *obj_data;
  boolean_T exitg1;
  boolean_T p;
  p = (obj->type->size[1] == 11);
  if (p && (obj->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 11)) {
      if (obj->type->data[sizepe] != cv[sizepe]) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }
  emxInit_char_T(&b_obj, 2);
  if (!p) {
    p = (obj->type->size[1] == 3);
    if (p && (obj->type->size[1] != 0)) {
      sizepe = 0;
      exitg1 = false;
      while ((!exitg1) && (sizepe < 3)) {
        if (obj->type->data[sizepe] != cv1[sizepe]) {
          p = false;
          exitg1 = true;
        } else {
          sizepe++;
        }
      }
    }
    if (!p) {
      p = (obj->type->size[1] == 3);
      if (p && (obj->type->size[1] != 0)) {
        sizepe = 0;
        exitg1 = false;
        while ((!exitg1) && (sizepe < 3)) {
          if (obj->type->data[sizepe] != cv2[sizepe]) {
            p = false;
            exitg1 = true;
          } else {
            sizepe++;
          }
        }
      }
      if (!p) {
        p = (obj->type->size[1] == 3);
        if (p && (obj->type->size[1] != 0)) {
          sizepe = 0;
          exitg1 = false;
          while ((!exitg1) && (sizepe < 3)) {
            if (obj->type->data[sizepe] != cv3[sizepe]) {
              p = false;
              exitg1 = true;
            } else {
              sizepe++;
            }
          }
        }
        if (!p) {
          p = (obj->type->size[1] == 2);
          if (p && (obj->type->size[1] != 0)) {
            sizepe = 0;
            exitg1 = false;
            while ((!exitg1) && (sizepe < 2)) {
              if (obj->type->data[sizepe] != cv5[sizepe]) {
                p = false;
                exitg1 = true;
              } else {
                sizepe++;
              }
            }
          }
          if (!p) {
            i = b_obj->size[0] * b_obj->size[1];
            b_obj->size[0] = 1;
            b_obj->size[1] = obj->type->size[1] + 1;
            emxEnsureCapacity_char_T(b_obj, i);
            obj_data = b_obj->data;
            sizepe = obj->type->size[1];
            for (i = 0; i < sizepe; i++) {
              obj_data[i] = obj->type->data[i];
            }
            obj_data[obj->type->size[1]] = '\x00';
            m2c_error(b_obj);
          }
        }
      }
    }
  }
  emxFree_char_T(&b_obj);
  t_obj = *(PetscObject *)(&obj->data->data[0]);
  *errCode = PetscObjectGetComm(t_obj, &arg);
  sizepe = sizeof(MPI_Comm);
  i = comm->data->size[0];
  comm->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(comm->data, i);
  i = comm->type->size[0] * comm->type->size[1];
  comm->type->size[0] = 1;
  comm->type->size[1] = 8;
  emxEnsureCapacity_char_T(comm->type, i);
  for (i = 0; i < 8; i++) {
    comm->type->data[i] = cv4[i];
  }
  comm->nitems = 1;
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    comm->data->data[i] = *(ptr);
    ptr = ptr + 1;
  }
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
  *toplevel = true;
}

void petscObjectGetComm_initialize(void)
{
}

void petscObjectGetComm_terminate(void)
{
}
