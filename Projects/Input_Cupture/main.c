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
#include <avr/io.h>
#include "avr/interrupt.h"

u8  First_Reading = 0;
u8  state;
u32 Ovr_Count;
f32 Ton;
f32 Toff;
f32 Ttot;
f32 Freq;
f32 Duty;
u8 arr[10]   = "Freq = ";
u8 arr_1[10] = "Duty = ";

int main(void)
{
	//Normal mode
	CLR_BIT(TCCR1A , 1);
	CLR_BIT(TCCR1A , 0);
	CLR_BIT(TCCR1B , 4);
	CLR_BIT(TCCR1B , 3);

	//input capture edge select (rising)
	SET_BIT(TCCR1B , 6);

	//pre_scaller
	CLR_BIT(TCCR1B , 2);
	CLR_BIT(TCCR1B , 1);
	SET_BIT(TCCR1B , 0);

	//Enable input capture interrupt
	SET_BIT(TIMSK , 5);
	//Enable overflow interrupt
	SET_BIT(TIMSK , 2);
	//GIE
	SET_BIT(SREG , 7);

	Dio_vidSetPinDir(DIO_u8PIN_7 , DIO_u8OUTPUT);
	Dio_vidSetPinDir(DIO_u8PIN_30 , DIO_u8INPUT);
	Lcd_vidInit();
	Ttot = Ton +Toff;
	Freq = (f32)1/Ttot;
	Duty = (Ton * (f32)100)/Ttot;
	Lcd_vidSendCommand(0X80);
	Lcd_vidWriteStr(arr);
	Lcd_vidWriteChar(((u8)Freq /100)+'0');
	Lcd_vidWriteChar((((u8)Freq %100)/10)+'0');
	Lcd_vidWriteChar(((u8)Freq %10)+'0');
	Lcd_vidWriteChar('H');
	Lcd_vidWriteChar('Z');

	Lcd_vidSendCommand(0XC0);
	Lcd_vidWriteStr(arr_1);
	Lcd_vidWriteChar(((u8)Duty /100)+'0');
	Lcd_vidWriteChar((((u8)Duty %100)/10)+'0');
	Lcd_vidWriteChar(((u8)Duty %10)+'0');
	Lcd_vidWriteChar('%');

	while(1)
	{
		Dio_vidSetPinval(DIO_u8PIN_7 , DIO_u8HIGH);
		_delay_ms(1);
		Dio_vidSetPinval(DIO_u8PIN_7 , DIO_u8LOW);
		_delay_ms(1);
	}
	return 0;
}


ISR(TIMER1_OVF_vect)
{
	Ovr_Count++;
}

ISR(TIMER1_CAPT_vect)
{
	if(First_Reading == 0)
	{
		//re-initialize timer
		TCNT1 =0;
		//change edge (falling edge)
		CLR_BIT(TCCR1B , 6);
		//indicate that now rising edge next is falling edge
		state = 1;
		First_Reading = 1;
		Ovr_Count = 0;
	}
	else
	{
		if(state == 1)
		{
			//re-initialize timer
			TCNT1 =0;
			//change edge (rising edge)
			SET_BIT(TCCR1B , 6);
			Ton = (f32)(ICR1 + (65536 * Ovr_Count)) / (f32)8000000;
			//indicate that now falling edge next is rising edge
			state = 0;
			Ovr_Count = 0;

		}
		else
		{
			TCNT1 =0;
			CLR_BIT(TCCR1B , 6);
			Toff = (f32)(ICR1 + (65536 * Ovr_Count)) / (f32)8000000;
			state = 1;
			Ovr_Count = 0;
		}
	}
}
