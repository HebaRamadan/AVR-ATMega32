/*
 * Internal_EPROM_prg.c
 *
 *  Created on: Aug 7, 2020
 *      Author: zas
 */
#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#include "Internal_EPROM_priv.h"
#include "Internal_EEPROM_int.h"


void Eeprom_vidWriteByte( u16 Address , u8 Data)
{
	/*Writing sequence
	 * 1- Wait  for complete previous writing operation.
	 * 2- Wait until SPMEN in SPMCR becomes zero .
	 * 3- Write new EEPROM address to EEAR.
	 * 4- Write new EEPROM data to EEDR.
	 * 5- Block interrupt in this section.
	 * 6- Write a logical one to the EEMWE bit while writing a zero to EEWE in EECR.
	 * 7- Within four clock cycles after setting EEMWE, write a logical one to EEWE.
	 * 8- return for previous State.
	 * */

	u8 sreg;


	/* Wait  for complete previous writing operation */
	while(GET_BIT(EECR , EEWE ) == 1);

	/* We can't program EEPROM while writing in flash memory (Related in BootLoader Case)*/
	while(GET_BIT(SPMCR , SPMEN) == 1);

	/* Write new EEPROM address to EEAR */
	EEARL =  Address ;
	EEARH = (Address >> 8);

	/* Write new EEPROM data to EEDR */
	EEDR = Data;

	/* Block interrupt in this section */
	sreg = SREG;
	CLR_BIT(SREG , I_Bit);

	/* Write a logical one to the EEMWE */
	//SET_BIT( EECR , EEMWE );
	//EECR = (1 << EEMWE);
	asm("SBI 0x1C,2");

	/* Enable writing */
	//SET_BIT( EECR , EEWE );
	//EECR = (1 << EEWE) | (1 << EEMWE);
	asm("SBI 0x1C,1");

	/* return for previous State */
	SREG =sreg;

}

u8   Eeprom_u8ReadByte( u16 Address )
{
	/* Reading Sequence
	 * 1- Wait  for complete previous writing operation.
	 * 2- Wait until SPMEN in SPMCR becomes zero .
	 * 3- Write new EEPROM address to EEAR.
	 * 4- Enable Reading.
	 * 5- Return Data in EEDR.
	 * */

	/* Wait  for complete previous writing operation */
	while(GET_BIT(EECR , EEWE ) == 1);

	/* We can't program EEPROM while writing in flash memory (Related in BootLoader Case)*/
	while(GET_BIT(SPMCR , SPMEN) == 1);

	/* Write new EEPROM address to EEAR */
	EEARL =  Address ;
	EEARH = (Address >> 8);

	/* Enable Reading */
	SET_BIT( EECR , EERE );

	/* Return Data */
	return EEDR;

}

/* Update Function to reduce writing operations in EEPROM */
void Eeprom_vidUpdateByte( u16 Address , u8 Data)
{
	/* Update data sequence
	 * 1- Read Data from location of this address.
	 * 2- Compare data read with input data.
	 * 3- If same, do nothing.
	 * 4- If not same, write new data in location of input address.
	 * */
	u8 CheckData;

	CheckData = Eeprom_u8ReadByte(Address);

	if(CheckData != Data)
	{
		Eeprom_vidWriteByte( Address , Data );
	}
}
