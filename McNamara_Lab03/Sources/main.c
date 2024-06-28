#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "Protos.h"

// Programmer(s) Name: Your Name
// Title of Program: Lab #03
// Date: 01/23/2023
// Class: ECET 30900 (49900)
// Due Date: 01/25/2023
/* The program you see before you will read the keypad press and
   then output it to the LEDs
*/

void main(void) 
{
  // Initialize our I/Os
  InitializeKeypadAndSuch();

  for(;;) 
  {
     // Calling get key press function to do all our heavy lifting.
     GetKeyPress();
      
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}




