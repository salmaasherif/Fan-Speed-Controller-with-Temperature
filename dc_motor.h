/*
 * dc_motor.h
 *
 *  Created on: Oct 11, 2021
 *      Author: ahmed
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"

#endif /* DC_MOTOR_H_ */
typedef enum
{
	STOP,CW,ACW
}DcMotor_State;

void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 speed);
