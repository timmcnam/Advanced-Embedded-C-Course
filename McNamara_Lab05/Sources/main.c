#include <hidef.h>      /* common defines and macros */
//#include "derivative.h"      /* derivative-specific definitions */
#include "Protos.h"
#include "ports.h"
#include "defs.h"

// Programmer(s) Name: Your Name
// Title of Program: Lab 05
// Date: 02/06/2024
// Class: ECET 30900 (49900)
// Due Date: 02/12/2024
/* This lab covers the macros again. However, we utilize macro function.
   We create 4 macro functions that will, enable an led to be written to,
   turn an LED on, turn an LED off, and read the state of the dip switches.
*/

void main(void) 
{

  for(;;) 
  {
     
     HALLab();
      
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}

void HALLab(void)
{
  if(SWITCH_STATE(0)) // test: is switch 0 high?
  { 
      LED_ENABLED(7); // if switch 0 is high, set LED bit 7
      LED_ON(7);
  }
  else
  {
      LED_ENABLED(7); //if switch 0 is low, clear LED bit 7
      LED_OFF(7);
  }

  if(SWITCH_STATE(1)) // test: is switch 1 high?
  {
      LED_ENABLED(6); // if switch 1 is high, set LED bit 6
      LED_ON(6);
  }
  else
  {
      LED_ENABLED(6); //if switch 1 is low, clear LED bit 6
      LED_OFF(6);
  }

  if(SWITCH_STATE(2)) // test: is switch 2 high?
  {
      LED_ENABLED(5); // if switch 2 is high, set LED bit 5
      LED_ON(5);
  }
  else
  {
      LED_ENABLED(5); //if switch 2 is low, clear LED bit 5
      LED_OFF(5);
  }

  if(SWITCH_STATE(3)) // test: is switch 3 high?
  {
      LED_ENABLED(4); // if switch 3 is high, set LED bit 4
      LED_ON(4);
  }
  else
  {
      LED_ENABLED(4); //if switch 3 is low, clear LED bit 4
      LED_OFF(4);
  }
  
  if(SWITCH_STATE(4)) // test: is switch 4 high?
  {
      LED_ENABLED(3); // if switch 4 is high, set LED bit 3
      LED_ON(3);
  }
  else
  {
      LED_ENABLED(3); //if switch 4 is low, clear LED bit 43
      LED_OFF(3);
  }

  if(SWITCH_STATE(5)) // test: is switch 5 high?
  {
     LED_ENABLED(2); // if switch 5 is high, set LED bit 2
     LED_ON(2);
  }
  else
  {
      LED_ENABLED(2); //if switch 5 is low, clear LED bit 2
      LED_OFF(2);
  }
  
  if(SWITCH_STATE(6)) // test: is switch 6 high?
  {
      LED_ENABLED(1); // if switch 6 is high, set LED bit 1
      LED_ON(1);
  }
  else
  {
      LED_ENABLED(1); //if switch 6 is low, clear LED bit 1
      LED_OFF(1);
  }
  
  if(SWITCH_STATE(7)) // test: is switch 7 high?
  {
      LED_ENABLED(0); // if switch 7 is high, set LED bit 0
      LED_ON(0);
  }
  else
  {
      LED_ENABLED(0); //if switch 7 is low, clear LED bit 10
      LED_OFF(0);
  }  
}



