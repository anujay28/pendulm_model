/*
 * double_pend_varible_private.h
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

#ifndef RTW_HEADER_double_pend_varible_private_h_
#define RTW_HEADER_double_pend_varible_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "double_pend_varible.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern real_T rt_hypotd_snf(real_T u0, real_T u1);
extern real_T rt_powd_snf(real_T u0, real_T u1);
extern void double_pend_varible_C(const real_T rtu_m[2], const real_T rtu_l[2],
  const real_T rtu_q[2], const real_T rtu_qd[2], B_C_double_pend_varible_T
  *localB);
extern void double_pend_vari_MATLABFunction(const real_T rtu_q[2], const real_T
  rtu_l[2], B_MATLABFunction_double_pend__T *localB);
extern void double_pend_var_MATLABFunction1(const real_T rtu_q[2], const real_T
  rtu_l[2], B_MATLABFunction1_double_pend_T *localB);
extern void double_pend_varible_G(const real_T rtu_m[2], const real_T rtu_q[2],
  B_G_double_pend_varible_T *localB);
extern void double_pend_varible_M_l(const real_T rtu_m[2], const real_T rtu_l[2],
  const real_T rtu_q[2], B_M_double_pend_varible_T *localB);

/* private model entry point functions */
extern void double_pend_varible_derivatives(void);

#endif                           /* RTW_HEADER_double_pend_varible_private_h_ */
