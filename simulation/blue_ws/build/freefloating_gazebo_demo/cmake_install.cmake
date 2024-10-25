# Install script for directory: /home/svrt_31/ardusub/blue_ws/src/freefloating_gazebo_demo

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/svrt_31/ardusub/blue_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/svrt_31/ardusub/blue_ws/build/freefloating_gazebo_demo/catkin_generated/installspace/freefloating_gazebo_demo.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/freefloating_gazebo_demo/cmake" TYPE FILE FILES
    "/home/svrt_31/ardusub/blue_ws/build/freefloating_gazebo_demo/catkin_generated/installspace/freefloating_gazebo_demoConfig.cmake"
    "/home/svrt_31/ardusub/blue_ws/build/freefloating_gazebo_demo/catkin_generated/installspace/freefloating_gazebo_demoConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/freefloating_gazebo_demo" TYPE FILE FILES "/home/svrt_31/ardusub/blue_ws/src/freefloating_gazebo_demo/package.xml")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/freefloating_gazebo_demo" TYPE DIRECTORY FILES
    "/home/svrt_31/ardusub/blue_ws/src/freefloating_gazebo_demo/launch"
    "/home/svrt_31/ardusub/blue_ws/src/freefloating_gazebo_demo/objects"
    "/home/svrt_31/ardusub/blue_ws/src/freefloating_gazebo_demo/scenes"
    "/home/svrt_31/ardusub/blue_ws/src/freefloating_gazebo_demo/scripts"
    "/home/svrt_31/ardusub/blue_ws/src/freefloating_gazebo_demo/terrain"
    "/home/svrt_31/ardusub/blue_ws/src/freefloating_gazebo_demo/urdf"
    )
endif()

