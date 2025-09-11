#include "pwm.h"


static uint16_t freq(uint16_t f;  uint16_t prescaler)
	{

		uint16_t result = (F_CPU/(prescale*f_pwm) - 1);
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

top = freq(20000,8);
pwm_init();

set_duty(top/2,top/4);

	while (1)
	{
		

	}
	
}

