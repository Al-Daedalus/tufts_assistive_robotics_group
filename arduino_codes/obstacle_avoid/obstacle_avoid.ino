#include <ros.h>
#include <geometry_msgs/Twist.h>

// defines pins numbers
const int trig1 = 4;
const int echo1 = 3;
const int echo2 = 8;
const int trig2 = 9;

ros::NodeHandle nh;
geometry_msgs::Twist vel_msg;
ros::Publisher vel_pub("/cmd_vel", &vel_msg);

void setup() {
  pinMode(trig1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echo1, INPUT); // Sets the echoPin as an Input
  pinMode(trig2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echo2, INPUT); // Sets the echoPin as an Input

  nh.initNode();
  nh.advertise(vel_pub);
}

void loop() {
 
  
  int distance1= SonarSensor(trig1, echo1);
  int distance2= SonarSensor(trig2, echo2);
  
  if (distance1 < 80 and distance2 < 80)
    vel_pub.publish(&vel_msg);
   nh.spinOnce();
   delay(100);
}

long SonarSensor(int trigPinSensor,int echoPinSensor)
{
  
  digitalWrite(trigPinSensor, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinSensor, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPinSensor, LOW);
  
 long duration = pulseIn(echoPinSensor, HIGH);
  long distance= (duration/2) / 29.1; 
  return distance;
}