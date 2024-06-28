#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "Protos.h"
#include "defs.h"
#include <stdio.h>

// Programmer(s) Name: Timothy McNamara
// Title of Program: Lab 11
// Date: 04/02/2024
// Class: ECET 30900 (49900)
// Due Date: 04/02/2024
/* Brief explanation of program, one to three lines

*/

// For now, put your Function Prototypes here

//Uninitialized Global Variables here.

//Initialized Global Variables here.






void main(void) 
{
  InitializePorts();
  TimerInitialize();
  InitializeLCD();
  PORTE = 0x04;

  for(;;) 
  {
    
    SPEAKER_OFF;
    while(PTS_PTS4)
    {
      ;	
    }
    Delay(20);
    
    while(!(PTS_PTS4))
    {
      Command(CLEAR_DISPLAY);
      Command(HOME_DISPLAY); 
    }
    SonarStart();
    SonarCheck();
    
   
      
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}




