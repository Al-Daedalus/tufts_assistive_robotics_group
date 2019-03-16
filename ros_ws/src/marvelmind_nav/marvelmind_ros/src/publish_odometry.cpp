#include "ros/ros.h"
#include "marvelmind_nav/hedge_imu_fusion.h"
#include "marvelmind_nav/hedge_pos_ang.h"
#include "sensor_msgs/Imu.h"
#include "geometry_msgs/PoseStamped.h"
#include "tf/transform_broadcaster.h"
#include "nav_msgs/Odometry.h"

class hedge_msg_adapter_node
{
public:
  hedge_msg_adapter_node() // Class constructor
  {
    ros::NodeHandle nh_; // Public nodehandle for pub-sub
    ros::NodeHandle nh_private_("~"); // Private nodehandle for handling parameters

    // Init subscribers
    imu_fusion_sub_ = nh_.subscribe("hedge_imu_fusion", 10, &hedge_msg_adapter_node::imu_fusion_callback, this);
    pos_ang_sub_ = nh_.subscribe("hedge_pos_ang", 10, &hedge_msg_adapter_node::pos_ang_callback, this);

    // Init publishers
    hedge_pose_pub_ = nh_.advertise<geometry_msgs::PoseStamped>("/pose", 10, false);
    hedge_imu_pub_ = nh_.advertise<sensor_msgs::Imu>("/imu", 10, false);
    odom_pub = nh_.advertise<nav_msgs::Odometry>("/odom", 50, false);

    // You must provide the static transforms for these in a launch file!
    imu_out_.header.frame_id = "imu";
    pose_out_.header.frame_id = "pose";
  }

  void imu_fusion_callback(const marvelmind_nav::hedge_imu_fusion::ConstPtr& imu_fusion_msg)
  {
    // Populate header
    imu_out_.header.stamp = ros::Time::now();

    // Populate orientation data
    imu_out_.orientation.x = imu_fusion_msg->qx;
    imu_out_.orientation.y = imu_fusion_msg->qy;
    imu_out_.orientation.z = imu_fusion_msg->qz;
    imu_out_.orientation.w = imu_fusion_msg->qw;

    // Populate pose message with orientation
    pose_out_.pose.orientation.x = imu_fusion_msg->qx;
    pose_out_.pose.orientation.y = imu_fusion_msg->qy;
    pose_out_.pose.orientation.z = imu_fusion_msg->qz;
    pose_out_.pose.orientation.w = imu_fusion_msg->qw;


    // Populate angular velocity data
    imu_out_.angular_velocity.x = imu_fusion_msg->vx;
    imu_out_.angular_velocity.y = imu_fusion_msg->vy;
    imu_out_.angular_velocity.z = imu_fusion_msg->vz;

    // Populate linear acceleration data
    imu_out_.linear_acceleration.x = imu_fusion_msg->ax;
    imu_out_.linear_acceleration.y = imu_fusion_msg->ay;
    imu_out_.linear_acceleration.z = imu_fusion_msg->az;

    // Publish the sensor_msgs/Imu message
    hedge_imu_pub_.publish(imu_out_);
  }

  void pos_ang_callback(const marvelmind_nav::hedge_pos_ang::ConstPtr& pos_ang_msg)
  {
    // Populate header
    pose_out_.header.stamp = ros::Time::now();

    // Populate position data
    pose_out_.pose.position.x = pos_ang_msg->x_m;
    pose_out_.pose.position.y = pos_ang_msg->y_m;
    pose_out_.pose.position.z = pos_ang_msg->z_m;
    


    // Publish the geometry_msgs/PoseWithCovarianceStamped message
    hedge_pose_pub_.publish(pose_out_);

    broadcast_transform(pose_out_);
  }


  void broadcast_transform(geometry_msgs::PoseStamped pose_msg)
  {
    nav_msgs::Odometry odom;
  odom.header.stamp = ros::Time::now();
  odom.header.frame_id = "odom";

  //set the position
    odom.pose.pose.position.x = pose_msg.pose.position.x;
    odom.pose.pose.position.y = pose_msg.pose.position.y;
    odom.pose.pose.position.z = 0;//pose_msg.pose.position.z;

    odom.pose.pose.orientation.x = pose_msg.pose.orientation.x;
    odom.pose.pose.orientation.y = pose_msg.pose.orientation.y;
    odom.pose.pose.orientation.z= pose_msg.pose.orientation.z;
    odom.pose.pose.orientation.w = pose_msg.pose.orientation.w;

    odom.child_frame_id = "base";

    odom_pub.publish(odom);


    geometry_msgs::TransformStamped odom_trans;
    odom_trans.header.stamp = ros::Time::now();
    odom_trans.header.frame_id = "odom";
    odom_trans.child_frame_id = "base_link";

    odom_trans.transform.translation.x = pose_msg.pose.position.x;
    odom_trans.transform.translation.y = pose_msg.pose.position.y;
    odom_trans.transform.translation.z = 0;//pose_msg.pose.position.z;
    odom_trans.transform.rotation = pose_msg.pose.orientation;

    odom_broadcaster.sendTransform(odom_trans);
  }

  
protected:
  // Subscriber objects
  ros::Subscriber imu_fusion_sub_;
  ros::Subscriber pos_ang_sub_;

  // Publisher objects
  ros::Publisher hedge_pose_pub_;
  ros::Publisher hedge_imu_pub_;

  // Message objects
  sensor_msgs::Imu imu_out_;
  geometry_msgs::PoseStamped pose_out_;


  tf::TransformBroadcaster odom_broadcaster;
  ros::Publisher odom_pub;
};






int main(int argc, char** argv)
{
  ros::init(argc, argv, "hedge_msg_adapter");

  hedge_msg_adapter_node adapter;

  ros::spin();
}