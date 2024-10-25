Only of ROS Noetic, Ubuntu 20.04, gazebo-11 configuration

# The repository contains code to make ArduSub move using LQR controller

This code is complied with the help of these git repositories -
1. https://github.com/bluerobotics/freebuoyancy_gazebo.git
2. https://github.com/freefloating-gazebo/freefloating_gazebo.git
3. https://github.com/freefloating-gazebo/freefloating_gazebo_demo.git
4. https://github.com/kdkalvik/bluerov-ros-pkg.git
5. https://github.com/ArduPilot/ardupilot.git

## To compile this code:

Before starting, put this on a terminal -
```
mkdir ardusub
cd ardusub
```

Then, git clone this repo or download and extract this repo in ardusub folder

Once you have successfully completed that, past this code on your terminal -
```
gedit ~/.bashrc
```

A text file named .bashrc will open. Add this code at the end of this text file -
```
source /usr/share/gazebo/setup.sh
source ~/ardusub/blue_ws/devel/setup.bash
export GAZEBO_MODEL_PATH=~/ardusub/ardupilot_gazebo/models
export GAZEBO_RESOURCE_PATH=~/ardusub/ardupilot_gazebo/worlds:${GAZEBO_RESOURCE_PATH}
export PATH=~/ardusub/ardupilot/Tools/autotest:$PATH
```
Save this file and exit gedit. 

 - Basic requirements:
```
sudo apt-get install ros-noetic-gazebo-ros-pkgs ros-noetic-gazebo-ros-control
sudo apt-get install git
sudo apt-get install -y libgazebo11-dev 
```
 - Install freebuoyancy plugin (https://github.com/bluerobotics/freebuoyancy_gazebo)
```
cd ~/ardusub
git clone https://github.com/bluerobotics/freebuoyancy_gazebo.git
mkdir -p freebuoyancy_gazebo/build
cd freebuoyancy_gazebo/build/
cmake ..
make
export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:~/ardusub/freebuoyancy_gazebo/build
```

- Install MAVROS
```
sudo apt-get install ros-noetic-mavros ros-noetic-mavros-extras
wget https://raw.githubusercontent.com/mavlink/mavros/master/mavros/scripts/install_geographiclib_datasets.sh
```
If the above step doesn’t work:
```
sudo gedit /etc/hosts
```
(Then at the end of this file, add the IP address.)
```
185.199.108.133 raw.githubusercontent.com
chmod +x ./install_geographiclib_datasets.sh
sudo ./install_geographiclib_datasets.sh
```

- Install the BlueROV2 simulations
```
cd ~/ardusub
mkdir blue_ws
sudo apt install gazebo11 libgazebo11-dev
pip install setuptools==64.0.2
pip install testresources
sudo apt-get install ros-noetic-gazebo-ros-pkgs ros-noetic-gazebo-ros-control
cd src/bluerov_ros_playground
source gazebo.sh
echo 'export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:~/ardusub/freebuoyancy_gazebo/build' >> gazebo.sh
echo "source ~/ardusub/catkin_ws_bluerov/src/bluerov_ros_playground/gazebo.sh" >> ~/ardusub/blue_ws_bluerov/devel/setup.bash
cd ~/ardusub/blue_ws
catkin_make
```

- Install ardusub
```
cd ~/ardusub
cd ardupilot
git submodule init
git submodule update --recursive
Tools/environment_install/install-prereqs-ubuntu.sh -y
./Tools/gittools/submodule-sync.sh
. ~/.profile
sudo usermod -a -G dialout $USER
python3 waf configure
python3 waf clean
python3 waf sub
```

- Install ardupilot plugin
```
cd ardupilot_gazebo/build
cmake ../
make
sudo make install
echo 'source /usr/share/gazebo/setup.sh' >> ~/.bashrc
echo 'export GAZEBO_MODEL_PATH=~/ardusub/ardupilot_gazebo/models' >> ~/.bashrc
echo 'export GAZEBO_RESOURCE_PATH=~/ardusub/ardupilot_gazebo/worlds:${GAZEBO_RESOURCE_PATH}' >> ~/.bashrc
source ~/.bashrc
```

- Finally install QGroundControl
```
sudo usermod -a -G dialout $USER
sudo apt-get remove modemmanager -y
sudo apt install gstreamer1.0-plugins-bad gstreamer1.0-libav gstreamer1.0-gl -y
sudo apt install libqt5gui5 -y
sudo apt install libfuse2 -y
```
Logout and login again to enable the change to user permissions.
Download [QGroundControl.AppImage](https://d176tv9ibo4jno.cloudfront.net/latest/QGroundControl.AppImage]). (Open the hyperlink)
```
cd ~/Downloads
chmod +x ./QGroundControl.AppImage
./QGroundControl.AppImage
 ```

Select the Q icon on top left
1) Select Application settings
2)  Select Comm Links
3)  Select Add
4)  Enter a name
5)  Type -> UDP
6)  Port -> 14555
7)  Select ok
8)  Close QGroundControl

## To run:
1) Open a new terminal
```
cd ~/ardusub/ardupilot/ArduSub
source ~/.bashrc
sim_vehicle.py -f gazebo-bluerov2 -I 0 -j4 -D -L RATBeach --console
```
SITL is now running

2) view the world in Gazebo
```
cd ~/ardusub/blue_ws/src/bluerov_ros_playground
source gazebo.sh
gazebo --verbose worlds/underwater.world -u
```
CLICK ON PLAY at the bottom left of the Gazebo GUI

3) use the Mavros package 
```
source ~/ardusub/blue_ws/devel/setup.bash
roslaunch bluerov_ros_playground apm.launch fcu_url:=udp://127.0.0.1:14550@
```
4) Getting the distance/error
```
roslaunch bluerov_control lqrcpp
```

Done!
The AUV must be moving to a certian target. 

The goal of this project was to move the AUV using only and only velocity command, which is being accomplished using an LQR Controller. 
If you wish to run it using pose commands, use this -
```
roslaunch bluerov_control main
```
Also, the LQR code is still in progress and we are debugging it. As such, it won't do the job that it exactly needs to do. Though it does put the LQR Controller theory properly into practice. I shall perfect the code in the coming months
