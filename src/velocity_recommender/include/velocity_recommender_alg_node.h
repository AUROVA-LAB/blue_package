// Copyright (C) 2010-2011 Institut de Robotica i Informatica Industrial, CSIC-UPC.
// Author 
// All rights reserved.
//
// This file is part of iri-ros-pkg
// iri-ros-pkg is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// 
// IMPORTANT NOTE: This code has been generated through a script from the 
// iri_ros_scripts. Please do NOT delete any comments to guarantee the correctness
// of the scripts. ROS topics can be easly add by using those scripts. Please
// refer to the IRI wiki page for more information:
// http://wikiri.upc.es/index.php/Robotics_Lab

#ifndef _velocity_recommender_alg_node_h_
#define _velocity_recommender_alg_node_h_

#include <iri_base_algorithm/iri_base_algorithm.h>
#include "velocity_recommender_alg.h"
#include "std_msgs/Float32.h"

// [publisher subscriber headers]

// [service client headers]

// [action server client headers]

/**
 * \brief IRI ROS Specific Algorithm Class
 *
 */
class VelocityRecommenderAlgNode : public algorithm_base::IriBaseAlgorithm<VelocityRecommenderAlgorithm>
{
private:
  const float OUT_OF_RANGE = 100.0;
  const float MAX_VELOCITY = 2.0;

  float time_to_reach_min_allowed_distance_;
  float safety_distance_to_stop_vehicle_;

  bool flag_new_data_;

  float hokuyo_front_obstacle_distance;
  float velodyne_front_obstacle_distance_;
  float local_map_front_obstacle_distance_;

  float min_front_obstacle_distance_;
  float forward_velocity_recommendation_;

  float velodyne_back_obstacle_distance_;
  float local_map_back_obstacle_distance_;

  float min_back_obstacle_distance_;
  float backward_velocity_recommendation_;

  // [publisher attributes]
  ros::Publisher forward_recommended_velocity_publisher_;
  std_msgs::Float32 forward_recommended_velocity_msg_;

  ros::Publisher backward_recommended_velocity_publisher_;
  std_msgs::Float32 backward_recommended_velocity_msg_;

  // [subscriber attributes]
  ros::Subscriber reactive_hokuyo_subscriber_;
  void reactive_hokuyo_callback(const std_msgs::Float32::ConstPtr& msg);

  // [service attributes]

  // [client attributes]

  // [action server attributes]

  // [action client attributes]

  pthread_mutex_t velocity_recommender_mutex_;
  void velocity_recommender_mutex_enter(void);
  void velocity_recommender_mutex_exit(void);

  /**
   * \brief config variable
   *
   * This variable has all the driver parameters defined in the cfg config file.
   * Is updated everytime function config_update() is called.
   */
  Config config_;
public:
  /**
   * \brief Constructor
   *
   * This constructor initializes specific class attributes and all ROS
   * communications variables to enable message exchange.
   */
  VelocityRecommenderAlgNode(void);

  /**
   * \brief Destructor
   *
   * This destructor frees all necessary dynamic memory allocated within this
   * this class.
   */
  ~VelocityRecommenderAlgNode(void);

protected:
  /**
   * \brief main node thread
   *
   * This is the main thread node function. Code written here will be executed
   * in every node loop while the algorithm is on running state. Loop frequency
   * can be tuned by modifying loop_rate attribute.
   *
   * Here data related to the process loop or to ROS topics (mainly data structs
   * related to the MSG and SRV files) must be updated. ROS publisher objects
   * must publish their data in this process. ROS client servers may also
   * request data to the corresponding server topics.
   */
  void mainNodeThread(void);

  /**
   * \brief dynamic reconfigure server callback
   *
   * This method is called whenever a new configuration is received through
   * the dynamic reconfigure. The derivated generic algorithm class must
   * implement it.
   *
   * \param config an object with new configuration from all algorithm
   *               parameters defined in the config file.
   * \param level  integer referring the level in which the configuration
   *               has been changed.
   */
  void node_config_update(Config &config, uint32_t level);

  /**
   * \brief node add diagnostics
   *
   * In this abstract function additional ROS diagnostics applied to the
   * specific algorithms may be added.
   */
  void addNodeDiagnostics(void);

  // [diagnostic functions]

  // [test functions]
};

#endif
