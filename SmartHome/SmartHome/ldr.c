/*
 * ldr.c
 *
 *  Created on: 5 Oct 2024
 *      Author: HP
 */
#include "ldr.h"
#include "adc.h"

uint8 LDR_getLightIntensity(void){
	//ayzeen nekteb el equation el kbeera 3shan ngeeb el temp men el digital value
	uint8 actualLightIntensity;

	uint16 digitalLdrValue= ADC_readChannel(LDR_SENSOR_CHANNEL);

	actualLightIntensity=(uint8)(((uint16)digitalLdrValue*ADC_REF_VOLT_VALUE*LDR_SENSOR_MAX_LIGHT_INTENSITY)/(LDR_SENSOR_MAX_VOLT_VALUE*ADC_MAXIMUM_VALUE));

	return actualLightIntensity;
}


