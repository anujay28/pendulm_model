//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: sliding_controller2.h
//
// Code generated for Simulink model 'sliding_controller2'.
//
// Model version                  : 1.184
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Jul 12 21:13:23 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_sliding_controller2_h_
#define RTW_HEADER_sliding_controller2_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "sliding_controller2_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
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

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
struct ODE3_IntgData {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
};

#endif

//
//  Exported Global Parameters
//
//  Note: Exported global parameters are tunable parameters with an exported
//  global storage class designation.  Code generation will declare the memory for
//  these parameters and exports their symbols.
//

extern real_T Dm1[49];                 // Variable: Dm1
                                          //  Referenced by: '<S25>/human derative gain'

extern real_T Km1[49];                 // Variable: Km1
                                          //  Referenced by: '<S25>/human proportional gain'

extern real_T dampener[4];             // Variable: dampener
                                          //  Referenced by:
                                          //    '<S31>/dampener left shank'
                                          //    '<S32>/dampener left thigh'
                                          //    '<S33>/dampener right shank'
                                          //    '<S34>/dampener right shank'

extern real_T exo_sat;                 // Variable: exo_sat
                                          //  Referenced by: '<S6>/exo sateration'

extern real_T invMd[49];               // Variable: invMd
                                          //  Referenced by: '<S24>/addmittance gain'

extern real_T lambda2[49];             // Variable: lambda2
                                          //  Referenced by:
                                          //    '<S26>/Gain12'
                                          //    '<S26>/lambda SMC'

extern real_T rho2[49];                // Variable: rho2
                                          //  Referenced by: '<S26>/rho SMC'


// Class declaration for model sliding_controller2
class sliding_controller2ModelClass {
  // public data and function members
 public:
  // Block signals (default storage)
  struct B_sliding_controller2_T {
    SL_Bus_sliding_controller2_sensor_msgs_JointState msg;// '<Root>/human msg'
    SL_Bus_sliding_controller2_sensor_msgs_JointState msg_n;// '<Root>/exo msg'
    SL_Bus_sliding_controller2_sensor_msgs_JointState In1;// '<S53>/In1'
    SL_Bus_sliding_controller2_sensor_msgs_JointState In1_n;// '<S52>/In1'
    SL_Bus_sliding_controller2_sensor_msgs_JointState In1_e;// '<S9>/In1'
    SL_Bus_sliding_controller2_sensor_msgs_JointState In1_j;// '<S8>/In1'
    SL_Bus_sliding_controller2_sensor_msgs_JointState BusAssignment1;// '<S7>/Bus Assignment1' 
    SL_Bus_sliding_controller2_sensor_msgs_JointState b_varargout_2;
    SL_Bus_sliding_controller2_sensor_msgs_JointState b_varargout_2_m;
    SL_Bus_sliding_controller2_std_msgs_Float64MultiArray BusAssignment3;// '<Root>/Bus Assignment3' 
    SL_Bus_sliding_controller2_std_msgs_String b_varargout_2_Name[16];
    SL_Bus_sliding_controller2_ambf_walker_DesiredJoints In1_a;// '<S51>/In1'
    SL_Bus_sliding_controller2_ambf_walker_DesiredJoints b_varargout_2_c;
    real_T change[49];
    real_T Y[49];
    SL_Bus_sliding_controller2_RBDLInverseDynamicsReques_b5z6ex msg_o;
                              // '<Root>/MATLAB Function - String Array Assign'
    SL_Bus_sliding_controller2_RBDLInverseDynamicsReques_b5z6ex BusAssignment;// '<S26>/Bus Assignment' 
    SL_Bus_sliding_controller2_std_msgs_Header BusAssignment1_m;// '<Root>/Bus Assignment1' 
    SL_Bus_sliding_controller2_std_srvs_SetBoolResponse b_varargout_1;
    uint8_T b_varargout_2_Header_FrameId[128];
    SL_Bus_sliding_controller2_RBDLInverseDynamicsRespon_9vsb2h b_varargout_1_k;
    real_T Sum[7];                     // '<S24>/Sum'
    real_T qd_add[7];                  // '<S24>/Integrator'
    real_T qd_add_n[7];                // '<S24>/addmittance gain'
    real_T Gain[7];                    // '<S6>/Gain'
    real_T exosateration[7];           // '<S6>/exo sateration'
    real_T K[49];                      // '<S24>/MATLAB Function'
    real_T B[49];                      // '<S24>/MATLAB Function'
    real_T B_c[7];
    real_T b_varargout_2_Effort[7];
    real_T Add1_i[7];                  // '<S26>/Add1'
    real_T humansateration[7];         // '<S6>/human sateration'
    real_T dv[7];
    real_T dv1[7];
    real_T work[7];
    real_T vn1[7];
    real_T vn2[7];
    real_T rtb_Transpose2_b_b[4];
    int32_T jpvt[7];
    char_T b_zeroDelimServiceName[24];
    char_T b_zeroDelimTopic[24];
    char_T b_zeroDelimTopic_p[23];
    char_T b_zeroDelimServiceName_c[22];
    char_T b_zeroDelimTopic_f[21];
    char_T b_zeroDelimTopic_g[20];
    char_T b_zeroDelimServiceName_g[17];
    SL_Bus_sliding_controller2_ros_time_Time rtb_CurrentTime_m;
    real_T rtb_danke_g_n[2];
    real_T rtb_ankle_l_p[2];
    real_T rtb_Product2_h_l[2];
    real_T rtb_danke_j[2];
    real_T rtb_ankle_d[2];
    real_T rtb_dknee_g[2];
    real_T rtb_knee_l[2];
    real_T rtb_Add_c_d[2];
    real_T Add_m[2];                   // '<S36>/Add'
    real_T Subtract2[2];               // '<S33>/Subtract2'
    real_T wj;
    real_T b_varargout_2_Header_Stamp_Sec;
    real_T rtb_Product2_k_idx_0;
    real_T rtb_Product2_k_idx_1;
    real_T rtb_Product2_idx_0;
    real_T rtb_Product2_idx_1;
    real_T rtb_Transpose2_b_idx_3;
    real_T rtb_Transpose2_idx_0;
    real_T rtb_Transpose2_idx_2;
    real_T rtb_Transpose2_idx_1;
    real_T rtb_Transpose2_idx_3;
    real_T rtb_knee_idx_0;
    real_T rtb_knee_idx_1;
    real_T rtb_dknee_idx_1;
    real_T smax;
    real_T beta1;
    real_T scale;
    real_T absxk;
    real_T t;
    SL_Bus_ROSVariableLengthArrayInfo b_varargout_2_Effort_SL_Info;
    SL_Bus_sliding_controller2_std_msgs_Bool In1_k;// '<S54>/In1'
    int32_T j;
    int32_T i;
    int32_T k;
    int32_T minmn;
    int32_T ii;
    int32_T nmi;
    int32_T mmi;
    int32_T pvt;
    int32_T ix;
    int32_T iy;
    int32_T b_k;
    int32_T c_ix;
    int32_T e;
    int32_T ia;
    uint32_T b_varargout_2_Header_Seq;
    uint32_T b_varargout_2_Header_FrameId_SL;
    uint32_T b_varargout_2_Header_FrameId__l;
    uint32_T b_varargout_2_Name_SL_Info_Curr;
    uint32_T b_varargout_2_Name_SL_Info_Rece;
    uint32_T b_varargout_2_Position_SL_Info_;
    uint32_T b_varargout_2_Position_SL_Inf_b;
    uint32_T b_varargout_2_Velocity_SL_Info_;
    uint32_T b_varargout_2_Velocity_SL_Inf_h;
    boolean_T LogicalOperator;         // '<Root>/Logical Operator'
    boolean_T SourceBlock_o1;          // '<S14>/SourceBlock'
    boolean_T SourceBlock_o1_h;        // '<S13>/SourceBlock'
  };

  // Block states (default storage) for system '<Root>'
  struct DW_sliding_controller2_T {
    ros_slros_internal_block_Curr_T obj;// '<Root>/Current Time'
    ros_slroscpp_internal_block_P_T obj_k;// '<S11>/SinkBlock'
    ros_slroscpp_internal_block_P_T obj_m;// '<S50>/SinkBlock'
    ros_slroscpp_internal_block_P_T obj_n;// '<S49>/SinkBlock'
    ros_slroscpp_internal_block_P_T obj_o;// '<S23>/SinkBlock'
    ros_slroscpp_internal_block_S_T obj_i;// '<S58>/ServiceCaller'
    ros_slroscpp_internal_block_S_T obj_b;// '<S57>/ServiceCaller'
    ros_slroscpp_internal_block_S_T obj_ox;// '<S48>/ServiceCaller'
    ros_slroscpp_internal_block_k_T obj_c;// '<S15>/SourceBlock'
    ros_slroscpp_internal_block_k_T obj_h;// '<S14>/SourceBlock'
    ros_slroscpp_internal_block_k_T obj_cg;// '<S13>/SourceBlock'
    ros_slroscpp_internal_block_k_T obj_g;// '<S12>/SourceBlock'
    int8_T If_ActiveSubsystem;         // '<S16>/If'
    boolean_T EnabledSubsystem_MODE;   // '<Root>/Enabled Subsystem'
    boolean_T Controller_MODE;         // '<Root>/Controller'
  };

  // Continuous states (default storage)
  struct X_sliding_controller2_T {
    real_T Integrator1_CSTATE[7];      // '<S24>/Integrator1'
    real_T Integrator_CSTATE[7];       // '<S24>/Integrator'
  };

  // State derivatives (default storage)
  struct XDot_sliding_controller2_T {
    real_T Integrator1_CSTATE[7];      // '<S24>/Integrator1'
    real_T Integrator_CSTATE[7];       // '<S24>/Integrator'
  };

  // State disabled
  struct XDis_sliding_controller2_T {
    boolean_T Integrator1_CSTATE[7];   // '<S24>/Integrator1'
    boolean_T Integrator_CSTATE[7];    // '<S24>/Integrator'
  };

  // Parameters (default storage)
  struct P_sliding_controller2_T {
    real_T human_sat;                  // Variable: human_sat
                                          //  Referenced by: '<S6>/human sateration'

    real_T spring[4];                  // Variable: spring
                                          //  Referenced by:
                                          //    '<S31>/spring left shank'
                                          //    '<S32>/spring left thigh'
                                          //    '<S33>/spring right thigh'
                                          //    '<S34>/spring right thigh'

    SL_Bus_sliding_controller2_sensor_msgs_JointState Constant_Value;// Computed Parameter: Constant_Value
                                                                      //  Referenced by: '<S1>/Constant'

    SL_Bus_sliding_controller2_sensor_msgs_JointState Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                                      //  Referenced by: '<S2>/Constant'

    SL_Bus_sliding_controller2_sensor_msgs_JointState exo_Y0;// Computed Parameter: exo_Y0
                                                                //  Referenced by: '<S8>/exo'

    SL_Bus_sliding_controller2_sensor_msgs_JointState human_Y0;// Computed Parameter: human_Y0
                                                                  //  Referenced by: '<S9>/human'

    SL_Bus_sliding_controller2_sensor_msgs_JointState Out1_Y0;// Computed Parameter: Out1_Y0
                                                                 //  Referenced by: '<S52>/Out1'

    SL_Bus_sliding_controller2_sensor_msgs_JointState Constant_Value_a;// Computed Parameter: Constant_Value_a
                                                                      //  Referenced by: '<S13>/Constant'

    SL_Bus_sliding_controller2_sensor_msgs_JointState Out1_Y0_f;// Computed Parameter: Out1_Y0_f
                                                                   //  Referenced by: '<S53>/Out1'

    SL_Bus_sliding_controller2_sensor_msgs_JointState Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                                      //  Referenced by: '<S14>/Constant'

    SL_Bus_sliding_controller2_std_msgs_Float64MultiArray Constant_Value_l;// Computed Parameter: Constant_Value_l
                                                                      //  Referenced by: '<S5>/Constant'

    SL_Bus_sliding_controller2_ambf_walker_DesiredJoints Out1_Y0_i;// Computed Parameter: Out1_Y0_i
                                                                      //  Referenced by: '<S51>/Out1'

    SL_Bus_sliding_controller2_ambf_walker_DesiredJoints Constant_Value_b;// Computed Parameter: Constant_Value_b
                                                                      //  Referenced by: '<S12>/Constant'

    SL_Bus_sliding_controller2_RBDLInverseDynamicsReques_b5z6ex Constant_Value_e;// Computed Parameter: Constant_Value_e
                                                                      //  Referenced by: '<S3>/Constant'

    SL_Bus_sliding_controller2_std_msgs_Header Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                                   //  Referenced by: '<S4>/Constant'

    SL_Bus_sliding_controller2_std_srvs_SetBoolResponse Constant_Value_f;// Computed Parameter: Constant_Value_f
                                                                      //  Referenced by: '<S57>/Constant'

    SL_Bus_sliding_controller2_std_srvs_SetBoolResponse Constant_Value_dy;// Computed Parameter: Constant_Value_dy
                                                                      //  Referenced by: '<S58>/Constant'

    SL_Bus_sliding_controller2_std_srvs_SetBoolResponse
      exointernalcontrollerstate_Y0;
                            // Computed Parameter: exointernalcontrollerstate_Y0
                               //  Referenced by: '<S55>/exo internal controller state'

    SL_Bus_sliding_controller2_std_srvs_SetBoolResponse
      humaninternalcontrollerstate1_Y;
                          // Computed Parameter: humaninternalcontrollerstate1_Y
                             //  Referenced by: '<S55>/human internal controller state1'

    SL_Bus_sliding_controller2_RBDLInverseDynamicsRespon_9vsb2h
      Constant_Value_bi;               // Computed Parameter: Constant_Value_bi
                                          //  Referenced by: '<S48>/Constant'

    SL_Bus_sliding_controller2_std_msgs_Bool Constant_Value_p;// Computed Parameter: Constant_Value_p
                                                                 //  Referenced by: '<S20>/Constant'

    SL_Bus_sliding_controller2_std_msgs_Bool Out1_Y0_d;// Computed Parameter: Out1_Y0_d
                                                          //  Referenced by: '<S54>/Out1'

    SL_Bus_sliding_controller2_std_msgs_Bool Constant_Value_ea;// Computed Parameter: Constant_Value_ea
                                                                  //  Referenced by: '<S15>/Constant'

    SL_Bus_sliding_controller2_std_srvs_SetBoolRequest Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                                      //  Referenced by: '<S56>/Constant'

    real_T exotau_Y0;                  // Computed Parameter: exotau_Y0
                                          //  Referenced by: '<S6>/exo tau'

    real_T humantau_Y0;                // Computed Parameter: humantau_Y0
                                          //  Referenced by: '<S6>/human tau'

    real_T Constant_Value_l4;          // Expression: 0
                                          //  Referenced by: '<S22>/Constant'

    real_T Constant_Value_o;           // Expression: 0
                                          //  Referenced by: '<S41>/Constant'

    real_T Constant_Value_pa;          // Expression: 0
                                          //  Referenced by: '<S42>/Constant'

    real_T Integrator1_IC[7];     // Expression: [-0.349,-0.2,0,-0.349,-0.2,0,0]
                                     //  Referenced by: '<S24>/Integrator1'

    real_T Integrator_IC;              // Expression: 0
                                          //  Referenced by: '<S24>/Integrator'

    real_T surfacewidthSMC_Gain;       // Expression: 0.5
                                          //  Referenced by: '<S26>/surface width SMC'

    real_T Constant_Value_c;           // Expression: 0
                                          //  Referenced by: '<S21>/Constant'

    real_T Constant_Value_fk;          // Expression: 0
                                          //  Referenced by: '<S35>/Constant'

    real_T Constant_Value_k;           // Expression: 0
                                          //  Referenced by: '<S36>/Constant'

    real_T Gain_Gain;                  // Expression: 0
                                          //  Referenced by: '<S6>/Gain'

    real_T Constant1_Value[7];         // Expression: [0.2,0.6,.01,.2,.5,.6,.4]
                                          //  Referenced by: '<Root>/Constant1'

    boolean_T Constant_Value_i1;       // Expression: true
                                          //  Referenced by: '<S6>/Constant'

    boolean_T Constant_Value_op;       // Expression: false
                                          //  Referenced by: '<S16>/Constant'

  };

  // Real-time Model Data Structure
  struct RT_MODEL_sliding_controller2_T {
    const char_T *errorStatus;
    RTWSolverInfo solverInfo;
    X_sliding_controller2_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T CTOutputIncnstWithState;
    real_T odeY[14];
    real_T odeF[3][14];
    ODE3_IntgData intgData;

    //
    //  Sizes:
    //  The following substructure contains sizes information
    //  for many of the model attributes such as inputs, outputs,
    //  dwork, sample times, etc.

    struct {
      int_T numContStates;
      int_T numPeriodicContStates;
      int_T numSampTimes;
    } Sizes;

    //
    //  Timing:
    //  The following substructure contains information regarding
    //  the timing information for the model.

    struct {
      uint32_T clockTick0;
      time_T stepSize0;
      uint32_T clockTick1;
      SimTimeStep simTimeStep;
      boolean_T stopRequestedFlag;
      time_T *t;
      time_T tArray[2];
    } Timing;
  };

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  sliding_controller2ModelClass();

  // Destructor
  ~sliding_controller2ModelClass();

  // Real-Time Model get method
  sliding_controller2ModelClass::RT_MODEL_sliding_controller2_T * getRTM();

  // private data and function members
 private:
  // Tunable parameters
  static P_sliding_controller2_T sliding_controller2_P;

  // Block signals
  B_sliding_controller2_T sliding_controller2_B;

  // Block states
  DW_sliding_controller2_T sliding_controller2_DW;
  X_sliding_controller2_T sliding_controller2_X;// Block continuous states

  // Real-Time Model
  RT_MODEL_sliding_controller2_T sliding_controller2_M;

  // private member function(s) for subsystem '<S19>/exo left'
  static void sliding_controller2_exoleft(const real_T rtu_q[2], const real_T
    rtu_qd[2], real_T rty_knee[2], real_T rty_dknee[2], real_T rty_ankle[2],
    real_T rty_danke[2]);

  // private member function(s) for subsystem '<S35>/MATLAB Function'
  static void sliding_controll_MATLABFunction(const real_T rtu_q[2], real_T
    rty_y[4]);

  // private member function(s) for subsystem '<S35>/MATLAB Function1'
  static void sliding_control_MATLABFunction1(const real_T rtu_q[2], real_T
    rty_y[4]);

  // private member function(s) for subsystem '<Root>'
  void sliding_control_SystemCore_step(boolean_T *varargout_1, uint32_T
    *varargout_2_Header_Seq, real_T *varargout_2_Header_Stamp_Sec, real_T
    *varargout_2_Header_Stamp_Nsec, uint8_T varargout_2_Header_FrameId[128],
    uint32_T *varargout_2_Header_FrameId_SL_I, uint32_T
    *varargout_2_Header_FrameId_SL_0, SL_Bus_sliding_controller2_std_msgs_String
    varargout_2_Name[16], uint32_T *varargout_2_Name_SL_Info_Curren, uint32_T
    *varargout_2_Name_SL_Info_Receiv, real_T varargout_2_Position[7], uint32_T
    *varargout_2_Position_SL_Info_Cu, uint32_T *varargout_2_Position_SL_Info_Re,
    real_T varargout_2_Velocity[7], uint32_T *varargout_2_Velocity_SL_Info_Cu,
    uint32_T *varargout_2_Velocity_SL_Info_Re, real_T varargout_2_Effort[7],
    SL_Bus_ROSVariableLengthArrayInfo *varargout_2_Effort_SL_Info);
  void sliding_contr_SystemCore_step_k(boolean_T *varargout_1, uint32_T
    *varargout_2_Header_Seq, real_T *varargout_2_Header_Stamp_Sec, real_T
    *varargout_2_Header_Stamp_Nsec, uint8_T varargout_2_Header_FrameId[128],
    uint32_T *varargout_2_Header_FrameId_SL_I, uint32_T
    *varargout_2_Header_FrameId_SL_0, SL_Bus_sliding_controller2_std_msgs_String
    varargout_2_Name[16], uint32_T *varargout_2_Name_SL_Info_Curren, uint32_T
    *varargout_2_Name_SL_Info_Receiv, real_T varargout_2_Position[7], uint32_T
    *varargout_2_Position_SL_Info_Cu, uint32_T *varargout_2_Position_SL_Info_Re,
    real_T varargout_2_Velocity[7], uint32_T *varargout_2_Velocity_SL_Info_Cu,
    uint32_T *varargout_2_Velocity_SL_Info_Re, real_T varargout_2_Effort[7],
    SL_Bus_ROSVariableLengthArrayInfo *varargout_2_Effort_SL_Info);
  real_T sliding_controller2_xnrm2(int32_T n, const real_T x[7], int32_T ix0);
  void sliding_controller2_qrpf(real_T A[7], int32_T ia0, int32_T m, int32_T n,
    real_T *tau, int32_T jpvt[7]);

  // Continuous states update member function
  void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si );

  // Derivatives member function
  void sliding_controller2_derivatives();
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Display' : Unused code path elimination
//  Block '<Root>/To Workspace' : Unused code path elimination
//  Block '<S16>/Data Type Conversion' : Eliminate redundant data type conversion


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'sliding_controller2'
//  '<S1>'   : 'sliding_controller2/Blank Message1'
//  '<S2>'   : 'sliding_controller2/Blank Message2'
//  '<S3>'   : 'sliding_controller2/Blank Message3'
//  '<S4>'   : 'sliding_controller2/Blank Message4'
//  '<S5>'   : 'sliding_controller2/Blank Message6'
//  '<S6>'   : 'sliding_controller2/Controller'
//  '<S7>'   : 'sliding_controller2/Enabled Subsystem'
//  '<S8>'   : 'sliding_controller2/Enabled Subsystem1'
//  '<S9>'   : 'sliding_controller2/Enabled Subsystem2'
//  '<S10>'  : 'sliding_controller2/MATLAB Function - String Array Assign'
//  '<S11>'  : 'sliding_controller2/Publish2'
//  '<S12>'  : 'sliding_controller2/Subscribe'
//  '<S13>'  : 'sliding_controller2/Subscribe1'
//  '<S14>'  : 'sliding_controller2/Subscribe2'
//  '<S15>'  : 'sliding_controller2/Subscribe4'
//  '<S16>'  : 'sliding_controller2/Subsystem1'
//  '<S17>'  : 'sliding_controller2/exo msg'
//  '<S18>'  : 'sliding_controller2/human msg'
//  '<S19>'  : 'sliding_controller2/Controller/ interaction sping-damper'
//  '<S20>'  : 'sliding_controller2/Controller/Blank Message5'
//  '<S21>'  : 'sliding_controller2/Controller/F->tau'
//  '<S22>'  : 'sliding_controller2/Controller/F->tau1'
//  '<S23>'  : 'sliding_controller2/Controller/Publish1'
//  '<S24>'  : 'sliding_controller2/Controller/addmittance'
//  '<S25>'  : 'sliding_controller2/Controller/human controller'
//  '<S26>'  : 'sliding_controller2/Controller/sliding mode controller'
//  '<S27>'  : 'sliding_controller2/Controller/ interaction sping-damper/exo left'
//  '<S28>'  : 'sliding_controller2/Controller/ interaction sping-damper/exo right'
//  '<S29>'  : 'sliding_controller2/Controller/ interaction sping-damper/human left'
//  '<S30>'  : 'sliding_controller2/Controller/ interaction sping-damper/human right'
//  '<S31>'  : 'sliding_controller2/Controller/ interaction sping-damper/left shank'
//  '<S32>'  : 'sliding_controller2/Controller/ interaction sping-damper/left thigh'
//  '<S33>'  : 'sliding_controller2/Controller/ interaction sping-damper/right shank'
//  '<S34>'  : 'sliding_controller2/Controller/ interaction sping-damper/right tight'
//  '<S35>'  : 'sliding_controller2/Controller/F->tau/Subsystem'
//  '<S36>'  : 'sliding_controller2/Controller/F->tau/Subsystem1'
//  '<S37>'  : 'sliding_controller2/Controller/F->tau/Subsystem/MATLAB Function'
//  '<S38>'  : 'sliding_controller2/Controller/F->tau/Subsystem/MATLAB Function1'
//  '<S39>'  : 'sliding_controller2/Controller/F->tau/Subsystem1/MATLAB Function'
//  '<S40>'  : 'sliding_controller2/Controller/F->tau/Subsystem1/MATLAB Function1'
//  '<S41>'  : 'sliding_controller2/Controller/F->tau1/Subsystem'
//  '<S42>'  : 'sliding_controller2/Controller/F->tau1/Subsystem1'
//  '<S43>'  : 'sliding_controller2/Controller/F->tau1/Subsystem/MATLAB Function'
//  '<S44>'  : 'sliding_controller2/Controller/F->tau1/Subsystem/MATLAB Function1'
//  '<S45>'  : 'sliding_controller2/Controller/F->tau1/Subsystem1/MATLAB Function'
//  '<S46>'  : 'sliding_controller2/Controller/F->tau1/Subsystem1/MATLAB Function1'
//  '<S47>'  : 'sliding_controller2/Controller/addmittance/MATLAB Function'
//  '<S48>'  : 'sliding_controller2/Controller/sliding mode controller/Call Service'
//  '<S49>'  : 'sliding_controller2/Enabled Subsystem/Publish1'
//  '<S50>'  : 'sliding_controller2/Enabled Subsystem/Publish2'
//  '<S51>'  : 'sliding_controller2/Subscribe/Enabled Subsystem'
//  '<S52>'  : 'sliding_controller2/Subscribe1/Enabled Subsystem'
//  '<S53>'  : 'sliding_controller2/Subscribe2/Enabled Subsystem'
//  '<S54>'  : 'sliding_controller2/Subscribe4/Enabled Subsystem'
//  '<S55>'  : 'sliding_controller2/Subsystem1/If Action Subsystem'
//  '<S56>'  : 'sliding_controller2/Subsystem1/If Action Subsystem/Blank Message'
//  '<S57>'  : 'sliding_controller2/Subsystem1/If Action Subsystem/Call Service'
//  '<S58>'  : 'sliding_controller2/Subsystem1/If Action Subsystem/Call Service1'

#endif                                 // RTW_HEADER_sliding_controller2_h_

//
// File trailer for generated code.
//
// [EOF]
//
