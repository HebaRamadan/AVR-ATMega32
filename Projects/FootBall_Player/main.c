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

	 u8 A[8]=  { 0b01100, 0b01100, 0b00000, 0b01110, 0b11100, 0b01100, 0b11010, 0b10011};
	 u8 B[8]=  { 0b01100, 0b01100, 0b00000, 0b01110, 0b11100, 0b01100, 0b11010, 0b10010};

	 u8 O_u[8]={ 0b00000, 0b00000, 0b00000, 0b00000, 0b00110, 0b00110, 0b00000, 0b00000};
	 u8 O_d[8]={ 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00110, 0b00110, 0b00000};

	 u8 C[8]=  {0b00111,0b01111,0b10111,0b00111,0b00111,0b00111, 0b01110,0b11100};

	 LCD_vidSavePattern(A   , 0);
	 LCD_vidSavePattern(B   , 1);
	 LCD_vidSavePattern(O_u , 2);
	 LCD_vidSavePattern(O_d , 3);

	 LCD_vidSavePattern(C , 4);




	 u8 i = 0;
	 while(1)
	 {
		 if(i >= 13)
		 {
			 LCD_vidSendString("   GooooaL   ");
			 _delay_ms(2000);
			 LCD_vidSendCommand(0x01);
			 i = 0;
		 }
		 LCD_vidSendCommand(0x8F);
		 LCD_vidSendData(4);
		 LCD_vidSendCommand(0x80 + i);
		 LCD_vidSendData(0);
		 LCD_vidSendData(2);
		 i++;
		 _delay_ms(500);
		 LCD_vidSendCommand(0x01);

		 LCD_vidSendCommand(0x8F);
		 LCD_vidSendData(4);
		 LCD_vidSendCommand(0x80 + i);
		 LCD_vidSendData(1);
		 LCD_vidSendData(3);
		 i++;
		 _delay_ms(500);
		 LCD_vidSendCommand(0x01);



	 }
	return 0;
}


