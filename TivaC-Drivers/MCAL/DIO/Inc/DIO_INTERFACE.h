/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DIO_INTERFACE.h
 *       Module:  DIO_INTERFACE_H
 *
 *  Description:  header file for IntCrtl Module    
 *  
 *********************************************************************************************************************/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
typedef uint8 Dio_PortLevelType;

typedef enum 
{
	Dio_LevelLow=0,
	Dio_LevelHigh
	
}Dio_LevelType;

typedef enum 
{
 PIN0  , 
 PIN1  ,
 PIN2  , 
 PIN3  , 
 PIN4  ,
 PIN5  ,
 PIN6  ,
 PIN7 
}Dio_ChannelType;

typedef enum 
{
 PORTA=0, 
 PORTB,
 PORTC, 
 PORTD,
 PORTE,
 PORTF
}Dio_PortType;


void Dio_WriteChannel(Dio_PortType PORT,Dio_ChannelType PIN,Dio_LevelType lEVEL);
Dio_LevelType READ(Dio_ChannelType PIN);
Dio_LevelType Dio_ReadChannel(Dio_PortType PORT,Dio_ChannelType PIN);
void Dio_WritePort(Dio_PortType PORT,Dio_PortLevelType PortVal);
Dio_PortLevelType Dio_ReadPort(Dio_PortType PORT);
 
 #endif  	/* DIO_INTERFACE_H */

/**********************************************************************************************************************
 *  END OF FILE: DIO_INTERFACE.h
 *********************************************************************************************************************/
