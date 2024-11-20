#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <sensor_msgs/Imu.h>
#include <sensor_msgs/LaserScan.h>
#include <sensor_msgs/MagneticField.h>

// 回调函数
void encoderCallback(const nav_msgs::Odometry::ConstPtr &msg, ros::Publisher &pub)
{
    ROS_INFO("Received /driver/encoder message");
    pub.publish(msg);
}

void eulCallback(const sensor_msgs::Imu::ConstPtr &msg, ros::Publisher &pub)
{
    ROS_INFO("Received /driver/eul message");
    pub.publish(msg);
}

void imuCallback(const sensor_msgs::Imu::ConstPtr &msg, ros::Publisher &pub)
{
    ROS_INFO("Received /driver/imu message");
    pub.publish(msg);
}

void magCallback(const sensor_msgs::MagneticField::ConstPtr &msg, ros::Publisher &pub)
{
    ROS_INFO("Received /driver/mag message");
    pub.publish(msg);
}

void scanCallback(const sensor_msgs::LaserScan::ConstPtr &msg, ros::Publisher &pub)
{
    ROS_INFO("Received /driver/scan message");
    pub.publish(msg);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "yk");
    ros::NodeHandle nh;

    // 创建发布者
    ros::Publisher encoder_pub = nh.advertise<nav_msgs::Odometry>("/driver/encoder3", 10);
    ros::Publisher eul_pub = nh.advertise<sensor_msgs::Imu>("/driver/eul3", 10);
    ros::Publisher imu_pub = nh.advertise<sensor_msgs::Imu>("/driver/imu3", 10);
    ros::Publisher mag_pub = nh.advertise<sensor_msgs::MagneticField>("/driver/mag3", 10);
    ros::Publisher scan_pub = nh.advertise<sensor_msgs::LaserScan>("/driver/scan3", 10);

    // 创建订阅者
    ros::Subscriber encoder_sub = nh.subscribe<nav_msgs::Odometry>(
        "/driver/encoder", 10, boost::bind(encoderCallback, _1, boost::ref(encoder_pub)));

    ros::Subscriber eul_sub = nh.subscribe<sensor_msgs::Imu>(
        "/driver/eul", 10, boost::bind(eulCallback, _1, boost::ref(eul_pub)));

    ros::Subscriber imu_sub = nh.subscribe<sensor_msgs::Imu>(
        "/driver/imu", 10, boost::bind(imuCallback, _1, boost::ref(imu_pub)));

    ros::Subscriber mag_sub = nh.subscribe<sensor_msgs::MagneticField>(
        "/driver/mag", 10, boost::bind(magCallback, _1, boost::ref(mag_pub)));

    ros::Subscriber scan_sub = nh.subscribe<sensor_msgs::LaserScan>(
        "/driver/scan", 10, boost::bind(scanCallback, _1, boost::ref(scan_pub)));

    ROS_INFO("Node initialized, subscribing and relaying topics...");
    ros::spin();

    return 0;
}
