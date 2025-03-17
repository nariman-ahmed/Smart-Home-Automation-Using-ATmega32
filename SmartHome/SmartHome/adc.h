/*
 * adc.h
 *
 *  Created on: 3 Oct 2024
 *      Author: HP
 */

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

//DEFINE Vref, prescaler
#define ADC_REF_VOLT_VALUE     2.56
#define ADC_MAXIMUM_VALUE      1023
#define ADC_PRESCALER          128


//2 functions, init and read channel
void ADC_init(void);

uint16 ADC_readChannel(uint8 ch_num);

#endif /* ADC_H_ */
