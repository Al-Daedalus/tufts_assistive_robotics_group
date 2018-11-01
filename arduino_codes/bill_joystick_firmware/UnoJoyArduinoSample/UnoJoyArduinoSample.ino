
#include "UnoJoy.h"

boolean UpOn = false;
boolean DownOn = false;
boolean LeftOn = false;
boolean RightOn = false;

const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output


void setup(){
  setupUnoJoy();
}

void loop(){
  // Always be getting fresh data
  dataForController_t controllerData = getControllerData();
  setControllerData(controllerData);
}


dataForController_t getControllerData(void){
  
  // Set up a place for our controller data
  //  Use the getBlankDataForController() function, since
  //  just declaring a fresh dataForController_t tends
  //  to get you one filled with junk from other, random
  //  values that were in those memory locations before
  dataForController_t controllerData = getBlankDataForController();


  int x_direction = analogRead(X_pin);
  int y_direction = analogRead(Y_pin);

  //Left and Right directions
  if (x_direction < 200) LeftOn = true; 
  else if (x_direction > 800) RightOn = true;
  else if ((x_direction > 400) && (x_direction < 600)) 
          {LeftOn = false; RightOn = false;}

  if (y_direction < 200) DownOn = true;
  else if (y_direction > 800) UpOn = true;
  else if ((y_direction > 400) && (y_direction < 600)) 
          {UpOn = false; DownOn = false;}

  
  
  controllerData.dpadUpOn = UpOn;
  controllerData.dpadDownOn =DownOn;
  controllerData.dpadLeftOn = LeftOn; 
  controllerData.dpadRightOn = RightOn;
  
  return controllerData;
}
