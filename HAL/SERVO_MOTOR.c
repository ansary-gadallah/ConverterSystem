
#include "stdtypes.h"
#include "DIO_interface.h"
#include "Timers.h"
#include "SERVO_MOTOR.h"
#define  F_CPU 8000000
#include <util/delay.h>


void SERVO_Init(void)
{
	 Timer1_Init(Timer1Mode_SERVO,TIMER1_SCALER_8);
	Timer1_OCRA1Mode(OCRAMode_SERVO);
	Timer1_OCRB1Mode(OCRBMode_SERVO);
	ICR1=19999;
}

void SERVO_SetPosition(u8 Angle,SERVO_TYPES servo)
{
	if(servo==SERVO_1)
	{
		OCR1A=(Angle*(u32)1000/180)+999;
		
	}
	if(servo==SERVO_2)
	{
		OCR1B=(Angle*(u32)1000/180)+999;
	}
}

void SERVO_SetPosition_2(u8 Angle,SERVO_TYPES servo)
{
	//OCR1A=(Angle*(u32)2000/180)+499;
     if(servo==SERVO_1)
     {
	     OCR1A=(Angle*(u32)1000/180)+999;
	     
     }
     if(servo==SERVO_2)
     {
	     OCR1B=(Angle*(u32)1000/180)+999;
     }
}