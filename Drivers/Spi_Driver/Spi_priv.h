/*
 * Spi_priv.h
 *
 *  Created on: Jun 28, 2020
 *      Author: zas
 */

#ifndef SPI_PRIV_H_
#define SPI_PRIV_H_

#define SPDR  (*(volatile u8*) 0x2F)
#define SPSR  (*(volatile u8*) 0x2E)
#define SPCR  (*(volatile u8*) 0x2D)

#endif /* SPI_PRIV_H_ */
