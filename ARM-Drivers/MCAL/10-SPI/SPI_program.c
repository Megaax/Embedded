#include "BIT_MATH.h"
#include "STD_TYPES_H.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"


void SPI_VoidSpiInit()
{
	SPI->CR1=0x0347;
}
void SPI_VoidSendReceive(u8 u8_SentData , u8* u8_ReceivedData)
{

	/*make slave pin low*/

	SPI->DR=u8_SentData;

	while(GET_BIT(SPI->SR,7) == 1);

	u8_ReceivedData=SPI->DR;
	/*make slave pin HIGH*/



}
