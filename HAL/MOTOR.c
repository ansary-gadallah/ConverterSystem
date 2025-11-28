
#include "stdtypes.h"
#include "DIO_interface.h"
#include "MOTOR_interface.h"
#include "MOTOR_cfg.h"

extern const u8 arr1[NUMBER_MOTORS]; 
extern const u8 arr2[NUMBER_MOTORS];
void MOTOR_Stop(MOTOR_type motor)
{
	
	DIO_WritePin(arr1[motor],LOW);
	DIO_WritePin(arr2[motor],LOW);
	
}
void MOTOR_CW(MOTOR_type motor)
{
	
	DIO_WritePin(arr1[motor],HIGH);
	DIO_WritePin(arr2[motor],LOW);
	

}
void MOTOR_CCW(MOTOR_type motor)
{
		
	DIO_WritePin(arr1[motor],LOW);
	DIO_WritePin(arr2[motor],HIGH);

}
