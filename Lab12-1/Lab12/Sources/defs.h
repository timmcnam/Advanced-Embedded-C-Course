//********
// Kobe Liles
// lab12
// 4/18/2024
//********






//define bits
#define BIT0 0x01
#define BIT1 0x02
#define BIT2 0x04
#define BIT3 0x08
#define BIT4 0x10
#define BIT5 0x20
#define BIT6 0x40
#define BIT7 0x80


//macros for RS/RW/EN 
#define LCD_RS_ON   (PORTD |= BIT5)
#define LCD_RS_OFF   (PORTD &= ~BIT5)
#define LCD_RW_ON   (PORTD |= BIT6)
#define LCD_RW_OFF   (PORTD &= ~BIT6)
#define LCD_EN_ON   (PORTD |= BIT7)
#define LCD_EN_OFF   (PORTD &= ~BIT7)

//macros for display 
#define HOME_DISPLAY 0x02;
#define CLEAR_DISPLAY 0x01;
#define SECOND_LINE 0xc0;

//macros for busyflag
#define LCD_DDR_D7_ON (DDRK |= BIT7)
#define LCD_DDR_D7_OFF (DDRK &= ~BIT7)
#define LCD_D7 (PORTK & BIT7)


//macros for blacklight
#define DISPLAY_OFF (PORTE &= ~(BIT2 | BIT3))
#define DISPLAY_RED (PORTE |= BIT2) & (PORTE &= ~BIT3)
#define DISPLAY_GREEN (PORTE &= ~BIT2) & (PORTE |= BIT3)
#define DISPLAY_BLUE (PORTE |= (BIT2 | BIT3))

//enable global interrupts
#define ENABLE_INT asm cli 

 