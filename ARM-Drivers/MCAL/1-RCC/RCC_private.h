#ifndef _RCC_private_h
#define _RCC_private_h

/* Register Definition*/

#define RCC_CR   		*((u32*)0x40021000)
#define RCC_CFGR 		*((u32*)0x40021004)
#define RCC_CIR  		*((u32*)0x40021008)
#define RCC_APB2RSTR 	*((u32*)0x4002100C)
#define RCC_APB1RSTR  	*((u32*)0x40021010)
#define RCC_AHBENR   	*((u32*)0x40021014)
#define RCC_APB2ENR   	*((u32*)0x40021018)
#define RCC_APB1ENR   	*((u32*)0x4002101C)
#define RCC_BDCR   		*((u32*)0x40021020)
#define RCC_CSR   		*((u32*)0x40021024)


#define	RCC_HSI 			  0
#define	RCC_HSE_CRYSTAL 	  1
#define	RCC_HSE_RC			  2
#define	RCC_PLL				  3

#define	RCC_PLL_HSI_DIV_2   u8 0
#define	RCC_PLL_HSE_DIV_2	u8 1
#define	RCC_PLL_HSE 		u8 2



#define RCC_PLL_CLOCK_X2 	u8 0
#define RCC_PLL_CLOCK_X3 	u8 1
#define RCC_PLL_CLOCK_X4 	u8 2
#define RCC_PLL_CLOCK_X5 	u8 3
#define RCC_PLL_CLOCK_X6 	u8 4
#define RCC_PLL_CLOCK_X7 	u8 5
#define RCC_PLL_CLOCK_X8 	u8 5
#define RCC_PLL_CLOCK_X9 	u8 7
#define RCC_PLL_CLOCK_X10   u8 8
#define RCC_PLL_CLOCK_X11   u8 9
#define RCC_PLL_CLOCK_X12   u8 10
#define RCC_PLL_CLOCK_X13   u8 11
#define RCC_PLL_CLOCK_X14   u8 12
#define RCC_PLL_CLOCK_X15   u8 13
#define RCC_PLL_CLOCK_X16   u8 14




#endif
