/*
 * mian.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HOME
 */
	#include "DIO_interface.h"
	#include "ADC_program.h"
	#include "LCD_Driver/LCD.h"
	#include <util/delay.h>

	#undef F_CPU
	#define F_CPU   16000000
	void main (void)
	{
//		u8 app_entry[10]="ADC_READ";
//		u8 ADC_Digital;
//		u16 ADC_AnalogVolt=0;
//		u8 ADC_analogStr[5]={0};
			u8 arr[10]={0};


//		DIO_STDSetPortDir(PORTA,DIO__DIR_OUTPUT);
//		LCD_voidInitialization();
//
//ADC_VoidInitialize();
		while(1)
	 {
//			 	 LCD_voidWriteString(app_entry,10);
//			 	 _delay_ms(1000);
//			 	ADC_Digital=ADC_u8ReadDigital();
//
//			 	 ADC_AnalogVolt = ADC_Digital*(5000/1024);
//			 	LCD_VoidInttoString(ADC_AnalogVolt,arr);
//			 	LCD_voidWriteString(arr,0);
//			 _delay_ms(1000);
//			  LCD_voidClearScreen();



	 LCD_VoidInttoString(400000,arr);
	 LCD_voidWriteString(arr,0);
			 _delay_ms(500);
			 LCD_voidClearScreen();
	}
 }



