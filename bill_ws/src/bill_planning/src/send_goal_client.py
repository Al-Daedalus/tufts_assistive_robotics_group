#! /usr/bin/env python

import rospy


# Brings in the SimpleActionClient
import actionlib

# Brings in the messages used by the move_base action, including the
# goal message and the result message.
from move_base_msgs.msg import MoveBaseAction, MoveBaseGoal




def sendGoal():
    # Creates the SimpleActionClient, passing the type of the action
    # (FibonacciAction) to the constructor.
    client = actionlib.SimpleActionClient('move_base', MoveBaseAction)

    # Waits until the action server has started up and started
    # listening for goals.
    client.wait_for_server()

    # Creates a goal to send to the action server.
    goal1 = MoveBaseGoal()
    goal1.target_pose.header.frame_id = 'map'

    goal1.target_pose.pose.position.x = -1.99438786507
    goal1.target_pose.pose.position.y = -2.31423902512
    goal1.target_pose.pose.position.z = 0.0

    goal1.target_pose.pose.orientation.x = 0.0
    goal1.target_pose.pose.orientation.y = 0.0
    goal1.target_pose.pose.orientation.z = 0.991058969575
    goal1.target_pose.pose.orientation.w = -0.133424581039


    goal2 = MoveBaseGoal()
    goal2.target_pose.header.frame_id = 'map'

    goal2.target_pose.pose.position.x = -0.616559028625
    goal2.target_pose.pose.position.y = -0.680893063545
    goal2.target_pose.pose.position.z = 0.0

    goal2.target_pose.pose.orientation.x = 0.0
    goal2.target_pose.pose.orientation.y = 0.0
    goal2.target_pose.pose.orientation.z = -0.165727171251
    goal2.target_pose.pose.orientation.w = 0.986171640593


    goal3 = MoveBaseGoal()
    goal3.target_pose.header.frame_id = 'map'

    goal3.target_pose.pose.position.x = -0.409887075424
    goal3.target_pose.pose.position.y = -0.247118830681
    goal3.target_pose.pose.position.z = 0.0

    goal3.target_pose.pose.orientation.x = 0.0
    goal3.target_pose.pose.orientation.y = 0.0
    goal3.target_pose.pose.orientation.z = 0.413264576898
    goal3.target_pose.pose.orientation.w = 0.910610997892





    # Sends the goal to the action server.
    client.send_goal(goal1)
    rospy.loginfo("Goal one sent...")

    # Waits for the server to finish performing the action.
    client.wait_for_result()

    # Sends the goal to the action server.
    client.send_goal(goal2)
    rospy.loginfo("Goal two sent...")

    # Waits for the server to finish performing the action.
    client.wait_for_result()

    # Sends the goal to the action server.
    client.send_goal(goal3)
    rospy.loginfo("Goal three sent...")

    # Waits for the server to finish performing the action.
    client.wait_for_result()



if __name__ == '__main__':
    try:
        # Initializes a rospy node so that the SimpleActionClient can
        # publish and subscribe over ROS.
        rospy.init_node('send_the_goals')
        
        while True:
        	sendGoal()
    except rospy.ROSInterruptException:
        print("program interrupted before completion")