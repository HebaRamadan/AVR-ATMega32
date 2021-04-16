/*
 * main.c
 *
 *  Created on: Nov 30, 2020
 *      Author: zas
 */
#include "Std_types.h"
#include "Bit_math.h"
#include "LCD_Interface.h"

#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>

int main(void)
{
	LCD_vidInit();
	u8 i = 0;
	while(1)
	{

		if(i==16)
		{
			i=0;
		}
		LCD_vidSendCommand(0x80+i);
		LCD_vidSendString("Heba");
		_delay_ms(500);
		LCD_vidSendCommand(0x01);

		i += 4;

		LCD_vidSendCommand(0xc0+i);
		LCD_vidSendString("Heba");
		_delay_ms(500);
		LCD_vidSendCommand(0x01);

		i += 4;
	}

	return 0;
}

