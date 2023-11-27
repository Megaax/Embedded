/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  ADC_PRIVATE.h
 *       Module:  ADC
 *
 *  Description:  header file for Registers definition
 *  
 *********************************************************************************************************************/
#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"


typedef enum 
{
 ADC_BASE_ADDRESS=0x40004000

}ADC_BASE_ADDRESSES;

typedef  uint16 AdcRead;


typedef enum

{
	ADC_CHANNEL_ID_CH0 ,
	ADC_CHANNEL_ID_CH1 ,
	ADC_CHANNEL_ID_CH2 ,
	ADC_CHANNEL_ID_CH3 ,
	ADC_CHANNEL_ID_CH4 ,
	ADC_CHANNEL_ID_CH5 ,
	ADC_CHANNEL_ID_CH6 ,
	ADC_CHANNEL_ID_CH7 ,
	ADC_CHANNEL_ID_CH8 ,
	ADC_CHANNEL_ID_CH9 ,
	ADC_CHANNEL_ID_CH10 ,
	ADC_CHANNEL_ID_CH11 

}ADC_CHANNEL;

typedef enum {
	GROUP_ID_GP0 ,
	GROUP_ID_GP1 ,
	GROUP_ID_GP2 ,
	GROUP_ID_GP3
}ADC_GroupType;

typedef enum {
	GROUP_PRI_0 ,
	GROUP_PRI_1 ,
	GROUP_PRI_2 ,
	GROUP_PRI_3 
}GROUP_PRI;

typedef enum {
	SINGLE_MODE ,
	CONTINOUS_MODE
}GROUP_MODE;

typedef struct{
	ADC_CHANNEL channel;
	ADC_GroupType	group_id;
	GROUP_PRI 	group_pri;
	GROUP_MODE 	group_mode ;
	int 	Streaming_num_samples;
}ADC_CONFIG_t;

typedef volatile uint16 ADC_ValueGroupType;

	
/*
typedef struct {

	uint32 ADCACTSS;
	uint32 ADCRIS;
	uint32 ADCIM;
	uint32 ADCISC
	uint32 ADCOSTAT,
	uint32 ADCEMUX,
	uint32 ADCUSTAT,
	uint32 ADCTSSEL,
	uint32 ADCSSPRI,
	uint32 ADCSPC,
	uint32 ADCPSSI,
	uint32 RESV0,
	uint32 ADCSAC,
	uint32 ADCDCISC,
	uint32 ADCCTL,
	uint32 RESV1,
	uint32 ADCSSMUX0,
	uint32 ADCSSCTL0,
	uint32 ADCSSFIFO0,
	uint32 ADCSSFSTAT0;
}ADC_t;

#define ADC ((volatile ADC_t*) ADC_BASE)

*/

#define RCGCADC											*((volatile uint32*)(0x400FE638))

#define ADC_BASE			0x40038000

#define ADCACTSS										*((volatile uint32*)(ADC_BASE))
#define ADCEMUX											*((volatile uint32*)(ADC_BASE+ADC_BASE))
#define ADCSSPRI										*((volatile uint32*)(ADC_BASE+0x020))
#define ADCPSSI											*((volatile uint32*)(ADC_BASE+0x028))
	
#define ADCSSMUX0										*((volatile uint32*)(ADC_BASE+0x040))
#define ADCSSCTL0										*((volatile uint32*)(ADC_BASE+0x044))
#define ADCSSFIFO0									*((volatile uint32*)(ADC_BASE+0x048))
	
#define ADCSSMUX3									*((volatile uint32*)(ADC_BASE+0x0A0))
#define ADCSSCTL3										*((volatile uint32*)(ADC_BASE+0x0A4))
#define ADCSSFIFO3									*((volatile uint32*)(ADC_BASE+0x0A8))
	
#define ADCRIS									*((volatile uint32*)(ADC_BASE+0x004))
#define ADCISC										*((volatile uint32*)(ADC_BASE+0x00C))



#endif  /* DIO_PRIVATE_H */

/**********************************************************************************************************************
 *  END OF FILE: DIO_PRIVATE.h
 *********************************************************************************************************************/
