//********
// Kobe Liles
// lab12
// 4/18/2024
//********

//prototypes in taskscheduler.c 
void InitializePorts(void);
void InitializeTimer(void);
void interrupt SpeakerInterrupt(void);
void interrupt TaskInterrupt(void);
void TaskScheduler(void);

//prototypes in statemachines.c
void KeyPadState(void);
unsigned char keyPad(unsigned char);
void LCDState(void);
void InitializeDisplay(void);
void WriteCommands(unsigned char);
void SendString(char*);
void Delay(unsigned long);



