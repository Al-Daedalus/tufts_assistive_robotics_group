#! /usr/bin/env python

import speech_recognition as sr

rawCommand=""

# def heard(recognizer, audio):
# 	# Defining Commands to be accepted
# 	global t2s
# 	credsJson = ""
# 	with open('baxter-helper-bot-gspeechcreds.json', 'r') as gspeechcreds:
# 		credsJson = gspeechcreds.read()
	
# 	sens = 1
# 	commands = ["move", "arm", "forward", "backward", "left", "right", "up", "down", 
# 				"higher", "lower", "close", "hand", "open", "stop", "stop", "stop", 
#                 "faster", "slower", "fridge", "zero", "get", "water bottle", "fridge", 
#                 "place on", "table", "fridge is open", "holding something", "fridge is closed", 
#                 "hand is empty", "microwave", "start", "turn off", "continue", "cook",
#                 "put", "food", "is open", "get the food"]
# 	print('trying to recognize')
# 	try:
# 		commandIter = [command[0] for command in commands]
# 		global rawCommand
# 		rawCommand = recognizer.recognize_google_cloud(audio_data=audio, language='en-US', credentials_json=credsJson, preferred_phrases=commands)
# 		print(rawCommand)
# 	except sr.UnknownValueError:
# 		print("could not understand audio")
# 		pass
# 	except sr.RequestError as e:
# 		print("Recognition error; {}".format(e))


r = sr.Recognizer()
m = sr.Microphone()
r.pause_threshold = .5
r.dynamic_energy_threshold = False

with m as source:
	r.adjust_for_ambient_noise(source, duration=5)
	print("speak")
	audio = r.listen(source)

# with open('baxter-helper-bot-gspeechcreds.json', 'r') as gspeechcreds:
#  		credsJson = gspeechcreds.read()
# credsJson = GOOGLE_APPLICATION_CREDENTIALS
print("listening")
commands = ["move arm forward", "backward", "left", "right", "up", "down", 
				"higher", "lower", "close", "hand", "open", "stop", "stop", "stop", 
                "faster", "slower", "open the fridge", "zero", "get", "water bottle", "fridge", 
                "place on", "table", "fridge is open", "holding something", "fridge is closed", 
                "hand is empty", "put food in the microwave", "start", "turn off", "continue", "cook",
                "put", "food", "is open", "get the food"]
print('trying to recognize')
try:
	# commandIter = [command[0] for command in commands]
	rawCommand = r.recognize_google_cloud(audio_data=audio, language='en-US', preferred_phrases=commands)
	print(rawCommand)
except sr.UnknownValueError:
	print("could not understand audio")
	pass
except sr.RequestError as e:
	print("Recognition error; {}".format(e))


# while True:
# 	with m as source:
# 		r.adjust_for_ambient_noise(source, 1)
# 	stopListening = r.listen_in_background(m, heard, phrase_time_limit=4)
# 	print rawCommand
