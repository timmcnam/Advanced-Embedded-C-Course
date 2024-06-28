#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "defs.h"
#include "Protos.h"

/*
  Timothy McNamara
  ECET 49900
  Lab 08
  Last Revised: 02/27/2024
*/


// This dealy uses a passed value to decrement
// and kill time before goign onto the next value
// in the array.
void Delay (unsigned long value)
{
  while(value > 0)
  {
    value--;
  }
}




void Taillights(void)
{
   // these arrays mimic stages of both turn signals and
   // the flashing lights on tail lights of a car. 
   unsigned char leftTurnArray[]= {0b00100000, 0b01100000,
                                   0b11100000, 0b00000000};
                      
   unsigned char rightTurnArray[] = {0b00000100, 0b00000110,
                                     0b00000111, 0b00000000};
                       
   unsigned char flashArray[] = {0b11100111, 0b00000000};
   
   // This function uses defined macros that read PORTB
   // swithches. If Switch 0 is high and the other switches
   // are low, then we will cycle through the array and 
   // display the right turn signal values.  
   if(RIGHT_TURN && !(LEFT_TURN) && !(FLASHERS))
   {
     unsigned int r;
     for(r = 0; r < 4; r++)
     {
        PORTC = rightTurnArray[r];
        //Delay(150000);
        RTIDelay();
         
     }
   }
   // This function uses defined macros that read PORTB
   // swithches. If Switch 7 is high and the other switches
   // are low, then we will cycle through the array and 
   // display the left turn signal values. 
   else if(LEFT_TURN && !(RIGHT_TURN) && !(FLASHERS))
   {
     unsigned int l;
     for(l = 0; l < 4; l++)
     {
        PORTC = leftTurnArray[l];
        //Delay(150000);
        RTIDelay();
     }
   }
   // This function uses defined macros that read PORTB
   // swithches. If Switch 4 is high and the other switches
   // are low, then we will cycle through the array and 
   // display the flasher signal values. 
   else if(FLASHERS && !(RIGHT_TURN) && !(LEFT_TURN))
   {
     unsigned int f;
     for(f = 0; f < 2; f++)
     {
        PORTC = flashArray[f];
        //Delay(175000);
        RTIDelay(); 
     }
   }
}