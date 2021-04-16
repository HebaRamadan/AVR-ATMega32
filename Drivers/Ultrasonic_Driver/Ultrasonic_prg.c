/*
 * Ultrasonic_prg.c
 *
 *  Created on: Apr 8, 2020
 *      Author: zas
 */
#include "../lib/Std_types.h"
#include "Dio_int.h"
#include "delay_int.h"
#include "Timer1_int.h"
#include "Ultrasonic_cfg.h"
#include "Ultrasonic_int.h"

void Ultrasonic_vidInit(void)
{
	Dio_vidSetPinDir(ULTRASONIC_u8TRIG_PIN , DIO_u8OUTPUT);
	Dio_vidSetPinDir(ULTRASONIC_u8ECHO_PIN , DIO_u8INPUT);
}


u16 Ultrasonic_u8GetDistance(void)
{
	u16 Timer_Value;
	u16 Distance;

	//Send signal with 10usec HIGH to trigger pin of Ultrasonic to start to send ultrasound wave
	Dio_vidSetPinVal(ULTRASONIC_u8TRIG_PIN , DIO_u8HIGH);
	MyDelayFunc_us(10);
	Dio_vidSetPinVal(ULTRASONIC_u8TRIG_PIN , DIO_u8LOW);

	//Check ECHO PIN if (ECHO = 0 mean transmitter of  Ultrasonic didn't send wave so waaaite)
	while(Dio_u8GetPinVal(ULTRASONIC_u8ECHO_PIN) == 0 );

	//(ECHO = 1)  Ultrasonic start to send wave Sooooo Start TIMER1
	Timer1_vidInit();

	//Waaaaite while Ultrasonic send wave
	while(Dio_u8GetPinVal(ULTRASONIC_u8ECHO_PIN) == 1 );

	//Ultrasonic  start to Receive wave
	Timer1_vidStopTimer();

	//Get the value of counter register
	Timer_Value = Timer1_u16GetTCNT1Val(); //Clk Freq is 1MHZ Sooo number of counts represent time with usec

	//Calculate Distance
	Distance = ((Timer_Value /58)/2);  //DataSheet Equation to calculate distance with cm

	return Distance;
}

