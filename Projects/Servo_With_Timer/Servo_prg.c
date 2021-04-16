/*
 * Servo_prg.c
 *
 *  Created on: Mar 1, 2020
 *      Author: zas
 */
#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#include "Timer1_int.h"
#include "Dio_int.h"
#include "Servo_cfg.h"
#include "Servo_int.h"

void Servo_vidInit(void)
{
	Dio_vidSetPinDir(TIMER_1_PIN, DIO_u8OUTPUT);

	/* Initialize Timer */
	Timer1_vidInit();

	/* Set Value In ICR Register To Make Freq = 20HZ  */
	Timer1_vidSetICR1Val(20000);

}

void Servo_vidSetDegree(u8 degree)
{
	f32 time_of_degree;
	u16 val_of_register;

	/* Convert Degree To TIME And Counts */
	time_of_degree = ((degree * TIME_OF_FULL_DEGREE)/FULL_DEGREE)+INITIAL_TIME;
	val_of_register = (u16)(time_of_degree *1000) ;

	/* Set Compare Register Value */
	Timer1_vidSetOCR1AVal(val_of_register);
}


