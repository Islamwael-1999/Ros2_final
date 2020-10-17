cmake_minimum_required(VERSION 3.5)
project(project_cpp)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)

add_executable(cpp_move src/motion_plan.cpp)
ament_target_dependencies(cpp_move rclcpp example_interfaces)




install(TARGETS
cpp_move
DESTINATION lib/${PROJECT_NAME}
)

ament_package()
