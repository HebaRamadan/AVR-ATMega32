/*
 * WDT.Prog.c
 *
 *  Created on: Dec 21, 2020
 *      Author: zas
 */
#include "Std_types.h"
#include "Bit_math.h"
#include "WDT.Private.h"


void WDT_vidEnable (void)
{
	SET_BIT( WDTCR , WDE);

	CLR_BIT( WDTCR , WDP0);
	SET_BIT( WDTCR , WDP1);
	SET_BIT( WDTCR , WDP2);
}

void WDT_vidDisable(void)
{
	WDTCR |= 0b00011000;
	WDTCR  = 0;
}

