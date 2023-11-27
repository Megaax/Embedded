/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  STEPPER_INTERFACE.h
 *       Module:  STEPPER_INTERFACE_H
 *
 *  Description:  header file for STEPPER     
 *  
 *********************************************************************************************************************/
#ifndef STEPPER_INTERFACE_H
#define STEPPER_INTERFACE_H


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Platform_Types.h"
#include"DIO_INTERFACE.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define STEPPER_1_PORT                 PORTA
#define STEPPER_1_PIN                  PIN7

#define STEPPER_2_PORT                 PORTA
#define STEPPER_2_PIN                  PIN5

#define STEPPER_3_PORT                 PORTD
#define STEPPER_3_PIN                  PIN2

#define STEPPER_4_PORT                 PORTD
#define STEPPER_4_PIN                  PIN3

#define ENA_A_PORT                     PORTA
#define ENA_A_PIN                      PIN4

#define ENA_B_PORT                     PORTC
#define ENA_B_PIN                      PIN5

#define MAX_STEPS                       135

static uint8 gOldPosition = 0;

void STEPPER_voidInit ();

void STEPPER_voidGoForward ();

void STEPPER_voidZeroPosition ();  

void STEPPER_voidDeinit ();

void STEPPER_voidGoReverse ();

void STEEPER_voidGotoDefinedPosition (uint16 WantedPosition);

void STEEPER_voidPrint (uint16 PressureValue);

void STEEPER_voidEditPosition (uint16 NewPosition);

uint16 STEEPER_U16GetCurrentPosition ();


#endif

/**********************************************************************************************************************
 *  END OF FILE: STEPPER_INTERFACE.h
 *********************************************************************************************************************/
