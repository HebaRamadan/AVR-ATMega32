/*
 * TIMER2_prg.c
 *
 *  Created on: Mar 23, 2020
 *      Author: zas
 */

#include "../Lib/Std_types.h"
#include "Timer2_cfg.h"
#include "Timer2_int.h"
#include "Timer2_priv.h"

void(*Pfun_OVF)(void);
void(*Pfun_CMP)(void);

void Timer2_vidInit(void)
{

#if TIMER2_u8WFG_MODE == TIMER2_u8NORMAL_MODE
	//Select Normal Mode
	TCCR2.Bits.WGM20 = 0;
	TCCR2.Bits.WGM21 = 0;
#elif TIMER2_u8WFG_MODE == TIMER2_u8CTC_MODE
	//Select compare timer
	TCCR2.Bits.WGM20 = 0;
	TCCR2.Bits.WGM21 = 1;
#elif TIMER2_u8WFG_MODE == TIMER2_u8FAST_PWM_MODE
	//Select compare fast PWM mode
	TCCR2.Bits.WGM20 = 1;
	TCCR2.Bits.WGM21 = 1;
#endif


#if TIMER2_u8COMPARE_MATCH_OUTPUT_MODE == TIMER2_u8OC2_DISCONNECTED
	//Select OCR1 disconnected (NO_COMPARE_MATCH)
	TCCR2.Bits.COM = 0;
#elif TIMER2_u8COMPARE_MATCH_OUTPUT_MODE == TIMER2_u8TOGGLE_OC2_ON_CM
	//Select toggle output at OCR2 compare match value
	TCCR2.Bits.COM = 1;
#elif TIMER2_u8COMPARE_MATCH_OUTPUT_MODE == TIMER2_u8CLEAR_OC2_ON_CM
	//Select clear output at OCR2 compare match value
	TCCR2.Bits.COM = 2;
#elif TIMER2_u8COMPARE_MATCH_OUTPUT_MODE == TIMER2_u8SET_OC2_ON_CM
	//Select set output at OCR2 compare match value
	TCCR2.Bits.COM = 3;
#elif TIMER2_u8COMPARE_MATCH_OUTPUT_MODE == TIMER2_u8CLEAR_OC2_ON_CM_SET_ON_TOP
	//Select clear output at OCR2 compare match value and set at register overflow
	TCCR2.Bits.COM = 2;
#elif TIMER2_u8COMPARE_MATCH_OUTPUT_MODE == TIMER2_u8SET_OC2_ON_CM_CLEAR_ON_TOP
	//Select set output at OCR2 compare match value and clear at register overflow
	TCCR2.Bits.COM = 3;
#endif

#if TIMER2_u8PRESCALLER_VALU == TIMER2_u8FCPU_1
	//Select No Pre_scalling
	TCCR2.Bits.CS = 1;
#elif TIMER2_u8PRESCALLER_VALU == TIMER2_u8FCPU_8
	//Select Pre_scaller with 8
	TCCR2.Bits.CS = 2;
#elif TIMER2_u8PRESCALLER_VALU == TIMER2_u8FCPU_64
	//Select Pre_scaller with 64
	TCCR2.Bits.CS = 3;
#elif TIMER2_u8PRESCALLER_VALU == TIMER2_u8FCPU_256
	//Select Pre_scaller with 256
	TCCR2.Bits.CS = 4;
#elif TIMER2_u8PRESCALLER_VALU == TIMER2_u8FCPU_1024
	//Select Pre_scaller with 1024
	TCCR2.Bits.CS = 5;
#elif TIMER2_u8PRESCALLER_VALU == TIMER2_u8FCPU_EXTERNAL_CLK_FALLING
	//Select External CLK on T2 (clock on falling edge)
	TCCR2.Bits.CS = 6;
#elif TIMER2_u8PRESCALLER_VALU == TIMER2_u8FCPU_EXTERNAL_CLK_RISING
	//Select External CLK on T2 (clock on rising edge)
	TCCR2.Bits.CS = 7;
#endif

#if TIMER2_u8OVF_INTERRUPT == TIMER2_u8OVF_INTERRUPT_ENABLE
	//PIE of TIMER2 at overflow of counter register
	SREG.Bits.I_bit  =  1;
	TIMSK.Bits.TOIE2 =  1;
#elif TIMER2_u8OVF_INTERRUPT == TIMER2_u8OVF_INTERRUPT_DISABLE
	//disable interrupt TIMER2 at overflow of counter register
	TIMSK.Bits.TOIE2 =  0;
#endif

#if TIMER2_u8CMP_INTERRUPT == TIMER2_u8CMP_INTERRUPT_ENABLE
	//PIE of TIMER2 at Compare Match Output Register
	SREG.Bits.I_bit  =  1;
	TIMSK.Bits.OCIE2 =  1;
#elif TIMER2_u8CMP_INTERRUPT == TIMER2_u8CMP_INTERRUPT_DISABLE
	//disable interrupt TIMER2 at Compare Match Output Register
	TIMSK.Bits.OCIE2 =  0;
#endif
}

void Timer2_vidStopTimer(void)
{
	//Stop Timer (NO Clock Source)
	TCCR2.Bits.CS = 0;
}

void Timer2_vidSetCounterRegisterValue(u8 Val)
{
	//Set Value In Timer Counter Register	 (TCNT2)
	TCNT2.Byte = Val;
}

void Timer2_vidSetCompareRegisterValue(u8 Val)
{
	//Set Value Of Timer Compare Match Register (OCR2)
	OCR2.Byte = Val;
}


void CMP_vidTimer2SetCB(void(*pf)(void))
{
	Pfun_CMP = pf;
}


void OVF_vidTimer2SetCB(void(*pf)(void))
{
	Pfun_OVF = pf;
}


void __vector_4 (void)
{
	Pfun_CMP();
}

void __vector_5 (void)
{
	Pfun_OVF();
}
