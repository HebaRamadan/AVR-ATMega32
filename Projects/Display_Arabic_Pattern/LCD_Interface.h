/*
 * LCD_Interface.h
 *
 *  Created on: Nov 30, 2020
 *      Author: zas
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_vidInit(void);
void LCD_vidSendCommand(u8 Cmd);
void LCD_vidSendData(u8 Char);
void LCD_vidSendString(u8* Str);
void LCD_vidWriteNumber(u16 Number);

void LCD_vidSavePattern(u8 *Pattern , u8 Pattern_Adress);


#endif /* LCD_INTERFACE_H_ */
