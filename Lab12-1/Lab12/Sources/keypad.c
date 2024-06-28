#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "protos.h"
#include "defs.h"
#include <stdio.h>


//**********
// Kobe Liles, Timothy McNamara, NINA KIKISSAGBE
// 4/18/2024
// ECET 309
// Lab12
//**********

//gloabal variables
//hardware values for PORTA
const unsigned char detectedKeyPress[] =  {0xd7, 0xde, 0xed, 0xdd, 
                                           0xeb, 0xbb, 0x7d};
//LCD values                                           
const unsigned char keypadKeyPressValue[] = {'C', 'D', 'E', 'F', 
                                             'G', 'A', 'B'};
//rollpoll array                                    
const unsigned char rollPoll[] = {0x0e, 0x0d, 0x0b, 0x07};

//value which holds keypad value and gives it to LCD

unsigned char state = 1; 
unsigned int speakerValue;
volatile unsigned char readSwitch;
unsigned char lcdValue;
unsigned char i; //variable for index
  
void KeyPadState(void)
{
  //variables    
  unsigned char index = 0;  
  unsigned char match;
  switch(state)
  {

      case 1:
             for(index; index < 4; index++)
             {
               PORTA = rollPoll[index];
               readSwitch = PORTA;
               readSwitch = PORTA;
               match = keyPad(readSwitch);
               if(!(match == 0xFF))
               {
                 PTT_PTT5 = 1;//turn on speaker
                 state = 2;//return to state 2 
               }
               else
               {
                 state = 1;//return back to state 2
               }
              }
             break;
              
      case 2:
             Delay(1000);//delay 1ms
             state = 3;//return to state 3 
             break;
             
      case 3:
             while(PORTA == match)
             {
               ; 
             }
             PTT_PTT5 = 0;//turn off speaker
             state = 4;//waiting for key realse
             break;
             
      case 4:
             Delay(1000);//delay 1ms
             state = 1;//loop back to state 1 
             break;
   }
}                                    
                                    
unsigned char keyPad(unsigned char val1)
{
  
  for(i = 0; i < 7; i++)
  {
      if(val1 == detectedKeyPress[i]) //step thru array until index value equals predetmined value
      {
         lcdValue = keypadKeyPressValue[i];
         return keypadKeyPressValue[i]; //return value if val1 = i
      }
  }
  return 0xff; //if vslue not found, return 0xff
}

//delay function
void Delay(unsigned long count)
{
  unsigned int i;
  for(i = 0; i < count; i++)
  {
     ;
  }
}