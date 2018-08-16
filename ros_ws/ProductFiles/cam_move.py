#! /usr/bin/env python
import rospy
import sys
import baxter_interface
import geometry_msgs.msg
from geometry_msgs.msg import PoseStamped
from positionControl import *
from ar_track_alvar_msgs.msg import AlvarMarkers
import time
import moveit_commander
import tf2_ros
import tf2_geometry_msgs
import tf
import speech_recognition as sr

once = False

class gotomarker:

		#######   FRIDGE OPERATIONS   ##############
		def open_fridge_callback(self,data):
			if not self.fridgeOpened:
				global once
				if not data.markers:
					return
				self.get_fridge_pose(data)


		#detected markers are in an array
		#Here, we search for the marker with ID stored in variable 
		#self.place
		def get_fridge_pose(self, data):
			for i in range(0,len(data.markers)):
				if data.markers[i].id == self.fridge_marker:
					found_object = True
					self.fridge_marker_pose = data.markers[i].pose
					self.transform_fridge_marker_pose_to_robot_rf()
					self.open_fridge()




		#Here, we transform the pose of the marker to the reference frame 'base'
		#which is the reference frame of the entire robot and from which
		#all other poses are relative to
		def transform_fridge_marker_pose_to_robot_rf(self):
			#kinect camera axi is not the same as the robot axis so we could have
			#to perform the necessary transforms first to get both axes aligned
			#and then to transform camera rf to robot's rf
			#goal_pose is the final pose of the marker wrt the robot's rf
			marker_pose = PoseStamped()
			marker_pose.pose.position.y = self.fridge_marker_pose.pose.position.y
			marker_pose.pose.position.x = self.fridge_marker_pose.pose.position.x
			marker_pose.pose.position.z = self.fridge_marker_pose.pose.position.z
			marker_pose.pose.orientation = self.fridge_marker_pose.pose.orientation

			tf_buffer = tf2_ros.Buffer(rospy.Duration(1200.0))
			tf_listener = tf2_ros.TransformListener(tf_buffer)

			transform = tf_buffer.lookup_transform('base', 'camera_link',rospy.Time(0),
				rospy.Duration(1.0))
			self.fridge_goal_pose = tf2_geometry_msgs.do_transform_pose(marker_pose, transform)

			# self.goal_pose.pose.position.y = p.pose.position.y
			# self.goal_pose.pose.position.x = p.pose.position.x
			# self.goal_pose.pose.position.z = p.pose.position.z
			# self.goal_pose.pose.orientation.x = p.pose.orientation.x
			# self.goal_pose.pose.orientation.y = p.pose.orientation.y
			# self.goal_pose.pose.orientation.z = p.pose.orientation.z
			# self.goal_pose.pose.orientation.w = p.pose.orientation.w


		#Calculates the distance between the current pose of the left gripper
		#and the goal_pose on all three axis and instructs the left gripper
		#to move on each of the axis by their respective distances til it gets to the
		#marker
		def open_fridge(self):
			p = get_open_fridge_goal_pose(self.fridge_goal_pose)
			move_to_goal_pose(self.lLimb, p, self.pause_event)
			ang =  self.lLimb.joint_angles()
			ang['left_w1']+=0.8
			move_to_goal_joint_angle(self.lLimb, ang, self.pause_event)
			# playPositionFile('./openFreezer.wp', self.lLimb, self.rLimb, self.pause_event)
			# self.fridgeOpened = True
			rospy.signal_shutdown("moving done")




		##############   MICROWAVE OPERATIONS   #################

		def transform_microwave_marker_pose_to_robot_rf(self):
			#kinect camera axi is not the same as the robot axis so we could have
			#to perform the necessary transforms first to get both axes aligned
			#and then to transform camera rf to robot's rf
			#goal_pose is the final pose of the marker wrt the robot's rf
			marker_pose = PoseStamped()
			marker_pose.pose.position.y = self.microwave_marker_pose.pose.position.y
			marker_pose.pose.position.x = self.microwave_marker_pose.pose.position.x
			marker_pose.pose.position.z = self.microwave_marker_pose.pose.position.z
			marker_pose.pose.orientation = self.microwave_marker_pose.pose.orientation

			tf_buffer = tf2_ros.Buffer(rospy.Duration(1200.0))
			tf_listener = tf2_ros.TransformListener(tf_buffer)

			transform = tf_buffer.lookup_transform('base', 'camera_link',rospy.Time(0),
				rospy.Duration(1.0))
			self.microwave_goal_pose = tf2_geometry_msgs.do_transform_pose(marker_pose, transform)


		def open_microwave_callback(self, data):
			if not data.markers:
				return
			for i in range(0,len(data.markers)):
				if data.markers[i].id == self.microwave_marker:
					self.microwave_marker_pose = data.markers[i].pose
					self.transform_microwave_marker_pose_to_robot_rf()
					# print self.microwave_goal_pose
					self.open_microwave()


		def open_microwave(self):
			p = get_open_microwave_goal_pose(self.microwave_goal_pose)

			# p = PoseStamped()
			# p.pose.position.x = -0.295
			# p.pose.position.y = 1.04755
			# p.pose.position.z = 0.3307

			# p.pose.orientation.x = 0.1018
			# p.pose.orientation.y = 0.976
			# p.pose.orientation.z = 0.1919
			# p.pose.orientation.w = -0.02187

			move_to_goal_pose(self.lLimb, p, self.pause_event)
			ang =  self.lLimb.joint_angles()
			ang['left_w0']+=0.5
			move_to_goal_joint_angle(self.lLimb, ang, self.pause_event)
			# ang =  self.lLimb.joint_angles()
			# ang['left_w1']+=0.8
			# move_to_goal_joint_angle(self.lLimb, ang, self.pause_event)
			# # playPositionFile('./openFreezer.wp', self.lLimb, self.rLimb, self.pause_event)
			# # self.fridgeOpened = True
			rospy.signal_shutdown("moving done")




		#################   BOTTLE OPERATIONS   ######################

		def transform_bottle_marker_pose_to_robot_rf(self):
			#kinect camera axi is not the same as the robot axis so we could have
			#to perform the necessary transforms first to get both axes aligned
			#and then to transform camera rf to robot's rf
			#goal_pose is the final pose of the marker wrt the robot's rf
			marker_pose = PoseStamped()
			marker_pose.pose.position.y = self.bottle_pose.pose.position.y
			marker_pose.pose.position.x = self.bottle_pose.pose.position.x
			marker_pose.pose.position.z = self.bottle_pose.pose.position.z
			marker_pose.pose.orientation = self.bottle_pose.pose.orientation

			tf_buffer = tf2_ros.Buffer(rospy.Duration(1200.0))
			tf_listener = tf2_ros.TransformListener(tf_buffer)

			transform = tf_buffer.lookup_transform('base', 'left_hand_camera',rospy.Time(0),
				rospy.Duration(1.0))
			p = tf2_geometry_msgs.do_transform_pose(marker_pose, transform)

			self.bottle_pose.pose.position.y = p.pose.position.y
			self.bottle_pose.pose.position.x = p.pose.position.x
			self.bottle_pose.pose.position.z = p.pose.position.z
			self.bottle_pose.pose.orientation.x = p.pose.orientation.x
			self.bottle_pose.pose.orientation.y = p.pose.orientation.y
			self.bottle_pose.pose.orientation.z = p.pose.orientation.z
			self.bottle_pose.pose.orientation.w = p.pose.orientation.w



		def pick_bottle_callback(self, data):
			if not data.markers:
				return
			for i in range(0,len(data.markers)):
				if data.markers[i].id == self.bottle_marker:
					self.bottle_pose = data.markers[i].pose
					# print self.bottle_pose
					self.grab_bottle()

		


		def grab_bottle(self):
			# del_x = self.bottle_pose.pose.position.x
			# del_y = self.bottle_pose.pose.position.y
			# del_z = self.bottle_pose.pose.position.z
			'''
			self.transform_bottle_marker_pose_to_robot_rf()
			print "***********************"
			print self.limb.endpoint_pose()
			print "____________________________"
			self.bottle_pose.pose.position.y-=0.1
			print self.bottle_pose

			p = PoseStamped()
			p.pose.position.y = 0.491
			p.pose.position.x = 1.211
			p.pose.position.z = 0.4556

			p.pose.orientation.x = 0.5563
			p.pose.orientation.y = -0.4713
			p.pose.orientation.z = -0.47
			p.pose.orientation.w = 0-0.4979

			move_to_goal_pose(self.lLimb, p, self.pause_event)
			'''
			e1 = 1.15
			s0 = -0.5
			s1 = 0.15

			x = self.bottle_pose.pose.position.x
			y = self.bottle_pose.pose.position.y
			z = self.bottle_pose.pose.position.z

			# if x > 0.05:
			# 	e1-=0.05
			# elif x < 0.03:
			# 	e1 += 0.05

			if y >0.25:
				s1+= 0.05
			elif y < 0.16:
				s1 -= 0.05

			if z>0.25:
				s0+=0.05
			elif z < 0.19:
				s0-= 0.05

			e_out = self.valmap(x, -0.008, 0.111, 0.08, -0.1)
			e1+=e_out 


			goal = {'left_w0': -0.34399519168330406, 
			'left_w1': 0.27880100819817394, 
			'left_w2': -1.5, 
			'left_e0': 1.7725148004015956, 
			'left_e1': e1, 
			'left_s0': s0, 
			'left_s1': s1
			}
		
			print goal
			move_to_goal_joint_angle(self.lLimb, goal, self.pause_event)
			# rospy.signal_shutdown("moving done")

			# moveOnAxis(self.lLimb, 'x', del_x, del_x/4, self.pause_event)
			# time.sleep(2)
			# moveOnAxis(self.lLimb, 'y', del_y, del_y/4, self.pause_event)
			# time.sleep(2)
			# moveOnAxis(self.lLimb, 'z', del_z-0.07, del_z/4, self.pause_event)
			# time.sleep(2)

			# rospy.signal_shutdown("moving done")

			# if moveOnAxis(self.lLimb, 'y', y-0.05, y/4, self.pause_event):
			# 	print moveby
			# 	rospy.signal_shutdown("moving done")
			# current_pose = self.limb.endpoint_pose()
			# print "current pose"
			# print current_pose#['position']
			# print "marker pose"
			# print self.goal_pose.pose.position
					
			# 		#setting some offsets to the goal position for our convenience
			# 		goal_pose.pose.position.z -= 0.10
			# 		# goal_pose.pose.position.y -= 0.05

			# 		gripper_pose = self.limb.endpoint_pose()

			# 		goal_pose.pose.orientation.x = gripper_pose['orientation'][0]
			# 		goal_pose.pose.orientation.y = gripper_pose['orientation'][1]
			# 		goal_pose.pose.orientation.z = gripper_pose['orientation'][2]
			# 		goal_pose.pose.orientation.w = gripper_pose['orientation'][3]
					
			# 		#passing the pose goal into the moveit motion planner to plan the trajectory
			# 		left_arm.set_pose_target(goal_pose)
			# 		left_arm.set_start_state_to_current_state()
			# 		left_plan = left_arm.plan()
			# 		print "done planning"

			# 		#executing planned trajectory
			# 		rospy.sleep(5)
			# 		# left_arm.execute(left_plan)
    				
			# if not found_object:
			# 	print "Could not find marker ID "+ str(self.place)





		def move_to_origin(self):
			lLimb = baxter.Limb('left')
			rLimb = baxter.Limb('right')
			fPath = '/'
			pause_event = None
			playPositionFile(fPath, lLimb, rLimb, pause_event)
			rospy.sleep(3)


		def valmap(self,value, istart, istop, ostart, ostop):
  			return ostart + (ostop - ostart) * ((value - istart) / (istop - istart))

		def __init__(self):
			rospy.init_node('gotomarker', disable_signals=True)
			print "What can I do for you"
			self.limb = baxter.Limb('left')
			self.place = 0
			self.baxter_enabler = baxter.RobotEnable(versioned=True)
			self.baxter_enabler.enable()

			self.lLimb = baxter.Limb('left')
			self.rLimb = baxter.Limb('right')
			self.lGripper = baxter.Gripper('left')
			self.rGripper = baxter.Gripper('right')

			# calibrating gripper
			# if not self.lGripper.calibrate():
			#     print("left gripper did not calibrate")
			#     sys.exit()

			self.lGripper.set_holding_force(100)
			self.lGripper.set_moving_force(100)

			self.rGripper.set_holding_force(100)
			self.rGripper.set_moving_force(100)

			self.fridge_goal_pose = PoseStamped()
			self.head = baxter.Head()
			self.marker_pose = None
			# self.head.set_pan(0)

			self.fridgeOpened = False
			self.fridge_marker = 0

			self.bottleGrabbed = False
			self.bottle_marker = 2

			self.microwaveOpened = False
			self.microwave_marker = 1

			self.bottle_pose = None
			self.pause_event = Event()

			self.origin = {'left_w0': -0.34399519168330406, 
			'left_w1': 0.27880100819817394, 
			'left_w2': -0.8222137023065818, 
			'left_e0': 1.7725148004015956, 
			'left_e1': 1.3863351370514427, 
			'left_s0': -0.8179952551398969, 
			'left_s1': -0.40727189918357737
			}

			# print self.lLimb.endpoint_pose()
			# print self.lLimb.joint_angles()
			# move_to_goal_joint_angle(self.lLimb, self.origin, self.pause_event)
			# rospy.Subscriber('/head_kinect/ar_pose_marker', AlvarMarkers, self.open_fridge_callback)
			rospy.Subscriber('/head_kinect/ar_pose_marker', AlvarMarkers, self.open_microwave_callback)
			# move_to_goal_joint_angle(self.lLimb, self.origin, self.pause_event)
			# rospy.Subscriber('/left_hand_camera/ar_pose_marker', AlvarMarkers, self.pick_bottle_callback)
			rospy.spin()
			# if  self.marker_pose != None:
			# 	self.transform_marker_pose_to_robot_rf()
			# 	self.move_to_marker()
			# else:
			# 	print "Didn't get marker pose"
				#rospy.spin()

			# p = PoseStamped()
			# p.pose.position.y = 0.4976
			# p.pose.position.x = 1.215
			# p.pose.position.z = 0.45597

			# p.pose.orientation.x = -0.549
			# p.pose.orientation.y = 0.469
			# p.pose.orientation.z = 0.4772
			# p.pose.orientation.w = 0.5
			
'''
			origin = {'left_w0': -0.34399519168330406, 
			'left_w1': 0.27880100819817394, 
			'left_w2': -0.8222137023065818, 
			'left_e0': 1.7725148004015956, 
			'left_e1': 1.3863351370514427, 
			'left_s0': -0.8179952551398969, 
			'left_s1': -0.40727189918357737
			}

			goal_z = {'left_w0': -0.34399519168330406, 
			'left_w1': 0.27880100819817394, 
			'left_w2': -0.8222137023065818, 
			'left_e0': 1.7725148004015956, 
			'left_e1': 1.3863351370514427, 
			'left_s0': -0.8179952551398969, 
			'left_s1': 0.15
			}

			goal_x = {'left_w0': -0.34399519168330406, 
			'left_w1': 0.27880100819817394, 
			'left_w2': -1.5, 
			'left_e0': 1.7725148004015956, 
			'left_e1': 1.47, 
			'left_s0': -0.8179952551398969, 
			'left_s1': 0.15
			}

			goal_y = {'left_w0': -0.34399519168330406, 
			'left_w1': 0.27880100819817394, 
			'left_w2': -1.5, 
			'left_e0': 1.7725148004015956, 
			'left_e1': 1.15, 
			'left_s0': -0.5, 
			'left_s1': 0.15
			}
			# move_to_goal_pose(self.lLimb, p, self.pause_event)
			move_to_goal_joint_angle(self.lLimb, origin, self.pause_event)

			# print self.lLimb.joint_angles()
'''
			


if __name__=="__main__":
	
	try:
		go = gotomarker()

	except rospy.ROSInterruptException: pass


