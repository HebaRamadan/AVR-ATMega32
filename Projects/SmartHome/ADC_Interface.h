/*
 * ADC_Interface.h
 *
 *  Created on: Dec 7, 2020
 *      Author: zas
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define Chnl_Id_0 0
#define Chnl_Id_1 1

void __vector_16 (void) __attribute__ ((signal,used, externally_visible)); //ADC ISR (Conversion Complete)

void Adc_vidInit(void);
u16 Adc_u16GetResult(void);

#endif /* ADC_INTERFACE_H_ */
