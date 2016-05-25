#include "mptKSPSetup.h"
#include "mpetsc.h"
#include "m2c.h"

static void b_m2c_error(int varargin_3);
static void c_m2c_error(int varargin_3);
static void d_m2c_error(int varargin_3);
static void e_m2c_error(const emxArray_char_T *varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void f_m2c_error(int varargin_3);
static void g_m2c_error(int varargin_3);
static void h_m2c_error(int varargin_3);
static void i_m2c_error(int varargin_3);
static boolean_T isequal(const emxArray_char_T *varargin_1);
static void j_m2c_error(int varargin_3);
static void k_m2c_error(int varargin_3);
static void l_m2c_error(int varargin_3);
static void m2c_error(const emxArray_char_T *varargin_3);
static void m_m2c_error(int varargin_3);
static MPI_Comm petscObjectGetComm(const emxArray_uint8_T *obj_data, const
  emxArray_char_T *obj_type);
static void b_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "PetscObjectGetComm returned error code %d\n",
            varargin_3);
}

static void c_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPCreate returned error code %d\n",
            varargin_3);
}

static void d_m2c_error(int varargin_3)
{
  M2C_error("MPI:RuntimeError", "MPI_Barrier returned error code %d\n",
            varargin_3);
}

static void e_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i4;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i4 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i4, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i4 = 0; i4 < loop_ub; i4++) {
    b_varargin_3->data[i4] = varargin_3->data[i4];
  }

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected Mat.\n", &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
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

static void f_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPSetOperators returned error code %d\n",
            varargin_3);
}

static void g_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPGetPC returned error code %d\n",
            varargin_3);
}

static void h_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "PCSetType returned error code %d\n",
            varargin_3);
}

static void i_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPSetPCSide returned error code %d\n",
            varargin_3);
}

static boolean_T isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i2;
  boolean_T exitg1;
  static const char cv8[3] = { 'M', 'a', 't' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i2 = varargin_1->size[k];
      if (i2 != (k << 1) + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(varargin_1->data[k] == cv8[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  return p;
}

static void j_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "petscPCFactorSetMatSolverPackage returned error code %d\n",
            varargin_3);
}

static void k_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPSetType returned error code %d\n",
            varargin_3);
}

static void l_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPSetFromOptions returned error code %d\n",
            varargin_3);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i3;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i3 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i3, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i3 = 0; i3 < loop_ub; i3++) {
    b_varargin_3->data[i3] = varargin_3->data[i3];
  }

  M2C_error("PetscObject:WrongType",
            "Incorrect data type %s. Expected PetscObject.", &b_varargin_3->
            data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void m_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPSetUp returned error code %d\n",
            varargin_3);
}

static MPI_Comm petscObjectGetComm(const emxArray_uint8_T *obj_data, const
  emxArray_char_T *obj_type)
{
  MPI_Comm comm;
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg8;
  int i1;
  boolean_T exitg7;
  emxArray_char_T *b_obj_type;
  static const char cv4[11] = { 'P', 'e', 't', 's', 'c', 'O', 'b', 'j', 'e', 'c',
    't' };

  emxArray_uint8_T *data;
  int exitg6;
  PetscObject t_obj;
  MPI_Comm t_comm;
  int errCode;
  boolean_T exitg5;
  static const char cv5[3] = { 'V', 'e', 'c' };

  int exitg4;
  boolean_T exitg3;
  static const char cv6[3] = { 'K', 'S', 'P' };

  int exitg2;
  boolean_T exitg1;
  static const char cv7[2] = { 'P', 'C' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg8 = 0;
    if (k < 2) {
      i1 = obj_type->size[k];
      if (i1 != 10 * k + 1) {
        exitg8 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg8 = 1;
    }
  } while (exitg8 == 0);

  if (b_p && (!(obj_type->size[1] == 0))) {
    k = 0;
    exitg7 = false;
    while ((!exitg7) && (k < 11)) {
      if (!(obj_type->data[k] == cv4[k])) {
        b_p = false;
        exitg7 = true;
      } else {
        k++;
      }
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  emxInit_char_T(&b_obj_type, 2);
  if ((!p) && (!isequal(obj_type))) {
    p = false;
    b_p = false;
    k = 0;
    do {
      exitg6 = 0;
      if (k < 2) {
        i1 = obj_type->size[k];
        if (i1 != (k << 1) + 1) {
          exitg6 = 1;
        } else {
          k++;
        }
      } else {
        b_p = true;
        exitg6 = 1;
      }
    } while (exitg6 == 0);

    if (b_p && (!(obj_type->size[1] == 0))) {
      k = 0;
      exitg5 = false;
      while ((!exitg5) && (k < 3)) {
        if (!(obj_type->data[k] == cv5[k])) {
          b_p = false;
          exitg5 = true;
        } else {
          k++;
        }
      }
    }

    if (!b_p) {
    } else {
      p = true;
    }

    if (!p) {
      p = false;
      b_p = false;
      k = 0;
      do {
        exitg4 = 0;
        if (k < 2) {
          i1 = obj_type->size[k];
          if (i1 != (k << 1) + 1) {
            exitg4 = 1;
          } else {
            k++;
          }
        } else {
          b_p = true;
          exitg4 = 1;
        }
      } while (exitg4 == 0);

      if (b_p && (!(obj_type->size[1] == 0))) {
        k = 0;
        exitg3 = false;
        while ((!exitg3) && (k < 3)) {
          if (!(obj_type->data[k] == cv6[k])) {
            b_p = false;
            exitg3 = true;
          } else {
            k++;
          }
        }
      }

      if (!b_p) {
      } else {
        p = true;
      }

      if (!p) {
        p = false;
        b_p = false;
        k = 0;
        do {
          exitg2 = 0;
          if (k < 2) {
            i1 = obj_type->size[k];
            if (i1 != k + 1) {
              exitg2 = 1;
            } else {
              k++;
            }
          } else {
            b_p = true;
            exitg2 = 1;
          }
        } while (exitg2 == 0);

        if (b_p && (!(obj_type->size[1] == 0))) {
          k = 0;
          exitg1 = false;
          while ((!exitg1) && (k < 2)) {
            if (!(obj_type->data[k] == cv7[k])) {
              b_p = false;
              exitg1 = true;
            } else {
              k++;
            }
          }
        }

        if (!b_p) {
        } else {
          p = true;
        }

        if (!p) {
          i1 = b_obj_type->size[0] * b_obj_type->size[1];
          b_obj_type->size[0] = 1;
          b_obj_type->size[1] = obj_type->size[1] + 1;
          emxEnsureCapacity((emxArray__common *)b_obj_type, i1, (int)sizeof(char));
          k = obj_type->size[1];
          for (i1 = 0; i1 < k; i1++) {
            b_obj_type->data[b_obj_type->size[0] * i1] = obj_type->data
              [obj_type->size[0] * i1];
          }

          b_obj_type->data[b_obj_type->size[0] * obj_type->size[1]] = '\x00';
          m2c_error(b_obj_type);
        }
      }
    }
  }

  emxFree_char_T(&b_obj_type);
  emxInit_uint8_T(&data, 1);
  i1 = data->size[0];
  data->size[0] = obj_data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i1, (int)sizeof(unsigned char));
  k = obj_data->size[0];
  for (i1 = 0; i1 < k; i1++) {
    data->data[i1] = obj_data->data[i1];
  }

  t_obj = *(PetscObject*)(&data->data[0]);
  errCode = PetscObjectGetComm(t_obj, &t_comm);
  comm = t_comm;
  emxFree_uint8_T(&data);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      b_m2c_error(errCode);
    }
  }

  return comm;
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInitArray_char_T(emxArray_char_T **pEmxArray, int numDimensions)
{
  emxInit_char_T(pEmxArray, numDimensions);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

void mptKSPSetup(const struct0_T *Amat, const emxArray_char_T *ksptype, const
                 emxArray_char_T *pctype, const emxArray_char_T *pcopt,
                 struct0_T *ksp, double *time, boolean_T *toplevel)
{
  MPI_Comm varargin_1;
  KSP t_ksp;
  int errCode;
  int k;
  PetscObject t_obj;
  MPI_Comm t_comm;
  int info;
  double t;
  emxArray_char_T *b_Amat;
  emxArray_uint8_T *data0;
  int i0;
  Mat c_Amat;
  boolean_T p;
  boolean_T b_p;
  emxArray_char_T *pctype0;
  PC t_pc;
  int exitg6;
  boolean_T exitg5;
  static const char cv0[4] = { 'l', 'e', 'f', 't' };

  double secs;
  int exitg4;
  int sizepe;
  char t3_type[3];
  boolean_T exitg3;
  static const char cv1[3] = { 'K', 'S', 'P' };

  static const char cv2[5] = { 'r', 'i', 'g', 'h', 't' };

  int exitg2;
  char * ptr;
  boolean_T exitg1;
  int i;
  static const char cv3[9] = { 's', 'y', 'm', 'm', 'e', 't', 'r', 'i', 'c' };

  varargin_1 = petscObjectGetComm(Amat->data, Amat->type);
  errCode = KSPCreate(varargin_1, &t_ksp);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      c_m2c_error(errCode);
    }
  }

  t_obj = (PetscObject)(t_ksp);
  errCode = PetscObjectGetComm(t_obj, &t_comm);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      b_m2c_error(errCode);
    }
  }

  info = MPI_Barrier(t_comm);
  if (info != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      d_m2c_error(info);
    }
  }

  t = MPI_Wtime();
  if (!isequal(Amat->type)) {
    emxInit_char_T(&b_Amat, 2);
    i0 = b_Amat->size[0] * b_Amat->size[1];
    b_Amat->size[0] = 1;
    b_Amat->size[1] = Amat->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_Amat, i0, (int)sizeof(char));
    k = Amat->type->size[1];
    for (i0 = 0; i0 < k; i0++) {
      b_Amat->data[b_Amat->size[0] * i0] = Amat->type->data[Amat->type->size[0] *
        i0];
    }

    b_Amat->data[b_Amat->size[0] * Amat->type->size[1]] = '\x00';
    e_m2c_error(b_Amat);
    emxFree_char_T(&b_Amat);
  }

  emxInit_uint8_T(&data0, 1);
  i0 = data0->size[0];
  data0->size[0] = Amat->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  k = Amat->data->size[0];
  for (i0 = 0; i0 < k; i0++) {
    data0->data[i0] = Amat->data->data[i0];
  }

  c_Amat = *(Mat*)(&data0->data[0]);
  errCode = KSPSetOperators(t_ksp, c_Amat, c_Amat);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      f_m2c_error(errCode);
    }
  }

  p = !(pctype->size[1] == 0);
  b_p = !(pcopt->size[1] == 0);
  emxInit_char_T(&pctype0, 2);
  if (p || b_p) {
    errCode = KSPGetPC(t_ksp, &t_pc);
    if (errCode != 0) {
      k = (M2C_DEBUG);
      if (k != 0) {
        g_m2c_error(errCode);
      }
    }

    if (p) {
      if (pctype->data[pctype->size[1] - 1] != '\x00') {
        i0 = pctype0->size[0] * pctype0->size[1];
        pctype0->size[0] = 1;
        pctype0->size[1] = pctype->size[1] + 1;
        emxEnsureCapacity((emxArray__common *)pctype0, i0, (int)sizeof(char));
        k = pctype->size[1];
        for (i0 = 0; i0 < k; i0++) {
          pctype0->data[pctype0->size[0] * i0] = pctype->data[pctype->size[0] *
            i0];
        }

        pctype0->data[pctype0->size[0] * pctype->size[1]] = '\x00';
      } else {
        i0 = pctype0->size[0] * pctype0->size[1];
        pctype0->size[0] = 1;
        pctype0->size[1] = pctype->size[1];
        emxEnsureCapacity((emxArray__common *)pctype0, i0, (int)sizeof(char));
        k = pctype->size[0] * pctype->size[1];
        for (i0 = 0; i0 < k; i0++) {
          pctype0->data[i0] = pctype->data[i0];
        }
      }

      errCode = PCSetType(t_pc, &pctype0->data[0]);
      if (errCode != 0) {
        k = (M2C_DEBUG);
        if (k != 0) {
          h_m2c_error(errCode);
        }
      }
    }

    if (b_p) {
      p = false;
      b_p = false;
      k = 0;
      do {
        exitg6 = 0;
        if (k < 2) {
          i0 = pcopt->size[k];
          if (i0 != 3 * k + 1) {
            exitg6 = 1;
          } else {
            k++;
          }
        } else {
          b_p = true;
          exitg6 = 1;
        }
      } while (exitg6 == 0);

      if (b_p && (!(pcopt->size[1] == 0))) {
        k = 0;
        exitg5 = false;
        while ((!exitg5) && (k < 4)) {
          if (!(pcopt->data[k] == cv0[k])) {
            b_p = false;
            exitg5 = true;
          } else {
            k++;
          }
        }
      }

      if (!b_p) {
      } else {
        p = true;
      }

      if (p) {
        k = (PC_LEFT);
        errCode = KSPSetPCSide(t_ksp, k);
        if (errCode != 0) {
          k = (M2C_DEBUG);
          if (k != 0) {
            i_m2c_error(errCode);
          }
        }
      } else {
        p = false;
        b_p = false;
        k = 0;
        do {
          exitg4 = 0;
          if (k < 2) {
            i0 = pcopt->size[k];
            if (i0 != (k << 2) + 1) {
              exitg4 = 1;
            } else {
              k++;
            }
          } else {
            b_p = true;
            exitg4 = 1;
          }
        } while (exitg4 == 0);

        if (b_p && (!(pcopt->size[1] == 0))) {
          k = 0;
          exitg3 = false;
          while ((!exitg3) && (k < 5)) {
            if (!(pcopt->data[k] == cv2[k])) {
              b_p = false;
              exitg3 = true;
            } else {
              k++;
            }
          }
        }

        if (!b_p) {
        } else {
          p = true;
        }

        if (p) {
          k = (PC_RIGHT);
          errCode = KSPSetPCSide(t_ksp, k);
          if (errCode != 0) {
            k = (M2C_DEBUG);
            if (k != 0) {
              i_m2c_error(errCode);
            }
          }
        } else {
          p = false;
          b_p = false;
          k = 0;
          do {
            exitg2 = 0;
            if (k < 2) {
              i0 = pcopt->size[k];
              if (i0 != (k << 3) + 1) {
                exitg2 = 1;
              } else {
                k++;
              }
            } else {
              b_p = true;
              exitg2 = 1;
            }
          } while (exitg2 == 0);

          if (b_p && (!(pcopt->size[1] == 0))) {
            k = 0;
            exitg1 = false;
            while ((!exitg1) && (k < 9)) {
              if (!(pcopt->data[k] == cv3[k])) {
                b_p = false;
                exitg1 = true;
              } else {
                k++;
              }
            }
          }

          if (!b_p) {
          } else {
            p = true;
          }

          if (p) {
            k = (PC_SYMMETRIC);
            errCode = KSPSetPCSide(t_ksp, k);
            if (errCode != 0) {
              k = (M2C_DEBUG);
              if (k != 0) {
                i_m2c_error(errCode);
              }
            }
          } else {
            if (pcopt->data[pcopt->size[1] - 1] != '\x00') {
              i0 = pctype0->size[0] * pctype0->size[1];
              pctype0->size[0] = 1;
              pctype0->size[1] = pcopt->size[1] + 1;
              emxEnsureCapacity((emxArray__common *)pctype0, i0, (int)sizeof
                                (char));
              k = pcopt->size[1];
              for (i0 = 0; i0 < k; i0++) {
                pctype0->data[pctype0->size[0] * i0] = pcopt->data[pcopt->size[0]
                  * i0];
              }

              pctype0->data[pctype0->size[0] * pcopt->size[1]] = '\x00';
            } else {
              i0 = pctype0->size[0] * pctype0->size[1];
              pctype0->size[0] = 1;
              pctype0->size[1] = pcopt->size[1];
              emxEnsureCapacity((emxArray__common *)pctype0, i0, (int)sizeof
                                (char));
              k = pcopt->size[0] * pcopt->size[1];
              for (i0 = 0; i0 < k; i0++) {
                pctype0->data[i0] = pcopt->data[i0];
              }
            }

            errCode = PCFactorSetMatSolverPackage(t_pc, &pctype0->data[0]);
            if (errCode != 0) {
              k = (M2C_DEBUG);
              if (k != 0) {
                j_m2c_error(errCode);
              }
            }
          }
        }
      }
    }
  }

  if ((!(ksptype->size[1] == 0)) && ((unsigned char)ksptype->data[ksptype->size
       [1] - 1] != 0)) {
    i0 = pctype0->size[0] * pctype0->size[1];
    pctype0->size[0] = 1;
    pctype0->size[1] = ksptype->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)pctype0, i0, (int)sizeof(char));
    k = ksptype->size[1];
    for (i0 = 0; i0 < k; i0++) {
      pctype0->data[pctype0->size[0] * i0] = ksptype->data[ksptype->size[0] * i0];
    }

    pctype0->data[pctype0->size[0] * ksptype->size[1]] = '\x00';
  } else {
    i0 = pctype0->size[0] * pctype0->size[1];
    pctype0->size[0] = 1;
    pctype0->size[1] = ksptype->size[1];
    emxEnsureCapacity((emxArray__common *)pctype0, i0, (int)sizeof(char));
    k = ksptype->size[0] * ksptype->size[1];
    for (i0 = 0; i0 < k; i0++) {
      pctype0->data[i0] = ksptype->data[i0];
    }
  }

  if (!(pctype0->size[1] == 0)) {
    errCode = KSPSetType(t_ksp, &pctype0->data[0]);
    if (errCode != 0) {
      k = (M2C_DEBUG);
      if (k != 0) {
        k_m2c_error(errCode);
      }
    }
  }

  emxFree_char_T(&pctype0);
  if (pcopt->size[1] == 0) {
    k = (PC_RIGHT);
    errCode = KSPSetPCSide(t_ksp, k);
    if (errCode != 0) {
      k = (M2C_DEBUG);
      if (k != 0) {
        i_m2c_error(errCode);
      }
    }
  }

  errCode = KSPSetFromOptions(t_ksp);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      l_m2c_error(errCode);
    }
  }

  errCode = KSPSetUp(t_ksp);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      m_m2c_error(errCode);
    }
  }

  info = MPI_Barrier(t_comm);
  if (info != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      d_m2c_error(info);
    }
  }

  secs = MPI_Wtime();
  *time = secs - t;
  *toplevel = true;
  sizepe = sizeof(KSP);
  i0 = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  for (i0 = 0; i0 < 3; i0++) {
    t3_type[i0] = cv1[i0];
  }

  i0 = ksp->data->size[0];
  ksp->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)ksp->data, i0, (int)sizeof(unsigned char));
  k = data0->size[0];
  for (i0 = 0; i0 < k; i0++) {
    ksp->data->data[i0] = data0->data[i0];
  }

  emxFree_uint8_T(&data0);
  i0 = ksp->type->size[0] * ksp->type->size[1];
  ksp->type->size[0] = 1;
  ksp->type->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)ksp->type, i0, (int)sizeof(char));
  for (i0 = 0; i0 < 3; i0++) {
    ksp->type->data[i0] = t3_type[i0];
  }

  ksp->nitems = 1;
  ptr = (char *)(&t_ksp);
  for (i = 1; i <= sizepe; i++) {
    ksp->data->data[i - 1] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }
}

void mptKSPSetup_1arg(const struct0_T *Amat, struct0_T *ksp, double *time,
                      boolean_T *toplevel)
{
  MPI_Comm varargin_1;
  KSP t_ksp;
  int errCode;
  int flag;
  PetscObject t_obj;
  MPI_Comm t_comm;
  int info;
  double t;
  emxArray_char_T *b_Amat;
  emxArray_uint8_T *data0;
  int loop_ub;
  Mat c_Amat;
  double secs;
  int sizepe;
  char t2_type[3];
  static const char cv9[3] = { 'K', 'S', 'P' };

  char * ptr;
  int i;
  varargin_1 = petscObjectGetComm(Amat->data, Amat->type);
  errCode = KSPCreate(varargin_1, &t_ksp);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      c_m2c_error(errCode);
    }
  }

  t_obj = (PetscObject)(t_ksp);
  errCode = PetscObjectGetComm(t_obj, &t_comm);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      b_m2c_error(errCode);
    }
  }

  info = MPI_Barrier(t_comm);
  if (info != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      d_m2c_error(info);
    }
  }

  t = MPI_Wtime();
  if (!isequal(Amat->type)) {
    emxInit_char_T(&b_Amat, 2);
    flag = b_Amat->size[0] * b_Amat->size[1];
    b_Amat->size[0] = 1;
    b_Amat->size[1] = Amat->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_Amat, flag, (int)sizeof(char));
    loop_ub = Amat->type->size[1];
    for (flag = 0; flag < loop_ub; flag++) {
      b_Amat->data[b_Amat->size[0] * flag] = Amat->type->data[Amat->type->size[0]
        * flag];
    }

    b_Amat->data[b_Amat->size[0] * Amat->type->size[1]] = '\x00';
    e_m2c_error(b_Amat);
    emxFree_char_T(&b_Amat);
  }

  emxInit_uint8_T(&data0, 1);
  flag = data0->size[0];
  data0->size[0] = Amat->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, flag, (int)sizeof(unsigned char));
  loop_ub = Amat->data->size[0];
  for (flag = 0; flag < loop_ub; flag++) {
    data0->data[flag] = Amat->data->data[flag];
  }

  c_Amat = *(Mat*)(&data0->data[0]);
  errCode = KSPSetOperators(t_ksp, c_Amat, c_Amat);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      f_m2c_error(errCode);
    }
  }

  flag = (PC_RIGHT);
  errCode = KSPSetPCSide(t_ksp, flag);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      i_m2c_error(errCode);
    }
  }

  errCode = KSPSetFromOptions(t_ksp);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      l_m2c_error(errCode);
    }
  }

  errCode = KSPSetUp(t_ksp);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      m_m2c_error(errCode);
    }
  }

  info = MPI_Barrier(t_comm);
  if (info != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      d_m2c_error(info);
    }
  }

  secs = MPI_Wtime();
  sizepe = sizeof(KSP);
  flag = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, flag, (int)sizeof(unsigned char));
  for (flag = 0; flag < 3; flag++) {
    t2_type[flag] = cv9[flag];
  }

  flag = ksp->data->size[0];
  ksp->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)ksp->data, flag, (int)sizeof(unsigned
    char));
  loop_ub = data0->size[0];
  for (flag = 0; flag < loop_ub; flag++) {
    ksp->data->data[flag] = data0->data[flag];
  }

  emxFree_uint8_T(&data0);
  flag = ksp->type->size[0] * ksp->type->size[1];
  ksp->type->size[0] = 1;
  ksp->type->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)ksp->type, flag, (int)sizeof(char));
  for (flag = 0; flag < 3; flag++) {
    ksp->type->data[flag] = t2_type[flag];
  }

  ksp->nitems = 1;
  ptr = (char *)(&t_ksp);
  for (i = 1; i <= sizepe; i++) {
    ksp->data->data[i - 1] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }

  *time = secs - t;
  *toplevel = true;
}

void mptKSPSetup_2args(const struct0_T *Amat, const emxArray_char_T *ksptype,
  struct0_T *ksp, double *time, boolean_T *toplevel)
{
  MPI_Comm varargin_1;
  KSP t_ksp;
  int errCode;
  int flag;
  PetscObject t_obj;
  MPI_Comm t_comm;
  int info;
  double t;
  emxArray_char_T *b_Amat;
  emxArray_uint8_T *data0;
  int loop_ub;
  Mat c_Amat;
  emxArray_char_T *ksptype0;
  double secs;
  int sizepe;
  char t1_type[3];
  static const char cv10[3] = { 'K', 'S', 'P' };

  char * ptr;
  int i;
  varargin_1 = petscObjectGetComm(Amat->data, Amat->type);
  errCode = KSPCreate(varargin_1, &t_ksp);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      c_m2c_error(errCode);
    }
  }

  t_obj = (PetscObject)(t_ksp);
  errCode = PetscObjectGetComm(t_obj, &t_comm);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      b_m2c_error(errCode);
    }
  }

  info = MPI_Barrier(t_comm);
  if (info != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      d_m2c_error(info);
    }
  }

  t = MPI_Wtime();
  if (!isequal(Amat->type)) {
    emxInit_char_T(&b_Amat, 2);
    flag = b_Amat->size[0] * b_Amat->size[1];
    b_Amat->size[0] = 1;
    b_Amat->size[1] = Amat->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_Amat, flag, (int)sizeof(char));
    loop_ub = Amat->type->size[1];
    for (flag = 0; flag < loop_ub; flag++) {
      b_Amat->data[b_Amat->size[0] * flag] = Amat->type->data[Amat->type->size[0]
        * flag];
    }

    b_Amat->data[b_Amat->size[0] * Amat->type->size[1]] = '\x00';
    e_m2c_error(b_Amat);
    emxFree_char_T(&b_Amat);
  }

  emxInit_uint8_T(&data0, 1);
  flag = data0->size[0];
  data0->size[0] = Amat->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, flag, (int)sizeof(unsigned char));
  loop_ub = Amat->data->size[0];
  for (flag = 0; flag < loop_ub; flag++) {
    data0->data[flag] = Amat->data->data[flag];
  }

  c_Amat = *(Mat*)(&data0->data[0]);
  errCode = KSPSetOperators(t_ksp, c_Amat, c_Amat);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      f_m2c_error(errCode);
    }
  }

  emxInit_char_T(&ksptype0, 2);
  if ((!(ksptype->size[1] == 0)) && ((unsigned char)ksptype->data[ksptype->size
       [1] - 1] != 0)) {
    flag = ksptype0->size[0] * ksptype0->size[1];
    ksptype0->size[0] = 1;
    ksptype0->size[1] = ksptype->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)ksptype0, flag, (int)sizeof(char));
    loop_ub = ksptype->size[1];
    for (flag = 0; flag < loop_ub; flag++) {
      ksptype0->data[ksptype0->size[0] * flag] = ksptype->data[ksptype->size[0] *
        flag];
    }

    ksptype0->data[ksptype0->size[0] * ksptype->size[1]] = '\x00';
  } else {
    flag = ksptype0->size[0] * ksptype0->size[1];
    ksptype0->size[0] = 1;
    ksptype0->size[1] = ksptype->size[1];
    emxEnsureCapacity((emxArray__common *)ksptype0, flag, (int)sizeof(char));
    loop_ub = ksptype->size[0] * ksptype->size[1];
    for (flag = 0; flag < loop_ub; flag++) {
      ksptype0->data[flag] = ksptype->data[flag];
    }
  }

  if (!(ksptype0->size[1] == 0)) {
    errCode = KSPSetType(t_ksp, &ksptype0->data[0]);
    if (errCode != 0) {
      flag = (M2C_DEBUG);
      if (flag != 0) {
        k_m2c_error(errCode);
      }
    }
  }

  emxFree_char_T(&ksptype0);
  flag = (PC_RIGHT);
  errCode = KSPSetPCSide(t_ksp, flag);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      i_m2c_error(errCode);
    }
  }

  errCode = KSPSetFromOptions(t_ksp);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      l_m2c_error(errCode);
    }
  }

  errCode = KSPSetUp(t_ksp);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      m_m2c_error(errCode);
    }
  }

  info = MPI_Barrier(t_comm);
  if (info != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      d_m2c_error(info);
    }
  }

  secs = MPI_Wtime();
  sizepe = sizeof(KSP);
  flag = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, flag, (int)sizeof(unsigned char));
  for (flag = 0; flag < 3; flag++) {
    t1_type[flag] = cv10[flag];
  }

  flag = ksp->data->size[0];
  ksp->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)ksp->data, flag, (int)sizeof(unsigned
    char));
  loop_ub = data0->size[0];
  for (flag = 0; flag < loop_ub; flag++) {
    ksp->data->data[flag] = data0->data[flag];
  }

  emxFree_uint8_T(&data0);
  flag = ksp->type->size[0] * ksp->type->size[1];
  ksp->type->size[0] = 1;
  ksp->type->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)ksp->type, flag, (int)sizeof(char));
  for (flag = 0; flag < 3; flag++) {
    ksp->type->data[flag] = t1_type[flag];
  }

  ksp->nitems = 1;
  ptr = (char *)(&t_ksp);
  for (i = 1; i <= sizepe; i++) {
    ksp->data->data[i - 1] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }

  *time = secs - t;
  *toplevel = true;
}

void mptKSPSetup_3args(const struct0_T *Amat, const emxArray_char_T *ksptype,
  const emxArray_char_T *pctype, struct0_T *ksp, double *time, boolean_T
  *toplevel)
{
  MPI_Comm varargin_1;
  KSP t_ksp;
  int errCode;
  int flag;
  PetscObject t_obj;
  MPI_Comm t_comm;
  int info;
  double t;
  emxArray_char_T *b_Amat;
  emxArray_uint8_T *data0;
  int loop_ub;
  Mat c_Amat;
  boolean_T b0;
  emxArray_char_T *pctype0;
  PC t_pc;
  double secs;
  int sizepe;
  char t0_type[3];
  static const char cv11[3] = { 'K', 'S', 'P' };

  char * ptr;
  int i;
  varargin_1 = petscObjectGetComm(Amat->data, Amat->type);
  errCode = KSPCreate(varargin_1, &t_ksp);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      c_m2c_error(errCode);
    }
  }

  t_obj = (PetscObject)(t_ksp);
  errCode = PetscObjectGetComm(t_obj, &t_comm);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      b_m2c_error(errCode);
    }
  }

  info = MPI_Barrier(t_comm);
  if (info != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      d_m2c_error(info);
    }
  }

  t = MPI_Wtime();
  if (!isequal(Amat->type)) {
    emxInit_char_T(&b_Amat, 2);
    flag = b_Amat->size[0] * b_Amat->size[1];
    b_Amat->size[0] = 1;
    b_Amat->size[1] = Amat->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_Amat, flag, (int)sizeof(char));
    loop_ub = Amat->type->size[1];
    for (flag = 0; flag < loop_ub; flag++) {
      b_Amat->data[b_Amat->size[0] * flag] = Amat->type->data[Amat->type->size[0]
        * flag];
    }

    b_Amat->data[b_Amat->size[0] * Amat->type->size[1]] = '\x00';
    e_m2c_error(b_Amat);
    emxFree_char_T(&b_Amat);
  }

  emxInit_uint8_T(&data0, 1);
  flag = data0->size[0];
  data0->size[0] = Amat->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, flag, (int)sizeof(unsigned char));
  loop_ub = Amat->data->size[0];
  for (flag = 0; flag < loop_ub; flag++) {
    data0->data[flag] = Amat->data->data[flag];
  }

  c_Amat = *(Mat*)(&data0->data[0]);
  errCode = KSPSetOperators(t_ksp, c_Amat, c_Amat);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      f_m2c_error(errCode);
    }
  }

  b0 = !(pctype->size[1] == 0);
  emxInit_char_T(&pctype0, 2);
  if (b0) {
    errCode = KSPGetPC(t_ksp, &t_pc);
    if (errCode != 0) {
      flag = (M2C_DEBUG);
      if (flag != 0) {
        g_m2c_error(errCode);
      }
    }

    if (pctype->data[pctype->size[1] - 1] != '\x00') {
      flag = pctype0->size[0] * pctype0->size[1];
      pctype0->size[0] = 1;
      pctype0->size[1] = pctype->size[1] + 1;
      emxEnsureCapacity((emxArray__common *)pctype0, flag, (int)sizeof(char));
      loop_ub = pctype->size[1];
      for (flag = 0; flag < loop_ub; flag++) {
        pctype0->data[pctype0->size[0] * flag] = pctype->data[pctype->size[0] *
          flag];
      }

      pctype0->data[pctype0->size[0] * pctype->size[1]] = '\x00';
    } else {
      flag = pctype0->size[0] * pctype0->size[1];
      pctype0->size[0] = 1;
      pctype0->size[1] = pctype->size[1];
      emxEnsureCapacity((emxArray__common *)pctype0, flag, (int)sizeof(char));
      loop_ub = pctype->size[0] * pctype->size[1];
      for (flag = 0; flag < loop_ub; flag++) {
        pctype0->data[flag] = pctype->data[flag];
      }
    }

    errCode = PCSetType(t_pc, &pctype0->data[0]);
    if (errCode != 0) {
      flag = (M2C_DEBUG);
      if (flag != 0) {
        h_m2c_error(errCode);
      }
    }
  }

  if ((!(ksptype->size[1] == 0)) && ((unsigned char)ksptype->data[ksptype->size
       [1] - 1] != 0)) {
    flag = pctype0->size[0] * pctype0->size[1];
    pctype0->size[0] = 1;
    pctype0->size[1] = ksptype->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)pctype0, flag, (int)sizeof(char));
    loop_ub = ksptype->size[1];
    for (flag = 0; flag < loop_ub; flag++) {
      pctype0->data[pctype0->size[0] * flag] = ksptype->data[ksptype->size[0] *
        flag];
    }

    pctype0->data[pctype0->size[0] * ksptype->size[1]] = '\x00';
  } else {
    flag = pctype0->size[0] * pctype0->size[1];
    pctype0->size[0] = 1;
    pctype0->size[1] = ksptype->size[1];
    emxEnsureCapacity((emxArray__common *)pctype0, flag, (int)sizeof(char));
    loop_ub = ksptype->size[0] * ksptype->size[1];
    for (flag = 0; flag < loop_ub; flag++) {
      pctype0->data[flag] = ksptype->data[flag];
    }
  }

  if (!(pctype0->size[1] == 0)) {
    errCode = KSPSetType(t_ksp, &pctype0->data[0]);
    if (errCode != 0) {
      flag = (M2C_DEBUG);
      if (flag != 0) {
        k_m2c_error(errCode);
      }
    }
  }

  emxFree_char_T(&pctype0);
  flag = (PC_RIGHT);
  errCode = KSPSetPCSide(t_ksp, flag);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      i_m2c_error(errCode);
    }
  }

  errCode = KSPSetFromOptions(t_ksp);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      l_m2c_error(errCode);
    }
  }

  errCode = KSPSetUp(t_ksp);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      m_m2c_error(errCode);
    }
  }

  info = MPI_Barrier(t_comm);
  if (info != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      d_m2c_error(info);
    }
  }

  secs = MPI_Wtime();
  sizepe = sizeof(KSP);
  flag = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, flag, (int)sizeof(unsigned char));
  for (flag = 0; flag < 3; flag++) {
    t0_type[flag] = cv11[flag];
  }

  flag = ksp->data->size[0];
  ksp->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)ksp->data, flag, (int)sizeof(unsigned
    char));
  loop_ub = data0->size[0];
  for (flag = 0; flag < loop_ub; flag++) {
    ksp->data->data[flag] = data0->data[flag];
  }

  emxFree_uint8_T(&data0);
  flag = ksp->type->size[0] * ksp->type->size[1];
  ksp->type->size[0] = 1;
  ksp->type->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)ksp->type, flag, (int)sizeof(char));
  for (flag = 0; flag < 3; flag++) {
    ksp->type->data[flag] = t0_type[flag];
  }

  ksp->nitems = 1;
  ptr = (char *)(&t_ksp);
  for (i = 1; i <= sizepe; i++) {
    ksp->data->data[i - 1] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }

  *time = secs - t;
  *toplevel = true;
}

void mptKSPSetup_initialize(void)
{
}

void mptKSPSetup_terminate(void)
{
}
