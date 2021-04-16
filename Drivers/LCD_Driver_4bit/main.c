/*
 * main.c
 *
 *  Created on: Feb 7, 2020
 *      Author: zas
 */
#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>
#include "Lcd_int.h"
#include "Dio_int.h"

int main(void)
{
	u8 arr[] = "heba";
	u8 i =0;
	Lcd_vidInit();
	Lcd_vidSendCommand(0x01);
	Lcd_vidSendCommand(0x0C);


	while(1)
	{
		Lcd_vidSendCommand(0x80+i);
		Lcd_vidWriteStr(arr);
		_delay_ms(300);
		Lcd_vidSendCommand(0x01);
		_delay_ms(2);
		i++;
		if(i==17)
		{
			i=0;
		}

	}
	return 0;
}

