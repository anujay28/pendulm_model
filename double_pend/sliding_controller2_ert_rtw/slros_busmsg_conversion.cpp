#include "slros_busmsg_conversion.h"


// Conversions between SL_Bus_sliding_controller2_ambf_walker_DesiredJoints and ambf_walker::DesiredJoints

void convertFromBus(ambf_walker::DesiredJoints* msgPtr, SL_Bus_sliding_controller2_ambf_walker_DesiredJoints const* busPtr)
{
  const std::string rosMessageType("ambf_walker/DesiredJoints");

  convertFromBusVariablePrimitiveArray(msgPtr->controller, busPtr->Controller, busPtr->Controller_SL_Info);
  convertFromBus(&msgPtr->header, &busPtr->Header);
  convertFromBusVariablePrimitiveArray(msgPtr->other, busPtr->Other, busPtr->Other_SL_Info);
  convertFromBusVariablePrimitiveArray(msgPtr->q, busPtr->Q, busPtr->Q_SL_Info);
  convertFromBusVariablePrimitiveArray(msgPtr->qd, busPtr->Qd, busPtr->Qd_SL_Info);
  convertFromBusVariablePrimitiveArray(msgPtr->qdd, busPtr->Qdd, busPtr->Qdd_SL_Info);
}

void convertToBus(SL_Bus_sliding_controller2_ambf_walker_DesiredJoints* busPtr, ambf_walker::DesiredJoints const* msgPtr)
{
  const std::string rosMessageType("ambf_walker/DesiredJoints");

  convertToBusVariablePrimitiveArray(busPtr->Controller, busPtr->Controller_SL_Info, msgPtr->controller, slros::EnabledWarning(rosMessageType, "controller"));
  convertToBus(&busPtr->Header, &msgPtr->header);
  convertToBusVariablePrimitiveArray(busPtr->Other, busPtr->Other_SL_Info, msgPtr->other, slros::EnabledWarning(rosMessageType, "other"));
  convertToBusVariablePrimitiveArray(busPtr->Q, busPtr->Q_SL_Info, msgPtr->q, slros::EnabledWarning(rosMessageType, "q"));
  convertToBusVariablePrimitiveArray(busPtr->Qd, busPtr->Qd_SL_Info, msgPtr->qd, slros::EnabledWarning(rosMessageType, "qd"));
  convertToBusVariablePrimitiveArray(busPtr->Qdd, busPtr->Qdd_SL_Info, msgPtr->qdd, slros::EnabledWarning(rosMessageType, "qdd"));
}


// Conversions between SL_Bus_sliding_controller2_RBDLInverseDynamicsReques_b5z6ex and rbdl_server::RBDLInverseDynamicsRequest

void convertFromBus(rbdl_server::RBDLInverseDynamicsRequest* msgPtr, SL_Bus_sliding_controller2_RBDLInverseDynamicsReques_b5z6ex const* busPtr)
{
  const std::string rosMessageType("rbdl_server/RBDLInverseDynamicsRequest");

  convertFromBusVariablePrimitiveArray(msgPtr->model_name, busPtr->ModelName, busPtr->ModelName_SL_Info);
  convertFromBusVariablePrimitiveArray(msgPtr->q, busPtr->Q, busPtr->Q_SL_Info);
  convertFromBusVariablePrimitiveArray(msgPtr->qd, busPtr->Qd, busPtr->Qd_SL_Info);
  convertFromBusVariablePrimitiveArray(msgPtr->qdd, busPtr->Qdd, busPtr->Qdd_SL_Info);
}

void convertToBus(SL_Bus_sliding_controller2_RBDLInverseDynamicsReques_b5z6ex* busPtr, rbdl_server::RBDLInverseDynamicsRequest const* msgPtr)
{
  const std::string rosMessageType("rbdl_server/RBDLInverseDynamicsRequest");

  convertToBusVariablePrimitiveArray(busPtr->ModelName, busPtr->ModelName_SL_Info, msgPtr->model_name, slros::EnabledWarning(rosMessageType, "model_name"));
  convertToBusVariablePrimitiveArray(busPtr->Q, busPtr->Q_SL_Info, msgPtr->q, slros::EnabledWarning(rosMessageType, "q"));
  convertToBusVariablePrimitiveArray(busPtr->Qd, busPtr->Qd_SL_Info, msgPtr->qd, slros::EnabledWarning(rosMessageType, "qd"));
  convertToBusVariablePrimitiveArray(busPtr->Qdd, busPtr->Qdd_SL_Info, msgPtr->qdd, slros::EnabledWarning(rosMessageType, "qdd"));
}


// Conversions between SL_Bus_sliding_controller2_RBDLInverseDynamicsRespon_9vsb2h and rbdl_server::RBDLInverseDynamicsResponse

void convertFromBus(rbdl_server::RBDLInverseDynamicsResponse* msgPtr, SL_Bus_sliding_controller2_RBDLInverseDynamicsRespon_9vsb2h const* busPtr)
{
  const std::string rosMessageType("rbdl_server/RBDLInverseDynamicsResponse");

  convertFromBusVariablePrimitiveArray(msgPtr->tau, busPtr->Tau, busPtr->Tau_SL_Info);
}

void convertToBus(SL_Bus_sliding_controller2_RBDLInverseDynamicsRespon_9vsb2h* busPtr, rbdl_server::RBDLInverseDynamicsResponse const* msgPtr)
{
  const std::string rosMessageType("rbdl_server/RBDLInverseDynamicsResponse");

  convertToBusVariablePrimitiveArray(busPtr->Tau, busPtr->Tau_SL_Info, msgPtr->tau, slros::EnabledWarning(rosMessageType, "tau"));
}


// Conversions between SL_Bus_sliding_controller2_ros_time_Time and ros::Time

void convertFromBus(ros::Time* msgPtr, SL_Bus_sliding_controller2_ros_time_Time const* busPtr)
{
  const std::string rosMessageType("ros_time/Time");

  msgPtr->nsec =  busPtr->Nsec;
  msgPtr->sec =  busPtr->Sec;
}

void convertToBus(SL_Bus_sliding_controller2_ros_time_Time* busPtr, ros::Time const* msgPtr)
{
  const std::string rosMessageType("ros_time/Time");

  busPtr->Nsec =  msgPtr->nsec;
  busPtr->Sec =  msgPtr->sec;
}


// Conversions between SL_Bus_sliding_controller2_sensor_msgs_JointState and sensor_msgs::JointState

void convertFromBus(sensor_msgs::JointState* msgPtr, SL_Bus_sliding_controller2_sensor_msgs_JointState const* busPtr)
{
  const std::string rosMessageType("sensor_msgs/JointState");

  convertFromBusVariablePrimitiveArray(msgPtr->effort, busPtr->Effort, busPtr->Effort_SL_Info);
  convertFromBus(&msgPtr->header, &busPtr->Header);
  convertFromBusVariableStringArray(msgPtr->name, busPtr->Name, busPtr->Name_SL_Info);
  convertFromBusVariablePrimitiveArray(msgPtr->position, busPtr->Position, busPtr->Position_SL_Info);
  convertFromBusVariablePrimitiveArray(msgPtr->velocity, busPtr->Velocity, busPtr->Velocity_SL_Info);
}

void convertToBus(SL_Bus_sliding_controller2_sensor_msgs_JointState* busPtr, sensor_msgs::JointState const* msgPtr)
{
  const std::string rosMessageType("sensor_msgs/JointState");

  convertToBusVariablePrimitiveArray(busPtr->Effort, busPtr->Effort_SL_Info, msgPtr->effort, slros::EnabledWarning(rosMessageType, "effort"));
  convertToBus(&busPtr->Header, &msgPtr->header);
  convertToBusVariableStringArray(busPtr->Name, busPtr->Name_SL_Info, msgPtr->name, slros::EnabledWarning(rosMessageType, "name"));
  convertToBusVariablePrimitiveArray(busPtr->Position, busPtr->Position_SL_Info, msgPtr->position, slros::EnabledWarning(rosMessageType, "position"));
  convertToBusVariablePrimitiveArray(busPtr->Velocity, busPtr->Velocity_SL_Info, msgPtr->velocity, slros::EnabledWarning(rosMessageType, "velocity"));
}


// Conversions between SL_Bus_sliding_controller2_std_msgs_Bool and std_msgs::Bool

void convertFromBus(std_msgs::Bool* msgPtr, SL_Bus_sliding_controller2_std_msgs_Bool const* busPtr)
{
  const std::string rosMessageType("std_msgs/Bool");

  msgPtr->data =  busPtr->Data;
}

void convertToBus(SL_Bus_sliding_controller2_std_msgs_Bool* busPtr, std_msgs::Bool const* msgPtr)
{
  const std::string rosMessageType("std_msgs/Bool");

  busPtr->Data =  msgPtr->data;
}


// Conversions between SL_Bus_sliding_controller2_std_msgs_Float64MultiArray and std_msgs::Float64MultiArray

void convertFromBus(std_msgs::Float64MultiArray* msgPtr, SL_Bus_sliding_controller2_std_msgs_Float64MultiArray const* busPtr)
{
  const std::string rosMessageType("std_msgs/Float64MultiArray");

  convertFromBusVariablePrimitiveArray(msgPtr->data, busPtr->Data, busPtr->Data_SL_Info);
  convertFromBus(&msgPtr->layout, &busPtr->Layout);
}

void convertToBus(SL_Bus_sliding_controller2_std_msgs_Float64MultiArray* busPtr, std_msgs::Float64MultiArray const* msgPtr)
{
  const std::string rosMessageType("std_msgs/Float64MultiArray");

  convertToBusVariablePrimitiveArray(busPtr->Data, busPtr->Data_SL_Info, msgPtr->data, slros::EnabledWarning(rosMessageType, "data"));
  convertToBus(&busPtr->Layout, &msgPtr->layout);
}


// Conversions between SL_Bus_sliding_controller2_std_msgs_Header and std_msgs::Header

void convertFromBus(std_msgs::Header* msgPtr, SL_Bus_sliding_controller2_std_msgs_Header const* busPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertFromBusVariablePrimitiveArray(msgPtr->frame_id, busPtr->FrameId, busPtr->FrameId_SL_Info);
  msgPtr->seq =  busPtr->Seq;
  convertFromBus(&msgPtr->stamp, &busPtr->Stamp);
}

void convertToBus(SL_Bus_sliding_controller2_std_msgs_Header* busPtr, std_msgs::Header const* msgPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertToBusVariablePrimitiveArray(busPtr->FrameId, busPtr->FrameId_SL_Info, msgPtr->frame_id, slros::EnabledWarning(rosMessageType, "frame_id"));
  busPtr->Seq =  msgPtr->seq;
  convertToBus(&busPtr->Stamp, &msgPtr->stamp);
}


// Conversions between SL_Bus_sliding_controller2_std_msgs_MultiArrayDimension and std_msgs::MultiArrayDimension

void convertFromBus(std_msgs::MultiArrayDimension* msgPtr, SL_Bus_sliding_controller2_std_msgs_MultiArrayDimension const* busPtr)
{
  const std::string rosMessageType("std_msgs/MultiArrayDimension");

  convertFromBusVariablePrimitiveArray(msgPtr->label, busPtr->Label, busPtr->Label_SL_Info);
  msgPtr->size =  busPtr->Size;
  msgPtr->stride =  busPtr->Stride;
}

void convertToBus(SL_Bus_sliding_controller2_std_msgs_MultiArrayDimension* busPtr, std_msgs::MultiArrayDimension const* msgPtr)
{
  const std::string rosMessageType("std_msgs/MultiArrayDimension");

  convertToBusVariablePrimitiveArray(busPtr->Label, busPtr->Label_SL_Info, msgPtr->label, slros::EnabledWarning(rosMessageType, "label"));
  busPtr->Size =  msgPtr->size;
  busPtr->Stride =  msgPtr->stride;
}


// Conversions between SL_Bus_sliding_controller2_std_msgs_MultiArrayLayout and std_msgs::MultiArrayLayout

void convertFromBus(std_msgs::MultiArrayLayout* msgPtr, SL_Bus_sliding_controller2_std_msgs_MultiArrayLayout const* busPtr)
{
  const std::string rosMessageType("std_msgs/MultiArrayLayout");

  msgPtr->data_offset =  busPtr->DataOffset;
  convertFromBusVariableNestedArray(msgPtr->dim, busPtr->Dim, busPtr->Dim_SL_Info);
}

void convertToBus(SL_Bus_sliding_controller2_std_msgs_MultiArrayLayout* busPtr, std_msgs::MultiArrayLayout const* msgPtr)
{
  const std::string rosMessageType("std_msgs/MultiArrayLayout");

  busPtr->DataOffset =  msgPtr->data_offset;
  convertToBusVariableNestedArray(busPtr->Dim, busPtr->Dim_SL_Info, msgPtr->dim, slros::EnabledWarning(rosMessageType, "dim"));
}


// Conversions between SL_Bus_sliding_controller2_std_srvs_SetBoolRequest and std_srvs::SetBoolRequest

void convertFromBus(std_srvs::SetBoolRequest* msgPtr, SL_Bus_sliding_controller2_std_srvs_SetBoolRequest const* busPtr)
{
  const std::string rosMessageType("std_srvs/SetBoolRequest");

  msgPtr->data =  busPtr->Data;
}

void convertToBus(SL_Bus_sliding_controller2_std_srvs_SetBoolRequest* busPtr, std_srvs::SetBoolRequest const* msgPtr)
{
  const std::string rosMessageType("std_srvs/SetBoolRequest");

  busPtr->Data =  msgPtr->data;
}


// Conversions between SL_Bus_sliding_controller2_std_srvs_SetBoolResponse and std_srvs::SetBoolResponse

void convertFromBus(std_srvs::SetBoolResponse* msgPtr, SL_Bus_sliding_controller2_std_srvs_SetBoolResponse const* busPtr)
{
  const std::string rosMessageType("std_srvs/SetBoolResponse");

  convertFromBusVariablePrimitiveArray(msgPtr->message, busPtr->Message, busPtr->Message_SL_Info);
  msgPtr->success =  busPtr->Success;
}

void convertToBus(SL_Bus_sliding_controller2_std_srvs_SetBoolResponse* busPtr, std_srvs::SetBoolResponse const* msgPtr)
{
  const std::string rosMessageType("std_srvs/SetBoolResponse");

  convertToBusVariablePrimitiveArray(busPtr->Message, busPtr->Message_SL_Info, msgPtr->message, slros::EnabledWarning(rosMessageType, "message"));
  busPtr->Success =  msgPtr->success;
}

