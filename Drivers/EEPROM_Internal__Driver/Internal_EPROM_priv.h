/*
 * Internal_EPROM_priv.h
 *
 *  Created on: Aug 7, 2020
 *      Author: zas
 */

#ifndef INTERNAL_EPROM_PRIV_H_
#define INTERNAL_EPROM_PRIV_H_

#define  EERE    0
#define  EEWE    1
#define  EEMWE   2
#define  EERIE   3
#define  I_Bit   7
#define  SPMEN   0

#define  EECR   (*(volatile u8 *)0x3C)
#define  EEDR   (*(volatile u8 *)0x3D)
#define  EEARL  (*(volatile u8 *)0x3E)
#define  EEARH  (*(volatile u8 *)0x3F)
#define  SREG   (*(volatile u8 *)0x5F)
#define SPMCR   (*(volatile u8 *)0x57)

#define  EECR_RE   (*(volatile Reg *)0x3C)

typedef union
{
	struct
	{
		u8 bit:1;
		u8 EEWE_bit:1;
		u8 EEMWE_bit:1;

	}bits;
}Reg;
#endif /* INTERNAL_EPROM_PRIV_H_ */

