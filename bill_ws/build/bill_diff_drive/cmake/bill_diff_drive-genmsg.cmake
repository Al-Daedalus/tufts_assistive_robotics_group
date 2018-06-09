# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "bill_diff_drive: 1 messages, 0 services")

set(MSG_I_FLAGS "-Ibill_diff_drive:/home/bill/bill_ros/bill_ws/src/bill_diff_drive/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(bill_diff_drive_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/bill/bill_ros/bill_ws/src/bill_diff_drive/msg/Diff_drive.msg" NAME_WE)
add_custom_target(_bill_diff_drive_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "bill_diff_drive" "/home/bill/bill_ros/bill_ws/src/bill_diff_drive/msg/Diff_drive.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(bill_diff_drive
  "/home/bill/bill_ros/bill_ws/src/bill_diff_drive/msg/Diff_drive.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/bill_diff_drive
)

### Generating Services

### Generating Module File
_generate_module_cpp(bill_diff_drive
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/bill_diff_drive
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(bill_diff_drive_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(bill_diff_drive_generate_messages bill_diff_drive_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bill/bill_ros/bill_ws/src/bill_diff_drive/msg/Diff_drive.msg" NAME_WE)
add_dependencies(bill_diff_drive_generate_messages_cpp _bill_diff_drive_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(bill_diff_drive_gencpp)
add_dependencies(bill_diff_drive_gencpp bill_diff_drive_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS bill_diff_drive_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(bill_diff_drive
  "/home/bill/bill_ros/bill_ws/src/bill_diff_drive/msg/Diff_drive.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/bill_diff_drive
)

### Generating Services

### Generating Module File
_generate_module_eus(bill_diff_drive
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/bill_diff_drive
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(bill_diff_drive_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(bill_diff_drive_generate_messages bill_diff_drive_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bill/bill_ros/bill_ws/src/bill_diff_drive/msg/Diff_drive.msg" NAME_WE)
add_dependencies(bill_diff_drive_generate_messages_eus _bill_diff_drive_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(bill_diff_drive_geneus)
add_dependencies(bill_diff_drive_geneus bill_diff_drive_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS bill_diff_drive_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(bill_diff_drive
  "/home/bill/bill_ros/bill_ws/src/bill_diff_drive/msg/Diff_drive.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/bill_diff_drive
)

### Generating Services

### Generating Module File
_generate_module_lisp(bill_diff_drive
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/bill_diff_drive
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(bill_diff_drive_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(bill_diff_drive_generate_messages bill_diff_drive_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bill/bill_ros/bill_ws/src/bill_diff_drive/msg/Diff_drive.msg" NAME_WE)
add_dependencies(bill_diff_drive_generate_messages_lisp _bill_diff_drive_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(bill_diff_drive_genlisp)
add_dependencies(bill_diff_drive_genlisp bill_diff_drive_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS bill_diff_drive_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(bill_diff_drive
  "/home/bill/bill_ros/bill_ws/src/bill_diff_drive/msg/Diff_drive.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/bill_diff_drive
)

### Generating Services

### Generating Module File
_generate_module_nodejs(bill_diff_drive
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/bill_diff_drive
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(bill_diff_drive_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(bill_diff_drive_generate_messages bill_diff_drive_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bill/bill_ros/bill_ws/src/bill_diff_drive/msg/Diff_drive.msg" NAME_WE)
add_dependencies(bill_diff_drive_generate_messages_nodejs _bill_diff_drive_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(bill_diff_drive_gennodejs)
add_dependencies(bill_diff_drive_gennodejs bill_diff_drive_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS bill_diff_drive_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(bill_diff_drive
  "/home/bill/bill_ros/bill_ws/src/bill_diff_drive/msg/Diff_drive.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/bill_diff_drive
)

### Generating Services

### Generating Module File
_generate_module_py(bill_diff_drive
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/bill_diff_drive
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(bill_diff_drive_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(bill_diff_drive_generate_messages bill_diff_drive_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bill/bill_ros/bill_ws/src/bill_diff_drive/msg/Diff_drive.msg" NAME_WE)
add_dependencies(bill_diff_drive_generate_messages_py _bill_diff_drive_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(bill_diff_drive_genpy)
add_dependencies(bill_diff_drive_genpy bill_diff_drive_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS bill_diff_drive_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/bill_diff_drive)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/bill_diff_drive
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(bill_diff_drive_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/bill_diff_drive)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/bill_diff_drive
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(bill_diff_drive_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/bill_diff_drive)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/bill_diff_drive
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(bill_diff_drive_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/bill_diff_drive)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/bill_diff_drive
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(bill_diff_drive_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/bill_diff_drive)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/bill_diff_drive\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/bill_diff_drive
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(bill_diff_drive_generate_messages_py std_msgs_generate_messages_py)
endif()
