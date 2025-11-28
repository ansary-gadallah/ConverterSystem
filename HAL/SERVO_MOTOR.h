/*
 * SERVO_MOTOR.h
 *
 * Created: 25/02/2023 20:50:27
 *  Author: Kimo Store
 */ 


#ifndef SERVO_MOTOR_H_
#define SERVO_MOTOR_H_

#define  Timer1Mode_SERVO   TIMER1_FASTPWM_ICR_TOP_MODE
#define  OCRAMode_SERVO     OCRA_NON_INVERTING 
#define  OCRBMode_SERVO     OCRB_NON_INVERTING

/*************SERVO PIN**********/

typedef enum{
	SERVO_1=PINC0,
    SERVO_2=PINC1
 }SERVO_TYPES;

void SERVO_Init(void);
void SERVO_SetPosition(u8 Angle,SERVO_TYPES servo);
void SERVO_SetPosition_2(u8 Angle,SERVO_TYPES servo);



#endif /* SERVO_MOTOR_H_ */