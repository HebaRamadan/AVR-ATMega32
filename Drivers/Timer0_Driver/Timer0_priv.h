/*
 * Timer0_priv.h
 *
 *  Created on: Mar 23, 2020
 *      Author: zas
 */

#ifndef TIMER0_PRIV_H_
#define TIMER0_PRIV_H_

void __vector_10 (void) __attribute__ ((signal,used, externally_visible)) ;  //Timer0 CMP
void __vector_11 (void) __attribute__ ((signal,used, externally_visible)) ;  //Timer0 OVF

#define SREG   (*(volatile Status_SREG_Type *)0x5F)
#define OCR0   (*(volatile Timer0_OCR0_Type *)0x5C)
#define TIMSK  (*(volatile Timer0_TIMSK_Type *)0x59)
#define TCCR0  (*(volatile Timer0_TCCR0_Type *)0x53)
#define TCNT0  (*(volatile Timer0_TCNT0_Type *)0x52)

typedef union Timer0_TCCR0_Type Timer0_TCCR0_Type;
typedef union Timer0_TCNT0_Type Timer0_TCNT0_Type;
typedef union Timer0_OCR0_Type  Timer0_OCR0_Type;
typedef union Timer0_TIMSK_Type Timer0_TIMSK_Type;
typedef union Status_SREG_Type  Status_SREG_Type;


union Timer0_TCCR0_Type
{
	struct
	{
		u8 CS:3;      //Clock Select(Pre_scaler)
		u8 WGM01:1;   //Wave Form Generation(Bit_1)
		u8 COM:2;     //Compare Output Mode
		u8 WGM00:1;   //Wave Form Generation(Bit_2)
		u8 FOC0:1;    //Force Output Compare

	}Bits;

	u8 Byte;
};

union Timer0_TCNT0_Type
{
	u8 Byte;
};

union Timer0_OCR0_Type
{
	u8 Byte;
};

union Timer0_TIMSK_Type
{
	struct
	{
		u8 TOIE0:1;   //Timer Overflow Interrupt Enable
		u8 OCIE0:1;   //Output Compare Interrupt Enable
		u8 bits:6;
	}Bits;

	u8 Byte;
};


union Status_SREG_Type
{
	struct
	{
		u8 bits:7;
		u8 I_bit:1;  //Global Interrupt BIT

	}Bits;

	u8 Byte;
};



#endif /* TIMER0_PRIV_H_ */
