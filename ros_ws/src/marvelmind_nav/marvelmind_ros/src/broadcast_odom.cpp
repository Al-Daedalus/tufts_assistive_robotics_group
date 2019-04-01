#include "ros/ros.h"
#include "geometry_msgs/PoseStamped.h"
#include "tf/transform_broadcaster.h"
#include "nav_msgs/Odometry.h"


class broadcast_transform
{
public:
broadcast_transform(){
	ros::NodeHandle n;
	odom_pub = n.advertise<nav_msgs::Odometry>("/odom", 50, false);

	ros::Subscriber odom_sub = n.subscribe("/pose", 10, &broadcast_transform::pose_callback, this);

}

void pose_callback(const geometry_msgs::PoseStamped::ConstPtr& pose_msg)
{
	nav_msgs::Odometry odom;
	odom.header.stamp = ros::Time::now();
	odom.header.frame_id = "odom";

	//set the position
    odom.pose.pose.position.x = pose_msg->pose.position.x;
    odom.pose.pose.position.y = pose_msg->pose.position.y;
    odom.pose.pose.position.z = pose_msg->pose.position.z;

    odom.pose.pose.orientation.x = pose_msg->pose.orientation.x;
    odom.pose.pose.orientation.y = pose_msg->pose.orientation.y;
    odom.pose.pose.orientation.z= pose_msg->pose.orientation.z;
    odom.pose.pose.orientation.w = pose_msg->pose.orientation.w;

    odom.child_frame_id = "base";
    std::cout << "here"<<std::endl;

    odom_pub.publish(odom);


    geometry_msgs::TransformStamped odom_trans;
    odom_trans.header.stamp = ros::Time::now();
    odom_trans.header.frame_id = "odom";
    odom_trans.child_frame_id = "base";

    odom_trans.transform.translation.x = pose_msg->pose.position.x;
    odom_trans.transform.translation.y = pose_msg->pose.position.y;
    odom_trans.transform.translation.z = 0.0;
    odom_trans.transform.rotation = pose_msg->pose.orientation;

    odom_broadcaster.sendTransform(odom_trans);

}

protected:
	
	tf::TransformBroadcaster odom_broadcaster;
	ros::Publisher odom_pub;
	
};

int main(int argc, char** argv)
{
  ros::init(argc, argv, "odometry_publisher");
  broadcast_transform b;
  ros::spin();
  
}