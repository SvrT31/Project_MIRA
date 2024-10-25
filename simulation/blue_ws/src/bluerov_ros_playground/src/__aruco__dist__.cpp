#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Quaternion.h>

float arucoX = 5;
float arucoY = 9;
float arucoZ = -5;

geometry_msgs::PoseStamped currentPose;

void poseCallback(const geometry_msgs::PoseStamped::ConstPtr &msg) {
    currentPose = *msg;
}

void pub(ros::Publisher arucoDistPublisher) {
    while (ros::ok()) {
        geometry_msgs::Quaternion q;
        q.x = arucoX - currentPose.pose.position.x;
        q.y = arucoY - currentPose.pose.position.y; 
        q.z = arucoZ - currentPose.pose.position.z; 
        arucoDistPublisher.publish(q);
        ros::spinOnce();
    }
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "aruco_pub");
    ros::NodeHandle nh;
    ros::Publisher arucoDistPublisher = nh.advertise<geometry_msgs::Quaternion>("/bluerov/aruco", 1);
    ros::Subscriber currentPoseSub = nh.subscribe("/mavros/local_position/pose", 1, poseCallback);
    pub(arucoDistPublisher);
}
