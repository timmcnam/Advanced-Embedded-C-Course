#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "Protos.h"   //Function Prototypes File

unsigned char count1;  // Globally declaring these variables for later use
unsigned char count2;  // in their respective functions (for loops). 

// This array is used to represent physical key presses and their
// hardware encoded addresses. Each array is parallel from each other
// so it can have it's place and value transparently passed.
const unsigned char keyPressArr[15]={0xd7, 0xee, 0xde, 0xbe,
                                     0xed, 0xdd, 0xbd, 0xeb,
                                     0xdb, 0xbb, 0x7e, 0x7d,
                                     0x7b, 0x77, 0xe7, 0xb7};

// This array has the value of each key pad expressly placed on
// the front of the keys.                                    
const unsigned char decArr[15]={0, 1, 2, 3,
                                4, 5, 6, 7,
                                8, 9, 'A', 'B',
                               'C', 'D', '*', '#'};
// This is the ASCII value of each alphabetical and symbol shown on
// the keys of the keypad.                                 
const unsigned char asciiArr[15]={0x30, 0x31, 0x32, 0x33,
                                  0x34, 0x35, 0x36, 0x37,
                                  0x38, 0x39, 0x41, 0x42,
                                  0x43, 0x44, 0x2A, 0x23};
                                  
// This is the first function. This function takes the key button pressed 
// physically and transposes it to a digital "decimal" value our program can 
// read.
volatile unsigned char DetermineDecimalNum (volatile unsigned char decValue)
{
  for(count1 = 0; count1 < 16; count1++)
  {   
      // checking in first array if value recieved exists.
   if(keyPressArr[count1] == decValue)
   {
      // if it exists, return digital value.
      return decArr[count1];   
   }
  }
  // if doesn't exist, return hex FF.
  return 0xFF;
}

// Second Function gets the physical key button address and returns the
// ASCII hex value for it.   
volatile unsigned char DetermineAsciiVal (volatile unsigned char asciiValue)
{
 for (count2 = 0; count2 < 16; count2++)
 {
  // checking if the first array again has the passed hardware address.
  if(keyPressArr[count2] == asciiValue)
  {
     //if yes, return this.
     return asciiArr[count2];
  }
 }
 //else return this hex FF.
 return 0xFF;
}

