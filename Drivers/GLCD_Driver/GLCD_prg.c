/*
 * GLCD_prg.c

 *
 *  Created on: May 10, 2020
 *      Author: zas
 */
#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#include "../Lib/Glcd_font.h"
#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>
#include "Dio_int.h"
#include "GLCD_cfg.h"
#include "GLCD_int.h"

void GLCD_vidSendCommand(u8 Cmd)
{
	Dio_vidSetPinVal(GLCD_u8RS_PIN , DIO_u8LOW);   // Make RS LOW for command register
	Dio_vidSetPinVal(GLCD_u8RW_PIN , DIO_u8LOW);   // Make RW LOW for write operation
	Dio_vidSetPinVal(GLCD_u8EN_PIN , DIO_u8HIGH);  // Make EN HIGH for stop receiving data

	Dio_vidSetPinVal(GLCD_u8D0_PIN , GET_BIT(Cmd , 0));
	Dio_vidSetPinVal(GLCD_u8D1_PIN , GET_BIT(Cmd , 1));
	Dio_vidSetPinVal(GLCD_u8D2_PIN , GET_BIT(Cmd , 2));
	Dio_vidSetPinVal(GLCD_u8D3_PIN , GET_BIT(Cmd , 3));
	Dio_vidSetPinVal(GLCD_u8D4_PIN , GET_BIT(Cmd , 4));
	Dio_vidSetPinVal(GLCD_u8D5_PIN , GET_BIT(Cmd , 5));
	Dio_vidSetPinVal(GLCD_u8D6_PIN , GET_BIT(Cmd , 6));
	Dio_vidSetPinVal(GLCD_u8D7_PIN , GET_BIT(Cmd , 7));

	_delay_ms(2);
	Dio_vidSetPinVal(GLCD_u8EN_PIN , DIO_u8LOW);  // Make EN HIGH for start receiving data

}


void GLCD_vidInit(void)
{
	Dio_vidSetPinDir(GLCD_u8RS_PIN  , DIO_u8OUTPUT);
	Dio_vidSetPinDir(GLCD_u8RW_PIN  , DIO_u8OUTPUT);
	Dio_vidSetPinDir(GLCD_u8EN_PIN  , DIO_u8OUTPUT);
	Dio_vidSetPinDir(GLCD_u8CS1_PIN , DIO_u8OUTPUT);
	Dio_vidSetPinDir(GLCD_u8CS2_PIN , DIO_u8OUTPUT);
	Dio_vidSetPinDir(GLCD_u8RST_PIN , DIO_u8OUTPUT);

	Dio_vidSetPinDir(GLCD_u8D0_PIN , DIO_u8OUTPUT);
	Dio_vidSetPinDir(GLCD_u8D1_PIN , DIO_u8OUTPUT);
	Dio_vidSetPinDir(GLCD_u8D2_PIN , DIO_u8OUTPUT);
	Dio_vidSetPinDir(GLCD_u8D3_PIN , DIO_u8OUTPUT);
	Dio_vidSetPinDir(GLCD_u8D4_PIN , DIO_u8OUTPUT);
	Dio_vidSetPinDir(GLCD_u8D5_PIN , DIO_u8OUTPUT);
	Dio_vidSetPinDir(GLCD_u8D6_PIN , DIO_u8OUTPUT);
	Dio_vidSetPinDir(GLCD_u8D7_PIN , DIO_u8OUTPUT);

	// Select both left & right half of display & Keep reset pin high
	Dio_vidSetPinVal(GLCD_u8CS1_PIN , DIO_u8HIGH);
	Dio_vidSetPinVal(GLCD_u8CS2_PIN , DIO_u8HIGH);
	Dio_vidSetPinVal(GLCD_u8RST_PIN , DIO_u8HIGH);
	_delay_ms(2);
	GLCD_vidSendCommand(GLCD_u8CMD_DISP_OFF);    // Display OFF
	_delay_ms(2);
	GLCD_vidSendCommand(0x40);                   // Set Y address (column=0)
	_delay_ms(2);
	GLCD_vidSendCommand(0xB8);                   // Set x address (Line=0)
	_delay_ms(2);
	GLCD_vidSendCommand(0xC0);                   // Set z address (start line=0)
	_delay_ms(2);
	GLCD_vidSendCommand(GLCD_u8CMD_DISP_ON);     // Display ON
}


void GLCD_vidSendData(u8 Data)
{
	Dio_vidSetPinVal(GLCD_u8RS_PIN , DIO_u8HIGH);  // Make RS LOW for Data register
	Dio_vidSetPinVal(GLCD_u8RW_PIN , DIO_u8LOW);   // Make RW LOW for write operation
	Dio_vidSetPinVal(GLCD_u8EN_PIN , DIO_u8HIGH);  // Make EN HIGH for stop receiving data

	Dio_vidSetPinVal(GLCD_u8D0_PIN , GET_BIT(Data , 0));
	Dio_vidSetPinVal(GLCD_u8D1_PIN , GET_BIT(Data , 1));
	Dio_vidSetPinVal(GLCD_u8D2_PIN , GET_BIT(Data , 2));
	Dio_vidSetPinVal(GLCD_u8D3_PIN , GET_BIT(Data , 3));
	Dio_vidSetPinVal(GLCD_u8D4_PIN , GET_BIT(Data , 4));
	Dio_vidSetPinVal(GLCD_u8D5_PIN , GET_BIT(Data , 5));
	Dio_vidSetPinVal(GLCD_u8D6_PIN , GET_BIT(Data , 6));
	Dio_vidSetPinVal(GLCD_u8D7_PIN , GET_BIT(Data , 7));

	_delay_ms(2);
	Dio_vidSetPinVal(GLCD_u8EN_PIN , DIO_u8LOW);  // Make EN HIGH for start receiving data
}
void GLCD_vidWriteChar(u8 Char)
{
	u16 i =0;
	u16 Start_font = 0;
	u16 End_font   = 0;
	Start_font = ((Char - 32) * 5) ;
	End_font =  Start_font + 5 ;

	for(i=Start_font; i<End_font; i++)
	{
		GLCD_vidSendData(System5x7[i]);
	}

}

void GLCD_vidWriteString(u8 *Str)
{
	u8 index = 0;
	while(Str[index] != '\0')
	{
		GLCD_vidWriteChar(Str[index]);
		index++;
	}
}


void GLCD_vidSelectChip(u8 Chip)
{
	switch(Chip)
	{
	case 0:
		Dio_vidSetPinVal(GLCD_u8CS1_PIN , DIO_u8HIGH); //Select Left side
		Dio_vidSetPinVal(GLCD_u8CS2_PIN , DIO_u8LOW);
	break;

	case 1:
		Dio_vidSetPinVal(GLCD_u8CS1_PIN , DIO_u8LOW);   //Select Right side
		Dio_vidSetPinVal(GLCD_u8CS2_PIN , DIO_u8HIGH);
	break;

	case 2:
		Dio_vidSetPinVal(GLCD_u8CS1_PIN , DIO_u8HIGH);   //Select Left & Right side
		Dio_vidSetPinVal(GLCD_u8CS2_PIN , DIO_u8HIGH);
	break;


	}
}


void GLCD_vidClearAll(void)
{
	u8 i , j;
	GLCD_vidSelectChip(SELECT_CHIP_0_1);
	for(i=0; i<TOTAL_PAGES; i++)
	{
		GLCD_vidSendCommand((0xB8) + i);          // Increment page
		for(j=0; j<NUM_PIXEL_OF_PAGE; j++)
		{
			GLCD_vidSendCommand((0x40) +j);       // Increment pixel in each page
			GLCD_vidSendData(0);
		}

	}
	_delay_ms(2);

}


void GLCD_vidPrintPicture(const u8 *ptr)
{
	u8 page = 0;
	u8 column = 0;

	for(page=0; page<TOTAL_PAGES; page++)
	{
		GLCD_vidSelectChip(SELECT_CHIP_0);
		GLCD_vidSendCommand((0xB8)+page);
		GLCD_vidSendCommand((0x40));
		for(column=0; column<128; column++)
		{
			if(column==64)
			{
				GLCD_vidSelectChip(SELECT_CHIP_1);
				GLCD_vidSendCommand((0xB8)+page);
				GLCD_vidSendCommand((0x40));

			}
			GLCD_vidSendData(*ptr);
			ptr++;
		}


	}
}
