

#ifndef UART_SERVICES_H_
#define UART_SERVICES_H_


#include "UART.h"

void UART_SendString(u8*str);
void UART_ReceiveString(u8*str);
void UART_SendStringCheckSum(u8*str);
u8 UART_ReceiveStringCheckSum(u8*str);
void UART_SendStringAshync(u8*str);
void UART_ReceiveStringAshync(u8*str);
u32 Endian_Convert32(u32 num);
u16 Endian_Convert16(u16 num);
u8 Endian_Test(void);
u32 UART_ReceiveNumber(void);
void UART_SendNumber(u32 num);
void UART_SendStringNoBlock(u8*str);
#endif /* UART_SERVICES_H_ */