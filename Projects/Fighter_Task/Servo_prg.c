/*
 * Servo_prg.c
 *
 *  Created on: Mar 1, 2020
 *      Author: zas
 */
#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#include <avr/io.h>
#include "Dio_int.h"
#include "Servo_cfg.h"
#include "Servo_int.h"

void Servo_vidInit(void)
{
	Dio_vidSetPinDir(TIMER_1_PIN, DIO_u8OUTPUT);

	SET_BIT(TCCR1A , 7);
	CLR_BIT(TCCR1A , 6);
	SET_BIT(TCCR1A , 1);
	CLR_BIT(TCCR1A , 0);

	SET_BIT(TCCR1B , 4);
	SET_BIT(TCCR1B , 3);

	CLR_BIT(TCCR1B , 2);
	SET_BIT(TCCR1B , 1);
	CLR_BIT(TCCR1B , 0);
	ICR1  = 20000;
}

void Servo_vidSetDegree(u8 degree)
{
	f32 time_of_degree;
	u16 val_of_register;

	time_of_degree = ((degree * TIME_OF_FULL_DEGREE)/FULL_DEGREE)+INITIAL_TIME;
	val_of_register = time_of_degree *1000 ;
	OCR1A  = val_of_register;
}


