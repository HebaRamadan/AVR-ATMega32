/*
 * GLCD_int.h
 *
 *  Created on: May 10, 2020
 *      Author: zas
 */

#ifndef GLCD_INT_H_
#define GLCD_INT_H_
#define GLCD_u8CMD_DISP_ON  0x3F
#define GLCD_u8CMD_DISP_OFF 0x3E
#define TOTAL_PAGES 8
#define SELECT_CHIP_0   0
#define SELECT_CHIP_1   1
#define SELECT_CHIP_0_1 2

#define NUM_PIXEL_OF_PAGE 64


void GLCD_vidInit(void);
void GLCD_vidSendCommand(u8 Cmd);
void GLCD_vidSendData(u8 Data);
void GLCD_vidWriteChar(u8 Char);
void GLCD_vidWriteString(u8 *Str);
void GLCD_vidSelectChip(u8 Chip);
void GLCD_vidClearAll(void);
void GLCD_vidPrintPicture(const u8 *ptr);

#endif /* GLCD_INT_H_ */
