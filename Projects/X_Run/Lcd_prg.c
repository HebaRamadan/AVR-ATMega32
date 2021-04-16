/*

 * Lcd_prg.c
 *
 *  Created on: Feb 4, 2020
 *      Author: zas
 */
#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#include <avr/io.h>
#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>
#include "Lcd_int.h"


void Lcd_vidSendCommand(u8 Cmd)
{
	CLR_BIT(PORTA , 0);  //RS
	CLR_BIT(PORTA , 1);  //RW
	PORTD = Cmd;
	SET_BIT(PORTA , 2);  //EN
	_delay_ms(2);
	CLR_BIT(PORTA , 2);  //EN

}

void Lcd_vidInit(void)
{
	DDRA = 0xff;
	DDRD = 0xff;
	Lcd_vidSendCommand(0x38);
	_delay_ms(2);
	Lcd_vidSendCommand(0x0C);
	_delay_ms(2);
	Lcd_vidSendCommand(0x01);
	_delay_ms(2);

}

void Lcd_vidWriteChar(u8 Char)

{
	SET_BIT(PORTA , 0);  //RS
	CLR_BIT(PORTA , 1);  //RW
	PORTD = Char;
	SET_BIT(PORTA , 2);  //EN
	_delay_ms(2);
	CLR_BIT(PORTA , 2);  //EN
}

void step_1(void){
	u8 i;
	 for(i=0; i<16; i++)
	 {
		 Lcd_vidSendCommand(0x01);
		 Lcd_vidSendCommand((0x80 +i));
		 Lcd_vidWriteChar('X');
		 _delay_ms(300);
	 }

	 for(i=0; i<16; i++)
	 {
		 Lcd_vidSendCommand(0x01);
		 Lcd_vidSendCommand((0xc0 +i));
		 Lcd_vidWriteChar('X');
		 _delay_ms(300);
	 }
}

void step_2(void)
{
	u8 i;
	 for(i=0; i<16; i++){
		 Lcd_vidSendCommand(0x01);
		 Lcd_vidSendCommand((0xcf -i));
		 Lcd_vidWriteChar('X');
		 _delay_ms(300);
	 }
	 for(i=0; i<16; i++)
	 {
		 Lcd_vidSendCommand(0x01);
		 Lcd_vidSendCommand((0x8f -i));
		 Lcd_vidWriteChar('X');
		 _delay_ms(300);
	 }
}

