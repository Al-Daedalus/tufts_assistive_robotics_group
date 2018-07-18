#! /usr/bin/env python

import rospy
from ar_track_alvar_msgs.msg import AlvarMarkers
from gtts import gTTS
import playsound
import time

kitchen = False
bed = False
bath = False

def callback(data):
    global bath
    global kitchen
    global bed
    if not data.markers:
        return
    elif data.markers[0].id == 3:
        if data.markers[0].pose.pose.position.x < 1:
            
            if not kitchen:
                tts = gTTS(text='I am now in the kitchen. Wanna get some food', lang='en')
                tts.save("word1.mp3")
                playsound.playsound("word1.mp3", True)
                time.sleep(5)
                kitchen = True
                bath = False
                bed = False
    elif data.markers[0].id == 4:

        if not bath:
            if data.markers[0].pose.pose.position.x < 1:
                tts = gTTS(text='I am now in the bathroom to take a shower', lang='en')
                tts.save("word2.mp3")
                playsound.playsound("word2.mp3", True)
                time.sleep(5)
                bath = True
                kitchen = False
                bed = False

    elif data.markers[0].id == 5:
        if data.markers[0].pose.pose.position.x < 1:
            if not bed:
                tts = gTTS(text='In the bedroom  Goodnight everyone', lang='en')
                tts.save("word3.mp3")
                playsound.playsound("word3.mp3", True)
                time.sleep(5)
                bed = True
                kitchen = False
                bath = False

        
    
def listener():
    rospy.init_node('place', anonymous=True)

    rospy.Subscriber("/ar_pose_marker", AlvarMarkers, callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

#if __name__ == '__main__':
while True:
    listener()


