/*
 * Lcd_int.h
 *
 *  Created on: Feb 7, 2020
 *      Author: zas
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_
#define LCD_u8CMD_4_BIT_2x16_5x7 0x28
#define LCD_u8CMD_DISP_ON_CURS_OFF 0x0C
#define LCD_u8CMD_CLR_Display 0x01

void Lcd_vidInit(void);
void Lcd_vidSendCommand(u8 Cmd);
void Lcd_vidWriteChar(u8 Char);
void Lcd_vidWriteStr(u8 *Str);

#endif /* LCD_INT_H_ */
