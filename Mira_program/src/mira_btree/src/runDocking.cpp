#include "ros/ros.h"
#include "std_msgs/Bool.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "boolean_publisher");
    ros::NodeHandle nh;
    ros::Publisher bool_pub = nh.advertise<std_msgs::Bool>("runDocking", 10);
    ros::Rate loop_rate(10);

    ROS_INFO("Docking Node Started");
    while (ros::ok()){
        std_msgs::Bool msg;
        msg.data = true;
        bool_pub.publish(msg);
        //ROS_INFO("Published: %d", msg.data);
        ros::spinOnce();
        loop_rate.sleep();
    }
    ROS_INFO("Docking Node Ended");


    return 0;
}
