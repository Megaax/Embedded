#ifndef _RCC_config_h
#define _RCC_config_h

// CONFIG CLOCK TYPE

/*
Options :
		RCC_HSI
		RCC_HSE_CRYSTAL
		RCC_HSE_RC
		RCC_PLL
*/

#define RCC_CLOCK_TYPE 	RCC_HSI

#if RCC_CLOCK_TYPE == RCC_PLL

/*
Options:
	RCC_PLL_HSI_DIV_2
	RCC_PLL_HSE_DIV_2
	RCC_PLL_HSE
*/

#define RCC_PLL_INPUT 

/*
	Options: FROM 2 TO 16
*/
#define RCC_PLL_FACTOR 2


#endif

#endif

