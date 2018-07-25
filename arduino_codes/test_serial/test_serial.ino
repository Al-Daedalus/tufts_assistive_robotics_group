//Roboclaw simple serial example.  Set mode to 6.  Option to 4(38400 bps)

//See limitations of Arduino SoftwareSerial



void setup() {
  Serial1.begin(38400);
}

void loop() {
  //forward
  Serial1.write(1);
  Serial1.write(-127);
  delay(2000);
  
//  //backward
//  Serial1.write(127);
//  Serial1.write(-1);
//  delay(2000);
//
//  //left
//  Serial1.write(1);
//  Serial1.write(-1);
//  delay(2000);
//
//  //stop
//  Serial1.write((uint8_t)0);
//  delay(1000);
//
//  //right
//  Serial1.write(127);
//  Serial1.write(-127);
//  delay(2000);
//
//  //stop
//  Serial1.write((uint8_t)0);
//  delay(1000);
}
