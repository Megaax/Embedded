/*
 * EXTERNAL_INTERRUPT.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HOME
 */

#ifndef EXTERNAL_INTERRUPT_H_
#define EXTERNAL_INTERRUPT_H_

#include "REGISTER.h"

#define EXTI_u8GIE_MASK   (u8) 0x80

 #define EXTI_u8SREG_REG        *((volatile u8 *const)0x5F)
 #define EXTI_u8MCUCR_REG       *((volatile u8 *const )0x55)
 #define EXTI_u8MCUCSR_REG      *((volatile u8 *const)0x54)
 #define EXTI_u8GICR_REG        *((volatile u8 *const)0x5B)
 #define EXTI_u8GIFR_REG       *((volatile u8 *const)0x5A)



 #define EXTI_u8_ISC00      (u8)0x00
 #define EXTI_u8_ISC01      (u8)0x01
#define EXTI_u8_ISC10        (u8)0x02
 #define EXTI_u8_ISC11       (u8)0x03
 #define EXTI_u8_ISC2        (u8)0x06


 #define EXTI_u8_EXTI0_PIE   (u8)0x06
 #define EXTI_u8_EXTI1_PIE   (u8)0x07
 #define EXTI_u8_EXTI2_PIE  (u8)0x05

 #define EXTI_u8_EXTI0_PIF   (u8)0x06
 #define EXTI_u8_EXTI1_PIF   (u8)0x07
 #define EXTI_u8_EXTI2_PIF    (u8)0x05

#define EXTI_u8ENABLE   (u8)0x01
#define EXTI_u8DISABLE   (u8)0x00

#define EXTI_EXTI0     (u8)0x00
#define EXTI_EXTI1     (u8)0x01
#define EXTI_EXTI2     (u8)0x02



#define EXTI_EXTI0_SWITCH  		EXTI_u8ENABLE
#define EXTI_EXTI1_SWITCH		EXTI_u8ENABLE
#define EXTI_EXTI2_SWITCH   	    EXTI_u8ENABLE


#define EXTI_u8RISING_EDGE         (u8)0x3f
#define EXTI_u8FALLING_EDGE       (u8)0xcf
#define EXTI_u8CHANGE_LEVEL      (u8)0x03
#define EXTI_u8LOW_LEVEL             (u8)0xf0


#define EXTI_EXTI0SENSECONT    EXTI_u8FALLING_EDGE

#define EXTI_EXTI1SENSECONT    EXTI_u8FALLING_EDGE
//possible configuration rising || falling

#define EXTI_EXTI2SENSECONT   EXTI_u8FALLING_EDGE






void EXTI_voidInitialize(void);

STD_ERROR EXTI_eInterruptEnable(u8 EXTI_u8Pin, u8 EXTI_u8State);


//__VOID_VECTOR_1 (VOID) __attribute__((signal,used))  -> ISR

#endif /* EXTERNAL_INTERRUPT_H_ */
