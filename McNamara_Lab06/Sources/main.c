#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "Protos.h"
#include "defs.h"

// Programmer(s) Name: Your Name
// Title of Program: Lab 06
// Date: 02/13/2024
// Class: ECET 30900 (49900)
// Due Date: 02/19/2024
/* This Lab focuses on creating functions to write to the LCD.

*/

// For now, put your Function Prototypes here

// Uninitialized Global Variables here.

// Initialized Global Variables here.

void main(void) 
{
  // Here we call each function and pass a string value to the 
  // Display Function Call.
  InitializeLCDPorts();
  InitializeLCD();
  Display("My 1st Message");

  for(;;) 
  {
     
      
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}



