
#include "UnoJoy.h"

#include <RFM69.h>
#include <SPI.h>

boolean UpOn = false;
boolean DownOn = false;
boolean LeftOn = false;
boolean RightOn = false;

#define LED 13
#define NETWORKID     0   // Must be the same for all nodes (0 to 255)
#define MYNODEID      4   // My node ID (0 to 255)
#define TONODEID      3   // Destination node ID (0 to 254, 255 = broadcast)

#define FREQUENCY     RF69_915MHZ
#define RFM69_CS      8
#define RFM69_IRQ     2
#define RFM69_IRQN    2  // Pin 2 is IRQ 2!
#define RFM69_RST     4
#define IS_RFM69HCW true
RFM69 radio = RFM69(RFM69_CS, RFM69_IRQ, IS_RFM69HCW);//, RFM69_IRQN);



void setup(){
  // Hard Reset the RFM module
  pinMode(RFM69_RST, OUTPUT);
  digitalWrite(RFM69_RST, HIGH);
  delay(100);
  digitalWrite(RFM69_RST, LOW);
  delay(100);

  radio.initialize(FREQUENCY, MYNODEID, NETWORKID);
  radio.setHighPower(); // Always use this for RFM69HCW
  radio.setPowerLevel(31);
  
  pinMode(LED, OUTPUT);
  setupPins();
  setupUnoJoy();
  
}

void loop(){
  // Always be getting fresh data
  dataForController_t controllerData = getControllerData();
  setControllerData(controllerData);
}




void setupPins(void){
  // Set all the digital pins as inputs
  // with the pull-up enabled, except for the 
  // two serial line pins
  pinMode(A4, INPUT);
  digitalWrite(A4, HIGH);
  pinMode(A5, INPUT);
  digitalWrite(A5, HIGH);
}

dataForController_t getControllerData(void){
  
 
  dataForController_t controllerData = getBlankDataForController();
  // Since our buttons are all held high and
  //  pulled low when pressed, we use the "!"
  //  operator to invert the readings from the pins


//  if (xbee.available() > 0)
//  {
//    char data = xbee.read();
//    
//    resetKeys();
//    
//    if(data == 'u') UpOn = true;
//    else if (data == 'd') DownOn = true;
//    else if (data == 'l') LeftOn = true;
//    else if (data == 'r') RightOn = true;
//    else if (data == 'c')
//    {
//      UpOn = false;
//      DownOn = false;
//      LeftOn = false;
//      RightOn = false;
//    }
//  }
//
//  else
//  {
//      UpOn = false;
//      DownOn = false;
//      LeftOn = false;
//      RightOn = false;
//  }
//  

if (radio.receiveDone())
  {
    digitalWrite(LED, HIGH);
    char data = (char)radio.DATA[0];
    
    resetKeys();
    
    if(data == 'u') UpOn = true;
    else if (data == 'd') DownOn = true;
    else if (data == 'l') LeftOn = true;
    else if (data == 'r') RightOn = true;
    else if (data == 'c')
    {
      UpOn = false;
      DownOn = false;
      LeftOn = false;
      RightOn = false;
    }
    
  }

  

  controllerData.dpadUpOn = UpOn;
  controllerData.dpadDownOn =DownOn;
  controllerData.dpadLeftOn = LeftOn; 
  controllerData.dpadRightOn = RightOn;
 
//  controllerData.startOn = !digitalRead(A4);
//  controllerData.homeOn = !digitalRead(A5);
//
// 
//  
//  // Set the analog sticks
//  //  Since analogRead(pin) returns a 10 bit value,
//  //  we need to perform a bit shift operation to
//  //  lose the 2 least significant bits and get an
//  //  8 bit number that we can use  
//  controllerData.leftStickX = analogRead(A0) >> 2;
//  controllerData.leftStickY = analogRead(A1) >> 2;
//  controllerData.rightStickX = analogRead(A2) >> 2;
//  controllerData.rightStickY = analogRead(A3) >> 2;
  // And return the data!
  return controllerData;
}

void resetKeys(void)
{
  UpOn = false;
  DownOn = false;
  LeftOn = false;
  RightOn = false;
}

