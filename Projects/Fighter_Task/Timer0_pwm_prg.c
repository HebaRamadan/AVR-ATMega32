/*
 * Timer0_pwm_prg.c
 *
 *  Created on: Mar 4, 2020
 *      Author: zas
 */

#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>
#include <avr/io.h>
#include "Dio_int.h"
#include "Timer0_pwm_cfg.h"
#include "Timer0_pwm_int.h"

void Timer_vidInit(void)
{
	Dio_vidSetPinDir(DIO_u8PIN_11 , DIO_u8OUTPUT);
	//Select Mode(fast PWM with compare)
	SET_BIT(TCCR0 , 6);
	SET_BIT(TCCR0 , 3);

	//Compare output mode (CLR at compare SET at max)
	SET_BIT(TCCR0 , 5);
	CLR_BIT(TCCR0 , 4);

	//select CLK Freq
	CLR_BIT(TCCR0 , 2);
	CLR_BIT(TCCR0 , 1);
	SET_BIT(TCCR0 , 0);
}

void Timer_vidIntensity(u8 intensity)
{

	OCR0 = (intensity * (255/100));

}
