/*
 * main.c
 *
 *  Created on: Dec 8, 2020
 *      Author: zas
 */
#include "../lib/Std_types.h"
#include "../Lib/Bit_math.h"
#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>
#include "ADC_Interface.h"
#include "Lcd_int.h"
#include "Keypad_int.h"
#include "SevenSeg_int.h"
#include "Dio_int.h"

void Check_ADC(void);

extern u8 flag;
u8 Flag_ID   = 1;
u8 Flag_Pass = 0;
u8 Flag_App  = 0;

u8 Flag_Warning = 0;
u8 temp_varable = 0;
u16 TempValue = 0;
u16 LightDens = 0;
u8 counter    = 0;
u8 arr[6];

int main(void)
{
	Lcd_vidInit();
	Keypad_vidInit();
	Adc_vidInit();
	SevenSeg_vidInit(LEFT_SEVENSEG);
	Dio_vidSetPinDir(DIO_u8PIN_3 , DIO_u8OUTPUT);
	Dio_vidSetPinDir(DIO_u8PIN_4 , DIO_u8OUTPUT);

	for(u8 i=0; i<=5; i++)
	{
		arr[i]= 0xff;
	}
	Lcd_vidSendString("Enter ID: ");
	Lcd_vidSendCommand(0xc0);

	while(1)
	{
		u8 i = 0;
		while(Flag_ID == 1)
		{
			SevenSeg_vidTurnOff(LEFT_SEVENSEG);
			u8 check_id = 0;
			u8 Key = Keypad_u8GetKey();
			if(Key != 0xff)
			{
				if((Key >= 0) && (Key <= 9))
				{

					arr[i] = Key;
					Lcd_vidWriteNumber(Key);
					i++;
				}
				else if(Key == '=' )
				{
					check_id = 1;
					i = 0;
				}
			}

			if(check_id == 1)
			{
				u16 num = 0;
				u16 ID  = 0;
				while(arr[i] != 0xff)
				{
					num = num *10;
					num = num + arr[i];
					ID = num;
					i++;
				}
				if((ID == 1111) || (ID == 2222) || (ID == 3333))
				{
					Lcd_vidSendCommand(0x01);
					Lcd_vidSendString("Correct ID");
					_delay_ms(1000);
					Lcd_vidSendCommand(0x01);
					Lcd_vidSendString("Enter Password:");
					Lcd_vidSendCommand(0xc0);
					SevenSeg_vidDisplayNum(LEFT_SEVENSEG , 3);
					Flag_ID = 0;
					Flag_Pass = 1;
					i = 0;
				}
				else
				{
					Lcd_vidSendCommand(0x01);
					Lcd_vidSendString("InCorrect ID");
					_delay_ms(1000);
					Lcd_vidSendCommand(0x01);
					Lcd_vidSendString("ID Again:");
					Lcd_vidSendCommand(0xc0);
					for(u8 i=0; i<=5; i++)
					{
						arr[i]= 0xff;
					}
				}
				_delay_ms(200);
			}
			u8 counterpass = 3;
			while(Flag_Pass == 1)
			{
				u8 check_pass = 0;
				u8 Key = Keypad_u8GetKey();
				if(Key != 0xff)
				{
					if((Key >= 0) && (Key <= 9))
					{

						arr[i] = Key;
						Lcd_vidWriteNumber(Key);
						i++;
					}
					else if(Key == '=' )
					{
						check_pass = 1;
						i = 0;
					}
				}
				if(check_pass == 1)
				{
					u16 num = 0;
					u16 pass  = 0;
					while(arr[i] != 0xff)
					{
						num = num *10;
						num = num + arr[i];
						pass = num;
						i++;
					}
					if(pass == 1234)
					{
						Lcd_vidSendCommand(0x01);
						SevenSeg_vidTurnOff(LEFT_SEVENSEG);
						Lcd_vidSendString("Correct Password");
						_delay_ms(1000);
						Lcd_vidSendCommand(0x01);
						Lcd_vidSendString("1-Temp  ");
						Lcd_vidSendString("2-Light ");
						Lcd_vidSendCommand(0xc0);
						Lcd_vidSendString("3-Both  ");
						Lcd_vidSendString("4-Close ");

						Flag_App   = 1;
						Flag_Pass  = 0;
					}
					else
					{
						if(counterpass > 1)
						{
							Lcd_vidSendCommand(0x01);
							Lcd_vidSendString("InCorrect Password");
							_delay_ms(1000);
							Lcd_vidSendCommand(0x01);
							Lcd_vidSendString("Password Again:");
							Lcd_vidSendCommand(0xc0);
							for(u8 i=0; i<=5; i++)
							{
								arr[i]= 0xff;
							}
							counterpass--;
							SevenSeg_vidDisplayNum(LEFT_SEVENSEG , counterpass);
						}
						else
						{
							Lcd_vidSendCommand(0x01);
							Lcd_vidSendString("InCorrect Password");
							_delay_ms(1000);
							Lcd_vidSendCommand(0x01);
							Lcd_vidSendString("System Closed...");
							SevenSeg_vidTurnOff(LEFT_SEVENSEG);
							Flag_Pass  = 0;
							break;
						}
					}
				}
				_delay_ms(300);
			}

			while(Flag_App == 1)
			{
				u8 Key = Keypad_u8GetKey();
				if(Key != 0xff)
				{
					if(Key >=0 && Key<=9)
					{
						temp_varable = Key;
					}
				}
				Check_ADC();
				if(Flag_Warning == 1)
				{
					Lcd_vidSendCommand(0x01);
					Lcd_vidSendString("Warning...");
					Dio_vidSetPinval(DIO_u8PIN_3 , DIO_u8HIGH);
					Dio_vidSetPinval(DIO_u8PIN_4 , DIO_u8HIGH);
					_delay_ms(600);
					Lcd_vidSendCommand(0x01);
					Lcd_vidSendString("Warning...");
					Dio_vidSetPinval(DIO_u8PIN_3 , DIO_u8LOW);
					_delay_ms(500);
				}
				else
				{
					if(temp_varable == 1)
					{
						Lcd_vidSendCommand(0x01);
						Lcd_vidSendString("Temperature = ");
						Lcd_vidSendCommand(0xc0);
						Lcd_vidWriteNumber(TempValue);
						_delay_ms(500);

					}
					if(temp_varable == 2)
					{
						Lcd_vidSendCommand(0x01);
						Lcd_vidSendString("Light = ");
						Lcd_vidSendCommand(0xc0);
						Lcd_vidWriteNumber(LightDens);
						Lcd_vidWriteChar('%');
						_delay_ms(500);

					}
					if(temp_varable == 3)
					{
						Lcd_vidSendCommand(0x01);
						Lcd_vidSendString("Temperature= ");
						Lcd_vidWriteNumber(TempValue);
						Lcd_vidSendCommand(0xc0);
						Lcd_vidSendString("Light      = ");
						Lcd_vidWriteNumber(LightDens);
						Lcd_vidWriteChar('%');
						_delay_ms(500);
					}
					else if(temp_varable == 4)
					{
						Lcd_vidSendCommand(0x01);
						Lcd_vidSendString("Enter ID: ");
						Flag_App  = 0;
						Flag_Pass = 0;
						Flag_ID   = 1;
					}
					/*else
					{
						Lcd_vidSendCommand(0x01);
						Lcd_vidSendString("Not Valid");
						_delay_ms(1000);
						Lcd_vidSendCommand(0x01);
						Lcd_vidSendString("1-Temp  ");
						Lcd_vidSendString("2-Light ");
						Lcd_vidSendCommand(0xc0);
						Lcd_vidSendString("3-Both  ");
						Lcd_vidSendString("4-Close ");
					}*/
					if(Key == '=')
					{
						Lcd_vidSendCommand(0x01);
						Lcd_vidSendString("1-Temp  ");
						Lcd_vidSendString("2-Light ");
						Lcd_vidSendCommand(0xc0);
						Lcd_vidSendString("3-Both  ");
						Lcd_vidSendString("4-Close ");
						temp_varable = 0;
					}


				}
			}
			_delay_ms(200);
		}

	}
	return 0;
}

void Check_ADC(void)
{

 	f32 Digital = 0 ;
	Digital  = Adc_u16GetResult();
	if(flag == 0)
	{

		TempValue   = (Digital * 500)/1024;
		if(TempValue > 40)
		{
			Flag_Warning = 1;
		}
		else
		{
			Flag_Warning = 0;
		}
	}
	else if(flag == 1)
	{
		LightDens = (((Digital * 5)/1024)/5)*100 ;
	}

}
