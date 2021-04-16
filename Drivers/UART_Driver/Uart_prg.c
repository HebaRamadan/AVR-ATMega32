/*
 * Uart_prg.c
 *
 *  Created on: Jun 20, 2020
 *      Author: zas
 */
#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#include "Uart_cfg.h"
#include "Uart_priv.h"
#include "Uart_int.h"

u8 Send_Data;
u8 Received_Data;
u8 Interrupt_Flag;

void Uart_vidInit(void)
{
/*      Enable Rx and Tx       */
	UCSRB.Bits.RXEN = 1;         //Rx
	UCSRB.Bits.TXEN = 1;         //Tx


/*      Select USART Implementation Based     */
#if USART_u8IMPLEMENTATION_BASED ==  USART_u8POLLING_BASED
	//Disable Interrupt Peripheral
	UCSRB.Bits.RXCIE = 0;
	UCSRB.Bits.UDRIE = 0;

#elif  USART_u8IMPLEMENTATION_BASED == USART_u8INTERRUPT_BASED
	//Enable Global Interrupt && Enable Interrupt Peripheral
	SREG.Bits.I_bit  = 1;
	UCSRB.Bits.RXCIE = 1;
	UCSRB.Bits.UDRIE = 1;

#endif


/*      Select USART MODE     */
#if USART_u8MODE == USART_u8ASYNCHRONOUS_MODE
	//Asynchronous Mode
	UCSRC.Bits.URSEL = 0;
	UCSRC.Bits.UMSEL = 0;

#elif USART_u8MODE == USART_u8SYNCHRONOUS_MODE
	//Synchronous Mode
	UCSRC.Bits.UMSEL = 1;

#endif


/*      Select Parity Bit MODE     */
#if USART_u8PARIY_BIT_MODE == USART_u8DISABLE_PARITY_MODE
	//Disable Parity Bit
	UCSRC.Bits.UPM = 0;

#elif USART_u8PARIY_BIT_MODEE == USART_u8ENABLE_EVEN_PARITY
	//Even Parity Bit
	UCSRC.Bits.UPM = 2;

#elif USART_u8PARIY_BIT_MODEE == USART_u8ENABLE_EVEN_PARITY
	//Odd Parity Bit
	UCSRC.Bits.UPM = 3;

#endif


/*      Select Stop Bit MODE     */
#if USART_u8STOP_BIT_NUM == USART_u8STOP_BIT_1
	//Select 1-Bit Stop
	UCSRC.Bits.USBS = 0;

#elif USART_u8STOP_BIT_NUM == USART_u8STOP_BIT_2
	//Select 2-Bit Stop
	UCSRC.Bits.USBS = 1;


#endif


/*      Select Character Size     */
#if USART_u8CHARACTER_SIZE == USART_u8CHARACTER_SIZE_5BIT
	//Select 5-Bit Character Size
	UCSRC.Bits.UCSZ0 = 0;
	UCSRC.Bits.UCSZ1 = 0;
	UCSRB.Bits.UCSZ2 = 0;

#elif USART_u8CHARACTER_SIZE == USART_u8CHARACTER_SIZE_6BIT
	//Select 6-Bit Character Size
	UCSRC.Bits.UCSZ0 = 1;
	UCSRC.Bits.UCSZ1 = 0;
	UCSRB.Bits.UCSZ2 = 0;

#elif USART_u8CHARACTER_SIZE == USART_u8CHARACTER_SIZE_7BIT
	//Select 7-Bit Character Size
	UCSRC.Bits.UCSZ0 = 0;
	UCSRC.Bits.UCSZ1 = 1;
	UCSRB.Bits.UCSZ2 = 0;

#elif USART_u8CHARACTER_SIZE == USART_u8CHARACTER_SIZE_8BIT
	//Select 8-Bit Character Size
	UCSRC.Bits.UCSZ0 = 1;
	UCSRC.Bits.UCSZ1 = 1;
	UCSRB.Bits.UCSZ2 = 0;

#elif USART_u8CHARACTER_SIZE == USART_u8CHARACTER_SIZE_9BIT
	//Select 9-Bit Character Size
	UCSRC.Bits.UCSZ0 = 1;
	UCSRC.Bits.UCSZ1 = 1;
	UCSRB.Bits.UCSZ2 = 1;
#endif


/*      Select SPeed MODE && Baud Rate     */
#if USART_u8SPEED_MODE == USART_u8NORMAL_SPEED
	//Select Normal Speed
	UCSRA.Bits.U2X = 0;

/*      Select Configure Of Baud Rate     */
	#if USART_u8BAUD_RATE == USART_u8BAUD_RATE_2400BPS
		//Configure "2400" Baud rate
		UBRRH.Byte = 0;
		UBRRL.Byte = 207;

	#elif USART_u8BAUD_RATE == USART_u8BAUD_RATE_4800BPS
		//Configure "4800" Baud rate
		UBRRH.Byte = 0;
		UBRRL.Byte = 103;

	#elif USART_u8BAUD_RATE == USART_u8BAUD_RATE_9600BPS
		//Configure "9600" Baud rate
		UBRRH.Byte = 0;
		UBRRL.Byte = 51;

	#elif USART_u8BAUD_RATE == USART_u8BAUD_RATE_14.4KBPS
		//Configure "14.4K" Baud rate
		UBRRH.Byte = 0;
		UBRRL.Byte = 34;

	#elif USART_u8BAUD_RATE == USART_u8BAUD_RATE_19.2KBPS
		//Configure "19.2K" Baud rate
		UBRRH.Byte = 0;
		UBRRL.Byte = 25;

	#elif USART_u8BAUD_RATE == USART_u8BAUD_RATE_28.8KBPS
		//Configure "28.8K" Baud rate
		UBRRH.Byte = 0;
		UBRRL.Byte = 16;

	#endif

#elif USART_u8SPEED_MODE == USART_u8DOUBLE_SPEED
	//Select Double Speed
	UCSRA.Bits.U2X = 1;

	/*      Select Configure Of Baud Rate     */
	#if USART_u8BAUD_RATE == USART_u8BAUD_RATE_2400BPS
		//Configure "2400" Baud rate
		UBRRH.Byte = (416 >> 8);
		UBRRL.Byte = 416;

	#elif USART_u8BAUD_RATE == USART_u8BAUD_RATE_4800BPS
		//Configure "4800" Baud rate
		UBRRH.Byte = 0;
		UBRRL.Byte = 207;

	#elif USART_u8BAUD_RATE == USART_u8BAUD_RATE_9600BPS
		//Configure "9600" Baud rate
		UBRRH.Byte = 0;
		UBRRL.Byte = 103;

	#elif USART_u8BAUD_RATE == USART_u8BAUD_RATE_14.4KBPS
		//Configure "14.4K" Baud rate
		UBRRH.Byte = 0;
		UBRRL.Byte = 51;

	#elif USART_u8BAUD_RATE == USART_u8BAUD_RATE_19.2KBPS
		//Configure "19.2K" Baud rate
		UBRRH.Byte = 0;
		UBRRL.Byte = 34;

	#elif USART_u8BAUD_RATE == USART_u8BAUD_RATE_28.8KBPS
		//Configure "28.8K" Baud rate
		UBRRH.Byte = 0;
		UBRRL.Byte = 25;

	#endif

#endif


}


void Uart_vidSendByte(u8 Byte)
{

#if USART_u8IMPLEMENTATION_BASED ==  USART_u8POLLING_BASED
	// Waiting till UDR register is Empty
	while(UCSRA.Bits.UDRE == 0);
	/* Update UDR register with the data needs to be sent */
	UDR.Byte = Byte;

#elif USART_u8IMPLEMENTATION_BASED ==  USART_u8INTERRUPT_BASED
	Send_Data = Byte;
#endif

}



u8   Uart_u8ReceiveByte(void)
{
	/*  Declare Variable to check time out of receiving data */
	u16 Mcal_u16TimeOut = 10000;

	/* Re-initialize Interrupt Flag which raised when jump to ISR*/
	Interrupt_Flag = 0;

#if USART_u8IMPLEMENTATION_BASED == USART_u8POLLING_BASED
	while(Mcal_u16TimeOut--)
	{
		// Check RxC flag
		if(UCSRA.Bits.RXC == 1)
		{
			Received_Data = UDR.Byte;
			return Received_Data;
		}
	}

	return UART_u8NO_RECEIVE;

#elif USART_u8IMPLEMENTATION_BASED == USART_u8INTERRUPT_BASED
	while(Mcal_u16TimeOut--)
	{
		// Check ISR flag
		if(Interrupt_Flag == 1)
		{

			return Received_Data;
		}
	}

	return UART_u8NO_RECEIVE;
#endif

}


/*     RXC ISR     */
void __vector_13 (void)
{
	Interrupt_Flag = 1;
	Received_Data  = UDR.Byte;
}

/*     UDR empty ISR    */
void __vector_14 (void)
{
	UDR.Byte = Send_Data;
}




