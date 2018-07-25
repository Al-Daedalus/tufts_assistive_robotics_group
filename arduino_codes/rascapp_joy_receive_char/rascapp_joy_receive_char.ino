#include <SoftwareSerial.h>

SoftwareSerial xbee(2,3);

void setup() {
  xbee.begin(9600);
  Serial.begin(38400);
  for(int i=4; i<8; i++)
    pinMode(i, OUTPUT);

}

void loop() {
  if (xbee.available()>0)
  {
    char data = xbee.read();
    Serial.println(data);
//    if(data == 'u') Seri
//    else if (data == 'd') digitalWrite(4, HIGH);
//    else if (data == 'l') digitalWrite(5, HIGH);
//    else if (data == 'r')digitalWrite(6, HIGH);
//    else if (data == 'c')digitalWrite(7, HIGH);

//    for (int i=4; i<8; i++)
//      digitalWrite(i, LOW);
  }

}
