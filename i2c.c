#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>


#endif /* MAIN_H_ */

void i2c_init(void)
	{
		TWBR = 0x20; //десятичное  32-  частота 10kHZ при тактировании 8 мГц
	}

void i2c_start(void) // старт и2с
	{
		TWCR =(1<<TWINT)|(1<<TWISTA)|(1<<TWEN);// Interrput \ start \ enable
		while(!(TWCR&(1<<TWINT))); // ждем твин в нуле - задание оконченно пока 1 - работа
	}

void i2c_stop(void) // stop i2c
	{
		TWCR =(1<<TWINT)|(1<<TWISTO)|(1<<TWEN); // в бит стоп 1
	}
void i2c_send(unsigned char data)
	{
		TWDR = data;// запись данных в регистр данных
		TWCR=(1<<TWINT)|(1<<TWEN);//вкл передача
		while(!(TWCR&(1<<TWINT))); // twint ждем в нуле
	}













int main()
{

	
}
