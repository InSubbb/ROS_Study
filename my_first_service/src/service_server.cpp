#include "ros/ros.h"
#include "my_first_service/MyFirstSrv.h"

#define PLUS 1
#define MINUS 2
#define MULTIPLICATION 3
#define DIVISION 4

int g_operator = PLUS;

bool calculate(my_first_service::MyFirstSrv::Request &req,
	my_first_service::MyFirstSrv::Response &res)  {
	switch(g_operator){
	  case PLUS:
		res.sum = req.a + req.b;
		break;
	  case MINUS:
		res.sum = req.a - req.b;
	  	break;
	  case MULTIPLICATION:
		res.sum = req.a * req.b;
		break;
	  case DIVISION:
		if(req.b==0){
			res.sum=0;
		} else {
			res.sum = req.a / req.b;
		}
		break;
	  default:
		res.sum=0;
		break;
	}
	ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
	ROS_INFO("sending back response: [%ld]", (long int)res.sum);
	return true;
}

int main(int argc, char **argv){

	ros::init(argc, argv , "service_server");
	ros::NodeHandle nh;

	ros::ServiceServer service = nh.advertiseService("calculate_two_ints",calculate);
	ROS_INFO("Ready to calcualte two ints.");
	ros::Rate r(10);
	while(ros::ok()){
	nh.param("calculation_method",g_operator,PLUS);
	ros::spinOnce();
	r.sleep();
     }

	return 0;
}
