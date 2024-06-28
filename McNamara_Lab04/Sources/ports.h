/*
  Timothy McNamara
  ECET 49900
  Lab 04
  Last Revised: 01/30/2024
*/

// Here we define PortB and PortC and their
// corresponding data directional registers in 
// memory. Each #define using the pointer method
// of pointing to where in memory they should be
// located. However we comment out PORTB and PORTC
// due to the second part of the lab where we 
// use structure based macros to define our variables.  

// #define PORTB (*(volatile unsigned char*)(0x01))
// #define PORTC (*(volatile unsigned char*)(0x04))
 #define DDRB (*(volatile unsigned char*)(0x03))
 #define DDRC (*(volatile unsigned char*)(0x06))