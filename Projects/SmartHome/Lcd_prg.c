/*
 * Lcd_prg.c
 *
 *  Created on: Nov 30, 2020
 *      Author: Heba Ramadan
 */

#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>
#include "Lcd_cfg.h"
#include "Lcd_int.h"
#include "Dio_int.h"


void Lcd_vidSendCommand(u8 Cmd)
{
	//Start to change in LCD control Reg to indicate it that you will receive command
	Dio_vidSetPinval(LCD_u8RS_PIN , DIO_u8LOW);  //make RS->0 to indicate LCD "you will receive command not data"
	Dio_vidSetPinval(LCD_u8RW_PIN , DIO_u8LOW);  //make RW->0 to indicate LCD "you will write in command Register"
	Dio_vidSetPinval(LCD_u8EN_PIN , DIO_u8HIGH); //make EN->1 to indicate LCD "Please LCD don't save any thing in your buffer until be sure all data sent "

	//In prof_code we can't send all data '8_bit'  for PORT at the same time so we use GET_BIT
	Dio_vidSetPinval(LCD_u8D0_PIN , GET_BIT(Cmd,0));
	Dio_vidSetPinval(LCD_u8D1_PIN , GET_BIT(Cmd,1));
	Dio_vidSetPinval(LCD_u8D2_PIN , GET_BIT(Cmd,2));
	Dio_vidSetPinval(LCD_u8D3_PIN , GET_BIT(Cmd,3));
	Dio_vidSetPinval(LCD_u8D4_PIN , GET_BIT(Cmd,4));
	Dio_vidSetPinval(LCD_u8D5_PIN , GET_BIT(Cmd,5));
	Dio_vidSetPinval(LCD_u8D6_PIN , GET_BIT(Cmd,6));
	Dio_vidSetPinval(LCD_u8D7_PIN , GET_BIT(Cmd,7));

	_delay_ms(2);

	Dio_vidSetPinval(LCD_u8EN_PIN , DIO_u8LOW);  //make EN->0 to indicate LCD "NOW you can save bits in your buffer all data sent"

}

void Lcd_vidInit(void)
{
	 Dio_vidSetPinDir(LCD_u8RS_PIN , DIO_u8OUTPUT);
	 Dio_vidSetPinDir(LCD_u8RW_PIN , DIO_u8OUTPUT);
	 Dio_vidSetPinDir(LCD_u8EN_PIN , DIO_u8OUTPUT);

	 Dio_vidSetPinDir(LCD_u8D0_PIN , DIO_u8OUTPUT);
	 Dio_vidSetPinDir(LCD_u8D1_PIN , DIO_u8OUTPUT);
	 Dio_vidSetPinDir(LCD_u8D2_PIN , DIO_u8OUTPUT);
	 Dio_vidSetPinDir(LCD_u8D3_PIN , DIO_u8OUTPUT);
	 Dio_vidSetPinDir(LCD_u8D4_PIN , DIO_u8OUTPUT);
	 Dio_vidSetPinDir(LCD_u8D5_PIN , DIO_u8OUTPUT);
	 Dio_vidSetPinDir(LCD_u8D6_PIN , DIO_u8OUTPUT);
	 Dio_vidSetPinDir(LCD_u8D7_PIN , DIO_u8OUTPUT);

	Lcd_vidSendCommand(LCD_u8CMD_8_BIT_2x16_5x7); //LCD_8BIT_2x16_5x7
	_delay_ms(2);
	Lcd_vidSendCommand(LCD_u8CMD_DISP_ON_CURS_ON);
	_delay_ms(2);
	Lcd_vidSendCommand(LCD_u8CMD_CLR_Display);
	_delay_ms(2);

}

void Lcd_vidWriteChar(u8 Char)

{
	Dio_vidSetPinval(LCD_u8RS_PIN , DIO_u8HIGH);  //RS
	Dio_vidSetPinval(LCD_u8RW_PIN , DIO_u8LOW);  //RW
	Dio_vidSetPinval(LCD_u8EN_PIN , DIO_u8HIGH);  //EN

	Dio_vidSetPinval(LCD_u8D0_PIN , GET_BIT(Char,0));
	Dio_vidSetPinval(LCD_u8D1_PIN , GET_BIT(Char,1));
	Dio_vidSetPinval(LCD_u8D2_PIN , GET_BIT(Char,2));
	Dio_vidSetPinval(LCD_u8D3_PIN , GET_BIT(Char,3));
	Dio_vidSetPinval(LCD_u8D4_PIN , GET_BIT(Char,4));
	Dio_vidSetPinval(LCD_u8D5_PIN , GET_BIT(Char,5));
	Dio_vidSetPinval(LCD_u8D6_PIN , GET_BIT(Char,6));
	Dio_vidSetPinval(LCD_u8D7_PIN , GET_BIT(Char,7));

	_delay_ms(2);

	Dio_vidSetPinval(LCD_u8EN_PIN , DIO_u8LOW);  //EN
}

void Lcd_vidSendString(u8 * Str)
{
	u8 i =0;
	while(Str[i] !=  '\0' )
	{
		Lcd_vidWriteChar(Str[i]);
		i++;
	}
}



void Lcd_vidWriteNumber(u32 Number)
{
	u32 Rev = 1;
	do
	{
		Rev    = (Rev * 10) + (Number % 10);
		Number =  Number / 10;

	}while(Number != 0);


	while( (Rev / 10) != 0)
	{
		Lcd_vidWriteChar((Rev % 10) + '0');
		Rev = Rev / 10 ;
	}

}


void Lcd_vidStorePattern(u8 *pattern , u8 pattern_num)
{
	u8 i;
	u8 CGRAM_Adress;

	if(pattern_num < 8)
	{
		CGRAM_Adress = pattern_num *8;
		SET_BIT(CGRAM_Adress , 6);
		Lcd_vidSendCommand(CGRAM_Adress);
		for(i=0; i<8; i++){
			Lcd_vidWriteChar(pattern[i]);
		}
	}
	Lcd_vidSendCommand(0x02);
}
