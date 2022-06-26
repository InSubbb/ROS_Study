#include "ros/ros.h"
#include "my_first_topic/MyFirstMsg.h"

void chatterCallback(const my_first_topic::MyFirstMsg::ConstPtr& msg)
{
	ROS_INFO_STREAM("I heard: " << msg->data);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "listener");
	ros::NodeHandle nh;

	ros::Subscriber sub = nh.subscribe("chatter1", 1000, chatterCallback);

	ros::Publisher chatter_pub =
		nh.advertise<my_first_topic::MyFirstMsg>("chatter2",1000);

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
