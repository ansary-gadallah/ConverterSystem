


#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_

#define Coil_1A  PINC0
#define Coil_1B  PINC1
#define Coil_2A  PINC2
#define Coil_2B  PINC3

#define   Delay  10

typedef enum{
	CW,
	CCW
}Direction_move;


 void Stepper_Unipoler_CW(void);
 void Stepper_Unipoler_CCW(void);
 
 void Stepper_Angle(u16 angle,Direction_move direction);
 void Stepper_Rotate(u16 rotate,Direction_move direction);
 //void Stepper_CW(void);




#endif /* STEPPER_INTERFACE_H_ */