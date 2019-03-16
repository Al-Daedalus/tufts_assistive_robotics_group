#! /usr/bin/env python

import rospy
from std_msgs.msg import Int32
from geometry_msgs.msg import Twist
import time

class Distance:
	def __init__(self):
		rospy.init_node('distance')

		self.left = 0
		self.right = 0
		self.ticks_meter = 9.95
		self.base_width = 0.6
		self.enc_left = 0
		self.enc_right = 0
		self.rate = 10
		self.l_enc_updated = False
		self.r_enc_updated = False
		self.vel_pub = rospy.Publisher('/cmd_vel', Twist,queue_size=1)
		
		rospy.Subscriber('l_wheel', Int32, self.lwheelCallback)
		rospy.Subscriber('r_wheel', Int32, self.rwheelCallback)


	#def kitchenCallback(self,data):

	def lwheelCallback(self, msg):
		self.left = msg.data
		if not self.l_enc_updated:
			self.enc_left = self.left
			self.l_enc_updated = True

	def rwheelCallback(self, msg):
		self.right = msg.data
		if not self.r_enc_updated:
			self.enc_right = self.right
			self.r_enc_updated = True


	def spin(self):
		r = rospy.Rate(self.rate)
		#while not rospy.is_shutdown():
		self.forward(0.7)
		time.sleep(2)
		self.turn_right_90(0.5)
		#rospy.spinOnce()
		# r.sleep()

	def turn_right_90(self, dist):
		d_left = (self.left-self.enc_left) / self.ticks_meter
		d_right = (self.right - self.enc_right)/self.ticks_meter
		r = rospy.Rate(self.rate)
		vel = Twist()
		vel.angular.z = -2

		while d_left < dist and not rospy.is_shutdown():
			d_left = (self.left-self.enc_left) / self.ticks_meter
			d_right = (self.right - self.enc_right)/self.ticks_meter
			r = rospy.Rate(self.rate)
			self.vel_pub.publish(vel)
			r.sleep()
			rospy.loginfo("distance: %f",d_left)
		stop = Twist()
		stop.linear.x = 0
		self.vel_pub.publish(stop)


	def forward(self,dist):
		d_left = (self.left-self.enc_left) / self.ticks_meter
		d_right = (self.right - self.enc_right)/self.ticks_meter
		r = rospy.Rate(self.rate)
		vel = Twist()
		vel.linear.x = 1.00
		d = (d_left + d_right)/2
		while d < dist-0.10 and not rospy.is_shutdown():
			d_left = (self.left-self.enc_left) / self.ticks_meter
			d_right = (self.right - self.enc_right)/self.ticks_meter
			r = rospy.Rate(self.rate)
			vel = Twist()
			vel.linear.x = 1.00
			d = (d_left + d_right)/2

			
			self.vel_pub.publish(vel)
			r.sleep()
			rospy.loginfo("distance: %f",d)

		stop = Twist()
		stop.linear.x = 0
		self.vel_pub.publish(stop)



if __name__ == '__main__':
	try:
		dist = Distance()
		dist.spin()

	except rospy.ROSInterruptException:
		pass




