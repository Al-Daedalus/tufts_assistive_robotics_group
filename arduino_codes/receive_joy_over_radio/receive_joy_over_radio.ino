#include <RFM69.h>
#include <SPI.h>

#define NETWORKID     0   // Must be the same for all nodes (0 to 255)
#define MYNODEID      4   // My node ID (0 to 255)
#define TONODEID      3   // Destination node ID (0 to 254, 255 = broadcast)

#define FREQUENCY     RF69_915MHZ
#define RFM69_CS      8
#define RFM69_IRQ     2
#define RFM69_IRQN    2  // Pin 3 is IRQ 3!
#define RFM69_RST     4
#define IS_RFM69HCW true
RFM69 radio = RFM69(RFM69_CS, RFM69_IRQ, IS_RFM69HCW);//, RFM69_IRQN);

void setup()
{ 
  // Hard Reset the RFM module
  pinMode(RFM69_RST, OUTPUT);
  digitalWrite(RFM69_RST, HIGH);
  delay(100);
  digitalWrite(RFM69_RST, LOW);
  delay(100);
  
  radio.initialize(FREQUENCY, MYNODEID, NETWORKID);
  radio.setHighPower(); // Always use this for RFM69HCW
  //radio.setPowerLevel(31);
  Serial.begin(9600);
}

void loop()
{

  if (radio.receiveDone()) // Got one!
  {
    
    if ((char)radio.DATA[0] == 'u') Serial.println("UP");      
    else if ((char)radio.DATA[0] == 'd') Serial.println("DOWN");
    else if ((char)radio.DATA[0] == 'l') Serial.println("LEFT");
    else if ((char)radio.DATA[0] == 'r') Serial.println("RIGHT");
    else if ((char)radio.DATA[0] == 'c') Serial.println("CENTER");
    
  }
 
}


