/*
 * Stepper_prg.c
 *
 *  Created on: Feb 17, 2020
 *      Author: zas
 */
#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>
#include "Dio_int.h"
#include "Stepper_cfg.h"
#include "Stepper_int.h"

void Stepper_vidInit(void)
{
	Dio_vidSetPinDir(STEPPER_ORANGE_COIL , DIO_u8OUTPUT);
	Dio_vidSetPinDir(STEPPER_YELLOW_COIL , DIO_u8OUTPUT);
	Dio_vidSetPinDir(STEPPER_PINK_COIL   , DIO_u8OUTPUT);
	Dio_vidSetPinDir(STEPPER_BLUE_COIL   , DIO_u8OUTPUT);
}


void Stepper_vidTurnRight(u16 Degree)
{
	u16 i;
	u16 Num_of_iteration;
	Num_of_iteration = Degree / DEG_OF_ONE_ITERATION ;

	for(i=0; i<Num_of_iteration; i++)
	{
		Dio_vidSetPinval(STEPPER_ORANGE_COIL , DIO_u8HIGH);
		Dio_vidSetPinval(STEPPER_YELLOW_COIL , DIO_u8LOW);
		Dio_vidSetPinval(STEPPER_PINK_COIL   , DIO_u8LOW);
		Dio_vidSetPinval(STEPPER_BLUE_COIL   , DIO_u8LOW);
		_delay_us(1300);

		Dio_vidSetPinval(STEPPER_ORANGE_COIL , DIO_u8LOW);
		Dio_vidSetPinval(STEPPER_YELLOW_COIL , DIO_u8HIGH);
		Dio_vidSetPinval(STEPPER_PINK_COIL   , DIO_u8LOW);
		Dio_vidSetPinval(STEPPER_BLUE_COIL   , DIO_u8LOW);
		_delay_us(1300);

		Dio_vidSetPinval(STEPPER_ORANGE_COIL , DIO_u8LOW);
		Dio_vidSetPinval(STEPPER_YELLOW_COIL , DIO_u8LOW);
		Dio_vidSetPinval(STEPPER_PINK_COIL   , DIO_u8HIGH);
		Dio_vidSetPinval(STEPPER_BLUE_COIL   , DIO_u8LOW);
		_delay_us(1300);

		Dio_vidSetPinval(STEPPER_ORANGE_COIL , DIO_u8LOW);
		Dio_vidSetPinval(STEPPER_YELLOW_COIL , DIO_u8LOW);
		Dio_vidSetPinval(STEPPER_PINK_COIL   , DIO_u8LOW);
		Dio_vidSetPinval(STEPPER_BLUE_COIL   , DIO_u8HIGH);
		_delay_us(1300);

	}

}

void Stepper_vidTurnLeft(u16 Degree)
{
	u16 i;
	u16 Num_of_iteration;
	Num_of_iteration = Degree / DEG_OF_ONE_ITERATION ;

	for(i=0; i<Num_of_iteration; i++)
	{
		Dio_vidSetPinval(STEPPER_ORANGE_COIL , DIO_u8LOW);
		Dio_vidSetPinval(STEPPER_YELLOW_COIL , DIO_u8LOW);
		Dio_vidSetPinval(STEPPER_PINK_COIL   , DIO_u8LOW);
		Dio_vidSetPinval(STEPPER_BLUE_COIL   , DIO_u8HIGH);
		_delay_us(1300);

		Dio_vidSetPinval(STEPPER_ORANGE_COIL , DIO_u8LOW);
		Dio_vidSetPinval(STEPPER_YELLOW_COIL , DIO_u8LOW);
		Dio_vidSetPinval(STEPPER_PINK_COIL   , DIO_u8HIGH);
		Dio_vidSetPinval(STEPPER_BLUE_COIL   , DIO_u8LOW);
		_delay_us(1300);

		Dio_vidSetPinval(STEPPER_ORANGE_COIL , DIO_u8LOW);
		Dio_vidSetPinval(STEPPER_YELLOW_COIL , DIO_u8HIGH);
		Dio_vidSetPinval(STEPPER_PINK_COIL   , DIO_u8LOW);
		Dio_vidSetPinval(STEPPER_BLUE_COIL   , DIO_u8LOW);
		_delay_us(1300);

		Dio_vidSetPinval(STEPPER_ORANGE_COIL , DIO_u8HIGH);
		Dio_vidSetPinval(STEPPER_YELLOW_COIL , DIO_u8LOW);
		Dio_vidSetPinval(STEPPER_PINK_COIL   , DIO_u8LOW);
		Dio_vidSetPinval(STEPPER_BLUE_COIL   , DIO_u8LOW);
		_delay_us(1300);

	}

}



