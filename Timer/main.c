#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint32_t  ms_cnt= 0;// счетчик ms


void timer_ini(void) // timer0
 {
    TCCR0 = (1<<WGM01)|(1<<CS00)|(1<<CS01); // Вкл СТС, Выбор делителя частота/64
    TIMSK |=(1<<OCIE0); // Включение прерывания по совпадению  (СТС)
//  TIMSK |=(1<<TOIE0); // Включение прерывания по переполнению

    OCR0 = 125; // числа для сравнения
    
 }

ISR(TIMER0_COMP_vect) //Обработка прерывания. В скобках вектор пр-ния по переполнению
 {
	ms_cnt++;
 }

DDRA = 0xFF;
PORTA = 0x00;

int get_mills() // получение миллисекунд
 {
	uint32_t mills;
	cli();
	mills = ms_cnt;
	sei();
	return mills;
 }


int main (void)
 {

	timer_ini();
	sei();


while(1)
	{
	
		uint32_t start = 0;
		if (get_mills() - start >= 500)
		{
		PORTA^= (1<<0);
		start = get_mills();
	}

	
		//other process
 }



}
