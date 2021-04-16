/*
 * Eeprom_int.h
 *
 *  Created on: Jun 30, 2020
 *      Author: zas
 */

#ifndef EEPROM_INT_H_
#define EEPROM_INT_H_

#define Device_0 0
#define Device_1 1

void Eeprom_vidInit(void);

u8   Eeprom_u8WiteByte(u8 DeviceId , u16 Location , u8 Byte);

u8   Eeprom_u8ReadByte(u8 DeviceId , u16 Location , u8* pByte);

void Eeprom_u8ClearDevice(u8 DeviceId , u16 Num_Location);


#endif /* EEPROM_INT_H_ */
