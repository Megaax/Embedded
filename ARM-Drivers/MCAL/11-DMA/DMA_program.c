#include "BIT_MATH.h"
#include "STD_TYPES_H.h"

#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"


void DMA_voidInit(void)
{

	#if CHANNEL_ID==1

	DMA->channel[0].CCR=0x00007AC3;
	#endif
}

void DMA_voidChannelStart(u32 * u32Ptr_Source, u32 * u32Ptr_Destination,u16 u16_BlockLength)
{
	CLR_BIT(DMA->channel[0].CCR,0);
	DMA->channel[0].CPAR  = u32Ptr_Source;
	DMA->channel[0].CMAR  = u32Ptr_Destination;
	DMA->channel[0].CNDTR = u16_BlockLength;
	SET_BIT(DMA->channel[0].CCR,0);

}
