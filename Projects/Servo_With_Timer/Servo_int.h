/*
 * Servo_int.h
 *
 *  Created on: Mar 1, 2020
 *      Author: zas
 */

#ifndef SERVO_INT_H_
#define SERVO_INT_H_

#define FULL_DEGREE 180
#define TIME_OF_FULL_DEGREE 2.1
#define INITIAL_TIME 0.4

void Servo_vidInit(void);
void Servo_vidSetDegree(u8 degree);


#endif /* SERVO_INT_H_ */
