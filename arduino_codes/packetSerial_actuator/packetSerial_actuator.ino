#include <ros.h>
#include <SoftwareSerial.h>
#include "RoboClaw.h"
#include <geometry_msgs/Twist.h>
#include <std_msgs/UInt16.h>

#define SPEED 30
#define OFFSET 5
#define LOFFSET 0
#define STOP (uint32_t)0
#define address 0x80
#define VOLT_MNTR 5

ros::NodeHandle nh;
SoftwareSerial serial(10,11);
RoboClaw roboclaw(&serial,10000);

geometry_msgs::Twist input;

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

void messageCb(const geometry_msgs::Twist &input) 
{
  //Turn left
  if ( input.angular.z > 0.0) 
                        turnLeft();
  
  //Turn right
  else if (input.angular.z < 0.0) 
                        turnRight();

  
  //move forward
  else if (input.linear.x < 0.0  ) 
                        moveForward();
           
    //move backward                       
 else if (input.linear.x > 0.0) 
                        moveBackward();

  else if (input.linear.x == 0 and input.angular.z == 0)
   
     {
                        //roboclaw.TurnLeftMixed(address, STOP);
                        //roboclaw.TurnRightMixed(address, STOP);
                        //roboclaw.ForwardMixed(address, STOP);
                        //roboclaw.BackwardMixed(address, STOP);
                        roboclaw.SpeedM1M2(address, STOP, STOP);
     }
  
}

ros::Subscriber<geometry_msgs::Twist> sub("/cmd_vel", &messageCb);
std_msgs::UInt16 voltage_pub;
ros::Publisher chatter("/voltage_level", &voltage_pub);

void setup() {
  roboclaw.begin(57600);
  roboclaw.ForwardMixed(address, STOP);
  roboclaw.TurnRightMixed(address, STOP);
  pinMode(VOLT_MNTR, OUTPUT);
  digitalWrite(VOLT_MNTR, HIGH);
  delay(3000);
  nh.initNode();
  nh.subscribe(sub);
  nh.advertise(chatter);

}

void loop() {

  int volt = roboclaw.ReadMainBatteryVoltage(address);
  volt = map(volt, 0, 255, 0, 24);
  if (volt < 10) digitalWrite(VOLT_MNTR, LOW); else digitalWrite(VOLT_MNTR, HIGH);
  voltage_pub.data = volt;
  chatter.publish(&voltage_pub);
  nh.spinOnce();
  delay(1);
  
}
