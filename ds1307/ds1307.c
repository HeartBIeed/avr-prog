#include "ds1307.h"

uint8_t hour,min,sec;

uint8_t DecToBSD(uint8_t chin) // 10 >> 0x10
	{
	 uint8_t chout = ((chin / 10)<<4)|(chin % 10);
	 return chout;
	}

uint8_t BSDtoDec(uint8_t chin) // 0x10 >> 10
	{
	 uint8_t chout = ((chin >> 4 )*10) + (0b00001111 & chin);
	 return chout;
	}




void lcd_print_number(uint8_t num) 
	{
	 send_byte((num / 10) + '0',1);  // десятки
	 send_byte((num % 10) + '0',1);  // единицы
	}

void set_time(uint32_t h,uint32_t m)
	{
	 i2c_init();

	i2c_start(); // настройка времени
		i2c_send(0b11010000); // адрес 0x68 + 0 - бит отправки
		i2c_send(0);
		i2c_send(DecToBSD(0)); //секунды
		i2c_send(DecToBSD(m)); //минуты
		i2c_send(DecToBSD(h)); //часы
	i2c_stop();
	} 


void time_to_lcd(int x,int y)
	{
	i2c_init();
	
	i2c_start();
		i2c_send(0b11010000);// адрес 0x68 
		i2c_send(0);
	i2c_stop();
		
	i2c_start();
		i2c_send_adress(0x68); 
		sec = i2c_read_byte();
		min = i2c_read_byte();
		hour =i2c_read_byte_NACK();
	i2c_stop();
		
	sec = BSDtoDec(sec);
	min = BSDtoDec(min);
	hour =BSDtoDec(hour);

	set_lcd_pos(x,y);

	lcd_print_number(hour);
	send_byte(0x3A,1);
	lcd_print_number(min);
	send_byte(0x3A,1);
	lcd_print_number(sec);
	
	}



int main()
{

	i2c_init();		
	LCD1602_ini();
	set_lcd_pos(0,0);
	set_time(22,02);

while(1)
	{

	time_to_lcd(0,0);
		_delay_ms(250);

	}
	
	
}
