cmake_minimum_required(VERSION 3.0.2)
project(bluerov_control)

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  gazebo_msgs
  image_transport
  roscpp
  rospy
  sensor_msgs
  std_msgs
  mavros_msgs
  Eigen3 REQUIRED  # Add Eigen as a required component
)

catkin_package(
 INCLUDE_DIRS include
 LIBRARIES bluerov_control
 CATKIN_DEPENDS cv_bridge gazebo_msgs image_transport roscpp rospy sensor_msgs std_msgs
#  DEPENDS system_lib
)

include_directories(
include
  ${catkin_INCLUDE_DIRS}
  ${EIGEN3_INCLUDE_DIRS}
)

add_executable(subs src/main.cpp)
target_link_libraries(subs ${catkin_LIBRARIES})

add_executable(straight src/straight.cpp)
target_link_libraries(straight ${catkin_LIBRARIES} ${EIGEN3_LIBRARIES})

add_executable(lqrcpp src/lqrcpp.cpp)
target_link_libraries(lqrcpp ${catkin_LIBRARIES} ${EIGEN3_LIBRARIES})