// Generated by gencpp from file object_recognition_msgs/ObjectRecognitionAction.msg
// DO NOT EDIT!


#ifndef OBJECT_RECOGNITION_MSGS_MESSAGE_OBJECTRECOGNITIONACTION_H
#define OBJECT_RECOGNITION_MSGS_MESSAGE_OBJECTRECOGNITIONACTION_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <object_recognition_msgs/ObjectRecognitionActionGoal.h>
#include <object_recognition_msgs/ObjectRecognitionActionResult.h>
#include <object_recognition_msgs/ObjectRecognitionActionFeedback.h>

namespace object_recognition_msgs
{
template <class ContainerAllocator>
struct ObjectRecognitionAction_
{
  typedef ObjectRecognitionAction_<ContainerAllocator> Type;

  ObjectRecognitionAction_()
    : action_goal()
    , action_result()
    , action_feedback()  {
    }
  ObjectRecognitionAction_(const ContainerAllocator& _alloc)
    : action_goal(_alloc)
    , action_result(_alloc)
    , action_feedback(_alloc)  {
  (void)_alloc;
    }



   typedef  ::object_recognition_msgs::ObjectRecognitionActionGoal_<ContainerAllocator>  _action_goal_type;
  _action_goal_type action_goal;

   typedef  ::object_recognition_msgs::ObjectRecognitionActionResult_<ContainerAllocator>  _action_result_type;
  _action_result_type action_result;

   typedef  ::object_recognition_msgs::ObjectRecognitionActionFeedback_<ContainerAllocator>  _action_feedback_type;
  _action_feedback_type action_feedback;





  typedef boost::shared_ptr< ::object_recognition_msgs::ObjectRecognitionAction_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::object_recognition_msgs::ObjectRecognitionAction_<ContainerAllocator> const> ConstPtr;

}; // struct ObjectRecognitionAction_

typedef ::object_recognition_msgs::ObjectRecognitionAction_<std::allocator<void> > ObjectRecognitionAction;

typedef boost::shared_ptr< ::object_recognition_msgs::ObjectRecognitionAction > ObjectRecognitionActionPtr;
typedef boost::shared_ptr< ::object_recognition_msgs::ObjectRecognitionAction const> ObjectRecognitionActionConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::object_recognition_msgs::ObjectRecognitionAction_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::object_recognition_msgs::ObjectRecognitionAction_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace object_recognition_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'shape_msgs': ['/opt/ros/kinetic/share/shape_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'object_recognition_msgs': ['/home/bill/bill_ros/bill_ws/devel/share/object_recognition_msgs/msg', '/home/bill/bill_ros/bill_ws/src/object_recognition_msgs/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::object_recognition_msgs::ObjectRecognitionAction_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::object_recognition_msgs::ObjectRecognitionAction_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::object_recognition_msgs::ObjectRecognitionAction_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::object_recognition_msgs::ObjectRecognitionAction_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::object_recognition_msgs::ObjectRecognitionAction_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::object_recognition_msgs::ObjectRecognitionAction_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::object_recognition_msgs::ObjectRecognitionAction_<ContainerAllocator> >
{
  static const char* value()
  {
    return "7d8979a0cf97e5078553ee3efee047d2";
  }

  static const char* value(const ::object_recognition_msgs::ObjectRecognitionAction_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x7d8979a0cf97e507ULL;
  static const uint64_t static_value2 = 0x8553ee3efee047d2ULL;
};

template<class ContainerAllocator>
struct DataType< ::object_recognition_msgs::ObjectRecognitionAction_<ContainerAllocator> >
{
  static const char* value()
  {
    return "object_recognition_msgs/ObjectRecognitionAction";
  }

  static const char* value(const ::object_recognition_msgs::ObjectRecognitionAction_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::object_recognition_msgs::ObjectRecognitionAction_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
\n\
ObjectRecognitionActionGoal action_goal\n\
ObjectRecognitionActionResult action_result\n\
ObjectRecognitionActionFeedback action_feedback\n\
\n\
================================================================================\n\
MSG: object_recognition_msgs/ObjectRecognitionActionGoal\n\
# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
\n\
Header header\n\
actionlib_msgs/GoalID goal_id\n\
ObjectRecognitionGoal goal\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: actionlib_msgs/GoalID\n\
# The stamp should store the time at which this goal was requested.\n\
# It is used by an action server when it tries to preempt all\n\
# goals that were requested before a certain time\n\
time stamp\n\
\n\
# The id provides a way to associate feedback and\n\
# result message with specific goal requests. The id\n\
# specified must be unique.\n\
string id\n\
\n\
\n\
================================================================================\n\
MSG: object_recognition_msgs/ObjectRecognitionGoal\n\
# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
# Optional ROI to use for the object detection\n\
bool use_roi\n\
float32[] filter_limits\n\
\n\
================================================================================\n\
MSG: object_recognition_msgs/ObjectRecognitionActionResult\n\
# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
\n\
Header header\n\
actionlib_msgs/GoalStatus status\n\
ObjectRecognitionResult result\n\
\n\
================================================================================\n\
MSG: actionlib_msgs/GoalStatus\n\
GoalID goal_id\n\
uint8 status\n\
uint8 PENDING         = 0   # The goal has yet to be processed by the action server\n\
uint8 ACTIVE          = 1   # The goal is currently being processed by the action server\n\
uint8 PREEMPTED       = 2   # The goal received a cancel request after it started executing\n\
                            #   and has since completed its execution (Terminal State)\n\
uint8 SUCCEEDED       = 3   # The goal was achieved successfully by the action server (Terminal State)\n\
uint8 ABORTED         = 4   # The goal was aborted during execution by the action server due\n\
                            #    to some failure (Terminal State)\n\
uint8 REJECTED        = 5   # The goal was rejected by the action server without being processed,\n\
                            #    because the goal was unattainable or invalid (Terminal State)\n\
uint8 PREEMPTING      = 6   # The goal received a cancel request after it started executing\n\
                            #    and has not yet completed execution\n\
uint8 RECALLING       = 7   # The goal received a cancel request before it started executing,\n\
                            #    but the action server has not yet confirmed that the goal is canceled\n\
uint8 RECALLED        = 8   # The goal received a cancel request before it started executing\n\
                            #    and was successfully cancelled (Terminal State)\n\
uint8 LOST            = 9   # An action client can determine that a goal is LOST. This should not be\n\
                            #    sent over the wire by an action server\n\
\n\
#Allow for the user to associate a string with GoalStatus for debugging\n\
string text\n\
\n\
\n\
================================================================================\n\
MSG: object_recognition_msgs/ObjectRecognitionResult\n\
# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
# Send the found objects, see the msg files for docs\n\
object_recognition_msgs/RecognizedObjectArray recognized_objects\n\
\n\
================================================================================\n\
MSG: object_recognition_msgs/RecognizedObjectArray\n\
##################################################### HEADER ###########################################################\n\
Header header\n\
\n\
# This message type describes a potential scene configuration: a set of objects that can explain the scene\n\
object_recognition_msgs/RecognizedObject[] objects\n\
\n\
##################################################### SEARCH ###########################################################\n\
\n\
# The co-occurrence matrix between the recognized objects\n\
float32[] cooccurrence\n\
\n\
================================================================================\n\
MSG: object_recognition_msgs/RecognizedObject\n\
##################################################### HEADER ###########################################################\n\
\n\
# The header frame corresponds to the pose frame, NOT the point_cloud frame.\n\
Header header\n\
\n\
################################################## OBJECT INFO #########################################################\n\
\n\
# Contains information about the type and the position of a found object\n\
# Some of those fields might not be filled because the used techniques do not fill them or because the user does not\n\
# request them\n\
\n\
# The type of the found object\n\
object_recognition_msgs/ObjectType type\n\
\n\
#confidence: how sure you are it is that object and not another one.\n\
# It is between 0 and 1 and the closer to one it is the better\n\
float32 confidence\n\
\n\
################################################ OBJECT CLUSTERS #######################################################\n\
\n\
# Sometimes you can extract the 3d points that belong to the object, in the frames of the original sensors\n\
# (it is an array as you might have several sensors)\n\
sensor_msgs/PointCloud2[] point_clouds\n\
\n\
# Sometimes, you can only provide a bounding box/shape, even in 3d\n\
# This is in the pose frame\n\
shape_msgs/Mesh bounding_mesh\n\
\n\
# Sometimes, you only have 2d input so you can't really give a pose, you just get a contour, or a box\n\
# The last point will be linked to the first one automatically\n\
geometry_msgs/Point[] bounding_contours\n\
\n\
#################################################### POSE INFO #########################################################\n\
\n\
# This is the result that everybody expects : the pose in some frame given with the input. The units are radian/meters\n\
# as usual\n\
geometry_msgs/PoseWithCovarianceStamped pose\n\
\n\
================================================================================\n\
MSG: object_recognition_msgs/ObjectType\n\
################################################## OBJECT ID #########################################################\n\
\n\
# Contains information about the type of a found object. Those two sets of parameters together uniquely define an\n\
# object\n\
\n\
# The key of the found object: the unique identifier in the given db\n\
string key\n\
\n\
# The db parameters stored as a JSON/compressed YAML string. An object id does not make sense without the corresponding\n\
# database. E.g., in object_recognition, it can look like: \"{'type':'CouchDB', 'root':'http://localhost'}\"\n\
# There is no conventional format for those parameters and it's nice to keep that flexibility.\n\
# The object_recognition_core as a generic DB type that can read those fields\n\
# Current examples:\n\
# For CouchDB:\n\
#   type: 'CouchDB'\n\
#   root: 'http://localhost:5984'\n\
#   collection: 'object_recognition'\n\
# For SQL household database:\n\
#   type: 'SqlHousehold'\n\
#   host: 'wgs36'\n\
#   port: 5432\n\
#   user: 'willow'\n\
#   password: 'willow'\n\
#   name: 'household_objects'\n\
#   module: 'tabletop'\n\
string db\n\
\n\
================================================================================\n\
MSG: sensor_msgs/PointCloud2\n\
# This message holds a collection of N-dimensional points, which may\n\
# contain additional information such as normals, intensity, etc. The\n\
# point data is stored as a binary blob, its layout described by the\n\
# contents of the \"fields\" array.\n\
\n\
# The point cloud data may be organized 2d (image-like) or 1d\n\
# (unordered). Point clouds organized as 2d images may be produced by\n\
# camera depth sensors such as stereo or time-of-flight.\n\
\n\
# Time of sensor data acquisition, and the coordinate frame ID (for 3d\n\
# points).\n\
Header header\n\
\n\
# 2D structure of the point cloud. If the cloud is unordered, height is\n\
# 1 and width is the length of the point cloud.\n\
uint32 height\n\
uint32 width\n\
\n\
# Describes the channels and their layout in the binary data blob.\n\
PointField[] fields\n\
\n\
bool    is_bigendian # Is this data bigendian?\n\
uint32  point_step   # Length of a point in bytes\n\
uint32  row_step     # Length of a row in bytes\n\
uint8[] data         # Actual point data, size is (row_step*height)\n\
\n\
bool is_dense        # True if there are no invalid points\n\
\n\
================================================================================\n\
MSG: sensor_msgs/PointField\n\
# This message holds the description of one point entry in the\n\
# PointCloud2 message format.\n\
uint8 INT8    = 1\n\
uint8 UINT8   = 2\n\
uint8 INT16   = 3\n\
uint8 UINT16  = 4\n\
uint8 INT32   = 5\n\
uint8 UINT32  = 6\n\
uint8 FLOAT32 = 7\n\
uint8 FLOAT64 = 8\n\
\n\
string name      # Name of field\n\
uint32 offset    # Offset from start of point struct\n\
uint8  datatype  # Datatype enumeration, see above\n\
uint32 count     # How many elements in the field\n\
\n\
================================================================================\n\
MSG: shape_msgs/Mesh\n\
# Definition of a mesh\n\
\n\
# list of triangles; the index values refer to positions in vertices[]\n\
MeshTriangle[] triangles\n\
\n\
# the actual vertices that make up the mesh\n\
geometry_msgs/Point[] vertices\n\
\n\
================================================================================\n\
MSG: shape_msgs/MeshTriangle\n\
# Definition of a triangle's vertices\n\
uint32[3] vertex_indices\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/PoseWithCovarianceStamped\n\
# This expresses an estimated pose with a reference coordinate frame and timestamp\n\
\n\
Header header\n\
PoseWithCovariance pose\n\
\n\
================================================================================\n\
MSG: geometry_msgs/PoseWithCovariance\n\
# This represents a pose in free space with uncertainty.\n\
\n\
Pose pose\n\
\n\
# Row-major representation of the 6x6 covariance matrix\n\
# The orientation parameters use a fixed-axis representation.\n\
# In order, the parameters are:\n\
# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)\n\
float64[36] covariance\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of position and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
\n\
================================================================================\n\
MSG: object_recognition_msgs/ObjectRecognitionActionFeedback\n\
# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
\n\
Header header\n\
actionlib_msgs/GoalStatus status\n\
ObjectRecognitionFeedback feedback\n\
\n\
================================================================================\n\
MSG: object_recognition_msgs/ObjectRecognitionFeedback\n\
# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
#no feedback\n\
\n\
";
  }

  static const char* value(const ::object_recognition_msgs::ObjectRecognitionAction_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::object_recognition_msgs::ObjectRecognitionAction_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.action_goal);
      stream.next(m.action_result);
      stream.next(m.action_feedback);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ObjectRecognitionAction_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::object_recognition_msgs::ObjectRecognitionAction_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::object_recognition_msgs::ObjectRecognitionAction_<ContainerAllocator>& v)
  {
    s << indent << "action_goal: ";
    s << std::endl;
    Printer< ::object_recognition_msgs::ObjectRecognitionActionGoal_<ContainerAllocator> >::stream(s, indent + "  ", v.action_goal);
    s << indent << "action_result: ";
    s << std::endl;
    Printer< ::object_recognition_msgs::ObjectRecognitionActionResult_<ContainerAllocator> >::stream(s, indent + "  ", v.action_result);
    s << indent << "action_feedback: ";
    s << std::endl;
    Printer< ::object_recognition_msgs::ObjectRecognitionActionFeedback_<ContainerAllocator> >::stream(s, indent + "  ", v.action_feedback);
  }
};

} // namespace message_operations
} // namespace ros

#endif // OBJECT_RECOGNITION_MSGS_MESSAGE_OBJECTRECOGNITIONACTION_H
