/*
 * Timer0_Private.h
 *
 *  Created on: Dec 15, 2020
 *      Author: zas
 */

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

void __vector_10 (void) __attribute__ ((signal,used, externally_visible)) ;  //Timer0 CTC
void __vector_11 (void) __attribute__ ((signal,used, externally_visible)) ;  //Timer0 OVF


#define SREG   (*(volatile u8 *)0x5F)
#define OCR0   (*(volatile u8 *)0x5C)
#define TIMSK  (*(volatile u8 *)0x59)
#define TCCR0  (*(volatile u8 *)0x53)
#define TCNT0  (*(volatile u8 *)0x52)


#define WGM00		6
#define COM01		5
#define COM00		4
#define WGM01		3
#define CS02		2
#define CS01		1
#define CS00		0


#define OCIE0		1
#define TOIE0		0

#endif /* TIMER0_PRIVATE_H_ */
