/*
 * main.c
 *
 *  Created on: Jul 1, 2020
 *      Author: zas
 */
#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>
#include "Eeprom_int.h"
#include "Lcd_int.h"


int main(void)
{
	Eeprom_vidInit();
	Lcd_vidInit();

	u8 str[] = "Reading App";
	u8 Received_Data;
	Lcd_vidWriteStr(str);
	_delay_ms(500);

	Lcd_vidSendCommand(0xc0);

	Eeprom_u8ReadByte( 0 , 1 , &Received_Data);
	Lcd_vidWriteChar(Received_Data);
	_delay_ms(10);

	Eeprom_u8ReadByte( 0 , 2 , &Received_Data);
	Lcd_vidWriteChar(Received_Data);
	_delay_ms(10);

	Eeprom_u8ReadByte( 0 , 3 , &Received_Data);
	Lcd_vidWriteChar(Received_Data);
	_delay_ms(10);

	Eeprom_u8ReadByte( 0 , 4 , &Received_Data);
	Lcd_vidWriteChar(Received_Data);
	_delay_ms(10);

	Eeprom_u8ReadByte( 0 , 5 , &Received_Data);
	Lcd_vidWriteChar(Received_Data);
	_delay_ms(10);

	Eeprom_u8ReadByte( 0 , 200 , &Received_Data);
	Lcd_vidWriteChar(Received_Data + '0');
	_delay_ms(10);




	while(1);

	return 0;
}

