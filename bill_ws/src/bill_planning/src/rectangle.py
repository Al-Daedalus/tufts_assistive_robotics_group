#! /usr/bin/env python
import rospy
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Twist

rospy.init_node('move_in_rectangle')
cmd_pub = rospy.Publisher('/cmd_vel', Twist, queue_size = 1)

class rectangle:
	def odom_callback(self, odom):
		self.distance = odom.pose.pose.position.x
		self.orientation = odom.pose.pose.orientation.z

	def move:
		if self.distance < 3.0:
			vel = Twist()
			vel.linear.x = 0.2
			vel.angular.z = 0.0 
			cmd_pub.publish(vel)
			rospy.Subscriber("/odom", Odometry,self.odom_callback)
			
		rospy.sleep(5)
		vel = Twist()
		vel.linear.x = 0.2
		vel.angular.z = 0.1

		if self.orientation < 0.2:
			cmd_pub.publish(vel)
			rospy.Subscriber("/odom", Odometry,self.odom_callback)

		rospy.sleep(5)
		if self.distance < 3.0:
			vel = Twist()
			vel.linear.x = 0.2
			vel.angular.z = 0.0 
			cmd_pub.publish(vel)
			rospy.Subscriber("/odom", Odometry,self.odom_callback)
			
		rospy.sleep(5)
		





