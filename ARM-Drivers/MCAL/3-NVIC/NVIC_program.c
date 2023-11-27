#include "STD_TYPES_H.h"
#include "BIT_MATH.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"



void NVIC_VoidInitPriority()
{
#define SCB_AIRCR *((u32*)0xE000ED0C)

	SCB_AIRCR=NVIC_PRIORITY_CONFIG;
}

void NVIC_VoidSetPriority(u8 u8_PEREPHRAL, u8 u8_PRIORITY)
{
	NVIC_IPR[u8_PEREPHRAL]=u8_PRIORITY;
}

void NCIV_VoidEnableInterrupt(u8 u8_INT)
{
	if(u8_INT <=31)
	{
		NVIC_ISER0 = ( 1 << u8_INT);

	}

	else if(u8_INT <=59)
	{
		u8_INT-=32;
		NVIC_ISER1 = ( 1 << u8_INT);

	}
}

void NCIV_VoidDisableInterrupt(u8 u8_INT)
{
	if(u8_INT <=31)
	{
		NVIC_ICER0 = ( 1 << u8_INT);
	}

	else if(u8_INT <=59)
	{
		u8_INT-=32;
		NVIC_ICER1 = ( 1 << u8_INT);

	}
}
void NCIV_VoidSetPendingFlag(u8 u8_INT)
{
	if(u8_INT <=31)
	{
		NVIC_ISPR0 = ( 1 << u8_INT);


	}

	else if(u8_INT <=59)
	{
		u8_INT-=32;
		NVIC_ISPR1 = ( 1 << u8_INT);

	}
}
void NCIV_VoidClearPendingFlag(u8 u8_INT)
{
	if(u8_INT <=31)
	{
		NVIC_ICPR0 = ( 1 << u8_INT);
	}

	else if(u8_INT <=59)
	{
		u8_INT-=32;
		NVIC_ICPR1= ( 1 << u8_INT);

	}
}

u8 NVIC_u8GetActiveFlag(u8 u8_INT)
{
	u8 u8_loacalResult=0;

	if(u8_INT <=31)
		{
			u8_loacalResult = GET_BIT(NVIC_IABR0,u8_INT);
		}

		else if(u8_INT <=59)
		{
			u8_INT-=32;
			u8_loacalResult = GET_BIT(NVIC_IABR0,u8_INT);

		}
	return u8_loacalResult;
}
