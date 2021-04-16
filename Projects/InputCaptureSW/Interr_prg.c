/*
 * Interr_prg.c
 *
 *  Created on: Dec 6, 2020
 *      Author: zas
 */
#include "Std_types.h"
#include "Bit_math.h"
#include "Interr_priv.h"
#include "Interr_cfg.h"
#include "Interr_int.h"

static void(*pfun_0)(void);   //pointer to function
static void(*pfun_1)(void);

void INT_vidInit(void)
{
/* INT0 */
#if INT_u8INTERRUPT_0_CFG == INT_u8INTERRUPT_0_ENABLE  //INT0
	//Enable Interrupt 0
	GICR.Bits.INT_0 = 1;

	//select interrupt 0 sense control
	#if INT0_u8INTERRUPT_SOURCE == INT_PIF_LOW_LEVEL
		//Rise Interrupt Flag At LOW_LEVEL Event
		MCUCR.Bits.ISC0 = 0;

	#elif INT0_u8INTERRUPT_SOURCE == INT_PIF_ON_CHANGE
		//Rise Interrupt Flag At ON_CHANGEL Event
		MCUCR.Bits.ISC0 = 1;

	#elif INT0_u8INTERRUPT_SOURCE == INT_PIF_FALLING_EDGE
		//Rise Interrupt Flag At FALLING_EDGE Event
		MCUCR.Bits.ISC0 = 2;

		#elif INT0_u8INTERRUPT_SOURCE == INT_u8PIF_RISING_EDGE
		//Rise Interrupt Flag At RISING_EDGE Event
		MCUCR.Bits.ISC0 = 3;


		#endif

#elif INT_u8INTERRUPT_0_CFG == INT_u8INTERRUPT_0_DISABLE
	//Disable Interrupt 0
	GICR.Bits.INT_0 = 0;
#endif


/* INT1  */
#if INT_u8INTERRUPT_1_CFG == INT_u8INTERRUPT_1_ENABLE  //INT1
   //Enable Interrupt 1
	GICR.Bits.INT_1 = 1;

	//select interrupt 1 sense control
	#if INT1_u8INTERRUPT_SOURCE == INT_PIF_LOW_LEVEL
		//Rise Interrupt Flag At LOW_LEVEL Event
		MCUCR.Bits.ISC1 = 0;

	#elif INT0_u8INTERRUPT_SOURCE == INT_PIF_ON_CHANGE
		//Rise Interrupt Flag At ON_CHANGE Event
		MCUCR.Bits.ISC1 = 1;

	#elif INT0_u8INTERRUPT_SOURCE == INT_PIF_FALLING_EDGE
		//Rise Interrupt Flag At FALLING_EDGE Event
		MCUCR.Bits.ISC1 = 2;

	#elif INT0_u8INTERRUPT_SOURCE == INT_PIF_RISING_EDGE
		//Rise Interrupt Flag At RISING_EDGE Event
		MCUCR.Bits.ISC1 = 3;
	#endif

#elif INT_u8INTERRUPT_1_CFG == INT_u8INTERRUPT_1_DISABLE
	//Disable Interrupt 1
	GICR.Bits.INT_1 = 0;
#endif

}


void IN0_vidSenseControl(u8 Val)
{
	MCUCR.Bits.ISC0 = Val;
}


void IN1_vidSenseControl(u8 Val)
{
	MCUCR.Bits.ISC1 = Val;
}


/*void GIE_vidEnable(void)
{
	SREG.Bits.I_bit = 1;
}

void GIE_vidDisable(void)
{
	SREG.Bits.I_bit = 1;
}*/


//Call_Back function has an address of another function in main.c for INT0
void INT0_vidSetCB(void(*pf)(void))
{
	pfun_0 = pf;
}

//function has an address of another function in main.c for INT1
void INT1_vidSetCB(void(*pf)(void))
{
	pfun_1 = pf;
}
//ISR OF INT0
void __vector_1 (void)
{
	pfun_0();
}
//ISR OF INT1
void __vector_2 (void)
{
	pfun_1();
}
