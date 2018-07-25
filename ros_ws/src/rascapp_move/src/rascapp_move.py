#! /usr/bin/env python

import sys
import copy
import rospy
import moveit_commander
import moveit_msgs.msg 
import geometry_msgs.msg 

moveit_commander.roscpp_initialize(sys.argv)
rospy.init_node('move_tutorial', anonymous=True)

robot = moveit_commander.RobotCommander()
scene = moveit_commander.PlanningSceneInterface()
group = moveit_commander.MoveGroupCommander("left_arm")
display_trajectory_publisher = rospy.Publisher('/move_group/display_planned_path', moveit_msgs.msg.DisplayTrajectory, queue_size=1)

pose_target = geometry_msgs.msg.Pose()
pose_target.orientation.w = 0.1
pose_target.position.x = 0.4
pose_target.position.y = -0.05
pose_target.position.z = -0.03
# p = group.get_current_pose()
# group.set_pose_target(p)


# plan1 = group.plan()
# print "Reference frame: %s" % group.get_planning_frame()
# print "End effector: %s" % group.get_end_effector_link()
# print "Current Pose:"
print group.get_current_pose()

rospy.sleep(5)

moveit_commander.roscpp_shutdown()