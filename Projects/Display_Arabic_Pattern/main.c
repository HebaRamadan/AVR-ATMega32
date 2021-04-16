/*
 * main.c
 *
 *  Created on: Dec 1, 2020
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

	 u8 H[8]={ 0b11111, 0b00001, 0b11101, 0b10101, 0b11111, 0b00000, 0b00000, 0b00000};
	 u8 b[8]={ 0b00000, 0b00000, 0b01000, 0b01000, 0b11111, 0b00000, 0b01000, 0b00000};
	 u8 h[8]={ 0b00000, 0b11100, 0b10100, 0b11100, 0b00111, 0b00000, 0b00000, 0b00000};

	 LCD_vidSavePattern(H , 0);
	 LCD_vidSavePattern(b , 1);
	 LCD_vidSavePattern(h , 2);

	 u8 i = 0;
	 while(1)
	 {

			if(i==15)
			{
				i=0;
			}
			 LCD_vidSendCommand(0x8F-i);
			 LCD_vidSendData(0);
			 i++;

			 LCD_vidSendCommand(0x8F-i);;
			 LCD_vidSendData(1);
			 i++;

			 LCD_vidSendCommand(0x8F-i);
			 LCD_vidSendData(2);
			 i++;


			_delay_ms(500);
			LCD_vidSendCommand(0x01);


			 LCD_vidSendCommand(0xcf-i);
			 LCD_vidSendData(0);
			 i++;

			 LCD_vidSendCommand(0xcf-i);;
			 LCD_vidSendData(1);
			 i++;

			 LCD_vidSendCommand(0xcf-i);
			 LCD_vidSendData(2);


			_delay_ms(500);
			LCD_vidSendCommand(0x01);
	 }
	return 0;
}


