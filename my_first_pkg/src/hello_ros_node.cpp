#include <ros/ros.h>
int main(int argc, char** argv)
{
	ros::init(argc,argv,"hello_ros_node");

	ros::NodeHandle nh;

	ros::Rate loopRate(10);
	
	unsigned int count =0;

	while (ros::ok()){
	
		ROS_INFO_STREAM("Hello ros world " << count);

		ros::spinOnce();

		loopRate.sleep();
		count++;
	}
	return 0;
}
