#include <ros/ros.h>
#include <bluerov_control/bluerov_subs.hpp>
#include <geometry_msgs/TwistStamped.h>
#include <geometry_msgs/PoseStamped.h>
#include <Eigen/Dense>

// Declare wavepoints globally
std::vector<std::vector<float>> wavepoints = {
    {1, 0, 0},
    {3, 0, 0},
    {5, 0, 0},
    {5, 0, -1},
    {5, 0, -3},
    {5, 0, -5},
    {5, 3, -5},
    {5, 6, -5},
    {5, 9, -5},
};

geometry_msgs::PoseStamped current_pose;
float tol = 0.1;

void poseCallback(const geometry_msgs::PoseStamped::ConstPtr& msg) {
    current_pose = *msg; // Store the received pose
}

Eigen::Matrix3d riccati_eqn(const Eigen::Matrix3d& A, const Eigen::Matrix3d& B, const Eigen::Matrix3d& Q, const Eigen::Matrix3d& R, Eigen::Matrix3d& P) {
    Eigen::Matrix3d S = Q;
    Eigen::Matrix3d M = A;
    for (int i = 0; i < 100; i++) { // Iterate for convergence
        S = Q + A.transpose() * S * A - A.transpose() * S * B * (R + B.transpose() * S * B).inverse() * B.transpose() * S * A;
        M = A - B * (R + B.transpose() * S * B).inverse() * B.transpose() * S * A;
    }
    P = S;
    
    return P;
}

Eigen::Vector3d lqr(const Eigen::Vector3d& current_position, const Eigen::Vector3d& target_position, Eigen::Vector3d& control_input) {
    Eigen::Matrix3d A = Eigen::Matrix3d::Identity(); // Assuming a simple vehicle dynamics mode;
    Eigen::Matrix3d B = Eigen::Matrix3d::Identity(); // Assuming direct yet simple control over position
    Eigen::Matrix3d Q = Eigen::Matrix3d::Identity(); // Penalizing distance error
    Eigen::Matrix3d R = 0.001 * Eigen::Matrix3d::Identity(); // Small effort penalty for simulation

    Eigen::Matrix3d P;
    riccati_eqn(A, B, Q, R, P);

    Eigen::Vector3d error = target_position - current_position;
    control_input = -P * B.transpose() * error;

    return control_input;
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "subscriber");
    ros::NodeHandle nh;
    ros::Rate rate(1);
    ros::Publisher twistPub = nh.advertise<geometry_msgs::TwistStamped>("/mavros/setpoint_velocity/cmd_vel", 1);
    ros::Subscriber pose_sub = nh.subscribe("/mavros/local_position/pose", 10, poseCallback);
    Subscriber sub(nh);        
    
    sub.connect();

    while(ros::ok()){
        // move to guided mode & arm throttle
        sub.guided_armed();

        // Get current position from ROS
        Eigen::Vector3d current_position(current_pose.pose.position.x, current_pose.pose.position.y, current_pose.pose.position.z);

        // Determine target position from wavepoints
        Eigen::Vector3d target_position;
        target_position << wavepoints.front()[0], wavepoints.front()[1], wavepoints.front()[2];

        if ((current_position - target_position).norm() < tol) {
            wavepoints.erase(wavepoints.begin());
            if (wavepoints.empty()) {
                break; // All wavepoints reached
            }
            target_position << wavepoints.front()[0], wavepoints.front()[1], wavepoints.front()[2];
        }

        // Calculate control input using LQR
        Eigen::Vector3d control_input;
        lqr(current_position, target_position, control_input);

        // Publish control input
        geometry_msgs::TwistStamped twistMsg;
        twistMsg.twist.linear.x = control_input[0];
        twistMsg.twist.linear.y = control_input[1];
        twistMsg.twist.linear.z = control_input[2];
        twistPub.publish(twistMsg);

        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}
