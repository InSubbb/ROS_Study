#include "ros/ros.h"
#include "my_first_topic/MyFirstMsg.h"

int main(int argc, char **argv){

	ros::init(argc, argv , "talker");
	ros::NodeHandle nh;

	ros::Publisher chatter_pub =
		nh.advertise<my_first_topic::MyFirstMsg>("chatter",1000);

	ros::Rate loop_rate(10);
	my_first_topic::MyFirstMsg msg;

	int count = 0;
	while (ros::ok()){

		msg.stamp = ros::Time::now();
		msg.data = count;

		ROS_INFO_STREAM("Time: "<<msg.stamp <<", count: "<< msg.data);

		chatter_pub.publish(msg);

		ros::spinOnce();
		loop_rate.sleep();
		count++;
	}
	return 0;
}
