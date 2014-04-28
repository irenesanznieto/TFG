/* Auto-generated by genmsg_cpp for file /home/irene/repos/ros_ws/sandbox/TFG/msg/HandPointCloud.msg */
#ifndef TFG_MESSAGE_HANDPOINTCLOUD_H
#define TFG_MESSAGE_HANDPOINTCLOUD_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"

#include "std_msgs/Header.h"
#include "sensor_msgs/PointCloud2.h"

namespace TFG
{
template <class ContainerAllocator>
struct HandPointCloud_ {
  typedef HandPointCloud_<ContainerAllocator> Type;

  HandPointCloud_()
  : header()
  , name()
  , pointcloud()
  {
  }

  HandPointCloud_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , name(_alloc)
  , pointcloud(_alloc)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _name_type;
  std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  name;

  typedef  ::sensor_msgs::PointCloud2_<ContainerAllocator>  _pointcloud_type;
   ::sensor_msgs::PointCloud2_<ContainerAllocator>  pointcloud;


  typedef boost::shared_ptr< ::TFG::HandPointCloud_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::TFG::HandPointCloud_<ContainerAllocator>  const> ConstPtr;
}; // struct HandPointCloud
typedef  ::TFG::HandPointCloud_<std::allocator<void> > HandPointCloud;

typedef boost::shared_ptr< ::TFG::HandPointCloud> HandPointCloudPtr;
typedef boost::shared_ptr< ::TFG::HandPointCloud const> HandPointCloudConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::TFG::HandPointCloud_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::TFG::HandPointCloud_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace TFG

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::TFG::HandPointCloud_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::TFG::HandPointCloud_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::TFG::HandPointCloud_<ContainerAllocator> > {
  static const char* value() 
  {
    return "899f5cab835230d85f28f09b38d4247b";
  }

  static const char* value(const  ::TFG::HandPointCloud_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x899f5cab835230d8ULL;
  static const uint64_t static_value2 = 0x5f28f09b38d4247bULL;
};

template<class ContainerAllocator>
struct DataType< ::TFG::HandPointCloud_<ContainerAllocator> > {
  static const char* value() 
  {
    return "TFG/HandPointCloud";
  }

  static const char* value(const  ::TFG::HandPointCloud_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::TFG::HandPointCloud_<ContainerAllocator> > {
  static const char* value() 
  {
    return "Header header\n\
string name\n\
sensor_msgs/PointCloud2 pointcloud\n\
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
# * stamp.secs: seconds (stamp_secs) since epoch\n\
# * stamp.nsecs: nanoseconds since stamp_secs\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
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
";
  }

  static const char* value(const  ::TFG::HandPointCloud_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::TFG::HandPointCloud_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::TFG::HandPointCloud_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::TFG::HandPointCloud_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.name);
    stream.next(m.pointcloud);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct HandPointCloud_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::TFG::HandPointCloud_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::TFG::HandPointCloud_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.name);
    s << indent << "pointcloud: ";
s << std::endl;
    Printer< ::sensor_msgs::PointCloud2_<ContainerAllocator> >::stream(s, indent + "  ", v.pointcloud);
  }
};


} // namespace message_operations
} // namespace ros

#endif // TFG_MESSAGE_HANDPOINTCLOUD_H

