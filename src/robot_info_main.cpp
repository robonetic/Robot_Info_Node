#include "ros/init.h"
#include "ros/node_handle.h"
#include "ros/rate.h"
#include <iostream>
#include <robot_info/robot_info_class.h>
#include <unistd.h>

using namespace std;

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_info_node");
  ros::NodeHandle nh;

  RobotInfo robot_info_node{&nh, "Mir100", "567A359", "169.254.5.180", "3.5.8"};

  while (ros::ok()) {
    robot_info_node.publish_data();
    sleep(1);
  }

  ros::spin();
}