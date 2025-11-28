
#include "UART.h"

u8 init_flag=0;
static void(*UART_RX_Fptr)(void)=NULLPTR;
static void(*UART_TX_Fptr)(void)=NULLPTR;


void UART_Init(void)
{
	//baud rate 9600 f=8mhz,normal speed
	UBRRL=51;
	//frame-> no parity , 8data bits , 1 stop bits
	//enable
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
	CLR_BIT(UCSRA,U2X);
}


void UART_SendData(u8 data)
{
		while(!READ_BIT(UCSRA,UDRE));
		UDR=data;
	
}

u8 UART_ReceiveData(void)
{
	while(!READ_BIT(UCSRA,RXC));
	return UDR;
}

u8 UART_ReceivePerodic(u8*pdata)
{
	if (READ_BIT(UCSRA,RXC))
	{
		*pdata=UDR;
		return 1;
	}
return 0;
}

void UART_SendNoBlock(u8 data)
{
	UDR=data;
}

u8 UART_ReceiveNoBlock(void)
{
	return UDR;
}


void UART_RX_InterruptEnable(void)
{
	SET_BIT(UCSRB,RXCIE);
}

void UART_RX_InterruptDisable(void)
{
	CLR_BIT(UCSRB,RXCIE);
}

void UART_TX_InterruptEnable(void)
{
	SET_BIT(UCSRB,TXCIE);
}

void UART_TX_InterruptDisable(void)
{
	CLR_BIT(UCSRB,TXCIE);
}

void UART_RX_SetCallBack(void (*LocalFptr)(void))
{
	UART_RX_Fptr = LocalFptr;
}

void UART_TX_SetCallBack(void (*LocalFptr)(void))
{
	UART_TX_Fptr = LocalFptr;
}


ISR(UART_RX_vect)
{
	if (UART_RX_Fptr!=NULLPTR)
	{
		UART_RX_Fptr();
	}
}

ISR(UART_TX_vect)
{
	if (UART_TX_Fptr!=NULLPTR)
	{
		UART_TX_Fptr();
	}
}	
	




