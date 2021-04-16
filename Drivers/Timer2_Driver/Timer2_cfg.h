/*
 * TIMER2_cfg.h
 *
 *  Created on: Mar 23, 2020
 *      Author: zas
 */

#ifndef TIMER2_CFG_H_
#define TIMER2_CFG_H_

#define TIMER2_u8NORMAL_MODE                 1
#define TIMER2_u8CTC_MODE                    2
#define TIMER2_u8FAST_PWM_MODE               3


#define TIMER2_u8OC2_DISCONNECTED 			 1
#define TIMER2_u8TOGGLE_OC2_ON_CM  		     2
#define TIMER2_u8CLEAR_OC2_ON_CM             3
#define TIMER2_u8SET_OC2_ON_CM               4
#define TIMER2_u8CLEAR_OC2_ON_CM_SET_ON_TOP  5
#define TIMER2_u8SET_OC2_ON_CM_CLEAR_ON_TOP  6

#define TIMER2_u8FCPU_1                      1
#define TIMER2_u8FCPU_8                      2
#define TIMER2_u8FCPU_64                     3
#define TIMER2_u8FCPU_256                    4
#define TIMER2_u8FCPU_1024                   5
#define TIMER2_u8FCPU_EXTERNAL_CLK_FALLING   6
#define TIMER2_u8FCPU_EXTERNAL_CLK_RISING    7

#define TIMER2_u8OVF_INTERRUPT_DISABLE       0
#define TIMER2_u8OVF_INTERRUPT_ENABLE        1

#define TIMER2_u8CMP_INTERRUPT_DISABLE       0
#define TIMER2_u8CMP_INTERRUPT_ENABLE        1


/************************************
 * Waveform Generation Mode:
 * Select one of the following:
 * TIMER2_u8NORMAL_MODE
 * TIMER2_u8CTC_MODE
 * TIMER2_u8FAST_PWM_MODE
 * for ex. #define TIMER2_u8WFG_MODE  TIMER2_u8FAST_PWM_MODE
 ************************************/
#define TIMER2_u8WFG_MODE	 TIMER2_u8FAST_PWM_MODE


/************************************
 * Compare Match Output Mode:
 * Select one of the following:
 * TIMER2_u8OC2_DISCONNECTED
 * TIMER2_u8TOGGLE_OC2_ON_CM
 * TIMER2_u8CLEAR_OC2_ON_CM
 * TIMER2_u8SET_OC2_ON_CM
 * TIMER2_u8CLEAR_OC2_ON_CM_SET_ON_TOP
 * TIMER2_u8SET_OC2_ON_CM_CLEAR_ON_TOP
 * for ex. #define TIMER2_u8COMPARE_MATCH_OUTPUT_MODE    IMER2_u8CLEAR_OC0_ON_CM
 ************************************/
#define TIMER2_u8COMPARE_MATCH_OUTPUT_MODE  TIMER2_u8CLEAR_OC2_ON_CM_SET_ON_TOP


/************************************
 * TIMER2 Pre_Scaler:
 * Select one of the following:
 * TIMER2_u8FCPU_1
 * TIMER2_u8FCPU_8
 * TIMER2_u8FCPU_64
 * TIMER2_u8FCPU_256
 * TIMER2_u8FCPU_1024
 * TIMER2_u8FCPU_EXTERNAL_CLK_FALLING
 * TIMER2_u8FCPU_EXTERNAL_CLK_RISING
 * for ex. #define TIMER2_u8PRESCALLER_VALU  TIMER2_u8FCPU_8
 ************************************/
#define TIMER2_u8PRESCALLER_VALU  TIMER2_u8FCPU_1


/************************************
 * TIMER2 overflow interrupt:
 * Select one of the following:
 * TIMER2_u8OVF_INTERRUPT_DISABLE
 * TIMER2_u8OVF_INTERRUPT_ENABLE
 * for ex. #define TIMER2_u8OVF_INTERRUPT  TIMER2_u8OVF_INTERRUPT_DISABLE
 ************************************/
#define TIMER2_u8OVF_INTERRUPT  TIMER2_u8OVF_INTERRUPT_DISABLE


/************************************
 * TIMER2 output compare match interrupt:
 * Select one of the following:
 * TIMER2_u8CMP_INTERRUPT_DISABLE
 * TIMER2_u8CMP_INTERRUPT_ENABLE
 * for ex. #define TIMER2_u8CMP_INTERRUPT  TIMER2_u8CMP_INTERRUPT_DISABLE
 ************************************/
#define TIMER2_u8CMP_INTERRUPT  TIMER2_u8CMP_INTERRUPT_DISABLE

#endif /* TIMER2_CFG_H_ */
