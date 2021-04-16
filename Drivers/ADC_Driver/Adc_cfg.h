/*
 * Adc_cfg.h
 *
 *  Created on : Mar 10, 2020
 *  Author       : Heba Ramadan Taha
 */

 
#ifndef ADC_CFG_H_
#define ADC_CFG_H_

#define ADC_u8AREF					   1
#define ADC_u8AVCC					   2
#define ADC_u8_2_56V				   3


#define ADC_u8LEFT_ADJUST              0
#define ADC_u8RIGHT_ADJUST	       	    1


#define ADC_u8TRIGGER_SOURCE_DISABLED					1
#define ADC_u8TRIGGER_SOURCE_FREE_RUN					2
#define ADC_u8TRIGGER_SOURCE_ANALOG_COMP			3
#define ADC_u8TRIGGER_SOURCE_EXTERNAL_INT 			4
#define ADC_u8TRIGGER_SOURCE_TIMER0_CM				5
#define ADC_u8TRIGGER_SOURCE_TIMER0_OVERFLOW	6
#define ADC_u8TRIGGER_SOURCE_TIMER_CM_B				7
#define ADC_u8TRIGGER_SOURCE_TIMER1_OVERFLOW	8
#define ADC_u8TRIGGER_SOURCE_TIMER1_CAP_INPUT 	9


#define ADC_u8INTERRUPT_BASED     							1
#define ADC_u8POLLING_BASED       							2

#define ADC_u8FCPU_2   										   	1
#define ADC_u8FCPU_4      											2
#define ADC_u8FCPU_8     											3
#define ADC_u8FCPU_16    											4
#define ADC_u8FCPU_32    											5
#define ADC_u8FCPU_64    											6
#define ADC_u8FCPU_128  											7


/************************************
 * Reference Voltage configuration:
 * Select one of the following:
 * ADC_u8AREF
 * ADC_u8AVCC
 * ADC_u8_2_56V
 * for ex. #define ADC_u8REF_VOLT  ADC_u8AVCC
 ************************************/
#define ADC_u8REF_VOLT	 ADC_u8AVCC

/************************************
 * Result Adjustment configuration:
 * Select one of the following:
 * ADC_u8RIGHT_ADJUST
 * ADC_u8LEFT_ADJUST
 * for ex. #define ADC_u8RESULT_ADJUST  ADC_u8RIGHT_ADJUST
 ************************************/
#define ADC_u8RESULT_ADJUST  ADC_u8RIGHT_ADJUST

/************************************
 * AUTO Trigger configuration:
 * Select one of the following:
 * ADC_u8TRIGGER_SOURCE_DISABLED
 * ADC_u8TRIGGER_SOURCE_FREE_RUN
 * ADC_u8TRIGGER_SOURCE_ANALOG_COMP
 * ADC_u8TRIGGER_SOURCE_EXTERNAL_INT
 * ADC_u8TRIGGER_SOURCE_TIMER0_CM
 * ADC_u8TRIGGER_SOURCE_TIMER0_OVERFLOW
 * ADC_u8TRIGGER_SOURCE_TIMER_CM_B
 * ADC_u8TRIGGER_SOURCE_TIMER1_OVERFLOW
 * ADC_u8TRIGGER_SOURCE_TIMER1_CAP_INPUT
 * for ex. #define ADC_u8AUTO_TRIGGER  ADC_u8TRIGGER_SOURCE_FREE_RUN
 ************************************/
#define ADC_u8AUTO_TRIGGER   ADC_u8TRIGGER_SOURCE_DISABLED


/************************************
 * ADC Implementation Based:
 * Select one of the following:
 * ADC_u8INTERRUPT_BASED
 * ADC_u8POLLING_BASED
 * for ex. ADC_u8IMPLEMENTATION_BASED  ADC_u8POLLING_BASED
 ************************************/
#define ADC_u8IMPLEMENTATION_BASED	ADC_u8POLLING_BASED


/************************************
 * ADC Pre_scaler:
 * Select one of the following:
 * ADC_u8FCPU_2
 * ADC_u8FCPU_4
 * ADC_u8FCPU_8
 * ADC_u8FCPU_16
 * ADC_u8FCPU_32
 * ADC_u8FCPU_64
 * ADC_u8FCPU_128
 * for ex. ADC_u8PRESCALLER_VALUE  ADC_u8FCPU_16
 ************************************/
#define ADC_u8PRESCALLER_VALUE   ADC_u8FCPU_8


#endif /* ADC_CFG_H_ */
