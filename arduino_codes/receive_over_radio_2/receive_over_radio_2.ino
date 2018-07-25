
#include <RFM69.h>
#include <SPI.h>

#define NETWORKID     0   // Must be the same for all nodes (0 to 255)
#define MYNODEID      2   // My node ID (0 to 255)
#define TONODEID      3   // Destination node ID (0 to 254, 255 = broadcast)

#define FREQUENCY     RF69_915MHZ
#define IS_RFM69HCW   true

#define RFM69_CS      8
#define RFM69_IRQ     3
#define RFM69_IRQN    3  // Pin 3 is IRQ 3!
#define RFM69_RST     4

#define LED 13
//#define STOP 5
const unsigned long MAX_DELAY = 5000;
unsigned long last_heard;
unsigned long now;

RFM69 radio= RFM69(RFM69_CS, RFM69_IRQ, IS_RFM69HCW, RFM69_IRQN);

void setup()
{ 

   // Hard Reset the RFM module
  pinMode(RFM69_RST, OUTPUT);
  digitalWrite(RFM69_RST, HIGH);
  delay(100);
  digitalWrite(RFM69_RST, LOW);
  delay(100);
  
  Serial.begin(9600);
  radio.initialize(FREQUENCY, MYNODEID, NETWORKID);
  radio.setHighPower(); // Always use this for RFM69HCW
  radio.setPowerLevel(31);
  
  pinMode(LED, OUTPUT);
  //pinMode(STOP, OUTPUT);
  digitalWrite(LED, LOW);
  //digitalWrite(STOP, LOW);
}

void loop()
{

  if (radio.receiveDone()) // Got one!
  {
    now = millis();
    last_heard = now;
    if ((char)radio.DATA[0] == 'm')
      {
        Serial.println("Received m");
        move_motor();
      }
      
    else if ((char)radio.DATA[0] == 's')
    {
      Serial.println("Received s");
      stop_motor();
      
    }
  }

  digitalWrite(LED, LOW);
  //digitalWrite(STOP, LOW);
  last_heard = millis();
//
  if ((last_heard - now) > MAX_DELAY)
    stop_motor();
}

void stop_motor()
{
  digitalWrite(LED, LOW);
  
  delay(100);
}

void move_motor()
{
  digitalWrite(LED, HIGH);
  
  delay(100);
}

