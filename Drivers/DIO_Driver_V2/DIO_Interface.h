/*
 *********** DIO_Interface.h
 *********** Author			: 	Heba Ramadan Taha
 *********** Created on	:  29 / 11 / 2020
 *********** Version			:  1
 */


#ifndef  DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


#define portA 0
#define portB 1
#define portC 2
#define portD 3

void DIO_vidSetPinDirection		( u8 Copy_U8Port  ,  u8 Copy_U8Pin  ,  u8 Copy_U8Direction);
void DIO_vidSetPinValue			( u8 Copy_U8Port  ,  u8 Copy_U8Pin  ,  u8 Copy_U8Value     );
u8   DIO_u8GetPinValue    	 	( u8 Copy_U8Port  ,  u8 Copy_U8Pin	);

void DIO_vidSetPortDirection	( u8 Copy_U8Port  ,  u8 Copy_U8Direction	);
void DIO_vidSetPortValue		    ( u8 Copy_U8Port  ,  u8 Copy_U8Value		);
void DIO_vidTogglePin			    ( u8 Copy_U8Port  ,  u8 Copy_U8Pin			);



#endif 
