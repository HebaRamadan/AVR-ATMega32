/*
 * Internal_EEPROM_int.h
 *
 *  Created on: Aug 7, 2020
 *      Author: zas
 */

#ifndef INTERNAL_EEPROM_INT_H_
#define INTERNAL_EEPROM_INT_H_

#define  EEMEM __attribute__((section(".eeprom")))

void Eeprom_vidWriteByte( u16 Address  , u8 Data);
void Eeprom_vidUpdateByte( u16 Address , u8 Data);
u8   Eeprom_u8ReadByte( u16 Address );

#endif /* INTERNAL_EEPROM_INT_H_ */
