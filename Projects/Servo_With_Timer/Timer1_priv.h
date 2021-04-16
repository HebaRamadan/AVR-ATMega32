/*
 * Timer1_priv.h
 *
 *  Created on: Mar 25, 2020
 *      Author: zas
 */

#ifndef TIMER1_PRIV_H_
#define TIMER1_PRIV_H_

void __vector_9 (void) __attribute__ ((signal,used, externally_visible)) ;  //Timer1 OVR
void __vector_8 (void) __attribute__ ((signal,used, externally_visible)) ;  //Timer1 COM_B
void __vector_7 (void) __attribute__ ((signal,used, externally_visible)) ;  //Timer1 COM_A
void __vector_6 (void) __attribute__ ((signal,used, externally_visible)) ;  //Timer1 CAPT


#define SREG   (*(volatile Status_SREG_Type *)0x5F)
#define TIMSK  (*(volatile Timer1_TIMSK_Type *)0x59)
#define TCCR1A (*(volatile Timer1_TCCR1A_Type *)0x4F)
#define TCCR1B (*(volatile Timer1_TCCR1B_Type *)0x4E)
#define TCNT1  (*(volatile Timer1_TCNT1_Type *)0x4C)
#define OCR1A  (*(volatile Timer1_OCR1A_Type *)0x4A)
#define OCR1B  (*(volatile Timer1_OCR1B_Type *)0x48)
#define ICR1   (*(volatile Timer1_ICR1_Type *)0x46)

typedef union Status_SREG_Type   Status_SREG_Type;
typedef union Timer1_TIMSK_Type  Timer1_TIMSK_Type;
typedef union Timer1_TCCR1A_Type Timer1_TCCR1A_Type;
typedef union Timer1_TCCR1B_Type Timer1_TCCR1B_Type;
typedef union Timer1_TCNT1_Type  Timer1_TCNT1_Type;
typedef union Timer1_OCR1A_Type  Timer1_OCR1A_Type;
typedef union Timer1_OCR1B_Type  Timer1_OCR1B_Type;
typedef union Timer1_ICR1_Type   Timer1_ICR1_Type;


//TCCR1A Register
union Timer1_TCCR1A_Type
{
	struct
	{
		u8 WGM10:1;   //Waveform Generation (Timer Mode)bit_1
		u8 WGM11:1;   //Waveform Generation (Timer Mode)bit_2
		u8 FOC1B:1;   //Force Output Compare Channel B
		u8 FOC1A:1;   //Force Output Compare Channel A
		u8 COM1B:2;   //Compare Output Mode Channel B
		u8 COM1A:2;   //Compare Output Mode Channel A
	}Bits;

	u8 Byte;
};


//TCCR1B Register
union Timer1_TCCR1B_Type
{
	struct
	{
		u8 CS:3;      //Clock Selection (Pre_Scaler)
		u8 WGM12:1;   //Waveform Generation (Timer Mode)bit_3
		u8 WGM13:1;   //Waveform Generation (Timer Mode)bit_4
		u8 RES_BIT:1; //Reserved Bit
		u8 ICES1:1;   //Input CAP Edge Selection
		u8 ICNC1:1;   //Input CAP Noise Canceler

	}Bits;

	u8 Byte;
};


//TCNT1 Register
union Timer1_TCNT1_Type
{
	struct
	{
		u16 TCNT1L:8;
		u16 TCNT1H:8;

	}Bits;

	u16 Byte;
};

//ICR1 Register
union Timer1_ICR1_Type
{
	struct
	{
		u16 ICR1L:8;
		u16 ICR1H:8;

	}Bits;

	u16 Byte;
};

//OCR1A Register
union Timer1_OCR1A_Type
{
	struct
	{
		u16 OCR1AL:8;
		u16 OCR1AH:8;

	}Bits;

	u16 Byte;
};

//OCR1B Register
union Timer1_OCR1B_Type
{
	struct
	{
		u16 OCR1BL:8;
		u16 OCR1BH:8;

	}Bits;

	u16 Byte;
};

//TIMSK Register
union Timer1_TIMSK_Type
{
	struct
	{
		u8 TIMER0:2;   //Timer0 Interrupt Enable (NOT Interested)
		u8 TOIE1:1;    //Timer1 Overflow Interrupt Enable
		u8 OCIE1B:1;   //Timer1 Output Compare Interrupt Enable Channel B
		u8 OCIE1A:1;   //Timer1 Output Compare Interrupt Enable Channel A
		u8 TICIE1:1;   //Timer1 Input Capture Interrupt Enable
		u8 TIMER2:2;   //Timer2 Interrupt Enable (NOT Interested)
	}Bits;

	u8 Byte;
};

//SREG Register
union Status_SREG_Type
{
	struct
	{
		u8 bits:7;
		u8 I_bit:1;  //Global Interrupt BIT

	}Bits;

	u8 Byte;
};

#endif /* TIMER1_PRIV_H_ */
