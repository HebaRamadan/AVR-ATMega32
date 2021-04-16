/*
 * Interr_int.h
 *
 *  Created on: Dec 6, 2020
 *      Author: zas
 */

#ifndef INTERR_INT_H_
#define INTERR_INT_H_

#define  RISING    3
#define  FALLING   2

void INT_vidInit(void);
//void GIE_vidEnable(void);
//void GIE_vidDisable(void);

void INT0_vidSetCB(void(*pf)(void));
void INT1_vidSetCB(void(*pf)(void));

void IN0_vidSenseControl(u8 Val);
void IN1_vidSenseControl(u8 Val);

#endif /* INTERR_INT_H_ */
