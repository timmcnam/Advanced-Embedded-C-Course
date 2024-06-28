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

/*
volatile unsigned int milliSecTime;

// This function uses the Interrupts timing to
// cause a delay. Every time the interrupt function
// is called it increments the value used in the 
// while loop below.  
void RTIDelay(void)
{
   milliSecTime = 0;
   while(milliSecTime<122)
   {
      ;  
   }
}

void RTIInitial(void)
{ 
   ENAB_INTERRUPTS; // Enable realtime interrrupt on
   CLOCK_AND_RESET_GEN; // CRT: clocks and reset generators
   INTERRUPT_OCCURANCE; // interrupt will happen every 4.096 ms
   ENABLE_INT; // Global interrupts on
}

// This function calls the interrupt. It's vector address
// has been mapped in the project prm file as 0xFFF0.
// This function when called clears the routine and increments
// the variable used in the delay function up above.
void interrupt RTIServiceRout(void)
{
   CLEAR_FLAG;
   milliSecTime++; 
}
*/
