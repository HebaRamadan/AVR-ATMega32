/*
 * Timer2_int.h
 *
 *  Created on: Mar 23, 2020
 *      Author: zas
 */

#ifndef TIMER2_INT_H_
#define TIMER2_INT_H_

void Timer2_vidInit(void);
void Timer2_vidStopTimer(void);
void Timer2_vidSetCounterRegisterValue(u8 Val);
void Timer2_vidSetCompareRegisterValue(u8 Val);
void OVF_vidTimer2SetCB(void(*pf)(void));
void CMP_vidTimer2SetCB(void(*pf)(void));

#endif /* TIMER2_INT_H_ */
