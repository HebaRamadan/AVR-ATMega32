/*
 * DC_Motor_prg.c
 *
 *  Created on: Feb 19, 2020
 *      Author: zas
 */

#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#include "Dio_int.h"
#include "DC_Motor_cfg.h"
#include "DC_Motor_int.h"


void DC_vidInit(void)
{
	Dio_vidSetPinDir(DC_MOTOR_u8PIN , DIO_u8OUTPUT);
}

void DC_vidTurnOn(void)
{
	Dio_vidSetPinval(DC_MOTOR_u8PIN , DIO_u8HIGH);
}


void DC_vidTurnOff(void)
{
	Dio_vidSetPinval(DC_MOTOR_u8PIN , DIO_u8LOW);
}
