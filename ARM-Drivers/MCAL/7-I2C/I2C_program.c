#include "BIT_MATH.h"
#include "STD_TYPES_H.h"

#include "I2C_interface.h"
#include "I2C_private.h"
#include "I2C_config.h"


void I2C_VoidSpiInit()
{
	
}
void SPI_VoidSendReceive(u8 u8_SentData , u8* u8_ReceivedData)
{

	/*make slave pin low*/

	SPI->DR=u8_SentData;

	while(GET_BIT(SPI->SR,7) == 1);

	u8_ReceivedData=SPI->DR;
	/*make slave pin HIGH*/



}
