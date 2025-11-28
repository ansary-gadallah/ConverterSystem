#include "stdtypes.h"
#include "LDR_8Led.h"
#include "DIO_interface.h"
#include "ADC.h"
#include "Sensors.h"
#include "MemMap.h"


u16 LDR_8Led(void)
{
	u16 x;
	x=LDR_Volt();  // ===> in sensor.c
	if(x<4)
	{
		PORTB=0XFF;  //0b 1111 1111
	}
	else if(x<9&&x>=4)
	{
		PORTB=0xFE; //0b 1111 1110
	}
	else if(x<19&&x>=9)
	{
		PORTB=0XFC;
	}
	else if(x<48&&x>=19)
	{
		PORTB=0XF8;
	}
	else if(x<97&&x>=48)
	{
		PORTB=0XF0;
	}
	else if(x<190&&x>=97)
	{
		PORTB=0XE0;
	}
	else if(x<454&&x>=190)
	{
		PORTB=0XC0;
	}
	else if(x<834&&x>=454)
	{
		PORTB=0X80;
	}
	else if(x>=834)
	{
		PORTB=0X00;
	}
	return x;
}

