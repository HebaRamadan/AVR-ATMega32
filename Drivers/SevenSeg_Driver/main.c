/*
 * main.c
 *
 *  Created on: Feb 19, 2020
 *      Author: zas
 */
#include "../lib/Std_types.h"
#include "../Lib/Bit_math.h"
#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>
#include "SevenSeg_int.h"

int main(void)
{
	SevenSeg_vidInit( RIGHT_SEVENSEG);
	SevenSeg_vidInit( LEFT_SEVENSEG);
	SevenSeg_vidTurnOn( RIGHT_SEVENSEG);
	SevenSeg_vidTurnOn( LEFT_SEVENSEG);
	u8 i;

	while(1)
	{
		for(i=0; i<10; i++)
		{
			SevenSeg_vidDisplayNum(RIGHT_SEVENSEG , i);
			SevenSeg_vidDisplayNum(LEFT_SEVENSEG , i);
			_delay_ms(500);
		}

	}

	return 0;
}

