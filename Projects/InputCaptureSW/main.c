/*
 * main.c
 *
 *  Created on: Dec 20, 2020
 *      Author: zas
 */
#include "Std_types.h"
#include "Bit_math.h"
#include "Timer0_Init.h"
#include "Timer1_Interface.h"
#include "Interr_int.h"
#include "LCD_Interface.h"
#include "DIO_Interface.h"

void App_vidOverFlowCounter(void);
void App_vidDetectEdge     (void);


u8  flag        = 0;
u8  Time_Flag   = 0;
u8  OV_Counter  = 0;

u32 TON         = 0;
u32 TOFF        = 0;

f32 DutyCycle   = 0;
f32 Frequency   = 0;

int main(void)
{
	Timer1_vidInit();
	INT_vidInit();
	LCD_vidInit();
	DIO_vidSetPinDirection( PortD , PIN_5  , 1);
	DIO_vidSetPinDirection( PortD , PIN_2  , 0);
	GIE_vidEnable();

	OVF_vidSetCB(App_vidOverFlowCounter);
	INT0_vidSetCB(App_vidDetectEdge);

	while(1)
	{
		if( 1 == Time_Flag)
		{
			DutyCycle = (TON * 100  / (TON + TOFF));

			Frequency = ((8000000/256) / (TON + TOFF));
			Time_Flag = 0;

			LCD_vidSendCommand(0x80);
			LCD_vidSendString( "DutyCycle =");
			LCD_vidWriteNumber( (u32)DutyCycle   );
			LCD_vidSendData('%');


			LCD_vidSendCommand(0xC0);
			LCD_vidSendString( "Frequency =");
			LCD_vidWriteNumber( Frequency   );
			LCD_vidSendString( "HZ");

		}


	}


}

void App_vidOverFlowCounter(void)
{
	OV_Counter++;
}

void App_vidDetectEdge(void)
{
	if( 0 == flag )
	{
		Timer0_vidInit();
		IN0_vidSenseControl(FALLING);
		OV_Counter = 0;
		flag       = 1;
	}
	else if( 1 == flag )
	{
		u8 Timer_Val = Timer0_u8GetCounterRegistr();
		Timer0_u8SetCounterRegistr(0);

		TON =  Timer_Val + (OV_Counter * 256);

		IN0_vidSenseControl(RISING);

		OV_Counter = 0;
		flag       = 2;

	}
	else if( 2 == flag )
	{
		u8 Timer_Val = Timer0_u8GetCounterRegistr();
		Timer0_u8SetCounterRegistr(0);

		TOFF =  Timer_Val + (OV_Counter * 256);

		IN0_vidSenseControl(FALLING);
		OV_Counter = 0;
		flag       = 1;
		Time_Flag  = 1;
	}
}
