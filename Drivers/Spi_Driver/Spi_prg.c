/*
 * Spi_prog.c
 *
 *  Created on: Jun 28, 2020
 *      Author: zas
 */
#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#include "Dio_int.h"
#include "Spi_priv.h"
#include "Spi_int.h"

void Spi_vidMasterInit(void)
{
	/*************** Dio Configuration  *****************
	*                   MasTer    |    Slave            *
	*                 -------------------------         *
	*PB4 12 -> SS       O/P              I/P  (Pull-Up) *
	*PB4 13 -> MOSI     O/P              I/P            *
	*PB4 14 -> MISO     I/P              O/P            *
	*PB4 15 -> SCK      O/P              I/P            *
	****************************************************/
	Dio_vidSetPinDir(DIO_u8PIN_12 , DIO_u8OUTPUT);
	Dio_vidSetPinDir(DIO_u8PIN_13 , DIO_u8OUTPUT);
	Dio_vidSetPinDir(DIO_u8PIN_14 , DIO_u8INPUT);
	Dio_vidSetPinDir(DIO_u8PIN_15 , DIO_u8OUTPUT);

	/* Enable SPI */
	SET_BIT(SPCR , 6);

	/* Select MSB first data order */
	SET_BIT(SPCR , 5);

	/* Select Master Mode */
	SET_BIT(SPCR , 4);

	/*Select falling edge as Leading edge (High Level ideal state) */
	SET_BIT(SPCR , 3);     //CPOL

	/*Select Setup First */
	SET_BIT(SPCR , 2);     //CPHA

	/* Select Fosc/64 for SCK */
	SET_BIT(SPCR , 1);
	SET_BIT(SPCR , 0);
	SET_BIT(SPSR , 0);    //SPI2X

}

void Spi_vidSlaveInit(void)
{
	/*************** Dio Configuration  *****************
	*                   MasTer    |    Slave            *
	*                 -------------------------         *
	*PB4 12 -> SS       O/P              I/P  (Pull-Up) *
	*PB4 13 -> MOSI     O/P              I/P            *
	*PB4 14 -> MISO     I/P              O/P            *
	*PB4 15 -> SCK      O/P              I/P            *
	****************************************************/
	Dio_vidSetPinDir(DIO_u8PIN_12 , DIO_u8INPUT);
	Dio_vidSetPinVal(DIO_u8PIN_12 , DIO_u8HIGH);

	Dio_vidSetPinDir(DIO_u8PIN_13 , DIO_u8INPUT);
	Dio_vidSetPinDir(DIO_u8PIN_12 , DIO_u8OUTPUT);
	Dio_vidSetPinDir(DIO_u8PIN_12 , DIO_u8INPUT);

	/* Enable SPI */
	SET_BIT(SPCR , 6);

	/* Select MSB first data order */
	SET_BIT(SPCR , 5);

	/* Select Slave Mode */
	CLR_BIT(SPCR , 4);

	/*Select falling edge as Leading edge (High Level ideal state) */
	SET_BIT(SPCR , 3);     //CPOL

	/*Select Setup First */
	SET_BIT(SPCR , 2);     //CPHA
}


u8   Spi_u8MasterTransfare(u8 Data)
{
	/* Select the Slave  */
	Dio_vidSetPinVal(DIO_u8PIN_12 , DIO_u8LOW);

	/* Loading The Register With Data to be transferred */
	SPDR = Data;

	/* Waiting till transferring complete */
	while((GET_BIT(SPSR , 7)) == 0);

	/* Release The Slave */
	Dio_vidSetPinVal(DIO_u8PIN_12 , DIO_u8HIGH);

	/* Return the received data */
	return SPDR;
}


u8   Spi_u8SlaveTransfare(u8 Data)
{
	/* Loading The Register With Data to be transferred */
	SPDR = Data;

	/* Waiting till transferring complete */
	while((GET_BIT(SPSR , 7)) == 0);

	/* Return the received data */
	return SPDR;

}





