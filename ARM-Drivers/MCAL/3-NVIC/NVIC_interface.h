#ifndef NVIC_interface_H
#define NVIC_interface_H


void NCIV_VoidEnableInterrupt (u8 u8_INT);
void NCIV_VoidDisableInterrupt(u8 u8_INT);
void NCIV_VoidSetPendingFlag  (u8 u8_INT);
void NCIV_VoidClearPendingFlag(u8 u8_INT);
u8 NVIC_u8GetActiveFlag       (u8 u8_INT);





#endif 
