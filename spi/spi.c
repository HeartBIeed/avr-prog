#include "spi.h"

void spi_init(void)
	{
	DDRB |= (1<<PB2)|(1<<PB3)|(1<<PB5); // spi pin out
	PORTB &= ~((1<<PB2)|(1<<PB3)|(1<<PB5)); // in low

	SPCR &= ~ ((1<<SPE)|(1<<MSTR));  // spi control registr: enable spi / master  
	SPDR = 0; // data registr
	}



int main(void)
{

uint8_t data_spi =0;


	while(!(SPSR&(1<<SPIF))) // SR - status registr, SPIF - end transmit HIGH
		{
			data_spi = SPDR;
		}


	
}



/*

SPDR (SPI Data Register) — регистр данных

SPCR (SPI Control Register) — управляющий регистр
(1<<SPIE)- interrupt

SPSR (SPI Status Register) — статусный регистр
SPIF - complete
*/
