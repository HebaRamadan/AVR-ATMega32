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

static void(*Pfun_OVF)(void);
static void(*Pfun_CMP)(void);


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
	TCCR0 = 3;
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
	SET_BIT(TIMSK , OCIE0);
	//Initial OCR0 Register
	OCR0 = TIMER0_u8PRELOAD;

#elif TIMER0_u8WFG_MODE == TIMER0_u8FAST_PWM_MODE
	SET_BIT(TCCR0 , WGM00);
	SET_BIT(TCCR0 , WGM01);
#endif


#if TIMER0_u8COMPARE_MATCH_OUTPUT_MODE == TIMER0_u8OC0_DISCONNECTED
	//Select OCR0 disconnected (NO_COMPARE_MATCH)
	CLR_BIT(TCCR0 , COM00);
	CLR_BIT(TCCR0 , COM01);
#elif TIMER0_u8COMPARE_MATCH_OUTPUT_MODE == TIMER0_u8TOGGLE_OC0_ON_CM
	//Select toggle output at OCR0 compare match value
	SET_BIT(TCCR0 , COM00);
	CLR_BIT(TCCR0 , COM01);
#elif TIMER0_u8COMPARE_MATCH_OUTPUT_MODE == TIMER0_u8CLEAR_OC0_ON_CM
	//Select clear output at OCR0 compare match value
	CLR_BIT(TCCR0 , COM00);
	SET_BIT(TCCR0 , COM01);
#elif TIMER0_u8COMPARE_MATCH_OUTPUT_MODE == TIMER0_u8SET_OC0_ON_CM
	//Select set output at OCR0 compare match value
	SET_BIT(TCCR0 , COM00);
	SET_BIT(TCCR0 , COM01);
#elif TIMER0_u8COMPARE_MATCH_OUTPUT_MODE == TIMER0_u8CLEAR_OC0_ON_CM_SET_ON_TOP
	//Select clear output at OCR0 compare match value and set at register overflow
	CLR_BIT(TCCR0 , COM00);
	SET_BIT(TCCR0 , COM01);
#elif TIMER0_u8COMPARE_MATCH_OUTPUT_MODE == TIMER0_u8SET_OC0_ON_CM_CLEAR_ON_TOP
	//Select set output at OCR0 compare match value and clear at register overflow
	SET_BIT(TCCR0 , COM00);
	SET_BIT(TCCR0 , COM01);
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

void Timer0_vidSetCompareRegisterValue(u8 Val)
{
	OCR0 = Val;
}

void Timer0_vidDutyCycle(u8 Duty)
{
	u8 Val = (256 * Duty) /100 ;
	OCR0 = Val;
}



u8   Timer0_u8GetCounterRegistr(void)
{
	return TCNT0;
}
void Timer0_u8SetCounterRegistr(u8 Val)
{
	TCNT0   =  Val;
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
