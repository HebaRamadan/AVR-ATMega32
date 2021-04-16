/*
 * SevenSeg_int.h
 *
 *  Created on: Feb 19, 2020
 *      Author: zas
 */

#ifndef SEVENSEG_INT_H_
#define SEVENSEG_INT_H_
#define RIGHT_SEVENSEG 0
#define LEFT_SEVENSEG 1

void SevenSeg_vidInit(u8 ID);
void SevenSeg_vidTurnOn(u8 ID);
void SevenSeg_vidTurnOff(u8 ID);
void SevenSeg_vidDisplayNum(u8 ID , u8 NUM);

#endif /* SEVENSEG_INT_H_ */
