execute_process(COMMAND "/home/svrt_31/ardusub/blue_ws/build/bluerov_ros_playground/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/svrt_31/ardusub/blue_ws/build/bluerov_ros_playground/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
