/*
 * Timer1_int.h
 *
 *  Created on: Mar 25, 2020
 *      Author: zas
 */

#ifndef TIMER1_INT_H_
#define TIMER1_INT_H_

void Timer1_vidInit(void);
void Timer1_vidSetTCNT1Val(u16 Val);
u16 Timer1_u16GetTCNT1Val(void);

void Timer1_vidSetICR1Val(u16 Val);
u16 Timer1_u16GetICR1Val(void);

void Timer1_vidSetOCR1AVal(u16 Val);
void Timer1_vidSetOCR1BVal(u16 Val);

void Timer1_vidInputCapRisingEdge(void);
void Timer1_vidInputCapFallingEdge(void);
void Timer1_vidStopTimer(void);

void Timer1_vidSetCallBackOVF(void(*pf)(void));
void Timer1_vidSetCallBackCMP_A(void(*pf)(void));
void Timer1_vidSetCallBackCMP_B(void(*pf)(void));
void Timer1_vidSetCallBackInputCAP(void(*pf)(void));

#endif /* TIMER1_INT_H_ */
