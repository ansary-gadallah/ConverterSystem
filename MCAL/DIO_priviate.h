/*
 * DIO_priviate.h
 *
 * Created: 20/11/2022 07:09:12
 *  Author: Kimo Store
 */ 


#ifndef DIO_PRIVIATE_H_
#define DIO_PRIVIATE_H_


extern const DIO_PinStatus_type PinsStatusArray[TOTAL_PINS];
static void DIO_InitPin(DIO_Pin_type PIN,DIO_PinStatus_type status);


#endif /* DIO_PRIVIATE_H_ */