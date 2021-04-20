/*
 * Exit_Private.h
 *
 *  Created on: Dec 6, 2020
 *      Author: zas
 */

#ifndef EXIT_PRIVATE_H_
#define EXIT_PRIVATE_H_

void __vector_1 (void) __attribute__ ((signal,used, externally_visible)); //INT0
void __vector_2 (void) __attribute__ ((signal,used, externally_visible)); //INT1

#define SREG  (*(volatile u8 *)0x5F)
#define GICR  (*(volatile u8 *)0x5B)
#define MCUCR (*(volatile u8 *)0x55)


#endif /* EXIT_PRIVATE_H_ */
