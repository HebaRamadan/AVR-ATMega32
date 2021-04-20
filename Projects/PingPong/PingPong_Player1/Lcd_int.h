/*
 * Lcd_int.h
 *
 *  Created on: Nov 30, 2020
 *      Author: Heba Ramadan
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

#define LCD_u8CMD_8_BIT_2x16_5x7 0x38
#define LCD_u8CMD_DISP_ON_CURS_OFF 0x0C
#define LCD_u8CMD_CLR_Display 0x01

void Lcd_vidInit(void);
void Lcd_vidSendCommand(u8 Cmd);
void Lcd_vidWriteChar(u8 Char);
void Lcd_vidSendString(u8 * Str);

void Lcd_vidWriteNumber(u32 Number);
void Lcd_vidStorePattern(u8 *pattern , u8 pattern_num);
void Lcd_vidSetPosition(u8 Row , u8 Col);


#endif /* LCD_INT_H_ */
