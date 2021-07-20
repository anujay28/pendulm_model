/*
 * double_pend_varible_data.c
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

#include "double_pend_varible.h"
#include "double_pend_varible_private.h"

/* Block parameters (default storage) */
P_double_pend_varible_T double_pend_varible_P = {
  /* Variable: Bn0
   * Referenced by: '<S3>/Constant3'
   */
  { 500.0, 500.0 },

  /* Variable: Bp0
   * Referenced by: '<S3>/Constant2'
   */
  { 500.0, 500.0 },

  /* Variable: Dm1
   * Referenced by: '<S7>/Gain2'
   */
  { 30.0, 0.0, 0.0, 30.0 },

  /* Variable: Km1
   * Referenced by: '<S7>/Gain1'
   */
  { 30.0, 0.0, 0.0, 30.0 },

  /* Variable: Kn0
   * Referenced by: '<S3>/Constant1'
   */
  { 500.0, 500.0 },

  /* Variable: Kp0
   * Referenced by: '<S3>/Constant'
   */
  { 500.0, 500.0 },

  /* Variable: alpha
   * Referenced by: '<S3>/Constant4'
   */
  { 15.0, 15.0 },

  /* Variable: beta
   * Referenced by: '<S10>/Gain18'
   */
  { 0.5, 0.5 },

  /* Variable: dampener
   * Referenced by:
   *   '<S12>/Gain4'
   *   '<S13>/Gain4'
   */
  { 100.0, 0.0, 0.0, 100.0 },

  /* Variable: exo_sat
   * Referenced by: '<Root>/Saturation'
   */
  120.0,

  /* Variable: gamma
   * Referenced by: '<S3>/Constant5'
   */
  { 15.0, 15.0 },

  /* Variable: human_sat
   * Referenced by: '<Root>/Saturation3'
   */
  30.0,

  /* Variable: l
   * Referenced by:
   *   '<S4>/Constant1'
   *   '<S5>/Constant'
   *   '<S6>/Constant'
   *   '<S11>/Constant3'
   *   '<S14>/Gain1'
   *   '<S14>/Gain2'
   *   '<S14>/Gain3'
   *   '<S14>/Gain4'
   *   '<S14>/Gain5'
   *   '<S14>/Gain6'
   *   '<S14>/Gain7'
   *   '<S14>/Gain8'
   *   '<S15>/Gain1'
   *   '<S15>/Gain2'
   *   '<S15>/Gain3'
   *   '<S15>/Gain4'
   *   '<S15>/Gain5'
   *   '<S15>/Gain6'
   *   '<S15>/Gain7'
   *   '<S15>/Gain8'
   *   '<S31>/Constant1'
   */
  { 0.324, 0.39 },

  /* Variable: lambda2
   * Referenced by:
   *   '<S10>/Gain12'
   *   '<S10>/Gain3'
   */
  { 1.2, 0.0, 0.0, 1.25 },

  /* Variable: me
   * Referenced by:
   *   '<S4>/Constant'
   *   '<S31>/Constant'
   */
  { 3.2923999999999998, 1.6648 },

  /* Variable: mh
   * Referenced by: '<S11>/Constant2'
   */
  { 1.1824, 0.3848 },

  /* Variable: rho2
   * Referenced by: '<S10>/Gain4'
   */
  { 100.0, 0.0, 0.0, 450.0 },

  /* Variable: spring
   * Referenced by:
   *   '<S12>/Gain3'
   *   '<S13>/Gain3'
   */
  { 100.0, 0.0, 0.0, 100.0 },

  /* Expression: [ 0 , -pi, 0;  0 -0.5*pi,0 ]
   * Referenced by: '<Root>/Trajectory generation'
   */
  { 0.0, 0.0, -3.1415926535897931, -1.5707963267948966, 0.0, 0.0 },

  /* Expression: [ 0, 5, 10]
   * Referenced by: '<Root>/Trajectory generation'
   */
  { 0.0, 5.0, 10.0 },

  /* Expression: zeros( 2, 3 )
   * Referenced by: '<Root>/Trajectory generation'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 1
   * Referenced by: '<Root>/Sine Wave Function'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave Function'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<Root>/Sine Wave Function'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave Function'
   */
  0.0,

  /* Expression: -0.75
   * Referenced by: '<Root>/Constant2'
   */
  -0.75,

  /* Expression: [0.01;0.01]
   * Referenced by: '<S4>/Integrator4'
   */
  { 0.01, 0.01 },

  /* Expression: [0;0]
   * Referenced by: '<S4>/Integrator1'
   */
  { 0.0, 0.0 },

  /* Expression: p.R{1}
   * Referenced by: '<S16>/R1'
   */
  { 0.031622776601683791, 0.0, 0.0, 0.0, 0.0, 0.031622776601683791, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S16>/MeasurementFcn1Inputs'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/Constant5'
   */
  1.0,

  /* Expression: [pi;0.5*pi]
   * Referenced by: '<S3>/Integrator1'
   */
  { 3.1415926535897931, 1.5707963267948966 },

  /* Expression: 0
   * Referenced by: '<S3>/Integrator'
   */
  0.0,

  /* Expression: [0;0]
   * Referenced by: '<Root>/Constant3'
   */
  { 0.0, 0.0 },

  /* Expression: p.Q
   * Referenced by: '<S16>/Q'
   */
  { 0.31622776601683794, 0.0, 0.0, 0.0, 0.0, 3.1622776601683795, 0.0, 0.0, 0.0,
    0.0, 0.031622776601683791, 0.0, 0.0, 0.0, 0.0, 0.031622776601683791 },

  /* Expression: 60
   * Referenced by: '<S7>/Saturation'
   */
  60.0,

  /* Expression: -60
   * Referenced by: '<S7>/Saturation'
   */
  -60.0,

  /* Expression: p.InitialCovariance
   * Referenced by: '<S16>/DataStoreMemory - P'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0 },

  /* Expression: p.InitialState
   * Referenced by: '<S16>/DataStoreMemory - x'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: inv(Md)
   * Referenced by: '<S3>/Gain5'
   */
  { 0.1, -0.0, -0.0, 0.1 },

  /* Computed Parameter: yBlockOrdering_Y0
   * Referenced by: '<S17>/yBlockOrdering'
   */
  0,

  /* Expression: true()
   * Referenced by: '<S16>/BlockOrdering'
   */
  1
};
