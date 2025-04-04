#include "robot_info/agv_robot_info_class.h"
#include <iostream>
#include <ros/ros.h>
#include <unistd.h>

using namespace std;

int main(int argc, char **argv) {
  ros::init(argc, argv, "agv_robot_info_node");
  ros::NodeHandle nh;

  AGVRobotInfo agv_robot_info_node{
      &nh, "Mir100", "567A359", "169.254.5.180", "3.5.8", 100};

  while (ros::ok()) {
    agv_robot_info_node.publish_data();
    sleep(1);
  }

  ros::spin();
}