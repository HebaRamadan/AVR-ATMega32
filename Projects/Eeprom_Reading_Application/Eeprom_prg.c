/*
 * Eeprom_prg.c
 *
 *  Created on: Jun 30, 2020
 *      Author: zas
 */
#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>
#include "I2c_int.h"
#include "Eeprom_priv.h"
#include "Eeprom_int.h"

void Eeprom_vidInit(void)
{
	/* Initialize I2C AS Communication Protocol To Connect MCU With EEPROM */
	I2c_vidInit();

}



u8   Eeprom_u8WiteByte(u8 DeviceId , u16 Location , u8 Byte)
{
	/**********************************************************
	 * 1-Send Start
	 * 2-Check Status
	 * 3-Send Slave Address With Write Bit
	 * 4-Check Status
	 * 5-Send Location "Location For EEPROM But Data For I2C"
	 * 6-Check Status
	 * 7-Send Byte
	 * 8-Check Status
	 * 9-Send Stop
	 **********************************************************/

	/* Local Variable To save Slave Address */
	u8 SLA;

	/* At first Select Slave Address */
	if(DeviceId == Device_0)
	{
		/* Select Slave Address depend on Device Address_0 and Page num from Location Variable */
		SLA = EEPROM_u8DEVICE_ADRESS_0 | ((Location >> 8) << 1);
	}
	else if(DeviceId == Device_1)
	{
		/* Select Slave Address depend on Device Address_1 and Page num from Location Variable */
		SLA = EEPROM_u8DEVICE_ADRESS_1 | ((Location >> 8) << 1);
	}

	/* Send Start Bit */
	I2c_vidSendStart();

	/* Check Status */
	if(I2c_u8CheckStatus(I2C_u8SC_TRASMITTER_MODE) == 1)
	{
		/* Send Slave Address With Write Bit */
		I2c_vidSendSlaveAddess(SLA);

		/* Check Status */
		if(I2c_u8CheckStatus(I2C_u8SLA_W_TRASMITTER_MODE)== 1)
		{
			/* Send Location "Location For EEPROM But Data For I2C" */
			I2c_vidSendData( (u8)Location );

			/* Check Status */
			if(I2c_u8CheckStatus(I2C_u8DATA_TRASMITTER_MODE)== 1)
			{
				/* Send Byte */
				I2c_vidSendData(Byte);

				/* Check Status */
				if(I2c_u8CheckStatus(I2C_u8DATA_TRASMITTER_MODE)== 1)
				{
					/* Send Stop */
					I2c_vidSendStop();

					/* Return 1 To Reflect Data Written WELL*/
					return 1;
				}

			}

		}
	}
	/* Return 0 To Reflect Error*/
	return 0;
}



u8   Eeprom_u8ReadByte(u8 DeviceId , u16 Location , u8* pByte)
{
	/**********************************************************
	 * 1-Send Start
	 * 2-Check Status
	 * 3-Send Slave Address With Write Bit
	 * 4-Check Status
	 * 5-Send Location "Location For EEPROM But Data For I2C"
	 * 6-Check Status
	 * 7-Send Start "Repeated Start"
	 * 8-Check Status
	 * 9-Send Slave Address With Read Bit
	 * 10-Check Status
	 * 11-Read The Received Byte
	 * 12-Send Stop
	 **********************************************************/

	/* Local Variable To save Slave Address */
	u8 SLA;

	/* At first Select Slave Address */
	if(DeviceId == Device_0)
	{
		/* Select Slave Address depend on Device Address_0 and Page num from Location Variable */
		SLA = EEPROM_u8DEVICE_ADRESS_0 | ((Location >> 8) << 1);
	}
	else if(DeviceId == Device_1)
	{
		/* Select Slave Address depend on Device Address_1 and Page num from Location Variable */
		SLA = EEPROM_u8DEVICE_ADRESS_1 | ((Location >> 8) << 1);
	}

	/* Send Start Bit */
	I2c_vidSendStart();

	/* Check Status */
	if(I2c_u8CheckStatus(I2C_u8SC_TRASMITTER_MODE) == 1)
	{
		/* Send Slave Address With Write Bit */
		I2c_vidSendSlaveAddess(SLA);

		/* Check Status */
		if(I2c_u8CheckStatus(I2C_u8SLA_W_TRASMITTER_MODE)== 1)
		{
			/* Send Location "Location For EEPROM But Data For I2C" */
			I2c_vidSendData( (u8)Location );

			/* Check Status */
			if(I2c_u8CheckStatus(I2C_u8DATA_TRASMITTER_MODE)== 1)
			{
				/* Send Start "Repeated Start" */
				I2c_vidSendStart();

				/* Check Status */
				if(I2c_u8CheckStatus(I2C_u8RSC_TRASMITTER_MODE)== 1)
				{
					/* Send Slave Address With Read Bit */
					I2c_vidSendSlaveAddess( (SLA | 0x01) );

					/* Check Status */
					if(I2c_u8CheckStatus(I2C_u8SLA_R_RECEIVE_MODE)== 1)
					{
						/* Read The Received Byte */
						*pByte = I2c_vidReceiveData();
						/* Send Stop */
						I2c_vidSendStop();

						/* Return 1 To Reflect Data Read WELL*/
						return 1;
					}

				}


			}

		}
	}
	/* Return 0 To Reflect Error*/
	return 0;

}



void Eeprom_u8ClearDevice(u8 DeviceId , u16 Num_Location)
{
	u16 i;

	if(DeviceId == Device_0)
	{
		for(i=0; i<Num_Location; i++)
		{
			Eeprom_u8WiteByte(Device_0 , i , 0);
			_delay_ms(10);
		}
	}
	else if(DeviceId == Device_1)
	{
		for(i=0; i<Num_Location; i++)
		{
			Eeprom_u8WiteByte(Device_1 , i , 0);
			_delay_ms(10);
		}
	}

}
