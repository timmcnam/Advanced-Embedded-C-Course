#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "protos.h"
#include "defs.h"
#include <stdio.h>
//********
// Kobe Liles
// lab12
// 4/18/2024
//********



//array used for LCD display
signed char buffer[50];

//display commands
unsigned char array[] = {0x30, 0x30, 0x30, 0x38, 0x0f, 0x01, 0x06};

//state variable
unsigned char state2 = 1;
extern unsigned char lcdValue;

void LCDState(void)
{
    static unsigned char count;
      switch(state2)
      {
        case 1:
               PORTK = CLEAR_DISPLAY;//clear display
               LCD_RS_OFF;
               LCD_RW_OFF;
               LCD_EN_ON;
               LCD_EN_OFF;
               Delay(20000);
               
               PORTK = HOME_DISPLAY;//return cursor to home
               LCD_RS_OFF;
               LCD_RW_OFF;
               LCD_EN_ON;
               LCD_EN_OFF;
               Delay(20000);
               sprintf(buffer,"note = %c", lcdValue);//send lcd value to 
                                                      //buffer array
               state2 = 2; //return to state 2
               break; 
        case 2:
               Delay(20000);  
               state2 = 3;//if not busy return to state            
               break;
        case 3:
               SendString(buffer);//send buffer to LCD displau
               state2 = 4;//go to state 4
               break;
        case 4:
               if(count%200 == 0)//wait for count to cycle 200ms
               {  
                 state2 = 1; //return to state 1
                 
               }
               else
               {
                 count++;//increment counter
                 state2 = 4;//return back to state 4
               }
               
               break;
      }
}

//loop through global array and subroutine the value to 
//writecommands
void InitializeDisplay(void)
{
   unsigned char i;
   for(i = 0; i < 7; i++)
   {
     WriteCommands(array[i]); 
   }
}

//read commands that are passed in
void WriteCommands(unsigned char var)
{
   PORTK = var;
   LCD_RS_OFF;
   LCD_RW_OFF;
   LCD_EN_ON;
   LCD_EN_OFF;
   Delay(20000);
  
}

//sending string value to display
void SendString(char *var)
{
   while(*var)
   {
       
      PORTK = *var++;
      LCD_RS_ON;
      LCD_RW_OFF;
      LCD_EN_ON;
      LCD_EN_OFF;
      Delay(20000);     
   }
}







