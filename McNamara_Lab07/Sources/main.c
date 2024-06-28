#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "Protos.h"
#include "defs.h"

// Programmer(s) Name: Your Name
// Title of Program: Lab 07
// Date: 02/20/2024
// Class: ECET 30900 (49900)
// Due Date: 02/26/2024
/* This Lab focuses on creating functions to write to the LCD. However,
   for the following lab, we must be able to create a program to write
   to the second line of the LCD.
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
  LCDBacklight(DISPLAY_GREEN);
  Display("My 1st Message");
  Delay(20000);
  Display("My 2nd big message!");
  Delay(20000);

  for(;;) 
  {
     
      
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}
