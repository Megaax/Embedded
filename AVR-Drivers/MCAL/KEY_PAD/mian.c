/*
 * mian.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HOME
 */
#include "stdtype.h"
#include "REGISTER.h"
#include "DIO_interface.h"
#include "KEY_interface.h"
#include <avr/delay.h>

u8 arr[4][4]={{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
u8 x=0XFF;
int main (void)

//{
//u8 i=0 ,j=0;
//	//KEY_PADInitialization();
//	KeyPad_GetPressedKey(arr);
//
//
//	while (arr[i][j ]==0)
//
//	{
//		j++;
//		if(j ==3)
//		{
//			i++;
//		}
//
//	}
//
//if ( arr[i][j]==1)
//{
//	_delay_ms(50);
//	DIO_SetPinDir(PORT_C,P_1,DIO__DIR_OUTPUT);
//	DIO_SetPinValue(PORT_C,P_1,DIO_VALUE_HIGH);
//}
//
//



DIO_SetPinDir(PORT_D,P_2,DIO__DIR_INPUT);
		DIO_SetPinValue(PORT_D,P_2,DIO_VALUE_HIGH);

		DIO_SetPinDir(PORT_B,P_4,DIO__DIR_OUTPUT);
				DIO_SetPinValue(PORT_B,P_4,DIO_VALUE_LOW);


				if((DIO_GetPinValue(PORT_D,P_2,i))!=0)
						{
							DIO_SetPinDir(PORT_C,P_0,DIO__DIR_OUTPUT);
							DIO_SetPinValue(PORT_C,P_0,DIO_VALUE_HIGH);



return(0);
}
