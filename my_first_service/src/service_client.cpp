#include <cstdlib>
#include "ros/ros.h"
#include "my_first_service/MyFirstSrv.h"

int main(int argc, char **argv){

	ros::init(argc, argv , "service_client");
	if(argc!=3) {
	  ROS_INFO("usage: add_two_ints_client X Y");
	  return 1;
	}

	ros::NodeHandle nh;

	ros::ServiceClient client=
		nh.serviceClient<my_first_service::MyFirstSrv>("calculate_two_ints");
	my_first_service::MyFirstSrv srv;
	srv.request.a = atoll(argv[1]); // atoll is changing letters to numbers
	srv.request.b = atoll(argv[2]);

	if(client.call(srv)) {
	ROS_INFO("Sum: %ld" , (long int)srv.response.sum);
	} else{
	ROS_ERROR("Failed to call service add_two_ints");
	return 1;
	}

	return 0;
}
