/*
 * tempSensor.c
 *
 *  Created on: 3 Oct 2024
 *      Author: HP
 */
#include "lm35.h"
#include "adc.h"

uint8 LM35_getTemp(void){
	//ayzeen nekteb el equation el kbeera 3shan ngeeb el temp men el digital value
	uint8 actualTemp;

	uint16 digitalTemp= ADC_readChannel(TEMP_SENSOR_CHANNEL);

	actualTemp=(uint8)(((uint16)digitalTemp*ADC_REF_VOLT_VALUE*TEMP_SENSOR_MAXIMUM_TEMP_VALUE)/(TEMP_SENSOR_MAXIMUM_VOLTAGE_VALUE*ADC_MAXIMUM_VALUE));

	return actualTemp;
}


