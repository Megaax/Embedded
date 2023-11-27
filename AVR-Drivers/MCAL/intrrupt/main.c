/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HOME
 */
#include "STD_TYPES_H.h"
#include "avr/interrupt.h"
#include "DIO_interface.h"
#include "EXTERNAL_INTERRUPT.h"
#undef F_CPU
#define F_CPU 16000000
#include <avr/delay.h>

void main(void)
{

	DIO_STDSetPortDir(PORT_C,ALL_PORT_OUTPUT);

	DIO_STDSetPinDir(PORT_D,P_2,DIO__DIR_INPUT);
	DIO_STDSetPinValue(PORT_D,P_2,DIO_VALUE_HIGH);

	DIO_STDSetPinDir(PORT_D,P_3,DIO__DIR_INPUT);
	DIO_STDSetPinValue(PORT_D,P_3,DIO_VALUE_HIGH);

	DIO_STDSetPinDir(PORT_B,P_4,DIO__DIR_OUTPUT);
	DIO_STDSetPinValue(PORT_B,P_4,DIO_VALUE_LOW);

	EXTI_voidInitialize();




	while(1)
	{
		DIO_STDSetPortValue(PORT_C,ALL_PORT_INPUT);

	//	DIO_STDSetPinValue(PORT_C,P_0,DIO_VALUE_LOW);
		//DIO_STDSetPinValue(PORT_C,P_1,DIO_VALUE_LOW);


		_delay_ms(500);

	}

}
ISR(INT0_vect)
		{
			DIO_STDSetPinValue(PORT_C,P_0,DIO_VALUE_HIGH);
			_delay_ms(500);
		}
		ISR(INT1_vect)
				{
			DIO_STDSetPinValue(PORT_C,P_1,DIO_VALUE_HIGH);
			_delay_ms(500);

				}

