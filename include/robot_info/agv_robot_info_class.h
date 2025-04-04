#pragma once

#include "robot_info/hydraulic_system_monitor.h"
#include "robot_info/robot_info_class.h"
#include <ros/ros.h>

using namespace std;

class AGVRobotInfo : public RobotInfo {
public:
  AGVRobotInfo(ros::NodeHandle *node_handle, string robot_description,
               string serial_number, string ip_address, string firmware_version,
               int maximum_payload);

  // GETTERS
  string get_oil_temperature();
  string get_oil_tank_fill_level();
  string get_oil_pressure();
  tuple<string, string, string> get_system_monitor();

  // SETTERS
  void publish_data() override;
  void set_oil_temperature(string temp);
  void set_oil_tank_fill_level(string tank_fill_level);
  void set_oil_pressure(string pressure);

protected:
  HydraulicSystemMonitor hydraulic_system_monitor;
  int maximum_payload;
};