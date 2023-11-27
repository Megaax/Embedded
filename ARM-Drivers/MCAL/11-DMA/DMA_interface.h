#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H


void DMA_voidInit(void);

void DMA_voidChannelStart(u32 * u32Ptr_Source, u32 * u32Ptr_Destination,u16 u16_BlockLength);


#endif
