#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "Protos.h"
#include "defs.h"

/*
  Timothy McNamara
  ECET 49900
  Lab 06
  Last Revised: 02/13/2024
*/

// Here we globaly declare the array initializer. 
// It would be best if this was locally declared but it is no harm here.
// Each array value is a command that the LCD will take and then
// execute. These commands help initialize the LCD upon startup.
unsigned char lcdArrayInitializer[] = { 0x30, 0x30, 0x30, 0x38, 
                                        0x0f, 0x01, 0x06};

void InitializeLCDPorts(void)
{
   // These are macro calls that set the corresponding
   // Data directional registers. Here we change all bits
   // of PORTK as outputs and the bits 7-5 of PORTD as
   // outputs. 
   DB_DDRX_OUTPUT;
   PORTD_DDRX;  
}

void InitializeLCD(void)
{
   // Here we create a for loop to cycle through each command
   // to send to the LCD. However, since they are commands 
   // themselves, I pass it to the nested Command Function.
   int i;
   for(i = 0; i < 7; i++)
   {
        Command(lcdArrayInitializer[i]);
   }
}

void Command(unsigned char k)
{
   // Here we recieve the command and set that passed
   // command value to "k". Now we do a macro call
   // and set the LCD_DATA (which is PORTK) to the k value.
   // To send a command, we have to turn off the RS bit,
   // turn off the RW bit, and toggle the ELINE bit to 
   // register each bit. This has to be done by setting
   // and clearing each bit since the toggle operator
   // (^=) is too quick for our LCD. And at the end we 
   // We create a delay to ensure that the LCD can
   // process the commands.
   LCD_DATA = k;
   LCD_RS_OFF;
   LCD_RW_OFF;
   ELINE_ON;
   ELINE_OFF; 
   Delay(20000); 
}

void Display(char *p)
{
    // In order to print each string value to the LCD, we have to either
    // create passed array variable or (what I did) create a pointer
    // That can point to each value in the string. The boolean logic 
    // in the while loop becomes easy as it will end when every single
    // string has been pointed. Also, to write to the screen, we 
    // set the RS bit and clear the RW bit. And of course, we toggle the
    // ELINE bit and call a delay.
    while(*p)
     {
         LCD_DATA = *p++;
         LCD_RS_ON;
         LCD_RW_OFF;
         ELINE_ON;
         ELINE_OFF;
         Delay(20000);         
     }
     
}

void Delay(long time)
{
   // while the delay value is greater than 0, decrement.
   while(time > 0)
   {
      time--;  
   }
}