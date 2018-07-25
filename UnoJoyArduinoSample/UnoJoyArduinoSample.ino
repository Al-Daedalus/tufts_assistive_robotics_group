
#include "UnoJoy.h"
#include <SoftwareSerial.h>

SoftwareSerial xbee(2,3);

boolean UpOn = false;
boolean DownOn = false;
boolean LeftOn = false;
boolean RightOn = false;

void setup(){
  setupPins();
  setupUnoJoy();
  xbee.begin(38400);
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
  for (int i = 4; i <= 12; i++){
    pinMode(i, INPUT);
    digitalWrite(i, HIGH);
  }
  pinMode(A4, INPUT);
  digitalWrite(A4, HIGH);
  pinMode(A5, INPUT);
  digitalWrite(A5, HIGH);
}

dataForController_t getControllerData(void){
  
  // Set up a place for our controller data
  //  Use the getBlankDataForController() function, since
  //  just declaring a fresh dataForController_t tends
  //  to get you one filled with junk from other, random
  //  values that were in those memory locations before
  dataForController_t controllerData = getBlankDataForController();
  // Since our buttons are all held high and
  //  pulled low when pressed, we use the "!"
  //  operator to invert the readings from the pins


  if (xbee.available() > 0)
  {
    char data = xbee.read();
    
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

  else
  {
      UpOn = false;
      DownOn = false;
      LeftOn = false;
      RightOn = false;
  }
  
  
//  controllerData.triangleOn = !digitalRead(2);
//  controllerData.circleOn = !digitalRead(3);
  controllerData.squareOn = !digitalRead(4);
  controllerData.crossOn = !digitalRead(5);
  controllerData.dpadUpOn = UpOn;//!digitalRead(6);
  controllerData.dpadDownOn =DownOn;// !digitalRead(7);
  controllerData.dpadLeftOn = LeftOn; // !digitalRead(8);
  controllerData.dpadRightOn = RightOn;// !digitalRead(9);
  controllerData.l1On = !digitalRead(10);
  controllerData.r1On = !digitalRead(11);
  controllerData.selectOn = !digitalRead(12);
  controllerData.startOn = !digitalRead(A4);
  controllerData.homeOn = !digitalRead(A5);

 
  
  // Set the analog sticks
  //  Since analogRead(pin) returns a 10 bit value,
  //  we need to perform a bit shift operation to
  //  lose the 2 least significant bits and get an
  //  8 bit number that we can use  
  controllerData.leftStickX = analogRead(A0) >> 2;
  controllerData.leftStickY = analogRead(A1) >> 2;
  controllerData.rightStickX = analogRead(A2) >> 2;
  controllerData.rightStickY = analogRead(A3) >> 2;
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

