/*
 * main.c
 *
 *  Created on: Feb 6, 2020
 *      Author: zas
 */
#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>

#include "Led_int.h"

int main(void)
{
	Led_vidInit(LED_1);

	while(1)
	{
		Led_vidTurnOn(LED_1);
		_delay_ms(1000);

		Led_vidTurnOff(LED_1);
		_delay_ms(1000);

	}
	return 0;
}

