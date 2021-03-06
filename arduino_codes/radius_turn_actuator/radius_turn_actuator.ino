#include <ros.h>
#include <SoftwareSerial.h>
#include "RoboClaw.h"
#include <geometry_msgs/Twist.h>
//#include <std_msgs/UInt16.h>
#include <std_msgs/Float32.h>

#define SPEED 30
#define LOW_SPEED 15
#define OFFSET 15
#define LOFFSET 0
#define TURN_OFFSET 0
#define STOP (uint32_t)0
#define address 0x80
//#define VOLT_MNTR 5

bool TOO_CLOSE = false;

ros::NodeHandle nh;
SoftwareSerial serial(10,11);
RoboClaw roboclaw(&serial,10000);

geometry_msgs::Twist input;
std_msgs::Float32 distance;

//M1 is RIGHT, M2 is LEFT
//roboclaw.Forward moves robot backward, roboclaw.Backward moves robot forward
void turnRightPrecise()
{
  roboclaw.ForwardM1(address, STOP);
  roboclaw.BackwardM2(address, SPEED+OFFSET+TURN_OFFSET);
}

void turnLeftPrecise()
{
  roboclaw.BackwardM1(address, SPEED+LOFFSET+TURN_OFFSET+10);
  roboclaw.ForwardM2(address, STOP);
}

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

void moveBackward()
{
  roboclaw.ForwardM1(address, SPEED+OFFSET);
  roboclaw.ForwardM2(address, SPEED+LOFFSET);
}

void moveForward()
{
  roboclaw.BackwardM1(address, SPEED+OFFSET);
  roboclaw.BackwardM2(address, SPEED+LOFFSET);
}

void moveBackwardALittle()
{
  roboclaw.ForwardM1(address, LOW_SPEED+OFFSET);
  roboclaw.ForwardM2(address, LOW_SPEED+LOFFSET);
}

void moveForwardALittle()
{
  roboclaw.BackwardM1(address, LOW_SPEED+OFFSET);
  roboclaw.BackwardM2(address, LOW_SPEED+LOFFSET);
}

void messageCb(const geometry_msgs::Twist &input) 
{
  //Turn left
  if ( input.angular.z == 2.0) 
                        turnLeft();
  
  //Turn right
  else if (input.angular.z == -2.0) 
                        turnRight();

   //Turn right precise
  else if (input.angular.z == -1.0) 
                        turnRightPrecise();   

   //Turn left precise
  else if (input.angular.z == 1.0) 
                        turnLeftPrecise();                             

  
  //move BACKWARD
  else if (input.linear.x == -3.0  ) 
                        moveBackward();
           
    //move FORWARD                       
 else if (input.linear.x == 3.0) {
  if (not TOO_CLOSE)
                        moveForward();
 }

 //move BACKWARD A LITTLE
 else if (input.linear.x == -0.5)
                        moveBackwardALittle();

 else if (input.linear.x == 0.5){
  if (not TOO_CLOSE)
                        moveForwardALittle();
 }

  else if (input.linear.x == 0 and input.angular.z == 0)
   
     {
                        //roboclaw.TurnLeftMixed(address, STOP);
                        //roboclaw.TurnRightMixed(address, STOP);
                        //roboclaw.ForwardMixed(address, STOP);
                        //roboclaw.BackwardMixed(address, STOP);
                        roboclaw.SpeedM1M2(address, STOP, STOP);
     }
  
}


void distcb(const std_msgs::Float32 &distance)
{
  if (distance.data < 40.0)
    TOO_CLOSE = true;

  else
    TOO_CLOSE = false;
}

ros::Subscriber<std_msgs::Float32> sub2("/clearance", &distcb);
ros::Subscriber<geometry_msgs::Twist> sub("/cmd_vel", &messageCb);
//std_msgs::UInt16 voltage_pub;
//ros::Publisher chatter("/voltage_level", &voltage_pub);

void setup() {
  roboclaw.begin(57600);
  roboclaw.ForwardMixed(address, STOP);
  roboclaw.TurnRightMixed(address, STOP);
//  pinMode(VOLT_MNTR, OUTPUT);
//  digitalWrite(VOLT_MNTR, HIGH);
  delay(3000);
  nh.initNode();
  nh.subscribe(sub);
  nh.subscribe(sub2);
//  nh.advertise(chatter);

}

void loop() {

//  int volt = roboclaw.ReadMainBatteryVoltage(address);
//  volt = map(volt, 0, 255, 0, 24);
//  voltage_pub.data = volt;
//  chatter.publish(&voltage_pub);
  nh.spinOnce();
  delay(1);
  
}
