/*
 * Author: Anis Koubaa
 * Year: 2016
 * Prince Sultan University/Gaitech Robotics.
 *
 */
#include <iostream>
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include <ros/master.h>
#include <boost/algorithm/string.hpp>

using namespace std;

ros::Publisher velocity_publisher;
ros::Subscriber turtle1_Subscriber;
turtlesim::Pose turtlesim_pose;
ros::Subscriber xTurtleSubscibers[50];
ros::Subscriber tTurtleSubscribers[50];

string otherTurtleNames[50];

int xTurtleCount = 0;
int tTurtleCount = 0;

struct TurtlePose {
	string turtlename;
	string topicname;
	turtlesim::Pose pose;
  };

static TurtlePose turtle1;
static TurtlePose xTurtles[50];
static TurtlePose tTurtles[50];

class XListener{
public:
	string turtleName;
	string topicName;
	double xTurtle_x;
	double xTurtle_y;
	turtlesim::Pose xTurtlePose;

	void xTurtleCallBack(const turtlesim::Pose::ConstPtr & pose_message, const int index);

};

//this is where i stopped at 12:46am working on create a data structure with the name and coordinate points. most likely will use a struct.
void XListener::xTurtleCallBack(const turtlesim::Pose::ConstPtr & pose_message, const int index){
	xTurtles[index].pose.x = pose_message->x;
	//cout << xTurtles[xCounter].pose.y << endl;
	xTurtles[index].pose.y = pose_message->y;
	//cout << xTurtles[xCounter].pose.y << endl;
}

class TListener{
public:
	string turtleName;
	string topicName;
	turtlesim::Pose tTurtlePose;

	void tTurtleCallBack(const turtlesim::Pose::ConstPtr & pose_message);
};

void TListener::tTurtleCallBack(const turtlesim::Pose::ConstPtr & pose_message){
	tTurtlePose.x = pose_message->x;
	tTurtlePose.y = pose_message->y;
}

const double x_min = 0.0;
const double y_min = 0.0;
const double x_max = 11.0;
const double y_max = 11.0;

const double PI = 3.14159265359;

void move(double speed, double distance, bool isForward);
void rotate (double angular_speed, double angle, bool clockwise);
double degrees2radians(double angle_in_degrees);
void setDesiredOrientation (double desired_angle_radians);
void poseCallback(const turtlesim::Pose::ConstPtr & pose_message);
void moveGoal(turtlesim::Pose  goal_pose, double distance_tolerance);
static string getTurtlename(const string topicname);
void storeTurtleNames();


int main(int argc, char **argv)
{
	// Initiate new ROS node named "talker"
	ros::init(argc, argv, "TurtleDodge");
	ros::NodeHandle n;
	double speed, angular_speed;
	double distance, angle;
	bool isForward, clockwise;
	storeTurtleNames();

	cout << "Number of X Turtles >> " << xTurtleCount << endl;
	cout << "Numer of T Turtles >> " << tTurtleCount << endl;

	XListener xTurtleListener[xTurtleCount];
	TListener tTurtleListener[tTurtleCount];

	velocity_publisher = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
	turtle1_Subscriber = n.subscribe("/turtle1/pose", 10, poseCallback);

	for(int i = 0; i < xTurtleCount; i ++){
		xTurtleListener[i].turtleName = xTurtles[i].turtlename;
		xTurtleListener[i].topicName = xTurtles[i].topicname;
		xTurtleSubscibers[i] = n.subscribe<turtlesim::Pose>(xTurtleListener[i].topicName, 1000, boost::bind(&XListener::xTurtleCallBack, &xTurtleListener[i], _1, i));
	}
	cout << "turtleName of xTurtles[5] >> " << xTurtles[5].turtlename << endl;
	cout << "topicName of xTurtles[5] >> " << xTurtles[5].topicname << endl;
	cout << "x value of xTurtles[5].pose.x >> " << xTurtles[5].pose.x << endl;

	/*for(int i = 0; i < tTurtleCount; i++){
		tCounter = i;
		tTurtleSubscribers[i] = n.subscribe<turtlesim::Pose>(tTurtles[i].topicname, 1000, tTurtleCallBack);

	}*/

	/*for(int i = 0; i < xTurtleCount; i++){
		cout << "Turtle Name : " << xTurtles[i].turtlename << " has a Topic Type of >> " << xTurtles[i].topicname << endl;
		cout << "Turtle Name : " << xTurtles[i].turtlename << " has a X coordinate of >> " << xTurtles[i].pose.x << endl;
		cout << "Turtle Name : " << xTurtles[i].turtlename << " has a Y coordinate of >> " << xTurtles[i].pose.y << endl;
	}

	for(int i = 0; i < tTurtleCount; i++){
		cout << "Turtle Name : " << tTurtles[i].turtlename << " has a Topic Type of >> " << tTurtles[i].topicname << endl;
	}*/


	//ros::Rate loop_rate(10);

	/** test your code here **/
	ROS_INFO("\n\n\n******START TESTING************\n");
	/*cout<<"enter speed: ";
	cin>>speed;
	cout<<"enter distance: ";
	cin>>distance;
	cout<<"forward?: ";
	cin>>isForward;
	move(speed, distance, isForward);

	cout<<"enter angular velocity (degree/sec): ";
	cin>>angular_speed;
	cout<<"enter desired angle (degrees): ";
	cin>>angle;
	cout<<"clockwise ?: ";
	cin>>clockwise;

	rotate(degrees2radians(angular_speed), degrees2radians(angle), clockwise);
	 */
	ros::Rate loop_rate(0.5);

	/*setDesiredOrientation(degrees2radians(120));

	loop_rate.sleep();
	setDesiredOrientation(degrees2radians(-60));
	loop_rate.sleep();
	setDesiredOrientation(degrees2radians(0));*/

	/*turtlesim::Pose goal_pose;
	goal_pose.x=1;
	goal_pose.y=1;
	goal_pose.theta=0;
	moveGoal(goal_pose, 0.01);
	loop_rate.sleep();
	 */

	//gridClean();

	ros::Rate loop(0.5);
	turtlesim::Pose pose;
	pose.x=1;
	pose.y=1;
	pose.theta=0;
	//moveGoal(pose, 0.01);

	pose.x=6;
	pose.y=6;
	pose.theta=0;
	//moveGoal(pose, 0.01);

	loop.sleep();
	//spiralClean();

	ros::spin();
	return 0;
}

/**
 *  makes the robot move with a certain linear velocity for a
 *  certain distance in a forward or backward straight direction.
 */
void move(double speed, double distance, bool isForward){
	geometry_msgs::Twist vel_msg;
	//set a random linear velocity in the x-axis
	if (isForward)
		vel_msg.linear.x =abs(speed);
	else
		vel_msg.linear.x =-abs(speed);
	vel_msg.linear.y =0;
	vel_msg.linear.z =0;
	//set a random angular velocity in the y-axis
	vel_msg.angular.x = 0;
	vel_msg.angular.y = 0;
	vel_msg.angular.z =0;

	double t0 = ros::Time::now().toSec();
	double current_distance = 0.0;
	ros::Rate loop_rate(100);
	do{
		velocity_publisher.publish(vel_msg);
		double t1 = ros::Time::now().toSec();
		current_distance = speed * (t1-t0);
		ros::spinOnce();
		loop_rate.sleep();
		//cout<<(t1-t0)<<", "<<current_distance <<", "<<distance<<endl;
	}while(current_distance<distance);
	vel_msg.linear.x =0;
	velocity_publisher.publish(vel_msg);

}

void rotate (double angular_speed, double relative_angle, bool clockwise){

	geometry_msgs::Twist vel_msg;
	//set a random linear velocity in the x-axis
	vel_msg.linear.x =0;
	vel_msg.linear.y =0;
	vel_msg.linear.z =0;
	//set a random angular velocity in the y-axis
	vel_msg.angular.x = 0;
	vel_msg.angular.y = 0;

	if (clockwise)
		vel_msg.angular.z =-abs(angular_speed);
	else
		vel_msg.angular.z =abs(angular_speed);

	double current_angle = 0.0;
	double t0 = ros::Time::now().toSec();
	ros::Rate loop_rate(10);
	do{
		velocity_publisher.publish(vel_msg);
		double t1 = ros::Time::now().toSec();
		current_angle = angular_speed * (t1-t0);
		ros::spinOnce();
		loop_rate.sleep();
	}while(current_angle<relative_angle);

	vel_msg.angular.z =0;
	velocity_publisher.publish(vel_msg);

}

double degrees2radians(double angle_in_degrees){
	return angle_in_degrees *PI /180.0;
}


void setDesiredOrientation (double desired_angle_radians){
	double relative_angle_radians = desired_angle_radians - turtlesim_pose.theta;
	bool clockwise = ((relative_angle_radians<0)?true:false);
	//cout<<desired_angle_radians <<","<<turtlesim_pose.theta<<","<<relative_angle_radians<<","<<clockwise<<endl;
	rotate (degrees2radians(10), abs(relative_angle_radians), clockwise);

}

void poseCallback(const turtlesim::Pose::ConstPtr & pose_message){
	turtlesim_pose.x=pose_message->x;
	turtlesim_pose.y=pose_message->y;
	turtlesim_pose.theta=pose_message->theta;
}

double getDistance(double x1, double y1, double x2, double y2){
	return sqrt(pow((x1-x2),2)+pow((y1-y2),2));
}

void moveGoal(turtlesim::Pose  goal_pose, double distance_tolerance){

	geometry_msgs::Twist vel_msg;

	ros::Rate loop_rate(100);
	double E = 0.0;
	do{
		/****** Proportional Controller ******/
		//linear velocity in the x-axis
		double Kp=1.0;
		double Ki=0.02;
		//double v0 = 2.0;
		//double alpha = 0.5;
		double e = getDistance(turtlesim_pose.x, turtlesim_pose.y, goal_pose.x, goal_pose.y);
		double E = E+e;
		//Kp = v0 * (exp(-alpha)*error*error)/(error*error);
		vel_msg.linear.x = (Kp*e);
		vel_msg.linear.y =0;
		vel_msg.linear.z =0;
		//angular velocity in the z-axis
		vel_msg.angular.x = 0;
		vel_msg.angular.y = 0;
		vel_msg.angular.z =4*(atan2(goal_pose.y-turtlesim_pose.y, goal_pose.x-turtlesim_pose.x)-turtlesim_pose.theta);

		velocity_publisher.publish(vel_msg);

		ros::spinOnce();
		loop_rate.sleep();

	}while(getDistance(turtlesim_pose.x, turtlesim_pose.y, goal_pose.x, goal_pose.y)>distance_tolerance);
	cout<<"end move goal"<<endl;
	vel_msg.linear.x =0;
	vel_msg.angular.z = 0;
	velocity_publisher.publish(vel_msg);
}

string getTurtleName(const string topicname) {
	vector<string> elems;
	char lc_delim[2];
	lc_delim[0] = '/';
	lc_delim[1] = '\0';
  
	boost::algorithm::split(elems, topicname, boost::algorithm::is_any_of(lc_delim));
	return elems[1];
  }

void storeTurtleNames(){
	ros::master::V_TopicInfo alltopics;
	string tname = "";
	string topicType = "";
	int turtleIdx = 0;
	//get all topic names 
	ros::master::getTopics(alltopics);

	for (int i=0; i<alltopics.size(); i++) {
		tname = getTurtleName(alltopics[i].name);
		topicType = getTurtleName(alltopics[i].datatype);
		//cout << "Type of topic >> " << topicType << endl;
		turtleIdx = atoi(tname.substr(1).c_str()); //extract turtle # from turtlename
		turtleIdx = turtleIdx - 1; //since index starts from 0
		if (tname[0] == 'T' && topicType == "Pose"){
			tTurtles[turtleIdx].turtlename = tname;
			tTurtles[turtleIdx].topicname = "/" + tname + "/pose";
			//tTurtleNames[turtleIdx] = tname;
			tTurtleCount++;
		}
		else if(tname[0] == 'X' && topicType == "Pose"){
			xTurtles[turtleIdx].turtlename = tname;
			xTurtles[turtleIdx].topicname = "/" + tname + "/pose";
			//xTurtleNames[turtleIdx] = tname;
			xTurtleCount++;
		}
		else{
		otherTurtleNames[turtleIdx] = tname;
		}
		tname = "";
		topicType = "";
		turtleIdx = 0;
	};
}

	//xTurtlePose * xTurtles = new xTurtlePose[xTurtleCount];
	//tTurtlePose * tTurtles = new tTurtlesPose[tTurtleCount];
	//TurtlePose * turtlePosition = new TurtlePose[xTurtleCount];
	/*cout << "Number of X Turtles >> " << xTurtleCount << endl;
	cout << "Number of T Turtles >> " << tTurtleCount << endl;
	for(int i = 0; i < 30; i++){
		cout << "Turtle Name >> " << turtleNames[i] << endl;
	}
	for(int i = 0; i < 25; i ++){
		cout << "X Turtle name >> " << xTurtleNames[i] << endl;
		cout << "T Turtle Name >> " << tTurtleNames[i] << endl;
	}*/

			//add values to the struct object here
		//then reset the values of xTurtle_x, xTurtle_y, xTurtle_theta back to zero; then when we loop again they will get set inside the callback then add
		//to the next struct object in the array of structs.
		/*xTurtles[i].x = xTurtle_x;
		xTurtles[i].y = xTurtle_y;
		xTurtles[i].theta = xTurtle_theta;
		xTurtle_x, xTurtle_y, xTurtle_theta = 0;*/

			/*
	for(int i = 0; i < xTurtleCount; i++){
		xTurtleSubscibers[i].
	}*/