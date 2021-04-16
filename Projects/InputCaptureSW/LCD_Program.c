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
#include "LCD_Private.h"
#include "LCD_Interface.h"


#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>


void LCD_vidInit(void)
{
#if LCD_MODE == LCD_8BITMODE
	DIO_vidSetPortDirection(Data_Port    , 0XFF);
	DIO_vidSetPinDirection (Control_Port , RS , 1);  //RS
	DIO_vidSetPinDirection (Control_Port , RW , 1);  //RW
	DIO_vidSetPinDirection (Control_Port , EN , 1);	//EN
	_delay_ms(40);

	LCD_vidSendCommand( FUNCTION_SET   );
	_delay_ms(1);

	LCD_vidSendCommand( DISPLAY_ON_LCD );
	_delay_ms(1);

	LCD_vidSendCommand( CLEAR_DISPLAY  );
	_delay_ms(1);

#elif LCD_MODE == LCD_4BITMODE
	DIO_vidSetPinDirection(Data_Port , PIN_0 , DIO_u8OUTPUT);
	DIO_vidSetPinDirection(Data_Port , PIN_1 , DIO_u8OUTPUT);
	DIO_vidSetPinDirection(Data_Port , PIN_2 , DIO_u8OUTPUT);
	DIO_vidSetPinDirection(Data_Port , PIN_3 , DIO_u8OUTPUT);

	DIO_vidSetPinDirection(Control_Port , RS , DIO_u8OUTPUT);  //RS
	DIO_vidSetPinDirection(Control_Port , RW , DIO_u8OUTPUT);  //RW
	DIO_vidSetPinDirection(Control_Port , EN , DIO_u8OUTPUT);	//E

	_delay_ms(40);

	LCD_vidSendCommand( 0b00100000 );
	LCD_vidSendCommand( 0b00100000 );
	//LCD_vidSendCommand( LCD_u8CMD_4_BIT_2x16_5x7 );  // 2Lines && 5x7

	_delay_ms(1);

	LCD_vidSendCommand( 0b00000000 );
	LCD_vidSendCommand( 0b11000000 );   //Display_ON && Cursor_OFF && NO_Blink

	_delay_ms(1);

	LCD_vidSendCommand( 0b00000000 );
	//LCD_vidSendCommand( LCD_u8CMD_CLR_Display );   //Clear Display

	_delay_ms(1);
#endif

}

void LCD_vidSendCommand(u8 Cmd)
{
#if LCD_MODE == LCD_8BITMODE
	DIO_vidSetPinValue(Control_Port , RS , 0);
	DIO_vidSetPinValue(Control_Port , RW , 0);

	DIO_vidSetPortValue(Data_Port , Cmd);

	DIO_vidSetPinValue(Control_Port , EN , 1);

	_delay_ms(5);

	DIO_vidSetPinValue(Control_Port , EN , 0);

#elif LCD_MODE == LCD_4BITMODE
	DIO_vidSetPinValue(Control_Port , RS , 0);   //make RS->0 to indicate LCD "you will receive command not data"
	DIO_vidSetPinValue(Control_Port , RW , 0);	 //make RW->0 to indicate LCD "you will write in command Register"


	//In 4_bit Mode Send Upper Data first
	DIO_vidSetPinValue(Data_Port , PIN_0 , GET_BIT(Cmd , 4));
	DIO_vidSetPinValue(Data_Port , PIN_1 , GET_BIT(Cmd , 5));
	DIO_vidSetPinValue(Data_Port , PIN_2 , GET_BIT(Cmd , 6));
	DIO_vidSetPinValue(Data_Port , PIN_3 , GET_BIT(Cmd , 7));


	DIO_vidSetPinValue(Control_Port , EN , 1);  //Disable Receiving data from port
	_delay_ms(5);
	DIO_vidSetPinValue(Control_Port , EN , 0);	//Receive  data and save in buffer


	//Send Lower data
	DIO_vidSetPinValue(Data_Port , PIN_0 , GET_BIT(Cmd , 0));
	DIO_vidSetPinValue(Data_Port , PIN_1 , GET_BIT(Cmd , 1));
	DIO_vidSetPinValue(Data_Port , PIN_2 , GET_BIT(Cmd , 2));
	DIO_vidSetPinValue(Data_Port , PIN_3 , GET_BIT(Cmd , 3));


	DIO_vidSetPinValue(Control_Port , EN , 1);  //Disable Receiving data from port
	_delay_ms(5);
	DIO_vidSetPinValue(Control_Port , EN , 0);	//Receive  data and save in buffer
#endif
}

void LCD_vidSendData(u8 Char)
{
#if LCD_MODE == LCD_8BITMODE
	DIO_vidSetPinValue(Control_Port , RS , 1);
	DIO_vidSetPinValue(Control_Port , RW , 0);

	DIO_vidSetPortValue(Data_Port , Char);

	DIO_vidSetPinValue(Control_Port , EN , 1);

	_delay_ms(5);

	DIO_vidSetPinValue(Control_Port , EN , 0);

#elif LCD_MODE == LCD_4BITMODE
	DIO_vidSetPinValue(Control_Port , RS , 1);   //make RS->1 to indicate LCD "you will receive data
	DIO_vidSetPinValue(Control_Port , RW , 0);	 //make RW->0 to indicate LCD "you will write in command Register"


	//In 4_bit Mode Send Upper Data first
	DIO_vidSetPinValue(Data_Port , PIN_0 , GET_BIT(Char , 4));
	DIO_vidSetPinValue(Data_Port , PIN_1 , GET_BIT(Char , 5));
	DIO_vidSetPinValue(Data_Port , PIN_2 , GET_BIT(Char , 6));
	DIO_vidSetPinValue(Data_Port , PIN_3 , GET_BIT(Char , 7));


	DIO_vidSetPinValue(Control_Port , EN , 1);  //Disable Receiving data from port
	_delay_ms(5);
	DIO_vidSetPinValue(Control_Port , EN , 0);	//Receive  data and save in buffer


	//Send Lower data
	DIO_vidSetPinValue(Data_Port , PIN_0 , GET_BIT(Char , 0));
	DIO_vidSetPinValue(Data_Port , PIN_1 , GET_BIT(Char , 1));
	DIO_vidSetPinValue(Data_Port , PIN_2 , GET_BIT(Char , 2));
	DIO_vidSetPinValue(Data_Port , PIN_3 , GET_BIT(Char , 3));

	DIO_vidSetPinValue(Control_Port , EN , 1);  //Disable Receiving data from port
	_delay_ms(5);
	DIO_vidSetPinValue(Control_Port , EN , 0);	//Receive  data and save in buffer
#endif

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

	//LCD_vidSendCommand(LCD_u8CMD_RETURN_AC);    //Move AC to DDRAM
}

void LCDC_vidClearScreen(void)
{
	//LCD_vidSendCommand( LCD_u8CMD_CLR_Display  );
	_delay_ms(1);
}

void Lcd_vidSetPosition(u8 Row , u8 Col)
{
	if(Row == 0)
	{
		LCD_vidSendCommand(128 + Col);
	}
	else if(Row == 1)
	{
		LCD_vidSendCommand(128 + 64 + Col);
	}
}



