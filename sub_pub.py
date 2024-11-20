#!/usr/bin/env python
import rospy
from nav_msgs.msg import Odometry
from sensor_msgs.msg import Imu, LaserScan, MagneticField

# 回调函数
def encoder_callback(data):
    rospy.loginfo("Received /driver/encoder message")
    encoder_pub.publish(data)

def eul_callback(data):
    rospy.loginfo("Received /driver/eul message")
    eul_pub.publish(data)

def imu_callback(data):
    rospy.loginfo("Received /driver/imu message")
    imu_pub.publish(data)

def mag_callback(data):
    rospy.loginfo("Received /driver/mag message")
    mag_pub.publish(data)

def scan_callback(data):
    rospy.loginfo("Received /driver/scan message")
    scan_pub.publish(data)

if __name__ == '__main__':
    rospy.init_node('yk', anonymous=True)

    # 创建发布者
    encoder_pub = rospy.Publisher('/driver/encoder2', Odometry, queue_size=10)
    eul_pub = rospy.Publisher('/driver/eul2', Imu, queue_size=10)
    imu_pub = rospy.Publisher('/driver/imu2', Imu, queue_size=10)
    mag_pub = rospy.Publisher('/driver/mag2', MagneticField, queue_size=10)
    scan_pub = rospy.Publisher('/driver/scan2', LaserScan, queue_size=10)

    # 订阅话题
    rospy.Subscriber('/driver/encoder', Odometry, encoder_callback)
    rospy.Subscriber('/driver/eul', Imu, eul_callback)
    rospy.Subscriber('/driver/imu', Imu, imu_callback)
    rospy.Subscriber('/driver/mag', MagneticField, mag_callback)
    rospy.Subscriber('/driver/scan', LaserScan, scan_callback)

    rospy.loginfo("Node initialized, subscribing and relaying topics...")
    rospy.spin()
