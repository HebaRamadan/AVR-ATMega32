/*
 * main.c
 *
 *  Created on: Dec 21, 2020
 *      Author: zas
 */
#include "Std_types.h"
#include "Bit_math.h"
#include "WDT.Interface.h"
#include "DIO_Interface.h"

#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>

int main(void)
{
	DIO_vidSetPinDirection(PortA ,PIN_0 , 1);
	WDT_vidEnable();

	DIO_vidSetPinValue(PortA ,PIN_0 , 1);
	_delay_ms( 500 );
	DIO_vidSetPinValue(PortA ,PIN_0 , 0);

	WDT_vidDisable();
	while(1);
	return 0;
}


