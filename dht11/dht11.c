#ifndef DHT11_H_
#define DHT11_H_

#define F_CPU 8000000UL

#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define DHT_DDRD DDRD
#define DHT_PORT PORTD
#define DHT_PIN PIND
#define DHT_BIT 6



#endif /* DHT11_H_ */

uint8_t dht_input_mode(){DHT_DDRD &=~(1<<DHT_BIT);} //пин порта на вход
uint8_t dht_output_mode(){DHT_DDRD |= (1<<DHT_BIT);}// на выход
uint8_t dht_high(){DHT_PORT |= (1<<DHT_BIT);} // установит пин в 1
uint8_t dht_low(){DHT_PORT &=~(1<<DHT_BIT);} // в ноль

void dht_start(void)
{
dht_output_mode();
dht_low();
_delay_ms(20);
dht_high()
_delay_us(40);

dht_input_mode();
}

uint8_t dht_wait_high()
{

//свыше 30 мкс  - 1
}

uint8_t dht_wait_low()
{

//до 30 мкс  - 1
	
}

uint8_t dht_read_bit()
{

	
}

uint8_t dht_read_byte(void)
{
uint8_t data =0;
for (int i = 0; i < 8; ++i)
	{
		data << = 1;
		data | = dht_read_bit();
	}
	return data;
}


int main(void)
{

DDRB |= (1<<PB2)|(1<<PB3)|(1<<PB5); // spi pin out
PORTB &= ~((1<<PB2)|(1<<PB3)|(1<<PB5)); // in low


PORTB |=  (1<<PB2); // ss up	
PORTB &= ~(1<<PB2);	// ss down	

	
}



/*


*/
