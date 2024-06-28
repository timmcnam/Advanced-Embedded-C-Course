#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "Protos.h"
#include "defs.h"

/*
  Timothy McNamara
  ECET 49900
  Lab 11
  Last Revised: 04/02/2024
*/

void TimerInitialize(void)
{
   //ENABLE_INT;
   TIMER_SYSTEM_EN;
   TIMER_SCALAR;
   ENABLE_TIMER_SIX;
   ENABLE_TIMER_SEVEN;
   TIMER_SIX_EDGA;
   TIMER_SIX_EDGB;
   TIMER_SEVEN_EDGA;
   TIMER_SEVEN_EDGB;
}

