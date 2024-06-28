/*
  Timothy McNamara
  ECET 49900
  Lab 067
  Last Revised: 02/19/2024
*/

// Here lie the function prototypes. 
// There is five functions, two are passed nothing.
// 3 are passed values corresponding to their given 
// function purposes
 
void InitializeLCDPorts(void);
void InitializeLCD(void);
void LCDBusyFlagRead(void);
void Command(unsigned char);
void Display(char*);
void LCDBacklight(unsigned char);
void Delay(long);