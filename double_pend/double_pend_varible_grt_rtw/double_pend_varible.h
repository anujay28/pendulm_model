/*
 * double_pend_varible.h
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

#ifndef RTW_HEADER_double_pend_varible_h_
#define RTW_HEADER_double_pend_varible_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef double_pend_varible_COMMON_INCLUDES_
#define double_pend_varible_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                /* double_pend_varible_COMMON_INCLUDES_ */

#include "double_pend_varible_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals for system '<S4>/C' */
typedef struct {
  real_T y[2];                         /* '<S4>/C' */
} B_C_double_pend_varible_T;

/* Block signals for system '<S5>/MATLAB Function' */
typedef struct {
  real_T y[4];                         /* '<S5>/MATLAB Function' */
} B_MATLABFunction_double_pend__T;

/* Block signals for system '<S5>/MATLAB Function1' */
typedef struct {
  real_T y[4];                         /* '<S5>/MATLAB Function1' */
} B_MATLABFunction1_double_pend_T;

/* Block signals for system '<S31>/G' */
typedef struct {
  real_T y[2];                         /* '<S31>/G' */
} B_G_double_pend_varible_T;

/* Block signals for system '<S31>/M' */
typedef struct {
  real_T y[4];                         /* '<S31>/M' */
} B_M_double_pend_varible_T;

/* Block signals (default storage) */
typedef struct {
  real_T Product;                      /* '<Root>/Product' */
  real_T Integrator4[2];               /* '<S4>/Integrator4' */
  real_T Integrator1[2];               /* '<S4>/Integrator1' */
  real_T Gain5;                        /* '<S14>/Gain5' */
  real_T Gain6;                        /* '<S14>/Gain6' */
  real_T Product2;                     /* '<S14>/Product2' */
  real_T Product3;                     /* '<S14>/Product3' */
  real_T Subtract2[2];                 /* '<S12>/Subtract2' */
  real_T Add[2];                       /* '<S14>/Add' */
  real_T Add1[2];                      /* '<S14>/Add1' */
  real_T Subtract2_c[2];               /* '<S13>/Subtract2' */
  real_T Add_b[2];                     /* '<S5>/Add' */
  real_T q_add[2];                     /* '<S3>/Sum1' */
  real_T qd_add[2];                    /* '<S3>/Integrator' */
  real_T q_add_a[2];                   /* '<S3>/Sum2' */
  real_T Transpose1[4];                /* '<S6>/Transpose1' */
  real_T Transpose2[4];                /* '<S6>/Transpose2' */
  real_T Nm[2];                        /* '<Root>/Saturation3' */
  real_T Add_j[2];                     /* '<S10>/Add' */
  real_T Tanh[2];                      /* '<S10>/Tanh' */
  real_T qd_add_b[2];                  /* '<S3>/Gain5' */
  real_T Product1[2];                  /* '<S4>/Product1' */
  real_T Sign[2];                      /* '<S10>/Sign' */
  real_T K[4];                         /* '<S3>/MATLAB Function' */
  real_T B[4];                         /* '<S3>/MATLAB Function' */
  real_T Trajectorygeneration_o1[2];   /* '<Root>/Trajectory generation' */
  real_T DataStoreRead[4];             /* '<S18>/Data Store Read' */
  B_M_double_pend_varible_T sf_M1;     /* '<S11>/M1' */
  B_G_double_pend_varible_T sf_G_pn;   /* '<S11>/G' */
  B_C_double_pend_varible_T sf_C_i;    /* '<S11>/C' */
  B_M_double_pend_varible_T sf_M_l;    /* '<S31>/M' */
  B_G_double_pend_varible_T sf_G_p;    /* '<S31>/G' */
  B_C_double_pend_varible_T sf_C_e;    /* '<S31>/C' */
  B_MATLABFunction1_double_pend_T sf_MATLABFunction1_d;/* '<S6>/MATLAB Function1' */
  B_MATLABFunction_double_pend__T sf_MATLABFunction_h1;/* '<S6>/MATLAB Function' */
  B_MATLABFunction1_double_pend_T sf_MATLABFunction1;/* '<S5>/MATLAB Function1' */
  B_MATLABFunction_double_pend__T sf_MATLABFunction_h;/* '<S5>/MATLAB Function' */
  B_C_double_pend_varible_T sf_C;      /* '<S4>/C' */
} B_double_pend_varible_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  robotics_slcore_internal_bloc_T obj; /* '<Root>/Trajectory generation' */
  real_T P[16];                        /* '<S16>/DataStoreMemory - P' */
  real_T x[4];                         /* '<S16>/DataStoreMemory - x' */
  boolean_T objisempty;                /* '<Root>/Trajectory generation' */
} DW_double_pend_varible_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator4_CSTATE[2];        /* '<S4>/Integrator4' */
  real_T Integrator1_CSTATE[2];        /* '<S4>/Integrator1' */
  real_T Integrator1_CSTATE_j[2];      /* '<S3>/Integrator1' */
  real_T Integrator_CSTATE[2];         /* '<S3>/Integrator' */
} X_double_pend_varible_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator4_CSTATE[2];        /* '<S4>/Integrator4' */
  real_T Integrator1_CSTATE[2];        /* '<S4>/Integrator1' */
  real_T Integrator1_CSTATE_j[2];      /* '<S3>/Integrator1' */
  real_T Integrator_CSTATE[2];         /* '<S3>/Integrator' */
} XDot_double_pend_varible_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator4_CSTATE[2];     /* '<S4>/Integrator4' */
  boolean_T Integrator1_CSTATE[2];     /* '<S4>/Integrator1' */
  boolean_T Integrator1_CSTATE_j[2];   /* '<S3>/Integrator1' */
  boolean_T Integrator_CSTATE[2];      /* '<S3>/Integrator' */
} XDis_double_pend_varible_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_double_pend_varible_T_ {
  real_T Bn0[2];                       /* Variable: Bn0
                                        * Referenced by: '<S3>/Constant3'
                                        */
  real_T Bp0[2];                       /* Variable: Bp0
                                        * Referenced by: '<S3>/Constant2'
                                        */
  real_T Dm1[4];                       /* Variable: Dm1
                                        * Referenced by: '<S7>/Gain2'
                                        */
  real_T Km1[4];                       /* Variable: Km1
                                        * Referenced by: '<S7>/Gain1'
                                        */
  real_T Kn0[2];                       /* Variable: Kn0
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Kp0[2];                       /* Variable: Kp0
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T alpha[2];                     /* Variable: alpha
                                        * Referenced by: '<S3>/Constant4'
                                        */
  real_T beta[2];                      /* Variable: beta
                                        * Referenced by: '<S10>/Gain18'
                                        */
  real_T dampener[4];                  /* Variable: dampener
                                        * Referenced by:
                                        *   '<S12>/Gain4'
                                        *   '<S13>/Gain4'
                                        */
  real_T exo_sat;                      /* Variable: exo_sat
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T gamma[2];                     /* Variable: gamma
                                        * Referenced by: '<S3>/Constant5'
                                        */
  real_T human_sat;                    /* Variable: human_sat
                                        * Referenced by: '<Root>/Saturation3'
                                        */
  real_T l[2];                         /* Variable: l
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
  real_T lambda2[4];                   /* Variable: lambda2
                                        * Referenced by:
                                        *   '<S10>/Gain12'
                                        *   '<S10>/Gain3'
                                        */
  real_T me[2];                        /* Variable: me
                                        * Referenced by:
                                        *   '<S4>/Constant'
                                        *   '<S31>/Constant'
                                        */
  real_T mh[2];                        /* Variable: mh
                                        * Referenced by: '<S11>/Constant2'
                                        */
  real_T rho2[4];                      /* Variable: rho2
                                        * Referenced by: '<S10>/Gain4'
                                        */
  real_T spring[4];                    /* Variable: spring
                                        * Referenced by:
                                        *   '<S12>/Gain3'
                                        *   '<S13>/Gain3'
                                        */
  real_T Trajectorygeneration_Waypoints[6];
                                     /* Expression: [ 0 , -pi, 0;  0 -0.5*pi,0 ]
                                      * Referenced by: '<Root>/Trajectory generation'
                                      */
  real_T Trajectorygeneration_TimePoints[3];/* Expression: [ 0, 5, 10]
                                             * Referenced by: '<Root>/Trajectory generation'
                                             */
  real_T Trajectorygeneration_VelocityBo[6];/* Expression: zeros( 2, 3 )
                                             * Referenced by: '<Root>/Trajectory generation'
                                             */
  real_T SineWaveFunction_Amp;         /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave Function'
                                        */
  real_T SineWaveFunction_Bias;        /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave Function'
                                        */
  real_T SineWaveFunction_Freq;        /* Expression: 5
                                        * Referenced by: '<Root>/Sine Wave Function'
                                        */
  real_T SineWaveFunction_Phase;       /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave Function'
                                        */
  real_T Constant2_Value;              /* Expression: -0.75
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Integrator4_IC[2];            /* Expression: [0.01;0.01]
                                        * Referenced by: '<S4>/Integrator4'
                                        */
  real_T Integrator1_IC[2];            /* Expression: [0;0]
                                        * Referenced by: '<S4>/Integrator1'
                                        */
  real_T R1_Value[16];                 /* Expression: p.R{1}
                                        * Referenced by: '<S16>/R1'
                                        */
  real_T MeasurementFcn1Inputs_Value;  /* Expression: 0
                                        * Referenced by: '<S16>/MeasurementFcn1Inputs'
                                        */
  real_T Constant5_Value;              /* Expression: 1
                                        * Referenced by: '<S2>/Constant5'
                                        */
  real_T Integrator1_IC_n[2];          /* Expression: [pi;0.5*pi]
                                        * Referenced by: '<S3>/Integrator1'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S3>/Integrator'
                                        */
  real_T Constant3_Value[2];           /* Expression: [0;0]
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Q_Value[16];                  /* Expression: p.Q
                                        * Referenced by: '<S16>/Q'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 60
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -60
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T DataStoreMemoryP_InitialValue[16];/* Expression: p.InitialCovariance
                                            * Referenced by: '<S16>/DataStoreMemory - P'
                                            */
  real_T DataStoreMemoryx_InitialValue[4];/* Expression: p.InitialState
                                           * Referenced by: '<S16>/DataStoreMemory - x'
                                           */
  real_T Gain5_Gain[4];                /* Expression: inv(Md)
                                        * Referenced by: '<S3>/Gain5'
                                        */
  boolean_T yBlockOrdering_Y0;         /* Computed Parameter: yBlockOrdering_Y0
                                        * Referenced by: '<S17>/yBlockOrdering'
                                        */
  boolean_T BlockOrdering_Value;       /* Expression: true()
                                        * Referenced by: '<S16>/BlockOrdering'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_double_pend_varible_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_double_pend_varible_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[8];
  real_T odeF[3][8];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_double_pend_varible_T double_pend_varible_P;

/* Block signals (default storage) */
extern B_double_pend_varible_T double_pend_varible_B;

/* Continuous states (default storage) */
extern X_double_pend_varible_T double_pend_varible_X;

/* Block states (default storage) */
extern DW_double_pend_varible_T double_pend_varible_DW;

/* Model entry point functions */
extern void double_pend_varible_initialize(void);
extern void double_pend_varible_step(void);
extern void double_pend_varible_terminate(void);

/* Real-time Model object */
extern RT_MODEL_double_pend_varible_T *const double_pend_varible_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'double_pend_varible'
 * '<S1>'   : 'double_pend_varible/ interaction sping-damper'
 * '<S2>'   : 'double_pend_varible/EKF'
 * '<S3>'   : 'double_pend_varible/addmittance'
 * '<S4>'   : 'double_pend_varible/exo model'
 * '<S5>'   : 'double_pend_varible/forward kin exo'
 * '<S6>'   : 'double_pend_varible/forward kin human'
 * '<S7>'   : 'double_pend_varible/human controller'
 * '<S8>'   : 'double_pend_varible/joint 1'
 * '<S9>'   : 'double_pend_varible/joint 2'
 * '<S10>'  : 'double_pend_varible/sliding mode controller'
 * '<S11>'  : 'double_pend_varible/standered interation exo'
 * '<S12>'  : 'double_pend_varible/ interaction sping-damper/Subsystem'
 * '<S13>'  : 'double_pend_varible/ interaction sping-damper/Subsystem1'
 * '<S14>'  : 'double_pend_varible/ interaction sping-damper/forward kin'
 * '<S15>'  : 'double_pend_varible/ interaction sping-damper/forward kin2'
 * '<S16>'  : 'double_pend_varible/EKF/Extended Kalman Filter'
 * '<S17>'  : 'double_pend_varible/EKF/Extended Kalman Filter/Correct1'
 * '<S18>'  : 'double_pend_varible/EKF/Extended Kalman Filter/Output'
 * '<S19>'  : 'double_pend_varible/EKF/Extended Kalman Filter/Predict'
 * '<S20>'  : 'double_pend_varible/EKF/Extended Kalman Filter/Correct1/Correct'
 * '<S21>'  : 'double_pend_varible/EKF/Extended Kalman Filter/Output/MATLAB Function'
 * '<S22>'  : 'double_pend_varible/EKF/Extended Kalman Filter/Predict/Predict'
 * '<S23>'  : 'double_pend_varible/addmittance/MATLAB Function'
 * '<S24>'  : 'double_pend_varible/exo model/C'
 * '<S25>'  : 'double_pend_varible/exo model/G'
 * '<S26>'  : 'double_pend_varible/exo model/M'
 * '<S27>'  : 'double_pend_varible/forward kin exo/MATLAB Function'
 * '<S28>'  : 'double_pend_varible/forward kin exo/MATLAB Function1'
 * '<S29>'  : 'double_pend_varible/forward kin human/MATLAB Function'
 * '<S30>'  : 'double_pend_varible/forward kin human/MATLAB Function1'
 * '<S31>'  : 'double_pend_varible/sliding mode controller/inv model 1'
 * '<S32>'  : 'double_pend_varible/sliding mode controller/inv model 1/C'
 * '<S33>'  : 'double_pend_varible/sliding mode controller/inv model 1/G'
 * '<S34>'  : 'double_pend_varible/sliding mode controller/inv model 1/M'
 * '<S35>'  : 'double_pend_varible/standered interation exo/C'
 * '<S36>'  : 'double_pend_varible/standered interation exo/G'
 * '<S37>'  : 'double_pend_varible/standered interation exo/M1'
 */
#endif                                 /* RTW_HEADER_double_pend_varible_h_ */
