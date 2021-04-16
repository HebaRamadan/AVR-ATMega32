/*
 * Buzzer_prg.c
 *
 *  Created on: Feb 17, 2020
 *      Author: zas
 */

#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#include "Dio_int.h"
#include "Buzzer_cfg.h"
#include "Buzzer_int.h"

Buzzer_vidInit()
{
	Dio_vidSetPinDir(BUZZER_PIN , DIO_u8OUTPUT);
}

Buzzer_vidTurnOn()
{
	Dio_vidSetPinval(BUZZER_PIN , DIO_u8HIGH);
}

Buzzer_vidTurnOff()
{
	Dio_vidSetPinval(BUZZER_PIN , DIO_u8LOW);
}
