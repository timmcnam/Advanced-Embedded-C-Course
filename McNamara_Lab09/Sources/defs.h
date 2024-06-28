/*
  Timothy McNamara
  ECET 49900
  Lab 09
  Last Revised: 03/07/2024
*/

// We define each of these bits with a hex value in mind, 
// so we can use them subsequently. Whether we want to do 
// bit manipulation, etc.
#define BIT_0 0x01
#define BIT_1 0x02
#define BIT_2 0x04
#define BIT_3 0x08
#define BIT_4 0x10
#define BIT_5 0x20
#define BIT_6 0x40
#define BIT_7 0x80

// Globally enabling interrupts. Must be done for any of this to work.
#define ENABLE_INT asm cli

// Enable the Timer System
#define TIMER_SYSTEM_EN (ECT_TSCR1_TEN = 1)

// Enables the timer (0) as an TOC. 
// (Timer Output Capture)
#define ENABLE_TIMER_ZERO (ECT_TIOS_IOS0 = 1)

// enable timer interrupts
#define TIMER_ZERO_INTERRUPT_EN (ECT_TIE_C0I = 1)

// resets the timer interrupts
#define TIMER_ZERO_FLAG_RESET (ECT_TFLG1_C0F = 1)

// priming the channel for a match
#define TIMER_PRIMER (ECT_TC0 = ECT_TCNT + 16000)

// reads the output line of timer channel 0
#define TIMER_ZERO_OL (ECT_TCTL2_OL0 = 1)
#define TIMER_ZERO_OM (ECT_TCTL2_OM0 = 0)

// Check if BIT_0 of PORTB is high.
#define FAST_SPEED (PORTB & BIT_0)
#define SLOW_SPEED (PORTB & BIT_7)
