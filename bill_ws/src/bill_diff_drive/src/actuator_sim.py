#! /usr/bin/env python

import rospy
from diff_drive_msgs.msg import Diff_drive
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry  
from std_msgs.msg import Float64

class actuator_sim:
	def diff_callback(self, msg):
		self.left_vel = Float64(msg.left_wheel_vel)
		self.right_vel = Float64(msg.right_wheel_vel)
		self.left_pub.publish(self.left_vel)
		self.right_pub.publish(self.right_vel)

	def __init__(self):
		self.left_vel = 0.0
		self.right_vel = 0.0
		self.left_pub = rospy.Publisher('/bill/left_wheel_hinge_position_controller/command',Float64, queue_size=1)
		self.right_pub = rospy.Publisher('/bill/right_wheel_hinge_position_controller/command',Float64, queue_size=1)

		rospy.Subscriber("/diff_drive_vel", Diff_drive, self.diff_callback)
		rospy.spin()

if __name__=="__main__":
	rospy.init_node("actuator_sim")
	try:
		actuator = actuator_sim()
	except rospy.ROSInterruptException: pass