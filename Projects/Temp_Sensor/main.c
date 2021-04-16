/*
 * main.c
 *
 *  Created on: Feb 28, 2020
 *      Author: zas
 */
#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#include "Adc_int.h"
#include "SevenSeg_int.h"

int main()
{
	SevenSeg_vidInit( RIGHT_SEVENSEG );
	SevenSeg_vidInit( LEFT_SEVENSEG );
	SevenSeg_vidTurnOn( RIGHT_SEVENSEG);
	SevenSeg_vidTurnOn( LEFT_SEVENSEG);
	Adc_vidInit();
	u16 Digital;
	u8 Analog;

	while(1)
	{
		Digital = Adc_u16GetResult(ADC_u8CH_0);
		Analog  = (Digital * 500)/1024 ;
		SevenSeg_vidDisplayNum(RIGHT_SEVENSEG , (Analog%10));
		SevenSeg_vidDisplayNum(LEFT_SEVENSEG  , (Analog/10));

	}
	return 0;

}


