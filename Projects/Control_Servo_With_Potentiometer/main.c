/*
 * main.c
 *
 *  Created on: Mar 1, 2020
 *      Author: zas
 */
#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#include "Adc_int.h"
#include "Servo_int.h"

int main(void)
{
	Adc_vidInit();
	Servo_vidInit();
	u16 Digital;
	u8  angle;
	while(1)
	{
		Digital = Adc_u16GetResult(ADC_u8CH_0);
		angle   = Digital * (198/1024);
		Servo_vidSetDegree(angle);
	}
	return 0;
}

