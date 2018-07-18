#! /usr/bin/env python

import rospy
from ar_track_alvar_msgs.msg import AlvarMarkers
from geometry_msgs.msg import Twist
from sensor_msgs.msg import Imu
from std_msgs.msg import Float32
from gtts import gTTS 
import playsound
import time
import tf
from math import atan2, fabs, sin, cos, pi

class auto_park:
	def imu_callback(self, imu_data):
		
		orr = (pi /180)*imu_data.data
		orrientation = atan2(sin(orr),cos(orr))

		self.orientation = orrientation
		if not self.init_gotten:
			self.init_orientation = orrientation
			self.init_gotten = True
		



	def turn(self):
		rate = rospy.Rate(5)
		# diff = fabs(self.orientation - self.init_orientation)
		while  True:# < 1.658):
			rospy.Subscriber("/imu_heading", Float32, self.imu_callback)
			
			diff = fabs(self.orientation - self.init_orientation)
			print diff

			if rospy.is_shutdown():
				break
			

	def __init__(self):
		self.orientation = 0.0
		self.init_orientation = 0.0
		self.init_gotten = False
		rospy.Subscriber("/imu_heading", Float32, self.imu_callback)
		self.turn()

if __name__ == "__main__":
	rospy.init_node('auto')
	try:
		pack = auto_park()

	except rospy.ROSInterruptException: pass

		