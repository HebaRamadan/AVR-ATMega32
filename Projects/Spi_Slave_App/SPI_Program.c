/*
 * SPI_Program.c
 *
 *  Created on: Dec 23, 2020
 *      Author: zas
 */
#include "Std_types.h"
#include "Bit_math.h"
#include "DIO_Interface.h"
#include "SPI_Private.h"

void Spi_vidMasterInit(void)
{

	u8 Temp  = 0;
	DIO_vidSetPinDirection(PortB , PIN_4 , OUTPUT);     //SS
	DIO_vidSetPinDirection(PortB , PIN_5 , OUTPUT);     //MOSI
	DIO_vidSetPinDirection(PortB , PIN_6 , INPUT );     //MISO
	DIO_vidSetPinDirection(PortB , PIN_7 , OUTPUT);     //SCK

	/* Enable SPI */
	SET_BIT(Temp , 6);

	/* Select Master Mode */
	SET_BIT(Temp , 4);

	/* Select LSB first data order */
	SET_BIT(Temp , 5);

	/*Select falling edge as Leading edge (High Level ideal state) */
	SET_BIT(Temp , 3);     //CPOL

	/*Select Setup First */
	SET_BIT(SPCR , 2);     //CPHA

	/* Select Fosc/64 for SCK */
	SET_BIT(Temp , 1);
	CLR_BIT(Temp , 0);
	CLR_BIT(SPSR , 0);    //SPI2X

	SPCR = Temp;
}

void Spi_vidSlaveInit(void)
{

	u8 Temp = 0;

	DIO_vidSetPinDirection(PortB , PIN_4 , INPUT);     //SS
	DIO_vidSetPinValue    (PortB , PIN_4 , HIGH);

	DIO_vidSetPinDirection(PortB , PIN_5 , INPUT);     //MOSI
	DIO_vidSetPinDirection(PortB , PIN_6 , OUTPUT);    //MISO
	DIO_vidSetPinDirection(PortB , PIN_7 , INPUT);     //SCK

	/* Enable SPI */
	SET_BIT(Temp , 6);

	/* Select Slave Mode */
	CLR_BIT(Temp , 4);

	/* Select LSB first data order */
	SET_BIT(Temp , 5);


	/*Select falling edge as Leading edge (High Level ideal state) */
	SET_BIT(Temp , 3);     //CPOL

	/*Select Setup First */
	SET_BIT(Temp , 2);     //CPHA

	SPCR = Temp;

}

u8   Spi_u8MasterTransfare(u8 Data)
{
	/* Select the Slave  */
	DIO_vidSetPinValue(PortB , PIN_4 , LOW);

	/* Loading The Register With Data to be transferred */
	SPDR = Data;

	/* Waiting till transferring complete */
	while((GET_BIT(SPSR , 7)) == 0);

	/* Release The Slave */
	DIO_vidSetPinValue(PortB , PIN_4 , HIGH);

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

