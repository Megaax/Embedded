/*
 * mian.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HOME
 */


#include "STD_TYPES_H.h"
#include "REGISTER.h"
#include "DIO_interface.h"
#include "TIMER.h"
#include <avr/interrupt.h>

#undef F_CPU
#define F_CPU      (u32)16000000

void main (void )
{
	SREG|=0x80;
	TCCRO =0x04;
	TIMSK =0x01;
	TCNT0 =0b1;


	while(1)
		{

		}
}
	ISR( TIMER0_0VF_vect)
	{

	}








