#include "ADC_INTERFACE.h"
#include "ADC_PRIVATE.h"
#include "BIT_MATH.h"
#include "DIO_PRIVATE.h"
#include "Std_Types.h"

#define STEP 4
#define END_BIT  (uint32) 2

void ADC_INIT(/*const ADC_CONFIG_t*CFG*/)
{
	SET_BIT(GPIO_CLK,4);
	SET_BIT(RCGCADC,0);							/*INITIALIZE ADC CLOCK*/
	for(uint8 i=0;i<3;i++)
	{
		GPIOE->AFSEL|=(1<<i);
		GPIOE->DEN&=~(1<<i);
		GPIOE->AMSEL|=(1<<i);	
		CLR_BIT(ADCACTSS,i);	
		
	}
		SET_BIT(ADCSSCTL3,1);
		SET_BIT(ADCSSCTL3,2);


}


void ADC_STARTCONV(ADC_CHANNEL Channel)
{
	ADCSSMUX3 = Channel;         						/* get input from channel 0 */
	SET_BIT(ADCACTSS,3);
	SET_BIT(ADCPSSI,3);
}


AdcRead ADCREAD()
{
	while((GET_BIT(ADCRIS,3))==0);
  int adc_value =(uint16) ADCSSFIFO3;			 /* read adc coversion result from SS3 FIFO*/
        CLR_BIT(ADCISC,8); 
	return adc_value;
}


Std_ReturnType ADC_ReadGroup(ADC_GroupType Group,ADC_ValueGroupType*DataBufferPtr)
{
	switch (Group)
	{
		case GROUP_ID_GP0:
			while((GET_BIT(ADCRIS,3))==0);
			DataBufferPtr[0]=ADCSSFIFO0;
		   CLR_BIT(ADCISC,8); 

		break;
		
		case GROUP_ID_GP1:
				while((GET_BIT(ADCRIS,3))==0);
			*DataBufferPtr=(uint16)ADCSSFIFO0;
		   CLR_BIT(ADCISC,8); 
		break;
		
		case GROUP_ID_GP2:
				while((GET_BIT(ADCRIS,3))==0);
			*DataBufferPtr=(uint16)ADCSSFIFO0;
		   CLR_BIT(ADCISC,8); 
		break;
		
		case GROUP_ID_GP3:
				while((GET_BIT(ADCRIS,3))==0);
			*DataBufferPtr=(uint16)ADCSSFIFO0;
		   CLR_BIT(ADCISC,8);
		break;
		
	}
	
}



/*
		uint8 i;
	for(i=0;i<1;i++)
	{
		CLR_BIT(ADCACTSS,CFG[i].group_id);
		
		ADCSSPRI=CFG[i].group_pri;
		ADCSSMUX0=CFG[i].channel;
		
		ADCSSCTL0=(END_BIT<<((CFG[i].channel)*STEP));
		SET_BIT(ADCSSCTL0,1);
		SET_BIT(ADCSSCTL0,1);
		SET_BIT(ADCSSCTL0,1);

		SET_BIT(ADCACTSS,CFG[i].group_id);
	}
	*/