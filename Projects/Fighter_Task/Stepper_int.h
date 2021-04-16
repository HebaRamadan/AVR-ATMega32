/*
 * Stepper_int.h
 *
 *  Created on: Feb 17, 2020
 *      Author: zas
 */

#ifndef STEPPER_INT_H_
#define STEPPER_INT_H_
#define DEG_OF_ONE_ITERATION 0.703

void Stepper_vidInit(void);
void Stepper_vidTurnRight(u16 Degree);
void Stepper_vidTurnLeft(u16 Degree);

#endif /* STEPPER_INT_H_ */
