/*
 * ADC_Program.c
 *
 *  Created on: Dec 7, 2020
 *      Author: zas
 */
#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"

#include "ADC_Private.h"
#include "ADC_Interface.h"

u8  flag = 0;
u16 Result;

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

	CLR_BIT( ADCSRA , 5 );   //Auto Trigger (no interrupt)

	SET_BIT( SREG   , 7 );   // Set global interrupt
	SET_BIT( ADCSRA , 4 );   //ADC interrupt flag(clear flag)
	SET_BIT( ADCSRA , 3 );   //ADC interrupt Enable

	CLR_BIT( ADCSRA , 2 );   //ADC Prescaler(/8)
	SET_BIT( ADCSRA , 1 );
	SET_BIT( ADCSRA , 0 );
}

u16 Adc_u16GetResult(void)
{


	//start conversion
	SET_BIT( ADCSRA , 6);


	return Result;

}

void __vector_16 (void)
{

	if(flag == 0)
	{
		ADMUX &= 0b11100000;
		ADMUX |= (Chnl_Id_1 & 0b00011111);
		Result  = 0;
		Result  = ADCL;
		Result |= (ADCH<<8);
		flag = 1;

	}
	else if(flag == 1)
	{
		ADMUX &= 0b11100000;
		ADMUX |= (Chnl_Id_0 & 0b00011111);
		Result  = 0;
		Result  = ADCL;
		Result |= (ADCH<<8);
		flag = 0;
		CLR_BIT( ADCSRA , 6);
	}


}
