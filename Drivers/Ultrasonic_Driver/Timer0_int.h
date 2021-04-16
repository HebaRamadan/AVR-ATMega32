/*
 * Timer0_int.h
 *
 *  Created on: Mar 23, 2020
 *      Author: zas
 */

#ifndef TIMER0_INT_H_
#define TIMER0_INT_H_

void Timer0_vidInit(void);
void Timer0_vidStop(void);
void Timer0_vidSetCounterRegisterValue(u8 Val);
void Timer0_vidSetCompareRegisterValue(u8 Val);

#endif /* TIMER0_INT_H_ */
