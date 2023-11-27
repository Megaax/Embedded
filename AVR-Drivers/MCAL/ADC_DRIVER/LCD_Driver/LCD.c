/*
 * LCD.c(
 *
 *  Created on: Sep 7, 2019
 *      Author: Naguib
 */

#include "REGISTER.h"
#include "STD_TYPES_H.h"
#include "LCD.h"
#include "avr\io.h"
#include "util\delay.h"
#undef F_CPU
#define F_CPU 16000000


void LCD_voidInitialization(void)
{
//	_delay_ms(50);
	LCD_u8DataDir = 0xFF;
	LCD_u8ControlDir |= (1<<LCD_u8RegisterSelPin)
	|(1<<LCD_u8ReadWritePin)|(1<<LCD_u8EnablePin);
	_delay_ms(100);
	LCD_voidWriteCommand(LCD_u8ComReturnHome);
	_delay_ms(10);
	LCD_voidWriteCommand(LCD_u8Com8bit_2Line);
	_delay_ms(10);
	LCD_voidWriteCommand(LCD_u8ComDispOn);
	_delay_ms(10);
	LCD_voidWriteCommand(LCD_u8ComClearScreen);
	_delay_ms(10);
	LCD_voidWriteCommand(LCD_u8ComEntryMode);
_delay_ms(10);
}

void LCD_voidWriteCommand(u8 Copy_u8Command)
{
	LCD_u8ControlPort &= ~((1<<LCD_u8RegisterSelPin)
			|(1<<LCD_u8ReadWritePin));
	LCD_u8DataPort = Copy_u8Command;
	LCD_voidWakeUp();
}



void LCD_voidWriteChar( u8 Copy_u8Char)
{

	LCD_u8ControlPort &= (~(1<<LCD_u8ReadWritePin));
	LCD_u8ControlPort|=(1<<LCD_u8RegisterSelPin);
	LCD_u8DataPort = Copy_u8Char;
	LCD_voidWakeUp();
}

void LCD_voidGotoXY(u8 Copy_u8Xpos , u8 Copy_u8Ypos)
{
	u8 Local_u8ActualAdd;
	switch(Copy_u8Ypos)
	{
	case LCD_u8DispLine1:
		if((Copy_u8Xpos>=0) &&(Copy_u8Xpos<16))
		{
			Local_u8ActualAdd = LCD_u8ComDispFirstRow
					+Copy_u8Xpos;
		}

		break;
	case LCD_u8DispLine2:

		if((Copy_u8Xpos>=0) &&((Copy_u8Xpos<16)))
		{
			Local_u8ActualAdd = LCD_u8ComDispSecondRow
					+Copy_u8Xpos;
		}
		break;
	}
	LCD_voidWriteCommand(Local_u8ActualAdd);
}


void LCD_voidClearScreen(void)
{
	LCD_voidWriteCommand(LCD_u8ComClearScreen);
}


void LCD_voidWakeUp(void)
{
	LCD_u8ControlPort |= (1<<LCD_u8EnablePin);
	_delay_ms(15);//2
	LCD_u8ControlPort &= (~(1<<LCD_u8EnablePin));
	_delay_ms(15);//2
}



void LCD_voidWriteString(u8 * Copy_u8StringArr, u8 Copy_u8CharNum)
{
	u8 Local_u8Counter=0;

//	for(Local_u8Counter =0;Local_u8Counter < Copy_u8CharNum
//	;Local_u8Counter++ )
//	{
		while ( Copy_u8StringArr[Local_u8Counter] !='\0' )
		{
		LCD_voidWriteChar(Copy_u8StringArr[Local_u8Counter]);
		Local_u8Counter++;
		_delay_ms(15);
		}
	}

//}

void LCD_VoidInttoString(u32 number , u8*num_string )
{
	u8 index =0;
	u32 counter =1;
	u32 copy_number=number;
	while  (number!=0)
	{
		number/=10;
		counter *=10;
	}
	number=copy_number;
	counter /=10;

	while(number!=0||counter!=0)
	{
		num_string[index]= (number/counter);
		number -=(num_string[index]*counter);
		num_string[index]+=48;
		counter/=10;
		index++;
	}
	num_string[index]='\0';
}


