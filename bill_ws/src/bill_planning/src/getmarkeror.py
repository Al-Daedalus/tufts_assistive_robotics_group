#! /usr/bin/env python
import rospy
import tf
from ar_track_alvar_msgs.msg import AlvarMarkers

def callback(data):
	if not data.markers:
		return
	
	for i in range(0, len(data.markers)):
		quat_orr = (data.markers[i].pose.pose.orientation.x,
				data.markers[i].pose.pose.orientation.y,
				data.markers[i].pose.pose.orientation.z,
				data.markers[i].pose.pose.orientation.w)
		euler_orr = tf.transformations.euler_from_quaternion(quat_orr)
		print euler_orr

if __name__ == "__main__":
	rospy.init_node('orr')
	
	rospy.Subscriber("/ar_pose_marker", AlvarMarkers, callback, queue_size=1)
	rospy.spin()
	
	

