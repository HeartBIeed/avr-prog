#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>


#define MS_ASK 0x28
#define SM_ASK 0x50
#define MS_NASK 0x58



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

int eepr_write(unsigned char c) // запись в ЕЕПРОМ
{
TWDR =c;

TWCR=(1<<TWINT)|(1<<TWEN);//вкл передача
while(!(TWCR&(1<<TWINT))); // twint ждем в нуле

	if ((TWSR & 0xF8)! = MS_ASK )
		{
		return 1;
		}
		
		return 0;
		
}


char ERR = 0;

int eepr_read(unsigned char c) // чтение из  ЕЕПРОМ
{
ERR =0;

TWCR=(1<<TWINT)|(1<<TWEN|(1<<TWEA);//twea - ведомый подтверждает 
while(!(TWCR&(1<<TWINT))); // twint ждем в нуле

	if ((TWSR & 0xF8)! = SM_ASK )
		{
		ERR =1;
		}
		ERR =0;
	return TWDR;	
}

int eepr_read_lastbyte(unsigned char c) // чтение из  ЕЕПРОМ последнего байта
{
ERR =0;

TWCR=(1<<TWINT)|(1<<TWEN);//twea - ведомый подтверждает 
while(!(TWCR&(1<<TWINT))); // twint ждем в нуле

	if ((TWSR & 0xF8)! = MS_NASK )
		{
		ERR =1;
		}
		ERR =0;
	return TWDR;
		
}





int main()
{

i2c_init();

mass[8] = {0x30;0x31;0x32;0x33;0x34;0x35;0x36;};


i2c_start();
i2c_send(0b10100000); // адрес + 0 - бит отправки
//i2c_send(0b10100001); // заготовка на чтениес 


int i = 0;
for(i; i <= 8; i++)
	{
	eepr_write(mass[i]);
		
	}
	
	i2c_stop();
}


//read
mass2[8];

int i = 0;
for(i; i <= 7; i++)
	{
	mass2[i] = eepr_read();
		
	}
	mass[8] = eepr_read_lastbyte();
	
	i2c_stop();
}
