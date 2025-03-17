/*
 * flame_sensor.c
 *
 *  Created on: 6 Oct 2024
 *      Author: HP
 */
#include "flame_sensor.h"


void FlameSensor_init(void){

	GPIO_setupPinDirection(FLAME_INPUT_PORT_ID,FLAME_INPUT_PIN_IN,PIN_INPUT);

}

uint8 FlameSensor_getValue(void){

	uint8 value = GPIO_readPin(FLAME_INPUT_PORT_ID,FLAME_INPUT_PIN_IN);

	return value;

}

