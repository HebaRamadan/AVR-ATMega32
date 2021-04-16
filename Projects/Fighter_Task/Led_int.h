/*
 * Led_int.h
 *
 *  Created on: Feb 12, 2020
 *      Author: zas
 */

#ifndef LED_INT_H_
#define LED_INT_H_

#define LED_1 1
#define LED_2 2
#define LED_3 3
#define LED_4 4
#define LED_5 5
#define LED_6 6
#define LED_7 7
#define LED_8 8

void Led_vidInit(u8 LedId);
void Led_vidTurnOn(u8 LedId);
void Led_vidTurnOff(u8 LedId);

#endif /* LED_INT_H_ */
