#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

#include "lcd1602.h"


#endif /* MAIN_H_ */

unsigned char hour,min,sec;


void i2c_init(void)
{
	TWBR = 0x20; //дес€тичное  32-  частота 10kHZ при тактировании 8 м√ц
}

void i2c_start(void) // старт и2с
{
	TWCR =(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);// Interrput \ start \ enable
	while(!(TWCR&(1<<TWINT))); // ждем твин в нуле - задание оконченно пока 1 - работа
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

void iniport(void)
{
	DDRA=0xFF;
	PORTA=0x01;

}



unsigned char BinDec(unsigned char chin) // двоичный в дес€тичный
{
	unsigned char chout = ((chin / 10)<<4)|(chin % 10);
	
	return chout;
}

unsigned char DecBin(unsigned char chin) //  дес€тичный to bin
{
	unsigned char chout = ((chin >> 4 )*10) + (0b00001111 & chin);
	
	return chout;
}


unsigned char i2c_read(void) // чтение 
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);//twea - ведомый подтверждает
	while(!(TWCR&(1<<TWINT))); // twint ждем в нуле
	return TWDR;
}

unsigned char i2c_read_lastbyte(void) // чтение последнего байт
{
	TWCR=(1<<TWINT)|(1<<TWEN);//twea - ведомый подтверждает
	while(!(TWCR&(1<<TWINT))); // twint ждем в нуле
	return TWDR;

}

void lcd_print_number(unsigned char num) {
	sendchar((num / 10) + '0');  // старша€ цифра
	sendchar((num % 10) + '0');  // младша€ цифра
}

int main()
{

	i2c_init();
	
	
i2c_start();
i2c_send(0b11010000); // адрес 0x68 + 0 - бит отправки
i2c_send(0);
i2c_send(BinDec(0));
i2c_send(BinDec(55));
i2c_send(BinDec(21));
i2c_stop();

	
	iniport();
	LCD_ini();
	setpos(0,0);
		
/*char time[9]={"19:31:14"};
	sendchar(time);
*/

while(1)
	{
		i2c_start();
		i2c_send(0b11010000); // адрес 0x68 + 0 - бит отправки
		i2c_send(0);
		i2c_stop();
		


		i2c_start();
		i2c_send(0b11010001); // адрес 0x68 + 0 - бит read
		
		sec = i2c_read();
		min = i2c_read();
		hour =i2c_read_lastbyte();
	    
		i2c_stop();
		
sec = DecBin(sec);		
min = DecBin(min);
hour =DecBin(hour);

setpos(0,0);



lcd_print_number(hour);
sendchar(0x3A);
lcd_print_number(min);
sendchar(0x3A);
lcd_print_number(sec);

		
	}
	
	
}
