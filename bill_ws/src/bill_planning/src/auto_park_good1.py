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
	def announce(self):
		tts = gTTS(text='Deactivating joystick. Please do not use the joystick. Activating auto pilot mode', lang='en')
		tts.save("autopilot.mp3")
		playsound.playsound("autopilot.mp3", True)
		time.sleep(5)
		self.announced = True


	def imu_callback(self, imu_data):
		
		orr = (pi /180)*imu_data.data
		orrientation = atan2(sin(orr),cos(orr))

		self.orientation = orrientation
		if not self.init_gotten:
			self.init_orientation = orrientation
			self.init_gotten = True
		



	def turn(self,angle):
		rate = rospy.Rate(5)
		diff = fabs(self.orientation - self.init_orientation)
		while  not (angle < diff):# < 1.658):
			velocity = Twist()
			velocity.angular.z = -1.0
			self.vel_pub.publish(velocity)
			rospy.Subscriber("/imu_heading", Float32, self.imu_callback)
			print diff
			diff = fabs(self.orientation - self.init_orientation)

			if rospy.is_shutdown():
				break
			rate.sleep()

		self.turn_complete = True
		velocity = Twist()
		velocity.angular.z = 0.0
		self.vel_pub.publish(velocity)
		print "Done turning 90 degrees"




	def approach1(self, dist, data):
		if not self.donewith1:
			z_dist_1 = data.pose.pose.position.z
			x_dist_1 = data.pose.pose.position.x
			print "z_dist_1 = " + str(z_dist_1)

			if ((dist-0.05)>z_dist_1) or (z_dist_1 > (dist+0.05)):
				velocity = Twist()

				if z_dist_1 < (dist-0.2):
					velocity.linear.x = -1.0
				else:
					velocity.linear.x = 1.0

				self.vel_pub.publish(velocity)
				time.sleep(1)
				
				if x_dist_1 < -0.5:
					vel = Twist()
					vel.angular.z = 1.0
					self.vel_pub.publish(vel)
					print "left"
				elif x_dist_1 > 0.0:
					vel = Twist()
					vel.angular.z = -1.0
					self.vel_pub.publish(vel)
					print "right"
				time.sleep(0.5)
			else:
				v = Twist()
				self.vel_pub.publish(v)
				time.sleep(3)
				self.donewith1 = True
				self.turn(0.02)




	def approach5(self, dist, data):
		if not self.donewith5:
			z_dist_5 = data.pose.pose.position.z
			x_dist_5 = data.pose.pose.position.x
			print "z_dist_5 = " + str(z_dist_5)

			if ((dist-0.05)>z_dist_5) or (z_dist_5 > (dist+0.05)):
				velocity = Twist()

				if z_dist_5 < (dist-0.2):
					velocity.linear.x = -1.0
				else:
					velocity.linear.x = 1.0

				self.vel_pub.publish(velocity)
				time.sleep(1)
				
				if x_dist_5 < -0.4:
					vel = Twist()
					vel.angular.z = 1.0
					self.vel_pub.publish(vel)
					print "left"
				elif x_dist_5 > 0.0:
					vel = Twist()
					vel.angular.z = -1.0
					self.vel_pub.publish(vel)
					print "right"

			else:
				v = Twist()
				self.vel_pub.publish(v)
				time.sleep(3)
				self.donewith5 = True
				print 'done localizing'




	def update_markers(self, data):
		
		if not data.markers:
			print "didn't update"
			velocity = Twist()
			self.vel_pub.publish(velocity)
			self.updated = False
			return

		
		self.updated = True
		for i in range(0, len(data.markers)):
			if data.markers[i].id == 1:
				if not self.donewith1:
					self.approach1(1.5, data.markers[i])
				
				

			if data.markers[i].id == 5:
				if not self.donewith5:
					self.approach5(1.3, data.markers[i])
				

			
			if data.markers[i].id == 34:
				if data.markers[i].pose.pose.position.z > 3.0:
					v = Twist()
					v.linear.x = 1.0
					self.vel_pub.publish(v)
					time.sleep(3)
				self.turn(0.03)




	def listener(self):
		rospy.Subscriber("/ar_pose_marker", AlvarMarkers, self.update_markers, queue_size=1)
		rospy.spin()


	def __init__(self):
		self.init_orientation = 0.0
		self.orientation = 0.0
		self.announced = False
		self.init_gotten = False
		self.turn_complete = False
		self.localized = False
		self.updated = False
		self.donewith1 = False
		self.donewith5 = False
		self.vel_pub = rospy.Publisher('/cmd_vel', Twist, queue_size=10)
		
		self.listener()
		



if __name__ == "__main__":
	rospy.init_node('auto_parking')
	try:
		pack = auto_park()

	except rospy.ROSInterruptException: pass

