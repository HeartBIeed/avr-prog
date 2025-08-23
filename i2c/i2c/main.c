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
	TWBR = 0x20; //����������  32-  ������� 10kHZ ��� ������������ 8 ���
}

void i2c_start(void) // ����� �2�
{
	TWCR =(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);// Interrput \ start \ enable
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





int main(void)
{
/*uint8_t buffer[1024]; // 1024 �����
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