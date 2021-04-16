/*
 * Dio_prg.c
 *
 *  Created on: Jan 20, 2020
 *      Author: zas
 */
#include "Std_types.h"
#include "Bit_math.h"
#include "Dio_int.h"
#include "avr/io.h"

void Dio_vidSetPinDir(u8 Pin , u8 Dir)
{
	u8 PinId;
	u8 PinLoc;

	PinId  = Pin/8;
	PinLoc = Pin%8;

	switch(PinId)
	{
		case 0:
			if(Dir==1)
			{
				SET_BIT(DDRA , PinLoc);
			}
			else
			{
				CLR_BIT(DDRA , PinLoc);
			}
		break;

		case 1:
			if(Dir==1)
			{
				SET_BIT(DDRB , PinLoc);
			}
			else
			{
				CLR_BIT(DDRB , PinLoc);
			}
		 break;

		case 2:
			if(Dir==1)
			{
				SET_BIT(DDRC , PinLoc);
			}
			else
			{
				CLR_BIT(DDRC , PinLoc);
			}
		break;

		case 3:
			if(Dir==1)
			{
				SET_BIT(DDRD , PinLoc);
			}
			else
			{
				CLR_BIT(DDRD , PinLoc);
			}
		 break;
	}
}

void Dio_vidSetPinVal(u8 Pin , u8 Val)
{
	u8 PinId;
	u8 PinLoc;

	PinId  = Pin/8;
	PinLoc = Pin%8;

	switch(PinId)
	{
		case 0:
			if(Val==1)
			{
				SET_BIT(PORTA , PinLoc);
			}
			else
			{
				CLR_BIT(PORTA , PinLoc);
			}
		break;

		case 1:
			if(Val==1)
			{
				SET_BIT(PORTB , PinLoc);
			}
			else
			{
				CLR_BIT(PORTB , PinLoc);
			}
		 break;

		case 2:
			if(Val==1)
			{
				SET_BIT(PORTC , PinLoc);
			}
			else
			{
				CLR_BIT(PORTC , PinLoc);
			}
		break;

		case 3:
			if(Val==1)
			{
				SET_BIT(PORTD , PinLoc);
			}
			else
			{
				CLR_BIT(PORTD , PinLoc);
			}
		 break;
	}
}


