/*
 * flame_sensor.h
 *
 *  Created on: 6 Oct 2024
 *      Author: HP
 */

#ifndef FLAME_SENSOR_H_
#define FLAME_SENSOR_H_

#include "std_types.h"
#include "gpio.h"

#define FLAME_INPUT_PORT_ID       PORTD_ID
#define FLAME_INPUT_PIN_IN        PIN2_ID

void FlameSensor_init(void);

uint8 FlameSensor_getValue(void);

#endif /* FLAME_SENSOR_H_ */
