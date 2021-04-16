/*
 * main.c
 *
 *  Created on: Dec 15, 2020
 *      Author: zas
 */
#include "Std_types.h"
#include "Bit_math.h"
#include "Timer0_Init.h"
#include "DIO_Interface.h"



int main(void)
{
	DIO_vidSetPinDirection(PortA , PIN_0 , 1);
	DIO_vidSetPinValue(PortA , PIN_0 , 1);

	/*Initial Timer0*/
	Timer0_vidInit();
	GIE_vidEnable();

	while(1);
	return 0;
}
