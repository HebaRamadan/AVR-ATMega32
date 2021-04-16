/*
 * Uart_cfg.h
 *
 *  Created on: Jun 20, 2020
 *      Author: zas
 */

#ifndef UART_CFG_H_
#define UART_CFG_H_

#define USART_u8SYNCHRONOUS_MODE          1
#define USART_u8ASYNCHRONOUS_MODE         2


#define USART_u8DISABLE_PARITY_MODE       1
#define USART_u8ENABLE_EVEN_PARITY        2
#define USART_u8ENABL_ODD_PARITY          3


#define USART_u8CHARACTER_SIZE_5BIT       1
#define USART_u8CHARACTER_SIZE_6BIT       2
#define USART_u8CHARACTER_SIZE_7BIT       3
#define USART_u8CHARACTER_SIZE_8BIT       4
#define USART_u8CHARACTER_SIZE_9BIT       5


#define USART_u8STOP_BIT_1                1
#define USART_u8STOP_BIT_2                2


#define USART_u8NORMAL_SPEED              1
#define USART_u8DOUBLE_SPEED              2


#define USART_u8BAUD_RATE_2400BPS         1
#define USART_u8BAUD_RATE_4800BPS         2
#define USART_u8BAUD_RATE_9600BPS         3
#define USART_u8BAUD_RATE_14.4KBPS        4
#define USART_u8BAUD_RATE_19.2KBPS        5
#define USART_u8BAUD_RATE_28.8KBPS        6


#define USART_u8POLLING_BASED             1
#define USART_u8INTERRUPT_BASED           2



/************************************
 * USART Mode:
 * Select one of the following:
 * USART_u8SYNCHRONOUS_MODE
 * USART_u8ASYNCHRONOUS_MODE
 * for ex. #define USART_u8MODE  USART_u8ASYNCHRONOUS_MODE
 ************************************/
#define USART_u8MODE  USART_u8ASYNCHRONOUS_MODE



/************************************
 * Parity Bit Mode:
 * Select one of the following:
 * USART_u8DISABLE_PARITY_MODE
 * USART_u8ENABLE_EVEN_PARITY
 * USART_u8ENABLE_ODD_PARITY
 * for ex. #define USART_u8PARIY_BIT_MODE  USART_u8DISABLE_PARITY_MODE
 ************************************/
#define USART_u8PARIY_BIT_MODE  USART_u8DISABLE_PARITY_MODE



/************************************
 * Character Size Bits:
 * Select one of the following:
 * USART_u8CHARACTER_SIZE_5BIT
 * USART_u8CHARACTER_SIZE_6BIT
 * USART_u8CHARACTER_SIZE_7BIT
 * USART_u8CHARACTER_SIZE_8BIT
 * USART_u8CHARACTER_SIZE_9BIT
 * for ex. #define USART_u8CHARACTER_SIZE  USART_u8CHARACTER_SIZE_8BIT
 ************************************/
#define USART_u8CHARACTER_SIZE  USART_u8CHARACTER_SIZE_8BIT



/************************************
 * Stop Bit Number:
 * Select one of the following:
 * USART_u8STOP_BIT_1
 * USART_u8STOP_BIT_2
 * for ex. #define USART_u8STOP_BIT_NUM  USART_u8STOP_BIT_1
 ************************************/
#define USART_u8STOP_BIT_NUM  USART_u8STOP_BIT_1



/************************************
 * Speed Mode:
 * Select one of the following:
 * USART_u8NORMAL_SPEED
 * USART_u8DOUBLE_SPEED
 * for ex. #define USART_u8SPEED_MODE  USART_u8NORMAL_SPEED
 ************************************/
#define USART_u8SPEED_MODE  USART_u8NORMAL_SPEED



/************************************
 * Baud Rate:
 * Select one of the following:
 * USART_u8BAUD_RATE_2400BPSD
 * USART_u8BAUD_RATE_4800BPS
 * USART_u8BAUD_RATE_9600BPS
 * USART_u8BAUD_RATE_14.4KBPS
 * USART_u8BAUD_RATE_19.2KBPS
 * USART_u8BAUD_RATE_28.8KBPS
 * for ex. #define USART_u8BAUD_RATE  USART_u8BAUD_RATE_9600BPS
 ************************************/
#define USART_u8BAUD_RATE  USART_u8BAUD_RATE_9600BPS



/************************************
 * USART Implementation Based:
 * Select one of the following:
 * USART_u8POLLING_BASED
 * USART_u8INTERRUPT_BASED
 * for ex. USART_u8IMPLEMENTATION_BASED  USART_u8POLLING_BASED
 ************************************/
#define USART_u8IMPLEMENTATION_BASED  USART_u8POLLING_BASED

#endif /* UART_CFG_H_ */
