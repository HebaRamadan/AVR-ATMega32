/*
 * Adc_int.h
 *
 *  Created on: Mar 1, 2020
 *      Author: zas
 */

#ifndef ADC_INT_H_
#define ADC_INT_H_

#define ADC_u8CH_0 0
#define ADC_u8CH_1 1
#define ADC_u8CH_2 2
#define ADC_u8CH_3 3
#define ADC_u8CH_4 4
#define ADC_u8CH_5 5
#define ADC_u8CH_6 6
#define ADC_u8CH_7 7

void Adc_vidInit(void);
u16 Adc_u16GetResult(u8 chnl_Id);

#endif /* ADC_INT_H_ */
