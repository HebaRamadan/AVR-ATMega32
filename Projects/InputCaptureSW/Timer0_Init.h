/*
 * Timer0_Init.h
 *
 *  Created on: Dec 15, 2020
 *      Author: zas
 */

#ifndef TIMER0_INIT_H_
#define TIMER0_INIT_H_


void Timer0_vidInit(void);
void GIE_vidEnable(void);
void GIE_vidDisable(void);

void Timer0_vidDutyCycle(u8 Duty);
void Timer0_vidSetCompareRegisterValue(u8 Val);

u8   Timer0_u8GetCounterRegistr(void);
void Timer0_u8SetCounterRegistr(u8 Val);

void OVF_vidSetCB(void(*pf)(void));
void CMP_vidSetCB(void(*pf)(void));
#endif /* TIMER0_INIT_H_ */
