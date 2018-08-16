execute_process(COMMAND "/home/bill/bill_ros/bill_ws/build/master_sync_fkie/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/bill/bill_ros/bill_ws/build/master_sync_fkie/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
