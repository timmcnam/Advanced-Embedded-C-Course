/*
  Timothy McNamara
  ECET 49900
  Lab 06
  Last Revised: 02/13/2024
*/
 
// Here we define each bit of a byte of memory
#define BIT_0 0x01
#define BIT_1 0x02
#define BIT_2 0x04
#define BIT_3 0x08
#define BIT_4 0x10
#define BIT_5 0x20
#define BIT_6 0x40
#define BIT_7 0x80
#define HELLO_KITTY ">.<"

// Here I created macros to clear and set each bit of
// PORTD. Bit 7-5 to be exact. We also created a macro
// to define another name for PORTK and not confuse the
// logic in these functions.
#define LCD_RS_ON (PORTD |= BIT_5)
#define LCD_RS_OFF (PORTD &= ~BIT_5)
#define LCD_RW_ON (PORTD |= BIT_6)
#define LCD_RW_OFF (PORTD &= ~BIT_6)
#define ELINE_ON (PORTD |= BIT_7)
#define ELINE_OFF (PORTD &= ~BIT_7)
#define LCD_DATA (PORTK)

// These macros help initialize the I/Os we will be using.
#define DB_DDRX_OUTPUT (DDRK = 0xFF)
#define PORTD_DDRX (DDRD = 0xE0) 
 


 