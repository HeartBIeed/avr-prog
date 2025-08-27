#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

#endif /* MAIN_H_ */


void init_PWM(void)
{
	
DDRB|=(1<<3); //PB3

TCNT0 = 0;
TCCR0 = (1 << WGM00) | (1 << WGM01)|(1 << COM01)|(1 << CS01)|(1 << CS00); // FastPWM / предделитель




}

int pwm_proc(int p) //Проценты в число
{
	unsigned int result;
	result = (p*255)/100;
	return	result;
}

int main(void)
{
	init_PWM();

	
	while (1)
	{
		
		OCR0 = pwm_proc(10); //10%

	}
	
}