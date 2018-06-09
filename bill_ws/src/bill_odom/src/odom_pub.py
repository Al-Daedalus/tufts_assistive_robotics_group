#! /usr/bin/env python
import rospy
from nav_msgs.msg import Odometry
from sensor_msgs.msg import Imu
from encoder_msgs.msg import Encoder
from math import pi, sin, cos
from tf.transformations import quaternion_from_euler

class odom:
	def encoder_callback(self,enc):
		self.left_ticks = enc.left_encoder_count
		self.right_ticks = enc.right_encoder_count

	def imu_callback(self,imu):
		self.imu_or = imu.orientation.z
		self.imu_or -= self.init_imu_or

	def init_imu_callback(self,imu):
		self.init_imu_or = imu.orientation.z

	def complementaryFilter(self,enc_or, imu_or):
		final_or = 0.98*imu_or + 0.02*enc_or
		return final_or


	def pub_odom(self):
		rospy.Subscriber("/imu", Imu, self.imu_callback)
		rospy.Subscriber("/encoder", Encoder, self.encoder_callback)
		left_curr_dist = (self.left_ticks * self.wheel_diameter * pi) / self.left_ticks_per_rev
		right_curr_dist = (self.right_ticks * self.wheel_diameter * pi) / self.right_ticks_per_rev

		left_est_vel = left_curr_dist - self.left_old_dist
		right_est_vel = right_curr_dist - self.right_old_dist

		self.left_old_dist = left_curr_dist
		self.right_old_dist = right_curr_dist

		linear_vel = (right_est_vel + left_est_vel) * 0.5
		delta_enc_or = (right_est_vel - left_est_vel) / self.baseline_length
		self.enc_or = self.prev_or + delta_enc_or

		self.final_or = self.complementaryFilter(self.enc_or, self.imu_or)

		self.x += linear_vel * cos(self.prev_or)
		self.y += linear_vel * sin(self.prev_or)

		now = rospy.get_time()
		dt = now - self.last_time
		
		if dt < 0.0001:
			dt = 0.0001

		delta_or = self.final_or - self.prev_or

		linear_vel = linear_vel / dt
		angular_vel = delta_or / dt

		orientation_quat = quaternion_from_euler(0,0,self.final_or)

		odom_word = Odometry()

		
		odom_word.header.stamp = rospy.get_rostime()
		odom_word.pose.pose.position.x = self.x
		odom_word.pose.pose.position.y = self.y
		odom_word.pose.pose.orientation.z = self.final_or
		odom_word.twist.twist.linear.x = linear_vel
		odom_word.twist.twist.angular.z = angular_vel

		self.prev_or = self.final_or

		self.odom_pub.publish(odom_word)

		self.last_time = rospy.get_time()

		

	def __init__(self):
		
		#init params
		self.left_ticks = 0.0
		self.right_ticks = 0.0
		self.imu_or = 0.0
		self.init_imu_or = 0.0
		self.left_ticks_per_rev = 110.0
		self.right_ticks_per_rev = 197.0
		self.wheel_diameter = 0.324
		self.left_old_dist = 0.0
		self.right_old_dist = 0.0
		self.baseline_length = 0.62
		self.enc_or = 0.0
		self.prev_or = 0.0
		self.final_or = 0.0
		self.x = 0.0
		self.y = 0.0
		self.last_time = rospy.get_time()

		self.odom_pub = rospy.Publisher('/odom', Odometry, queue_size=1)

		rospy.Subscriber("/imu", Imu, self.init_imu_callback)
		

		while not rospy.is_shutdown():
			self.pub_odom()


if __name__ == "__main__":
	rospy.init_node('publish_odometry')
	try:
		publish_odom = odom()

	except rospy.ROSInterruptException: pass



