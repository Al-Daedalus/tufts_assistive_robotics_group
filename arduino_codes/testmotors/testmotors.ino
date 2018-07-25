//RoboClaw RC Mode
//Control RoboClaw with servo pulses from a microcontroller.
//Mode settings: Mode 2(RC mixed mode) with Option 4(MCU with Exponential).
#include <Servo.h>
#define MIN 1250
#define MAX 1750
#define STOP 1500
Servo myservo1; // create servo object to control a RoboClaw channel
Servo myservo2; // create servo object to control a RoboClaw channel
int pos = 0; // variable to store the servo position
void setup()
{
myservo1.attach(5); // attaches the RC signal on pin 5 to the servo object
myservo2.attach(6); // attaches the RC signal on pin 6 to the servo object
}
void loop()
{
myservo1.writeMicroseconds(STOP); //Stop
myservo2.writeMicroseconds(STOP); //Stop
delay(2000);
myservo1.writeMicroseconds(MIN); //full forward
myservo2.writeMicroseconds(MIN);
delay(2000);
myservo1.writeMicroseconds(STOP); //stop
myservo2.writeMicroseconds(STOP); //stop
delay(2000);
myservo1.writeMicroseconds(MAX); //full reverse
myservo2.writeMicroseconds(MAX); //full reverse
delay(2000);
myservo1.writeMicroseconds(STOP); //Stop
myservo2.writeMicroseconds(STOP); //Stop
delay(2000);
myservo1.writeMicroseconds(STOP); //full turn left
myservo2.writeMicroseconds(MIN); //full turn left
delay(2000);
myservo2.writeMicroseconds(STOP); //Stop
delay(2000);
myservo1.writeMicroseconds(MAX); //full turn right
myservo2.writeMicroseconds(STOP); //full turn right
delay(10000);
}
