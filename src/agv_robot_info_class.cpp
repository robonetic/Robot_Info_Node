#include "robot_info/agv_robot_info_class.h"
#include "robot_info/RobotInfoMsg.h"
#include <ros/ros.h>
#include <string>

using namespace std;

AGVRobotInfo::AGVRobotInfo(ros::NodeHandle *node_handle,
                           string robot_description, string serial_number,
                           string ip_address, string firmware_version,
                           int maximum_payload)
    : RobotInfo(node_handle, robot_description, serial_number, ip_address,
                firmware_version) {
  this->maximum_payload = maximum_payload;
}

void AGVRobotInfo::publish_data() {
  robot_info::RobotInfoMsg robot_info_msg;

  robot_info_msg.data_field_01 = "robot_description: " + robot_description;
  robot_info_msg.data_field_02 = "serial_number: " + serial_number;
  robot_info_msg.data_field_03 = "ip_address: " + ip_address;
  robot_info_msg.data_field_04 = "firmware_version: " + firmware_version;
  robot_info_msg.data_field_05 =
      "maximum_payload: " + to_string(maximum_payload) + " Kg";

  robot_info_pub.publish(robot_info_msg);

  ROS_INFO("Published Robot Information.");
}
