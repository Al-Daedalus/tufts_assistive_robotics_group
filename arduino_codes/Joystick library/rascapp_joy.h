#ifndef RASCAPP_JOY_H
#define RASCAPP_JOY_H

#include <stdint.h>
#include <Arduino.h>

//Joystick data struct
typedef struct JoyData_T
{
        uint8_t UpOn : 1;
        uint8_t DownOn : 1;
        uint8_t LeftOn : 1;
        uint8_t RightOn : 1;
        uint8_t Padding : 4;

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
        TIMSKO |= (1<<OCIE0A);  //Fire ISR every 1024us
}

void initializeJoy(int interval)
{
        serialCheckInterval = interval;
        initializeJoy();
}

ISR(TIMER0_COMPA_vect)
{
        serialCheckCounter++;

        if (serialCheckCounter >= serialCheckInterval)
        {
                while (Serial.available() > 0)
                {
                        pinMode(13, OUTPUT);
                        digitalWrite(13, HIGH);
                        Serial.write(dataBuffer);
                        digitalWrite(13, LOW);
                }
        }
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