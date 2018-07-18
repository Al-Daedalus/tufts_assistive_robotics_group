#! /usr/bin/env python

import rospy
from geometry_msgs.msg import Twist
from ar_track_alvar_msgs import AlvarMarkers
from sensor_msgs.msg import Imu
from gtts import gTTS 
import playsound
import time

class auto_pilot:

	def init_imu_callback(self, imu_data):
		self.init_orientation = imu_data.orientation.z

	def imu_callback(self, imu_data):
		self.orientation = imu_data.orientation.z

	def marker_callback(self, data):
		if not data.markers:
			return

		for i in range(0, len(data.markers)):
			if data.markers[i].id == 15:
				if data.markers[i].pose.pose.position.x <= 1.0:
					tts = gTTS(text='Deactivating joystick and activating auto_pilot mode', lang='en')
                	tts.save("autopilot.mp3")
                	playsound.playsound("autopilot.mp3", True)
                	time.sleep(5)
                	rospy.Subscriber("/imu", Imu, self.init_imu_callback)
                	rospy.Subscriber("/imu", Imu, self.imu_callback)

                	while not (1.484 < abs(self.orientation - self.init_orientation) < 1.658):
                		velocity = Twist()
                		velocity.angular.z = 1.0
                		self.vel_pub.publish(velocity)
                		rospy.Subscriber("/imu", Imu, self.imu_callback)

                	velocity = Twist()
                	velocity.angular.z = 0.0
                	self.vel_pub.publish(velocity)

            if data.markers[i].id == 19:
            	while data.markers[i].pose.pose.position.x > 0.5:
            		velocity = Twist()
            		velocity.linear.x = 1.0
            		self.vel_pub.publish(velocity)


            	velocity = Twist()
            	velocity.linear.x = 0.0
            	self.vel_pub.publish(velocity)

    def __init__(self):
    	self.init_orientation = 0.0
    	self.orientation = 0.0
    	self.vel_pub = rospy.Publisher('/cmd_vel', Twist, queue_size=1)
    	rospy.Subscriber('/ar_pose_marker', AlvarMarkers, self.marker_callback)


if __name__ == "__main__":
	rospy.init_node('auto_parking')
	try:
		autopark = auto_pilot()

	except rospy.ROSInterruptException: pass
