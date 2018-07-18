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


	def approach1(self, dist):
		v = Twist()
		
		if self.seen1:
			while ((dist-0.05)>self.z_dist_1) or (self.z_dist_1 > (dist+0.05)):
				rospy.Subscriber("/ar_pose_marker", AlvarMarkers, self.update_markers, queue_size=1)
				time.sleep(1)
			
				if rospy.is_shutdown():
					break

				if self.updated:
				
					velocity = Twist()

					if self.z_dist_1 < (dist-0.2):
						velocity.linear.x = -1.0
					else:
						velocity.linear.x = 1.0

					self.vel_pub.publish(velocity)
					time.sleep(1)
					#print self.z_dist_1
					if self.x_dist_1 < -0.5:
						vel = Twist()
						vel.angular.z = 1.0
						self.vel_pub.publish(vel)
						print "left"
					elif self.x_dist_1 > 0.0:
						vel = Twist()
						vel.angular.z = -1.0
						self.vel_pub.publish(vel)
						print "right"

				
					#self.vel_pub.publish(v)
					print "self.z_dist_1 = "+str(self.z_dist_1)
					rospy.Subscriber("/ar_pose_marker", AlvarMarkers, self.update_markers, queue_size=1)
					time.sleep(0.5)
					self.vel_pub.publish(v)
					time.sleep(1)
		
			velocity = Twist()
			self.vel_pub.publish(velocity)
			print "done approaching 1"




	def approach5(self, dist):		
		v = Twist()
		
		if self.seen5:
			while ((dist-0.05)>self.z_dist_5) or (self.z_dist_5 > (dist+0.05)):
				rospy.Subscriber("/ar_pose_marker", AlvarMarkers, self.update_markers, queue_size=1)
				time.sleep(1)
			
				if rospy.is_shutdown():
					break

				if self.updated:
					velocity = Twist()

					if self.z_dist_5 < (dist-0.2):
						velocity.linear.x = -1.0
					else:
						velocity.linear.x = 1.0

					self.vel_pub.publish(velocity)
					time.sleep(1)
					#print self.z_dist_1
					if self.x_dist_5 < -0.4:
						vel = Twist()
						vel.angular.z = 1.0
						self.vel_pub.publish(vel)
						print "left"
					elif self.x_dist_5 > 0.0:
						vel = Twist()
						vel.angular.z = -1.0
						self.vel_pub.publish(vel)
						print "right"

					if rospy.is_shutdown():
						break
					#self.vel_pub.publish(v)
					print "self.z_dist_5 = "+str(self.z_dist_5)
					rospy.Subscriber("/ar_pose_marker", AlvarMarkers, self.update_markers, queue_size=1)
					time.sleep(0.5)
					self.vel_pub.publish(v)
					#time.sleep(1)
		
			velocity = Twist()
			self.vel_pub.publish(velocity)
			print "done approaching 5"
	

	def adjust34(self):
		if self.seen34:
			print "adjusting for 34"
			# if self.z_dist_34 > 3.5:
				

			# 	velocity = Twist()
			# 	velocity.linear.x = 1.0
			# 	self.vel_pub.publish(velocity)
			# 	time.sleep(1)

			# 	if self.x_dist_34 < -0.5:
			# 		vel = Twist()
			# 		vel.angular.z = 1.0
			# 		self.vel_pub.publish(vel)
			# 		print "left34"
			# 	elif self.x_dist_34 > 0.0:
			# 		vel = Twist()
			# 		vel.angular.z = -1.0
			# 		self.vel_pub.publish(vel)
			# 		print "right34"
				
				
			self.turn(0.02);
	#def approach30(self, dist):
	#	print "approaching"
	#	rate = rospy.Rate(1)
		
	#	if not self.z_dist_30 == -1:
	#		while self.z_dist_30 > dist:
	#			velocity = Twist()
	#			v = Twist()
	#			velocity.linear.x = 1.0
	#			self.vel_pub.publish(velocity)
	#			if self.x_dist_30 < -0.5:
	#				vel = Twist()
	#				vel.angular.z = 1.0
	#				self.vel_pub.publish(vel)
				
	#			elif self.x_dist_30 > 0.0:
	#				vel = Twist()
	#				vel.angular.z = -1.0
	#				self.vel_pub.publish(vel)
	#			
	#			if rospy.is_shutdown():
	#				break
	#			rate.sleep()
	#			self.vel_pub.publish(v)
	#			rate.sleep()
			
	#			print "self.z_dist_30 = "+str(self.z_dist_30)
	#			rospy.Subscriber("/ar_pose_marker", AlvarMarkers, self.update_markers)

	#		velocity = Twist()
	#		self.vel_pub.publish(velocity)
	#		print "done approaching 30"
	#		self.turn(0.02)
	#		x = 0;
	#		while x < 3:
	#			vel = Twist()
	#			vel.linear.x = 1.0
	#			self.vel_pub.publish(vel)
	#			x+=1
	#			time.sleep(1)
	#		vel = Twist()
	#		vel.linear.x = 0.0
	#		self.vel_pub.publish(vel)


	#def approach34(self, dist):
	#	print "approaching"
	#	rate = rospy.Rate(5)
		
	#	while self.z_dist_34 > dist:
	#		velocity = Twist()
	#		velocity.linear.x = 1.0
	#		self.vel_pub.publish(velocity)
	#		if self.x_dist_34 < -0.5:
	#			vel = Twist()
	#			vel.angular.z = 1.0
	#			self.vel_pub.publish(vel)
	#		elif self.x_dist_34 > 0.0:
	#			vel = Twist()
	#			vel.angular.z = -1.0
	#			self.vel_pub.publish(vel)
	#		if rospy.is_shutdown():
	#			break
	#		rate.sleep()
	#		print "self.z_dist_34 = "+str(self.z_dist_34)
	#		rospy.Subscriber("/ar_pose_marker", AlvarMarkers, self.update_markers)

	#	velocity = Twist()
	#	self.vel_pub.publish(velocity)
	#	print "done approaching 34"
	#	self.turn(0.02)






	def update_markers(self, data):
		
		if not data.markers:
			print "didn't update"
			velocity = Twist()
			self.vel_pub.publish(velocity)
			#time.sleep(1)
			self.updated = False
			return

		
		self.updated = True
		for i in range(0, len(data.markers)):
			if data.markers[i].id == 1:
				#print "updating"
				#self.data_1 = data.markers[i]
				self.seen1 = True
				self.x_dist_1 = data.markers[i].pose.pose.position.x
				self.z_dist_1 = data.markers[i].pose.pose.position.z
				#print "orig z_dist_1 = "+str(data.markers[i].pose.pose.position.z)
				#self.approach1(0.8)
				#print self.z_dist_1
				

			if data.markers[i].id == 5:
				#self.data_5 = data.markers[i]
				self.seen5 = True
				self.x_dist_5 = data.markers[i].pose.pose.position.x
				self.z_dist_5 = data.markers[i].pose.pose.position.z
				#if not self.seen5:
					#self.seen5 = True
					#self.approach5(0.6)


			#if data.markers[i].id == 30:
			#	self.data_30 = data.markers[i]
			#	self.x_dist_30 = data.markers[i].pose.pose.position.x
			#	self.z_dist_30 = data.markers[i].pose.pose.position.z
			#	if not self.seen30:
			#		self.seen30 = True
			#		self.approach30(1.3)

			if data.markers[i].id == 34:
				#self.data_34 = data.markers[i]
				self.x_dist_34 = data.markers[i].pose.pose.position.x
				self.z_dist_34 = data.markers[i].pose.pose.position.z
				self.seen34 = True
			#	if not self.seen34:
			#		self.seen34 = True
			#		self.approach34(1.3)
	

	def __init__(self):
		self.init_orientation = 0.0
		self.orientation = 0.0
		self.seen30 = False
		self.seen34 = False
		self.seen1 = False
		self.seen5 = False
		self.announced = False
		self.z_dist_1 = 1.0
		self.x_dist_1 = 0.0
		self.z_dist_5 = 1.0
		self.x_dist_5 = 0.0
		self.init_gotten = False
		self.turn_complete = False
		self.localized = False
		self.updated = False
		self.vel_pub = rospy.Publisher('/cmd_vel', Twist, queue_size=10)
		#rospy.Subscriber("/ar_pose_marker", AlvarMarkers, self.update_markers, queue_size=1)
		#print self.z_dist_1
		time.sleep(2)
		#self.adjust34()
		time.sleep(3)
		#rospy.Subscriber("/ar_pose_marker", AlvarMarkers, self.update_markers,queue_size=1)
		time.sleep(2)
		#self.approach1(1.5)
		#rospy.spin()
		self.turn(0.035)
		time.sleep(3)
		self.approach5(1.3)
		
		



if __name__ == "__main__":
	rospy.init_node('auto_parking')
	try:
		pack = auto_park()

	except rospy.ROSInterruptException: pass

