/*
 * main.c
 *
 *  Created on: Nov 26, 2020
 *      Author: zas
 */
#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#include <avr/io.h>
#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>

int main(void)
{
	DDRA = 0xff;

	while(1)
	{
		for(u8 i=0; i<=7; i++)
		{
			PORTA = 0xff & (~(1<<i));
			_delay_ms(500);
		}
	}

	return 0;
}

