execute_process(COMMAND "/home/bill/bill_ros/ros_ws/build/baxter_tools/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/bill/bill_ros/ros_ws/build/baxter_tools/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
