#include "UART_Interface.h"
#include "UART_Private.h"
#include "DIO_PRIVATE.h"
#include "BIT_MATH.h"


static void (*UART_0_Rx_callback) (void) = NULL;
static void (*UART_0_Tx_callback)(void) = NULL;




void UART_voidInit()
{
		SET_BIT(UART_CLK,1); 
	  SET_BIT(GPIO_CLK,PORTC);
		UART_1->CTL = 0;         /* UART5 module disbable */
    UART_1->IBRD = 104;      /* for 9600 baud rate, integer = 104 */
    UART_1->FBRD = 11;       /* for 9600 baud rate, fractional = 11*/
    UART_1->CC = 0;          /*select system clock*/
    UART_1->LCRH = 0x60;     /* data lenght 8-bit, not parity bit, no FIFO */
    UART_1->CTL = 0x301;
	
	  GPIOC->DEN = 0x30;      /* set PE4 and PE5 as digital */
    GPIOC->AFSEL = 0x30;    /* Use PE4,PE5 alternate function */
    GPIOC->AMSEL = 0;    /* Turn off analg function*/
    GPIOC->PCTL = 0x00110000;
	

}

void UART_voidSendChar(unsigned char data)  
{
while((UART_1->FR & (1<<5)) != 0); /* wait until Tx buffer not full */
    UART_1->DR = data;     
}

char UART_charGetRecievedChar(void)
{
     char data;
	  while((UART_1->FR & (1<<4)) != 0); /* wait until Rx buffer is not full */
    data = UART_1->DR ;  	/* before giving it another byte */
    return (unsigned char) data;  
}

void UART_voidSendString(char *str)
{
  while(*str)
  {
      UART_voidSendChar(*(str++));
  }
}


