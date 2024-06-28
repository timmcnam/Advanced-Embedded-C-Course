#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "Protos.h"

// Programmer(s) Name: Timothy McNamara
// Title of Program: Lab 01
// Date: 01/09/2023
// Class: ECET 30900
// Due Date: 01/11/2023
// Brief explanation of program, one to three lines

//Function Prototypes here

//Uninitialized Global Variables here.
  
unsigned char table[6]; // {1}, {1}, {2}, {6}, {24}, {120}
   
   // The Function Fact is called 16 times.
       
//Initialized Global Variables here.



void main(void) 
{
  
  unsigned char x = 72;
  x %= 6;

 //  FillTable();



  for(;;) 
  {
     
      
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}

void FillTable(void)
{
   int i;
   
   for (i = 0; i < 6; i++)
      table[i] = Fact(i);
}

/* Recursive Factorial Function
*/

int Fact(int num)
{
   if (num < 2)
      return (1);
   else
      return (num * Fact(num - 1));
}



