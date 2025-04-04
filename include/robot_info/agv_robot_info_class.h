#pragma once

#include "robot_info/robot_info_class.h"
#include <ros/ros.h>

using namespace std;

class AGVRobotInfo : public RobotInfo {
public:
  AGVRobotInfo(ros::NodeHandle *node_handle, string robot_description,
               string serial_number, string ip_address, string firmware_version,
               int maximum_payload);

  void publish_data() override;

protected:
  int maximum_payload;
};