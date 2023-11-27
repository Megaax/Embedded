#include "BIT_MATH.h"
#include "STD_TYPES_H.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

static void (*EXTI_CALLBACK) (void) =NULL;

void EXTI_voidInit()
{
#if EXTI_MODE == RISING

	SET_BIT(EXTI->IMR,EXTI_LINE);
	SET_BIT(EXTI->RTSR,EXTI_LINE);

#elif
	EXTI_MODE == FALLING

		SET_BIT(EXTI->IMR,EXTI_LINE);
		SET_BIT(EXTI->FTSR,EXTI_LINE);
#elif
	EXTI_MODE == ONCHANGE

		SET_BIT(EXTI->IMR,EXTI_LINE);
		SET_BIT(EXTI->RTSR,EXTI_LINE);
		SET_BIT(EXTI->FTSR,EXTI_LINE);
#endif
}
void EXTI_voidEnableEXTI(u8 u8_Line)
{
	SET_BIT(EXTI->IMR,u8_Line);

}
void EXTI_voidDisableEXTI(u8 u8_Line)
{
	CLR_BIT(EXTI->IMR,u8_Line);

}

void EXTI_voidSignalLatche(u8 u8_Line, u8 u8_senseMode)
{
		SET_BIT(EXTI->IMR,EXTI_LINE);

	switch(u8_senseMode)
	{
		case RISING:
		SET_BIT(EXTI->RTSR,EXTI_LINE);
		break;
		
		case FALLING:
		SET_BIT(EXTI->FTSR,EXTI_LINE);
		break;
		
		case ONCHANGE:
		SET_BIT(EXTI->RTSR,EXTI_LINE);
		SET_BIT(EXTI->FTSR,EXTI_LINE);
		break;
		
	}
	
}
void EXTI_voidSetCallBack(void (*ptr)(void))
{
	EXTI_CALLBACK=ptr;
}





