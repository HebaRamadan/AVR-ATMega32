/*
 * main.c
 *
 *  Created on: Apr 1, 2020
 *      Author: zas
 */
#include "../Lib/Std_types.h"
#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>
#include "Dio_int.h"
#include "Timer0_int.h"


int main(void)
{
	u8 i;
	Dio_vidSetPinDir(DIO_u8PIN_11 , DIO_u8OUTPUT);
	Timer0_vidInit();

	while(1)
	{
	    for(i=0; i<255; i++)
	    {
	    	Timer0_vidSetCompareRegisterValue(i);    //compare register
	    	_delay_ms(5);

	    }

	    for(i=255; i>0; i--)
	    {
	    	Timer0_vidSetCompareRegisterValue(i);
	    	_delay_ms(5);

	    }
	}
	return 0;
}

