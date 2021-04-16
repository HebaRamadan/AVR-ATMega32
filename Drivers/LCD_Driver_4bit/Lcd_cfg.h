/*
 * Lcd_cfg.h
 *
 *  Created on: Feb 7, 2020
 *      Author: zas
 */

#ifndef LCD_CFG_H_
#define LCD_CFG_H_
//We can change in this file only that's depend on which PIN I need to connect my LCD
#define LCD_u8RS_PIN DIO_u8PIN_0      //RS at PORTA PIN_0
#define LCD_u8RW_PIN DIO_u8PIN_1	  //RW at PORTA PIN_1
#define LCD_u8EN_PIN DIO_u8PIN_2	  //EN at PORTA PIN_2

#define LCD_u8D4_PIN DIO_u8PIN_28	  //D4 at PORTD PIN_4
#define LCD_u8D5_PIN DIO_u8PIN_29	  //D5 at PORTD PIN_5
#define LCD_u8D6_PIN DIO_u8PIN_30	  //D6 at PORTD PIN_6
#define LCD_u8D7_PIN DIO_u8PIN_31	  //D7 at PORTD PIN_7

#endif /* LCD_CFG_H_ */
