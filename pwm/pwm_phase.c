#include "pwm.h"


static uint16_t freq(uint16_t f;  uint16_t prescaler)
	{

		uint16_t result = (F_CPU/(prescaler*f)-1);
		return result;

	}


void pwm_init(uint16_t top,uint16_t prescaler)
	{

		DDRD|= (1<<5)|(1<<4);

		TCNT1 = 0;
		TCCR1A = (1 << COM1A1) | (1 << COM1B1)| (1 << WGM11);
		TCCR1B = (1 << WGM13) | (1 << WGM12);
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

/*
int main(void)
{

set_duty();

	while (1)
	{
		

	}
	
}

*/