/*
 * main.c
 *
 *  Created on: Mar 1, 2020
 *      Author: zas
 */

#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>
#include "Servo_int.h"

int main(void)
{
	Servo_vidInit();
	f32 i;
	while(1)
	{
		Servo_vidSetDegree(180);
	}

}
