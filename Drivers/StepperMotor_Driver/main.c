/*
 * main.c
 *
 *  Created on: Feb 17, 2020
 *      Author: zas
 */
#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>
#include "Stepper_int.h"


int main(void)
{
	Stepper_vidInit();
	while(1)
	{
		Stepper_vidTurnRight(360);
		_delay_ms(300);
		Stepper_vidTurnLeft(360);
		_delay_ms(300);
	}
	return 0;

}

