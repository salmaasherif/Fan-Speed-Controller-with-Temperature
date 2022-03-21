/*
 * main.c
 *
 *  Created on: Oct 11, 2021
 *      Author: Ahmed Haggag
 */
#include "lcd.h"
#include "lm35_sensor.h"
#include "adc.h"
#include "dc_motor.h"
#include "pwm.h"
void main(void){
	DcMotor_Init();
	LCD_init();
	ADC_ConfigType adc_config = {INTERNAL_V,F_CPU_8};
	ADC_init(&adc_config);
	uint8 temperature;
	char * fan_condition="OFF";
	while(1){
		//LCD_intgerToString(ADC_readChannel(2));
		//	if(temperature >= 100){
		//		LCD_intgerToString(temperature);
		//	}
		//	else{
		//		LCD_intgerToString(temperature);
		//		/* In case the digital value is two or one digits print space in the next digit place */
		//		LCD_displayCharacter(' ');
		temperature=LM35_getTemperature();
		if(temperature<30){
			fan_condition="OFF";
			DcMotor_Rotate(STOP,0);
		}
		else if(temperature>=30 && temperature <60){
			fan_condition="ON ";
			DcMotor_Rotate(CW,25);
		}
		else if(temperature>=60 && temperature < 90){
			fan_condition="ON";
			DcMotor_Rotate(CW,50);
		}
		else if(temperature>=90 && temperature < 120){
			fan_condition="ON";
			DcMotor_Rotate(CW,75);

		}
		else if(temperature >= 120){
			fan_condition="ON";
			DcMotor_Rotate(CW,100);

		}
		LCD_displayStringRowColumn(0,2,"Fan is ");
		LCD_displayStringRowColumn(0,9,fan_condition);

		LCD_displayStringRowColumn(1,2,"Temp = ");
		LCD_intgerToString(temperature);

		if(temperature<100 || temperature <10){
		LCD_displayCharacter(' ');
		}
		LCD_displayStringRowColumn(1,12,"C");
	}
}
