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
	while(1)
	{
		for(u8 i=0; i<16; i++)
		{

			LCD_vidSendCommand(0x80+i);
			LCD_vidSendString("Heba");

			if(i == 13 )
			{
				LCD_vidSendCommand(0x80);
				LCD_vidSendData('a');
			}
			if(i == 14 )
			{
				LCD_vidSendCommand(0x80);
				LCD_vidSendString("ba");
			}
			if(i == 15 )
			{
				LCD_vidSendCommand(0x80);
				LCD_vidSendString("eba");
			}

			_delay_ms(400);
			LCD_vidSendCommand(0x01);
			_delay_ms(50);

		}

	}

	return 0;
}

