#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/Int32.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char** argv)
{
    ros::init(argc,argv,"inter_move_test");
    
    ROS_INFO("auto_move_ test_start!");

    ros::NodeHandle nh;
    ros::Publisher test_pub = nh.advertise<std_msgs::Int32>("/inter_move", 1000);
        ros::Duration(3.0).sleep();
    //vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel",10);
    //vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop",10);
    int i = 0;
    while(i < 5)
    {
    printf("send %d\n", 1);
    std_msgs::Int32 msg;
    msg.data = 1;
    test_pub.publish(msg);
    ros::spinOnce();
    ros::Duration(0.8).sleep();
    i++;
    }
    ros::Duration(3.0).sleep();
    i= 0;
    while(i < 2)
    {
    printf("send %d\n", 3);
    std_msgs::Int32 msg;
    msg.data = 3;
    test_pub.publish(msg);
    ros::spinOnce();
    ros::Duration(0.8).sleep();
    i++;
    }
    ros::Duration(3.0).sleep();
    i= 0;
    while(i < 4)
    {
    printf("send %d\n", 5);
    std_msgs::Int32 msg;
    msg.data = 5;
    test_pub.publish(msg);
    ros::spinOnce();
    ros::Duration(0.8).sleep();
    i++;
    }
    i= 0;
    while(i < 2)
    {
    printf("send %d\n", 2);
    std_msgs::Int32 msg;
    msg.data = 2;
    test_pub.publish(msg);
    ros::spinOnce();
    ros::Duration(0.8).sleep();
    i++;
    }
    printf("send %d\n", 0);
    std_msgs::Int32 msg;
    msg.data = 0;
    test_pub.publish(msg);
    ros::spinOnce();
    ros::Duration(0.8).sleep();

return 0;
}
