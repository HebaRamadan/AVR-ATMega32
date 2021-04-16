/*
 * SevenSeg_prg.c
 *
 *  Created on: Feb 28, 2020
 *      Author: zas
 */
#include "../lib/Std_types.h"
#include "../Lib/Bit_math.h"
#include "Dio_int.h"
#include "SevenSeg_cfg.h"
#include "SevenSeg_int.h"

void SevenSeg_vidInit(u8 ID)
{
	switch(ID)
	{
		case 0:    //Initial Right SevenSeg as OUTPUT
			 Dio_vidSetPinDir(SEVENSEG_R_u8PIN_A , DIO_u8OUTPUT);
			 Dio_vidSetPinDir(SEVENSEG_R_u8PIN_B , DIO_u8OUTPUT);
			 Dio_vidSetPinDir(SEVENSEG_R_u8PIN_C , DIO_u8OUTPUT);
			 Dio_vidSetPinDir(SEVENSEG_R_u8PIN_D , DIO_u8OUTPUT);
			 Dio_vidSetPinDir(SEVENSEG_R_u8PIN_E , DIO_u8OUTPUT);
			 Dio_vidSetPinDir(SEVENSEG_R_u8PIN_F , DIO_u8OUTPUT);
			 Dio_vidSetPinDir(SEVENSEG_R_u8PIN_G , DIO_u8OUTPUT);
		break;

		case 1:    //Initial Left SevenSeg as OUTPUT
			 Dio_vidSetPinDir(SEVENSEG_L_u8PIN_A , DIO_u8OUTPUT);
			 Dio_vidSetPinDir(SEVENSEG_L_u8PIN_B , DIO_u8OUTPUT);
			 Dio_vidSetPinDir(SEVENSEG_L_u8PIN_C , DIO_u8OUTPUT);
			 Dio_vidSetPinDir(SEVENSEG_L_u8PIN_D , DIO_u8OUTPUT);
			 Dio_vidSetPinDir(SEVENSEG_L_u8PIN_E , DIO_u8OUTPUT);
			 Dio_vidSetPinDir(SEVENSEG_L_u8PIN_F , DIO_u8OUTPUT);
			 Dio_vidSetPinDir(SEVENSEG_L_u8PIN_G , DIO_u8OUTPUT);
		break;
	}
}


void SevenSeg_vidTurnOn(u8 ID)
{
	switch(ID)
	{
		case 0: //display 0 on Right seven segment
			 Dio_vidSetPinval(SEVENSEG_R_u8PIN_A , DIO_u8LOW);
			 Dio_vidSetPinval(SEVENSEG_R_u8PIN_B , DIO_u8LOW);
			 Dio_vidSetPinval(SEVENSEG_R_u8PIN_C , DIO_u8LOW);
			 Dio_vidSetPinval(SEVENSEG_R_u8PIN_D , DIO_u8LOW);
			 Dio_vidSetPinval(SEVENSEG_R_u8PIN_E , DIO_u8LOW);
			 Dio_vidSetPinval(SEVENSEG_R_u8PIN_F , DIO_u8LOW);
			 Dio_vidSetPinval(SEVENSEG_R_u8PIN_G , DIO_u8HIGH);
		break;

		case 1: //display 0 on Left seven segment
			 Dio_vidSetPinval(SEVENSEG_L_u8PIN_A , DIO_u8LOW);
			 Dio_vidSetPinval(SEVENSEG_L_u8PIN_B , DIO_u8LOW);
			 Dio_vidSetPinval(SEVENSEG_L_u8PIN_C , DIO_u8LOW);
			 Dio_vidSetPinval(SEVENSEG_L_u8PIN_D , DIO_u8LOW);
			 Dio_vidSetPinval(SEVENSEG_L_u8PIN_E , DIO_u8LOW);
			 Dio_vidSetPinval(SEVENSEG_L_u8PIN_F , DIO_u8LOW);
			 Dio_vidSetPinval(SEVENSEG_L_u8PIN_G , DIO_u8HIGH);
		break;
	}
}
void SevenSeg_vidTurnOff(u8 ID)
{
	switch(ID)
	{
		case 0: //don't display any thing on Right seven segment
			 Dio_vidSetPinval(SEVENSEG_R_u8PIN_A , DIO_u8HIGH);
			 Dio_vidSetPinval(SEVENSEG_R_u8PIN_B , DIO_u8HIGH);
			 Dio_vidSetPinval(SEVENSEG_R_u8PIN_C , DIO_u8HIGH);
			 Dio_vidSetPinval(SEVENSEG_R_u8PIN_D , DIO_u8HIGH);
			 Dio_vidSetPinval(SEVENSEG_R_u8PIN_E , DIO_u8HIGH);
			 Dio_vidSetPinval(SEVENSEG_R_u8PIN_F , DIO_u8HIGH);
			 Dio_vidSetPinval(SEVENSEG_R_u8PIN_G , DIO_u8HIGH);
		break;

		case 1: //don't display any thing on Left seven segment
			 Dio_vidSetPinval(SEVENSEG_L_u8PIN_A , DIO_u8HIGH);
			 Dio_vidSetPinval(SEVENSEG_L_u8PIN_B , DIO_u8HIGH);
			 Dio_vidSetPinval(SEVENSEG_L_u8PIN_C , DIO_u8HIGH);
			 Dio_vidSetPinval(SEVENSEG_L_u8PIN_D , DIO_u8HIGH);
			 Dio_vidSetPinval(SEVENSEG_L_u8PIN_E , DIO_u8HIGH);
			 Dio_vidSetPinval(SEVENSEG_L_u8PIN_F , DIO_u8HIGH);
			 Dio_vidSetPinval(SEVENSEG_L_u8PIN_G , DIO_u8HIGH);
		break;
	}
}


void SevenSeg_vidDisplayNum(u8 ID , u8 NUM)
{
	u8 Seg[10] = {0b1000000, 0b1111001, 0b0100100, 0b0110000, 0b0011001, 0b0010010, 0b0000010, 0b1111000, 0b0000000, 0b0010000};
	u8 temp;

	temp = Seg[NUM]; //select temp register to store bits which represent number to display

	switch(ID)
	{
		case 0: //now apply these bits on pins of seven segment to display num
			 Dio_vidSetPinval(SEVENSEG_R_u8PIN_A , GET_BIT(temp , 0));
			 Dio_vidSetPinval(SEVENSEG_R_u8PIN_B , GET_BIT(temp , 1));
			 Dio_vidSetPinval(SEVENSEG_R_u8PIN_C , GET_BIT(temp , 2));
			 Dio_vidSetPinval(SEVENSEG_R_u8PIN_D , GET_BIT(temp , 3));
			 Dio_vidSetPinval(SEVENSEG_R_u8PIN_E , GET_BIT(temp , 4));
			 Dio_vidSetPinval(SEVENSEG_R_u8PIN_F , GET_BIT(temp , 5));
			 Dio_vidSetPinval(SEVENSEG_R_u8PIN_G , GET_BIT(temp , 6));
		break;

		case 1:
			 Dio_vidSetPinval(SEVENSEG_L_u8PIN_A , GET_BIT(temp , 0));
			 Dio_vidSetPinval(SEVENSEG_L_u8PIN_B , GET_BIT(temp , 1));
			 Dio_vidSetPinval(SEVENSEG_L_u8PIN_C , GET_BIT(temp , 2));
			 Dio_vidSetPinval(SEVENSEG_L_u8PIN_D , GET_BIT(temp , 3));
			 Dio_vidSetPinval(SEVENSEG_L_u8PIN_E , GET_BIT(temp , 4));
			 Dio_vidSetPinval(SEVENSEG_L_u8PIN_F , GET_BIT(temp , 5));
			 Dio_vidSetPinval(SEVENSEG_L_u8PIN_G , GET_BIT(temp , 6));
		break;
	}

}
