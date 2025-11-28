#include "UART_Services.h"
#include "UART.h"
#define F_CPU 8000000
#include <util/delay.h>
void UART_SendString(u8*str)
{
	u8 i;
	for (i=0;str[i];i++)
	{
		UART_SendData(str[i]);	
	}		
}


void UART_ReceiveString(u8*str)
{
	u8 i=0;
	str[i]=UART_ReceiveData();
	for (;str[i]!='#';)
	{
		i++;
		str[i]=UART_ReceiveData();
	}
	str[i]=0;
}


void UART_SendNumber(u32 num)
{
	
	/*
	UART_SendData(p[0]);
	UART_SendData(p[1]);
	UART_SendData(p[2]);
	UART_SendData(p[3]);*/
	
	UART_SendData((u8)num);
	UART_SendData((u8)(num>>8));
	UART_SendData((u8)(num>>16));
	UART_SendData((u8)(num>>24));
	
}

u32 UART_ReceiveNumber(void)
{
	u32 num=0;
	/*u8*p=&num;
	p[0]=UART_Receive();
	p[1]=UART_Receive();
	p[2]=UART_Receive();
	p[3]=UART_Receive();*/
	
	u8 b1=UART_ReceiveData();
	u8 b2=UART_ReceiveData();
	u8 b3=UART_ReceiveData();
	u8 b4=UART_ReceiveData();
	num=(u32)b1| ((u32)b2<<8) | ((u32)b2<<16)| ((u32)b2<<24);
}

#define LITTLE_ENDIAN   0
#define BIG_ENDIAN      1
u8 Endian_Test(void)
{
	u32 x=1;
	u8*p=&x;
	if (*p==1)
	{
		return LITTLE_ENDIAN;
	}
	else
	{
		return BIG_ENDIAN;
	}
}


u16 Endian_Convert16(u16 num)
{
	u16 n=num<<8|num>>8;

}
u32 Endian_Convert32(u32 num)
{
	u32 n;
	/*
	u32 b1=(num>>24);
	u32 b4=(num<<24);
	u32 b2=(num>>8)&(0x0000ff00);
	u32 b3=(num<<8)&(0x00ff0000);
	n=b1|b2|b3|b4;*/
	return (num>>24)|(num<<24)|(num>>8)&(0x0000ff00)|(num<<8)&(0x00ff0000);
	//return n;
}


void UART_SendStringCheckSum(u8*str)
{
	u8 len=0,i;
	u16 sum=0;
	for (len=0;str[len];len++)
	{
		sum=sum+str[len];
	}
	UART_SendData(len);
	for (i=0;i<len;i++)
	{
		UART_SendData(str[i]);
	}
	UART_SendData((u8)sum);
	UART_SendData((u8)(sum>>8));
	
}
u8 UART_ReceiveStringCheckSum(u8*str)
{
	u8 len=UART_ReceiveData();
	u8 i,b1,b2;
	u16 sum_calc=0,sum_rec;
	for (i=0;i<len;i++)
	{
		str[i]=UART_ReceiveData();
		sum_calc+=str[i];
	}
	b1=UART_ReceiveData();
	b2=UART_ReceiveData();
	sum_rec=(u16)b1|(u16)b2<<8;
	str[i]=0;
	if (sum_rec==sum_calc)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	

}

/*
void TX_Fuc(void)
{
	static i=0;
	UART_SendNoBlock(str[i]);
	i++;
}
void UART_SendStringAshync(u8*str)
{
	static u8 i;
	UART_TX_InterruptEnable();
	UART_TX_SetCallBack(TX_Fuc);
	i++;
	if(str[i]=='0')
	{
		i=0;
	}
	
	for (i=0;str[i];i++)
	{
		UART_SendData(str[i]);
	}
}*/








//**********************************

static u8*TX_Str;
//static u8 flag=1;
//static u8 i=0;
                                   
void func_tx(void)
{
	static u8 i=1;
	if (TX_Str[i]!=0)
	{
		UART_SendNoBlock(TX_Str[i]);
		i++;
	}
	else
	{
		i=1;
	}
	
}

void UART_SendStringAshync(u8*str)
{
	//static u8 i=0;
	UART_TX_SetCallBack(func_tx);
	UART_SendNoBlock(str[0]);
	TX_Str=str;
	//i++;
	UART_TX_InterruptEnable();
}

void UART_SendStringNoBlock(u8*str)
{
	
}


u8* RX_Str;
void func_Rx(void)
{
	static u8 i=0;
	RX_Str[i]=UART_ReceiveNoBlock();
	i++;
}

void UART_ReceiveStringAshync(u8*str)
{
	UART_RX_SetCallBack(func_Rx);
	
	UART_RX_InterruptEnable();
	RX_Str=str;
}












/*
void UART_SendStringInit(void)
{
	UART_TX_SetCallBack(func_tx2);
	UART_TX_InterruptEnable();
}*/
/*
void UART_SendStringRunnable(void)
{
	static u8 j=0;
	static u8 i=0;
	if (flag==1)
	{
		if (TX_Str[i][j])
		{
			UART_SendNoBlock(TX_Str[i][j]);
			j++;
		}
		else
		{
			j=0;
			i++;
		}
		flag=0;
	}
	
}

void UART_SendStringSetter(u8*str)
{
	TX_Str[i]=str;
	i++;
}



u8 RX_Buffer1[8];
u8 RX_Buffer2[8];
static u8 Bufferflag=0;
u8 readyflag=0;
static void func_Rx2(void)
{
	static u8 i=0;
	
	if (Bufferflag==0)
	{
		RX_Buffer1[i]=UART_ReceiveNoBlock();
	}
	else
	{
		RX_Buffer2[i]=UART_ReceiveNoBlock();
	}
	i++;
	if (i==8)
	{
		i=0;
		readyflag=1;
		Bufferflag^=1;
	}
	
}

void UART_BufferInit(void)
{
	UART_RX_SetCallBack(func_Rx2);
	
	UART_RX_InterruptEnable();
}

u8 UART_BufferGetter(u8*str)
{
	u8 i;
	if (readyflag==0)
	{
		return 0;
	}
	for (i=0;i<8;i++)
	{
		if (Bufferflag==0)
		{
			str[i]=RX_Buffer2[i];
		}
		else
		{
			str[i]=RX_Buffer1[i];
		}
	}
	readyflag=0;
	return 1;
}
*/
