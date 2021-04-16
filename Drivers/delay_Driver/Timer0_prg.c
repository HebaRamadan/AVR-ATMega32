/*
 * Timer0_prg.c
 *
 *  Created on: Mar 23, 2020
 *      Author: zas
 */

#include "../Lib/Std_types.h"
#include "Timer0_priv.h"
#include "Timer0_cfg.h"
#include "Timer0_int.h"
#include "delay_int.h"

u32 ovf_count;
u32 ms_counts;
u32 us_counts;
u32 T_desired;
u8 Var;
u8 End;


void Timer0_vidInit(void)
{
#if TIMER0_u8WFG_MODE == TIMER0_u8NORMAL_MODE
	//Select Normal Mode
	TCCR0.Bits.WGM00 = 0;
	TCCR0.Bits.WGM01 = 0;
#elif TIMER0_u8WFG_MODE == TIMER0_u8CTC_MODE
	//Select compare timer compare match
	TCCR0.Bits.WGM00 = 0;
	TCCR0.Bits.WGM01 = 1;
#elif TIMER0_u8WFG_MODE == TIMER0_u8PWM_MODE
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
	//PIE of TIMER0 at overflow of counter register
	SREG.Bits.I_bit  =  1;
	TIMSK.Bits.OCIE0 =  1;
#elif TIMER0_u8CMP_INTERRUPT == TIMER0_u8CMP_INTERRUPT_DISABLE
	//disable interrupt timer0 at overflow of counter register
	TIMSK.Bits.OCIE0 =  0;
#endif
}

void Timer0_vidStop(void)
{
	//NO Clock Source
	TCCR0.Bits.CS = 0;
}

void Timer0_vidSetCounterRegisterValue(u8 Val)
{
	TCNT0.Byte = Val;
}

void MyDelayFunc_ms(u32 Time)
{
	ovf_count = 0;
	ms_counts = 0;
	T_desired = Time;
	Var = 0;
	End = 0;
	//initialize timer counter to count 0.25msec
	Timer0_vidSetCounterRegisterValue(192);
	//Start Timer0
	Timer0_vidInit();
	//wait until complete Time
	while(End == 0);
	//stop timer 0
	Timer0_vidStop();
	//make TCNT0 = 0
	Timer0_vidSetCounterRegisterValue(0);
}

void MyDelayFunc_us(u32 Time)
{
	us_counts = 0;
	T_desired = Time;
	Var = 1;
	End = 0;
	//initialize timer counter to count only 8 counts which make 1usec
	Timer0_vidSetCounterRegisterValue(245);
	//Start Timer0
	Timer0_vidInit();
	//wait until complete Time
	while(End == 0);
	//stop timer 0
	Timer0_vidStop();
	//make TCNT0 = 0
	Timer0_vidSetCounterRegisterValue(0);
}


void __vector_11 (void)
{
	switch(Var)
	{
	case 0: //count msec
		ovf_count++;
	 	if(ovf_count == 32) //that's main we count 1msec
	 	{
	 		Timer0_vidSetCounterRegisterValue(192);   //Re-initial register
	 		ovf_count = 0;  //clear overflow counter to start again in new 1msec
	 		ms_counts++;    //number of msecs which counted
	 		if(ms_counts == T_desired)
	 		{
	 			End =1;
	 		}
	 	}
	break;

	case 1: //count usec
		//that's main we count 1usec
		Timer0_vidSetCounterRegisterValue(245);  //Re-initial register to start another usec
		us_counts++;
		if(us_counts == T_desired)
		{
			End =1;
		}
	break;
	}

}
