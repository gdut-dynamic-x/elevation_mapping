/*
 * starleth_elevation_map_node.cpp
 *
 *  Created on: Oct 3, 2013
 *      Author: Péter Fankhauser
 *   Institute: ETH Zurich, Autonomous Systems Lab
 */

#include <ros/ros.h>
#include "ElevationMapping.hpp"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "starleth_elevation_mapping");

  // Logger
  log4cxx::LoggerPtr logger = log4cxx::Logger::getLogger(ROSCONSOLE_DEFAULT_NAME);
  logger->setLevel(ros::console::g_level_lookup[ros::console::levels::Info]);

  ros::NodeHandle nodeHandle("~");

  starleth_elevation_mapping::ElevationMapping elevationMap(nodeHandle);

  // Spin
  ros::AsyncSpinner spinner(1); // Use n threads, TODO why are there 2 threads?
  spinner.start();
  ros::waitForShutdown();
  return 0;
}
