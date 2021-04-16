/*
 * Timer0_cfg.h
 *
 *  Created on: Mar 23, 2020
 *      Author: zas
 */

#ifndef TIMER0_CFG_H_
#define TIMER0_CFG_H_

#define TIMER0_u8NORMAL_MODE  1
#define TIMER0_u8CTC_MODE     2
#define TIMER0_u8PWM_MODE     3


#define TIMER0_u8OC0_DISCONNECTED 			1
#define TIMER0_u8TOGGLE_OC0_ON_CM  		    2
#define TIMER0_u8CLEAR_OC0_ON_CM            3
#define TIMER0_u8SET_OC0_ON_CM              4
#define TIMER0_u8CLEAR_OC0_ON_CM_SET_ON_TOP 5
#define TIMER0_u8SET_OC0_ON_CM_CLEAR_ON_TOP 6

#define TIMER0_u8FCPU_1      1
#define TIMER0_u8FCPU_8      2
#define TIMER0_u8FCPU_64     3
#define TIMER0_u8FCPU_256    4
#define TIMER0_u8FCPU_1024   5
#define TIMER0_u8FCPU_EXTERNAL_CLK_FALLING  6
#define TIMER0_u8FCPU_EXTERNAL_CLK_RISING   7

#define TIMER0_u8OVF_INTERRUPT_DISABLE 0
#define TIMER0_u8OVF_INTERRUPT_ENABLE  1

#define TIMER0_u8CMP_INTERRUPT_DISABLE 0
#define TIMER0_u8CMP_INTERRUPT_ENABLE  1


/************************************
 * Waveform Generation Mode:
 * Select one of the following:
 * TIMER0_u8NORMAL_MODE
 * TIMER0_u8CTC_MODE
 * TIMER0_u8FAST-PWM_MODE
 * for ex. #define TIMER0_u8WFG_MODE  TIMER0_u8FAST-PWM_MODE
 ************************************/
#define TIMER0_u8WFG_MODE	 TIMER0_u8NORMAL_MODE


/************************************
 * Compare Match Output Mode:
 * Select one of the following:
 * TIMER0_u8OC0_DISCONNECTED
 * TIMER0_u8TOGGLE_OC0_ON_CM
 * TIMER0_u8CLEAR_OC0_ON_CM
 * TIMER0_u8SET_OC0_ON_CM
 * TIMER0_u8CLEAR_OC0_ON_CM_SET_ON_TOP
 * TIMER0_u8SET_OC0_ON_CM_CLEAR_ON_TOP
 * for ex. #define TIMER0_u8COMPARE_MATCH_OUTPUT_MODE  TIMER0_u8FAST-PWM_MODE
 ************************************/
#define TIMER0_u8COMPARE_MATCH_OUTPUT_MODE  TIMER0_u8OC0_DISCONNECTED


/************************************
 * TIMER0 Pre_Scaler:
 * Select one of the following:
 * TIMER0_u8FCPU_1
 * TIMER0_u8FCPU_8
 * TIMER0_u8FCPU_64
 * TIMER0_u8FCPU_256
 * TIMER0_u8FCPU_1024
 * TIMER0_u8FCPU_EXTERNAL_CLK_FALLING
 * TIMER0_u8FCPU_EXTERNAL_CLK_RISING
 * for ex. #define TIMER0_u8PRESCALLER_VALU  TIMER0_u8FCPU_8
 ************************************/
#define TIMER0_u8PRESCALLER_VALU  TIMER0_u8FCPU_1


/************************************
 * Timer0 overflow interrupt:
 * Select one of the following:
 * TIMER0_u8OVF_INTERRUPT_DISABLE
 * TIMER0_u8OVF_INTERRUPT_ENABLE
 * for ex. #define TIMER0_u8OVF_INTERRUPT  TIMER0_u8OVF_INTERRUPT_DISABLE
 ************************************/
#define TIMER0_u8OVF_INTERRUPT  TIMER0_u8OVF_INTERRUPT_ENABLE


/************************************
 * Timer0 output compare match interrupt:
 * Select one of the following:
 * TIMER0_u8CMP_INTERRUPT_DISABLE
 * TIMER0_u8CMP_INTERRUPT_ENABLE
 * for ex. #define TIMER0_u8CMP_INTERRUPT  TIMER0_u8CMP_INTERRUPT_DISABLE
 ************************************/
#define TIMER0_u8CMP_INTERRUPT  TIMER0_u8CMP_INTERRUPT_DISABLE

#endif /* TIMER0_CFG_H_ */
