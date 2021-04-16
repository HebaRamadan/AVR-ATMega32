/*
 * main.c
 *
 *  Created on: Feb 16, 2020
 *      Author: zas
 */
#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#include "Adc_int.h"
#include "Lcd_int.h"

int main()
{

	Adc_vidInit();
	Lcd_vidInit();
	u8 arr[7] = "Volume";
	u8 i;
	f32 Digital;
	f32 Analog;
	u8 pattern_1[8]={ 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b11111, 0b00000};
	u8 pattern_2[8]={ 0b00000, 0b00000, 0b00000, 0b00000, 0b11111, 0b11111, 0b11111, 0b00000};
	u8 pattern_3[8]={ 0b00000, 0b00000, 0b00000, 0b11111, 0b11111, 0b11111, 0b11111, 0b00000};
	u8 pattern_4[8]={ 0b00000, 0b00000, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b00000};
	u8 pattern_5[8]={ 0b00000, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b00000};
	u8 pattern_6[8]={ 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b00000};
	Lcd_vidStorePattern(pattern_1 , 0);
	Lcd_vidStorePattern(pattern_2 , 1);
	Lcd_vidStorePattern(pattern_3 , 2);
    Lcd_vidStorePattern(pattern_4 , 3);
	Lcd_vidStorePattern(pattern_5 , 4);
	Lcd_vidStorePattern(pattern_6 , 5);

	 for(i=0; i<7; i++)
	 {
		if(arr[i] == '\0')
		{
			break;
		}
		else
		{
			Lcd_vidSendCommand(0x85 + i);
			Lcd_vidWriteChar(arr[i]);
		}
	 }

	while(1)
	{
		Digital = Adc_u16GetResult(ADC_u8CH_0);
		Analog  = (Digital * 5)/1024 ;

		if(Analog == 0)
		{

			 Lcd_vidSendCommand(0xC5);
			 Lcd_vidWriteChar(0);
			 Lcd_vidSendCommand(0xC6);
			 Lcd_vidWriteChar(0);
			 Lcd_vidSendCommand(0xC7);
			 Lcd_vidWriteChar(0);
			 Lcd_vidSendCommand(0xC8);
			 Lcd_vidWriteChar(0);
			 Lcd_vidSendCommand(0xC9);
			 Lcd_vidWriteChar(0);
			 Lcd_vidSendCommand(0xCA);
			 Lcd_vidWriteChar(0);
		}

		else if((Analog > 0 ) && (Analog <= 1))
		{
			 Lcd_vidSendCommand(0xC5);
			 Lcd_vidWriteChar(0);
			 Lcd_vidSendCommand(0xC6);
			 Lcd_vidWriteChar(1);
			 Lcd_vidSendCommand(0xC7);
			 Lcd_vidWriteChar(0);
			 Lcd_vidSendCommand(0xC8);
			 Lcd_vidWriteChar(0);
			 Lcd_vidSendCommand(0xC9);
			 Lcd_vidWriteChar(0);
			 Lcd_vidSendCommand(0xCA);
			 Lcd_vidWriteChar(0);
		}

		else if((Analog > 1 ) && (Analog <= 2))
		{

			 Lcd_vidSendCommand(0xC5);
			 Lcd_vidWriteChar(0);
			 Lcd_vidSendCommand(0xC6);
			 Lcd_vidWriteChar(1);
			 Lcd_vidSendCommand(0xC7);
			 Lcd_vidWriteChar(2);
			 Lcd_vidSendCommand(0xC8);
			 Lcd_vidWriteChar(0);
			 Lcd_vidSendCommand(0xC9);
			 Lcd_vidWriteChar(0);
			 Lcd_vidSendCommand(0xCA);
			 Lcd_vidWriteChar(0);
		}

		else if((Analog > 2 ) && (Analog <= 3))
		{
			 Lcd_vidSendCommand(0xC5);
			 Lcd_vidWriteChar(0);
			 Lcd_vidSendCommand(0xC6);
			 Lcd_vidWriteChar(1);
			 Lcd_vidSendCommand(0xC7);
			 Lcd_vidWriteChar(2);
			 Lcd_vidSendCommand(0xC8);
			 Lcd_vidWriteChar(3);
			 Lcd_vidSendCommand(0xC9);
			 Lcd_vidWriteChar(0);
			 Lcd_vidSendCommand(0xCA);
			 Lcd_vidWriteChar(0);
		}

		else if((Analog > 3 ) && (Analog <= 4))
		{
			 Lcd_vidSendCommand(0xC5);
			 Lcd_vidWriteChar(0);
			 Lcd_vidSendCommand(0xC6);
			 Lcd_vidWriteChar(1);
			 Lcd_vidSendCommand(0xC7);
			 Lcd_vidWriteChar(2);
			 Lcd_vidSendCommand(0xC8);
			 Lcd_vidWriteChar(3);
			 Lcd_vidSendCommand(0xC9);
			 Lcd_vidWriteChar(4);
			 Lcd_vidSendCommand(0xCA);
			 Lcd_vidWriteChar(0);
		}

		else
		{
			 Lcd_vidSendCommand(0xC5);
			 Lcd_vidWriteChar(0);
			 Lcd_vidSendCommand(0xC6);
			 Lcd_vidWriteChar(1);
			 Lcd_vidSendCommand(0xC7);
			 Lcd_vidWriteChar(2);
			 Lcd_vidSendCommand(0xC8);
			 Lcd_vidWriteChar(3);
			 Lcd_vidSendCommand(0xC9);
			 Lcd_vidWriteChar(4);
			 Lcd_vidSendCommand(0xCA);
			 Lcd_vidWriteChar(5);
		}



	}
	return 0;

}

