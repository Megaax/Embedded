/*
 * DIO_interface.h

 *
 *  Created on: ??þ/??þ/????
 *      Author: HOME
 */

#include "stdtype.h"

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define PIND  (u8 *const)(0x30)
#define DDRD (u8 *const)(0x31)
#define PORTD  (u8 *const)(0x32)



#define PORT_A			(u8)(3)
#define PORT_B			(u8)(2)
#define PORT_C          (u8)(1)
#define PORT_D          (u8)(0)
#define ZERO 0
#define DIO_REG_OFSET 3


#define P_0  (u8)(0)
#define P_1  (u8)(1)
#define P_2  (u8)(2)
#define P_3  (u8)(3)
#define P_4  (u8)(4)
#define P_5  (u8)(5)
#define P_6  (u8)(6)
#define P_7  (u8)(7)

#define DIO__DIR_INPUT    (u8)50
#define DIO__DIR_OUTPUT  (u8)70
#define DIO_VALUE_HIGH (u8) 60
#define DIO_VALUE_LOW (u8) 90

#define ALL_PORT_OUTPUT (u8) 0xff
#define ALL_PORT_INPUT (u8) 0x00
void DIO_voidInatialize (void);

STD_ERROR DIO_SetPinDir(u8 PORT_,u8 P_,u8 DIO_DIR);

STD_ERROR DIO_SetPinValue(u8 PORT_, u8 P_, u8 DIO_VALUE_);

STD_ERROR DIO_SetPortValue(u8 PORT_,  u8 DIO_VALUE_);

STD_ERROR DIO_SetPortDir(u8 PORT_, u8 DIO_DIR_);

STD_ERROR DIO_GetPinValue(u8 PORT_, u8 P_,u8 * Pin_Value );



#endif /* DIO_INTERFACE_H_ */
