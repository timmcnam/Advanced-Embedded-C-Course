#include <hidef.h>      /* common defines and macros */
//#include "derivative.h"      /* derivative-specific definitions */
#include "Protos.h"
#include "ports.h"
#include "defs.h"

// Programmer(s) Name: Timothy McNamara
// Title of Program: Lab 
// Date: 01/30/2024
// Class: ECET 30900 (49900)
// Due Date: 02/05/2024
/* This Program uses bit mapping and bit fields to create our own I/Os.
   We also use bit manipulation to change the state of the I/O ports.
*/

void main(void) 
{
  
  // Here we call our ports from the ports.h file. We obviously
  // set PORTB as inputs and PORTC as outputs. I was unsure if
  // these ports would automatically be set as inputs or outputs
  // due to us deleting the MC9S12XEP100.c and MC9S12XEP100.h file. 
  DDRB = 0x00;
  DDRC = 0xFF;
   
  for(;;) 
  {
    
   // Here we call the function for part 1 of the lab. 
   // *See below for more details.*
   // Traditional();
   
   // Here we call the second function for part 2 of the lab.
   // *See below for more details*
   Modern(); 
      
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}

// This function uses the #define's from ports.h file and the defs.h file.
// The #define's in the ports.h file point to specific addresses in memory
// for us to use. In the defs.h file, we define each bit (BIT0 -BIT7) as
// a specific hex value that in binary represents a bit mapped value that
// is translational to both PORTB and PORTC. Doing this allows us to 
// take up no memory.
/*
   void Traditional(void)
   {
      
     if(PORTB & BIT_0) // test: is switch 0 high?
     {
         PORTC |= BIT_7; // if switch 0 is high, set LED bit 7
     }
     else
     {
         PORTC &= ~BIT_7; //if switch 0 is low, clear LED bit 7
     }

     if(PORTB & BIT_1) // test: is switch 1 high?
     {
         PORTC |= BIT_6; // if switch 1 is high, set LED bit 6
     }
     else
     {
         PORTC &= ~BIT_6; //if switch 1 is low, clear LED bit 6
     }

     if(PORTB & BIT_2) // test: is switch 2 high?
     {
         PORTC |= BIT_5; // if switch 2 is high, set LED bit 5
     }
     else
     {
         PORTC &= ~BIT_5; //if switch 2 is low, clear LED bit 5
     }

     if(PORTB & BIT_3) // test: is switch 3 high?
     {
         PORTC |= BIT_4; // if switch 3 is high, set LED bit 4
     }
     else
     {
         PORTC &= ~BIT_4; //if switch 3 is low, clear LED bit 4
     }
     
     if(PORTB & BIT_4) // test: is switch 4 high?
     {
         PORTC |= BIT_3; // if switch 4 is high, set LED bit 3
     }
     else
     {
         PORTC &= ~BIT_3; //if switch 4 is low, clear LED bit 3
     }

     if(PORTB & BIT_5) // test: is switch 5 high?
     {
         PORTC |= BIT_2; // if switch 5 is high, set LED bit 2
     }
     else
     {
         PORTC &= ~BIT_2; //if switch 5 is low, clear LED bit 2
     }
     
     if(PORTB & BIT_6) // test: is switch 6 high?
     {
         PORTC |= BIT_1; // if switch 6 is high, set LED bit 1
     }
     else
     {
         PORTC &= ~BIT_1; //if switch 6 is low, clear LED bit 1
     }
     
     if(PORTB & BIT_7) // test: is switch 7 high?
     {
         PORTC |= BIT_0; // if switch 7 is high, set LED bit 0
     }
     else
     {
         PORTC &= ~BIT_0; //if switch 7 is low, clear LED bit 0
     }  
   }
*/

// This function uses the BITS_OF_A_PORT structure in defs.h and
// the same #defines in ports.h file (the DDRC and DDRB). Using the
// instance of the structure made in the defs.h file, we are able
// then use PORTC and PORTB variable we created along with the
// dot operator to read specific bit defined in the structure and
// read them. Use if statements, we are able to see if a 1 is 
// read at PORTB.BIT_X. If a 1 is not read, then we will write a 
// 1 or a 0 to a specific bit on PORTC. 
void Modern(void)
{

   if(PORTB.BIT_0) // test: is switch 0 high?
  {
      PORTC.BIT_7 = 1; // if switch 0 is high, set LED bit 7
  }
  else
  {
      PORTC.BIT_7 = 0; //if switch 0 is low, clear LED bit 7
  }

  if(PORTB.BIT_1) // test: is switch 1 high?
  {
      PORTC.BIT_6 = 1; // if switch 1 is high, set LED bit 6
  }
  else
  {
      PORTC.BIT_6 = 0; //if switch 1 is low, clear LED bit 6
  }

  if(PORTB.BIT_2) // test: is switch 2 high?
  {
      PORTC.BIT_5 = 1; // if switch 2 is high, set LED bit 5
  }
  else
  {
      PORTC.BIT_5 = 0; //if switch 2 is low, clear LED bit 5
  }

  if(PORTB.BIT_3) // test: is switch 3 high?
  {
      PORTC.BIT_4 = 1; // if switch 3 is high, set LED bit 4
  }
  else
  {
      PORTC.BIT_4 = 0; //if switch 3 is low, clear LED bit 4
  }
  
  if(PORTB.BIT_4) // test: is switch 4 high?
  {
      PORTC.BIT_3 = 1; // if switch 4 is high, set LED bit 3
  }
  else
  {
      PORTC.BIT_3 = 0; //if switch 4 is low, clear LED bit 3
  }

  if(PORTB.BIT_5) // test: is switch 5 high?
  {
      PORTC.BIT_2 = 1; // if switch 5 is high, set LED bit 2
  }
  else
  {
      PORTC.BIT_2 = 0; //if switch 5 is low, clear LED bit 2
  }
  
  if(PORTB.BIT_6) // test: is switch 6 high?
  {
      PORTC.BIT_1 = 1; // if switch 6 is high, set LED bit 1
  }
  else
  {
      PORTC.BIT_1 = 0; //if switch 6 is low, clear LED bit 1
  }
  
  if(PORTB.BIT_7) // test: is switch 7 high?
  {
      PORTC.BIT_0 = 1; // if switch 7 is high, set LED bit 0
  }
  else
  {
      PORTC.BIT_0 = 0; //if switch 7 is low, clear LED bit 0
  } 
}
