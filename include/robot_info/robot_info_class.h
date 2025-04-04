#pragma once

#include "ros/node_handle.h"
#include "ros/publisher.h"
#include <ros/ros.h>

using namespace std;

class RobotInfo {
public:
  RobotInfo(ros::NodeHandle *node_handle, string robot_description,
            string serial_number, string ip_address, string firmware_version);

  virtual ~RobotInfo();
  virtual void publish_data();

protected:
  string robot_description;
  string serial_number;
  string ip_address;
  string firmware_version;
  ros::Publisher robot_info_pub;

private:
  ros::NodeHandle nh;
};