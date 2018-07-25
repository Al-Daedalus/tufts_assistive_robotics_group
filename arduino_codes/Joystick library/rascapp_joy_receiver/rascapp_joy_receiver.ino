void setup() {
  Serial.begin(38400);
  Serial1.begin(38400);
  for (int i=3; i<8; i++)
  pinMode(i, OUTPUT);

}

void loop() {
  if (Serial1.available() > 0)
  {
//    Serial.println("available");
    int data = Serial1.read();
    Serial.println(data);
//    if(data == 'u') digitalWrite(3, HIGH);
//    if (data == 'd') digitalWrite(4, HIGH);
//    if (data == 'l') digitalWrite(5, HIGH);
//    if (data == 'r')digitalWrite(6, HIGH);
    if (data == 200) digitalWrite(5, HIGH);
    
  }

  for (int i=3; i<8; i++)
    digitalWrite(i, LOW);
}
