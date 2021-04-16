/*
 * Lcd_prg.c
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
#include "Lcd_cfg.h"

void Lcd_vidSendCommand(u8 Cmd)
{
	//Start to change in LCD control Reg to indicate it that you will receive command
	Dio_vidSetPinVal(LCD_u8RS_PIN , DIO_u8LOW);  //make RS->0 to indicate LCD "you will receive command not data"
	Dio_vidSetPinVal(LCD_u8RW_PIN , DIO_u8LOW);  //make RW->0 to indicate LCD "you will write in command Register"
	Dio_vidSetPinVal(LCD_u8EN_PIN , DIO_u8HIGH); //make EN->1 to indicate LCD "Please LCD don't save any thing in your buffer until be sure all data sent "

	//In prof_code we can't send all data '4_bit' uper_bit
	Dio_vidSetPinVal(LCD_u8D4_PIN , GET_BIT(Cmd,4));
	Dio_vidSetPinVal(LCD_u8D5_PIN , GET_BIT(Cmd,5));
	Dio_vidSetPinVal(LCD_u8D6_PIN , GET_BIT(Cmd,6));
	Dio_vidSetPinVal(LCD_u8D7_PIN , GET_BIT(Cmd,7));
	_delay_ms(2);
	Dio_vidSetPinVal(LCD_u8EN_PIN , DIO_u8LOW);  //make EN->0 to indicate LCD "NOW you can save bits in your buffer all data sent"
	_delay_ms(2);

	Dio_vidSetPinVal(LCD_u8EN_PIN , DIO_u8HIGH);

	//In prof_code we can't send all data '4_bit'lower_bit
	Dio_vidSetPinVal(LCD_u8D4_PIN , GET_BIT(Cmd,0));
	Dio_vidSetPinVal(LCD_u8D5_PIN , GET_BIT(Cmd,1));
	Dio_vidSetPinVal(LCD_u8D6_PIN , GET_BIT(Cmd,2));
	Dio_vidSetPinVal(LCD_u8D7_PIN , GET_BIT(Cmd,3));

	_delay_ms(2);
	Dio_vidSetPinVal(LCD_u8EN_PIN , DIO_u8LOW);  //make EN->0 to indicate LCD "NOW you can save bits in your buffer all data sent"
}

void Lcd_vidInit(void)
{
	 Dio_vidSetPinDir(LCD_u8RS_PIN , DIO_u8OUTPUT);
	 Dio_vidSetPinDir(LCD_u8RW_PIN , DIO_u8OUTPUT);
	 Dio_vidSetPinDir(LCD_u8EN_PIN , DIO_u8OUTPUT);

	 Dio_vidSetPinDir(LCD_u8D4_PIN , DIO_u8OUTPUT);
	 Dio_vidSetPinDir(LCD_u8D5_PIN , DIO_u8OUTPUT);
	 Dio_vidSetPinDir(LCD_u8D6_PIN , DIO_u8OUTPUT);
	 Dio_vidSetPinDir(LCD_u8D7_PIN , DIO_u8OUTPUT);

	Lcd_vidSendCommand(LCD_u8CMD_4_BIT_2x16_5x7); //LCD_4BIT_2x16_5x7
	_delay_ms(2);
	Lcd_vidSendCommand(LCD_u8CMD_DISP_ON_CURS_OFF);
	_delay_ms(2);
	Lcd_vidSendCommand(LCD_u8CMD_CLR_Display);
	_delay_ms(2);

}

void Lcd_vidWriteChar(u8 Char)

{
	Dio_vidSetPinVal(LCD_u8RS_PIN , DIO_u8HIGH);  //RS
	Dio_vidSetPinVal(LCD_u8RW_PIN , DIO_u8LOW);  //RW

	//In prof_code we can't send all data '4_bit' uper_bit
	Dio_vidSetPinVal(LCD_u8D4_PIN , GET_BIT(Char,4));
	Dio_vidSetPinVal(LCD_u8D5_PIN , GET_BIT(Char,5));
	Dio_vidSetPinVal(LCD_u8D6_PIN , GET_BIT(Char,6));
	Dio_vidSetPinVal(LCD_u8D7_PIN , GET_BIT(Char,7));

	Dio_vidSetPinVal(LCD_u8EN_PIN , DIO_u8HIGH);  //EN
	_delay_ms(2);
	Dio_vidSetPinVal(LCD_u8EN_PIN , DIO_u8LOW);  //make EN->0 to indicate LCD "NOW you can save bits in your buffer all data sent"




	//In prof_code we can't send all data '4_bit'lower_bit
	Dio_vidSetPinVal(LCD_u8D4_PIN , GET_BIT(Char,0));
	Dio_vidSetPinVal(LCD_u8D5_PIN , GET_BIT(Char,1));
	Dio_vidSetPinVal(LCD_u8D6_PIN , GET_BIT(Char,2));
	Dio_vidSetPinVal(LCD_u8D7_PIN , GET_BIT(Char,3));

	Dio_vidSetPinVal(LCD_u8EN_PIN , DIO_u8HIGH);
	_delay_ms(2);
	Dio_vidSetPinVal(LCD_u8EN_PIN , DIO_u8LOW);  //make EN->0 to indicate LCD "NOW you can save bits in your buffer all data sent"
}

void Lcd_vidWriteStr(u8 *Str){
	u8 index = 0;
	while(Str[index] != '\0')
	{
		Lcd_vidWriteChar(Str[index]);
		index++;
	}
}


