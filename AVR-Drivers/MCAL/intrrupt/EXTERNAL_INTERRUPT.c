/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HOME
 */
#include "STD_TYPES_H.h"
#include "avr/interrupt.h"
#include "DIO_interface.h"
#include "EXTERNAL_INTERRUPT.h"



void EXTI_voidInitialize(void)
{

	switch (EXTI_EXTI0SENSECONT) {
		case EXTI_u8RISING_EDGE:
			EXTI_u8MCUCR_REG |= (1<<EXTI_u8_ISC00);
			EXTI_u8MCUCR_REG|=(1<<EXTI_u8_ISC01);

			break;
		case EXTI_u8FALLING_EDGE:
			EXTI_u8MCUCR_REG |=(1<<EXTI_u8_ISC01);
			EXTI_u8MCUCR_REG &=~(1<<EXTI_u8_ISC00);

					break;
		case EXTI_u8CHANGE_LEVEL:
			EXTI_u8MCUCR_REG&=~(1<<EXTI_u8_ISC01);
			EXTI_u8MCUCR_REG|=(1<<EXTI_u8_ISC00);

					break;
		case EXTI_u8LOW_LEVEL :
			EXTI_u8MCUCR_REG&=~(1<<EXTI_u8_ISC00);
			EXTI_u8MCUCR_REG&=~(1<<EXTI_u8_ISC01);

					break;

	}

	switch (EXTI_EXTI1SENSECONT) {
			case EXTI_u8RISING_EDGE  :
				EXTI_u8MCUCR_REG |=(1<<EXTI_u8_ISC10);
				EXTI_u8MCUCR_REG|=(1<<EXTI_u8_ISC11);

				break;
			case EXTI_u8FALLING_EDGE:
				EXTI_u8MCUCR_REG |=(1<<EXTI_u8_ISC11);
				EXTI_u8MCUCR_REG &=~(1<<EXTI_u8_ISC10);

						break;
			case EXTI_u8CHANGE_LEVEL:
				EXTI_u8MCUCR_REG&=~(1<<EXTI_u8_ISC11);
				EXTI_u8MCUCR_REG|=(1<<EXTI_u8_ISC10);

						break;
			case EXTI_u8LOW_LEVEL :
				EXTI_u8MCUCR_REG&=~(1<<EXTI_u8_ISC10);
				EXTI_u8MCUCR_REG&=~(1<<EXTI_u8_ISC11);

						break;

		}

	switch (EXTI_EXTI2SENSECONT) {
				case EXTI_u8RISING_EDGE  :
					EXTI_u8MCUCSR_REG |=(1<<EXTI_u8_ISC2);

					break;
				case EXTI_u8FALLING_EDGE:
					EXTI_u8MCUCSR_REG &=~(1<<EXTI_u8_ISC2);

							break;

			}


	switch (EXTI_EXTI0_SWITCH) {
		case  EXTI_u8ENABLE:
			EXTI_u8GICR_REG|=(1<<EXTI_u8_EXTI0_PIE);
			break;
		case EXTI_u8DISABLE:
		EXTI_u8GICR_REG&=~(1<<EXTI_u8_EXTI0_PIE);
		break ;
	}
	switch (EXTI_EXTI1_SWITCH) {
			case EXTI_u8ENABLE:
				EXTI_u8GICR_REG|=(1<<EXTI_u8_EXTI1_PIE);
				break;
			case EXTI_u8DISABLE:
			EXTI_u8GICR_REG&=~(1<<EXTI_u8_EXTI1_PIE);

			break ;
		}
	switch (EXTI_EXTI2_SWITCH) {
			case EXTI_u8ENABLE:
				EXTI_u8GICR_REG|=(1<<EXTI_u8_EXTI2_PIE);
				break;
			case EXTI_u8DISABLE:
			EXTI_u8GICR_REG&=~(1<<EXTI_u8_EXTI2_PIE);

			break ;
		}


	EXTI_u8SREG_REG |=EXTI_u8GIE_MASK;
}
STD_ERROR EXTI_eInterruptEnable(u8 EXTI_u8Pin, u8 EXTI_u8State)
{

	switch (EXTI_u8Pin) {
			caseEXTI_u8ENABLE:
				EXTI_u8GICR_REG|=(1<<EXTI_u8_EXTI0_PIE);
				break;
			case EXTI_u8DISABLE:
			EXTI_u8GICR_REG&=~(1<<EXTI_u8_EXTI0_PIE);
			break ;
		}
	switch (EXTI_u8Pin) {
				case EXTI_u8ENABLE:
					EXTI_u8GICR_REG|=(1<<EXTI_u8_EXTI1_PIE);
					break;
				case EXTI_u8DISABLE:
				EXTI_u8GICR_REG&=~(1<<EXTI_u8_EXTI1_PIE);
				break ;
			}

	switch (EXTI_u8Pin) {
				case EXTI_u8ENABLE:
					EXTI_u8GICR_REG|=(1<<EXTI_u8_EXTI2_PIE);
					break;
				case EXTI_u8DISABLE:
				EXTI_u8GICR_REG&=~(1<<EXTI_u8_EXTI2_PIE);
				break ;
			}


}

