/*
 * Lcd_int.h
 *
 *  Created on: Feb 4, 2020
 *      Author: zas
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

void Lcd_vidInit(void);
void Lcd_vidSendCommand(u8 Cmd);
void Lcd_vidWriteChar(u8 Char);
void step_1(void);
void step_2(void);

#endif /* LCD_INT_H_ */
