/*
 * SmartHome.c
 *
 *  Created on: 5 Oct 2024
 *      Author: HP
 */
#include "gpio.h"
#include "lcd.h"
#include "adc.h"
#include "lm35.h"
#include "led.h"
#include "ldr.h"
#include "buzzer.h"
#include "pmw.h"
#include "dc_motor.h"
#include "flame_sensor.h"

void controlLighting(void);
void controlFan(void);
void printTitlesLCD(void);
void printTemp(void);
void printLDR(void);
void alertON(void);
void alertOFF(void);

uint8 LDR_light_intensity_value;
uint8 LM35_temperature_value;
uint8 flameSensorStatus;

int main(void){

	ADC_init();
	LCD_init();
	LEDS_init();
	BUZZER_init();
	FlameSensor_init();

	GPIO_setupPinDirection(INPUT1_PORT_ID,INPUT1_PIN_ID,PIN_OUTPUT);

	printTitlesLCD();

	while(1){

		flameSensorStatus=FlameSensor_getValue();

		if(!flameSensorStatus)
		{
//			/*set up LCD*/
//			LCD_clearScreen();
//			printTitlesLCD();

			/*printing LDR light intensity value*/
			printLDR();

			/*printing LM35 temperature value*/
			printTemp();

			/*control fan speed and direction based on temperature*/
			controlFan();

			/*control the three LEDs based on light intensity*/
			controlLighting();

			BUZZER_off();


		}

		if(flameSensorStatus)
		{
			LCD_clearScreen();

			LCD_displayString("Critical Alert!");

			BUZZER_on();

		}

	}

	return 0;
}

void controlLighting(void){

	if(LDR_light_intensity_value<15)
	{
		LED_on(LED_RED_PORT_ID,LED_RED_PIN_ID);
		LED_on(LED_GREEN_PORT_ID,LED_GREEN_PIN_ID);
		LED_on(LED_BLUE_PORT_ID,LED_BLUE_PIN_ID);
	}
	else if(LDR_light_intensity_value<50)
	{
		LED_on(LED_RED_PORT_ID,LED_RED_PIN_ID);
		LED_on(LED_GREEN_PORT_ID,LED_GREEN_PIN_ID);
		LED_off(LED_BLUE_PORT_ID,LED_BLUE_PIN_ID);
	}
	else if(LDR_light_intensity_value<70)
	{
		LED_on(LED_RED_PORT_ID,LED_RED_PIN_ID);
		LED_off(LED_GREEN_PORT_ID,LED_GREEN_PIN_ID);
		LED_off(LED_BLUE_PORT_ID,LED_BLUE_PIN_ID);
	}
	else if(LDR_light_intensity_value>70)
	{
		LED_off(LED_RED_PORT_ID,LED_RED_PIN_ID);
		LED_off(LED_GREEN_PORT_ID,LED_GREEN_PIN_ID);
		LED_off(LED_BLUE_PORT_ID,LED_BLUE_PIN_ID);
	}

}

void controlFan(void){

	if(LM35_temperature_value>=40)
	{
		DcMotor_Rotate(MOTOR_CW,100);
		LCD_displayStringRowColumn(0,10,"ON ");
	}
	else if(LM35_temperature_value>=35 && LM35_temperature_value<40)
	{
		DcMotor_Rotate(MOTOR_CW,75);
		LCD_displayStringRowColumn(0,10,"ON ");
	}
	else if(LM35_temperature_value>=30 && LM35_temperature_value<35)
	{
		DcMotor_Rotate(MOTOR_CW,50);
		LCD_displayStringRowColumn(0,10,"ON ");
	}
	else if(LM35_temperature_value>=25 && LM35_temperature_value<30)
	{
		DcMotor_Rotate(MOTOR_CW,25);
		LCD_displayStringRowColumn(0,10,"ON ");
	}
	else if(LM35_temperature_value<25)
	{
		DcMotor_Rotate(MOTOR_CW,0);
		LCD_displayStringRowColumn(0,10,"OFF");
	}

}

void printTitlesLCD(void){

	LCD_displayStringRowColumn(0,3,"FAN is ");
	LCD_displayStringRowColumn(1,0,"Temp=   LDR=   %");

}

void printTemp(void){

	LM35_temperature_value=LM35_getTemp();
	LCD_moveCursor(1,5);
	if(LM35_temperature_value >= 100)
	{
		LCD_integerToString(LM35_temperature_value);
	}
	else
	{
		LCD_integerToString(LM35_temperature_value);
		/* In case the digital value is two or one digits print space in the next digit place */
		LCD_displayCharacter(' ');
	}
}

void printLDR(void){

	LDR_light_intensity_value=LDR_getLightIntensity();
	LCD_moveCursor(1,12);
	if(LDR_light_intensity_value >= 100)
	{
		LCD_integerToString(LDR_light_intensity_value);
	}
	else
	{
		LCD_integerToString(LDR_light_intensity_value);
		/* In case the digital value is two or one digits print space in the next digit place */
		LCD_displayCharacter(' ');
	}
}

void alertON(void){

}

void alertOFF(void){

}


