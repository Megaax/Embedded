#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

#define UART_INT_ENABLE 0

//#if BAUD_RATE == 9600
#define UART_INTEGER 104
#define UART_FRACTION 11
//#elifBAUD_RATE == 19200
//  #define UART_INTEGER 52
//  #define UART_FRACTION 5
//#if BAUD_RATE == 38400
//  #define UART_INTEGER 26
//  #define UART_FRACTION 3
//#endif
void UARTConfig();
void UART_voidInit();
void UART_voidSendChar(unsigned char data);
char UART_charGetRecievedChar(void);
void UART_voidSendString(char *str);
#endif