#ifndef PWM_H_
#define PWM_H_

#define F_CPU 8000000


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

#endif /* PWM_H_ */


static uint16_t freq(uint16_t f_pwm,  uint16_t prescaler)
{

	uint16_t result = (F_CPU/(prescaler * (f_pwm)) - 1);
	return result;

}


void pwm_init(uint16_t top)
{

	DDRD|= (1<<PD5)|(1<<PD4);

	TCNT1 = 0;
	TCCR1A = (1 << COM1A1) | (1 << COM1B1)| (1 << WGM11);
	TCCR1B = (1 << WGM13) | (1 << WGM12)|(1<<CS11);
	ICR1 = top;

}

void set_duty(uint16_t A,uint16_t B)
{

	OCR1A = A;
	OCR1B = B;

}


int pwm_proc(int p) //Проценты в число
{
	unsigned int result;
	result = (p*255)/100;
	return	result;
}


int main(void)
{

	uint16_t top = freq(3000,8);
	pwm_init(top);

	

int i = 50;

	uint16_t dt1 = pwm_proc(i);
	set_duty(dt1,dt1);

	while (1)
	{
		
	
		

	}
	
}

