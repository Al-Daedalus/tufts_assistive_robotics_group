#include <Servo.h>
#include <ros.h>
#include <geometry_msgs/Twist.h>

ros::NodeHandle nh;

Servo steering;
Servo thrust;
geometry_msgs::Twist input;

void messageCb(const geometry_msgs::Twist &input) 
{
   if (input.angular.z >= -1.0 and input.angular.z < 0.0){ steering.write(70);}
  
  if ( input.angular.z < -1.0) {steering.write(15); digitalWrite(13, HIGH); }
  
  if (input.angular.z == 0.0 or input.angular.z ==-0.0) {steering.write(90); }
  
  if (input.angular.z <= 1.0 and input.angular.z > 0.0) {steering.write(110);}
  
  if (input.angular.z > 1.0) {steering.write(165);}
  
  
  if (input.linear.x == 0.0) {thrust.writeMicroseconds(1500);}
  
  else if (input.linear.x > 1.0  ) {thrust.writeMicroseconds (1535); delay(100);}
  
  else if (input.linear.x > 0.0 and input.linear.x < 1.0) {thrust.writeMicroseconds (1520); }
  
  else if (input.linear.x < 0.0) {thrust.writeMicroseconds (1400);}
}

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", &messageCb);

void setup() {
  //pinMode(8, INPUT);
  pinMode(11, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(13, OUTPUT);
  
  steering.attach(6);
  thrust.attach(11);
  
  thrust.writeMicroseconds(1500);
  delay(3000);
  nh.initNode();
  nh.subscribe(sub);
  //Serial.begin(9600);
}

void loop() {
  
  nh.spinOnce();
  delay(1);
  
}
