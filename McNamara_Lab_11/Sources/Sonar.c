#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "Protos.h"
#include "defs.h"
#include <stdio.h>

/*
  Timothy McNamara
  ECET 49900
  Lab 11
  Last Revised: 04/02/2024
*/

volatile unsigned int count;
volatile unsigned int sendSig;
volatile unsigned int reciSig;
volatile unsigned int realCount;
volatile unsigned int time;
volatile unsigned int inches;
volatile unsigned int feet;
volatile unsigned int speed;
volatile unsigned int resolution;
char buffer[50];


void SonarStart(void)
{
   TIMER_SIX_FLAG;
   TIMER_SEVEN_FLAG;
   SPEAKER_ON;  
}

void SonarCheck(void)
{
   while(!(ECT_TFLG1_C7F))
   {
      ;  
   }
   
   ECT_TC6 = sendSig;
   reciSig = ECT_TC7;
   
   if( sendSig > reciSig)
   {
      count = ((65535 - sendSig) + reciSig);  
   }
   else
   {
      count = reciSig - sendSig;  
   }
   
    realCount = count / 2;
    
    resolution = (1/1000000) * 1000000; // 1MHz
    
    time = resolution * realCount;
    
    speed = 1116 * 12;
    
    feet = (time * speed)/ 1000000;
    
    inches = feet / 12; 
    
    sprintf(buffer, "dis = %d feet, %d in inches", feet, inches);
    Display(buffer);
    
}
