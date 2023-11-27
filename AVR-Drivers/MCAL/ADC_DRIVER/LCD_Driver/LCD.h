/*
 * LCD.h
 *
 *  Created on: Sep 6, 2019
 *      Author: Naguib
 */

#ifndef LCD_H_
#define LCD_H_

#define LCD_u8DataPort            PORTA
#define LCD_u8DataDir			  DDRA
#define LCD_u8ControlPort         PORTB
#define LCD_u8ControlDir		  DDRB


#define LCD_u8RegisterSelPin      0x00     /*Rs*/
#define LCD_u8ReadWritePin        0x01      /*Rw*/
#define LCD_u8EnablePin           0x02      /*En*/

#define LCD_u8WriteVal            0x00
#define LCD_u8ReadVal             0x01
#define LCD_u8DispLine1           0x00
#define LCD_u8DispLine2           0x01

#define LCD_u8ComMoveDispR		      (0x1C)
#define LCD_u8ComMoveDispL		      (0x18)
#define LCD_u8ComMoveCurR		      (0x14)
#define LCD_u8ComMoveCurL		      (0x10)
#define LCD_u8Com8bit_2Line		      (0x38)
#define LCD_u8Com4bit_2Line		      (0x28)
#define LCD_u8ComDispOn			      (0x0C)
#define LCD_u8ComDispOnCurOn          (0x0E)
#define LCD_u8ComDispOnCurOnBlink     (0x0F)
#define LCD_u8ComDispOff			  (0x08)
#define LCD_u8ComEntryDecShift		  (0x05)
#define LCD_u8ComEntryDec			  (0x04)
#define LCD_u8ComEntryInc			  (0x06)
#define LCD_u8ComEntryIncShift		  (0x07)
#define LCD_u8ComClearScreen		  (0x01)
#define LCD_u8ComDispFirstRow		  (0x80)
#define LCD_u8ComDispSecondRow		  (0xC0)
#define LCD_u8ComReturnHome           (0x02)
#define LCD_u8ComEntryMode			  LCD_u8ComEntryInc







void LCD_voidInitialization(void);

void LCD_voidWriteCommand(u8 Copy_u8Command);

void LCD_voidWriteChar( u8 Copy_u8Char);

void LCD_voidGotoXY(u8 Copy_u8Xpos , u8 Copy_u8Ypos);

void LCD_voidClearScreen(void);

void LCD_voidWakeUp(void);

void LCD_voidWriteString(u8 * Copy_u8StringArr, u8 Copy_u8CharNum);

void LCD_VoidInttoString(u32 number , u8*num_string );


#endif /* LCD_H_ */
