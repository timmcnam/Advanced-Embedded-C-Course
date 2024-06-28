/*
  Timothy McNamara
  ECET 49900
  Lab 03
  Last Revised: 01/23/2024
*/

// All prototypes are either self explanatory or have been 
// explained in previoue comments.
void Delay (unsigned char);
void InitializeKeypadAndSuch (void);
void KeyRelease (unsigned char);
void GetKeyPress (void);
void KeyWrite (unsigned char);
volatile unsigned char DetermineDecimalNum (unsigned char);
volatile unsigned char DetermineAsciiVal (unsigned char);
