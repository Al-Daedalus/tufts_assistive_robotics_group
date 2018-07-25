#include <Wire.h>
#include <ros.h>
#include <std_msgs/Int32.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>

ros::NodeHandle nh;
std_msgs::Int32 imu_msg;
ros::Publisher imu_pub("/imu_heading", &imu_msg);
/* Assign a unique ID to this sensor at the same time */
Adafruit_LSM303_Mag_Unified mag = Adafruit_LSM303_Mag_Unified(12345);

void setup(void) 
{
  //Serial.begin(9600);
  nh.initNode();
  nh.advertise(imu_pub);
}

void loop(void) 
{
  /* Get a new sensor event */ 
  sensors_event_t event; 
  mag.getEvent(&event);
  delay(5000);
  float Pi = 3.14159;
  
  // Calculate the angle of the vector y,x
  float heading = (atan2(event.magnetic.y,event.magnetic.x) * 180) / Pi;
  
  // Normalize to 0-360
  if (heading < 0)
    heading = 360 + heading;
  
  imu_msg.data = heading;
  imu_pub.publish(&imu_msg);
  nh.spinOnce();
  delay(1000);
}
