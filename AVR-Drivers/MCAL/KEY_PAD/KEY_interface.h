/*
 * KEY_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HOME
 */

#ifndef KEY_INTERFACE_H_
#define KEY_INTERFACE_H_

#define COLDDR  (u8 volatile *const)(0x31)
#define ROWDDR (u8 volatile *const)(0x37)



#define c0 (u8) 2
#define c1 (u8) 3
#define c2 (u8) 4
#define c3 (u8) 5

#define r0 (u8) 4
#define r1 (u8) 5
#define r2 (u8) 6
#define r3 (u8) 7

void KEY_PADInitialization(void);

STD_ERROR KeyPad_GetPressedKey(u8 a[4][4]);




#endif /* KEY_INTERFACE_H_ */
