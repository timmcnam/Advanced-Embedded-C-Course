#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "Protos.h"   //Function Prototypes File


// Programmer(s) Name: Timothy McNamara
// Title of Program: Lab 02
// Date: 01/17/2024
// Class: ECET 49900
// Due Date: 01/18/2024
/* This program covers the use of the keypad. However, this program does not use
   the program simulates the keypress of the hardware and goes through 3 parallel
   arrays to find the corresponding decimal value and the ASCII value. This is done 
   via 2 functions.
*/  


// the preset value is used is purely for simulation purposes.
volatile unsigned char presetValue = 0x7B;

// This variable is used the show the "decimal number value" the
// array returned.
volatile unsigned char decNuVa;

// This variable is used the show the "ASCII number value" the
// array returned.
volatile unsigned char asciiNuVa;

void main(void) 
{
  // setting the previously declared variables equal to what is
  // returned to the function.
  decNuVa = DetermineDecimalNum(presetValue);
  asciiNuVa = DetermineAsciiVal(presetValue);

  for(;;) 
  {
     
      
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}



