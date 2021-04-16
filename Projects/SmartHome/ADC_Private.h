/*
 * ADC_Private.h
 *
 *  Created on: Dec 7, 2020
 *      Author: zas
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_


#define ADMUX  (*(volatile u8 *)0x27)
#define ADCSRA (*(volatile u8 *)0x26)
#define ADCH   (*(volatile u8 *)0x25)
#define ADCL   (*(volatile u8 *)0x24)
#define SFIOR  (*(volatile u8 *)0x50)
#define SREG   (*(volatile u8 *)0x5F)


#endif /* ADC_PRIVATE_H_ */
