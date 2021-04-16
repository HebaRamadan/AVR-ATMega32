/*
 * main.c
 *
 *  Created on: Aug 7, 2020
 *      Author: zas
 */
#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>
#include "Internal_EEPROM_int.h"
#include "Lcd_int.h"



int main(void)
{
	u8 Data;

	Lcd_vidInit();

	Eeprom_vidWriteByte( 0 ,  'B');
	_delay_ms(30);

	Eeprom_vidWriteByte( 1 ,  'E');
	_delay_ms(30);

	Eeprom_vidWriteByte( 2 ,  'B');
	_delay_ms(30);

	Eeprom_vidWriteByte( 3 ,  'A');
	_delay_ms(30);

	Eeprom_vidUpdateByte( 3 ,  'S');
	_delay_ms(30);


	Data = Eeprom_u8ReadByte( 0 );
	_delay_ms(30);
	Lcd_vidWriteChar(Data);

	Data = Eeprom_u8ReadByte( 1 );
	_delay_ms(30);
	Lcd_vidWriteChar(Data);

	Data = Eeprom_u8ReadByte( 2 );
	_delay_ms(30);
	Lcd_vidWriteChar(Data);

	Data = Eeprom_u8ReadByte( 3 );
	_delay_ms(30);
	Lcd_vidWriteChar(Data);

	while(1);

	return 0;
}


