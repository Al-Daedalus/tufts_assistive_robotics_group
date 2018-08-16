
#include <RFM69.h>
#include <SPI.h>

#define NETWORKID     0   // Must be the same for all nodes (0 to 255)
#define MYNODEID      2   // My node ID (0 to 255)
#define TONODEID      1   // Destination node ID (0 to 254, 255 = broadcast)

#define FREQUENCY     RF69_915MHZ

#define MOTOR1 6
#define MOTOR2 5
const unsigned long MAX_DELAY = 5000;
unsigned long last_heard;
unsigned long now=millis();

RFM69 radio;

void setup()
{ 
  radio.initialize(FREQUENCY, MYNODEID, NETWORKID);
  radio.setHighPower(); // Always use this for RFM69HCW

  pinMode(MOTOR1, OUTPUT);
  pinMode(MOTOR2, OUTPUT);
  digitalWrite(MOTOR1, LOW);
  digitalWrite(MOTOR2, LOW);
}

void loop()
{

  if (radio.receiveDone()) // Got one!
  {
    now = millis();
    last_heard = now;
    if ((char)radio.DATA[0] == 'm')
      move_motor();
      
    else if ((char)radio.DATA[0] == 's')
      stop_motor();
  }
  
  
  last_heard = millis();
//
  if ((last_heard - now) > MAX_DELAY)
    stop_motor();
}

void stop_motor()
{
  digitalWrite(MOTOR1, LOW);
  digitalWrite(MOTOR2, LOW);
  delay(100);
}

void move_motor()
{
  digitalWrite(MOTOR1, HIGH);
  digitalWrite(MOTOR2, HIGH);
  delay(100);
}

