/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HOME
 */

#include "DIO_interface.h"
#undef F_CPU
#define F_CPU (u32) (16000000)
#include <avr/delay.h>


void main (void)
{

	while(1)
	{
DIO_SetPinDir(PORT_C,P_0,DIO__DIR_OUTPUT);
DIO_SetPinDir(PORT_C,P_1,DIO__DIR_OUTPUT);

// CLOCKWISE
DIO_SetPinValue(PORT_C,P_0,DIO_VALUE_HIGH);

_delay_ms(500);
DIO_SetPinValue(PORT_C,P_0,DIO_VALUE_LOW);

_delay_ms(500);

//ANTICLOCKWISE

DIO_SetPinValue(PORT_C,P_1,DIO_VALUE_HIGH);
_delay_ms(500);

DIO_SetPinValue(PORT_C,P_1,DIO_VALUE_LOW);
 _delay_ms(500);




	}




}
