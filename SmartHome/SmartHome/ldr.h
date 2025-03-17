/*
 * ldr.h
 *
 *  Created on: 5 Oct 2024
 *      Author: HP
 */

#ifndef LDR_H_
#define LDR_H_

#include "std_types.h"

#define LDR_SENSOR_CHANNEL               0
#define LDR_SENSOR_MAX_VOLT_VALUE        2.56
#define LDR_SENSOR_MAX_LIGHT_INTENSITY   100

uint8 LDR_getLightIntensity(void);

#endif /* LDR_H_ */
