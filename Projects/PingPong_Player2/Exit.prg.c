/*
 * Exit.prg.c
 *
 *  Created on: Dec 6, 2020
 *      Author: zas
 */

#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>
#include "Exit_Private.h"

u8 Flag_INT = 0;

void IN0_vidInit(void)
{

	SET_BIT(SREG  , 7);     //GIE
	SET_BIT(GICR  , 6);     //PIE
	CLR_BIT(MCUCR , 1);     //low level
	CLR_BIT(MCUCR , 0);
}

/*void IN1_vidInit(void)
{

	SET_BIT(SREG  , 7);     //GIE
	SET_BIT(GICR  , 6);     //PIE
	CLR_BIT(MCUCR , 1);     //low level
	CLR_BIT(MCUCR , 0);
}*/

void __vector_1 (void)
{
	static u8 counter = 0;

	if(counter == 1)
	{
		Flag_INT = 1;
		counter = 0;
	}
	counter++;
}
