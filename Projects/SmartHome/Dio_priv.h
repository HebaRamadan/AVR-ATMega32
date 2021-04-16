/*
 * Dio_Priv.h
 *
 *  Created on: Nov 29, 2020
 *      Author: Heba Ramadan
 */

#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_

typedef union Reg_type Reg_type ;

union Reg_type
{
	struct
	{
		u8 bit0:1;
		u8 bit1:1;
		u8 bit2:1;
		u8 bit3:1;
		u8 bit4:1;
		u8 bit5:1;
		u8 bit6:1;
		u8 bit7:1;
	}Bits;

	u8 Byte;
};

#define PORTA	 (*(volatile Reg_type *)0x3B)
#define DDRA 	 (*(volatile Reg_type *)0x3A)
#define PINA 	 (*(volatile Reg_type *)0x39)

#define PORTB 	(*(volatile Reg_type *)0x38)
#define DDRB 	(*(volatile Reg_type *)0x37)
#define PINB 	(*(volatile Reg_type *)0x36)

#define PORTC 	(*(volatile Reg_type *)0x35)
#define DDRC 	(*(volatile Reg_type *)0x34)
#define PINC 	(*(volatile Reg_type *)0x33)

#define PORTD	(*(volatile Reg_type *)0x32)
#define DDRD	(*(volatile Reg_type *)0x31)
#define PIND	(*(volatile Reg_type *)0x30)

#endif /* DIO_PRIV_H_ */
