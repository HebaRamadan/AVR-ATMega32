/*
 * Timer1_cfg.h
 *
 *  Created on: Mar 25, 2020
 *      Author: zas
 */

#ifndef TIMER1_CFG_H_
#define TIMER1_CFG_H_

#define TIMER1_u8NORMAL_MODE              1
#define TIMER1_u8CTC_MODE_TOP_OCR1        2
#define TIMER1_u8CTC_MODE_TOP_ICR1        3
#define TIMER1_u8FAST_PWM_MODE_8BIT       4
#define TIMER1_u8FAST_PWM_MODE_9BIT       5
#define TIMER1_u8FAST_PWM_MODE_10BIT      6
#define TIMER1_u8FAST_PWM_MODE_TOP_ICR1   7
#define TIMER1_u8FAST_PWM_MODE_TOP_OCR1   8

#define TIMER1_u8CHANNEL_A      1
#define TIMER1_u8CHANNEL_B      2

#define TIMER1_u8OC1_DISCONNECTED 		   	   1
#define TIMER1_u8TOGGLE_OC1_ON_CM  		       2
#define TIMER1_u8CLEAR_OC1_ON_CM               3
#define TIMER1_u8SET_OC1_ON_CM                 4
#define TIMER1_u8PWM_TOGGLE_OC1_ON_CM  	       6
#define TIMER1_u8PWMCLEAR_OC1_ON_CM_SET_ON_TOP 7
#define TIMER1_u8PWMSET_OC1_ON_CM_CLEAR_ON_TOP 8

#define TIMER1_u8FCPU_1      1
#define TIMER1_u8FCPU_8      2
#define TIMER1_u8FCPU_64     3
#define TIMER1_u8FCPU_256    4
#define TIMER1_u8FCPU_1024   5
#define TIMER1_u8FCPU_EXTERNAL_CLK_FALLING  6
#define TIMER1_u8FCPU_EXTERNAL_CLK_RISING   7

#define TIMER1_u8OVF_INTERRUPT_DISABLE  0
#define TIMER1_u8OVF_INTERRUPT_ENABLE   1

#define TIMER1_u8CMP_A_INTERRUPT_DISABLE 0
#define TIMER1_u8CMP_A_INTERRUPT_ENABLE  1

#define TIMER1_u8CMP_B_INTERRUPT_DISABLE 0
#define TIMER1_u8CMP_B_INTERRUPT_ENABLE  1

#define TIMER1_u8INPUT_CAPTUER_INTERRUPT_DISABLE 0
#define TIMER1_u8INPUT_CAPTUER_INTERRUPT_ENABLE  1


/************************************
 * Waveform Generation Mode:
 * Select one of the following:
 * TIMER1_u8NORMAL_MODE
 * TIMER1_u8CTC_MODE_TOP_OCR1
 * TIMER1_u8CTC_MODE_TOP_ICR1
 * TIMER1_u8FAST_PWM_MODE_8BIT
 * TIMER1_u8FAST_PWM_MODE_9BIT
 * TIMER1_u8FAST_PWM_MODE_10BIT
 * TIMER1_u8FAST_PWM_MODE_TOP_ICR1
 * TIMER1_u8FAST_PWM_MODE_TOP_OCR1
 * for ex. #define TIMER1_u8WFG_MODE  TIMER1_u8CTC_MODE_TOP_OCR1
 ************************************/
#define TIMER1_u8WFG_MODE  TIMER1_u8NORMAL_MODE


/************************************
 * TIMER_1 Channel configuration:
 * Select one of the following:
 * TIMER1_u8CHANNEL_A
 * TIMER1_u8CHANNEL_B
 * for ex. #define TIMER1_u8CHANNEL_CFG  TIMER1_u8CHANNEL_A
 ************************************/
#define TIMER1_u8CHANNEL_CFG  TIMER1_u8CHANNEL_A


/************************************
 * Compare Match Output Mode:
 * Select one of the following:
 * TIMER1_u8OC0_DISCONNECTED
 * TIMER1_u8TOGGLE_OC1_ON_CM
 * TIMER1_u8CLEAR_OC1_ON_CM
 * TIMER1_u8SET_OC1_ON_CM
 * TIMER1_u8PWM_TOGGLE_OC1_ON_CM
 * TIMER1_u8PWMCLEAR_OC1_ON_CM_SET_ON_TOP
 * TIMER1_u8PWMSET_OC1_ON_CM_CLEAR_ON_TOP
 * for ex. #define TIMER1_u8COMPARE_MATCH_OUTPUT_MODE  TIMER1_u8TOGGLE_OC1_ON_CM
 ************************************/
#define TIMER1_u8COMPARE_MATCH_OUTPUT_MODE  TIMER1_u8OC0_DISCONNECTED


/************************************
 * TIMER1 Pre_Scaler:
 * Select one of the following:
 * TIMER1_u8FCPU_1
 * TIMER1_u8FCPU_8
 * TIMER1_u8FCPU_64
 * TIMER1_u8FCPU_256
 * TIMER1_u8FCPU_1024
 * TIMER1_u8FCPU_EXTERNAL_CLK_FALLING
 * TIMER1_u8FCPU_EXTERNAL_CLK_RISING
 * for ex. #define TIMER1_u8PRESCALLER_VALU  TIMER1_u8FCPU_8
 ************************************/
#define TIMER1_u8PRESCALLER_VALU  TIMER1_u8FCPU_8


/************************************
 * Timer1 Overflow Interrupt Configuration:
 * Select one of the following:
 * TIMER1_u8OVF_INTERRUPT_DISABLE
 * TIMER1_u8OVF_INTERRUPT_ENABLE
 * for ex. #define TIMER1_u8OVF_INTERRUPT_CFG  TIMER1_u8OVF_INTERRUPT_DISABLE
 ************************************/
#define TIMER1_u8OVF_INTERRUPT_CFG  TIMER1_u8OVF_INTERRUPT_DISABLE


/************************************
 * Timer1 Output Compare Match Interrupt Configuration Channel_A:
 * Select one of the following:
 * TIMER1_u8CMP_A_INTERRUPT_DISABLE
 * TIMER1_u8CMP_A_INTERRUPT_ENABLE
 * for ex. #define TIMER1_u8CMP_A_INTERRUPT_CFG  TIMER1_u8CMP_A_INTERRUPT_DISABLE
 ************************************/
#define TIMER1_u8CMP_A_INTERRUPT_CFG  TIMER1_u8CMP_A_INTERRUPT_DISABLE


/************************************
 * Timer1 Output Compare Match Interrupt Configuration Channel_A:
 * Select one of the following:
 * TIMER1_u8CMP_B_INTERRUPT_DISABLE
 * TIMER1_u8CMP_B_INTERRUPT_ENABLE
 * for ex. #define TIMER1_u8CMP_B_INTERRUPT_CFG  TIMER1_u8CMP_B_INTERRUPT_DISABLE
 ************************************/
#define TIMER1_u8CMP_B_INTERRUPT_CFG  TIMER1_u8CMP_B_INTERRUPT_DISABLE

/************************************
 * Timer1 Input Capture Interrupt Configuration:
 * Select one of the following:
 * TIMER1_u8INPUT_CAPTUER_INTERRUPT_DISABLE
 * TIMER1_u8INPUT_CAPTUER_INTERRUPT_ENABLE
 * for ex. #define TIMER1_u8INPUT_CAPTUER_INTERRUPT_CFG  TIMER1_u8INPUT_CAPTUER_INTERRUPT_ENABLE
 ************************************/
#define TIMER1_u8INPUT_CAPTUER_INTERRUPT_CFG  TIMER1_u8INPUT_CAPTUER_INTERRUPT_DISABLE

#endif /* TIMER1_CFG_H_ */
