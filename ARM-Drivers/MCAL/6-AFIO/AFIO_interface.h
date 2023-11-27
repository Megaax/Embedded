#ifndef AFIO_interface_h
#define AFIO_interface_h


#define PORTA_EXTI  u8 0b0000
#define PORTB_EXTI  u8 0b0001
#define PORTC_EXTI  u8 0b0010


void AFIO_voidSetEXTILine(u8 u8_Line, u8 u8_PortMap);

#endif
