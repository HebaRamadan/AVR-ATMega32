/*
 * ADC_prg.c
 *
 *  Created on: Mar 1, 2020
 *      Author: zas
 */

#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#include <avr/io.h>
#include "Adc_int.h"

void Adc_vidInit(void)
{
	CLR_BIT( ADMUX , 7 );   //Vref
	SET_BIT( ADMUX , 6 );   //Vref
	CLR_BIT( ADMUX , 5 );   //Right adjust
	CLR_BIT( ADMUX , 4 );   //ADC0
	CLR_BIT( ADMUX , 3 );
	CLR_BIT( ADMUX , 2 );
	CLR_BIT( ADMUX , 1 );
	CLR_BIT( ADMUX , 0 );

	SET_BIT( ADCSRA , 7 );   //EN
	CLR_BIT( ADCSRA , 6 );   //SC (no conversion)
	CLR_BIT( ADCSRA , 5 );   //Auto Trigger (no interrupt)
	SET_BIT( ADCSRA , 4 );   //ADC interrupt flag(clear flag)
	CLR_BIT( ADCSRA , 3 );   //ADC interrupt Enable
	CLR_BIT( ADCSRA , 2 );   //ADC Prescaler(/8)
	SET_BIT( ADCSRA , 1 );
	SET_BIT( ADCSRA , 0 );


}


u16 Adc_u16GetResult(u8 chnl_Id)
{
	u16 Result;
	//select channel
	ADMUX &= 0b11100000;
	ADMUX |= (chnl_Id & 0b00011111);
	//start conversion
	SET_BIT( ADCSRA , 6);
	//check ADIF
	while(GET_BIT(ADCSRA , 4) == 0);
	//clear ADIF
	SET_BIT( ADCSRA , 4);
	//get result from ADCL & ADCH
	Result = 0;
	Result = ADCL;
	Result |= (ADCH<<8);
	return Result;

}

