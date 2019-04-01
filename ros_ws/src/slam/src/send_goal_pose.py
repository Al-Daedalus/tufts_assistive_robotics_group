#! /usr/bin/env python

'''
Written by Alphonsus Adu-Bredu (http://alphonsusadubredu.com)

Code for go_to_pose node
This node accepts a goal pose published to the /goal_pose topic 
and moves the robot to the goal pose.
It reads the current pose of the robot from the /pose topic
'''
import rospy
from geometry_msgs.msg import Twist
from geometry_msgs.msg import PoseStamped
import time
from tf.transformations import euler_from_quaternion
import math
import sys

robot_pose = PoseStamped()
def robot_pose_callback(pose):
		robot_pose = pose

def go_to_pose(delta):
	pose = PoseStamped()
	pose.pose.position.x = 2.285
	pose.pose.position.y = 12.082
	pose.pose.position.x = -1.116
	pose.pose.orientation.x = 0.0079
	pose.pose.orientation.y = -0.0049
	pose.pose.orientation.z = -0.9634
	pose.pose.orientation.w = -0.2676
	#pose.pose.position.x+=delta
	pose.pose.position.y+=delta
	pub = rospy.Publisher('/goal_pose',PoseStamped, queue_size=10)
	pub.publish(pose)


if __name__ == "__main__":
	rospy.init_node('test_node')
	#rospy.Subscriber('/pose', PoseStamped, robot_pose_callback)
	#while not rospy.is_shutdown():
	for i in range(0,5000):
		go_to_pose(0.4)
	
