#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "Protos.h"
#include "defs.h"

/*
  Timothy McNamara
  ECET 49900
  Lab 09
  Last Revised: 03/05/2024
*/

// Each of these variables are used is a quick timer frame. To allow
// the data variables to be changed in a quick time frame than
// normal, we make their data type to be volatile. This let's the
// encoder know that the variables data tied to is can change at 
// any time and possibly be used at any time. This prevents
// data loss and increases cpu cycles efficiency. 
volatile unsigned int aWholeTwoMilliseconds = 16000;
volatile unsigned int interruptCount = 0;
volatile unsigned int twoMilliCount = 0;
volatile unsigned int pointTwoFive = 0;
volatile unsigned int slowSpeed = 0;
volatile unsigned int fiveHertz = 0;
volatile unsigned int twoHertz = 0;
volatile unsigned int iAmSpeed = 0;
volatile unsigned int check = 0;
volatile unsigned int moto = 0;


// This entire function enables the timer channel zero interrupts.
// We use defined macros to set the values accordingly. Did this 
// for cosmetic purposes. See macro file for more details.
void TimerInitialize(void)
{
   ENABLE_INT;
   ENABLE_TIMER_ZERO;
   TIMER_ZERO_INTERRUPT_EN;
   TIMER_SYSTEM_EN;
   TIMER_PRIMER;
   TIMER_ZERO_OL;
   TIMER_ZERO_OM;
   TIMER_ZERO_FLAG_RESET;
}

void Init(void)
{
   DDRP = 0x01;
   DDRC = 0x07;  
}

void SpeedCheck(void)
{
   // uses a macro to read if BIT0 of PORTB is high and
   // sets values accordingly. 
   if(FAST_SPEED) 
   {
     iAmSpeed = 1;
       
   }
   else
   {
     iAmSpeed = 0;
       
   }
   
    if(SLOW_SPEED) 
   {
     slowSpeed = 1;
       
   }
   else
   {
     slowSpeed = 0;
       
   }
}

void MotorControl(void)
{
  static unsigned char motorCount = 0;
  
  if(iAmSpeed &&  (motorCount < 9)) // 90% duty Cycle
  {
     PTP = 0x01;  // Turns the motor.
     motorCount++;     
  }
  else
  {
     PTP = 0x00;  // Stops the motor.
     
  }
   
  if(slowSpeed &&  (motorCount < 3)) // 30% duty Cycle
  {
    PTP = 0x01;   // Turns the motor.
    motorCount++;
  }
  else
  {
     PTP = 0x00;  // Stops the motor.
     
  }
   
  
   // If the  motor count gets above 10, we reset it.
   if(iAmSpeed && (motorCount == 9))
   {
      motorCount = 0;  
   }
   if(slowSpeed && (motorCount == 3))
   {
      motorCount = 0;  
   }
}

void BitZeroTog(void)
{
  PORTC ^= BIT_0; // Toggles bit 0 of the LEDs at a rate of 5 Hz  
}

void BitOneTog(void)
{
  PORTC ^= BIT_1; // Toggles bit 1 of the LEDs at a rate of 2 Hz   
}

void BitTwoTog(void)
{
  PORTC ^= BIT_2; // Toggles bit 1 of the LEDs at a rate of 0.25 Hz  
}

void ThePoshTaskScheduler(void)
{
   if(fiveHertz > 0)
   {
      fiveHertz--;  // reset the incremented value to 0
      BitZeroTog(); // call the function to toggle bit 0 
   }
   if(twoHertz > 0)
   {
      twoHertz--;   // reset the incremented value to 0
      BitOneTog();  // call the function to toggle bit 1
   }
   if(pointTwoFive > 0)
   {
      pointTwoFive--; // reset the incremented value to 0
      BitTwoTog();    // call the function to toggle bit 0 
   }
   if(twoMilliCount > 0)
   {
      twoMilliCount--;         // reset the incremented value to 0
      MotorControl(); // Call the motor operation function
      
   }
   if(check > 0)
   {
      check--;       // reset the incremented value to 0
      SpeedCheck();  // check the dip dwitch.
   }
   
}

void interrupt TimerInterruptGuy(void)
{
   TIMER_ZERO_FLAG_RESET;            // reset time flag
   ECT_TC0 += aWholeTwoMilliseconds; //16000 (2ms rate)
   
   if((interruptCount % 10) == 0)
   {
      twoMilliCount++; // increment this value every 2ms  
   } 
   if((interruptCount % 50) == 0)
   {
      fiveHertz++; // increment this value every 100ms 
   }
   if((interruptCount % 125) == 0)
   {
      twoHertz++;  // increment this value every 250ms
   }
   if((interruptCount % 1000) == 0)
   {
      pointTwoFive++; // increment this value every 2s
   }
   if((interruptCount % 2500) == 0)
   {
      check++; // increments the value every 5 secs
   }
   // we don't need to go further than decimal 2500, so we reset the value.
   if(interruptCount > 2500)
   {
      interruptCount = 0; 
   }
   
   
   // increment after every use case.

   interruptCount++;
   
}