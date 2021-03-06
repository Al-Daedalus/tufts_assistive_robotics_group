// Generated by gencpp from file bill_diff_drive/Diff_drive.msg
// DO NOT EDIT!


#ifndef BILL_DIFF_DRIVE_MESSAGE_DIFF_DRIVE_H
#define BILL_DIFF_DRIVE_MESSAGE_DIFF_DRIVE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace bill_diff_drive
{
template <class ContainerAllocator>
struct Diff_drive_
{
  typedef Diff_drive_<ContainerAllocator> Type;

  Diff_drive_()
    : time_stamp(0.0)
    , left_wheel_vel(0.0)
    , right_wheel_vel(0.0)  {
    }
  Diff_drive_(const ContainerAllocator& _alloc)
    : time_stamp(0.0)
    , left_wheel_vel(0.0)
    , right_wheel_vel(0.0)  {
  (void)_alloc;
    }



   typedef float _time_stamp_type;
  _time_stamp_type time_stamp;

   typedef float _left_wheel_vel_type;
  _left_wheel_vel_type left_wheel_vel;

   typedef float _right_wheel_vel_type;
  _right_wheel_vel_type right_wheel_vel;





  typedef boost::shared_ptr< ::bill_diff_drive::Diff_drive_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::bill_diff_drive::Diff_drive_<ContainerAllocator> const> ConstPtr;

}; // struct Diff_drive_

typedef ::bill_diff_drive::Diff_drive_<std::allocator<void> > Diff_drive;

typedef boost::shared_ptr< ::bill_diff_drive::Diff_drive > Diff_drivePtr;
typedef boost::shared_ptr< ::bill_diff_drive::Diff_drive const> Diff_driveConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::bill_diff_drive::Diff_drive_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::bill_diff_drive::Diff_drive_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace bill_diff_drive

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'bill_diff_drive': ['/home/bill/bill_ros/bill_ws/src/bill_diff_drive/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::bill_diff_drive::Diff_drive_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::bill_diff_drive::Diff_drive_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::bill_diff_drive::Diff_drive_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::bill_diff_drive::Diff_drive_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::bill_diff_drive::Diff_drive_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::bill_diff_drive::Diff_drive_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::bill_diff_drive::Diff_drive_<ContainerAllocator> >
{
  static const char* value()
  {
    return "0203216223fb8c1d3e2b8b595642daed";
  }

  static const char* value(const ::bill_diff_drive::Diff_drive_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x0203216223fb8c1dULL;
  static const uint64_t static_value2 = 0x3e2b8b595642daedULL;
};

template<class ContainerAllocator>
struct DataType< ::bill_diff_drive::Diff_drive_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bill_diff_drive/Diff_drive";
  }

  static const char* value(const ::bill_diff_drive::Diff_drive_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::bill_diff_drive::Diff_drive_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 time_stamp\n\
float32 left_wheel_vel\n\
float32 right_wheel_vel\n\
";
  }

  static const char* value(const ::bill_diff_drive::Diff_drive_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::bill_diff_drive::Diff_drive_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.time_stamp);
      stream.next(m.left_wheel_vel);
      stream.next(m.right_wheel_vel);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Diff_drive_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::bill_diff_drive::Diff_drive_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::bill_diff_drive::Diff_drive_<ContainerAllocator>& v)
  {
    s << indent << "time_stamp: ";
    Printer<float>::stream(s, indent + "  ", v.time_stamp);
    s << indent << "left_wheel_vel: ";
    Printer<float>::stream(s, indent + "  ", v.left_wheel_vel);
    s << indent << "right_wheel_vel: ";
    Printer<float>::stream(s, indent + "  ", v.right_wheel_vel);
  }
};

} // namespace message_operations
} // namespace ros

#endif // BILL_DIFF_DRIVE_MESSAGE_DIFF_DRIVE_H
