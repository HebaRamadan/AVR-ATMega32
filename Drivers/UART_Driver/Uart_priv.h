/*
 * Uart_priv.h
 *
 *  Created on: Jun 20, 2020
 *      Author: zas
 */

#ifndef UART_PRIV_H_
#define UART_PRIV_H_


void __vector_13 (void) __attribute__ ((signal,used, externally_visible)) ;  //USART, RX complete
void __vector_14 (void) __attribute__ ((signal,used, externally_visible)) ;  //USART, UDR empty



#define UDR      (*(volatile UART_UDR_Type*)   0x2C)
#define UCSRA    (*(volatile UART_UCSRA_Type*) 0x2B)
#define UCSRB    (*(volatile UART_UCSRB_Type*) 0x2A)
#define UCSRC    (*(volatile UART_UCSRC_Type*) 0x40)
#define UBRRL    (*(volatile UART_UBRRL_Type*) 0x29)
#define UBRRH    (*(volatile UART_UBRRH_Type*) 0x40)
#define SREG     (*(volatile Status_SREG_Type*)0x5F)

/*      UDR Register     */
typedef union
{
	u8 Byte;        //Data register to read or write from buffer register

}UART_UDR_Type;


/*      USCRA Register    */
typedef union
{
	struct
	{
		u8 MPCM:1;   //Multi_processor Communication Mode
		u8 U2X:1;    //Double Speed
		u8 PE:1;     //Flag indicates parity error
		u8 DOR:1;    //Flag indicates Data OverRun
		u8 FE:1;     //Flag indicates frame error
		u8 UDRE:1;   //Flag bit indicates the status of UDR Register   (1 -> UDR Register empty and ready to receive new Data)
		u8 TXC:1;    //Flag bit indicates the status of Transmitter Buffer Register (1 -> All data transfer from  shift Reg and  Data Transmited)
		u8 RXC:1;    //Flag bit indicates the status of Receiver Buffer Register    (1 -> All data transfer from  shift Reg to UDR and ready to Read UDR)

	}Bits;

	u8 Byte;

}UART_UCSRA_Type;



/*      USCRB Register    */
typedef union
{
	struct
	{
		u8 TXB8:1;     //Ninth bit TX
		u8 RXB8:1;     //Ninth bit RX
		u8 UCSZ2:1;    //Bit_2 which combine with the UCSZ1:0 bit in UCSRC To select Data size
		u8 TXEN:1;     //Enables the USART Transmitter
		u8 RXEN:1;     //Enables the USART Receiver
		u8 UDRIE:1;    //UDRE Interrupt Enable
		u8 TXCIE:1;    //TXC  Interrupt Enable
		u8 RXCIE:1;    //RXC  Interrupt Enable

	}Bits;

	u8 Byte;

}UART_UCSRB_Type;


/*      USCRC Register    */
typedef union
{
	struct
	{
		u8 UCPOL:1;    //Clock Polarity(Related To Synchronous MOode)
		u8 UCSZ0:1;    //BIT_0 To Select Number of Data Size
		u8 UCSZ1:1;    //BIT_1 To Select Number of Data Size
		u8 USBS:1;     //Bit   To Select Number of bits for STOP_BIT
		u8 UPM:2;      //2Bits To Select Parity Bit MOode
		u8 UMSEL:1;    //Bit   To Select Synchronous OR ASynchronous MOode
		u8 URSEL:1;    //Bit   To Access USCRC Register Which share the same address with UBRRH

	}Bits;

	u8 Byte;

}UART_UCSRC_Type;


/*      UBRRH Register    */
typedef union
{
	struct
	{
		u8 UBRR:4;     //Baud Rate Register
		u8 bits:3;     //Reserved Bits
		u8 URSEL:1;    //Bit To Access UBRRH Register Which share the same address with USCRC
	}Bits;

	u8 Byte;

}UART_UBRRH_Type;

/*      UBBRL Register     */
typedef union
{
	u8 Byte;        //Baud Rate Register

}UART_UBRRL_Type;


/*      SREG Register     */
typedef union
{
	struct
	{
		u8 bits:7;
		u8 I_bit:1;  //Global Interrupt BIT

	}Bits;

	u8 Byte;
}Status_SREG_Type;



#endif /* UART_PRIV_H_ */
