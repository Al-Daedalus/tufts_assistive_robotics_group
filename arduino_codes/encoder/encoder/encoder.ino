
#include <ros.h>
#include <std_msgs/Int32.h>

std_msgs::Int32 lwheel;
std_msgs::Int32 rwheel;
ros::Publisher lpub("/l_wheel", &lwheel);
ros::Publisher rpub("/r_wheel", &rwheel);


ros::NodeHandle nh;

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


void setup() {
  nh.initNode();
  nh.advertise(lpub);
  nh.advertise(rpub);

  attachInterrupt(digitalPinToInterrupt(ENCODER_A), ISR_countA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCODER_B), ISR_countB, CHANGE);

}

void loop() {
  lwheel.data = counter_A;
  rwheel.data = counter_B;
  lpub.publish(&lwheel);
  rpub.publish(&rwheel);
  
  nh.spinOnce();
  delay(1);
  
}
