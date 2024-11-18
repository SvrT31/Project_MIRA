cmake_minimum_required(VERSION 3.0.2)
project(btree_test)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

catkin_package(

)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)


add_executable(btree src/btree.cpp)
target_link_libraries(btree ${catkin_LIBRARIES})

add_executable(disarm src/disarm.cpp)
target_link_libraries(disarm ${catkin_LIBRARIES})

add_executable(rov src/rov.cpp)
target_link_libraries(rov ${catkin_LIBRARIES})

add_executable(runController src/runController.cpp)
target_link_libraries(runController ${catkin_LIBRARIES})

add_executable(runDocking src/runDocking.cpp)
target_link_libraries(runDocking ${catkin_LIBRARIES})

add_executable(runEmergencyDependency src/runEmergencyDependency.cpp)
target_link_libraries(runEmergencyDependency ${catkin_LIBRARIES})

add_executable(runImagePipeline src/runImagePipeline.cpp)
target_link_libraries(runImagePipeline ${catkin_LIBRARIES})

add_executable(runPyMavlink src/runPyMavlink.cpp)
target_link_libraries(runPyMavlink ${catkin_LIBRARIES})
