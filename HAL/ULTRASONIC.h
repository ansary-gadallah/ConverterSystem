#include "DIO_interface.h"
#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#define  US1   PINC0
#define  US2   PINC1
#define  US3   PINC2
#define  US4   PINC3

typedef  DIO_Pin_type  ULTRASONIC_type;
 

typedef enum{            
	ULTRASONIC_1=PIND0,  
	ULTRASONIC_2=PIND1,   
	ULTRASONIC_3=PIND2,  
	ULTRASONIC_4=PIND3,  
}ULTRASONIC_type2;  
                       


void ULTRASONIC_Init(void);
u8 ULTRASONIC_GetDistance(ULTRASONIC_type us,u16*pdistance);
u16 ULTRASONIC_GetDistance2(ULTRASONIC_type2 us);





#endif /* ULTRASONIC_H_ */