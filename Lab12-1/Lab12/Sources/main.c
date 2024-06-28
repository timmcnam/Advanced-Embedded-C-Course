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

void main(void) 
{
  //initialing I/O, timers, interrupts, and display
  InitializePorts();
  InitializeTimer();
  InitializeDisplay();

  for(;;) 
  {
    //calling taskscheduler infintiely
    TaskScheduler();
    _FEED_COP(); 
  } 
  
}
