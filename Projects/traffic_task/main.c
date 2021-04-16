/*
 * main.c
 *
 *  Created on: Jan 20, 2020
 *      Author: zas
 */

#include "Std_types.h"
#include "Bit_math.h"
#include "Dio_int.h"
#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>
void sev_seg(u8 Led_num, u8 counter);
u8 Seg[10] = {0b1000000,  0b1111001, 0b0100100, 0b0110000, 0b0011001, 0b0010010, 0b0000010, 0b1111000, 0b0000000, 0b0010000};
u8 i;
int main(void)
{
	Dio_vidSetPinDir(8 , 1);
	Dio_vidSetPinDir(9 , 1);
	Dio_vidSetPinDir(10 , 1);

	for(i=0; i<7 ; i++)
	{
		Dio_vidSetPinDir(i , 1);
	}
	while(1)
	{
		sev_seg(8 , 10); //red led
		sev_seg(9 , 4); //yellow led
		sev_seg(10, 10); //green led
		sev_seg(9 , 4); //yellow led
	}

}

void sev_seg(u8 Led_num, u8 counter)
{
	for(i=counter; i>0 ;i--)
	{
		u8 j;
		u8 val;
		Dio_vidSetPinVal(Led_num , 1);

		for(j=0; j<7; j++)
		{
			val = ((Seg[i-1]>>j)&0x01);
			Dio_vidSetPinVal(j , val);
		}
		_delay_ms(1000);
	}
	Dio_vidSetPinVal(Led_num , 0);
}
