#include <bluerov_control/bluerov_subs.hpp>
#include <ros/ros.h>
#include <geometry_msgs/TwistStamped.h>

void go() {
    ros::NodeHandle nh;
    ros::Rate rate(1);
    ros::Publisher twistPub = nh.advertise<geometry_msgs::TwistStamped>("/mavros/setpoint_velocity/cmd_vel", 1);

    Subscriber sub(nh);        
    
    // step 1 - connect
    sub.connect();
    
    while(ros::ok()){
        
        // step 2 - move to guided mode & arm throttle
        sub.guided_armed();

        geometry_msgs::TwistStamped twistMsg;
        twistMsg.twist.linear.x = 0.0;  
        twistMsg.twist.linear.y = 0.0;  
        twistMsg.twist.linear.z = 0.0;  

        twistPub.publish(twistMsg);
        ros::spinOnce();
        rate.sleep();
    }
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "subscriber");
    go();
}
