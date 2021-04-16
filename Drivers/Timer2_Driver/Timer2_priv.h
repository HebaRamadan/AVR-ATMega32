/*
 * Timer2_priv.h
 *
 *  Created on: Mar 23, 2020
 *      Author: zas
 */

#ifndef TIMER2_PRIV_H_
#define TIMER2_PRIV_H_

void __vector_4 (void) __attribute__ ((signal,used, externally_visible)) ;  //Timer2 CMP
void __vector_5 (void) __attribute__ ((signal,used, externally_visible)) ;  //Timer2 OVF

#define SREG   (*(volatile Status_SREG_Type * )0x5F)
#define TIMSK  (*(volatile Timer2_TIMSK_Type *)0x59)
#define TCCR2  (*(volatile Timer2_TCCR2_Type *)0x45)
#define TCNT2  (*(volatile Timer2_TCNT2_Type *)0x44)
#define OCR2   (*(volatile Timer2_OCR2_Type * )0x43)

typedef union Timer2_TCCR2_Type Timer2_TCCR2_Type;
typedef union Timer2_TCNT2_Type Timer2_TCNT2_Type;
typedef union Timer2_OCR2_Type  Timer2_OCR2_Type;
typedef union Timer2_TIMSK_Type Timer2_TIMSK_Type;
typedef union Status_SREG_Type  Status_SREG_Type;


//FOC2 WGM20 COM21 COM20 WGM21 CS22 CS21 CS20

union Timer2_TCCR2_Type
{
	struct
	{
		u8 CS:3;      //Clock Select(Pre_scaler)
		u8 WGM21:1;   //Wave Form Generation(Bit_1)
		u8 COM:2;     //Compare Output Mode
		u8 WGM20:1;   //Wave Form Generation(Bit_2)
		u8 FOC2:1;    //Force Output Compare

	}Bits;

	u8 Byte;
};

union Timer2_TCNT2_Type
{
	u8 Byte;
};

union Timer2_OCR2_Type
{
	u8 Byte;
};

//OCIE2 TOIE2 TICIE1 OCIE1A OCIE1B TOIE1 OCIE0 TOIE0
union Timer2_TIMSK_Type
{
	struct
	{
		u8 bits:6 ;
		u8 TOIE2:1;   //Timer Overflow Interrupt Enable
		u8 OCIE2:1;   //Output Compare Interrupt Enable
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



#endif /* TIMER2_PRIV_H_ */
