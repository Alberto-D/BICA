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

#include "Move.h"

Move::Move(ros::NodeHandle& nh)
: nh_(nh),
  Action("move")
{
  ROS_INFO("[move] Ccreating action");
}

void
Move::activateCode()
{
  ROS_INFO("[move] Activating action");
  start_ = ros::Time::now();
}

void
Move::deActivateCode()
{
  ROS_INFO("[move] Deactivating action");
}

void
Move::step()
{
  if ((ros::Time::now() - start_).toSec() > 5.0)
    setSuccess();
  ROS_INFO("[move] Step");
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "rosplan_interface_move");
  ros::NodeHandle nh("~");

  Move move(nh);

  ros::Subscriber ds =
      nh.subscribe("/kcl_rosplan/action_dispatch", 1000, &KCL_rosplan::RPActionInterface::dispatchCallback,
                   dynamic_cast<KCL_rosplan::RPActionInterface*>(&move));

  move.runActionInterface();

  return 0;
}
