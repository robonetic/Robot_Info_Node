#include "robot_info/agv_robot_info_class.h"
#include "robot_info/RobotInfoMsg.h"
#include "robot_info/hydraulic_system_monitor.h"
#include <ros/ros.h>
#include <string>

using namespace std;

AGVRobotInfo::AGVRobotInfo(ros::NodeHandle *node_handle,
                           string robot_description, string serial_number,
                           string ip_address, string firmware_version,
                           int maximum_payload)
    : RobotInfo(node_handle, robot_description, serial_number, ip_address,
                firmware_version),
      hydraulic_system_monitor("45", "100", "250") {
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
  robot_info_msg.data_field_06 =
      "hydraulic_oil_temperature: " +
      hydraulic_system_monitor.get_hydraulic_oil_temperature() + "C";
  robot_info_msg.data_field_07 =
      "hydraulic_oil_tank_fill_level: " +
      hydraulic_system_monitor.get_hydraulic_oil_tank_fill_level() + "%";
  robot_info_msg.data_field_08 =
      "hydraulic_oil_pressure: " +
      hydraulic_system_monitor.get_hydraulic_oil_pressure() + " bar";

  robot_info_pub.publish(robot_info_msg);

  ROS_INFO("Published Robot Information.");
}

// GETTERS
string AGVRobotInfo::get_oil_temperature() {
  return hydraulic_system_monitor.get_hydraulic_oil_temperature();
}

string AGVRobotInfo::get_oil_tank_fill_level() {
  return hydraulic_system_monitor.get_hydraulic_oil_tank_fill_level();
}

string AGVRobotInfo::get_oil_pressure() {
  return hydraulic_system_monitor.get_hydraulic_oil_pressure();
}

tuple<string, string, string> AGVRobotInfo::get_system_monitor() {
  return hydraulic_system_monitor.system_monitor_info();
}

// SETTERS
void AGVRobotInfo::set_oil_temperature(string temp) {
  return hydraulic_system_monitor.set_hydraulic_oil_temperature(temp);
}

void AGVRobotInfo::set_oil_tank_fill_level(string tank_fill_level) {
  return hydraulic_system_monitor.set_hydraulic_oil_tank_fill_level(
      tank_fill_level);
}

void AGVRobotInfo::set_oil_pressure(string pressure) {
  return hydraulic_system_monitor.set_hydraulic_oil_pressure(pressure);
}
