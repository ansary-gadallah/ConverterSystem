
//#include <avr/io.h>
#include "MemMap.h"
#include "Utils.h"
#define F_CPU 8000000
#include <util/delay.h>
#include "stdtypes.h"
#include "DIO_interface.h"

#include "DIO_cfg.h"

#include "MOTOR_interface.h"
#include "LCD.h"
#include "KeyPad.h"
#include "ADC.h"
#include "Sensors.h"
#include "Fire System.h"
#include "EX_Interrupt.h"
#include "Calculator.h"
#include "Converter.h"
#include "Timers.h"
#include "RGB.h"
#include "Timers_Services.h"
#include "ULTRASONIC.h"
#include "U_Soinc.h"
#include "UART.h"
#include "UART_Services.h"
#include "SPI.h"
#include "SPI_App.h"
#include "Stepper_interface.h"
#include "Automatic System(MTI).h"
#include "SERVO_MOTOR.h"
#include "Kernel_Private.h"
#include "Kernel_Interface.h"


#define  LED_RED      PINC0
#define  LED_GREEN   PINB2
#define  LED_BLUEE   PIND1
#define  MOTOR       PIND1
//#define  M1       PIND0
//#define  M2       PINC1
#define  M3       PINC2
#define  IN1       PIND0
#define  IN2       PIND1
#define  GLOBAL_EN    sei
#define  GLOBAL_DIS    cli

volatile u16 c,t1,t2,t3,time;
volatile u16 des;
extern volatile u8 flag;
u32 freq;
u8 duty;
 u8 data=0;
                        

void F1(void);
void F2(void);
void F3(void);
void F4(void);
  int main(void)
{
	DIO_Init();
	//LCD_Init();
	//KEYPAD_Init();
	//ADC_Init(VREF_AVCC,ADC_SCALER_64);
	GLOBAL_EN();
	RTOS_u8CreateTask(0,&F1,5000,2);
	RTOS_u8CreateTask(1,&F2,1000,0);
	RTOS_u8CreateTask(2,&F3,10000,1);
	RTOS_u8CreateTask(3,&F4,5000,2);
	RTOS_voidStart();
	//DIO_TogglePIN(PINA0);
	while(1)
	{	
		_
        
		
	}
	
}

void F1(void)
{
	DIO_TogglePIN(PINA0);
	
}
void F2(void)
{
	DIO_TogglePIN(PINA1);
	
}
void F3(void)
{
	DIO_TogglePIN(PINA2);
	
}
void F4(void)
{
	DIO_TogglePIN(PINA3);
	
}




/*
typedef enum{
	Even,
	Odd
}frame_type;


void f(frame_type num)
{
	u8 data,i,c=0;
	for(i=0;i<8;i++)
	{
		data=data>>i&1;
		if(data==1)
		{
			c++;
		}
	}
	if(c%2==0)
	{
		// parity=0;
	}
	if(c%2==1)
	{
		//parity=1;
	}
	
}*/
static void Func_ICU(void)
{
	/*if(flag==0)
	{
		t1=ICR1;
		Timer1_InputCaptureEdge(FALLING);
		flag=1;
	}
	else if(flag==1)
	{
		t2=ICR1;
		Timer1_InputCaptureEdge(RISING);
		flag=2;
	}*/
	
}



/*
ISR(INT0_vect)
{
	static u8 flag;
	static u16 ton, toff;
	if(flag==0)
	{
		t1=TCNT1;
		c=0;
		flag=1;
		EXI_TriggerEdge(EX_INT0,FALLING_EDGE);
	}
	else if(flag==1)
	{
		t2=TCNT1;
		c=0;
		ton=(t2-t1)+c*65535;
		flag=2;
		EXI_TriggerEdge(EX_INT0,RISING_EDGE);
		
	}
	else if(flag==2)
	{
		t3=TCNT1;
		c=0;
		toff=(t3-t2)+c*65535;
		t1=t3;
		flag=1;
		EXI_TriggerEdge(EX_INT0,FALLING_EDGE);
		duty=((u32)ton*100)/((u32)ton+toff);
		freq=(u32)1000000/((u32)toff+ton);
		FLAG=5;
	}
	
}
*/















































/*ISR  ===> (Interrupt Service Rotine)   =====>> code whitch will run when interrupt accure*/
 //
/*
ISR(TIMER0_OVF_vect)
{
	TCNT0=6;
	static u16 c=0;
	c++;
	if(c==40)
	{
		//DIO_TogglePIN(PINC0);
		flag=0;
		flag2=0;
		flag3=0;
		c=0;
		
	}
}*/
/*
ISR(TIMER0_OC_vect)
{
	//OCR0+=10;	
	DIO_TogglePIN(PINC0);
}*/

/*ISR(INT0_vect,ISR_NOBLOCK)
{
	
	//DIO_TogglePIN(PINC0);
	flag=1;
}*/

/*
ISR(INT0_vect)
{
	//GLOBAL_EN();
	DIO_TogglePIN(PINC0);
	//flag=2;
	
}*/

/*ISR(BAD_vect) ///  BAD Interrupt
{
	DIO_TogglePIN(PINC5);
}*/
/*ISR(TIMER0_OVF_vect)
{
	
	TCNT0=6;
	static u16 flag=0;
	c++;
	iffl
	{
		DIO_TogglePIN(PINC0);
		c=0;
	}
	
}*/
                  


























/*
void __vector_5(void)__attribute__ ((signal));   // to context switch
void __vector_5(void)
{
	u16 num =ADC_GetReadNoBlock();
	LCD_WriteNumber(num);
}
void __vector_10(void)__attribute__ ((signal));
void __vector_10(void)
{
	DIO_WritePin(PINC0,HIGH);
}*/

	
	/*x=TEMP_Read();
		LCD_SetCursor(0,2);
		 LCD_WriteString("TEMP");
		LCD_SetCursor(0,7);
		LCD_WriteNumber(x/10);
		LCD_WriteChar('.');
		LCD_WriteNumber(x%10);
		LCD_WriteString("       ");
		LCD_SetCursor(1,4);
		LCD_WriteString("GOOD TEMP");
		LCD_WriteString("       ");*/
	
	
	
	
	
	
	