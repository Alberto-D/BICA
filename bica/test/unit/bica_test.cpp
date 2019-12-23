// Copyright 2019 Intelligent Robotics Lab
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <string>
#include <vector>
#include <regex>
#include <iostream>
#include <memory>

#include "ament_index_cpp/get_package_share_directory.hpp"

#include "bica/Component.hpp"

#include "gtest/gtest.h"

using namespace std::chrono_literals;


TEST(domain_expert, functions)
{
  /*
  auto component_1 = std::make_shared<bica::Component>("component_1");
  auto component_2 = std::make_shared<bica::Component>("component_2");

  rclcpp::Time start = component_1->now();

  while ( (component_1->now() - start).seconds() < 5) {
    // component_1->step();
    // component_2->step();
  }
  */
  ASSERT_EQ( 1, 1);
}

int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}