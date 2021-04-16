/*
 * Adc_prg.c
 *
 *  Created on: Feb 16, 2020
 *      Author: zas
 */
#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#include <avr/io.h>
#include "Adc_int.h"

void Adc_vidInit(void)
{
	CLR_BIT( ADMUX , 7 );
	SET_BIT( ADMUX , 6 );
	CLR_BIT( ADMUX , 5 );
	CLR_BIT( ADMUX , 4 );
	CLR_BIT( ADMUX , 3 );
	CLR_BIT( ADMUX , 2 );
	CLR_BIT( ADMUX , 1 );
	CLR_BIT( ADMUX , 0 );

	SET_BIT( ADCSRA , 7 );
	CLR_BIT( ADCSRA , 6 );
	CLR_BIT( ADCSRA , 5 );
	SET_BIT( ADCSRA , 4 );
	CLR_BIT( ADCSRA , 3 );
	CLR_BIT( ADCSRA , 2 );
	SET_BIT( ADCSRA , 1 );
	SET_BIT( ADCSRA , 0 );


}


u16 Adc_u16GetResult(u8 chnl_Id)
{
	u16 Result;
	ADMUX &= 0b11100000;
	ADMUX |= (chnl_Id & 0b00011111);
	SET_BIT( ADCSRA , 6);    //start conv
	while(GET_BIT(ADCSRA , 4) == 0);
	SET_BIT( ADCSRA , 4);
	Result = 0;
	Result = ADCL;
	Result |= (ADCH<<8);
	return Result;

}


