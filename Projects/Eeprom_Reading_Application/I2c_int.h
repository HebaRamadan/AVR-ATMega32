/*
 * I2c_int.h
 *
 *  Created on: Jun 29, 2020
 *      Author: zas
 */

#ifndef I2C_INT_H_
#define I2C_INT_H_

/* Status Codes for Master Transmitter Mode */
#define I2C_u8SC_TRASMITTER_MODE             0X08
#define I2C_u8RSC_TRASMITTER_MODE            0X10
#define I2C_u8SLA_W_TRASMITTER_MODE          0X18
#define I2C_u8DATA_TRASMITTER_MODE           0X28



/*  Status Codes for Master Receiver Mode  */
#define I2C_u8SC_RECEIVE_MODE                0X08
#define I2C_u8RSC_RECEIVE_MODE               0X10
#define I2C_u8SLA_R_RECEIVE_MODE             0X40
#define I2C_u8DATA_RECEIVE_MODE              0X50


void I2c_vidInit(void);

void I2c_vidSendStart(void);

void I2c_vidSendStop(void);

void I2c_vidSendSlaveAddess(u8 SlaveAddress_W_R);

void I2c_vidSendData(u8 Data);

u8   I2c_vidReceiveData(void);

u8   I2c_u8CheckStatus(u8 ExpectStatus);

#endif /* I2C_INT_H_ */
