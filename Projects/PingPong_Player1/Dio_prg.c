/*
 * Dio_prg.c
 *
 *  Created on: Nov 29, 2020
 *      Author: Heba Ramadan
 */
#include "../lib/Std_types.h"
#include "../Lib/Bit_math.h"
#include "Dio_priv.h"
#include "Dio_int.h"

void Dio_vidSetPinDir(u8 Pin , u8 Dir)
{
	u8 PortId;
	u8 PinLoc;

	PortId = Pin/8;
	PinLoc = Pin%8;

	switch(PortId){
		case 0: //DDRA
			if(Dir ==1)
				{
				SET_BIT(DDRA.Byte , PinLoc);
				}
			else
				{
				CLR_BIT(DDRA.Byte , PinLoc);
				}
			break;
		case 1: //DDRB
			if(Dir ==1)
				{
				SET_BIT(DDRB.Byte , PinLoc);
				}
			else
				{
				CLR_BIT(DDRB.Byte , PinLoc);
				}
			break;
		case 2: //DDRC
			if(Dir ==1)
				{
				SET_BIT(DDRC.Byte , PinLoc);
				}
			else
				{
				CLR_BIT(DDRC.Byte , PinLoc);
				}
			break;
		case 3: //DDRD
			if(Dir ==1)
				{
				SET_BIT(DDRD.Byte , PinLoc);
				}
			else
				{
				CLR_BIT(DDRD.Byte , PinLoc);
				}
			break;
	}
}

void Dio_vidSetPinval(u8 Pin , u8 val)
{
	u8 PortId;
	u8 PinLoc;

	PortId = Pin/8;
	PinLoc = Pin%8;

	switch(PortId){
		case 0: //PORTA
			if(val ==1)
				{
				SET_BIT(PORTA.Byte , PinLoc);
				}
			else
				{
				CLR_BIT(PORTA.Byte , PinLoc);
				}
			break;
		case 1: //PORTB
			if(val ==1)
				{
				SET_BIT(PORTB.Byte , PinLoc);
				}
			else
				{
				CLR_BIT(PORTB.Byte , PinLoc);
				}
			break;
		case 2: //PORTC
			if(val ==1)
				{
				SET_BIT(PORTC.Byte , PinLoc);
				}
			else
				{
				CLR_BIT(PORTC.Byte , PinLoc);
				}
			break;
		case 3: //PORTD
			if(val ==1)
				{
				SET_BIT(PORTD.Byte , PinLoc);
				}
			else
				{
				CLR_BIT(PORTD.Byte , PinLoc);
				}
			break;
	}
}

u8 Dio_u8GetPinVal(u8 pin)
{
	u8 PortId;
	u8 PinLoc;
	u8 PinVal = 0;

	if (pin > 31)
	{
		PinVal = DIO_u8INVALED_PIN_NUM;
	}
	else
	{
		PortId = pin/8;
		PinLoc = pin%8;
		switch(PortId)
		{
			case 0: //PINA
				PinVal = GET_BIT(PINA.Byte , PinLoc);
			break;

			case 1: //PINB
				PinVal = GET_BIT(PINB.Byte , PinLoc);
			break;

			case 2: //PINC
				PinVal = GET_BIT(PINC.Byte , PinLoc);
			break;

			case 3: //PIND
				PinVal = GET_BIT(PIND.Byte , PinLoc);
			break;
		}
	}
	return PinVal;

}
