

#include "stdtypes.h"
//#include "MemMap.h"
#include "ADC.h"
#include "Sensors.h"
static u16 array_temp_res[]={275,263,252,241,231,221,212,204,195,187
	,180,172,166,159,153,147,141,136,130,125,
	120,116,112,107,103,100,96,92,89,86,83,80
	,77,74,71,69,66,64,62,60,58,56,54,52,50,49
	,47,45,44,43,41,40,39,37,36,35,34,33,32,31,
   30,29,28,27,26,25};

u16 TEMP_Read(void)  //=====>> LM35
{
	u16 volt =ADC_ReadVolt(LM35_CH);
	u16 temp=volt;
	return temp;
}

/*u16 Thermistor(void)
{
	u16 volt =ADC_ReadVolt(Thermistor_CH);
	return volt;
}*/

   
u16 MQ_2Volt(void)
{
	u16 volt =ADC_ReadVolt(MQ_2_CH);
	return volt;
}


u16 Thermistor(void){
	u16 volt=ADC_ReadVolt(Thermistor_CH);
	u32 res=(u32)((u32)5000*125)-((u32)volt*125);
	res=res/volt;
	u8 first=0,last=65,ans=0,mid;
	while(first<=last){
		mid=(first+last)/2;
		if(res<=array_temp_res[mid]){
			first=mid+1;
			ans=mid;
		}else if(res>array_temp_res[mid])
		last=mid-1;
	}
	return ans;
}


u16 LDR_Volt(void)
{
	u16 volt =ADC_ReadVolt(LDR_CH);
	return volt;
}

u16 MPX4115_Read_pressure(void)
{
	
	u16 adc=ADC_GetRead();
	  u32 press=((u32)1000*(adc-55)/921)+150;
	return press;
}


