/*
 * Adc_prg.c
 *
 *  Created on: Mar 10, 2020
 *  Author      : Heba Ramadan Taha
 */
 
#include "../Lib/Std_types.h"
#include "Adc_cfg.h"
#include "Adc_priv.h"
#include "Adc_int.h"

//define global variable to save conversion result (Polling or Interrupt)
#if ADC_ADJUST_VALUE == ADC_RIGHT_ADJUST
	u16 Result;

#elif ADC_VREF_VALUE == ADC_LEFT_ADJUST
	u8 Result;
#endif


void Adc_vidInit(void)
{
	#if ADC_u8REF_VOLT == ADC_u8AREF
	/* Select AREF pin as reference voltage */
		ADMUX.Bits.REFS = 0;
	#elif ADC_u8REF_VOLT == ADC_u8AVCC
	/* Select AVCC as reference voltage */
		ADMUX.Bits.REFS = 1;
	#elif ADC_u8REF_VOLT == ADC_u8_2_56V
	/* Select internal 2.56V as reference voltage */
		ADMUX.Bits.REFS = 3;

	#endif


	#if ADC_u8RESULT_ADJUST == ADC_u8RIGHT_ADJUST
	/* Select Right adjustment */
		ADMUX.Bits.ADLAR = 0;
	#elif ADC_ADJUST_VALUE == ADC_LEFT_ADJUST
	/* Select Left adjustment */
		ADMUX.Bits.ADLAR = 1;
	#endif

	/* initialize with ADC0 */
		ADMUX.Bits.MUX = 0;

	#if ADC_u8AUTO_TRIGGER == ADC_u8TRIGGER_SOURCE_DISABLED
	/* Disable AUTO Trigger */
		ADCSRA.Bits.ADATE = 0;
	#elif ADC_u8AUTO_TRIGGER == ADC_u8TRIGGER_SOURCE_FREE_RUN
	/* Enable AUTO Trigger */
		ADCSRA.Bits.ADATE = 1;

	/* Select Free Run as AUTO Trigger */
		SFIOR.Bits.ADTS = 0;

	#elif ADC_u8AUTO_TRIGGER == ADC_u8TRIGGER_SOURCE_ANALOG_COMP
	/* Enable AUTO Trigger */
		ADCSRA.Bits.ADATE = 1;

	/* Select Analog Comparator as AUTO Trigger */
		SFIOR.Bits.ADTS = 1;

	#elif ADC_u8AUTO_TRIGGER == ADC_u8TRIGGER_SOURCE_EXTERNAL_INT
	/* Enable AUTO Trigger */
		ADCSRA.Bits.ADATE = 1;

	/* Select External Interrupt as AUTO Trigger */
		SFIOR.Bits.ADTS = 2;

	#elif ADC_u8AUTO_TRIGGER == ADC_u8TRIGGER_SOURCE_TIMER0_CM
	/* Enable AUTO Trigger */
		ADCSRA.Bits.ADATE = 1;

	/* Select Timer0 Compare Match A as AUTO Trigger */
		SFIOR.Bits.ADTS = 3;

	#elif ADC_u8AUTO_TRIGGER == ADC_u8TRIGGER_SOURCE_TIMER0_OVERFLOW
	/* Enable AUTO Trigger */
		ADCSRA.Bits.ADATE = 1;

	/* Select Timer0 Overflow as AUTO Trigger */
		SFIOR.Bits.ADTS = 4;

	#elif ADC_u8AUTO_TRIGGER == ADC_u8TRIGGER_SOURCE_TIMER_CM_B
	/* Enable AUTO Trigger */
		ADCSRA.Bits.ADATE = 1;

	/* Select Timer0 Compare Match B as AUTO Trigger */
		SFIOR.Bits.ADTS = 5;

	#elif ADC_u8AUTO_TRIGGER == AADC_u8TRIGGER_SOURCE_TIMER1_OVERFLOW
	/* Enable AUTO Trigger */
		ADCSRA.Bits.ADATE = 1;

	/* Select Timer1 Overflow as AUTO Trigger */
		SFIOR.Bits.ADTS = 6;

	#elif ADC_u8AUTO_TRIGGER == ADC_u8TRIGGER_SOURCE_TIMER1_CAP_INPUT
	/* Enable AUTO Trigger */
		ADCSRA.Bits.ADATE = 1;

	/* Select Timer1 Input Capture as AUTO Trigger */
		SFIOR.Bits.ADTS = 7;
	#endif


	/* Enable ADC module */
		ADCSRA.Bits.ADEN= 1;

	/* Disable start conversion */
		ADCSRA.Bits.ADSC = 0;


	/* Clear ADIF Flag */
		ADCSRA.Bits.ADIF = 1;

	#if ADC_u8IMPLEMENTATION_BASED == ADC_u8POLLING_BASED
		/*Disable ADC interrupt*/
		ADCSRA.Bits.ADIE = 0;

	#elif  ADC_u8IMPLEMENTATION_BASED == ADC_u8INTERRUPT_BASED
		/*global Interrupt Enable*/
		SREG.Bits.I_bit = 1;

		/*Enable ADC interrupt*/
		ADCSRA.Bits.ADIE = 1;
	#endif


	#if ADC_u8PRESCALLER_VALUE == ADC_u8FCPU_2
	/* Select division factor with 2 */
		ADCSRA.Bits.ADPS = 1;

	#elif ADC_u8PRESCALLER_VALUE == ADC_u8FCPU_4
	/* Select division factor with 4 */
		ADCSRA.Bits.ADPS = 2;

	#elif ADC_u8PRESCALLER_VALUE == ADC_u8FCPU_8
	/* Select division factor with 8 */
		ADCSRA.Bits.ADPS = 3;

	#elif ADC_u8PRESCALLER_VALUE == ADC_u8FCPU_16
	/* Select division factor by 16 */
		ADCSRA.Bits.ADPS = 4;

	#elif ADC_u8PRESCALLER_VALUE == ADC_u8FCPU_32
	/* Select division factor by 32 */
		ADCSRA.Bits.ADPS = 5;

	#elif ADC_u8PRESCALLER_VALUE == ADC_u8FCPU_64
	/* Select division factor by 64 */
		ADCSRA.Bits.ADPS = 6;

	#elif ADC_u8PRESCALLER_VALUE == ADC_u8FCPU_128
	/* Select division factor by 128 */
		ADCSRA.Bits.ADPS = 7;
	#endif
}


#if ADC_u8RESULT_ADJUST == ADC_u8RIGHT_ADJUST
	u16 Adc_u16GetResult(u8 Chnl_Id)

#elif ADC_u8RESULT_ADJUST == ADC_u8LEFT_ADJUST
	u8 Adc_u8GetResult(u8 Chnl_Id)

#endif
{

	//select channel
	ADMUX.Bits.MUX = Chnl_Id;


	#if ADC_u8IMPLEMENTATION_BASED == ADC_u8POLLING_BASED
		//start conversion
		ADCSRA.Bits.ADSC = 1;

		//check ADIF
		while( (ADCSRA.Bits.ADIF) == 0 );

		//clear ADIF
		ADCSRA.Bits.ADIF = 1;

		//get result from ADCL & ADCH
		#if ADC_ADJUST_VALUE == ADC_RIGHT_ADJUST
			Result  = 0;
			Result  = ADCL.Byte;
			Result |= (ADCH.Byte<<8);

		#elif ADC_VREF_VALUE == ADC_LEFT_ADJUST
			Result  = 0;
			Result  = ADCH.Byte;
		#endif


	#elif  ADC_u8IMPLEMENTATION_BASED == ADC_u8INTERRUPT_BASED
		//start conversion
		ADCSRA.Bits.ADSC = 1;

	#endif

	return Result;

}

void __vector_16 (void)
{
	//get result from ADCL & ADCH
	#if ADC_ADJUST_VALUE == ADC_RIGHT_ADJUST
		Result  = 0;
		Result  = ADCL.Byte;
		Result |= (ADCH.Byte<<8);

	#elif ADC_VREF_VALUE == ADC_LEFT_ADJUST
		Result  = 0;
		Result  = ADCH.Byte;
	#endif
}


