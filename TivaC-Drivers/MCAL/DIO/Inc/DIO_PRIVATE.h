/****************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DIO_PRIVATE.h
 *       Module:  DIO
 *
 *  Description:  header file for Registers definition    
 *  
 ***************************************/
#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

/****************************************
 * INCLUDES
 ***************************************/
#include 	"Platform_Types.h"
#include	"DIO_INTERFACE.h"


typedef struct 
{ 	
    uint32 DIR;
    uint32 IS;
    uint32 IBE;
    uint32 IEV;
    uint32 IM;
    uint32 RIS;
    uint32 MIS;
    uint32 ICR;
    uint32 AFSEL;
    uint32 RESERVED[55];  			
    uint32 DR2R;
    uint32 DR4R;
    uint32 DR8R;
    uint32 ODR;
    uint32 PUR;
    uint32 PDR;
    uint32 SLR;
    uint32 DEN;
    uint32 LOCK;
    uint32 CR;
    uint32 AMSEL;
    uint32 PCTL;
    uint32 ADCCTL;
    uint32 DMACTL;
}DIO_t;

#define GPIOA_BASE_ADDRESS 0x40004000 
#define GPIOB_BASE_ADDRESS 0x40005000
#define GPIOC_BASE_ADDRESS 0x40006000 
#define GPIOD_BASE_ADDRESS 0x40007000 
#define GPIOE_BASE_ADDRESS 0x40024000
#define GPIOF_BASE_ADDRESS 0x40025000	


#define GPIO_EN                                  		((volatile uint32)(GPIOF_BASE_ADDRESS+0x51C))
#define GPIO_DIR                                 		((volatile uint32)(GPIOF_BASE_ADDRESS +0x400))



#define GPIO_CLK										*((volatile uint32*)(0x400FE608))


/*********GPIOA******************/
#define  GPIOA ((volatile DIO_t *)  (GPIOA_BASE_ADDRESS+0x400))
#define  GPIOA_DATA                 GPIOA_BASE_ADDRESS
/*********GPIOB******************/
#define  GPIOB ((volatile DIO_t *)  (GPIOB_BASE_ADDRESS+0x400))
#define  GPIOB_DATA                 GPIOB_BASE_ADDRESS
/********GPIOC******************/
#define  GPIOC ((volatile DIO_t *)  (GPIOC_BASE_ADDRESS+0x400))
#define  GPIOC_DATA                 GPIOC_BASE_ADDRESS
/*********GPIOD******************/
#define  GPIOD ((volatile DIO_t *)  (GPIOD_BASE_ADDRESS+0x400))
#define  GPIOD_DATA                 GPIOD_BASE_ADDRESS
/*********GPIOE******************/
#define  GPIOE ((volatile DIO_t *)  (GPIOE_BASE_ADDRESS+0x400))
#define  GPIOE_DATA                 GPIOE_BASE_ADDRESS
/*********GPIOF******************/
#define  GPIOF ((volatile DIO_t *)  (GPIOF_BASE_ADDRESS+0x400))
#define  GPIOF_DATA                 GPIOF_BASE_ADDRESS


#endif  /* DIO_PRIVATE_H */

/****************************************
 *  END OF FILE: DIO_PRIVATE.h
 ***************************************/