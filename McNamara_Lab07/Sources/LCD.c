#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "Protos.h"
#include "defs.h"

/*
  Timothy McNamara
  ECET 49900
  Lab 07
  Last Revised: 02/20/2024
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
   // outputs. We also set bits 2 & 3 of DDRE so we can
   // change to color of the backlight. 
   DB_DDRX_OUTPUT;
   PORTD_DDRX;
   LCD_COLOR_DDRX;  
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
   //LCDBusyFlagRead();
   Delay(20000); 
}

void Display(char *p)
{
    int w = 0;
    
    // This function utilizes a while loop and creates a pointer
    // variable to point to each character of the string.
    // To write data to the LCD we must turn RS bit on, and turn
    // RW off. ELINE must be toggled, so we quickly turn it on and
    // off. The difference between this function and the previous
    // week's lab is that we add in a local variable called "w".
    // This variable counts every string character passed to the
    // function. If the w variable is incremented to 16, we then
    // send commands to the command function to home the cursor
    // and jump to the next line. Then we continue writing the
    // string characters to the next line.
    while(*p != 0)
     {
         LCD_DATA = *p++;
         LCD_RS_ON;
         LCD_RW_OFF;
         ELINE_ON;
         ELINE_OFF;
         w++;
         LCDBusyFlagRead();
         Delay(20000);
         if (w == 16)
         {
            Delay(20000);
            Command(HOME_DISPLAY);
            Delay(20000);
            Command(SECOND_LINE);	    
         } 
     }
     
     if (w < 16)
     {
        Delay(20000);
        Command(CLEAR_DISPLAY);  
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

void LCDBusyFlagRead(void)
{
   // Macros are used to read the busy flag and kill time until it
   // becomes high.
   LCD_DDR_BIT7_INPUT;
   ELINE_ON;
   LCD_RS_OFF;
   LCD_RW_ON;
   
   while(LCD_BIT7_READ)
   {
      ELINE_OFF;
      ELINE_ON;   
   }
   LCD_DDR_BIT7_OUTPUT;
}

void LCDBacklight(unsigned char valuable)
{
  // PORTE, bits 2 & 3, decide the color of the back of
  // LCD. Upon calling it in main, I type in a macro that
  // are defined to set the LCD a certain color. 
  PORTE = valuable;
}