//RoboClaw RC Mode
//Control RoboClaw with servo pulses from a microcontroller.
//Mode settings: Mode 2(RC mixed mode) with Option 4(MCU with Exponential).
#include <Servo.h>
#define FORWARD 1250
#define BACKWARD 1680
#define STOP 1500
Servo right; // create servo object to control a RoboClaw channel
Servo left; // create servo object to control a RoboClaw channel
int pos = 0; // variable to store the servo position
void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
right.attach(5); // attaches the RC signal on pin 5 to the servo object
left.attach(6); // attaches the RC signal on pin 6 to the servo object
}
void loop()
{
right.writeMicroseconds(FORWARD); //Stop
left.writeMicroseconds(BACKWARD); //Stop
delay(2000);
//myservo1.writeMicroseconds(MIN); //full forward
//myservo2.writeMicroseconds(MIN);
//delay(2000);
//myservo1.writeMicroseconds(STOP); //stop
//myservo2.writeMicroseconds(STOP); //stop
//delay(2000);
//myservo1.writeMicroseconds(MAX); //full reverse
//myservo2.writeMicroseconds(MAX); //full reverse
//delay(2000);

}
