#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "USART_Private.h"
#include "USART_Interface.h"
#include "USART_Config.h"
void USART_Init(void){
	volatile f32 temp = 0;
	volatile u16 mantissa =0;
	volatile u8 fraction=0;
	temp = ((25000000)/(((float)UART_BAUD_RATE)*16)) ;
	/*mantissa */
	mantissa = (u16)temp;
	temp-=mantissa;
	temp *=16;
	/*approximating fraction to the nearest whole number*/
	if( ( temp-( (int) temp ) )*10 >=5 ){temp++;}
	/*fraction*/
	fraction = (u8) temp ;
	UART->BRR.BIT.DIV_MANTISSA = mantissa;
	UART->BRR.BIT.DIV_FRACTION = fraction;
	/*enable Tx */
	UART->CR1.BIT.TE =1;
	/*enable Rx*/
	UART->CR1.BIT.RE =1 ;
	/*enable UART*/
	UART->CR1.BIT.UE = 1;
}

u8 USART_Receive(u32 MaxTimeToWait){
	u32 counter =0 ;
	/*poll on data register not empty flag*/
	while(UART->SR.BIT.RXNE==0){
		counter++;
		if(counter==MaxTimeToWait){ return '#' ; }
	}
	/*clear flag by writing zero*/
	UART->SR.BIT.RXNE=0;
	/*return data register when data is ready */
	return UART->DR.BIT.DATA ;
}
void USART_TransmitChar(u8 Data){
	/*poll on transmission complete flag*/
	while(UART->SR.BIT.TC==0);
	/*clear flag by writing zero*/
	UART->SR.BIT.TC=0;
	/*put data in UART data register*/
	UART->DR.BIT.DATA = Data ;

}
void USART_TransmitString(u8 * dataPtr){
	int i=0;
	/*loop until null character*/
	while(dataPtr[i] != '\0'){
		USART_TransmitChar(dataPtr[i++]);
	}
}

