/*
 * KEY_PAD.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HOME
 */

#include "stdtype.h"
#include "DIO_interface.h"
#include "KEY_interface.h"
#include  <avr/delay.h>
#include <avr/io.h>

u8 COL_ =2;
u8 ROW_=4;

void KEY_PADInitialization(void)
{
	for(COL_=c0 ;COL_<=c3 ;COL_++)
	{
		DIO_SetPinDir(PORT_D,COL_,DIO__DIR_OUTPUT);
		DIO_SetPinValue(PORT_D,COL_,DIO_VALUE_HIGH);
	}

	for(ROW_=r0 ;ROW_<=r3;ROW_++)
	{
		DIO_SetPinDir(PORT_B,ROW_,DIO__DIR_OUTPUT);
		DIO_SetPinValue(PORT_B,ROW_,DIO_VALUE_LOW);

	}


}
STD_ERROR KeyPad_GetPressedKey(u8 a[4][4])
{
	STD_ERROR LOC_ERROR=OK;

	u8 i=0;
	for(COL_= c0;COL_<= c3 ;COL_++)
	{
		_delay_ms(300);
		DIO_SetPinValue(PORT_D,COL_,DIO_VALUE_LOW);

		for (ROW_ = r0;ROW_<= r3;ROW_ ++)
		{
//			_delay_ms(2);
//			DIO_GetPinValue(PORT_B,ROW_,&i);
			DIO_SetPinDir(PORT_D,ROW_,DIO__DIR_INPUT);
					DIO_SetPinValue(PORT_D,ROW_,DIO_VALUE_HIGH);
			_delay_ms(2);
			DIO_GetPinValue(PORT_B,ROW_,&i);

			a[COL_][ROW_]=i;

		}
		DIO_SetPinValue(PORT_D,COL_,DIO_VALUE_HIGH);

	}

	return(LOC_ERROR);
}


