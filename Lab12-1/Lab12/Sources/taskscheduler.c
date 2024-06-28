#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "protos.h"
#include "defs.h"
#include <stdio.h>
//**********
// Kobe Liles, Timothy McNamara, NINA KIKISSAGBE
// 4/18/2024
// ECET 309
// Lab12
//**********

//global counters
extern unsigned char lcdValue;
volatile unsigned int MSecTime1 = 0;
volatile unsigned int MSecTime2 = 0;
volatile unsigned int interruptCounter = 0;
volatile unsigned int TwoMsDelayValue = 1000;

//initializing ports
void InitializePorts(void)
{
   DDRD = 0xE0;
   DDRK = 0xFF;
   DDRA = 0x0F;
   PUCR_PUPAE = 1;
   PTT_PTT5 = 0;   
}

//initializing timers/interrupts
void InitializeTimer(void)
{   
  ENABLE_INT; // Global interrupts on
  ECT_TSCR2 = 0x03;//prescale
  ECT_TSCR1_TEN = 1;//
  
  //ECT_TIOS_IOS0 =1;//
  ECT_TIOS_IOS0 = 1;  
  ECT_TIE_C0I = 1;//enabling ECT interrupts for channel 0 
  ECT_TFLG1_C0F = 1;//setting the flag for channel 0
  ECT_TCTL2_OM0 = 0;//toggling channel 0
  ECT_TCTL2_OL0 = 1;//toogling channel 0
  
  ECT_TIOS_IOS5 = 1;//enabling ECT timer 
  ECT_TIE_C5I = 1;//enabling ECT interrupt for channel 5
  ECT_TFLG1_C5F = 1;//setting flag for channel 5
  ECT_TCTL1_OM5 = 0;//toggling channel 5
  ECT_TCTL1_OL5 = 1;//toggling channel 5
  ECT_TC5 = ECT_TCNT + 1000;  
}

void interrupt TaskInterrupt(void)
{
   //reset the flag
   ECT_TFLG1_C5F = 1;//clearing flag at channel
   ECT_TC5 += TwoMsDelayValue;
   
   if(interruptCounter%9 == 0)
   {
      MSecTime1++;//9hz
   }
   
   if(interruptCounter%23 == 0)
   {
      MSecTime2++;//23hz
   }
   
   if(interruptCounter >= 23)
   {
      interruptCounter = 0;//setting counter to 0 if it reached its highest value
   }
   
   interruptCounter++;//incrementing counter
}

void interrupt SpeakerInterrupt(void)
{
   ECT_TFLG1_C5F = 1;//clearing flag for channel 0
   
   //only checks the switch case if key is pressed
   if(PTT_PTT5 == 1)
   {

    switch(lcdValue)
    {
        //different values per note
        case    'C': 
                        ECT_TC5 += 3823;
                        break; 
                     
                     
        case    'D': 
                        ECT_TC5 += 3405;
                        break;
                     
                     
        case    'E': 
                        ECT_TC5 += 3034;
                        break;
                     
                     
        case    'F': 
                        ECT_TC5 += 2864;
                        break;
                     
                     
        case    'G': 
                        ECT_TC5 += 2551;
                        break;
                     
                     
        case    'A': 
                        ECT_TC5 += 2273;
                        break;
                     
                     
        case    'B': 
                        ECT_TC5 += 2025;
                        break;
                     
    }
   }
}

void TaskScheduler(void)
{
  if (MSecTime1 > 0)
  { 
      MSecTime1--;
      LCDState();//calling LCD state machine
  }
  if (MSecTime2 > 0)
  { 
      MSecTime2--;
      KeyPadState();//calling KeyPad state machine
  }
}
