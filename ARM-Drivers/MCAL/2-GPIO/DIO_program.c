#include <STD_TYPES_H.h>
#include <BIT_MATH.h>
#include <DIO_interface.h>
#include <DIO_config.h>
#include <DIO_private.h>

void MGPIO_voidSetPortDirection(u8 u8_Port,u8 u8_Pin,u8 u8_Mode){
	
	switch(u8_Port){
		
		case GPIOA: 
		
			if(u8_Pin <=7)
				{
					GPIOA_CRL &=~ ((0b1111) << (u8_Pin * 4));
					
					GPIOA_CRL |=   ((u8_Mode) << (u8_Pin * 4));
				}
			
			else if(u8_Pin <=15)
				{
					u8_Pin= u8_Pin - 8;
					
					GPIOA_CRH &= ~ ((0b1111) << (u8_Pin * 4));
					
					GPIOA_CRH |=   ((u8_Mode) << (u8_Pin * 4));
				}
				break;

		
		case GPIOB:
				
			if(u8_Pin <=7)
				{
					GPIOB_CRL &= ~ ((0b1111) << (u8_Pin * 4));
					
					GPIOB_CRL |=   ((u8_Mode) << (u8_Pin * 4));
				}
			
			else if(u8_Pin <=15)
				{
					u8_Pin= u8_Pin - 8;
					
					GPIOB_CRH &= ~ ((0b1111) << (u8_Pin * 4));
					
					GPIOB_CRH |=   ((u8_Mode) << (u8_Pin * 4));
				}
				break;

		case GPIOC:	
		
			if(u8_Pin <=7)
				{
					GPIOC_CRL &= ~ ((0b1111) << (u8_Pin * 4));
					
					GPIOC_CRL |=   ((u8_Mode) << (u8_Pin * 4));
				}
			
			else if(u8_Pin <=15)
				{
					u8_Pin= u8_Pin - 8;
					
					GPIOC_CRH &= ~ ((0b1111) << (u8_Pin * 4));
					
					GPIOC_CRH |=   ((u8_Mode) << (u8_Pin * 4));
				}
				break;

	}
	
	
	
}

void MGPIO_voidSetPinValue(u8 u8_Port,u8 u8_Pin,u8 u8_value){

switch(u8_Port){
		
	case GPIOA:
		
		if(u8_value == HIGH)
			{
				GPIOA_ODR = SET_BIT(u8_Port,u8_Pin);
			}

		else if(u8_value == LOW)
			{
				GPIOA_ODR = CLR_BIT(u8_Port,u8_Pin);
			}
			break;

		
case GPIOB:
				
	if(u8_value == HIGH)
		{
			GPIOB_ODR = SET_BIT(u8_Port,u8_Pin);
		}

	else if(u8_value == LOW)
		{
			GPIOB_ODR = CLR_BIT(u8_Port,u8_Pin);
		}
		break;

case GPIOC:
		
	if(u8_value == HIGH)
		{
			GPIOC_ODR = SET_BIT(u8_Port,u8_Pin);
		}

	else if(u8_value == LOW)
		{
			GPIOC_ODR = CLR_BIT(u8_Port,u8_Pin);
		}
		break;
  }
}

u8 MGPIO_u8GetPinValue(u8 u8_Port,u8 u8_Pin){
	
	
	u8 LOC_u8_PIN_VALUE=0;
	
	switch(u8_Port){
		
	case GPIOA:  LOC_u8_PIN_VALUE = GET_BIT(GPIOA_IDR,u8_Pin);
	break;
	
	case GPIOB:  LOC_u8_PIN_VALUE = GET_BIT(GPIOB_IDR,u8_Pin);
	break;
	
	case GPIOC:  LOC_u8_PIN_VALUE = GET_BIT(GPIOC_IDR,u8_Pin);
	break;
		
	}
	 	 return LOC_u8_PIN_VALUE;
}






