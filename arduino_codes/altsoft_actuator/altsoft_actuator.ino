#include <AltSoftSerial.h>
#include <ros.h>
#include <geometry_msgs/Twist.h>

#define FORWARDl 148
#define REVERSEl 235
#define FORWARDr 10
#define REVERSEr 120
#define STOP (uint8_t)0

ros::NodeHandle nh;
AltSoftSerial motor;

geometry_msgs::Twist input;

void messageCb(const geometry_msgs::Twist &input) 
{
  //Turn left
  if ( input.angular.z > 0.0) 
                        { motor.write  (REVERSEl);
                          motor.write  (FORWARDr);}
  
  //Turn right
  if (input.angular.z < 0.0) 
                        { motor.write   (FORWARDl);
                          motor.write  (REVERSEr);}

  
  //move forward
  if (input.linear.x > 0.0  ) 
                        { motor.write   (FORWARDr);
                          motor.write  (FORWARDl);
                          }
           
    //move backward                       
 if (input.linear.x < 0.0) 
                        { motor.write   (REVERSEr);
                          motor.write  (REVERSEl);
                          }

  if (input.linear.x == 0 and input.angular.z == 0) 
     {
                        motor.write   (STOP);
                        
     }
  
}

ros::Subscriber<geometry_msgs::Twist> sub("/cmd_vel", &messageCb);

void setup() {
  motor.begin(38400);
  motor.write   (STOP);
  
  delay(3000);
  nh.initNode();
  nh.subscribe(sub);

}

void loop() {
  
  nh.spinOnce();
  delay(1);
  
}
