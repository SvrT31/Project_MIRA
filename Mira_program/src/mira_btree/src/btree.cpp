// #include <iostream>
// #include <chrono>
// #include <cstdlib>
// #include <vector>
// #include <std_msgs/Bool.h>
// #include "ros/ros.h"
// #include "std_msgs/String.h"
// #include <unistd.h>
// #include <sys/wait.h>
// #include <csignal>

// bool aruco_detected = false;
// bool emergency = false;

// // Define behavior tree node types
// class BehaviorTreeNode {
// public:
//     virtual std::string tick() = 0;
// };

// class ControlNode : public BehaviorTreeNode {
// protected:
//     std::vector<BehaviorTreeNode*> children;

// public:
//     ControlNode(const std::vector<BehaviorTreeNode*>& children) : children(children) {}

//     std::string tick() override {
//         for (auto child : children) {
//             std::string result = child->tick();
//             if (result != "SUCCESS") {
//                 return result;
//             }
//         }
//         return "SUCCESS";
//     }
// };

// class CompositeNode : public BehaviorTreeNode {
// protected:
//     BehaviorTreeNode* child;

// public:
//     CompositeNode(BehaviorTreeNode* child) : child(child) {}

//     std::string tick() override {
//         return child->tick();
//     }
// };

// // class ActionNode : public BehaviorTreeNode {
// // protected:
// //     std::string launchFile; // Store launch file path

// // public:
// //     ActionNode(const std::string& launchFile) : launchFile(launchFile) {}

// //     std::string tick() override {
// //         // Fork to create a child process for the launch command
// //         pid_t pid = fork();
// //         if (pid == -1) {
// //             std::cerr << "Failed to fork process for launch command" << std::endl;
// //             return "FAILURE";
// //         } else if (pid == 0) {
// //             // Child process for launch command
// //             execlp("roslaunch", "roslaunch", launchFile.c_str(), nullptr);
// //             std::cerr << "Failed to execute launch command" << std::endl;
// //             return "FAILURE";
// //         }

// //         return "SUCCESS";
// //     }
// // };

// // class ActionNode : public BehaviorTreeNode {
// // protected:
// //     std::string launchFile; // Store launch file path
// //     pid_t pid; // Process ID of the launched roslaunch process

// // public:
// //     ActionNode(const std::string& launchFile) : launchFile(launchFile), pid(-1) {}

// //     std::string tick() override {
// //         // If the process has not been launched yet
// //         if (pid == -1) {
// //             // Fork to create a child process for the launch command
// //             pid = fork();
// //             if (pid == -1) {
// //                 std::cerr << "Failed to fork process for launch command" << std::endl;
// //                 return "FAILURE";
// //             } else if (pid == 0) {
// //                 // Child process for launch command
// //                 execlp("roslaunch", "roslaunch", launchFile.c_str(), nullptr);
// //                 std::cerr << "Failed to execute launch command" << std::endl;
// //                 return "FAILURE";
// //             }
// //         }

// //         // Check for user input to terminate the roslaunch process
// //         int value;
// //         std::cout << "Enter value: ";
// //         std::cin >> value;

// //         if (value != -1) {
// //             // Terminate the roslaunch process if user input is not -1
// //             if (pid != -1) {
// //                 std::string process_name = launchFile.substr(launchFile.find_last_of('/') + 1);
// //                 std::string signal_str = "SIGTERM"; // Default signal is SIGTERM

// //                 // Determine the signal based on user input
// //                 if (value == 1) {
// //                     signal_str = "SIGINT"; // Terminate rov
// //                 } else if (value == 2) {
// //                     signal_str = "SIGINT"; // Terminate runDocking
// //                 } else if (value == 3) {
// //                     signal_str = "SIGINT"; // Terminate runController
// //                 } else if (value == 4) {
// //                     signal_str = "SIGINT"; // Terminate disarm
// //                 } else if (value == 0) {
// //                     signal_str = "SIGINT"; // Terminate runEmergencyDependency
// //                 }

// //                 std::cout << "Terminating process '" << process_name << "' with signal '" << signal_str << "'" << std::endl;
// //                 kill(pid, signal_str == "SIGINT" ? SIGINT : SIGTERM); // Send the appropriate signal to terminate the process
// //                 int status;
// //                 waitpid(pid, &status, 0); // Wait for the process to terminate
// //                 pid = -1; // Reset the process ID
// //             }
// //         } else {
// //             // Terminate the entire program if user input is -1
// //             exit(0);
// //         }

// //         return "SUCCESS";
// //     }
// // };

// class ActionNode : public BehaviorTreeNode {
// protected:
//     std::string launchFile; // Store launch file path
//     pid_t pid; // Process ID of the launched roslaunch process

// public:
//     ActionNode(const std::string& launchFile) : launchFile(launchFile), pid(-1) {}

//     std::string tick() override {
//         // If the process has not been launched yet
//         if (pid == -1) {
//             // Fork to create a child process for the launch command
//             pid = fork();
//             if (pid == -1) {
//                 std::cerr << "Failed to fork process for launch command" << std::endl;
//                 return "FAILURE";
//             } else if (pid == 0) {
//                 // Child process for launch command
//                 execlp("roslaunch", "roslaunch", launchFile.c_str(), nullptr);
//                 std::cerr << "Failed to execute launch command" << std::endl;
//                 return "FAILURE";
//             }
//         }

//         // Check for user input to terminate the roslaunch process
//         int value;
//         std::cout << "Enter value: ";
//         std::cin >> value;

//         if (value != -1) {
//             // Terminate the roslaunch process if user input is not -1
//             if (pid != -1) {
//                 std::string process_name = launchFile.substr(launchFile.find_last_of('/') + 1);
//                 std::string signal_str = "SIGTERM"; // Default signal is SIGTERM

//                 // Determine the signal based on user input
//                 if (value == 1) {
//                     signal_str = "SIGINT"; // Terminate rov
//                 } else if (value == 2) {
//                     signal_str = "SIGINT"; // Terminate runDocking
//                 } else if (value == 3) {
//                     signal_str = "SIGINT"; // Terminate runController
//                 } else if (value == 4) {
//                     signal_str = "SIGINT"; // Terminate disarm
//                 } else if (value == 0) {
//                     signal_str = "SIGINT"; // Terminate runEmergencyDependency
//                 }

//                 std::cout << "Terminating process '" << process_name << "' with signal '" << signal_str << "'" << std::endl;
//                 kill(pid, signal_str == "SIGINT" ? SIGINT : SIGTERM); // Send the appropriate signal to terminate the process
//                 int status;
//                 waitpid(pid, &status, 0); // Wait for the process to terminate
//                 pid = -1; // Reset the process ID
//             }
//         } else {
//             // Terminate the entire program if user input is -1
//             exit(0);
//         }

//         return "SUCCESS";
//     }
// };

// // #include <iostream>
// // #include <unistd.h>
// // #include <sys/wait.h>

// // class ActionNode : public BehaviorTreeNode {
// // protected:
// //     std::string launchFile; // Store launch file path

// // public:
// //     ActionNode(const std::string& launchFile) : launchFile(launchFile) {}

// //     std::string tick() override {
// //         pid_t pid = fork();
// //         if (pid == -1) {
// //             std::cerr << "Failed to fork process for launch command" << std::endl;
// //             return "FAILURE";
// //         } else if (pid == 0) {
// //             // Child process for launch command
// //             execlp("roslaunch", "roslaunch", launchFile.c_str(), nullptr);
// //             std::cerr << "Failed to execute launch command" << std::endl;
// //             return "FAILURE";
// //         }

// //         // Parent process
// //         int value = 9;

// //         while (value != -1) {
// //             std::cout << "Enter value: ";
// //             std::cin >> value;

// //             if (value == 1) {
// //                 kill(pid, SIGINT); // Terminate rov
// //             } else if (value == 2) {
// //                 kill(pid, SIGINT); // Terminate runDocking
// //             } else if (value == 3) {
// //                 kill(pid, SIGINT); // Terminate runController
// //             } else if (value == 4) {
// //                 kill(pid, SIGINT); // Terminate disarm
// //             } else {
// //                 break;
// //             }
// //         }

// //         exit(0);
// //     }
// // };

// class XavierSetupNode : public ControlNode {
// public:
//     XavierSetupNode(const std::vector<BehaviorTreeNode*>& children) : ControlNode(children) {}
// };

// class RunningNode : public ControlNode {
// public:
//     RunningNode(const std::vector<BehaviorTreeNode*>& children) : ControlNode(children) {}
// };

// class EmergencyNode : public ControlNode {
// public:
//     EmergencyNode(const std::vector<BehaviorTreeNode*>& children) : ControlNode(children) {}
// };

// class TreeNode : public CompositeNode {
// public:
//     TreeNode(BehaviorTreeNode* child) : CompositeNode(child) {}
// };

// class DockingNode : public CompositeNode {
// public:
//     DockingNode(BehaviorTreeNode* child) : CompositeNode(child) {}
// };


// void boolCallback1(const std_msgs::Bool::ConstPtr& msg)
// {
//     aruco_detected = msg->data;
// }

// // Callback function to handle incoming boolean messages from topic2
// void boolCallback2(const std_msgs::Bool::ConstPtr& msg)
// {
//     emergency = msg->data;
// }

// int main(int argc, char **argv) {
//     ros::init(argc, argv, "mira_behavior_tree");
//     ros::NodeHandle nh;

//     ros::Subscriber sub1 = nh.subscribe("aruco", 10, boolCallback1);
//     ros::Subscriber sub2 = nh.subscribe("emergency", 10, boolCallback2);

//     // Create behavior tree nodes with launch file paths
//     BehaviorTreeNode* runPyMavlink = new ActionNode("/home/aaron3074/testing/src/btree_test/launch/runPyMavlink.launch");
//     BehaviorTreeNode* runImagePipeline = new ActionNode("/home/aaron3074/testing/src/btree_test/launch/runImagePipeline.launch"); 
//     BehaviorTreeNode* runEmergencyDependency = new ActionNode("/home/aaron3074/testing/src/btree_test/launch/runEmergencyDependency.launch"); 
//     BehaviorTreeNode* rov = new ActionNode("/home/aaron3074/testing/src/btree_test/launch/rov.launch");
//     BehaviorTreeNode* runDocking = new ActionNode("/home/aaron3074/testing/src/btree_test/launch/runDocking.launch");
//     BehaviorTreeNode* runController = new ActionNode("/home/aaron3074/testing/src/btree_test/launch/runController.launch");
//     BehaviorTreeNode* disarm = new ActionNode("/home/aaron3074/testing/src/btree_test/launch/disarm.launch"); 

//     BehaviorTreeNode* xavierSetup = new ControlNode({new ControlNode({runPyMavlink, runImagePipeline})});
//     BehaviorTreeNode* emergency = 0;
//     while (ros::ok()){
//         if (!aruco_detected) {
//             BehaviorTreeNode* running = new ControlNode({new ControlNode({runEmergencyDependency, new CompositeNode({rov})})});
//         }
//         break;
//     }
//     while (ros::ok()){
//         if(aruco_detected){
//             BehaviorTreeNode* running = new ControlNode({new ControlNode({runEmergencyDependency, new CompositeNode({new ControlNode({runDocking, runController})})})});
//         }
//         break;
//     }
//     while (ros::ok()){
//         if (emergency){
//             BehaviorTreeNode* emergency = new ControlNode({new ControlNode({disarm, rov})});
//         }
//         break;
//     }

//     // Master Node
//     BehaviorTreeNode* masterNode = new ControlNode({xavierSetup, emergency});

//     // Execute behavior tree
//     while (ros::ok()) {
//         masterNode->tick();
//         ros::spinOnce();
//     }

//     return 0;
// }   

// #include <iostream>
// #include <thread>
// #include <map>
// #include <signal.h>
// #include <sys/wait.h>
// #include <unistd.h>
// #include "ros/ros.h"
// #include "std_msgs/Bool.h"

// // Behavior Tree Node Types
// class BehaviorTreeNode {
// public:
//     virtual ~BehaviorTreeNode() {}
//     virtual void execute() = 0;
//     virtual pid_t getPID() const { return -1; }
//     virtual void terminate() {}
// };

// class ActionNode : public BehaviorTreeNode {
// private:
//     std::string launchFile;
//     pid_t pid;

// public:
//     ActionNode(const std::string& file) : launchFile(file), pid(-1) {}

//     void execute() override {
//         if (pid == -1) {
//             pid = fork();
//             if (pid == 0) {
//                 execlp("roslaunch", "roslaunch", launchFile.c_str(), nullptr);
//                 _exit(1);  // If exec fails, exit child immediately
//             }
//         }
//     }

//     pid_t getPID() const override {
//         return pid;
//     }

//     void terminate() override {
//         if (pid > 0) {
//             kill(pid, SIGINT);
//             waitpid(pid, nullptr, 0);
//             pid = -1;
//         }
//     }
// };

// class ControlNode : public BehaviorTreeNode {
// protected:
//     std::vector<BehaviorTreeNode*> children;

// public:
//     ControlNode(const std::vector<BehaviorTreeNode*>& children) : children(children) {}

//     void execute() override {
//         for (auto& child : children) {
//             child->execute();
//         }
//     }

//     void terminate() override {
//         for (auto& child : children) {
//             child->terminate();
//         }
//     }

//     ~ControlNode() {
//         for (auto& child : children) {
//             delete child;
//         }
//     }
// };

// // Global variables for ROS callbacks
// bool aruco_detected = false;
// bool emergency = false;

// // ROS callback functions
// void arucoCallback(const std_msgs::Bool::ConstPtr& msg) {
//     aruco_detected = msg->data;
// }

// void emergencyCallback(const std_msgs::Bool::ConstPtr& msg) {
//     emergency = msg->data;
// }

// // Main function
// int main(int argc, char **argv) {
//     ros::init(argc, argv, "behavior_tree_control");
//     ros::NodeHandle nh;

//     // ROS Subscribers
//     ros::Subscriber sub1 = nh.subscribe("aruco_topic", 10, arucoCallback);
//     ros::Subscriber sub2 = nh.subscribe("emergency_topic", 10, emergencyCallback);

//     // Create the behavior tree nodes
//     ActionNode* runPyMavlink = new ActionNode("/home/aaron3074/testing/src/btree_test/launch/runPyMavlink.launch");
//     ActionNode* runImagePipeline = new ActionNode ("/home/aaron3074/testing/src/btree_test/launch/runImagePipeline.launch");
//     ActionNode* runEmergencyDependency = new ActionNode ("/home/aaron3074/testing/src/btree_test/launch/runEmergencyDependency.launch");
//     ActionNode* rov = new ActionNode ("/home/aaron3074/testing/src/btree_test/launch/rov.launch");
//     ActionNode* runDocking = new ActionNode ("/home/aaron3074/testing/src/btree_test/launch/runDocking.launch");
//     ActionNode* runController = new ActionNode ("/home/aaron3074/testing/src/btree_test/launch/runController.launch");
//     ActionNode* disarm = new ActionNode ("/home/aaron3074/testing/src/btree_test/launch/disarm.launch"); 

//     ControlNode* masterControl = new ControlNode({runPyMavlink, runImagePipeline, runEmergencyDependency, rov, runDocking, runController, disarm});

//     // Execution in a separate thread
//     std::thread execution_thread([&]() {
//         while (ros::ok()) {
//             if (emergency) {
//                 disarm->execute();
//             } else if (aruco_detected) {
//                 runDocking->execute();
//                 runController->execute();
//             } else {
//                 runPyMavlink->execute();
//                 runImagePipeline->execute();
//                 runEmergencyDependency->execute();
//                 rov->execute();
//             }
//         }
//     });

//     // Input handling thread
//     std::thread input_thread([&]() {
//         int input = 0;
//         while (ros::ok()) {
//             std::cin >> input;
//             switch (input) {
//                 case 1: rov->terminate(); break;
//                 case 2: runDocking->terminate(); break;
//                 case 3: runController->terminate(); break;
//                 case 4: disarm->terminate(); break;
//                 case 0: runEmergencyDependency->terminate(); break;
//                 case -1: // Terminate all and exit
//                     masterControl->terminate();
//                     ros::shutdown();
//                     break;
//                 default: break;
//             }
//         }
//     });

//     // Spin until ROS is shutdown
//     while (ros::ok()) {
//         ros::spinOnce();
//     }

//     // Cleanup
//     execution_thread.join();
//     input_thread.join();
//     delete masterControl;

//     return 0;
// }

// #include <iostream>
// #include <thread>
// #include <map>
// #include <signal.h>
// #include <sys/wait.h>
// #include <unistd.h>
// #include "ros/ros.h"
// #include "std_msgs/Bool.h"

// // Behavior Tree Node Types
// class BehaviorTreeNode {
// public:
//     virtual ~BehaviorTreeNode() {}
//     virtual void execute() = 0;
//     virtual void terminate() = 0;
//     virtual pid_t getPID() const { return -1; }
// };

// class ActionNode : public BehaviorTreeNode {
// private:
//     std::string launchFile;
//     pid_t pid;

// public:
//     ActionNode(const std::string& file) : launchFile(file), pid(-1) {}

//     void execute() override {
//         if (pid == -1) {
//             pid = fork();
//             if (pid == 0) {
//                 execlp("roslaunch", "roslaunch", launchFile.c_str(), nullptr);
//                 _exit(1);  // If exec fails, exit child immediately
//             }
//         }
//     }

//     void terminate() override {
//         if (pid > 0) {
//             std::cout << "Terminating PID: " << pid << std::endl;
//             kill(pid, SIGINT);
//             waitpid(pid, nullptr, 0);
//             pid = -1;
//         }
//     }

//     pid_t getPID() const override {
//         return pid;
//     }
// };

// // Global variables for ROS callbacks
// bool aruco_detected = false;
// bool emergency = false;

// // ROS callback functions
// void arucoCallback(const std_msgs::Bool::ConstPtr& msg) {
//     aruco_detected = msg->data;
// }

// void emergencyCallback(const std_msgs::Bool::ConstPtr& msg) {
//     emergency = msg->data;
// }

// // Main function
// int main(int argc, char **argv) {
//     // Initialize ROS
//     ros::init(argc, argv, "behavior_tree_control");
//     ros::NodeHandle nh;

//     // ROS Subscribers
//     ros::Subscriber sub1 = nh.subscribe("aruco_topic", 10, arucoCallback);
//     ros::Subscriber sub2 = nh.subscribe("emergency_topic", 10, emergencyCallback);

//     // Create the behavior tree nodes
//     ActionNode* runPyMavlink = new ActionNode("/home/aaron3074/testing/src/btree_test/launch/runPyMavlink.launch");
//     ActionNode* runImagePipeline = new ActionNode("/home/aaron3074/testing/src/btree_test/launch/runImagePipeline.launch");
//     ActionNode* runEmergencyDependency = new ActionNode("/home/aaron3074/testing/src/btree_test/launch/runEmergencyDependency.launch");
//     ActionNode* rov = new ActionNode("/home/aaron3074/testing/src/btree_test/launch/rov.launch");
//     ActionNode* runDocking = new ActionNode("/home/aaron3074/testing/src/btree_test/launch/runDocking.launch");
//     ActionNode* runController = new ActionNode("/home/aaron3074/testing/src/btree_test/launch/runController.launch");
//     ActionNode* disarm = new ActionNode("/home/aaron3074/testing/src/btree_test/launch/disarm.launch");

//     std::map<std::string, BehaviorTreeNode*> launchNodeMap;

//     // Store launch nodes in a map
//     launchNodeMap["runPyMavlink"] = runPyMavlink;
//     launchNodeMap["runImagePipeline"] = runImagePipeline;
//     launchNodeMap["runEmergencyDependency"] = runEmergencyDependency;
//     launchNodeMap["rov"] = rov;
//     launchNodeMap["runDocking"] = runDocking;
//     launchNodeMap["runController"] = runController;
//     launchNodeMap["disarm"] = disarm;

//     // Execution in a separate thread
//     std::thread execution_thread([&]() {
//         while (ros::ok()) {
//             if (emergency) {
//                 disarm->execute();
//             } else if (aruco_detected) {
//                 runDocking->execute();
//                 runController->execute();
//             } else {
//                 runPyMavlink->execute();
//                 runImagePipeline->execute();
//                 runEmergencyDependency->execute();
//                 rov->execute();
//             }
//             // Sleep for a while to prevent high CPU usage
//             std::this_thread::sleep_for(std::chrono::milliseconds(100));
//         }
//     });

//     // Input handling thread
//     std::thread input_thread([&]() {
//         int input = 0;
//         while (ros::ok()) {
//             std::cout << "Enter command (1-4 to terminate specific node, 0 to terminate runEmergencyDependency, -1 to terminate all and exit): ";
//             std::cin >> input;
//             switch (input) {
//                 case 1: {
//                     if (rov->getPID() != -1) {
//                         std::cout << "Terminating rov node with PID: " << rov->getPID() << std::endl;
//                         rov->terminate();
//                     }
//                     break;
//                 }
//                 case 2: {
//                     if (runDocking->getPID() != -1) {
//                         std::cout << "Terminating runDocking node with PID: " << runDocking->getPID() << std::endl;
//                         runDocking->terminate();
//                     }
//                     break;
//                 }
//                 case 3: {
//                     if (runController->getPID() != -1) {
//                         std::cout << "Terminating runController node with PID: " << runController->getPID() << std::endl;
//                         runController->terminate();
//                     }
//                     break;
//                 }
//                 case 4: {
//                     if (disarm->getPID() != -1) {
//                         std::cout << "Terminating disarm node with PID: " << disarm->getPID() << std::endl;
//                         disarm->terminate();
//                     }
//                     break;
//                 }
//                 case 0: {
//                     if (runEmergencyDependency->getPID() != -1) {
//                         std::cout << "Terminating runEmergencyDependency node with PID: " << runEmergencyDependency->getPID() << std::endl;
//                         runEmergencyDependency->terminate();
//                     }
//                     break;
//                 }
//                 case -1: { // Terminate all and exit
//                     for (auto& entry : launchNodeMap) {
//                         entry.second->terminate();
//                     }
//                     ros::shutdown();
//                     return;
//                 }
//                 default: 
//                     std::cout << "Invalid command!" << std::endl;
//                     break;
//             }
//         }
//     });

//     // Spin until ROS is shutdown
//     ros::spin();

//     // Cleanup
//     execution_thread.join();
//     input_thread.join();

//     delete runPyMavlink;
//     delete runImagePipeline;
//     delete runEmergencyDependency;
//     delete rov;
//     delete runDocking;
//     delete runController;
//     delete disarm;

//     return 0;
// }

// #include <iostream>
// #include <thread>
// #include <map>
// #include <signal.h>
// #include <sys/wait.h>
// #include <unistd.h>
// #include "ros/ros.h"
// #include "std_msgs/Bool.h"

// // Behavior Tree Node Types
// class BehaviorTreeNode {
// public:
//     virtual ~BehaviorTreeNode() {}
//     virtual void execute() = 0;
//     virtual void terminate() = 0;
//     virtual pid_t getPID() const { return -1; }
// };

// class ActionNode : public BehaviorTreeNode {
// private:
//     std::string launchFile;
//     pid_t pid;

// public:
//     ActionNode(const std::string& file) : launchFile(file), pid(-1) {}

//     void execute() override {
//         if (pid == -1) {
//             pid = fork();
//             if (pid == 0) {
//                 execlp("roslaunch", "roslaunch", launchFile.c_str(), nullptr);
//                 _exit(1);  // If exec fails, exit child immediately
//             }
//         }
//     }

//     void terminate() override {
//         if (pid > 0) {
//             std::cout << "Terminating PID: " << pid << std::endl;
//             kill(pid, SIGINT);
//             waitpid(pid, nullptr, 0);
//             pid = -1;
//         }
//     }

//     pid_t getPID() const override {
//         return pid;
//     }
// };

// // Global variables for ROS callbacks
// bool aruco_detected = false;
// bool emergency = false;

// // ROS callback functions
// void arucoCallback(const std_msgs::Bool::ConstPtr& msg) {
//     aruco_detected = msg->data;
// }

// void emergencyCallback(const std_msgs::Bool::ConstPtr& msg) {
//     emergency = msg->data;
// }

// // Global variable for child PIDs
// std::vector<pid_t> child_pids;

// // Function to kill all child processes
// void killChildren() {
//     for (pid_t pid : child_pids) {
//         kill(pid, SIGKILL);
//         std::cout << "Child process: " << pid << " killed" << std::endl;
//     }
// }

// // Signal handler function
// void handleSignal(int signal) {
//     if (signal == SIGINT) {
//         std::cout << "Exit code, killing all child processes" << std::endl;
//         killChildren();
//         std::cout << "Parent process exiting..." << std::endl;
//         exit(0);
//     }
// }

// // Main function
// int main(int argc, char **argv) {
//     // Initialize ROS
//     ros::init(argc, argv, "behavior_tree_control");
//     ros::NodeHandle nh;

//     // ROS Subscribers
//     ros::Subscriber sub1 = nh.subscribe("aruco_topic", 10, arucoCallback);
//     ros::Subscriber sub2 = nh.subscribe("emergency_topic", 10, emergencyCallback);

//     // Create the behavior tree nodes
//     //ActionNode* runPyMavlink = new ActionNode("/home/aaron3074/testing/src/btree_test/launch/runPyMavlink.launch");
//     //ActionNode* runImagePipeline = new ActionNode("/home/aaron3074/testing/src/btree_test/launch/runImagePipeline.launch");
//     ActionNode* runEmergencyDependency = new ActionNode("/home/aaron3074/testing/src/btree_test/launch/runEmergencyDependency.launch");
//     ActionNode* rov = new ActionNode("/home/aaron3074/testing/src/btree_test/launch/rov.launch");
//     ActionNode* runDocking = new ActionNode("/home/aaron3074/testing/src/btree_test/launch/runDocking.launch");
//     ActionNode* runController = new ActionNode("/home/aaron3074/testing/src/btree_test/launch/runController.launch");
//     ActionNode* disarm = new ActionNode("/home/aaron3074/testing/src/btree_test/launch/disarm.launch");

//     std::map<std::string, BehaviorTreeNode*> launchNodeMap;

//     // Store launch nodes in a map
//     //launchNodeMap["runPyMavlink"] = runPyMavlink;
//     //launchNodeMap["runImagePipeline"] = runImagePipeline;
//     launchNodeMap["runEmergencyDependency"] = runEmergencyDependency;
//     launchNodeMap["rov"] = rov;
//     launchNodeMap["runDocking"] = runDocking;
//     launchNodeMap["runController"] = runController;
//     launchNodeMap["disarm"] = disarm;

//     // Execution in a separate thread
//     std::thread execution_thread([&]() {
//         while (ros::ok()) {
//             if (emergency) {
//                 disarm->execute();
//             } else if (aruco_detected) {
//                 runDocking->execute();
//                 runController->execute();
//             } else {
//                 //runPyMavlink->execute();
//                 //runImagePipeline->execute();
//                 //runEmergencyDependency->execute();
//                 //rov->execute();
//             }
//             // Sleep for a while to prevent high CPU usage
//             std::this_thread::sleep_for(std::chrono::milliseconds(100));
//         }
//     });

//     // Input handling thread
//     std::thread input_thread([&]() {
//         int input = 0;
//         while (ros::ok()) {
//             std::cout << "Enter command (1-4 to terminate specific node, 0 to terminate runEmergencyDependency, -1 to terminate all and exit): ";
//             std::cin >> input;
//             switch (input) {
//                 case 1: {
//                     if (rov->getPID() != -1) {
//                         std::cout << "Terminating rov node with PID: " << rov->getPID() << std::endl;
//                         rov->terminate();
//                     }
//                     break;
//                 }
//                 case 2: {
//                     if (runDocking->getPID() != -1) {
//                         std::cout << "Terminating runDocking node with PID: " << runDocking->getPID() << std::endl;
//                         runDocking->terminate();
//                     }
//                     break;
//                 }
//                 case 3: {
//                     if (runController->getPID() != -1) {
//                         std::cout << "Terminating runController node with PID: " << runController->getPID() << std::endl;
//                         runController->terminate();
//                     }
//                     break;
//                 }
//                 case 4: {
//                     if (disarm->getPID() != -1) {
//                         std::cout << "Terminating disarm node with PID: " << disarm->getPID() << std::endl;
//                         disarm->terminate();
//                     }
//                     break;
//                 }
//                 case 0: {
//                     if (runEmergencyDependency->getPID() != -1) {
//                         std::cout << "Terminating runEmergencyDependency node with PID: " << runEmergencyDependency->getPID() << std::endl;
//                         runEmergencyDependency->terminate();
//                     }
//                     break;
//                 }
//                 case -1: { // Terminate all and exit
//                     for (auto& entry : launchNodeMap) {
//                         entry.second->terminate();
//                     }
//                     ros::shutdown();
//                     return;
//                 }
//                 default: 
//                     std::cout << "Invalid command!" << std::endl;
//                     break;
//             }
//         }
//     });

//     // Signal handling
//     signal(SIGINT, handleSignal);

//     // Spin until ROS is shutdown
//     ros::spin();

//     // Cleanup
//     execution_thread.join();
//     input_thread.join();

//     //delete runPyMavlink;
//     //delete runImagePipeline;
//     delete runEmergencyDependency;
//     delete rov;
//     delete runDocking;
//     delete runController;
//     delete disarm;

//     return 0;
// }

#include <iostream>
#include <thread>
#include <map>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include "ros/ros.h"
#include "std_msgs/Bool.h"

// Behavior Tree Node Types
class BehaviorTreeNode {
public:
    virtual ~BehaviorTreeNode() {}
    virtual void execute() = 0;
    virtual void terminate() = 0;
    virtual pid_t getPID() const { return -1; }
};

class ActionNode : public BehaviorTreeNode {
private:
    std::string nodeName;
    std::string launchFile;
    pid_t pid;

public:
    ActionNode(const std::string& name, const std::string& file) : nodeName(name), launchFile(file), pid(-1) {
        std::cout << "ActionNode created: " << nodeName << std::endl;
    }

    void execute() override {
        if (pid == -1) {
            pid = fork();
            if (pid == 0) {
                execlp("roslaunch", "roslaunch", launchFile.c_str(), nullptr);
                _exit(1);  // If exec fails, exit child immediately
            }
            std::cout << "PID set for " << nodeName << ": " << pid << std::endl;
        }
    }

    void terminate() override {
        if (pid > 0) {
            std::cout << "Terminating " << nodeName << " node with PID: " << pid << std::endl;
            kill(pid, SIGINT);
            waitpid(pid, nullptr, 0);
            pid = -1;
        }
    }

    pid_t getPID() const override {
        return pid;
    }
};

// Global variables for ROS callbacks
bool aruco_detected = false;
bool emergency = false;

// ROS callback functions
void arucoCallback(const std_msgs::Bool::ConstPtr& msg) {
    aruco_detected = msg->data;
}

void emergencyCallback(const std_msgs::Bool::ConstPtr& msg) {
    emergency = msg->data;
}

// Global variable for child PIDs
std::vector<pid_t> child_pids;

// Function to kill all child processes
void killChildren() {
    for (pid_t pid : child_pids) {
        kill(pid, SIGKILL);
        std::cout << "Child process: " << pid << " killed" << std::endl;
    }
}

// Signal handler function
void handleSignal(int signal) {
    if (signal == SIGINT) {
        std::cout << "Exit code, killing all child processes" << std::endl;
        killChildren();
        std::cout << "Parent process exiting..." << std::endl;
        exit(0);
    }
}

// Main function
int main(int argc, char **argv) {
    // Initialize ROS
    ros::init(argc, argv, "behavior_tree_control");
    ros::NodeHandle nh;

    // ROS Subscribers
    ros::Subscriber sub1 = nh.subscribe("aruco_topic", 10, arucoCallback);
    ros::Subscriber sub2 = nh.subscribe("emergency_topic", 10, emergencyCallback);

    // Create the behavior tree nodes
    ActionNode* runEmergencyDependency = new ActionNode("runEmergencyDependency", "/home/aaron3074/testing/src/btree_test/launch/runEmergencyDependency.launch");
    ActionNode* rov = new ActionNode("rov", "/home/aaron3074/testing/src/btree_test/launch/rov.launch");
    ActionNode* runDocking = new ActionNode("runDocking", "/home/aaron3074/testing/src/btree_test/launch/runDocking.launch");
    ActionNode* runController = new ActionNode("runController", "/home/aaron3074/testing/src/btree_test/launch/runController.launch");
    ActionNode* disarm = new ActionNode("disarm", "/home/aaron3074/testing/src/btree_test/launch/disarm.launch");

    std::map<std::string, BehaviorTreeNode*> launchNodeMap;

    // Store launch nodes in a map
    launchNodeMap["runEmergencyDependency"] = runEmergencyDependency;
    launchNodeMap["rov"] = rov;
    launchNodeMap["runDocking"] = runDocking;
    launchNodeMap["runController"] = runController;
    launchNodeMap["disarm"] = disarm;

    rov->execute();
    runDocking->execute();
    runController->execute();
    runEmergencyDependency->execute(); 
    disarm->execute();
    runEmergencyDependency->terminate(); 
    // Execution in a separate thread
    std::thread execution_thread([&]() {
        //while (ros::ok()) {
            if (emergency) {
                disarm->execute();
                runEmergencyDependency->terminate();
            } else if (aruco_detected) {
                runEmergencyDependency->execute();
                runDocking->execute();
                runController->execute();
            } //else {
                //disarm->execute();
                //rov->execute();
                //break;
            //}
            // Sleep for a while to prevent high CPU usage
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        //}
    });

    // Input handling thread
    std::thread input_thread([&]() {
    int input = 0;
    while (ros::ok()) {
        std::cout << "Enter command (1-4 to terminate specific node, 0 to terminate runEmergencyDependency, -1 to terminate all and exit): ";
        std::cin >> input;
        switch (input) {
            case 1: {
                auto it = launchNodeMap.find("rov");
                if (it != launchNodeMap.end()) {
                    BehaviorTreeNode* node = it->second;
                    if (node->getPID() != -1) {
                        std::cout << "Terminating rov node with PID: " << node->getPID() << std::endl;
                        node->terminate();
                    }
                }
                break;
            }
            case 2: {
                auto it = launchNodeMap.find("runDocking");
                if (it != launchNodeMap.end()) {
                    BehaviorTreeNode* node = it->second;
                    if (node->getPID() != -1) {
                        std::cout << "Terminating runDocking node with PID: " << node->getPID() << std::endl;
                        node->terminate();
                    }
                }
                break;
            }
            case 3: {
                auto it = launchNodeMap.find("runController");
                if (it != launchNodeMap.end()) {
                    BehaviorTreeNode* node = it->second;
                    if (node->getPID() != -1) {
                        std::cout << "Terminating runController node with PID: " << node->getPID() << std::endl;
                        node->terminate();
                    }
                }
                break;
            }
            case 4: {
                auto it = launchNodeMap.find("disarm");
                if (it != launchNodeMap.end()) {
                    BehaviorTreeNode* node = it->second;
                    if (node->getPID() != -1) {
                        std::cout << "Terminating disarm node with PID: " << node->getPID() << std::endl;
                        node->terminate();
                    }
                }
                break;
            }
            case 0: {
                auto it = launchNodeMap.find("runEmergencyDependency");
                if (it != launchNodeMap.end()) {
                    BehaviorTreeNode* node = it->second;
                    if (node->getPID() != -1) {
                        std::cout << "Terminating runEmergencyDependency node with PID: " << node->getPID() << std::endl;
                        node->terminate();
                    }
                }
                break;
            }
            case -1: { // Terminate all and exit
                for (auto& entry : launchNodeMap) {
                    entry.second->terminate();
                }
                ros::shutdown();
                return;
            }
            default: 
                std::cout << "Invalid command!" << std::endl;
                break;
        }
    }
});


    // Signal handling
    signal(SIGINT, handleSignal);

    // Spin until ROS is shutdown
    ros::spin();

    // Cleanup
    execution_thread.join();
    input_thread.join();

    //delete runPyMavlink;
    //delete runImagePipeline;
    delete runEmergencyDependency;
    delete rov;
    delete runDocking;
    delete runController;
    delete disarm;

    return 0;
}







