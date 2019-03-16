#include <ros.h>
#include <SoftwareSerial.h>
#include "RoboClaw.h"
#include <geometry_msgs/Twist.h>
//#include <std_msgs/Float32.h>
#include <std_msgs/Int32.h>
#include <walk_distance_msg/Walk.h>

#define SPEED 30
#define OFFSET 15
#define LOFFSET 5
#define TURN_OFFSET 0
#define STOP (uint32_t)0
#define address 0x80
//#define VOLT_MNTR 5

bool TOO_CLOSE = false;

std_msgs::Int32 feedback;
ros::Publisher chatter("/feedback", &feedback);

ros::NodeHandle nh;
SoftwareSerial serial(10,11);
RoboClaw roboclaw(&serial,10000);

geometry_msgs::Twist input;
//std_msgs::Float32 distance;

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
  if (not TOO_CLOSE)
                        moveBackward();
 }

  else if (input.linear.x == 0 and input.angular.z == 0)
   
     {
                        stop_moving();
     }
  
}


//void distcb(const std_msgs::Float32 &distance)
//{
//  if (distance.data < 40.0)
//    TOO_CLOSE = true;
//
//  else
//    TOO_CLOSE = false;
//}





/*****************************
 * encoder integration
 **************************/
const byte ENCODER_A = 2;//A pin -> the interrupt pin 0
const byte ENCODER_B = 3;//B pin -> the interrupt pin 1

const float stepcount = 10.00; //total number of ticks

const float wheeldiameter = 330.00; //in millimeters

volatile int counter_A = 0;
volatile int counter_B = 0;

void ISR_countA()
{
  counter_A++;
}


void ISR_countB()
{
  counter_B++;
}

int CMtoSteps(float cm)
{
  int result;
  float circumference = (wheeldiameter * 3.14)*0.1;  //wheel circumference in cm
  float cm_step = circumference / stepcount; //cm per step

  float f_result = cm/cm_step; 
  result = (int)f_result;
  return result;
}

void MoveDistanceForward(int steps)
{
  feedback.data = 1;
  chatter.publish(&feedback);
  //reset counters
  counter_A = 0; 
  counter_B = 0; 

  while(steps > counter_A && steps > counter_B)
  {
    if (steps > counter_A)
        roboclaw.ForwardM1(address, SPEED+OFFSET);
    else
        roboclaw.ForwardM1(address, STOP);

    if (steps > counter_B)
        roboclaw.ForwardM2(address, SPEED+LOFFSET);
    else
        roboclaw.ForwardM2(address, STOP);
    delay(100);
  }

  stop_moving();
  counter_A = 0;
  counter_B = 0;
  
  feedback.data =9;
  chatter.publish(&feedback);
}


void MoveDistanceBackward(int steps)
{
  
  //reset counters
  counter_A = 0; 
  counter_B = 0; 

  while(steps > counter_A && steps > counter_B)
  {
    if (steps > counter_A)
        roboclaw.BackwardM1(address, SPEED+OFFSET);
    else
        roboclaw.BackwardM1(address, STOP);

    if (steps > counter_B)
        roboclaw.BackwardM2(address, SPEED+LOFFSET);
    else
        roboclaw.BackwardM2(address, STOP);
    delay(100);
  }

  stop_moving();
  counter_A = 0;
  counter_B = 0;
}



void TurnDistanceRight(int steps)
{
  
  feedback.data = 4;
  chatter.publish(&feedback);
  //reset counters
  counter_A = 0; 
  counter_B = 0; 

  while(steps > counter_A && steps > counter_B)
  {
    if (steps > counter_A)
        roboclaw.BackwardM1(address, SPEED+OFFSET);
    else
        roboclaw.BackwardM1(address, STOP);

    if (steps > counter_B)
        roboclaw.ForwardM2(address, SPEED+LOFFSET);
    else
        roboclaw.ForwardM2(address, STOP);

    delay(100);
  }

  stop_moving();
  counter_A = 0;
  counter_B = 0;
}


void TurnDistanceLeft(int steps)
{
  
  //reset counters
  counter_A = 0; 
  counter_B = 0; 

  while(steps > counter_A && steps > counter_B)
  {
    if (steps > counter_A)
        roboclaw.ForwardM1(address, SPEED+OFFSET);
    else
        roboclaw.ForwardM1(address, STOP);

    if (steps > counter_B)
        roboclaw.BackwardM2(address, SPEED+LOFFSET);
    else
        roboclaw.BackwardM2(address, STOP);

    delay(100);
  }

  stop_moving();
  counter_A = 0;
  counter_B = 0;
}

void walkcb(const walk_distance_msg::Walk &walk)
{

  if (walk.direction == 1)
        MoveDistanceForward(CMtoSteps(walk.distance*100));

  else if (walk.direction == 2)
        MoveDistanceBackward(CMtoSteps(walk.distance*100));

  else if (walk.direction == 3)
        TurnDistanceLeft(walk.distance);
//90 deg turn: step=6
  else if (walk.direction == 4)
        TurnDistanceRight(walk.distance);
}


//ros::Subscriber<std_msgs::Float32> sub2("/clearance", &distcb);
ros::Subscriber<geometry_msgs::Twist> sub("/cmd_vel", &messageCb);
ros::Subscriber<walk_distance_msg::Walk> sub3("/walk", &walkcb);
//std_msgs::String feedback;
//ros::Publisher chatter("/feedback", &feedback);

void setup() {
  roboclaw.begin(57600);
  roboclaw.ForwardMixed(address, STOP);
  roboclaw.TurnRightMixed(address, STOP);

  delay(3000);
  nh.initNode();
  nh.subscribe(sub);
//  nh.subscribe(sub2);
  nh.subscribe(sub3);
  nh.advertise(chatter);

  attachInterrupt(0, ISR_countA, CHANGE);
  attachInterrupt(1, ISR_countB, CHANGE);

}

void loop() {
  nh.spinOnce();
  delay(1);
  
}
