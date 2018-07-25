
#include <RFM69.h>
#include <SPI.h>

// Addresses for this node. CHANGE THESE FOR EACH NODE!

#define NETWORKID     0   // Must be the same for all nodes (0 to 255)
#define MYNODEID      3   // My node ID (0 to 255)
#define TONODEID      2   // Destination node ID (0 to 254, 255 = broadcast)

#define FREQUENCY     RF69_915MHZ

#define IS_RFM69HCW true

#define RFM69_CS      8
#define RFM69_IRQ     3
#define RFM69_IRQN    3  // Pin 3 is IRQ 3!
#define RFM69_RST     4


#define Button1 5
#define Button2 6
//#define LED 13

char thesignal = 'm';
RFM69 radio = RFM69(RFM69_CS, RFM69_IRQ, IS_RFM69HCW, RFM69_IRQN);

void setup()
{ 
  
  delay(5000);

  // Hard Reset the RFM module
  pinMode(RFM69_RST, OUTPUT);
  digitalWrite(RFM69_RST, HIGH);
  delay(100);
  digitalWrite(RFM69_RST, LOW);
  delay(100);

  
  radio.initialize(FREQUENCY, MYNODEID, NETWORKID);
  radio.setHighPower(); 
  radio.setPowerLevel(31);

  pinMode(Button1, INPUT_PULLUP);
  pinMode(Button2, INPUT_PULLUP);
 
}

void loop()
{
  int b1state, b2state;
  b1state = digitalRead(Button1);
  b2state = digitalRead(Button2);

  if (b1state == LOW)  //If button is closed, it is low
  {
//    digitalWrite(LED, HIGH);
    thesignal = 's';
  }

  else if (b2state == LOW)
  {
//     digitalWrite(LED, HIGH);
    thesignal = 'm';
   
  }

  send_signal(thesignal);
//  digitalWrite(LED, LOW);
}


void send_signal(char thesignal)
{
    int sendlength = 1;
    static char sendbuffer[1];
    sendbuffer[0] = thesignal;
    radio.send(TONODEID, sendbuffer, sendlength);
    
    
}


