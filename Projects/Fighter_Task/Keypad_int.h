/*
 * Keypad_int.h
 *
 *  Created on: Feb 12, 2020
 *      Author: zas
 */

#ifndef KEYPAD_INT_H_
#define KEYPAD_INT_H_
#define KEYPAD_u8NO_KEY 0xff

#define KEYPAD_u8R1C1_KEY 1
#define KEYPAD_u8R1C2_KEY 2
#define KEYPAD_u8R1C3_KEY 3
#define KEYPAD_u8R1C4_KEY '+'

#define KEYPAD_u8R2C1_KEY 4
#define KEYPAD_u8R2C2_KEY 5
#define KEYPAD_u8R2C3_KEY 6
#define KEYPAD_u8R2C4_KEY '-'

#define KEYPAD_u8R3C1_KEY 7
#define KEYPAD_u8R3C2_KEY 8
#define KEYPAD_u8R3C3_KEY 9
#define KEYPAD_u8R3C4_KEY '*'

#define KEYPAD_u8R4C1_KEY '#'
#define KEYPAD_u8R4C2_KEY 0
#define KEYPAD_u8R4C3_KEY '='
#define KEYPAD_u8R4C4_KEY '/'

void Keypad_vidInit(void);
u8 Keypad_u8GetKey(void);


#endif /* KEYPAD_INT_H_ */
