#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "Protos.h"   //Function Prototypes File

/*
  Timothy McNamara
  ECET 49900
  Lab 03
  Last Revised: 01/25/2024
*/

volatile unsigned char portAReader;
unsigned char returnedKeyPress;
unsigned int i;
unsigned char count1;  // Globally declaring these variables for later use
unsigned char count2;  // in their respective functions (for loops). 

// This array is used to represent physical key presses and their
// hardware encoded addresses. Each array is parallel from each other
// so it can have it's place and value transparently passed.
const unsigned char keyPressArr[]={0xd7, 0xee, 0xde, 0xbe,
                                     0xed, 0xdd, 0xbd, 0xeb,
                                     0xdb, 0xbb, 0x7e, 0x7d,
                                     0x7b, 0x77, 0xe7, 0xb7};

// This array has the value of each key pad expressly placed on
// the front of the keys.                                    
const unsigned char decArr[]={0, 1, 2, 3,
                                4, 5, 6, 7,
                                8, 9, 'A', 'B',
                               'C', 'D', '*', '#'};
// This is the ASCII value of each alphabetical and symbol shown on
// the keys of the keypad.                                 
const unsigned char asciiArr[]={0x30, 0x31, 0x32, 0x33,
                                  0x34, 0x35, 0x36, 0x37,
                                  0x38, 0x39, 0x41, 0x42,
                                  0x43, 0x44, 0x2A, 0x23};
                                  
const unsigned char pollBoy[]={0x0e, 0x0d, 0x0b, 0x07};
  

                                  
// This is the first function. This function takes the key button pressed 
// physically and transposes it to a digital "decimal" value our program can
// read.
volatile unsigned char DetermineDecimalNum (unsigned char num1)
{
  for(count1 = 0; count1 < 16; count1++)
  {   
      // checking in first array if value recieved exists.
   if(keyPressArr[count1] == num1)
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
volatile unsigned char DetermineAsciiVal (unsigned char num2)
{
 for (count2 = 0; count2 < 16; count2++)
 {
  // checking if the first array again has the passed hardware address.
  if(keyPressArr[count2] == num2)
  {
     //if yes, return this.
     return asciiArr[count2];
  }
 }
 //else return this hex FF.
 return 0xFF;
}

// Initializes the keypad, the resistors tied to it, and the LEDs.
// We set the first four bits of PORTA as inputs in order for the
// four rows of the keypads to act as active lows. When a zero is
// detected on any row, we can summize that a key stroke has occured
// and we should determine its value! If no 0 is detected, a hex 
// value of FF will be returned.
void InitializeKeypadAndSuch (void)
{
     DDRA = 0x0F;
     PUCR_PUPAE = 0x01;
     DDRC = 0xFF;  
}

// This function acts as a delay and allows us to kill time with
// whatever non signed function we pass to it.
void Delay (unsigned char j)
{
  
  // while the passed value is greater than 0
  while (j > 0)
  {
   // decrement j
   j--;
  }
}

// In this function we shift PORTC over 4 bits. Then we take 
// whatever is in port C and or with a value that we and with 
// another value first. So we first "AND" the passed value with
// 0x0F. Since the value returned will only be four bits, we can
// do this. After this "AND" function, a number will be return
// like this 0x0X. The 'X' represents "Don't care". When we
// use this number with a set function "|=". 
// Since, we shifted over the four bits before hand. We leave 
// our previous value unaffected and then show the binary 
// value of the key we just pressed!
void KeyWrite (unsigned char val)
{
     PORTC <<= 4;
     PORTC |= (val & 0x0F);
}

// Here we wait for the button to be let go of. While the button
// we pressed matches the value in port A (meaning the value has
// not changed) we will do nothing until it changes. Back to
// 0xFF of course since this represents no value being pressed.
void KeyRelease (unsigned char matchedValue)
{
     while (matchedValue == PORTA)
     {
         ;
     }
}

// This function will create a for loop, that will cover the entire
// function due to the poll array encompassing the rows of the keypad.
// Each poll will determine if a key press has occured. 0x0E is row 0,
// 0x0D is row 1, 0x0B is row 2, and 0x07 is row 3. i = 0 refers to 
// row 0 and so on. Now, as we increment through the array, if 0xFF
// is found, we will keep going and eventually reset due to the function
// being in the endless for loop in main. But, it a key press is
// detected, we will get a value other than 0xFF and we can move onto
// calling the function and we will pass the value read in PORTA.
// We have to read the value in PORTA twice as to not always 
// get an error or underterminable value read from port A that is
// no in any of the bounds of our prewritten parallel arrays.
void GetKeyPress (void)
{
     for (i=0;i<4;i++)
     {
         
         PORTA = pollBoy[i];
         portAReader = PORTA;
         portAReader = PORTA;
         
         // if we have a match, we will actually get a match value returned
         // to then write to the LEDs.
         returnedKeyPress = DetermineAsciiVal(portAReader);
     
         if (!(returnedKeyPress == 0xFF))
         {
             KeyWrite(returnedKeyPress);
             Delay(2000);
             KeyRelease(portAReader);
             Delay(2000);		
         }
        
     }  
}
