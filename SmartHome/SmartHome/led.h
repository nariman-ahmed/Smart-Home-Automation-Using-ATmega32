/*
 * led.h
 *
 *  Created on: 5 Oct 2024
 *      Author: HP
 */

#ifndef LED_H_
#define LED_H_
#include "gpio.h"

#define POSITIVE_LOGIC

typedef struct{
	uint8 PORT_ID;
	uint8 PIN_ID;
}LED_ID;

#ifdef POSITIVE_LOGIC
#define LED_ON                   LOGIC_HIGH
#define LED_OFF                  LOGIC_LOW
#endif

#ifdef NEGATIVE_LOGIC
#define LED_ON                   LOGIC_LOW
#define LED_OFF                  LOGIC_HIGH
#endif

#define LED_RED_PORT_ID          PORTB_ID
#define LED_RED_PIN_ID           PIN5_ID

#define LED_GREEN_PORT_ID        PORTB_ID
#define LED_GREEN_PIN_ID         PIN6_ID

#define LED_BLUE_PORT_ID         PORTB_ID
#define LED_BLUE_PIN_ID          PIN7_ID

#define FIRE_ALARM_LED_PORT_ID   PORTD_ID
#define FIRE_ALARM_LED_PIN_ID    PIN2_ID

void LEDS_init(void);

void LED_on(uint8 port_id,uint8 pin_id);

void LED_off(uint8 port_id,uint8 pin_id);


#endif /* LED_H_ */
