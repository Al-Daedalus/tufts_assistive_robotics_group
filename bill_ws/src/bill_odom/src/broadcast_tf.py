#!/usr/bin/env python

import tf
import rospy
import time
from nav_msgs.msg import Odometry 

def broadcast_odom(odom):
	br = tf.TransformBroadcaster()
	br.sendTransform((odom.pose.pose.position.x, 
		odom.pose.pose.position.y, odom.pose.pose.position.z), 
		(odom.pose.pose.orientation.x,odom.pose.pose.orientation.y,
		odom.pose.pose.orientation.z, odom.pose.pose.orientation.w),
		rospy.Time.now(), 'base_link', 'odom')


if __name__=='__main__':
	rospy.init_node('broadcast_baselink_to_odom_tf')
	rospy.Subscriber("/odom", Odometry, broadcast_odom, queue_size=1)
	rospy.spin()