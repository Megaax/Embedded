#ifndef 	USART_INTERFACE_H
#define 	USART_INTERFACE_H

void USART_Init();
u8 USART_Receive(u32 MaxTimeToWait);
void USART_TransmitString(u8 * dataPtr);
void USART_TransmitChar(u8 Data);
#endif
