#!/usr/bin/env python
# -*- coding: utf-8 -*-

import rospy
import numpy
import tf

from os.path import expanduser
from cv_bridge import CvBridge, CvBridgeError
from sensor_msgs import point_cloud2 as pc2
from sensor_msgs.msg import Image, PointCloud2
from std_msgs.msg import Float32
import cv2
import numpy as np 

class Floor_Object_Pose:
	def thresh(self,gray):
	    ret,imgt=cv2.threshold(gray,127,255,cv2.THRESH_BINARY)
	    imgt = cv2.bitwise_not(imgt)
	    imgt = cv2.erode(imgt, None, iterations=4)
	    imgt = cv2.dilate(imgt, None, iterations=6)
	    return imgt


	def matchandfind(self,imgt):
	    offset=20
	    _,cnts, _ = cv2.findContours(imgt, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
	    cnts = sorted(cnts, key=cv2.contourArea, reverse=True)
	    if len(cnts):    
	        c = cnts[0]      
	        rect = cv2.minAreaRect(c)
	        box = np.int0(cv2.boxPoints(rect))
	        cv2.drawContours(self.scene, [box], -1, (0, 240, 0), 3)
	        
	        return rect, imgt


	def run(self):
		while not rospy.is_shutdown():
			if self.current_image is not None:
				try:
					#(trans,_) = self.tf_listener.lookupTransform('/camera_link', rospy.Time(0))
					self.scene = self.bridge.imgmsg_to_cv2(self.current_image, 'passthrough')
					rect, image = self.detect_object(self.scene)
					self.imagepub.publish(self.bridge.cv2_to_imgmsg(self.scene, 'rgb8'))
					cv2.imshow('Test',self.scene)
					if cv2.waitKey(1) &0xFF == ord('q'):
					    break
					angle = Float32()
					angle.data = rect[2]
					self.anglepub.publish(angle)

					center = rect[0]
					if self.current_pc is None:
						rospy.loginfo('No point cloud information available')

					else:
						pc_list = list(pc2.read_points(self.current_pc, skip_nans=True, field_names=('x', 'y', 'z'), uvs=[(int(center[0]), int(center[1]))]))

						if len(pc_list) > 0:
							tf_id = 'floor_object'
							point_x, point_y, point_z = pc_list[0]

							object_tf = [point_z, -point_x, -point_y]
							frame = '/camera_link'

							#object_tf = numpy.array(trans) + object_tf
							self.tfpub.sendTransform((object_tf),tf.transformations.quaternion_from_euler(0,0,0), rospy.Time.now(), tf_id, frame)

				except CvBridgeError as e:
					print(e)
				except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException) as e:
					print(e)


	def detect_object(self, img):
		gray= cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)     
		imgr=self.thresh(gray)
		rect,image = self.matchandfind(imgr)
		return rect, image


	def __init__(self):
		self.tf_listener = tf.TransformListener()
		self.bridge = CvBridge()
		self.current_image = None
		self.current_pc = None
		self.scene = None
		self.tfpub = tf.TransformBroadcaster()
		rospy.Subscriber('/camera/rgb/image_raw', Image, self.image_callback)
		rospy.Subscriber('/camera/depth/points', PointCloud2, self.pc_callback)
		self.imagepub = rospy.Publisher('/floor_object/image', Image, queue_size=10)
		self.anglepub = rospy.Publisher('/floor_object/angle', Float32, queue_size=10)


	def image_callback(self, image):
		self.current_image = image


	def pc_callback(self, pc):
		self.current_pc = pc



if __name__ == '__main__':
	rospy.init_node('floor_object_pose_publisher', log_level = rospy.INFO)

	try:
		f = Floor_Object_Pose()
		f.run()
	except KeyboardInterrupt:
		rospy.loginfo('Shutting down')







'''
element = cv2.getStructuringElement(cv2.MORPH_RECT,(3, 3))
cv2.namedWindow('Test')
cap = cv2.VideoCapture(1)
while cap.isOpened():
    ret,img = cap.read()
    img = cv2.addWeighted(img,1,np.zeros(img.shape,img.dtype),0,85)
    img=img[50:430, 50:590]
    main(img)
    cv2.imshow('Test',img)
    if cv2.waitKey(1) &0xFF == ord('q'):
        break
cap.release()
cv2.destroyAllWindows()
'''