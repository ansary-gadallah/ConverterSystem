
#include "stdtypes.h"
#include "DIO_interface.h"
#include "Stepper_interface.h"
#define F_CPU 8000000
#include <util/delay.h>





 void Stepper_Unipoler_CCW(void)
 {
	 DIO_WritePin(Coil_1A,HIGH);
	 DIO_WritePin(Coil_1B,LOW);
     DIO_WritePin(Coil_2A,LOW);
	 DIO_WritePin(Coil_2B,LOW);
	 _delay_ms(Delay);
	 DIO_WritePin(Coil_1A,LOW);
	 DIO_WritePin(Coil_1B,HIGH);
	 DIO_WritePin(Coil_2A,LOW);
	 DIO_WritePin(Coil_2B,LOW);
	 _delay_ms(Delay);
	 DIO_WritePin(Coil_1A,LOW);
	 DIO_WritePin(Coil_1B,LOW);
	 DIO_WritePin(Coil_2A,HIGH);
	 DIO_WritePin(Coil_2B,LOW);
	 _delay_ms(Delay);
	 DIO_WritePin(Coil_1A,LOW);
	 DIO_WritePin(Coil_1B,LOW);
	 DIO_WritePin(Coil_2A,LOW);
	 DIO_WritePin(Coil_2B,HIGH);
	 _delay_ms(Delay);
	 
 }
 void Stepper_Unipoler_CW(void)
 {
	  DIO_WritePin(Coil_1A,LOW);
	  DIO_WritePin(Coil_1B,LOW);
	  DIO_WritePin(Coil_2A,LOW);
	  DIO_WritePin(Coil_2B,HIGH);
	  _delay_ms(Delay);
	   DIO_WritePin(Coil_1A,LOW);
	   DIO_WritePin(Coil_1B,LOW);
	   DIO_WritePin(Coil_2A,HIGH);
	   DIO_WritePin(Coil_2B,LOW);
	   _delay_ms(Delay);
	   DIO_WritePin(Coil_1A,LOW);
	   DIO_WritePin(Coil_1B,HIGH);
	   DIO_WritePin(Coil_2A,LOW);
	   DIO_WritePin(Coil_2B,LOW);
	   _delay_ms(Delay);
	   DIO_WritePin(Coil_1A,HIGH);
	   DIO_WritePin(Coil_1B,LOW);
	   DIO_WritePin(Coil_2A,LOW);
	   DIO_WritePin(Coil_2B,LOW);	 
       _delay_ms(Delay);
	 
 }
 /****************************************************************/
 
 void Stepper_Angle(u16 angle,Direction_move direction)
 {
	u8 i;
	 u32 range;
	 range=((u32)angle*2048)/360;    // where resolution is  0.17
	 
	 for(i=0;i<(range/4);i++)
	 {
		 if(direction==CW)
		 {
			 	 Stepper_Unipoler_CW();
		 }
		 else if(direction==CCW)
		 {
			 	 Stepper_Unipoler_CCW();
		 }
	
	 }
 }
 
 
 void Stepper_Rotate(u16 rotate,Direction_move direction)
 {
	 u16 i;
	 for(i=0;i<(512*rotate);i++)     // where resolution is  0.175
	 {
		 if(direction==CW)
		 {
			 Stepper_Unipoler_CW();
		 }
		 else if(direction==CCW)
		 {
			 Stepper_Unipoler_CCW();
		 }
	 }
 }
