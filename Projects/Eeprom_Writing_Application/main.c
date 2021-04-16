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
	u8 var;

	u8 str[] = "Writing App";
	u8 arr[] = "Done";

	Lcd_vidWriteStr(str);
	_delay_ms(500);

   Eeprom_u8ClearDevice( Device_0 , 300);

	Lcd_vidSendCommand(0xc0);
	Lcd_vidWriteStr(arr);


	while(1);

	return 0;
}

