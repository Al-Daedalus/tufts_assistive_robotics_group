from multiprocessing import Process
from threading import (
    Thread,
    activeCount,
    Event as TEvent,
    enumerate,
)

import ctypes
import rospy
from std_msgs.msg import (
    UInt16,
    Bool,
)
import baxter_interface as baxter

from baxterGUI import lLimb, rLimb, lGripper, rGripper, lastAliveName

# Helper functions #
def terminate_thread(thread):
    if not thread.isAlive():
        return
    exc = ctypes.py_object(KeyboardInterrupt)
    res = ctypes.pythonapi.PyThreadState_SetAsyncExc(
    ctypes.c_long(thread.ident), exc)
    if res == 0:
        raise ValueError("nonexistent thread id")
    elif res > 1:
        ctypes.pythonapi.PyThreadState_SetAsyncExc(thread.ident, None)
        raise SystemError("PyThreadState_SetAsyncExc failed")


def runTask(task_target, task_name, args):
    global task, lLimb, rLimb, pause_event, rawCommand
    task = Thread(target=task_target, args=args,
                  name=task_name)
    print(task.name)
    pause_event.clear()
    task.daemon = True
    task.start()
    update_command_box(task_name)
    rawCommand = ""

def identifyTask():
    print("stub for now")