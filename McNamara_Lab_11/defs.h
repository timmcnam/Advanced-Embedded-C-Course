/*
  Timothy McNamara
  ECET 49900
  Lab 11
  Last Revised: 04/02/2024
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
#define DDRK_INIT (DDRK = 0xFF)
#define DDRD_INIT (DDRD = 0xE0)
#define DDRP_INIT (DDRP = 0x01)
#define DDRE_INIT (DDRE = 0x0C)
#define DDRC_INIT (DDRC = 0x07)
#define DDRT_INIT (DDRT = 0x40)


#define ENABLE_INT asm cli 

// Enable the Timer System
#define TIMER_SYSTEM_EN (ECT_TSCR1_TEN = 1)

#define TIMER_SCALAR (ECT_TSCR2 = 0x03)

// Enables the timer (0) as an TOC. 
// (Timer Output Capture)
#define ENABLE_TIMER_SIX (ECT_TIOS_IOS6 = 1)
#define ENABLE_TIMER_SEVEN (ECT_TIOS_IOS7 = 1)

#define TIMER_SIX_EDGA (ECT_TCTL3_EDG6A = 1)
#define TIMER_SIX_EDGB (ECT_TCTL3_EDG6B = 0)
#define TIMER_SEVEN_EDGA (ECT_TCTL3_EDG7A = 1)
#define TIMER_SEVEN_EDGB (ECT_TCTL3_EDG7B = 0)

#define TIMER_SIX_FLAG (ECT_TFLG1_C6F = 1)
#define TIMER_SEVEN_FLAG (ECT_TFLG1_C7F = 1)

#define SPEAKER_ON (PTIT_PTIT6 = 1)
#define SPEAKER_OFF (PTIT_PTIT6 = 0)

#define PB_PRESS (PTS_PTS4)

#define CLEAR_DISPLAY 0x01
#define HOME_DISPLAY 0x02
#define SECOND_LINE 0xc0
