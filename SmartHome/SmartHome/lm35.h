/*
 * tempSensor.h
 *
 *  Created on: 3 Oct 2024
 *      Author: HP
 */

#ifndef LM35_H_
#define LM35_H_

#include "std_types.h"

#define TEMP_SENSOR_CHANNEL                  1
#define TEMP_SENSOR_MAXIMUM_TEMP_VALUE       150
#define TEMP_SENSOR_MAXIMUM_VOLTAGE_VALUE    1.5

uint8 LM35_getTemp(void);

#endif /* LM35_H_ */
