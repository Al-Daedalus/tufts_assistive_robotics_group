#include <Servo.h>
#include <ros.h>
#include <geometry_msgs/Twist.h>

#define FORWARD 1250
#define REVERSE 1750
#define STOP 1500
#define LEFTW_PIN 6
#define RIGHTW_PIN 5

ros::NodeHandle nh;

Servo leftwheel;
Servo rightwheel;
geometry_msgs::Twist input;

void messageCb(const geometry_msgs::Twist &input) 
{
  //Turn left
  if ( input.angular.z > 0.0) 
                        { leftwheel.writeMicroseconds   (REVERSE);
                          rightwheel.writeMicroseconds  (FORWARD);}
  
  //Turn right
  if (input.angular.z < 0.0) 
                        { leftwheel.writeMicroseconds   (FORWARD);
                          rightwheel.writeMicroseconds  (REVERSE);}

  
  //move forward
  if (input.linear.x > 0.0  ) 
                        { leftwheel.writeMicroseconds   (FORWARD);
                          rightwheel.writeMicroseconds  (FORWARD);
                          }
           
    //move backward                       
 if (input.linear.x < 0.0) 
                        { leftwheel.writeMicroseconds   (REVERSE);
                          rightwheel.writeMicroseconds  (REVERSE);
                          }

  if (input.linear.x == 0 and input.angular.z == 0) 
     {
                        leftwheel.writeMicroseconds   (STOP);
                        rightwheel.writeMicroseconds  (STOP);
     }
  
}

ros::Subscriber<geometry_msgs::Twist> sub("/cmd_vel", &messageCb);

void setup() {

  pinMode(LEFTW_PIN, OUTPUT);
  pinMode(RIGHTW_PIN, OUTPUT);
  pinMode(13, OUTPUT);
  
  leftwheel.attach(RIGHTW_PIN);
  rightwheel.attach(LEFTW_PIN);
  
  leftwheel.writeMicroseconds(STOP);
  rightwheel.writeMicroseconds(STOP);
  
  delay(3000);
  nh.initNode();
  nh.subscribe(sub);

}

void loop() {
  
  nh.spinOnce();
  delay(1);
  
}
