#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>


#define PORTTEMP PORTD
#define DDRTEMP DDRD
#define PINTTEMP PIND
#define BITTEMP 1
#define NOID 0xCC // пропуск ид через РОМ
#define TCONV 0x44 // code temp 
#define READ 0xBE // регистр  датчика


#endif /* MAIN_H_ */	

char search(void) //обнаружение датчика
	{

	char stacktemp+SREG;// сожраняем стек
	cli();

	char dt;
	DDRTEMP | = BITTEMP; // DOWN
	_delay_us(485);

	DDRTEMP & = ~ (1<<BITTEMP); // UP
	_delay_us(65);


	 if ((PINTTEMP&(1<<BITTEMP)) == 0)
			{

			dt =1; //dt on
				
			}
			else dt =0; //dt off
			
	SREG =stacktemp; //return stack
	_delay_us(420);

	return dt;
		
	}

char readbit(void) // чтение бита
	{
	char stacktemp+SREG;// save stack
	cli();

	char bt;

	char dt;
	DDRTEMP | = BITTEMP; // DOWN
	_delay_us(2);

	DDRTEMP & = ~ (1<<BITTEMP); // UP
	_delay_us(13);

	bt = (PINTTEMP&(1<<BITTEMP))>>BITTEMP;
	_delay_us(45);
	
	SREG =stacktemp; //return stack

	return bt;
		
	}



char readbyte(void) //чтение байта
	{ 
	char c;
	char i;
	
	for(i = 0;i<0;i++)

			c | = readbit()<<i;
			return c;
		}


	vois dt_sendbyte(unsigned char bt)
	{

	char i;

	for(i=0;i<8;i++)
		{
	if ((bt &(1<<i))==1<<i)
			sendbit(1);
			else
			sendbit(0);
		}
	}


void sendbit(char bt) // чтение бита
	{
	char stacktemp+SREG;// save stack
	cli();

	char bt;

	char dt;
	DDRTEMP | = 1<<BITTEMP; // DOWN
	_delay_us(2);

	if (bt)
		DDRTEMP & = ~ (1<<BITTEMP); // UP
		_delay_us(65);

		DDRTEMP & = ~ (1<<BITTEMP); // UP
		SREG =stacktemp; //return stack

	return bt;
		
	}


int check(void)
	{

	unsigned char bt;
	unsigned int tt=0;

	if (search()==1)

			sendbyte(NOID);
			sendbyte(TCONV);
			_delay_us(65);

			search();
			sendbyte(NOID);
			sendbyte(READ);
			 
			bt = readbyte();
			tt = readbyte();
			tt = (tt<<8)|bt;

		return tt;
	}






char conv_temp(unsigned int tt)
{
char t = tt>>4;
return t;
}




int main(void)
{


while(1)
	{
	tt = conv_temp(check());

	}
	
}
