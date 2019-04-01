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
from math import hypot, atan2, fabs, sqrt
import sys


class move_robot:
	def robot_pose_callback(self,pose):
		self.robot_pose = pose
		if not self.done:
			self.goal_pose.pose.position.x = pose.pose.position.x
			self.goal_pose.pose.position.y = pose.pose.position.y
			self.goal_pose.pose.position.z = pose.pose.position.z
			self.goal_pose.pose.orientation.x = pose.pose.orientation.x
			self.goal_pose.pose.orientation.y = pose.pose.orientation.y
			self.goal_pose.pose.orientation.z = pose.pose.orientation.z
			self.goal_pose.pose.orientation.w = pose.pose.orientation.w
			#self.goal_pose.pose.position.x+=self.delta
			self.goal_pose.pose.position.y-=self.delta
			print(pose.pose.position.y)
			print ('goal is', self.goal_pose.pose.position.y)
			self.done = True
		if not self.finished:
			self.move_to_goal()


	def calculate_distance(self, pose1, pose2):
		return sqrt((pose1.pose.position.x - pose2.pose.position.x)**2+
			(pose1.pose.position.y - pose2.pose.position.y)**2)


	def calculate_angle_diff(self, pose1, pose2):
		return atan2((pose2.pose.position.y - pose1.pose.position.y), 
			(pose2.pose.position.x - pose1.pose.position.x))

	def current_orientation(self):
		quats = [self.robot_pose.pose.orientation.x, self.robot_pose.pose.orientation.y,
		self.robot_pose.pose.orientation.z, self.robot_pose.pose.orientation.w]
		(_, _, yaw) = euler_from_quaternion(quats)
		return yaw


	def move_back(self, period):
		print('moving back')
		vel = Twist()
		vel.linear.x = -0.5
		self.vel_pub.publish(vel)
		time.sleep(period)
		self.vel_pub.publish(self.stop)
		time.sleep(1)

	def move_forward(self, period):
		#print('moving forward')
		vel = Twist()
		vel.linear.x = 3
		self.vel_pub.publish(vel)
		time.sleep(period)
		self.vel_pub.publish(self.stop)
		time.sleep(1.5)

	def turn_left(self, period):
		print('moving left')
		vel = Twist()
		vel.angular.z = -2
		self.vel_pub.publish(vel)
		time.sleep(period)
		self.vel_pub.publish(self.stop)

	def turn_right(self, period):
		print('moving right')
		vel = Twist()
		vel.angular.z = 2
		self.vel_pub.publish(vel)
		time.sleep(period)
		self.vel_pub.publish(self.stop)



	def move_to_goal(self):
		#self.move_back(1)
		if self.calculate_distance(self.robot_pose, self.goal_pose) > self.dist_threshold:
			print ('current y',self.robot_pose.pose.position.y)
			deltaOrientation = self.calculate_angle_diff(self.robot_pose, self.goal_pose)
			goalOrientation = self.current_orientation() + deltaOrientation

			if fabs(goalOrientation - self.current_orientation()) > self.orient_threshold:
				print('orientation', fabs(goalOrientation - self.current_orientation()))
				# if (self.goal_pose.pose.position.x > self.robot_pose.pose.position.x): 
				# 	self.turn_left(1)
				# 	time.sleep(1)
				# else:
				# 	self.turn_right(1)
				# 	time.sleep(1)

			# 	deltaOrientation = self.calculate_angle_diff(self.robot_pose, self.goal_pose)
			# 	goalOrientation = self.current_orientation() + deltaOrientation

			self.move_forward(0.6)
		else: 
			self.finished = True
			print('finished')


	def __init__(self):
		self.stop = Twist()
		self.dist_threshold = 0.10
		self.orient_threshold = 0.4
		self.delta = float(sys.argv[1])
		self.goal_pose = PoseStamped()
		# pose = PoseStamped()
		# pose.pose.position.x = 2.285
		# pose.pose.position.y = 12.082
		# pose.pose.position.x = -1.116
		# pose.pose.orientation.x = 0.0079
		# pose.pose.orientation.y = -0.0049
		# pose.pose.orientation.z = -0.9634
		# pose.pose.orientation.w = -0.2676
		# pose.pose.position.x+=delta
		# pose.pose.position.y+=delta
		# self.goal_pose = pose
		self.vel_pub = rospy.Publisher('/cmd_vel',Twist, queue_size=10)
		self.done = False
		self.finished = False
		rospy.Subscriber('/pose', PoseStamped, self.robot_pose_callback)
		#rospy.Subscriber('/goal_pose', PoseStamped, self.move_to_goal)
		
		rospy.spin()


if __name__ == "__main__":
	rospy.init_node('go_to_pose')
	try:
		go = move_robot()
	except rospy.ROSInterruptException: pass



