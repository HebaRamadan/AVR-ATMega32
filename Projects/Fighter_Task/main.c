/*
 * main.c
 *
 *  Created on: Mar 2, 2020
 *      Author: zas
 */
#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>
#include "Lcd_int.h"
#include "Keypad_int.h"
#include "Stepper_int.h"
#include "Servo_int.h"
#include "DC_Motor_int.h"
#include "Buzzer_int.h"
#include "Led_int.h"
#include "Timer0_pwm_int.h"

u8 arr[5];
u8 arr_1[10]  = "Welcome";
u8 arr_2[10]  = "Password:";
u8 arr_3[10]  = "1-Window";
u8 arr_4[10]  = "2-Light";
u8 arr_5[10]  = "3-Fan";
u8 arr_6[10]  = "4-Exit";
u8 arr_7[20]  = "invalid Password";
u8 arr_8[20]  = "System Blocked";
u8 arr_9[20]  = "Not Valid Input";
u8 arr_10[10] = "GoodBye";
u8 arr_11[10] = "Home";
u8 arr_a[10]  = "Angle = ";
u8 arr_b[20]  = "Intensity = ";
u8 arr_c[5]   = "1-ON" ;
u8 arr_d[5]   = "0-OFF" ;
u8 key;
u8 Password_iteration = 0;
u16 Password_index;
u16 angle_index;
u8 angle;
u16 intensity_index;
u8  intensity;
u8 Password_flag = 1;
u8 error_flag  = 0;
u8 door_flag   = 0;
u8 control_flag= 0;
u8 window_flag = 0;
u8 light_flag  = 0;
u8 fan_flag    = 0;
u8 exit_flag   = 0;
u8 i = 0;

int main(void)
{
	//Initialize all peripherals
	Lcd_vidInit();
	Keypad_vidInit();
	Stepper_vidInit();
	Buzzer_vidInit();
	Led_vidInit(LED_2);
	Servo_vidInit();
	Timer_vidInit();
	DC_vidInit();

	while(1)
	{
		//start get password
		while(Password_flag == 1)
		{
			Lcd_vidSendCommand(0x80);
			Lcd_vidWriteStr(arr_1);
			Lcd_vidSendCommand(0xC0);
			Lcd_vidWriteStr(arr_2);
			key= Keypad_u8GetKey();
			if(key!= 0xff)
			{
				if((key<=9)&&(key>=0))
				{
					Lcd_vidSendCommand(0xC9 +i);
					Lcd_vidWriteChar('*');
					arr[i]=key;
					_delay_ms(500);
					i++;
				}
				else if(key =='#')
				{
					Password_index = (arr[0]*1000)+(arr[1]*100)+(arr[2]*10)+(arr[3]);
					i=0;
					Password_flag = 0;
					door_flag  = 1;
				}
			}
		}

		while(door_flag == 1)
		{
			if(Password_index == 1234 )
			{
				Password_iteration = 0;
				Lcd_vidSendCommand(0x01);
				Lcd_vidSendCommand(0x82);
				Lcd_vidWriteStr(arr_1);
				Lcd_vidSendCommand(0x8A);
				Lcd_vidWriteStr(arr_11);
				Stepper_vidTurnRight(180);
				_delay_ms(1000);
				Stepper_vidTurnLeft(180);
				Lcd_vidSendCommand(0x01);
				control_flag = 1;
				door_flag    = 0;
			}
			else
			{
				Password_iteration++;
				if(Password_iteration < 3)
				{
					Lcd_vidSendCommand(0x01);
					Lcd_vidSendCommand(0x80);
					Lcd_vidWriteStr(arr_7);
					_delay_ms(1500);
					Password_flag = 1;
					door_flag     = 0;
				}
				else
				{
					error_flag = 1;
					door_flag  = 0;
				}

			}
		}
		while(control_flag == 1)
		{
			Lcd_vidSendCommand(0x80);
			Lcd_vidWriteStr(arr_3);
			Lcd_vidSendCommand(0xC0);
			Lcd_vidWriteStr(arr_4);
			Lcd_vidSendCommand(0x89);
			Lcd_vidWriteStr(arr_5);
			Lcd_vidSendCommand(0xC9);
			Lcd_vidWriteStr(arr_6);
			key= Keypad_u8GetKey();
			if(key!= 0xff)
			{
				switch(key)
				{
					case 1:
						Lcd_vidSendCommand(0x01);
						Lcd_vidSendCommand(0x80);
						Lcd_vidWriteStr(arr_3);
						Lcd_vidSendCommand(0xC0);
						Lcd_vidWriteStr(arr_a);
						_delay_ms(500);
						window_flag  =1;
						control_flag =0;
					break;

					case 2:
						Lcd_vidSendCommand(0x01);
						Lcd_vidSendCommand(0x80);
						Lcd_vidWriteStr(arr_4);
						Lcd_vidSendCommand(0xC0);
						Lcd_vidWriteStr(arr_b);
						_delay_ms(500);
						light_flag   =1;
						control_flag =0;
					break;

					case 3:
						Lcd_vidSendCommand(0x01);
						Lcd_vidSendCommand(0x80);
						Lcd_vidWriteStr(arr_5);
						Lcd_vidSendCommand(0xC0);
						Lcd_vidWriteStr(arr_c);
						Lcd_vidSendCommand(0xC8);
						Lcd_vidWriteStr(arr_d);
						_delay_ms(500);
						fan_flag     =1;
						control_flag =0;
					break;

					case 4:
						Lcd_vidSendCommand(0x01);
						Lcd_vidSendCommand(0x80);
						Lcd_vidWriteStr(arr_6);
						exit_flag     =1;
						control_flag  =0;
					break;

					default :
						Lcd_vidSendCommand(0x01);
						Lcd_vidSendCommand(0x80);
						Lcd_vidWriteStr(arr_9);
						_delay_ms(1500);
						Lcd_vidSendCommand(0x01);
					break;
				}
			}

		}

		while(window_flag == 1)
		{
			key= Keypad_u8GetKey();
			if(key!= 0xff)
			{
				if((key<=9)&&(key>=0))
				{
					Lcd_vidSendCommand(0xC8 +i);
					Lcd_vidWriteChar(key + '0');
					arr[i]=key;
					_delay_ms(500);
					i++;
				}
				else if(key =='#')
				{
					if(i==1)
					{
						angle_index = (arr[0]);
					}
					else if(i==2)
					{
						angle_index = (arr[0]*10)+(arr[1]);
					}
					else
					{
						angle_index = (arr[0]*100)+(arr[1]*10)+(arr[2]);
					}

					if( (angle_index >= 0) && (angle_index <= 180) && (i<=3) )
					{
						angle = angle_index;
						Servo_vidSetDegree(angle);
						_delay_ms(1000);
						i=0;
					    Lcd_vidSendCommand(0x01);
						control_flag = 1;
					    window_flag  = 0;
					}
					else
					{
						i=0;
						Lcd_vidSendCommand(0x01);
						Lcd_vidWriteStr(arr_9);
						_delay_ms(1500);
						Lcd_vidSendCommand(0x01);
						Lcd_vidSendCommand(0x80);
						Lcd_vidWriteStr(arr_3);
						Lcd_vidSendCommand(0xC0);
						Lcd_vidWriteStr(arr_a);
					}
				}

			}

		}

		while(light_flag == 1)
		{
			key= Keypad_u8GetKey();
			if(key!= 0xff)
			{
				if((key<=9)&&(key>=0))
				{
					Lcd_vidSendCommand(0xCB +i);
					Lcd_vidWriteChar(key + '0');
					arr[i]=key;
					_delay_ms(500);
					i++;
				}
				else if(key =='#')
				{
					if(i==1)
					{
						intensity_index = (arr[0]);
					}
					else if(i==2)
					{
						intensity_index = (arr[0]*10)+(arr[1]);
					}
					else if(i==3)
					{
						intensity_index = (arr[0]*100)+(arr[1]*10)+(arr[2]);
					}
					if((intensity_index >=0 )  && (intensity_index <=100 ) && i<=3)
					{
						intensity = intensity_index;
						Timer_vidIntensity(intensity);
						_delay_ms(1000);
						i=0;
						Lcd_vidSendCommand(0x01);
						control_flag = 1;
						light_flag   = 0;
					}
					else
					{
						i=0;
						Lcd_vidSendCommand(0x01);
						Lcd_vidWriteStr(arr_9);
						_delay_ms(1500);
						Lcd_vidSendCommand(0x80);
						Lcd_vidWriteStr(arr_4);
						Lcd_vidSendCommand(0xC0);
						Lcd_vidWriteStr(arr_b);
					}

				}

			}


		}

		while(fan_flag == 1)
		{

			key= Keypad_u8GetKey();
			if(key!= 0xff)
			{
				switch(key)
				{
					case 0:
						DC_vidTurnOff();
						_delay_ms(1000);
						Lcd_vidSendCommand(0x01);
						control_flag = 1;
						fan_flag   = 0;
					break;

					case 1:
						DC_vidTurnOn();
						_delay_ms(1000);
						Lcd_vidSendCommand(0x01);
						control_flag = 1;
						fan_flag   = 0;
					break;

					default :
						Lcd_vidSendCommand(0x01);
						Lcd_vidSendCommand(0x80);
						Lcd_vidWriteStr(arr_9);
						_delay_ms(1500);
						Lcd_vidSendCommand(0x01);
						Lcd_vidSendCommand(0x80);
						Lcd_vidWriteStr(arr_5);
						Lcd_vidSendCommand(0xC0);
						Lcd_vidWriteStr(arr_c);
						Lcd_vidSendCommand(0xC8);
						Lcd_vidWriteStr(arr_d);
					break;
				}


			}

		}

		while(exit_flag == 1)
		{
			Lcd_vidSendCommand(0x01);
			Lcd_vidSendCommand(0x84);
			Lcd_vidWriteStr(arr_10);
			Stepper_vidTurnRight(180);
			_delay_ms(1000);
			Stepper_vidTurnLeft(180);
			Servo_vidSetDegree(0);
			_delay_ms(50);
			DC_vidTurnOff();
			_delay_ms(50);
			Timer_vidIntensity(0);
			_delay_ms(500);
			Lcd_vidSendCommand(0x01);
			Password_flag = 1;
			exit_flag    = 0;

		}

		if(error_flag == 1)
		{
			Lcd_vidSendCommand(0x01);
			Lcd_vidSendCommand(0x80);
			Lcd_vidWriteStr(arr_8);
			Buzzer_vidTurnOn();
			Led_vidTurnOn(LED_2);
			break;
		}
	}

	return 0;
}

