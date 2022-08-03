cmake_minimum_required(VERSION 3.22)
project(ToyRobot)

set(CMAKE_CXX_STANDARD 14)

include_directories(toy_robot_lib/src)
enable_testing()
add_subdirectory(toy_robot_lib/src)
add_subdirectory(toy_robot_lib/test)
add_subdirectory(toy_robot_ex/src)
add_subdirectory(external_lib/googletest)
