/*
 * double_pend_varible_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "double_pend_varible".
 *
 * Model version              : 3.85
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Thu Jul 15 11:08:39 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_double_pend_varible_types_h_
#define RTW_HEADER_double_pend_varible_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"

/* Model Code Variants */
#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_double_pend_varible_T
#define typedef_cell_wrap_double_pend_varible_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_double_pend_varible_T;

#endif                             /* typedef_cell_wrap_double_pend_varible_T */

#ifndef struct_tag_HPDzvHOPi4rZ9H07K2f7hH
#define struct_tag_HPDzvHOPi4rZ9H07K2f7hH

struct tag_HPDzvHOPi4rZ9H07K2f7hH
{
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
  cell_wrap_double_pend_varible_T inputVarSize;
  real_T Waypoints[6];
  real_T TimePoints[3];
  real_T VelocityBoundaryCondition[6];
  real_T AccelerationBoundaryCondition[10];
};

#endif                                 /* struct_tag_HPDzvHOPi4rZ9H07K2f7hH */

#ifndef typedef_robotics_slcore_internal_bloc_T
#define typedef_robotics_slcore_internal_bloc_T

typedef struct tag_HPDzvHOPi4rZ9H07K2f7hH robotics_slcore_internal_bloc_T;

#endif                             /* typedef_robotics_slcore_internal_bloc_T */

/* Parameters (default storage) */
typedef struct P_double_pend_varible_T_ P_double_pend_varible_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_double_pend_varible_T RT_MODEL_double_pend_varible_T;

#endif                             /* RTW_HEADER_double_pend_varible_types_h_ */
