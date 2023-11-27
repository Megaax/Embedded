#ifndef DIO_INTERFACE_H

#define DIO_INTERFACE_H

#define GPIOA u8 0
#define GPIOB u8 1
#define GPIOC u8 2

#define GPIO_HIGH u8 1
#define GPIO_LOW  u8 0

#define PIN0	 u8 0
#define PIN1	 u8 1
#define PIN2	 u8 2
#define PIN3	 u8 3
#define PIN4  	 u8 4
#define PIN5	 u8 5
#define PIN6	 u8 6
#define PIN7	 u8 7
#define PIN8	 u8 8
#define PIN9	 u8 9
#define PIN10	 u8 10
#define PIN11	 u8 11
#define PIN12	 u8 12
#define PIN13	 u8 13
#define PIN14	 u8 14
#define PIN15	 u8 15

#define OUTPUT_10MHZ_PP 	0b0001
#define OUTPUT_10MHZ_OD 	0b0101
#define OUTPUT_10MHZ_AFPP   0b1001
#define OUTPUT_10MHZ_APOD 	0b1101

#define OUTPUT_2MHZ_PP 		0b0010
#define OUTPUT_2MHZ_OD 		0b0110
#define OUTPUT_2MHZ_AFPP    0b1010
#define OUTPUT_2MHZ_APOD 	0b1110

#define OUTPUT_50MHZ_PP 	0b0011
#define OUTPUT_50MHZ_OD 	0b0111
#define OUTPUT_50MHZ_AFPP   0b1011
#define OUTPUT_50MHZ_APOD 	0b1111

#define INPUT_ANALOG		0b0000
#define INPUT_FLOATING		0b0100
#define INPUT_PULL_DOWN		0b1000


void MGPIO_voidSetPortDirection(u8_u8Port,u8_u8Pin,u8_u8value);

void MGPIO_voidSetPinValue(u8_u8Port,u8_u8Pin,u8_u8value);

u8 MGPIO_voidGetPinValue(u8_u8Port,u8_u8Pin);

#endif
