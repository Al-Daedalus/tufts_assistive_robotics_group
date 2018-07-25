#ifndef RASCAPP_JOY_H
#define RASCAPP_JOY_H

#include <stdint.h>
#include <Arduino.h>

//Joystick data struct
typedef struct JoyData_T
{
        uint8_t UpOn;
        uint8_t DownOn;
        uint8_t LeftOn;
        uint8_t RightOn;
        

} JoyData_T;


//Function prototypes
void setJoyData(JoyData_T);
JoyData_T getBlankData(void);
void initializeJoy(void);
void initializeJoy(int);

//Private attributes
JoyData_T dataBuffer;
volatile int serialCheckInterval = 1;
int serialCheckCounter = 0;


//function definitions
void initializeJoy(void)
{
        dataBuffer = getBlankData();
        Serial.begin(38400);
        OCR0A = 128;
        TIMSK0 |= (1<<OCIE0A);  //Fire ISR every 1024us
}

void initializeJoy(int interval)
{
        serialCheckInterval = interval;
        initializeJoy();
}

//ISR(TIMER0_COMPA_vect)
//{
//        serialCheckCounter++;
//
//        if (serialCheckCounter >= serialCheckInterval)
//        {
//                while (Serial.available() > 0)
//                {
//                        pinMode(13, OUTPUT);
//                        digitalWrite(13, HIGH);
//
//                        byte data = (uint8_t)0;
//                        data |= (uint8_t)dataBuffer.UpOn;
//                        data |= (uint8_t)(dataBuffer.DownOn) << 1;
//                        data |= (uint8_t)(dataBuffer.LeftOn) << 2;
//                        data |= (uint8_t)(dataBuffer.RightOn) << 3;
//                        Serial.write(data);
//                        digitalWrite(13, LOW);
//                }
//        }
//}

void sendData()
{

   
    if (dataBuffer.UpOn==1) Serial.write('u');
    else if (dataBuffer.DownOn==1) Serial.write('d');
    else if (dataBuffer.LeftOn==1) Serial.write('l');
    else if (dataBuffer.RightOn==1) Serial.write('r');
    else if (not dataBuffer.UpOn==1 and not dataBuffer.DownOn==1 and 
                  not dataBuffer.LeftOn==1 and not dataBuffer.RightOn==1)
        Serial.write('c');
    
    else Serial.write('c');
    delay(100);

}

void setJoyData(JoyData_T data)
{
        dataBuffer = data;
        
}

JoyData_T getBlankData()
{
        JoyData_T data;
        data.UpOn = 0;
        data.DownOn = 0;
        data.LeftOn = 0;
        data.RightOn = 0;
        return data;
}

#endif
