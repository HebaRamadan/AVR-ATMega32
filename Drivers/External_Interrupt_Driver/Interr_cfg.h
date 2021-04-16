/*
 * Interr_cfg.h
 *
 *  Created on: Mar 19, 2020
 *      Author: zas
 */

#ifndef INTERR_CFG_H_
#define INTERR_CFG_H_

#define INT_u8INTERRUPT_0_DISABLE 0
#define INT_u8INTERRUPT_0_ENABLE  1


#define INT_u8INTERRUPT_1_DISABLE 0
#define INT_u8INTERRUPT_1_ENABLE  1


#define INT_u8PIF_LOW_LEVEL     1
#define INT_u8PIF_ON_CHANGE     2
#define INT_u8PIF_FALLING_EDGE  3
#define INT_u8PIF_RISING_EDGE   4
#define INT_u8DISABLE           5

/************************************
 * Interrupt_0 configuration:
 * Select one of the following:
 * INT_u8INTERRUPT_0_DISABLE
 * INT_u8INTERRUPT_0_ENABLE
 * for ex. #define INT_u8INTERRUPT_0_CFG  INT_u8INTERRUPT_0_DISABLE
 ************************************/
#define INT_u8INTERRUPT_0_CFG   INT_u8INTERRUPT_0_ENABLE


/************************************
 * Interrupt_1 configuration:
 * Select one of the following:
 * INT_u8INTERRUPT_1_DISABLE
 * INT_u8INTERRUPT_1_ENABLE
 * for ex. #define INT_u8INTERRUPT_1_CFG  INT_u8INTERRUPT_1_DISABLE
 ************************************/
#define INT_u8INTERRUPT_1_CFG   INT_u8INTERRUPT_1_DISABLE


/************************************
 * Interrupt sense control:
 * Select one of the following:
 * INT_u8PIF_LOW_LEVEL
 * INT_u8PIF_ON_CHANGE
 * INT_u8PIF_FALLING_EDGE
 * INT_u8PIF_RISING_EDGE
 * INT_u8DISABLE
 * for ex. #define INT0_u8INTERRUPT_SOURCE  INT_u8PIF_LOW_LEVEL
 * for ex. #define INT1_u8INTERRUPT_SOURCE  INT_u8PIF_RISING_EDGE
 ************************************/
#define INT0_u8INTERRUPT_SOURCE INT_PIF_LOW_LEVEL
#define INT1_u8INTERRUPT_SOURCE INT_u8DISABLE

#endif /* INTERR_CFG_H_ */
