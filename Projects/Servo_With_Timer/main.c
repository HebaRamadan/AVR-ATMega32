/*
 * main.c
 *
 *  Created on: Feb 29, 2020
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
	u8 i;
	Servo_vidInit();

	while(1)
	{

		for(u8 i=0; i<=180; i++)
		{
			Servo_vidSetDegree(i);
			_delay_ms(100);
		}

	}

	return 0;


}

