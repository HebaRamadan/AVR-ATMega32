/*
 * Dio_prg.c
 *
 *  Created on: Feb 19, 2020
 *      Author: zas
 */
#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#include "Dio_int.h"
#include "Dio_priv.h"

void Dio_vidSetPinDir(u8 Pin , u8 Dir)
{
	u8 PortId;
	u8 PinLoc;

	PortId = Pin/8;
	PinLoc = Pin%8;

	switch(PortId){
		case 0:
			if(Dir ==1)
				{
					switch(PinLoc)
					{
						case 0:
							DDRA.Bits.Pin0 =1;
						break;

						case 1:
							DDRA.Bits.Pin1 =1;
						break;

						case 2:
							DDRA.Bits.Pin2 =1;
						break;

						case 3:
							DDRA.Bits.Pin3 =1;
						break;

						case 4:
							DDRA.Bits.Pin4 =1;
						break;

						case 5:
							DDRA.Bits.Pin5 =1;
						break;

						case 6:
							DDRA.Bits.Pin6 =1;
						break;

						case 7:
							DDRA.Bits.Pin7 =1;
						break;
					}
				}
			else
			{
				switch(PinLoc)
				{
					case 0:
						DDRA.Bits.Pin0 =0;
					break;

					case 1:
						DDRA.Bits.Pin1 =0;
					break;

					case 2:
						DDRA.Bits.Pin2 =0;
					break;

					case 3:
						DDRA.Bits.Pin3 =0;
					break;

					case 4:
						DDRA.Bits.Pin4 =0;
					break;

					case 5:
						DDRA.Bits.Pin5 =0;
					break;

					case 6:
						DDRA.Bits.Pin6 =0;
					break;

					case 7:
						DDRA.Bits.Pin7 =0;
					break;
				}
			}
		break;

		case 1:
			if(Dir ==1)
				{
					switch(PinLoc)
					{
						case 0:
							DDRB.Bits.Pin0 =1;
						break;

						case 1:
							DDRB.Bits.Pin1 =1;
						break;

						case 2:
							DDRB.Bits.Pin2 =1;
						break;

						case 3:
							DDRB.Bits.Pin3 =1;
						break;

						case 4:
							DDRB.Bits.Pin4 =1;
						break;

						case 5:
							DDRB.Bits.Pin5 =1;
						break;

						case 6:
							DDRB.Bits.Pin6 =1;
						break;

						case 7:
							DDRB.Bits.Pin7 =1;
						break;
					}
				}
			else
			{
				switch(PinLoc)
				{
					case 0:
						DDRB.Bits.Pin0 =0;
					break;

					case 1:
						DDRB.Bits.Pin1 =0;
					break;

					case 2:
						DDRB.Bits.Pin2 =0;
					break;

					case 3:
						DDRB.Bits.Pin3 =0;
					break;

					case 4:
						DDRB.Bits.Pin4 =0;
					break;

					case 5:
						DDRB.Bits.Pin5 =0;
					break;

					case 6:
						DDRB.Bits.Pin6 =0;
					break;

					case 7:
						DDRB.Bits.Pin7 =0;
					break;
				}
			}
			break;

		case 2:
			if(Dir ==1)
				{
					switch(PinLoc)
					{
						case 0:
							DDRC.Bits.Pin0 =1;
						break;

						case 1:
							DDRC.Bits.Pin1 =1;
						break;

						case 2:
							DDRC.Bits.Pin2 =1;
						break;

						case 3:
							DDRC.Bits.Pin3 =1;
						break;

						case 4:
							DDRC.Bits.Pin4 =1;
						break;

						case 5:
							DDRC.Bits.Pin5 =1;
						break;

						case 6:
							DDRC.Bits.Pin6 =1;
						break;

						case 7:
							DDRC.Bits.Pin7 =1;
						break;
					}
				}
			else
			{
				switch(PinLoc)
				{
					case 0:
						DDRC.Bits.Pin0 =0;
					break;

					case 1:
						DDRC.Bits.Pin1 =0;
					break;

					case 2:
						DDRC.Bits.Pin2 =0;
					break;

					case 3:
						DDRC.Bits.Pin3 =0;
					break;

					case 4:
						DDRC.Bits.Pin4 =0;
					break;

					case 5:
						DDRC.Bits.Pin5 =0;
					break;

					case 6:
						DDRC.Bits.Pin6 =0;
					break;

					case 7:
						DDRC.Bits.Pin7 =0;
					break;
				}
			}
		break;


		case 3:
			if(Dir ==1)
				{
					switch(PinLoc)
					{
						case 0:
							DDRD.Bits.Pin0 =1;
						break;

						case 1:
							DDRD.Bits.Pin1 =1;
						break;

						case 2:
							DDRD.Bits.Pin2 =1;
						break;

						case 3:
							DDRD.Bits.Pin3 =1;
						break;

						case 4:
							DDRD.Bits.Pin4 =1;
						break;

						case 5:
							DDRD.Bits.Pin5 =1;
						break;

						case 6:
							DDRD.Bits.Pin6 =1;
						break;

						case 7:
							DDRD.Bits.Pin7 =1;
						break;
					}
				}
			else
			{
				switch(PinLoc)
				{
					case 0:
						DDRD.Bits.Pin0 =0;
					break;

					case 1:
						DDRD.Bits.Pin1 =0;
					break;

					case 2:
						DDRD.Bits.Pin2 =0;
					break;

					case 3:
						DDRD.Bits.Pin3 =0;
					break;

					case 4:
						DDRD.Bits.Pin4 =0;
					break;

					case 5:
						DDRD.Bits.Pin5 =0;
					break;

					case 6:
						DDRD.Bits.Pin6 =0;
					break;

					case 7:
						DDRD.Bits.Pin7 =0;
					break;
				}
			}
		break;
	}
}

void Dio_vidSetPinVal(u8 Pin , u8 Val)
{
	u8 PortId;
	u8 PinLoc;

	PortId = Pin/8;
	PinLoc = Pin%8;

	switch(PortId){
		case 0:
			if(Val ==1)
				{
					switch(PinLoc)
					{
						case 0:
							PORTA.Bits.Pin0 =1;
						break;

						case 1:
							PORTA.Bits.Pin1 =1;
						break;

						case 2:
							PORTA.Bits.Pin2 =1;
						break;

						case 3:
							PORTA.Bits.Pin3 =1;
						break;

						case 4:
							PORTA.Bits.Pin4 =1;
						break;

						case 5:
							PORTA.Bits.Pin5 =1;
						break;

						case 6:
							PORTA.Bits.Pin6 =1;
						break;

						case 7:
							PORTA.Bits.Pin7 =1;
						break;
					}
				}
			else
			{
				switch(PinLoc)
				{
					case 0:
						PORTA.Bits.Pin0 =0;
					break;

					case 1:
						PORTA.Bits.Pin1 =0;
					break;

					case 2:
						PORTA.Bits.Pin2 =0;
					break;

					case 3:
						PORTA.Bits.Pin3 =0;
					break;

					case 4:
						PORTA.Bits.Pin4 =0;
					break;

					case 5:
						PORTA.Bits.Pin5 =0;
					break;

					case 6:
						PORTA.Bits.Pin6 =0;
					break;

					case 7:
						PORTA.Bits.Pin7 =0;
					break;
				}
			}
		break;

		case 1:
			if(Val ==1)
				{
					switch(PinLoc)
					{
						case 0:
							PORTB.Bits.Pin0 =1;
						break;

						case 1:
							PORTB.Bits.Pin1 =1;
						break;

						case 2:
							PORTB.Bits.Pin2 =1;
						break;

						case 3:
							PORTB.Bits.Pin3 =1;
						break;

						case 4:
							PORTB.Bits.Pin4 =1;
						break;

						case 5:
							PORTB.Bits.Pin5 =1;
						break;

						case 6:
							PORTB.Bits.Pin6 =1;
						break;

						case 7:
							PORTB.Bits.Pin7 =1;
						break;
					}
				}
			else
			{
				switch(PinLoc)
				{
					case 0:
						PORTB.Bits.Pin0 =0;
					break;

					case 1:
						PORTB.Bits.Pin1 =0;
					break;

					case 2:
						PORTB.Bits.Pin2 =0;
					break;

					case 3:
						PORTB.Bits.Pin3 =0;
					break;

					case 4:
						PORTB.Bits.Pin4 =0;
					break;

					case 5:
						PORTB.Bits.Pin5 =0;
					break;

					case 6:
						PORTB.Bits.Pin6 =0;
					break;

					case 7:
						PORTB.Bits.Pin7 =0;
					break;
				}
			}
			break;

		case 2:
			if(Val ==1)
				{
					switch(PinLoc)
					{
						case 0:
							PORTC.Bits.Pin0 =1;
						break;

						case 1:
							PORTC.Bits.Pin1 =1;
						break;

						case 2:
							PORTC.Bits.Pin2 =1;
						break;

						case 3:
							PORTC.Bits.Pin3 =1;
						break;

						case 4:
							PORTC.Bits.Pin4 =1;
						break;

						case 5:
							PORTC.Bits.Pin5 =1;
						break;

						case 6:
							PORTC.Bits.Pin6 =1;
						break;

						case 7:
							PORTC.Bits.Pin7 =1;
						break;
					}
				}
			else
			{
				switch(PinLoc)
				{
					case 0:
						PORTC.Bits.Pin0 =0;
					break;

					case 1:
						PORTC.Bits.Pin1 =0;
					break;

					case 2:
						PORTC.Bits.Pin2 =0;
					break;

					case 3:
						PORTC.Bits.Pin3 =0;
					break;

					case 4:
						PORTC.Bits.Pin4 =0;
					break;

					case 5:
						PORTC.Bits.Pin5 =0;
					break;

					case 6:
						PORTC.Bits.Pin6 =0;
					break;

					case 7:
						PORTC.Bits.Pin7 =0;
					break;
				}
			}
		break;


		case 3:
			if(Val ==1)
				{
					switch(PinLoc)
					{
						case 0:
							PORTD.Bits.Pin0 =1;
						break;

						case 1:
							PORTD.Bits.Pin1 =1;
						break;

						case 2:
							PORTD.Bits.Pin2 =1;
						break;

						case 3:
							PORTD.Bits.Pin3 =1;
						break;

						case 4:
							PORTD.Bits.Pin4 =1;
						break;

						case 5:
							PORTD.Bits.Pin5 =1;
						break;

						case 6:
							PORTD.Bits.Pin6 =1;
						break;

						case 7:
							PORTD.Bits.Pin7 =1;
						break;
					}
				}
			else
			{
				switch(PinLoc)
				{
					case 0:
						PORTD.Bits.Pin0 =0;
					break;

					case 1:
						PORTD.Bits.Pin1 =0;
					break;

					case 2:
						PORTD.Bits.Pin2 =0;
					break;

					case 3:
						PORTD.Bits.Pin3 =0;
					break;

					case 4:
						PORTD.Bits.Pin4 =0;
					break;

					case 5:
						PORTD.Bits.Pin5 =0;
					break;

					case 6:
						PORTD.Bits.Pin6 =0;
					break;

					case 7:
						PORTD.Bits.Pin7 =0;
					break;
				}
			}
		break;
	}
}


