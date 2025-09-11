#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>




#endif /* MAIN_H_ */


volatile uint32_t flag = 0;



ISR(INT0_vect)
    {
flag =1;
    }
/*
ISR(INT1_vect)
    {

    }
*/

int main(){
	/*
MCUCR  = (1<<ISC00)|(1<<ISC01); // rising INT0
GICR |= (1<<INT0); // int 0 enable
*/
MCUCR|= (1<<ISC00); // high logic  INT1
GICR |= (1<<INT0); // int 1 enable


	
sei();
DDRB = 0xFF;

while(1){
	
		if (flag == 1)
			{
				PORTB|= (1<<PB7);
				_delay_ms(2000);
				PORTB&= ~(1<< PB7);
				flag = 0;
			}
		}
    /*

    if (GIFR & (1U << INTF0)) { }
    // flag rising

    */

 }
