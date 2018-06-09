#! /usr/bin/env python

import rospy
from diff_drive_msgs.msg import Diff_drive
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry  
from math import atan2, fabs, sin, cos


class Diff_driver:
	def odom_callback(self,msg):
		self.curr_or = msg.twist.twist.angular.z

	def constrain_vel (self,inputs):
		if inputs > 0.55:
			return 0.55
		elif inputs < -0.55:
			return -0.55
		else:
			return inputs


	def publish_diff(self,v,w):
		self.v_r = (2*v + w*self.l)/(2*self.r)
		self.v_l = (2*v - w*self.l)/(2*self.r) 
		#self.v_r = self.constrain_vel(self.v_r)
		#self.v_l = self.constrain_vel(self.v_l)
		diff = Diff_drive()
		diff.time_stamp = rospy.get_time()
		diff.left_wheel_vel = self.v_l
		diff.right_wheel_vel = self.v_r
		self.diff_pub.publish(diff)

	
	def pid(self,v,w):
		last_time = 0.0
		prev_error = 0.0
		while True:
			rospy.Subscriber("/odom", Odometry, self.odom_callback)
			error = w - self.curr_or
			self.p = self.k_p * error
			self.i = self.i + (self.k_i*error)
			dt = rospy.get_time() - last_time
			self.d = self.k_d * ( (error - prev_error) / dt)
			last_time = rospy.get_time()
			prev_error = error
			self.PID = self.p + self.i + self.d
			self.PID = atan2(sin(self.PID), cos(self.PID))
			w_f = self.PID + self.curr_or
			w_f = atan2(sin(w_f), cos(w_f))
			self.publish_diff(v, w_f)

			if fabs(error) <= 0.05:
				break

	def vel_callback(self,vel):
		v = vel.linear.x
		w = vel.angular.z
		self.publish_diff(v,w)


	def __init__(self):
		self.p = 0.0
		self.i = 0.0
		self.d = 0.0
		self.curr_or = 0.0
		self.PID = 0.0
		self.k_p = 0.31
		self.k_i = 0.0
		self.k_d = 0.59
		self.v_l = 0.0
		self.v_r = 0.0
		self.l = 0.62
		self.r = 0.162

		self.diff_pub = rospy.Publisher('/diff_drive_vel', Diff_drive, queue_size=1)
		sub = rospy.Subscriber('/cmd_vel', Twist, self.vel_callback)
		rospy.spin()


if __name__ == "__main__":
	rospy.init_node('cmd_vel_to_diff_drive')
	try:
		differential = Diff_driver()

	except rospy.ROSInterruptException: pass

'''
rospy.init_node('cmd_vel_to_diff_drive')
diff_pub = rospy.Publisher('/diff_drive_vel', Diff_drive, queue_size=100)

diff = Diff_drive()
l =  0.62  #baseline length
r = 0.162    #radius of wheels
v_r = 0.0
v_l = 0.0
k_p = 0.31
k_i = 0.0
k_d = 0.59

def pid(w):
	
	

def callback(msg):
	v = msg.linear.x
	w = msg.angular.z
	
	while True:
		


	v_r = (2*v + w*l)/(2*r)
        v_l = (2*v - w*l)/(2*r)
	diff.time_stamp = rospy.get_time()
	diff.left_wheel_vel = v_l
	diff.right_wheel_vel = v_r
	diff_pub.publish(diff)


sub = rospy.Subscriber('/cmd_vel', Twist, callback)
rospy.spin()
'''
