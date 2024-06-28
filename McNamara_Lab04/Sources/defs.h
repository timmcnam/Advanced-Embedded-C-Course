/*
  Timothy McNamara
  ECET 49900
  Lab 04
  Last Revised: 01/30/2024
*/

// PART I
// Here we hard code each single bit and what their hex
// value should be. This allows us to easily compare
// our defined variables in the defs.h and use boolean
// logic to compare the state of PORTC and PORTB and
// their corresponding bits.
/*
#define BIT_0 0x01
#define BIT_1 0x02
#define BIT_2 0x04
#define BIT_3 0x08
#define BIT_4 0x10
#define BIT_5 0x20
#define BIT_6 0x40
#define BIT_7 0x80
*/

// PART II
// Here we create a structure and allocate a name for
// each bit of this structure. By calling each variable 
// an unsigned char, we allow ourselves to no go outside
// of 8 bits of a hex value. And since there are 8 bits
// on each of our PORTS in memory, we allocate BIT_0 
// through BIT_7. And we assign each value to on byte 
// using the colon symbol followed by how many bits a
// variable will take up.
struct BITS_OF_A_PORT
{
   volatile unsigned char BIT_0:1;
   volatile unsigned char BIT_1:1; 
   volatile unsigned char BIT_2:1; 
   volatile unsigned char BIT_3:1; 
   volatile unsigned char BIT_4:1; 
   volatile unsigned char BIT_5:1; 
   volatile unsigned char BIT_6:1;
   volatile unsigned char BIT_7:1;    
};

// using typedef, we allow ourselves to instantiate
// and instance of the structure and we define a
// new data type named BOAP. This allows us to use
// the structure for both of our ports and even more
// if we wanted to. 
typedef struct BITS_OF_A_PORT BOAP;

 // Now we declare the PORTB and C variables
 BOAP PORTB@0x01;
 BOAP PORTC@0x04; 
 