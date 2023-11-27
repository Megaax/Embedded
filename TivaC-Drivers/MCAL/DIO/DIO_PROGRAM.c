/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO_PROGRAM.c
 *        \brief  Digital Input Output Controller Driver
 *
 *      \details  The Driver Configure All MCU Ports
 *
 *********************************************************************************************************************/

#include "DIO_INTERFACE.h"
#include "DIO_PRIVATE.h"
#include "BIT_MATH.h"

/**********************************************************************************************************************
 *  FUNCTIONS IMPLEMENTATION
 *********************************************************************************************************************/


Dio_LevelType READ(Dio_ChannelType PIN)
{
	volatile uint8  RET_LOCAL;
	Dio_LevelType RET;
	SET_BIT(GPIO_CLK,5);
	uint16 OFFSET=1<<(PIN+2);
	
	RET_LOCAL= GET_BIT(*((volatile uint32*)(GPIOA_BASE_ADDRESS+OFFSET)),PIN);
	if(RET_LOCAL>0)
		RET=Dio_LevelHigh;
	else
		RET=Dio_LevelLow;
	
	return RET;
}

void Dio_WriteChannel(Dio_PortType PORT,Dio_ChannelType PIN,Dio_LevelType lEVEL)
{
	uint8 OFFSET;
	OFFSET=1<<(PIN+2);
	SET_BIT(GPIO_CLK,PORT);
	switch (PORT)
	{
	case PORTA:
		GPIOA->DIR|=1<<PIN;
		GPIOA->DEN|=1<<PIN;
		if(lEVEL == Dio_LevelHigh)
		*((volatile uint32*)(GPIOA_BASE_ADDRESS+OFFSET))=1<<PIN;
		else
		*((volatile uint32*)(GPIOA_BASE_ADDRESS+OFFSET))=0<<PIN;
			break;

	case PORTB:
		GPIOB->DIR|=1<<PIN;
		GPIOB->DEN|=1<<PIN;
		 OFFSET=1<<(PIN+2);
		if(lEVEL == Dio_LevelHigh)
		*((volatile uint32*)(GPIOB_BASE_ADDRESS+OFFSET))=1<<PIN;
		else
		*((volatile uint32*)(GPIOB_BASE_ADDRESS+OFFSET))=0<<PIN;
			break;

	case PORTC:
		GPIOC->DIR|=1<<PIN;
		GPIOC->DEN|=1<<PIN;
		if(lEVEL == Dio_LevelHigh)
		*((volatile uint32*)(GPIOC_BASE_ADDRESS+OFFSET))=1<<PIN;
		else
		*((volatile uint32*)(GPIOC_BASE_ADDRESS+OFFSET))=0<<PIN;
			break;

	case PORTD:
		GPIOD->DIR|=1<<PIN;
		GPIOD->DEN|=1<<PIN;
		if(lEVEL == Dio_LevelHigh)
		*((volatile uint32*)(GPIOD_BASE_ADDRESS+OFFSET))=1<<PIN;
		else
		*((volatile uint32*)(GPIOD_BASE_ADDRESS+OFFSET))=0<<PIN;
			break;

	case PORTE:
		GPIOE->DIR|=1<<PIN;
		GPIOE->DEN|=1<<PIN;
		if(lEVEL == Dio_LevelHigh)
		*((volatile uint32*)(GPIOE_BASE_ADDRESS+OFFSET))=1<<PIN;
		else
		*((volatile uint32*)(GPIOE_BASE_ADDRESS+OFFSET))=0<<PIN;
			break;

	case PORTF:
		GPIOF->DIR|=1<<PIN;
		GPIOF->DEN|=1<<PIN;
		if(lEVEL == Dio_LevelHigh)
		*((volatile uint32*)(GPIOF_BASE_ADDRESS+OFFSET))=1<<PIN;
		else
		*((volatile uint32*)(GPIOF_BASE_ADDRESS+OFFSET))=0<<PIN;
			break;
	}
}

Dio_LevelType Dio_ReadChannel(Dio_PortType PORT,Dio_ChannelType PIN)
{
	volatile uint8  RET_LOCAL;
	SET_BIT(GPIO_CLK,PORT);

   uint16 OFFSET=1<<(PIN+2);
	switch (PORT)
	{
	case PORTA:
  		RET_LOCAL= GET_BIT(*((volatile uint32*)(GPIOA_BASE_ADDRESS+OFFSET)),PIN);
  			break;
	
  	case PORTB:
  		RET_LOCAL= GET_BIT(*((volatile uint32*)(GPIOB_BASE_ADDRESS+OFFSET)),PIN);
  			break;

  	case PORTC:
     RET_LOCAL= GET_BIT(*((volatile uint32*)(GPIOC_BASE_ADDRESS+OFFSET)),PIN);
			break;

	case PORTD:
		RET_LOCAL= GET_BIT(*((volatile uint32*)(GPIOD_BASE_ADDRESS+OFFSET)),PIN);
			break;
	
	case PORTE:
		RET_LOCAL= GET_BIT((*((volatile uint32*)(GPIOE_BASE_ADDRESS+OFFSET))),PIN);
			break;

	case PORTF:
		RET_LOCAL= GET_BIT(*((volatile uint32*)(GPIOF_BASE_ADDRESS+OFFSET)),PIN);
			break;
	}	
	return RET_LOCAL;
}

void Dio_WritePort(Dio_PortType PORT,Dio_PortLevelType PortVal)
{
	SET_BIT(GPIO_CLK,PORT);
	switch(PORT)
	{
		case PORTA:
			GPIOA->DIR=0xFF;
			GPIOA->DEN=0xFF;
			*((volatile uint32*)(GPIOA_BASE_ADDRESS+0x3FC))=PortVal;	
			break;

		case PORTB:
			GPIOB->DIR=0xFF;
			GPIOB->DEN=0xFF;
			*((volatile uint32*)(GPIOB_BASE_ADDRESS+0x3FC))=PortVal;	
			break;

		case PORTC:
			GPIOC->DIR=0xFF;
			GPIOC->DEN=0xFF;
			*((volatile uint32*)(GPIOC_BASE_ADDRESS+0x3FC))=PortVal;	
			break;		
		case PORTD:
			GPIOD->DIR=0xFF;
			GPIOD->DEN=0xFF;
			*((volatile uint32*)(GPIOD_BASE_ADDRESS+0x3FC))=PortVal;	
			break;
		
		case PORTE:
			GPIOE->DIR=0xFF;
			GPIOE->DEN=0xFF;
			*((volatile uint32*)(GPIOE_BASE_ADDRESS+0x3FC))=PortVal;	
			break;
		
		case PORTF:
			GPIOF->DIR=0xFF;
			GPIOF->DEN=0xFF;
			*((volatile uint32*)(GPIOF_BASE_ADDRESS+0x3FC))=PortVal;	
			break;
	}
}

Dio_PortLevelType Dio_ReadPort(Dio_PortType PORT)
{
	volatile uint8 RET_LOCAL;
	SET_BIT(GPIO_CLK,PORT);

	switch (PORT)
	{
	case PORTA:
		RET_LOCAL = *((volatile uint32*)(GPIOA_BASE_ADDRESS+0x3FC));
		break;
	case PORTB:
		RET_LOCAL = *((volatile uint32*)(GPIOB_BASE_ADDRESS+0x3FC));
		break;
	case PORTC:
		RET_LOCAL = *((volatile uint32*)(GPIOC_BASE_ADDRESS+0x3FC));
		break;
	case PORTD:
		RET_LOCAL = *((volatile uint32*)(GPIOD_BASE_ADDRESS+0x3FC));
		break;
	case PORTE:
		RET_LOCAL = *((volatile uint32*)(GPIOE_BASE_ADDRESS+0x3FC));
		break;
	case PORTF:
		RET_LOCAL = *((volatile uint32*)(GPIOF_BASE_ADDRESS+0x3FC));
		break;
	}
	
	return RET_LOCAL;
}
/**********************************************************************************************************************
 *  END OF FILE: DIO_PROGRAM.c
 *********************************************************************************************************************/
