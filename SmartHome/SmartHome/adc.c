/*
 * adc.c
 *
 *  Created on: 3 Oct 2024
 *      Author: HP
 */
#include "adc.h"
#include <avr/io.h>
#include "common_macros.h"

void ADC_init(void){
	//hanzabat el 2 registers, ADCMUX, ADCSRA
	ADMUX |= (1<<REFS1)|(1<<REFS0);

	ADCSRA |=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}

uint16 ADC_readChannel(uint8 ch_num){

	//nekhtar el channel me ADMUX, clear first 5 bits in admux and add ur 3 bits
	ADMUX=(ADMUX&0xE0)|(ch_num&0x07);

	//start consversion
	ADCSRA|=(1<<ADSC);

	//polling
	while(BIT_IS_CLEAR(ADCSRA,ADIF));

	SET_BIT(ADCSRA,ADIF);

	//return digital value
	return ADC;
}


