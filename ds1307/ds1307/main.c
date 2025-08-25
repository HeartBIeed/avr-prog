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
	TWBR = 0x20; //����������  32-  ������� 10kHZ ��� ������������ 8 ���
}

void i2c_start(void) // ����� �2�
{
	TWCR =(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);// Interrput \ start \ enable
	while(!(TWCR&(1<<TWINT))); // ���� ���� � ���� - ������� ��������� ���� 1 - ������
}

void i2c_stop(void) // stop i2c
{
	TWCR =(1<<TWINT)|(1<<TWSTO)|(1<<TWEN); // � ��� ���� 1
}
void i2c_send(unsigned char data)
{
	TWDR = data;// ������ ������ � ������� ������
	TWCR=(1<<TWINT)|(1<<TWEN);//��� ��������
	while(!(TWCR&(1<<TWINT))); // twint ���� � ����
}

void iniport(void)
{
	DDRA=0xFF;
	PORTA=0x01;

}



unsigned char BinDec(unsigned char chin) // �������� � ����������
{
	unsigned char chout = ((chin / 10)<<4)|(chin % 10);
	
	return chout;
}

unsigned char DecBin(unsigned char chin) //  ���������� to bin
{
	unsigned char chout = ((chin >> 4 )*10) + (0b00001111 & chin);
	
	return chout;
}


unsigned char i2c_read(void) // ������ 
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);//twea - ������� ������������
	while(!(TWCR&(1<<TWINT))); // twint ���� � ����
	return TWDR;
}

unsigned char i2c_read_lastbyte(void) // ������ ���������� ����
{
	TWCR=(1<<TWINT)|(1<<TWEN);//twea - ������� ������������
	while(!(TWCR&(1<<TWINT))); // twint ���� � ����
	return TWDR;

}

void lcd_print_number(unsigned char num) {
	sendchar((num / 10) + '0');  // ������� �����
	sendchar((num % 10) + '0');  // ������� �����
}

int main()
{

	i2c_init();
	
	
i2c_start();
i2c_send(0b11010000); // ����� 0x68 + 0 - ��� ��������
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
		i2c_send(0b11010000); // ����� 0x68 + 0 - ��� ��������
		i2c_send(0);
		i2c_stop();
		


		i2c_start();
		i2c_send(0b11010001); // ����� 0x68 + 0 - ��� read
		
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
