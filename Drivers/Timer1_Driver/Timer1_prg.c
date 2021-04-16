/*
 * Timer1_prg.c
 *
 *  Created on: Mar 25, 2020
 *      Author: zas
 */

#include "../Lib/Std_types.h"
#include "Timer1_priv.h"
#include "Timer1_cfg.h"
#include "Timer1_int.h"

void(*Pfun_OVF)(void);
void(*Pfun_CMPA)(void);
void(*Pfun_CMPB)(void);
void(*Pfun_CAPT)(void);


void Timer1_vidInit(void)
{
//Select Waveform Generation Mode
#if TIMER1_u8WFG_MODE == TIMER1_u8NORMAL_MODE
	//Select Normal Mode
	TCCR1A.Bits.WGM10 = 0;
	TCCR1A.Bits.WGM11 = 0;
	TCCR1B.Bits.WGM12 = 0;
	TCCR1B.Bits.WGM13 = 0;

#elif TIMER1_u8WFG_MODE == TIMER1_u8CTC_MODE_TOP_OCR1
	//Select CTC Mode With OCR1 AS TOP Register
	TCCR1A.Bits.WGM10 = 0;
	TCCR1A.Bits.WGM11 = 0;
	TCCR1B.Bits.WGM12 = 1;
	TCCR1B.Bits.WGM13 = 0;

#elif TIMER1_u8WFG_MODE == TIMER1_u8CTC_MODE_TOP_ICR1
	//Select CTC Mode With ICR1 AS TOP Register
	TCCR1A.Bits.WGM10 = 0;
	TCCR1A.Bits.WGM11 = 0;
	TCCR1B.Bits.WGM12 = 1;
	TCCR1B.Bits.WGM13 = 1;

#elif TIMER1_u8WFG_MODE == TIMER1_u8FAST_PWM_MODE_8BIT
	//Select Fast PWM Mode With 8_BIT Counter Register MAX_COUNT(0 -> 255)
	TCCR1A.Bits.WGM10 = 1;
	TCCR1A.Bits.WGM11 = 0;
	TCCR1B.Bits.WGM12 = 1;
	TCCR1B.Bits.WGM13 = 0;

#elif TIMER1_u8WFG_MODE == TIMER1_u8FAST_PWM_MODE_9BIT
	//Select Fast PWM Mode With 9_BIT Counter Register MAX_COUNT(0 -> 511)
	TCCR1A.Bits.WGM10 = 0;
	TCCR1A.Bits.WGM11 = 1;
	TCCR1B.Bits.WGM12 = 1;
	TCCR1B.Bits.WGM13 = 0;

#elif TIMER1_u8WFG_MODE == TIMER1_u8FAST_PWM_MODE_10BIT
	//Select Fast PWM Mode With 10_BIT Counter Register MAX_COUNT(0 -> 1023)
	TCCR1A.Bits.WGM10 = 1;
	TCCR1A.Bits.WGM11 = 1;
	TCCR1B.Bits.WGM12 = 1;
	TCCR1B.Bits.WGM13 = 0;

#elif TIMER1_u8WFG_MODE == TIMER1_u8FAST_PWM_MODE_TOP_ICR1
	//Select Fast PWM Mode With ICR1 AS TOP Register
	TCCR1A.Bits.WGM10 = 0;
	TCCR1A.Bits.WGM11 = 1;
	TCCR1B.Bits.WGM12 = 1;
	TCCR1B.Bits.WGM13 = 1;

#elif TIMER1_u8WFG_MODE == TIMER1_u8FAST_PWM_MODE_TOP_OCR1
	//Select Fast PWM Mode With OCR1 AS TOP Register
	TCCR1A.Bits.WGM10 = 1;
	TCCR1A.Bits.WGM11 = 1;
	TCCR1B.Bits.WGM12 = 1;
	TCCR1B.Bits.WGM13 = 1;

#endif

//Select Compare Match Output Mode depend On Timer1 Channel
#if TIMER1_u8CHANNEL_CFG == TIMER1_u8CHANNEL_A
	//Select Channel_A
	#if TIMER1_u8COMPARE_MATCH_OUTPUT_MODE == TIMER1_u8OC1_DISCONNECTED
		//OC1 Disconnected (no compare match)
		TCCR1A.Bits.COM1A = 0;
	#elif TIMER1_u8COMPARE_MATCH_OUTPUT_MODE == TIMER1_u8TOGGLE_OC1_ON_CM
		//toggle output at OCR1 compare match value
		TCCR1A.Bits.COM1A = 1;
	#elif TIMER1_u8COMPARE_MATCH_OUTPUT_MODE == TIMER1_u8CLEAR_OC1_ON_CM
		//clear output at OCR1 compare match value
		TCCR1A.Bits.COM1A = 2;
	#elif TIMER1_u8COMPARE_MATCH_OUTPUT_MODE == TIMER1_u8SET_OC1_ON_CM
		//set output at OCR1 compare match value
		TCCR1A.Bits.COM1A = 3;
	#elif TIMER1_u8COMPARE_MATCH_OUTPUT_MODE == TIMER1_u8PWM_TOGGLE_OC1_ON_CM
		//Toggle OC1A on Compare Match, OC1B disconnected
		TCCR1A.Bits.COM1A = 1;
	#elif TIMER1_u8COMPARE_MATCH_OUTPUT_MODE == TIMER1_u8PWMCLEAR_OC1_ON_CM_SET_ON_TOP
		//Clear OC1 on compare match, set OC1 at TOP
		TCCR1A.Bits.COM1A = 2;
	#elif TIMER1_u8COMPARE_MATCH_OUTPUT_MODE == TIMER1_u8PWMSET_OC1_ON_CM_CLEAR_ON_TOP
		//Set OC1 on compare match, Clear OC1 at TOP
		TCCR1A.Bits.COM1A = 3;
	#endif

#elif TIMER1_u8CHANNEL_CFG == TIMER1_u8CHANNEL_B
		//Select Channel_B
		#if TIMER1_u8COMPARE_MATCH_OUTPUT_MODE == TIMER1_u8OC1_DISCONNECTED
			//OC0 Disconnected (no compare match)
			TCCR1A.Bits.COM1B = 0;
		#elif TIMER1_u8COMPARE_MATCH_OUTPUT_MODE == TIMER1_u8TOGGLE_OC1_ON_CM
			//toggle output at OCR1 compare match value
			TCCR1A.Bits.COM1B = 1;
		#elif TIMER1_u8COMPARE_MATCH_OUTPUT_MODE == TIMER1_u8CLEAR_OC1_ON_CM
			//clear output at OCR1 compare match value
			TCCR1A.Bits.COM1B = 2;
		#elif TIMER1_u8COMPARE_MATCH_OUTPUT_MODE == TIMER1_u8SET_OC1_ON_CM
			//set output at OCR1 compare match value
			TCCR1A.Bits.COM1B = 3;
		#elif TIMER1_u8COMPARE_MATCH_OUTPUT_MODE == TIMER1_u8PWM_TOGGLE_OC1_ON_CM
			//Toggle OC1B on Compare Match, OC1A disconnected
			TCCR1A.Bits.COM1B = 1;
		#elif TIMER1_u8COMPARE_MATCH_OUTPUT_MODE == TIMER1_u8PWMCLEAR_OC1_ON_CM_SET_ON_TOP
			//Clear OC1 on compare match, set OC1 at TOP
			TCCR1A.Bits.COM1B = 2;
		#elif TIMER1_u8COMPARE_MATCH_OUTPUT_MODE == TIMER1_u8PWMSET_OC1_ON_CM_CLEAR_ON_TOP
			//Set OC1 on compare match, Clear OC1 at TOP
			TCCR1A.Bits.COM1B = 3;
		#endif
#endif

//Select Pre_Scaler
#if TIMER1_u8PRESCALLER_VALU == TIMER1_u8FCPU_1
	//Select No Pre_scalling
	TCCR1B.Bits.CS = 1;
#elif TIMER1_u8PRESCALLER_VALU == TIMER1_u8FCPU_8
	//Select Pre_scaller with 8
	TCCR1B.Bits.CS = 2;
#elif TIMER1_u8PRESCALLER_VALU == TIMER1_u8FCPU_64
	//Select Pre_scaller with 64
	TCCR1B.Bits.CS = 3;
#elif TIMER1_u8PRESCALLER_VALU == TIMER1_u8FCPU_256
	//Select Pre_scaller with 256
	TCCR1B.Bits.CS = 4;
#elif TIMER1_u8PRESCALLER_VALU == TIMER1_u8FCPU_1024
	//Select Pre_scaller with 1024
	TCCR1B.Bits.CS = 5;
#elif TIMER1_u8PRESCALLER_VALU == TIMER1_u8FCPU_EXTERNAL_CLK_FALLING
	//Select External CLK on T1 (clock on falling edge)
	TCCR1B.Bits.CS = 6;
#elif TIMER1_u8PRESCALLER_VALU == TIMER1_u8FCPU_EXTERNAL_CLK_RISING
	//Select External CLK on T1 (clock on rising edge)
	TCCR1B.Bits.CS = 7;
#endif

#if TIMER1_u8OVF_INTERRUPT_CFG == TIMER1_u8OVF_INTERRUPT_ENABLE
	//PIE of TIMER1 at overflow of counter register
	SREG.Bits.I_bit  =  1;
	TIMSK.Bits.TOIE1 =  1;
#elif TIMER1_u8OVF_INTERRUPT_CFG == TIMER1_u8OVF_INTERRUPT_DISABLE
	//disable Interrupt TIMER1 at overflow of counter register
	TIMSK.Bits.TOIE1 =  0;
#endif

#if TIMER1_u8CMP_A_INTERRUPT_CFG == TIMER1_u8CMP_A_INTERRUPT_ENABLE
	//PIE of TIMER1 at Compare Match Output Register for Channel_A (OCR1A)
	SREG.Bits.I_bit   =  1;
	TIMSK.Bits.OCIE1A =  1;
#elif TIMER1_u8CMP_A_INTERRUPT_CFG == TIMER1_u8CMP_A_INTERRUPT_DISABLE
	//disable Interrupt TIMER1 at Compare Match Output Register for Channel_A (OCR1A)
	TIMSK.Bits.OCIE1A =  0;
#endif

#if TIMER1_u8CMP_B_INTERRUPT_CFG == TIMER1_u8CMP_B_INTERRUPT_ENABLE
	//PIE of TIMER1 at Compare Match Output Register for Channel_B (OCR1B)
	SREG.Bits.I_bit   =  1;
	TIMSK.Bits.OCIE1B =  1;
#elif TIMER1_u8CMP_A_INTERRUPT_CFG == TIMER1_u8CMP_A_INTERRUPT_DISABLE
	//disable Interrupt TIMER1 at Compare Match Output Register for Channel_B (OCR1B)
	TIMSK.Bits.OCIE1B =  0;
#endif

#if TIMER1_u8INPUT_CAPTUER_INTERRUPT_CFG == TIMER1_u8INPUT_CAPTUER_INTERRUPT_ENABLE
	//PIE of TIMER1 Input Capture
	SREG.Bits.I_bit   =  1;
	TIMSK.Bits.TICIE1 =  1;
#elif TIMER1_u8INPUT_CAPTUER_INTERRUPT_CFG == TIMER1_u8INPUT_CAPTUER_INTERRUPT_DISABLE
	//disable Interrupt TIMER1 Input Capture
	TIMSK.Bits.TICIE1 =  0;
#endif
}

void Timer1_vidSetTCNT1Val(u16 Val)
{
	//Set Value In Counter Register (TCNT1)
	TCNT1.Byte = Val;
}

void Timer1_vidSetICR1Val(u16 Val)
{
	//Set Value In Input Capture Register (ICR1)
	ICR1.Byte = Val;
}

u16 Timer1_u16GetICR1Val(void)
{
	//Read Value From Input Capture Register (ICR1)
	u16 Ret_Val;
	Ret_Val = ICR1.Byte;
	return Ret_Val;
}

void Timer1_vidSetOCR1AVal(u16 Val)
{
	//Set Value Output Compare Register Channel_A (OCR1A)
	OCR1A.Byte = Val;
}

void Timer1_vidSetOCR1BVal(u16 Val)
{
	//Set Value Output Compare Register Channel_B (OCR1B)
	OCR1B.Byte = Val;
}

void Timer1_vidInputCapRisingEdge(void)
{
	//Select Input Capture At Rising Edge
	TCCR1B.Bits.ICES1 = 1;
}

void Timer1_vidInputCapFallingEdge(void)
{
	//Select Input Capture At Falling Edge
	TCCR1B.Bits.ICES1 = 0;
}

void Timer1_vidStopTimer(void)
{
	//Stop Timer1
	TCCR1B.Bits.CS = 0;
}

void Timer1_vidSetCallBackOVF(void(*pf)(void))
{
	Pfun_OVF = pf;
}

void Timer1_vidSetCallBackCMP_A(void(*pf)(void))
{
	Pfun_CMPA = pf;
}

void Timer1_vidSetCallBackCMP_B(void(*pf)(void))
{
	Pfun_CMPB = pf;
}

void Timer1_vidSetCallBackInputCAP(void(*pf)(void))
{
	Pfun_CAPT = pf;
}

void __vector_9 (void)
{
	Pfun_OVF();
}

void __vector_8 (void)
{
	Pfun_CMPB();
}

void __vector_7 (void)
{
	Pfun_CMPA();
}

void __vector_6 (void)
{
	Pfun_CAPT();
}
