/*
 * SPI_Interface.h
 *
 *  Created on: Dec 23, 2020
 *      Author: zas
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#define SPI_u8DUMMY_DATA    0XFF

void Spi_vidMasterInit(void);
void Spi_vidSlaveInit (void);

u8   Spi_u8MasterTransfare(u8 Data);
u8   Spi_u8SlaveTransfare (u8 Data);

#endif /* SPI_INTERFACE_H_ */
