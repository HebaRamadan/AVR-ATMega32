/*
 * Timer1_Private.h
 *
 *  Created on: Dec 19, 2020
 *      Author: zas
 */

#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_
void __vector_9 (void) __attribute__ ((signal,used, externally_visible)) ;  //Timer1 OVR
void __vector_8 (void) __attribute__ ((signal,used, externally_visible)) ;  //Timer1 COM_B
void __vector_7 (void) __attribute__ ((signal,used, externally_visible)) ;  //Timer1 COM_A
void __vector_6 (void) __attribute__ ((signal,used, externally_visible)) ;  //Timer1 CAPT


#define SREG   (*(volatile u8  *)0x5F)
#define TIMSK  (*(volatile u8  *)0x59)
#define TCCR1A (*(volatile u8  *)0x4F)
#define TCCR1B (*(volatile u8  *)0x4E)
#define TCNT1  (*(volatile u16 *)0x4C)
#define OCR1A  (*(volatile u16 *)0x4A)
#define OCR1B  (*(volatile u16 *)0x48)
#define ICR1   (*(volatile u16 *)0x46)


/* TCCR1A */
#define COM1A1		7
#define COM1A0		6
#define COM1B1		5
#define COM1B0		4
#define FOC1A		3
#define FOC1B		2
#define WGM11		1
#define WGM10		0

/* TCCR1B */
#define ICNC		7
#define ICES1 		6
#define WGM13 		4
#define WGM12 		3
#define CS12 		2
#define CS11 		1
#define CS10		0

/* TIMSK */
#define TICIE1		5
#define OCIE1A		4
#define OCIE1B 		3
#define TOIE1		2


#endif /* TIMER1_PRIVATE_H_ */
