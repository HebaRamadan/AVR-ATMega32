/*
 *********** DIO_Interface.h
 *********** Author			: 	Heba Ramadan Taha
 *********** Created on	:  29 / 11 / 2020
 *********** Version			:  1
 */


#ifndef  DIO_INTERFACE_H_
#define  DIO_INTERFACE_H_


#define DIO_u8PORTA 0
#define DIO_u8PORTB 1
#define DIO_u8PORTC 2
#define DIO_u8PORTD 3

// define pin as input or output
#define DIO_u8OUTPUT 1
#define DIO_u8INPUT  0

#define DIO_u8OUTPUT_PORT 0xff
#define DIO_u8INPUT_PORT  0x00

// define pin has (high 5V) or (low 0V)
#define DIO_u8HIGH 1
#define DIO_u8LOW 0

#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7

void DIO_vidSetPinDirection		( u8 Copy_U8Port  ,  u8 Copy_U8Pin  ,  u8 Copy_U8Direction);
void DIO_vidSetPinValue			( u8 Copy_U8Port  ,  u8 Copy_U8Pin  ,  u8 Copy_U8Value     );
u8   DIO_u8GetPinValue    	 	( u8 Copy_U8Port  ,  u8 Copy_U8Pin	);

void DIO_vidSetPortDirection	( u8 Copy_U8Port  ,  u8 Copy_U8Direction	);
void DIO_vidSetPortValue		( u8 Copy_U8Port  ,  u8 Copy_U8Value		);
void DIO_vidTogglePin			( u8 Copy_U8Port  ,  u8 Copy_U8Pin			);



#endif 
