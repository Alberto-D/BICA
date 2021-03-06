/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2019, Intelligent Robotics Core S.L.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Intelligent Robotics Core nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 **********************************************************************/

/* Author: Francisco Martín Rico - fmrico@gmail.com */

#include "ros/ros.h"

#include <bica_graph/graph_client.h>

int main(int argc, char* argv[])
{
  ros::init(argc, argv, "graph_client_A");
  ros::NodeHandle n;

  bica_graph::GraphClient client;

  ros::Rate loop_rate(1);
  int count = 0;

  /*client.add_node("leia", "robot");

  while (ros::ok() && count < 4)
  {
    client.print();

    count++;
    ros::spinOnce();
    loop_rate.sleep();
  }

  client.remove_node("leia");

  count = 0;
  while (ros::ok() && count < 4)
  {
    client.print();

    count++;
    ros::spinOnce();
    loop_rate.sleep();
  }*/

  client.add_node("leia", "robot");
  client.add_node("bedroom", "room");
  client.add_edge("leia", std::string("is"), "bedroom");

  count = 0;
  while (ros::ok() && count < 4)
  {
    client.print();

    count++;
    ros::spinOnce();
    loop_rate.sleep();
  }

  tf2::Transform tf_r2l(tf2::Quaternion(0, 0, 0, 1), tf2::Vector3(3, 0, 0));
  client.add_edge("bedroom", tf_r2l, "leia");
  client.add_edge("bedroom", 0.95, "leia");

  count = 0;
  while (ros::ok() && count < 40)
  {
    client.print();

    count++;
    ros::spinOnce();
    loop_rate.sleep();
  }


  client.remove_double_edge("bedroom", "leia");
  client.remove_tf_edge("bedroom", "leia");
  client.remove_edge("leia", "is", "bedroom");

  count = 0;
  while (ros::ok() && count < 4)
  {

    count++;
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}
