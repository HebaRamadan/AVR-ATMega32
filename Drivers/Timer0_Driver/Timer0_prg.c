/*
 * Timer0_prg.c
 *
 *  Created on: Mar 23, 2020
 *      Author: zas
 */

#include "../Lib/Std_types.h"
#include "Dio_int.h"
#include "Timer0_priv.h"
#include "Timer0_cfg.h"
#include "Timer0_int.h"

void(*Pfun_OVF)(void);
void(*Pfun_CMP)(void);

void Timer0_vidInit(void)
{
#if TIMER0_u8WFG_MODE == TIMER0_u8NORMAL_MODE
	//Select Normal Mode
	TCCR0.Bits.WGM00 = 0;
	TCCR0.Bits.WGM01 = 0;
#elif TIMER0_u8WFG_MODE == TIMER0_u8CTC_MODE
	//Select compare timer
	TCCR0.Bits.WGM00 = 0;
	TCCR0.Bits.WGM01 = 1;
#elif TIMER0_u8WFG_MODE == TIMER0_u8FAST_PWM_MODE
	//Initial Timer0 PIN
	Dio_vidSetPinDir(DIO_u8PIN_11 , DIO_u8OUTPUT);
	//Select compare fast PWM mode
	TCCR0.Bits.WGM00 = 1;
	TCCR0.Bits.WGM01 = 1;
#endif


#if TIMER0_u8COMPARE_MATCH_OUTPUT_MODE == TIMER0_u8OC0_DISCONNECTED
	//Select OCR0 disconnected (NO_COMPARE_MATCH)
	TCCR0.Bits.COM = 0;
#elif TIMER0_u8COMPARE_MATCH_OUTPUT_MODE == TIMER0_u8TOGGLE_OC0_ON_CM
	//Select toggle output at OCR0 compare match value
	TCCR0.Bits.COM = 1;
#elif TIMER0_u8COMPARE_MATCH_OUTPUT_MODE == TIMER0_u8CLEAR_OC0_ON_CM
	//Select clear output at OCR0 compare match value
	TCCR0.Bits.COM = 2;
#elif TIMER0_u8COMPARE_MATCH_OUTPUT_MODE == TIMER0_u8SET_OC0_ON_CM
	//Select set output at OCR0 compare match value
	TCCR0.Bits.COM = 3;
#elif TIMER0_u8COMPARE_MATCH_OUTPUT_MODE == TIMER0_u8CLEAR_OC0_ON_CM_SET_ON_TOP
	//Select clear output at OCR0 compare match value and set at register overflow
	TCCR0.Bits.COM = 2;
#elif TIMER0_u8COMPARE_MATCH_OUTPUT_MODE == TIMER0_u8SET_OC0_ON_CM_CLEAR_ON_TOP
	//Select set output at OCR0 compare match value and clear at register overflow
	TCCR0.Bits.COM = 3;
#endif

#if TIMER0_u8PRESCALLER_VALU == TIMER0_u8FCPU_1
	//Select No Pre_scalling
	TCCR0.Bits.CS = 1;
#elif TIMER0_u8PRESCALLER_VALU == TIMER0_u8FCPU_8
	//Select Pre_scaller with 8
	TCCR0.Bits.CS = 2;
#elif TIMER0_u8PRESCALLER_VALU == TIMER0_u8FCPU_64
	//Select Pre_scaller with 64
	TCCR0.Bits.CS = 3;
#elif TIMER0_u8PRESCALLER_VALU == TIMER0_u8FCPU_256
	//Select Pre_scaller with 256
	TCCR0.Bits.CS = 4;
#elif TIMER0_u8PRESCALLER_VALU == TIMER0_u8FCPU_1024
	//Select Pre_scaller with 1024
	TCCR0.Bits.CS = 5;
#elif TIMER0_u8PRESCALLER_VALU == TIMER0_u8FCPU_EXTERNAL_CLK_FALLING
	//Select External CLK on T0 (clock on falling edge)
	TCCR0.Bits.CS = 6;
#elif TIMER0_u8PRESCALLER_VALU == TIMER0_u8FCPU_EXTERNAL_CLK_RISING
	//Select External CLK on T0 (clock on rising edge)
	TCCR0.Bits.CS = 7;
#endif

#if TIMER0_u8OVF_INTERRUPT == TIMER0_u8OVF_INTERRUPT_ENABLE
	//PIE of TIMER0 at overflow of counter register
	SREG.Bits.I_bit  =  1;
	TIMSK.Bits.TOIE0 =  1;
#elif TIMER0_u8OVF_INTERRUPT == TIMER0_u8OVF_INTERRUPT_DISABLE
	//disable interrupt timer0 at overflow of counter register
	TIMSK.Bits.TOIE0 =  0;
#endif

#if TIMER0_u8CMP_INTERRUPT == TIMER0_u8CMP_INTERRUPT_ENABLE
	//PIE of TIMER0 at Compare Match Output Register
	SREG.Bits.I_bit  =  1;
	TIMSK.Bits.OCIE0 =  1;
#elif TIMER0_u8CMP_INTERRUPT == TIMER0_u8CMP_INTERRUPT_DISABLE
	//disable interrupt timer0 at Compare Match Output Register
	TIMSK.Bits.OCIE0 =  0;
#endif
}

void Timer0_vidStopTimer(void)
{
	//Stop Timer (NO Clock Source)
	TCCR0.Bits.CS = 0;
}

void Timer0_vidSetCounterRegisterValue(u8 Val)
{
	//Set Value In Timer Counter Register	 (TCNT0)
	TCNT0.Byte = Val;
}

void Timer0_vidSetCompareRegisterValue(u8 Val)
{
	//Set Value Of Timer Compare Match Register (OCR0)
	OCR0.Byte = Val;
}


void CMP_vidSetCB(void(*pf)(void))
{
	Pfun_CMP = pf;
}


void OVF_vidSetCB(void(*pf)(void))
{
	Pfun_OVF = pf;
}


void __vector_10 (void)
{
	Pfun_CMP();
}

void __vector_11 (void)
{
	Pfun_OVF();
}
