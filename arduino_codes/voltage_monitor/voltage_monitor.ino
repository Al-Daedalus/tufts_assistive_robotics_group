#define RELAY 4
int count = 0;
int voltage = 0;

void setup() {
  analogReference(DEFAULT);
  pinMode(A5, INPUT);
  pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int readit = (analogRead(A5));
  float sens = readit * (5.0/1023.0);
  sens = (sens/3.36)*24;
  voltage+=sens;
  count++;

  if (count == 10)
  {
    
    int av = voltage/count;
    count = 0;
    voltage = 0;

    if (av < 12.0)
     {
      digitalWrite(RELAY, HIGH);
     }
  }

delay(5000);
}
