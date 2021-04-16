/*
 * LCD_Private.h
 *
 *  Created on: Dec 8, 2020
 *      Author: zas
 */

#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_


#define concf(LINES,PIXELS)         concf_Help(LINES, PIXELS)
#define concf_Help(LINES,PIXELS)    0b0011##LINES##PIXELS##00

#define FUNCTION_SET		        concf(LINES , PIXELS)


#define concd(DISPLAY_MODE,CURSOR_MODE,BLINK_MODE)         concd_Help(DISPLAY_MODE,CURSOR_MODE,BLINK_MODE)
#define concd_Help(DISPLAY_MODE,CURSOR_MODE,BLINK_MODE)    0b00001##DISPLAY_MODE##CURSOR_MODE##BLINK_MODE

#define DISPLAY_ON_LCD		       						   concd(DISPLAY_MODE,CURSOR_MODE,BLINK_MODE)


#define concc(CLRDISPLAY)           concc_Help(CLRDISPLAY)
#define concc_Help(CLRDISPLAY)      0b0000000##CLRDISPLAY

#define CLEAR_DISPLAY		        concc(CLRDISPLAY)


#endif /* LCD_PRIVATE_H_ */
