#include "STD_TYPES_H.h"
#include "BIT_MATH.h"
#include "RCC_inTerface.h"
#include "RCC_private.h"
#include "RCC_config.h"



void RCC_voidInitClockSystem(){

#if RCC_ClOCK_TYPE == RCC_HSI

	RCC_CR   = 0x00000001; /*HSI PIN ON*/
	RCC_CFGR = 0x00000000;

#elif RCC_ClOCK_TYPE == RCC_HSE_CRYSTAL

	RCC_CR 	 = 0x00010000; /*HSE PIN ON*/
	RCC_CFGR = 0x00000001;

#elif RCC_ClOCK_TYPE == RCC_HSE_RC

	RCC_CR   = 0x00050000; /*HSE RC PIN ON*/
	RCC_CFGR = 0x00000001;

#elif RCC_ClOCK_TYPE == RCC_PLL

	#if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
		
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
	
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
		
	#endif


//#else
////error

#endif
}

void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId){
	
	if(Copy_u8PerId <=31){
		
		switch (Copy_u8BusId)
		{
			case RCC_AHB:

			RCC_AHBENR |=(1<<Copy_u8PerId);
			break;
			case RCC_APB1 :
				SET_BIT(RCC_APB1ENR,Copy_u8PerId); break;

			case RCC_APB2 : SET_BIT(RCC_APB2ENR,Copy_u8PerId); break;
		}
	}
//	else{
//		//return Error
//
//	}
}

void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId){
	
	if(Copy_u8PerId <=31){
		
		switch (Copy_u8BusId)
		{
			case RCC_AHB  : CLR_BIT(RCC_AHBENR,Copy_u8PerId); break;
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR,Copy_u8PerId); break;
			case RCC_APB2 : CLR_BIT(RCC_APB2ENR,Copy_u8PerId); break;
	    }
}

}







