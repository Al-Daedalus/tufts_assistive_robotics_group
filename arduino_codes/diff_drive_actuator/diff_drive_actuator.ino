#include <ros.h>
#include <SoftwareSerial.h>
#include "RoboClaw.h"
#include <diff_drive_msgs/Diff_drive.h>

#define SPEED 16
#define STOP (uint8_t)0
#define address 0x80 

ros::NodeHandle nh;
SoftwareSerial serial(10,11);
RoboClaw roboclaw(&serial,10000);

diff_drive_msgs::Diff_drive input;

void messageCb(const diff_drive_msgs::Diff_drive &input) 
{
  float left_speed = input.left_wheel_vel;
  float right_speed = input.left_wheel_vel;

  if (left_speed < 0)
    roboclaw.BackwardM1(address,SPEED);

  else
    roboclaw.ForwardM1(address,SPEED);

   if (right_speed < 0)
    roboclaw.BackwardM2(address,SPEED);

  else
    roboclaw.ForwardM2(address,SPEED);
  
}

ros::Subscriber<diff_drive_msgs::Diff_drive> sub("/cmd_vel", &messageCb);

void setup() {
  roboclaw.begin(38400);
  roboclaw.ForwardMixed(address, STOP);
  roboclaw.TurnRightMixed(address, STOP);
  
  delay(3000);
  nh.initNode();
  nh.subscribe(sub);

}

void loop() {
  
  nh.spinOnce();
  delay(1);
  
}

