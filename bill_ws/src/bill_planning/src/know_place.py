#! /usr/bin/env python

import rospy
from ar_track_alvar_msgs import AlvarMarkers
from gtts import gTTS
import playsound
import time


def callback(data):
    if data.id == 3:
        if data.pose.pose.position.x < 1:
            tts = gTTS(text='I am now in the kitchen. Wanna get some food', lang='en')
            tts.save("word.mp3")
            playsound.playsound("word.mp3", True)
            time.sleep(5)
    if data.id == 4:
        if data.pose.pose.position.x < 1:
            tts = gTTS(text='I am now in the kitchen. Wanna take a shit', lang='en')
            tts.save("word.mp3")
            playsound.playsound("word.mp3", True)
            time.sleep(5)
    if data.id == 5:
        if data.pose.pose.position.x < 1:
            tts = gTTS(text='In the bedroom. Goodnight you all', lang='en')
            tts.save("word.mp3")
            playsound.playsound("word.mp3", True)
            time.sleep(5)

        
    
def listener():
    rospy.init_node('place', anonymous=True)

    rospy.Subscriber("/ar_pose_marker", AlvarMarkers, callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    listener()


