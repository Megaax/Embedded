#include "BIT_MATH.h"
#include "STD_TYPES_H.h"

#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"



void AFIO_voidSetEXTILine(u8 u8_Line, u8 u8_PortMap)
{
	u8 Local_u8=0;
	if(u8_Line <=3)
	{
		Local_u8=0;
	}
	else if (u8_Line <=7)
	{
		Local_u8=1;
		u8_Line-=4;

	}
	else if (u8_Line <=11)
	{
		Local_u8=2;
		u8_Line-=8;
	}

	else if (u8_Line <=15)
	{
		Local_u8=3;
		u8_Line-=12;
	}

	AFIO->EXTICR[Local_u8] & ~ = ((0b1111)   <<   (u8 u8_Line * 4));
	AFIO->EXTICR[Local_u8] |   = ((u8_PortMap) << (u8 u8_Line * 4));





}
