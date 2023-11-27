#ifndef REGISTER


#define  REGISTER
#define DDRA     *(u8 volatile*const)(0x3A)
#define DDRB     *(u8 volatile*const)(0x37)
#define DDRC     *(u8 volatile*const)(0x34)
#define DDRD     *(u8 volatile*const)(0x31)
#define PORTA    *(u8 volatile*const)(0x3B)
#define PORTB    *(u8 volatile*const)(0x38)
#define PORTC    *(u8 volatile*const)(0x35)
#define PORTD    *(u8 volatile*const)(0x32)
#define PINA     *(u8 volatile*const)(0x39)
#define PINB     *(u8 volatile*const)(0x36)
#define PINC     *(u8 volatile*const)(0x33)
#define PIND     *(u8 volatile*const)(0x30)
#endif
