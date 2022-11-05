#include "petscOptionsGetBool.h"
#include "petscOptionsGetBool_types.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(void);

static void c_m2c_error(int varargin_3);

static void m2c_error(void);

static void b_m2c_error(void)
{
  const char *fmt;
  const char *msgid;
  msgid = "Petsc4m:petscOptionsGetBool:InputError";
  fmt = "Argument name must be a null-terminated character string.";
  M2C_error(msgid, fmt);
}

static void c_m2c_error(int varargin_3)
{
  const char *fmt;
  const char *msgid;
  msgid = "petsc:RuntimeError";
  fmt = "PetscOptionsGetBool returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static void m2c_error(void)
{
  const char *fmt;
  const char *msgid;
  msgid = "Petsc4m:petscOptionsGetBool:InputError";
  fmt = "Argument prefix must be a null-terminated string.";
  M2C_error(msgid, fmt);
}

void petscOptionsGetBool(const emxArray_char_T *pre,
                         const emxArray_char_T *name, int *value, int *found,
                         int *errCode, boolean_T *toplevel)
{
  PetscBool b_flag;
  PetscBool b_value;
  PetscOptions obj;
  const char *name_data;
  const char *pre_data;
  name_data = name->data;
  pre_data = pre->data;
  *toplevel = true;
  if ((pre->size[1] != 0) && (pre_data[pre->size[1] - 1] != '\x00')) {
    m2c_error();
  }
  if ((name->size[1] != 0) && (name_data[name->size[1] - 1] != '\x00')) {
    b_m2c_error();
  }
  obj = NULL;
  *errCode =
      PetscOptionsGetBool(obj, &pre_data[0], &name_data[0], &b_value, &b_flag);
  *value = (int)(b_value);
  *found = (int)(b_flag);
  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }
}

void petscOptionsGetBool_initialize(void)
{
}

void petscOptionsGetBool_terminate(void)
{
}
