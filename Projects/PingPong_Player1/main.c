#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>
#include "Exit_Private.h"
#include "Exit_int.h"
#include "Lcd_int.h"
#include "Dio_int.h"

void App_vidCheckSwitch(void);

extern u8 Flag_INT  ;
u8 ButtonDownUp1_Flag = 1;
u8 LCD_Flag = 1;
u8 flag = 1;
u8 i = 1;

u8 pattern_0[] = { 0B00000, 0B00000, 0B01110, 0B01110, 0B01110, 0B00000, 0B00000, 0B00000};

int main(void)
{
	IN0_vidInit();
	Lcd_vidInit();

	Lcd_vidStorePattern(pattern_0 , 0);

	/* Switch PIN*/
	Dio_vidSetPinDir(DIO_u8PIN_13 , DIO_u8INPUT);
	Dio_vidSetPinval(DIO_u8PIN_13 , DIO_u8HIGH );

	/* High Signal*/
	Dio_vidSetPinDir(DIO_u8PIN_31 , DIO_u8OUTPUT);
	Dio_vidSetPinval(DIO_u8PIN_31, DIO_u8HIGH  );

	/* Interrupt_0 PIN*/
	Dio_vidSetPinDir(DIO_u8PIN_26 , DIO_u8INPUT);



	while(1)
	{
		if(LCD_Flag == 1)
		{
			if(Flag_INT == 0)
			{
				if(flag == 1)
				{
					if(ButtonDownUp1_Flag == 1)
					{
						for(u8 i=1; i<15; i++)
						{
							App_vidCheckSwitch();
							Lcd_vidSetPosition(0 , i );
							Lcd_vidWriteChar(0);
							_delay_ms(150);
							Lcd_vidSendCommand(0x01);
						 }
					}
					else
					{
						 for(u8 i=1; i<15; i++)
						 {
							 App_vidCheckSwitch();
							 Lcd_vidSetPosition(1 , i );
							 Lcd_vidWriteChar(0);
							 _delay_ms(150);
							 Lcd_vidSendCommand(0x01);
						 }
					}
					Dio_vidSetPinval(DIO_u8PIN_31 , DIO_u8LOW );
					_delay_ms(300);
					Dio_vidSetPinval(DIO_u8PIN_31 , DIO_u8HIGH  );
					flag = 0;
					LCD_Flag = 0;
				}
				else
				{
					if(ButtonDownUp1_Flag == 1)
					{
						 for(u8 i=15; i>0; i--)
						 {
							 App_vidCheckSwitch();
							 Lcd_vidSetPosition(1 , (i-1) );
							 Lcd_vidWriteChar(0);
							 _delay_ms(150);
							 Lcd_vidSendCommand(0x01);
						 }
						 if(ButtonDownUp1_Flag == 1)
						 {
							Lcd_vidSendCommand(0x01);
							Lcd_vidSendString("player_2   : ");
							Lcd_vidWriteNumber(i);
							_delay_ms(500);
							Lcd_vidSendCommand(0x01);
							i++;
						}
						 flag = 1;
						 LCD_Flag = 1;
					}
					else
					{
						 for(u8 i=15; i>0; i--)
						 {
							 App_vidCheckSwitch();
							 Lcd_vidSetPosition(0 , (i-1) );
							 Lcd_vidWriteChar(0);
							 _delay_ms(150);
							 Lcd_vidSendCommand(0x01);
						 }
						 if(ButtonDownUp1_Flag == 0)
						 {
							Lcd_vidSendCommand(0x01);
							Lcd_vidSendString("player_2   : ");
							Lcd_vidWriteNumber(i);
							_delay_ms(500);
							Lcd_vidSendCommand(0x01);
							i++;
						}
						 flag = 1;
						 LCD_Flag = 1;
					}

				}

			}
		}
		else
		{
			if(Flag_INT == 0)
			{
				App_vidCheckSwitch();

			}
			else
			{
				LCD_Flag = 1;
				Flag_INT = 0;
			}
		}
	}


}

void App_vidCheckSwitch(void)
{
	u8 PinVal = Dio_u8GetPinVal(DIO_u8PIN_13);
	_delay_ms(10);

	if(PinVal == 0)
	{
		if(ButtonDownUp1_Flag == 1)
		{
			Lcd_vidSendCommand(0x01);
			Lcd_vidSetPosition(1 , 0);
			Lcd_vidWriteChar(0xff);
			ButtonDownUp1_Flag = 0;
		}
		else
		{
			Lcd_vidSendCommand(0x01);
			Lcd_vidSetPosition(0 , 0);
			Lcd_vidWriteChar(0xff);
			ButtonDownUp1_Flag = 1;
		}
	}
	else
	{
		if(ButtonDownUp1_Flag == 1)
		{
			Lcd_vidSetPosition(0 , 0);
			Lcd_vidWriteChar(0xff);
		}
		else
		{
			Lcd_vidSetPosition(1 , 0);
			Lcd_vidWriteChar(0xff);
		}
	}
}

