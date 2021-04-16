/*
 * main.c
 *
 *  Created on: Feb 4, 2020
 *      Author: zas
 */
#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>
#include "Lcd_int.h"
#include "Lcd_int.h"

int main(void){
	 Lcd_vidInit();

	 while(1)
	 {
		 step_1();
		 step_2();

	 }
	 return 0;
}
