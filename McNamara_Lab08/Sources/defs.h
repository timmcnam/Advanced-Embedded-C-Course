/*
  Timothy McNamara
  ECET 49900
  Lab 08
  Last Revised: 02/27/2024
*/

#define BIT_0 0x01
#define BIT_1 0x02
#define BIT_2 0x04
#define BIT_3 0x08
#define BIT_4 0x10
#define BIT_5 0x20
#define BIT_6 0x40
#define BIT_7 0x80

#define RIGHT_TURN (PORTB & BIT_0) 
#define FLASHERS (PORTB & BIT_4)
#define LEFT_TURN (PORTB & BIT_7)

// This macro writes to the CRGINT register and sets
// the Real Time Interrupt Enable Bit (RTIE) to 1
#define ENAB_INTERRUPTS (CRGINT = BIT_7)

// This macro writes to BIT 7 of CRGFLG register. Bit 7
// is the Real Timer Interrup Flag and when it equals 1,
// a timeout occurs. 
#define CLEAR_FLAG (CRGFLG = BIT_7)


#define CLOCK_AND_RESET_GEN (CRGINT_RTIE = 1)

// This macro Real Time Interrupt Control Register
// (RTICTL) and sets the interrupt time interval to
// 4.096 milliseconds. By writing hex 70 to the register
// we can set the time interval for the interrupt request.
#define INTERRUPT_OCCURANCE (RTICTL = 0x70)

// This macro uses an assembly command to clear the I command
// and enable interrupts. Since the C languange model
// allows assembly commands. We use ams before the command so
// the compiler knows this line is specifically for an
// assembly command.
#define ENABLE_INT asm cli


