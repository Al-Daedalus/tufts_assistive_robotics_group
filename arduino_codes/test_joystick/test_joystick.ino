void setup() {
  init_pins();
  Serial.begin(9600);

}

void loop() {
  if(Serial.available()>0)
  {
    if (not digitalRead(6))
      Serial.println("UP");

    if (not digitalRead(7))
      Serial.println("DOWN");

    if (not digitalRead(8))
      Serial.println("LEFT");

    if (not digitalRead(9))
      Serial.println("RIGHT");

    if (not digitalRead(4))
      Serial.println("STOP");


    if (not digitalRead(5))
      Serial.println("MOVE");

    if (digitalRead(6) and digitalRead(7) and digitalRead(8) and digitalRead(9))
       Serial.println("CENTER");
    
  }
  reset_pins();

}

void reset_pins()
{
  for(int i=4; i<10; i++)
      digitalWrite(i, HIGH);
}

void init_pins()
{
  for (int i=4; i<10; i++)
      pinMode(i, INPUT);

   reset_pins();
}

