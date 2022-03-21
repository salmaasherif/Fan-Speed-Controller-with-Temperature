/*
 * pwm.c
 *
 *  Created on: Oct 11, 2021
 *      Author: ahmed
 */
#include "avr/io.h"
#include "pwm.h"
PWM_Timer0_Start(uint8 duty_cycle){
	TCCR0=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS01);
	TCNT0=0;
	OCR0=(uint8)(((float32)duty_cycle/100)*255);
	DDRB|=(1<<PB3);
}

