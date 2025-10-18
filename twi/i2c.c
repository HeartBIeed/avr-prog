#include "i2c.h"


void i2c_init(void)
	{
		TWBR = 0x20; //десятичное 32-частота 10 kHz при тактировании 8 MHz
	}

void i2c_start(void) // старт i2c
	{
		TWCR =(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);// interrput / start / enable
		while(!(TWCR&(1<<TWINT))); // ждем TWINT в 0 - задание оконченно/ пока 1 - работа
	}

void i2c_stop(void) // стоп i2c
	{
		TWCR =(1<<TWINT)|(1<<TWSTO)|(1<<TWEN); // 1 = TWSTO -> стоп 
	}

void i2c_send_adress(uint8_t adress) 
	{
		TWDR = (adress<<1)|0x01;
		TWCR=(1<<TWINT)|(1<<TWEN); 
		while(!(TWCR&(1<<TWINT))); 
	}

void i2c_send(uint8_t data)
	{
		TWDR = data;// запись данных в регистр данных
		TWCR=(1<<TWINT)|(1<<TWEN); //вкл передача
		while(!(TWCR&(1<<TWINT))); 
	}


uint8_t i2c_read_byte(void) // чтение 
	{
		TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA); //TWEA - ведомый подтверждает АСК
		while(!(TWCR&(1<<TWINT))); // TWINT ждем в нуле
		return TWDR;
	}

uint8_t i2c_read_byte_NACK(void) // чтение последнего байта
	{
		TWCR=(1<<TWINT)|(1<<TWEN); // без АСК
		while(!(TWCR&(1<<TWINT))); 
		return TWDR;

	}

