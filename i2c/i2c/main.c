#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#endif /* MAIN_H_ */

void i2c_init(void)
{
	TWBR = 0x20; //десятичное  32-  частота 10kHZ при тактировании 8 мГц
}

void i2c_start(void) // старт и2с
{
	TWCR =(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);// Interrput \ start \ enable
}
void i2c_stop(void) // stop i2c
{
	TWCR =(1<<TWINT)|(1<<TWSTO)|(1<<TWEN); // в бит стоп 1
}
void i2c_send(unsigned char data)
{
	TWDR = data;// запись данных в регистр данных
	TWCR=(1<<TWINT)|(1<<TWEN);//вкл передача
	while(!(TWCR&(1<<TWINT))); // twint ждем в нуле
}





int main(void)
{
/*uint8_t buffer[1024]; // 1024 байта
for(int i = 0; i < 1024; i++) 
	{
		buffer[i] = 0xFF;
		}
	*/
	
	
i2c_init();
	
i2c_start();     
i2c_send(0x78);  
i2c_send(0x00);
i2c_send(0xA7);
/*int i;    
for(i = 0; i < 1024; i++) {
	i2c_send(buffer[i]);
	}
*/		
i2c_stop();
	
	while (1) {
	}
}