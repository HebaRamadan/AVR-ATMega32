/*
 * Keypad_prg.c
 *
 *  Created on: Feb 12, 2020
 *      Author: zas
 */
#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#include "Keypad_cfg.h"
#include "Dio_int.h"
#include "Keypad_int.h"


void Keypad_vidInit(void)
{
	Dio_vidSetPinDir(KEYPAD_u8R1_PIN , DIO_u8OUTPUT);
	Dio_vidSetPinDir(KEYPAD_u8R2_PIN , DIO_u8OUTPUT);
	Dio_vidSetPinDir(KEYPAD_u8R3_PIN , DIO_u8OUTPUT);
	Dio_vidSetPinDir(KEYPAD_u8R4_PIN , DIO_u8OUTPUT);
	Dio_vidSetPinDir(KEYPAD_u8C1_PIN , DIO_u8INPUT);
	Dio_vidSetPinDir(KEYPAD_u8C2_PIN , DIO_u8INPUT);
	Dio_vidSetPinDir(KEYPAD_u8C3_PIN , DIO_u8INPUT);
	Dio_vidSetPinDir(KEYPAD_u8C4_PIN , DIO_u8INPUT);

	Dio_vidSetPinval(KEYPAD_u8R1_PIN , DIO_u8HIGH);
	Dio_vidSetPinval(KEYPAD_u8R2_PIN , DIO_u8HIGH);
	Dio_vidSetPinval(KEYPAD_u8R3_PIN , DIO_u8HIGH);
	Dio_vidSetPinval(KEYPAD_u8R4_PIN , DIO_u8HIGH);
	Dio_vidSetPinval(KEYPAD_u8C1_PIN , DIO_u8HIGH);
	Dio_vidSetPinval(KEYPAD_u8C2_PIN , DIO_u8HIGH);
	Dio_vidSetPinval(KEYPAD_u8C3_PIN , DIO_u8HIGH);
	Dio_vidSetPinval(KEYPAD_u8C4_PIN , DIO_u8HIGH);

}

u8 Keypad_u8GetKey(void)
{
	u8 pin_c1;
	u8 pin_c2;
	u8 pin_c3;
	u8 pin_c4;
	u8 temp;

	Dio_vidSetPinval(KEYPAD_u8R1_PIN , DIO_u8LOW);
	Dio_vidSetPinval(KEYPAD_u8R2_PIN , DIO_u8HIGH);
	Dio_vidSetPinval(KEYPAD_u8R3_PIN , DIO_u8HIGH);
	Dio_vidSetPinval(KEYPAD_u8R4_PIN , DIO_u8HIGH);

	//create mask to get value of pins
	pin_c1 = Dio_u8GetPinVal(KEYPAD_u8C1_PIN);
	pin_c2 = Dio_u8GetPinVal(KEYPAD_u8C2_PIN);
	pin_c3 = Dio_u8GetPinVal(KEYPAD_u8C3_PIN);
	pin_c4 = Dio_u8GetPinVal(KEYPAD_u8C4_PIN);

	temp = 0;
	temp |= (pin_c1 <<4);
	temp |= (pin_c2 <<5);
	temp |= (pin_c3 <<6);
	temp |= (pin_c4 <<7);

	switch(temp)
	{
		case 0b11100000:
			return KEYPAD_u8R1C1_KEY;
		case 0b11010000:
			return KEYPAD_u8R1C2_KEY;
		case 0b10110000:
			return KEYPAD_u8R1C3_KEY;
		case 0b01110000:
			return KEYPAD_u8R1C4_KEY;
	}


	Dio_vidSetPinval(KEYPAD_u8R1_PIN , DIO_u8HIGH);
	Dio_vidSetPinval(KEYPAD_u8R2_PIN , DIO_u8LOW);
	Dio_vidSetPinval(KEYPAD_u8R3_PIN , DIO_u8HIGH);
	Dio_vidSetPinval(KEYPAD_u8R4_PIN , DIO_u8HIGH);


	pin_c1 = Dio_u8GetPinVal(KEYPAD_u8C1_PIN);
	pin_c2 = Dio_u8GetPinVal(KEYPAD_u8C2_PIN);
	pin_c3 = Dio_u8GetPinVal(KEYPAD_u8C3_PIN);
	pin_c4 = Dio_u8GetPinVal(KEYPAD_u8C4_PIN);

	temp = 0;
	temp |= (pin_c1 <<4);
	temp |= (pin_c2 <<5);
	temp |= (pin_c3 <<6);
	temp |= (pin_c4 <<7);

	switch(temp)
	{
		case 0b11100000:
			return KEYPAD_u8R2C1_KEY;
		case 0b11010000:
			return KEYPAD_u8R2C2_KEY;
		case 0b10110000:
			return KEYPAD_u8R2C3_KEY;
		case 0b01110000:
			return KEYPAD_u8R2C4_KEY;
	}


	Dio_vidSetPinval(KEYPAD_u8R1_PIN , DIO_u8HIGH);
	Dio_vidSetPinval(KEYPAD_u8R2_PIN , DIO_u8HIGH);
	Dio_vidSetPinval(KEYPAD_u8R3_PIN , DIO_u8LOW);
	Dio_vidSetPinval(KEYPAD_u8R4_PIN , DIO_u8HIGH);


	pin_c1 = Dio_u8GetPinVal(KEYPAD_u8C1_PIN);
	pin_c2 = Dio_u8GetPinVal(KEYPAD_u8C2_PIN);
	pin_c3 = Dio_u8GetPinVal(KEYPAD_u8C3_PIN);
	pin_c4 = Dio_u8GetPinVal(KEYPAD_u8C4_PIN);

	temp = 0;
	temp |= (pin_c1 <<4);
	temp |= (pin_c2 <<5);
	temp |= (pin_c3 <<6);
	temp |= (pin_c4 <<7);

	switch(temp)
	{
		case 0b11100000:
			return KEYPAD_u8R3C1_KEY;
		case 0b11010000:
			return KEYPAD_u8R3C2_KEY;
		case 0b10110000:
			return KEYPAD_u8R3C3_KEY;
		case 0b01110000:
			return KEYPAD_u8R3C4_KEY;
	}


	Dio_vidSetPinval(KEYPAD_u8R1_PIN , DIO_u8HIGH);
	Dio_vidSetPinval(KEYPAD_u8R2_PIN , DIO_u8HIGH);
	Dio_vidSetPinval(KEYPAD_u8R3_PIN , DIO_u8HIGH);
	Dio_vidSetPinval(KEYPAD_u8R4_PIN , DIO_u8LOW);


	pin_c1 = Dio_u8GetPinVal(KEYPAD_u8C1_PIN);
	pin_c2 = Dio_u8GetPinVal(KEYPAD_u8C2_PIN);
	pin_c3 = Dio_u8GetPinVal(KEYPAD_u8C3_PIN);
	pin_c4 = Dio_u8GetPinVal(KEYPAD_u8C4_PIN);

	temp = 0;
	temp |= (pin_c1 <<4);
	temp |= (pin_c2 <<5);
	temp |= (pin_c3 <<6);
	temp |= (pin_c4 <<7);

	switch(temp)
	{
		case 0b11100000:
			return KEYPAD_u8R4C1_KEY;
		case 0b11010000:
			return KEYPAD_u8R4C2_KEY;
		case 0b10110000:
			return KEYPAD_u8R4C3_KEY;
		case 0b01110000:
			return KEYPAD_u8R4C4_KEY;
	}


	return KEYPAD_u8NO_KEY;
	}

