/*
 * Adc_int.h
 *
 *  Created on: Mar 10, 2020
 *  Author      : Heba Ramadan Taha
 */

#ifndef ADC_INT_H_
#define ADC_INT_H_

#include "Adc_cfg.h"

#define ADC_u8CH_0 0
#define ADC_u8CH_1 1
#define ADC_u8CH_2 2
#define ADC_u8CH_3 3
#define ADC_u8CH_4 4
#define ADC_u8CH_5 5
#define ADC_u8CH_6 6
#define ADC_u8CH_7 7

void Adc_vidInit(void);

#if ADC_ADJUST_VALUE == ADC_RIGHT_ADJUST
	u16 Adc_u16GetResult(u8 Chnl_Id);

#elif ADC_VREF_VALUE == ADC_LEFT_ADJUST
	u8 Adc_u16GetResult(u8 chnl_Id);

#endif


#endif /* ADC_INT_H_ */
