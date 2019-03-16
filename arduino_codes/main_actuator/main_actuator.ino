
#include <ros.h>
#include <SoftwareSerial.h>
#include "RoboClaw.h"
#include <geometry_msgs/Twist.h>
#include <std_msgs/Int32.h>

#define SPEED 30
#define OFFSET 15
#define LOFFSET 5
#define TURN_OFFSET 0
#define STOP (uint32_t)0
#define address 0x80

ros::NodeHandle nh;
SoftwareSerial serial(10,11);
RoboClaw roboclaw(&serial,10000);

geometry_msgs::Twist input;

//M1 is RIGHTwheel, M2 is LEFTwheel

void turnRight()
{
  roboclaw.ForwardM1(address, SPEED+OFFSET);
  roboclaw.BackwardM2(address, SPEED+LOFFSET);
}

void turnLeft()
{
  roboclaw.BackwardM1(address, SPEED+OFFSET);
  roboclaw.ForwardM2(address, SPEED+LOFFSET);
}

void moveForward()
{
  roboclaw.ForwardM1(address, SPEED+OFFSET);
  roboclaw.ForwardM2(address, SPEED+LOFFSET);
}

void moveBackward()
{
  roboclaw.BackwardM1(address, SPEED+OFFSET);
  roboclaw.BackwardM2(address, SPEED+LOFFSET);
}

void stop_moving()
{
  roboclaw.SpeedM1M2(address, STOP, STOP);
}

void messageCb(const geometry_msgs::Twist &input) 
{
  //Turn left
  if ( input.angular.z == 2.0) 
                        turnLeft();
  
  //Turn right
  else if (input.angular.z == -2.0) 
                        turnRight();                           

  
  //move BACKWARD
  else if (input.linear.x < 0.0  ) 
                        moveForward();
           
    //move FORWARD                       
 else if (input.linear.x > 0.0) {
                        moveBackward();
 }

  else if (input.linear.x == 0 and input.angular.z == 0)
   
     {
                        stop_moving();
     }
  
}


ros::Subscriber<geometry_msgs::Twist> sub("/cmd_vel", &messageCb);

void setup() {
  roboclaw.begin(57600);
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
