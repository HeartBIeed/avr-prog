#include "pwm.h"



static void pwm_phcorr_init(uint16_t f;  uint16_t prescaler)
	{

		uint16_t result = (F_CPU/(prescaler * (f_pwm)) - 1);

		DDRD|= (1<<PD5)|(1<<PD4);

		TCNT1 = 0;
		TCCR1A = (1 << COM1A1) | (1 << COM1B1)| (1 << WGM11);
		TCCR1B = (1 << WGM13) | (1 << WGM12)|(1<<CS11);
		ICR1 = result;

	}

void set_duty(uint8_t A,uint8_t B)
	{

		OCR1A = A;
		OCR1B = B;

	}


int pwm_proc(uint8_t p) //Проценты в число
	{
		uint8_t result;
		result = (p*255)/100;
		return	result;
	}


int main(void)
{
	uint8_t A = pwm_proc(40);
	uint8_t B = pwm_proc(80);

	pwm_phcorr_init(20000,8);
	set_duty(A,B);

	while (1)
	{
			

	}
		
}

