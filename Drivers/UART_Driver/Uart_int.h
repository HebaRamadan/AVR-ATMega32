/*
 * Uart_int.h
 *
 *  Created on: Jun 20, 2020
 *      Author: zas
 */

#ifndef UART_INT_H_
#define UART_INT_H_

#define UART_u8NO_RECEIVE 0xff

void Uart_vidInit(void);

void Uart_vidSendByte(u8 Byte);

u8   Uart_u8ReceiveByte(void);

void Uart_vidSendString(u8 *Str);


#endif /* UART_INT_H_ */
