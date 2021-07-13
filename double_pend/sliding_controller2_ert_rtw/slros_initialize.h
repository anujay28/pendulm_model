#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "slros_time.h"
#include "slros_generic_service.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block sliding_controller2/Subscribe
extern SimulinkSubscriber<ambf_walker::DesiredJoints, SL_Bus_sliding_controller2_ambf_walker_DesiredJoints> Sub_sliding_controller2_35;

// For Block sliding_controller2/Subscribe1
extern SimulinkSubscriber<sensor_msgs::JointState, SL_Bus_sliding_controller2_sensor_msgs_JointState> Sub_sliding_controller2_1262;

// For Block sliding_controller2/Subscribe2
extern SimulinkSubscriber<sensor_msgs::JointState, SL_Bus_sliding_controller2_sensor_msgs_JointState> Sub_sliding_controller2_1277;

// For Block sliding_controller2/Subscribe4
extern SimulinkSubscriber<std_msgs::Bool, SL_Bus_sliding_controller2_std_msgs_Bool> Sub_sliding_controller2_1418;

// For Block sliding_controller2/Controller/Publish1
extern SimulinkPublisher<std_msgs::Bool, SL_Bus_sliding_controller2_std_msgs_Bool> Pub_sliding_controller2_1405;

// For Block sliding_controller2/Enabled Subsystem/Publish1
extern SimulinkPublisher<sensor_msgs::JointState, SL_Bus_sliding_controller2_sensor_msgs_JointState> Pub_sliding_controller2_1242;

// For Block sliding_controller2/Enabled Subsystem/Publish2
extern SimulinkPublisher<sensor_msgs::JointState, SL_Bus_sliding_controller2_sensor_msgs_JointState> Pub_sliding_controller2_1246;

// For Block sliding_controller2/Publish2
extern SimulinkPublisher<std_msgs::Float64MultiArray, SL_Bus_sliding_controller2_std_msgs_Float64MultiArray> Pub_sliding_controller2_1428;

// For Block sliding_controller2/Controller/sliding mode controller/Call Service
extern SimulinkServiceCaller<rbdl_server::RBDLInverseDynamics, SL_Bus_sliding_controller2_RBDLInverseDynamicsReques_b5z6ex, SL_Bus_sliding_controller2_RBDLInverseDynamicsRespon_9vsb2h> ServCall_sliding_controller2_1160;

// For Block sliding_controller2/Subsystem1/If Action Subsystem/Call Service
extern SimulinkServiceCaller<std_srvs::SetBool, SL_Bus_sliding_controller2_std_srvs_SetBoolRequest, SL_Bus_sliding_controller2_std_srvs_SetBoolResponse> ServCall_sliding_controller2_47;

// For Block sliding_controller2/Subsystem1/If Action Subsystem/Call Service1
extern SimulinkServiceCaller<std_srvs::SetBool, SL_Bus_sliding_controller2_std_srvs_SetBoolRequest, SL_Bus_sliding_controller2_std_srvs_SetBoolResponse> ServCall_sliding_controller2_48;

void slros_node_init(int argc, char** argv);

#endif
