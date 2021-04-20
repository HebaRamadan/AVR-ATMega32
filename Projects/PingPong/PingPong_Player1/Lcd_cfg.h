/*
 * Lcd_cfg.h
 *
 *  Created on: Nov 30, 2020
 *      Author: Heba Ramadan
 */

#ifndef LCD_CFG_H_
#define LCD_CFG_H_

//We can change in this file only that's depend on which PIN I need to connect my LCD
#define LCD_u8RS_PIN DIO_u8PIN_10      //RS at PORTB PIN_2
#define LCD_u8RW_PIN DIO_u8PIN_9	   //RW at PORTB PIN_1
#define LCD_u8EN_PIN DIO_u8PIN_8	   //EN at PORTB PIN_0

#define LCD_u8D0_PIN DIO_u8PIN_7	  //D0 at PORTD PIN_0
#define LCD_u8D1_PIN DIO_u8PIN_6	  //D1 at PORTD PIN_1
#define LCD_u8D2_PIN DIO_u8PIN_5	  //D2 at PORTD PIN_2
#define LCD_u8D3_PIN DIO_u8PIN_4	  //D3 at PORTD PIN_3
#define LCD_u8D4_PIN DIO_u8PIN_3	  //D4 at PORTD PIN_4
#define LCD_u8D5_PIN DIO_u8PIN_2	  //D5 at PORTD PIN_5
#define LCD_u8D6_PIN DIO_u8PIN_1	  //D6 at PORTD PIN_6
#define LCD_u8D7_PIN DIO_u8PIN_0	  //D7 at PORTD PIN_7



#endif /* LCD_CFG_H_ */
