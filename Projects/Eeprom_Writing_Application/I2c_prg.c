#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#include "I2c_priv.h"
#include "I2c_int.h"


void I2c_vidInit(void)
{
	/* Enable I2C */
	TWCR.Bits.TWEN = 1;

	/* Enable Receiver Acknowledge */
	TWCR.Bits.TWEA =1;

	/* Select SCL = Fcpu / (16 + (2xTWBRX4^TWPS)) = 250KHZ */
	TWBR.Byte = 2;
	TWSR.Bits.TWPS = 0;

	/* Device Own Address = 1 and Disable General Call */
	TWAR.Bits.WGCE = 0;
	TWAR.Bits.TWA  = 1;
}


void I2c_vidSendStart(void)
{

	/* Update Value In TWCR Register
	 * Send Start Bit
	 * Clear Flag                  */
	TWCR.Byte = (1<<TWINT_BIT) | (1<<TWSTA_BIT) | (1<<TWEN_BIT);

	/* Wait Till The Job Done */
	while(TWCR.Bits.TWINT == 0);

}


void I2c_vidSendStop(void)
{

	/* Update Value In TWCR Register
	 * Send Stop Bit
	 * Clear Start Bit
	 * Clear Flag                  */
	TWCR.Byte = (1<<TWINT_BIT) | (1<<TWSTO_BIT) | (1<<TWEN_BIT);

}


void I2c_vidSendSlaveAddess(u8 SlaveAddress_W_R)
{

	/*  Load SLA in TWDR */
	TWDR.Byte = SlaveAddress_W_R ;

	/* Update Value In TWCR Register
	 * Clear Start Bit
	 * Clear Flag                  */
	TWCR.Byte = (1<<TWINT_BIT) | (1<<TWEN_BIT);


	/* Wait Till The Job Done */
	while(TWCR.Bits.TWINT == 0);

}


void I2c_vidSendData(u8 Data)
{

	/*  Load SLA in TWDR */
	TWDR.Byte = Data ;

	/* Update Value In TWCR Register
	 * Clear Start Bit
	 * Clear Flag                  */
	TWCR.Byte = (1<<TWINT_BIT) | (1<<TWEN_BIT);

	/* Wait Till The Job Done */
	while(TWCR.Bits.TWINT == 0);

}


u8   I2c_vidReceiveData(void)
{

	/* Update Value In TWCR Register
	 * Clear Start Bit
	 * Clear Flag                  */
	TWCR.Byte = (1<<TWINT_BIT) | (1<<TWEN_BIT);

	/* Wait Till The Job Done */
	while(TWCR.Bits.TWINT == 0);

	/* Return The Receive Data */
	return TWDR.Byte;

}


u8   I2c_u8CheckStatus(u8 ExpectStatus)
{

	if(ExpectStatus == (TWSR.Byte & 0xF8))   //0b1111 1000
	{
		return 1;
	}
	return 0;

}
