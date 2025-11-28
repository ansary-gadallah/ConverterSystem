
#include "stdtypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "ADC.h"
#include "DIO_interface.h"
#define F_CPU 8000000
#include <util/delay.h>
u16 volt_ref;
static u8 ADCflag=1;
void ADC_Init(ADC_Vref_type vref,ADC_Prescaler_type scaler)           //01010 000
{     /*clock*/                                                       //11111 000
	scaler=scaler&0x07; //00000111                                                 
	ADCSRA=ADCSRA&0xf8;  //1111 1000
	ADCSRA=ADCSRA|scaler;   
	
	
	 /*volt ref*/ 
	switch(vref)
	{
		case VREF_AREF:
		CLR_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		 volt_ref=AREF;
		break;
		case VREF_AVCC:
		SET_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		volt_ref=5000;
		break;
		case VREF_256:
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
		volt_ref=2560;
		break;
	}
	CLR_BIT(ADMUX,ADLAR);
	/*ADC Enable*/
	SET_BIT(ADCSRA,ADEN);
	
	
	
}


u16 ADC_Read(ADC_Channel_type ch)
{
	DIO_TogglePIN(PINC0);
	u16 adc;
	u8 adcl,adch;
	/* select channel*/
	ch=ch&0x07;   //===> 0000 0111
	ADMUX=ADMUX&0xE0;         //1100 0  000
	ADMUX=ADMUX|ch;
	/* start conversion */
	SET_BIT(ADCSRA,ADSC);
	/* w8 until finish */
	while(READ_BIT(ADCSRA,ADSC));
	/* get read */  
	adcl=ADCL;
	adch=ADCH;
	adc=adch<<8|adcl;
	//adc=ADC;  if cast short to read 2 byte toggither
	DIO_TogglePIN(PINC0);
	return adc;
}

  
  void ADC_StartConversion(ADC_Channel_type ch)
  {
	  if(ADCflag==1)
	  {
		  /* select channel*/
		  ch=ch&0x07;
		  ADMUX=ADMUX&0xE0;         //1100 0  000
		  ADMUX=ADMUX|ch;
		  /* start conversion */
		  SET_BIT(ADCSRA,ADSC);
		  ADCflag=0;
	  }
  }
  
  u16 ADC_GetRead(void)
  {
	  u16 adc;
	  u8 adcl,adch;
	  /* w8 until finish */
	  while(READ_BIT(ADCSRA,ADSC));
	  /* get read */
	  adcl=ADCL;
	  adch=ADCH;
	  adc=adch<<8|adcl;
	  //adc=ADC;  if cast short to read 2 byte toggither
	  ADCflag=1;
	  return adc;
	  
	  
  }
  
  u16 ADC_GetReadPerodic(u16*Pdata)
  {
	  u16 adc;
	  u8 adcl,adch;
	  adcl=ADCL;
	  adch=ADCH;
	  adc=adch<<8|adcl;
	  if(!READ_BIT(ADCSRA,ADSC))
	  {
		  *Pdata=adc;
		  ADCflag=1;
		  return 1;
	  }
	  else
	  {
		  return 0;
       }
  }
  
 u16 ADC_GetReadNoBlock(void)
 {
	 /* get read */
  u16 adc;
  u8 adcl,adch;
  adcl=ADCL;
  adch=ADCH;
  adc=adch<<8|adcl;
  return adc;
 }
   
  
  
  
  
u16 ADC_ReadVolt(ADC_Channel_type ch)
{
	u16 adc=ADC_Read(ch);
	u16 volt=(adc*(u32)volt_ref)/1024;     //casting
	return volt;
}