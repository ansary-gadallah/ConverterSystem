/*
 * Sensors.h
 *
 * Created: 12/12/2022 10:10:54
 *  Author: Kimo Store
 */ 


#ifndef SENSORS_H_
#define SENSORS_H_

#define LM35_CH   CH_0
#define Thermistor_CH   CH_0             
#define MQ_2_CH   CH_0  
#define LDR_CH   CH_7  
#define  MPX4115   CH_0
u16 TEMP_Read(void);
u16 MQ_2Volt(void);
u16 Thermistor(void);
u16 LDR_Volt(void);
u16 MPX4115_Read_pressure(void);



#endif /* SENSORS_H_ */