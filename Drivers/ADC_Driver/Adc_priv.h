/*
 * Adc_priv.h
 *
 *  Created on: Mar 10, 2020
 *  Author      : Heba Ramadan Taha
 */

 
#ifndef ADC_PRIV_H_
#define ADC_PRIV_H_

void __vector_16 (void) __attribute__ ((signal,used, externally_visible));                //ADC ISR (Conversion Complete)

#define ADMUX		(*(volatile Adc_ADMUX_Type	*)0x27)
#define ADCSRA		(*(volatile Adc_ADCSRA_Type	*)0x26)
#define ADCH			(*(volatile Adc_ADCH_Type		*)0x25)
#define ADCL			(*(volatile Adc_ADCL_Type		*)0x24)
#define SFIOR		(*(volatile Adc_SFIOR_Type		*)0x50)
#define SREG			(*(volatile Status_SREG_Type	*)0x5F)

typedef union		Adc_ADMUX_Type   Adc_ADMUX_Type	;
typedef union		Adc_ADCSRA_Type  Adc_ADCSRA_Type	;
typedef union		Adc_ADCH_Type    Adc_ADCH_Type     	;
typedef union		Adc_ADCL_Type    Adc_ADCL_Type		;
typedef union		Adc_SFIOR_Type   Adc_SFIOR_Type		;
typedef union		Status_SREG_Type Status_SREG_Type	;


//ADMUX Register
union Adc_ADMUX_Type
{
	struct
	{
		u8 MUX	 :5;       //ADC_Channel
		u8 ADLAR:1;      //ADC_Adjustment
		u8 REFS  :2;      //ADC_Voltage_Referance

	}Bits;

	u8 Byte;
};

//ADCSRA Register
union Adc_ADCSRA_Type
{
	struct
	{
		u8 ADPS	 :3;      //ADC_Pre_Scaler
		u8 ADIE  :1;      //ADC_Interrupt_Enable
		u8 ADIF	 :1;      //ADC_Interrupt_Flag
		u8 ADATE:1;     //ADC_Auto_Trigger
		u8 ADSC  :1;     //ADC_Start_Convirision
		u8 ADEN  :1;     //ADC_Enable

	}Bits;

	u8 Byte;
};

//ADCH Register
union Adc_ADCH_Type
{
	u8 Byte;
};

//ADCL Register
union Adc_ADCL_Type
{
	u8 Byte;
};

//SFIOR Register
union Adc_SFIOR_Type
{
	struct
	{
		u8 bits  :5;
		u8 ADTS:3;     //ADC_Trigger_Source

	}Bits;

	u8 Byte;
};

//SREG Register
union Status_SREG_Type
{
	struct
	{
		u8 bits :7;
		u8 I_bit:1;  //Global Interrupt BIT

	}Bits;

	u8 Byte;
};

#endif /* ADC_PRIV_H_ */
