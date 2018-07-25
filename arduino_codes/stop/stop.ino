//Roboclaw simple serial example.  Set mode to 6.  Option to 4(38400 bps)

#include <AltSoftSerial.h>
//See limitations of Arduino SoftwareSerial

AltSoftSerial mySerial;

void setup() {
  pinMode(46,OUTPUT);
  pinMode(48, OUTPUT);
  mySerial.begin(38400);
  
}

void loop() {

  mySerial.write((uint8_t)0);
  delay(5000);
}
