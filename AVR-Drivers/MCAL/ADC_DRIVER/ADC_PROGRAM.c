/*
 * ADC_PROGRAM.C
 *
 *  Created on: ??þ/??þ/????
 *      Author: HOME
 */

#include "REGISTER.h"
#include "STD_TYPES_H.h"
#include "ADC_PROGRAM.h"
#include "DIO_interface.h"



void ADC_VoidInitialize(void)
{
	ADC_u8_ADMUXREG |=(ADC_u8ref |ADC_u8ADJUST |ADC_u8_ChannelConfig);
    ADC_u8_ADCSRA_REG |=(ADC_u8_PERI_STATE |ADC_u8_AutoTRIG |ADC_u8_INT_STATE |ADC_u8_PRESCALER);
#if		ADC_u8_AutoTRIG == ADC_u8_TRIGGERED
    ADC_u8_SFIOR_REG  |=(ADC_u8_TRIGGER_SRC );
#endif

#if   		ADC_u8_GIE ==MCU_GI_ENABLE
    MCU_u8_SREG |=ADC_u8_GIE;
#endif
}

void ADC_u8StartConversion(u8 ADC_Channel)
{
	ADC_u8_ADMUXREG |=ADC_Channel;
	ADC_u8_ADCSRA_REG |=ADC_u8_INT_FLAG_MUSK ;

}


   u8 ADC_u8ReadDigital(void)
   {
	   u8 local_ADCRead;
	   while (!ADC_u8_ADCSRA_REG &ADC_u8_INT_FLAG_MUSK );
	   local_ADCRead = ADC_u8_ADCH_REG;

	   return(local_ADCRead);
   }

