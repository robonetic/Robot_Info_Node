#include "robot_info/robot_info_class.h"
#include "robot_info/RobotInfoMsg.h"

RobotInfo::RobotInfo(ros::NodeHandle *node_handle, string robot_description,
                     string serial_number, string ip_address,
                     string firmware_version) {
  this->nh = *node_handle;
  this->robot_description = robot_description;
  this->serial_number = serial_number;
  this->ip_address = ip_address;
  this->firmware_version = firmware_version;
  this->robot_info_pub =
      nh.advertise<robot_info::RobotInfoMsg>("robot_info_topic", 1000);
}

void RobotInfo::publish_data() {
  robot_info::RobotInfoMsg robot_info_msg;

  robot_info_msg.data_field_01 = "robot_description: " + robot_description;
  robot_info_msg.data_field_02 = "serial_number: " + serial_number;
  robot_info_msg.data_field_03 = "ip_address: " + ip_address;
  robot_info_msg.data_field_04 = "firmware_version: " + firmware_version;

  robot_info_pub.publish(robot_info_msg);

  ROS_INFO("Published Robot Information.");
}

RobotInfo::~RobotInfo() {}