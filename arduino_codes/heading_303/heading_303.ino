#include <Wire.h>
#include <ros.h>
#include <std_msgs/Float32.h>
#include <LSM303.h>

LSM303 compass;
ros::NodeHandle nh;
std_msgs::Float32 imu_msg;
ros::Publisher imu_pub("/imu_heading", &imu_msg);

void setup() {
//  Serial.begin(9600);
  Wire.begin();
  compass.init();
  compass.enableDefault();
  
  /*
  Calibration values; the default values of +/-32767 for each axis
  lead to an assumed magnetometer bias of 0. Use the Calibrate example
  program to determine appropriate values for your particular unit.
  */
  //New = min: {  -500,  -4096,  -1216}    max: {  -203,  -4096,   -876}

  compass.m_min = (LSM303::vector<int16_t>){  -500,  -4096,  -1216};
  compass.m_max = (LSM303::vector<int16_t>){  -203,  -4096,   -876};

//  compass.m_min = (LSM303::vector<int16_t>){-32767, -32767, -32767};
//  compass.m_max = (LSM303::vector<int16_t>){+32767, +32767, +32767};

   nh.initNode();
  nh.advertise(imu_pub);
}

void loop() {
  compass.read();
  
  /*
  When given no arguments, the heading() function returns the angular
  difference in the horizontal plane between a default vector and
  north, in degrees.
  
  The default vector is chosen by the library to point along the
  surface of the PCB, in the direction of the top of the text on the
  silkscreen. This is the +X axis on the Pololu LSM303D carrier and
  the -Y axis on the Pololu LSM303DLHC, LSM303DLM, and LSM303DLH
  carriers.
  
  To use a different vector as a reference, use the version of heading()
  that takes a vector argument; for example, use
  
    compass.heading((LSM303::vector<int>){0, 0, 1});
  
  to use the +Z axis as a reference.
  */
  float heading = compass.heading();
  
//  Serial.println(heading);

  imu_msg.data = heading;
  imu_pub.publish(&imu_msg);
  nh.spinOnce();
//  delay(1000);
  delay(100);
}
