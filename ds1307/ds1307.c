#include "ds1307.h"


unsigned char hour,min,sec;


void i2c_init(void)
{
	TWBR = 0x20; //десятичное  32-  частота 10kHZ при тактировании 8 мГц
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



unsigned char BinDec(unsigned char chin) // двоичный в десятичный
{
	unsigned char chout = ((chin / 10)<<4)|(chin % 10);
	
	return chout;
}

unsigned char DecBin(unsigned char chin) //  десятичный to bin
{
	unsigned char chout = ((chin >> 4 )*10) + (0b00001111 & chin);
	
	return chout;
}


unsigned char i2c_read(void) // чтение 
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);//TWEA - ведомый подтверждает АСК
	while(!(TWCR&(1<<TWINT))); // TWINT ждем в нуле
	return TWDR;
}

unsigned char i2c_read_lastbyte(void) // чтение последнего байт
{
	TWCR=(1<<TWINT)|(1<<TWEN); // без АСК
	while(!(TWCR&(1<<TWINT))); // TWINT ждем в нуле
	return TWDR;

}

void lcd_print_number(unsigned char num) {
	sendchar((num / 10) + '0');  // старшая цифра
	sendchar((num % 10) + '0');  // младшая цифра
}

int main()
{

	i2c_init();
	
/*	
i2c_start(); // настройка времени
i2c_send(0b11010000); // адрес 0x68 + 0 - бит отправки
i2c_send(0);
i2c_send(BinDec(0)); //секунды
i2c_send(BinDec(58)); //минуты
i2c_send(BinDec(21)); //часы
i2c_stop();
*/
	
	iniport();
	LCD_ini();
	setpos(0,0);
		

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
