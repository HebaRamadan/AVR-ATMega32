/*
 * main.c
 *
 *  Created on: Dec 23, 2020
 *      Author: zas
 */
#include "Std_types.h"
#include "Bit_math.h"
#include "SPI_Interface.h"
#include "DIO_Interface.h"

#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>

int main(void)
{
	Spi_vidMasterInit();
	Spi_vidSlaveInit();
	DIO_vidSetPinDirection(PortA , PIN_0 , OUTPUT);
	while(1)
	{
		Spi_u8MasterTransfare('H');
		_delay_ms(1000);

		Spi_u8MasterTransfare('L');
		_delay_ms(1000);

	}

}

