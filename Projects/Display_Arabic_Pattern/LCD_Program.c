/*
 * LCD_Program.c
 *
 *  Created on: Nov 30, 2020
 *      Author: Heba Ramadan
 */

#include "Std_types.h"
#include "Bit_math.h"
#include "DIO_Interface.h"
#include "LCD_Config.h"

#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>


void LCD_vidSendCommand(u8 Cmd)
{

	DIO_vidSetPinValue(Control_Port , RS , 0);
	DIO_vidSetPinValue(Control_Port , RW , 0);

	DIO_vidSetPortValue(Data_Port , Cmd);

	DIO_vidSetPinValue(Control_Port , EN , 1);

	_delay_ms(5);

	DIO_vidSetPinValue(Control_Port , EN , 0);

}


void LCD_vidSendData(u8 Char)
{
	DIO_vidSetPinValue(Control_Port , RS , 1);
	DIO_vidSetPinValue(Control_Port , RW , 0);

	DIO_vidSetPortValue(Data_Port , Char);

	DIO_vidSetPinValue(Control_Port , EN , 1);

	_delay_ms(5);

	DIO_vidSetPinValue(Control_Port , EN , 0);

}


void LCD_vidInit(void)
{
	DIO_vidSetPortDirection(Data_Port , 0xff);
	DIO_vidSetPinDirection (Control_Port , RS , 1);  //RS
	DIO_vidSetPinDirection (Control_Port , RW , 1);  //RW
	DIO_vidSetPinDirection (Control_Port , EN , 1);	 //E

	_delay_ms(40);
	LCD_vidSendCommand( 0b00111000 );

	_delay_ms(1);
	LCD_vidSendCommand( 0X0C );

	_delay_ms(1);
	LCD_vidSendCommand( 0b00000001 );
	_delay_ms(1);
}

void LCD_vidSendString(u8 * Str)
{
	u8 i =0;
	while(Str[i] !=  '\0' )
	{
		LCD_vidSendData(Str[i]);
		i++;
	}
}

void LCD_vidWriteNumber(u16 Number)
{
	u16 Rev = 1;
	do
	{
		Rev    = (Rev * 10) + (Number % 10);
		Number =  Number / 10;

	}while(Number != 0);


	while( (Rev / 10) != 0)
	{
		LCD_vidSendData((Rev % 10) + '0');
		Rev = Rev / 10 ;
	}

}


void LCD_vidSavePattern(u8 *Pattern , u8 Pattern_Adress)
{
	u8 CGRAM_Adress;

	if(Pattern_Adress < 8)
	{
		CGRAM_Adress = Pattern_Adress * 8;

		SET_BIT(CGRAM_Adress , 6);          //Move AC To CGRAM
		LCD_vidSendCommand(CGRAM_Adress);

		for(u8 i=0; i<8; i++)
		{
			LCD_vidSendData(Pattern[i]);
		}
	}

	LCD_vidSendCommand(0x02);    //Move AC to DDRAM
}



