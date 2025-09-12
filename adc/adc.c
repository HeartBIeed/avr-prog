#ifndef ADC_H_
#define ADC_H_

#define F_CPU 8000000UL

#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


#endif /* ADC_H_ */



int main(void)
{

DDRB |= (1<<PB2)|(1<<PB3)|(1<<PB5); // spi pin out
PORTB &= ~((1<<PB2)|(1<<PB3)|(1<<PB5)); // in low


PORTB |=  (1<<PB2); // ss up	
PORTB &= ~(1<<PB2);	// ss down	

	
}



/*


*/
