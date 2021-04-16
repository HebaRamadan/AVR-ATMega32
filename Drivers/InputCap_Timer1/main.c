/*
 * main.c
 *
 *  Created on: Dec 19, 2020
 *      Author: zas
 */

#include "Std_types.h"
#include "Bit_math.h"
#include "Timer1_Interface.h"
#include "LCD_Interface.h"
#include "DIO_Interface.h"

u8  flag       = 0;
u32 Snap_1     = 0;
u32 Snap_2     = 0;
u32 Snap_3     = 0;

u16 DutyCycle  = 0;
u32 Frequency  = 0;


int main(void)
{
	Timer1_vidInit();
	GIE_vidEnable();
	LCD_vidInit();
	DIO_vidSetPinDirection(PortD , PIN_6  , 0);

	while(1)
	{
		if(flag == 3)
		{
			DutyCycle = ((Snap_2 - Snap_1) *100) / (Snap_3 - Snap_1);
			Frequency = (u32)8000000 / (Snap_3 - Snap_1);
			flag = 0;

			LCD_vidSendCommand(0x80);
			LCD_vidSendString ("DutyCycle= ");
			LCD_vidWriteNumber( DutyCycle   );

			LCD_vidSendCommand(0xc0);
			LCD_vidSendString ("Frequency= ");
			LCD_vidWriteNumber( Frequency   );
		}

	}
	return 0;
}
