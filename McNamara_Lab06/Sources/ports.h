/*
  Timothy McNamara
  ECET 49900
  Lab 06
  Last Revised: 02/13/2024
*/

// Here we define PortB and PortC and their
// corresponding data directional registers in 
// memory. Each #define using the pointer method
// of pointing to where in memory they should be
// located. We do not need to change the DDRB
// since it will already be defaulted to all
// inputs.  

// #define PORTB (*(volatile unsigned char*)(0x01))
// #define PORTC (*(volatile unsigned char*)(0x04))
// #define DDRC (*(volatile unsigned char*)(0x06))