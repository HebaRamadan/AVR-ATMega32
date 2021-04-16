/*
 * Interr_int.h
 *
 *  Created on: Mar 19, 2020
 *      Author: zas
 */

#ifndef INTERR_INT_H_
#define INTERR_INT_H_


void INT_vidInit(void);
void INT0_vidSetCB(void(*pf)(void));
void INT1_vidSetCB(void(*pf)(void));


#endif /* INTERR_INT_H_ */
