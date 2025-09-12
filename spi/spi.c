#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

#endif /* MAIN_H_ */



int main(void)
{

DDRB |= (1<<PB2)|(1<<PB3)|(1<<PB5); // spi pin out
PORTB &= ~((1<<PB2)|(1<<PB3)|(1<<PB5)); // in low

SPCR &= ~ ((1<<SPE)|(1<<MSTR));  // enable spi / master enable / spi control registr
SPDR = 0; // data registr


	while(!(SPSR&(1<<SPIF))); // SR - status registr, SPIF - end transmit HIGH

PORTB |=  (1<<PB2); // ss up	
PORTB &= ~(1<<PB2);	// ss down	

	
}



/*

SPDR (SPI Data Register) — регистр данных

SPCR (SPI Control Register) — управляющий регистр
(1<<SPIE)- interrupt


SPSR (SPI Status Register) — статусный регистр
SPIF - complete
*/
