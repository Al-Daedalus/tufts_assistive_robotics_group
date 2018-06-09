roscore &
rosrun rosserial_python serial_node.py /dev/ttyACM0 &
source ./devel/setup.bash &
roslaunch bill_teleop_joy bill_joy.launch 

