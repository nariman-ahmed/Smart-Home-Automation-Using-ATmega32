/*
 * led.c
 *
 *  Created on: 5 Oct 2024
 *      Author: HP
 */
#include "led.h"

void LEDS_init(void){

	/*Set up pin direction for the three LDR leds*/
	GPIO_setupPinDirection(LED_RED_PORT_ID,LED_RED_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LED_GREEN_PORT_ID,LED_GREEN_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LED_BLUE_PORT_ID,LED_BLUE_PIN_ID,PIN_OUTPUT);

	/*set up pin direction for fire alarm led*/
	GPIO_setupPinDirection(FIRE_ALARM_LED_PORT_ID,FIRE_ALARM_LED_PIN_ID,PIN_OUTPUT);

	/*initialize all to zero*/
	GPIO_writePin(LED_RED_PORT_ID,LED_RED_PIN_ID,LOGIC_LOW);
	GPIO_writePin(LED_GREEN_PORT_ID,LED_GREEN_PIN_ID,LOGIC_LOW);
	GPIO_writePin(LED_BLUE_PORT_ID,LED_BLUE_PIN_ID,LOGIC_LOW);
	GPIO_writePin(FIRE_ALARM_LED_PORT_ID,FIRE_ALARM_LED_PIN_ID,LOGIC_LOW);

}

void LED_on(uint8 port_id,uint8 pin_id){

	GPIO_writePin(port_id,pin_id,LED_ON);

}

void LED_off(uint8 port_id,uint8 pin_id){

	GPIO_writePin(port_id,pin_id,LED_OFF);

}


