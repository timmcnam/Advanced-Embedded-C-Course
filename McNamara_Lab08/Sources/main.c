#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "Protos.h"
#include "defs.h"

// Programmer(s) Name: Timothy McNamara
// Title of Program: Lab 08
// Date: 02/27/2024
// Class: ECET 30900 (49900)
// Due Date: 03/04/2024
/* This program uses the RTI to control at which either a turn signal
   or the flashers will display to the LEDs. But before we do this, we
   test our code using a delay before we intialize and use the RTI. 
*/

//Uninitialized Global Variables here.

//Initialized Global Variables here.

void main(void) 
{
  // Here Initialize the LEDS and call the initialization
  // function to enable interrupts and 
  DDRC = 0xFF;
  RTIInitial();


  for(;;) 
  {
    Taillights(); 
      
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}

