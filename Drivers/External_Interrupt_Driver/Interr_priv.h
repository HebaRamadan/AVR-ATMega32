/*
 * Interr_priv.h
 *
 *  Created on: Mar 19, 2020
 *      Author: zas
 */

#ifndef INTERR_PRIV_H_
#define INTERR_PRIV_H_

void __vector_1 (void) __attribute__ ((signal,used, externally_visible)); //INT0
void __vector_2 (void) __attribute__ ((signal,used, externally_visible)); //INT1

#define SREG (*(volatile Status_SREG_Type *)0x5F)
#define GICR (*(volatile INT_GICR_Type *)0x5B)
#define MCUCR (*(volatile INT_MCUCR_Type *)0x55)

typedef union Status_SREG_Type Status_SREG_Type;
typedef union INT_GICR_Type INT_GICR_Type;
typedef union INT_MCUCR_Type INT_MCUCR_Type;

//SREG Register
union Status_SREG_Type
{
	struct
	{
		u8 bits:7;
		u8 I_bit:1;  //Global Interrupt BIT

	}Bits;

	u8 Byte;
};

//GICR Register
union INT_GICR_Type
{
	struct
	{
		u8 bits:6;
		u8 INT_0:1;  //External Interrupt 0 Request
		u8 INT_1:1;  //External Interrupt 1 Request

	}Bits;

	u8 Byte;
};

//MCUCR Register
union INT_MCUCR_Type
{
	struct
	{
		u8 ISC00:1; //Sense Control For Interrupt 0 (BIT_1)
		u8 ISC01:1; //Sense Control For Interrupt 0 (BIT_2)
		u8 ISC10:1; //Sense Control For Interrupt 1 (BIT_1)
		u8 ISC11:1; //Sense Control For Interrupt 1 (BIT_2)

	}Bits;

	u8 Byte;
};


#endif /* INTERR_PRIV_H_ */
