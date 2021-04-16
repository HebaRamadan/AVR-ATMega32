/*
 * Timer0_Prog.c
 *
 *  Created on: Dec 15, 2020
 *      Author: zas
 */
#include "Std_types.h"
#include "Bit_math.h"
#include "Timer0_Config.h"
#include "Timer0_Private.h"

#include "DIO_Interface.h"

u16 OVF_Counter;

void Timer0_vidInit(void)
{
#if TIMER0_u8PRESCALLER_VALU   == TIMER0_u8FCPU_1
	//Select No Pre_scalling
	TCCR0 = 1;
#elif TIMER0_u8PRESCALLER_VALU == TIMER0_u8FCPU_8
	//Select Pre_scaller with 8
	TCCR0 = 2;
#elif TIMER0_u8PRESCALLER_VALU == TIMER0_u8FCPU_64
	//Select Pre_scaller with 64
	TCCR0S = 3;
#elif TIMER0_u8PRESCALLER_VALU == TIMER0_u8FCPU_256
	//Select Pre_scaller with 256
	TCCR0 = 4;
#elif TIMER0_u8PRESCALLER_VALU == TIMER0_u8FCPU_1024
	//Select Pre_scaller with 1024
	TCCR0 = 5;
#elif TIMER0_u8PRESCALLER_VALU == TIMER0_u8FCPU_EXTERNAL_CLK_FALLING
	//Select External CLK on T0 (clock on falling edge)
	TCCR0 = 6;
#elif TIMER0_u8PRESCALLER_VALU == TIMER0_u8FCPU_EXTERNAL_CLK_RISING
	//Select External CLK on T0 (clock on rising edge)
	TCCR0 = 7;
#endif

#if TIMER0_u8WFG_MODE == TIMER0_u8NORMAL_MODE
	//Select Normal Mode
	CLR_BIT(TCCR0 , WGM00);
	CLR_BIT(TCCR0 , WGM01);
	//PIE of TIMER0 at overflow of counter register
	SET_BIT(TIMSK , TOIE0);
	//Initial TCNT0 Register
	TCNT0 = TIMER0_u8PRELOAD;
#elif TIMER0_u8WFG_MODE == TIMER0_u8CTC_MODE
	//Select compare timer
	CLR_BIT(TCCR0 , WGM00);
	SET_BIT(TCCR0 , WGM01);

	//PIE of TIMER0 at Compare Match Output Register
	SET_BIT(TIMSK , OCIE0)
	//Initial OCR0 Register
	OCR0 = TIMER0_u8PRELOAD;
#endif

}

void GIE_vidEnable(void)
{
	SET_BIT(SREG ,7);
}
void GIE_vidDisable(void)
{
	CLR_BIT(SREG ,7);
}

void __vector_10 (void)
{
	OVF_Counter++;
	if( OVF_Counter == TIMER0_u16OVFCOUNTER )
	{
		DIO_vidTogglePin(PortA , PIN_0);
		OVF_Counter = 0;
	}
}

void __vector_11 (void)
{
	OVF_Counter++;

	if(OVF_Counter == TIMER0_u16OVFCOUNTER)
	{
		//Initial register for next 2sec
		TCNT0 = TIMER0_u8PRELOAD;
		DIO_vidTogglePin(PortA , PIN_0);
		OVF_Counter = 0;
	}
}
