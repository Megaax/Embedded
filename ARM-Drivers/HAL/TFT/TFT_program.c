#include "STD_TYPES_H.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SPI_interface.h"
#include "STK_interface.h"

#include "TFT_interface.h"
#include "TFT_config.h"
#include "TFT_private.h"





void TFT_VoidInit(void)
{
	
	
}

void TFT_VoidDislpayImage(const u16* u16_image )
{
	
	
	
}


static void VoidWriteCommand(u8 u8_COMMAND) /*A0 is 0*/
{
	u8 LOCAL_u8NotUsed
	
	SPI_VoidSendReceive(u8_COMMAND,&LOCAL_u8NotUsed);
	
}

static void VoidWriteData(u8 u8_DATA) /*A0 is 1*/
{
		u8 LOCAL_u8NotUsed
	
	SPI_VoidSendReceive(u8_DATA,&LOCAL_u8NotUsed);
	
}