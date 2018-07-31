
#include <RFM69.h>
#include <SPI.h>

// Addresses for this node. CHANGE THESE FOR EACH NODE!

#define NETWORKID     0   // Must be the same for all nodes (0 to 255)
#define MYNODEID      1   // My node ID (0 to 255)
#define TONODEID      2   // Destination node ID (0 to 254, 255 = broadcast)

#define FREQUENCY     RF69_915MHZ

#define Button1 4
#define Button2 5
#define LED 6

char signal = 'm';
RFM69 radio;

void setup()
{ 
  delay(5000);
  radio.initialize(FREQUENCY, MYNODEID, NETWORKID);
  radio.setHighPower(); 

  pinMode(Button1, INPUT);
  pinMode(Button2, INPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}

void loop()
{
  int b1state, b2state;
  b1state = digitalRead(Button1);
  b2state = digitalRead(Button2);

  if (b1state == LOW)  //If button is closed, it is low
  {
    digitalWrite(LED, HIGH);
    signal = 's';
  }

  else if (b2state == LOW)
  {
     digitalWrite(LED, HIGH);
    signal = 'm';
   
  }

  send_signal(signal);
  digitalWrite(LED, LOW);
}


void send_signal(char signal)
{
    int sendlength = 1;
    static char sendbuffer[1];
    sendbuffer[0] = signal;
    radio.send(TONODEID, sendbuffer, sendlength);
    
}


