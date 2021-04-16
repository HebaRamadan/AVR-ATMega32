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


int main(void)
{
	Spi_vidSlaveInit();
	DIO_vidSetPinDirection(PortA , PIN_0 , OUTPUT);

	while(1)
	{
		u8 Received_Data = Spi_u8SlaveTransfare(SPI_u8DUMMY_DATA);

		if( Received_Data == 'H')
		{
			DIO_vidSetPinValue(PortA , PIN_0 , HIGH);
		}
		else if( Received_Data == 'L')
		{
			DIO_vidSetPinValue(PortA , PIN_0 , LOW);
		}
	}

}

