#include "Std_Types.h"

#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H


#define UART0_ADDRESS  0x4000C000
#define UART1_ADDRESS  0x4000D000
#define UART2_ADDRESS  0x4000E000
#define UART3_ADDRESS  0x4000F000
#define UART4_ADDRESS  0x40010000
#define UART5_ADDRESS  0x40011000
#define UART6_ADDRESS  0x40012000
#define UART7_ADDRESS  0x40013000




typedef enum
{ 
FIVE_BIT=0,
SIX_BIT,
SEVEN_BIT,
EIGHT_BIT
}UART_WORD_SIZE; 

#define RECEIVE_INTERRUPT_BIT 4
#define TRANSMIT_INTERRUPT_BIT 5
#define PARITYERROR_INTERRUPT_BIT 8
/*
typedef struct{
union{
  uint32 REG;
  struct {
    uint32 DATA:8;//Data TX or RX
    uint32 FE:1;//Framing Error
    uint32 PE:1;//Parity Error
    uint32 BE:1;//Btrak Error
    uint32 OE:1;//OverRun Error
  }BIT;
} 
DR;
uint32 ECR;
uint32 RESERVED[5];
union{
  uint16 REG;
  struct{
    uint16 CTS:1;//Clear to Send
    uint16 RESERVED:2;
    uint16 BUSY:1;
    uint16 RXFE:1;//RX FIFO empty
    uint16 TXFF:1;//Tx FIFO Full
    uint16 RXFF:1;//Rx FIFO Full
    uint16 TXFE:1;//Tx FIFO Empty
  }BIT;
}
FR;//Flag Register
uint32 ILPR;
uint32 IBRD;//Integer Baud-Rate Divisor
uint32 FBRD;//Fractional Baud-Rate Divisor
union{
  uint32 REG;
  struct{
    uint32 BRK:1;//Break BIt
    uint32 PEN:1;//Parity Bit
    uint32 EPS:1;//Even Parity
    uint32 STP:1;//Stop bits
    uint32 FEN:1;//FIFO enable
    uint32 WLEN:2;//Word Length [5-8]
    uint32 SPS:1;//Stick parity
  }BIT;
} 
LCRH;//Line Control Register
uint32 CTL;//Control Register(just use Bit0: ENable,Bit4 :EOT, Bit5:HSE, TXE:bit8 RXE:bit9)
uint32 IFLS;
uint32 IM;//Interrupt Mask
uint32 RIS;//Raw Interrput status
uint32 MIS;//Masked Interrput status
uint32 ICR;//Interrput Clear
}UART_t; 
*/

typedef struct {                                    /*!< UART0 Structure                                                       */
   uint32 DR;                                /*!< UART Data                                                             */
  /*
  union {
    __IO uint32_t  ECR_UART_ALT;                     UART Receive Status/Error Clear                                       
    __IO uint32_t  RSR;                            < UART Receive Status/Error Clear                                       
  };*/
	    uint32  RSR;

    uint32  RESERVED[4];
   uint32  FR;                                /*!< UART Flag                                                             */
    uint32  RESERVED1;
   uint32  ILPR;                              /*!< UART IrDA Low-Power Register                                          */
   uint32  IBRD;                              /*!< UART Integer Baud-Rate Divisor                                        */
   uint32  FBRD;                              /*!< UART Fractional Baud-Rate Divisor                                     */
   uint32  LCRH;                              /*!< UART Line Control                                                     */
   uint32  CTL;                               /*!< UART Control                                                          */
   uint32  IFLS;                              /*!< UART Interrupt FIFO Level Select                                      */
   uint32  IM;                                /*!< UART Interrupt Mask                                                   */
   uint32  RIS;                               /*!< UART Raw Interrupt Status                                             */
   uint32  MIS;                               /*!< UART Masked Interrupt Status                                          */
    uint32  ICR;                               /*!< UART Interrupt Clear                                                  */
   uint32  DMACTL;                            /*!< UART DMA Control                                                      */
    uint32  RESERVED2[22];
   uint32  _9BITADDR;                         /*!< UART 9-Bit Self Address                                               */
   uint32  _9BITAMASK;                        /*!< UART 9-Bit Self Address Mask                                          */
    uint32  RESERVED3[965];
   uint32  PP;                                /*!< UART Peripheral Properties                                            */
    uint32  RESERVED4;
   uint32  CC;                                /*!< UART Clock Configuration                                              */
} UART_t;




#define GPIO_CLK										*((volatile uint32*)(0x400FE608))

#define UART_CLK 										*((volatile uint32*)(0x400FE618))

#define  UART_5 ((volatile UART_t *)  (UART5_ADDRESS))


#define  UART_1 ((volatile UART_t *)  (UART1_ADDRESS))












#endif