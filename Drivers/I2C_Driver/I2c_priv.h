/*
 * I2c_priv.h
 *
 *  Created on: Jun 29, 2020
 *      Author: zas
 */

#ifndef I2C_PRIV_H_
#define I2C_PRIV_H_


#define TWDR    (*(volatile I2C_TWDR_Type*) 0x23)
#define TWAR    (*(volatile I2C_TWAR_Type*) 0x22)
#define TWSR    (*(volatile I2C_TWSR_Type*) 0x21)
#define TWBR    (*(volatile I2C_TWBR_Type*) 0x20)
#define TWCR    (*(volatile I2C_TWCR_Type*) 0x56)


/*      TWCR Register     */
typedef union
{
	struct
	{
		u8 TWIE:1;         //Bit To Configure TWI Interrupt Enable
		u8 Bit:1;          //Reserved Bit
		u8 TWEN:1;         //Bit To Enable TWI
		u8 TWWC:1;         //TWI Write Collision Flag (1 -> You Try To Access TWDR Register While TWI Execute Job Now )
		u8 TWSTO:1;        //Bit To configure Stop Bit If It Act As Master Or Release Device in Slave Mode
	    u8 TWSTA:1;        //Bit To configure Start Bit In Master Mode
		u8 TWEA:1;         //Bit To configure TWI Acknowledge Bit
		u8 TWINT:1;        //Interrupt Flag which Raised After finishing Every Job ( SC , SLA_R_W+ACK , Data+ACK , RSC ,STC )

	}Bits;

	u8 Byte;

}I2C_TWCR_Type;



/*      TWSR Register     */
typedef union
{
	struct
	{
		u8 TWPS:2;         //2Bit To Configure TWI Pre_Scaler
		u8 Bit:1;          //Reserved Bit
		u8 TWS:5;          //5Bits To Represent Status of TWI After Every Job
	}Bits;

	u8 Byte;

}I2C_TWSR_Type;




/*      TWAR Register     */
typedef union
{
	struct
	{
		u8 WGCE:1;       //Bit  To Configure General Call Recognition
		u8 TWA:7;        //7Bit To Configure The Address Of Device
	}Bits;

	u8 Byte;

}I2C_TWAR_Type;




/*      TWDR Register     */
typedef union
{
	u8 Byte;        //Data Register To Read Or Write Data ( SLA_R_w , DATA_R_W )

}I2C_TWDR_Type;




/*      TWBR Register     */
typedef union
{

	u8 Byte;        //Register To Select The Value Of Bit_Rate
}I2C_TWBR_Type;



#endif /* I2C_PRIV_H_ */
