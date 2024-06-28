#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "Protos.h"
#include "defs.h"

// Programmer(s) Name: Timothy McNamara
// Title of Program: Lab 09
// Date: 03/05/2024
// Class: ECET 30900 (49900)
// Due Date: 03/11/2024
/* This Lab utilizes interrupt timers channels an a task scheduler to
   flash LEDs at a specific rate and change the duty cycle operation of
   DC motor.
*/

void main(void) 
{
  Init();
  TimerInitialize();

  for(;;) 
  {
     ThePoshTaskScheduler();
      
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}



