/*
  Timothy McNamara
  ECET 49900
  Lab 05
  Last Revised: 02/06/2024
*/
 
// Here we hard code each single bit and what their hex
// value should be. This allows us to easily compare
// our defined variables in the defs.h and use boolean
// logic to compare the state of PORTC and PORTB and
// their corresponding bits.
#define BIT_0 0x01
#define BIT_1 0x02
#define BIT_2 0x04
#define BIT_3 0x08
#define BIT_4 0x10
#define BIT_5 0x20
#define BIT_6 0x40
#define BIT_7 0x80

// For this lab we are instructed to create 4 singular
// macro calls. LED_ENABLED will enable a specific LED
// in the DDRC that we can output to. LED_ON will
// set a certain bit. LED_OFF will clear a specific bit.
// SWITCH_STATE will check if a bit on PORTB is high.
// The specifics of each bit or what is checked is
// determined by what value is passed to it. This is
// represented by (n) which will later be replaced by 
// a value. This value is then appended to BIT_ by the
// double octothorp connector (##).
#define LED_ENABLED(n) (DDRC |= BIT_##n)
#define LED_ON(n) (PORTC |= BIT_##n)
#define LED_OFF(n) (PORTC &= ~BIT_##n)
#define SWITCH_STATE(n) (PORTB & BIT_##n) 


 