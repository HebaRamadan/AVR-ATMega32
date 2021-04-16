/*
 * main.c
 *
 *  Created on: Feb 16, 2020
 *      Author: zas
 */
#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>
#include "Adc_int.h"
#include "Lcd_int.h"
#include "Dio_int.h"

int main()
{
 	Lcd_vidInit();
	Adc_vidInit();
	u8 arr[8] = "Volt = ";
	f32 Digital;
	u16 Val;
	f32 Analog;
	u8 PinVal;
	u8 i;

	Dio_vidSetPinDir(DIO_u8PIN_19 , DIO_u8INPUT);
	Dio_vidSetPinval(DIO_u8PIN_19 , DIO_u8HIGH);

	while(1)
	{
		Digital = Adc_u16GetResult(ADC_u8CH_0);
		Analog  = (Digital * 5)/1024 ;
		PinVal  = Dio_u8GetPinVal(DIO_u8PIN_19);

		for(i=0; i<8; i++)
		{
			if(arr[i]== '\0')
				break;
			else
			{
				Lcd_vidSendCommand(0x80 + i );
				Lcd_vidWriteChar(arr[i]);
			}
		}

		if(PinVal == 1)
		{
			_delay_ms(330);
			Lcd_vidSendCommand(0x01);

			if(Analog < 1)
			{
				Val = Analog*10;
				Lcd_vidSendCommand(0x80+i );
				Lcd_vidWriteChar('0');
				Lcd_vidSendCommand((0x80+i)+1);
				Lcd_vidWriteChar('.');
				Lcd_vidSendCommand((0x80+i)+2);
				Lcd_vidWriteChar(Val + '0');
				Lcd_vidSendCommand((0x80+i)+3);
				Lcd_vidWriteChar('V');

			}

			else
			{
				Val = Analog*10;
				Lcd_vidSendCommand(0x80+i );
				Lcd_vidWriteChar((Val/10)+'0');
				Lcd_vidSendCommand((0x80+i)+1);
				Lcd_vidWriteChar('.');
				Lcd_vidSendCommand((0x80+i)+2);
				Lcd_vidWriteChar((Val%10)+ '0');
				Lcd_vidSendCommand((0x80+i)+3);
				Lcd_vidWriteChar('V');


			}
		}

		else
		{
			_delay_ms(330);
			Lcd_vidSendCommand(0x01);
			if((Analog < 1) && (Analog > 0))
			{
				Val = Analog*1000;
				Lcd_vidSendCommand((0x80+i)+2 );
				Lcd_vidWriteChar((Val%10) +'0');
				Val = Val /10;
				Lcd_vidSendCommand((0x80+i)+1);
				Lcd_vidWriteChar((Val%10) +'0');
				Val = Val /10;
				Lcd_vidSendCommand((0x80+i));
				Lcd_vidWriteChar((Val) +'0');

				Lcd_vidSendCommand((0x80+i)+4);
				Lcd_vidWriteChar('m');
				Lcd_vidSendCommand((0x80+i)+5);
				Lcd_vidWriteChar('V');


			}

			else
			{
				Val = Analog*1000;
				Lcd_vidSendCommand((0x80+i)+3 );
				Lcd_vidWriteChar((Val%10) +'0');
				Val = Val /10;
				Lcd_vidSendCommand((0x80+i)+2);
				Lcd_vidWriteChar((Val%10) +'0');
				Val = Val /10;
				Lcd_vidSendCommand((0x80+i)+1);
				Lcd_vidWriteChar((Val%10) +'0');
				Val = Val /10;
				Lcd_vidSendCommand((0x80+i));
				Lcd_vidWriteChar((Val) +'0');

				Lcd_vidSendCommand((0x80+i)+4);
				Lcd_vidWriteChar('m');
				Lcd_vidSendCommand((0x80+i)+5);
				Lcd_vidWriteChar('V');

			}
		}


	}
	return 0;

}
