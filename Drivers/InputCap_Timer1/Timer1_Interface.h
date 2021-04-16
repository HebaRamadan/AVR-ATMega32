/*
 * Timer1_Interface.h
 *
 *  Created on: Dec 19, 2020
 *      Author: zas
 */

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

void Timer1_vidInit(void);

void Timer1_vidDuttyCycleChannelA(u16 Val);
void Timer1_vidDuttyCycleChannelB(u16 Val);

void GIE_vidEnable(void);
void GIE_vidDisable(void);

void Timer1_vidStopTimer(void);


#endif /* TIMER1_INTERFACE_H_ */
