#include <ros.h>
#include <encoder_msgs/Encoder.h>
#include <std_msgs/String.h>

#define L_Encoder 3
#define L_Enc2 5
#define R_Encoder 2
#define R_Enc2 4

volatile long left_ticks = 0;
volatile long right_ticks = 0;

ros::NodeHandle nh;
encoder_msgs::Encoder enc_msg;
ros::Publisher enc_pub("/encoder", &enc_msg);


void setup() {
//  Serial.begin(57600);
  pinMode(L_Encoder, INPUT);
  pinMode(L_Enc2, INPUT);
  pinMode(R_Encoder, INPUT);
  pinMode(R_Enc2, INPUT);
  
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  attachInterrupt(digitalPinToInterrupt(L_Encoder), leftISR, RISING);
  attachInterrupt(digitalPinToInterrupt(R_Encoder), rightISR, RISING);

  
  nh.initNode();
  
  nh.advertise(enc_pub);
 
}

void loop() {
 enc_msg.time_stamp = millis();
 enc_msg.left_encoder_count = left_ticks;
 enc_msg.right_encoder_count = right_ticks;

 enc_pub.publish(&enc_msg);
 nh.spinOnce();
 delay(100);

}

void leftISR()
{
  if (digitalRead(L_Encoder))// == digitalRead(L_Enc2))
    left_ticks++;
}

void rightISR()
{
  if (digitalRead(R_Encoder))// == digitalRead(R_Enc2))
    right_ticks++;
}

