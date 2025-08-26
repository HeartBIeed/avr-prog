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

DDRB | = ((1<<POTRB2)|(1<<POTRB3)|(1<<POTRB5)); // spi pin out
POTRTB & = ~ ((1<<POTRB2)|(1<<POTRB3)|(1<<POTRB5)); // in low

SPCR & = ~ ((1<<SPE)|(1<<MSTR));  // enable spi / master enable / spi control registr
DPDR = 0; // data registr


	while(!(SPSR&(1<<SPIF))); // SR - status registr, SPIF - end transmit HIGH

POTRTB ! =  (1<<POTRB2); // ss up	
POTRTB & = ~ (1<<POTRB2);	// ss down	

	
}



/*

SPDR (SPI Data Register) — регистр данных
SPCR (SPI Control Register) — управляющий регистр
SPSR (SPI Status Register) — статусный регистр


*/
