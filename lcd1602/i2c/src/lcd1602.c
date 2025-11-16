#include "lcd1602.h"


void LCD1602_ini(void)
	{
		i2c_start();
		i2c_send_adress(ADDR_LCD); 

		
			_delay_ms(15);
		send_nibble(0x3,0);  // 0b00000011 включает 4 битный режим
			_delay_ms(4);
		send_nibble(0x3,0);
			_delay_us(100);
		send_nibble(0x3,0);
			_delay_ms(1);
		send_nibble(0x2,0);
			_delay_ms(1);


		send_byte(0b00101000, 0); // отправка команд
			_delay_ms(1);

		send_byte(0b00001100, 0);	
			_delay_ms(1);

		send_byte(0b00000110, 0);	
			_delay_ms(1);

			i2c_stop(); 
	}

void send_nibble(uint8_t nibble,uint8_t mode) 
	{
		uint8_t data = 0; 
		data |= (nibble<<4);// 
		
		if (mode) data |= (1<<0); // данные 1  | RS UP 
		
		data |= (1<<2);
		i2c_send(data);
			_delay_us(50);

		data &= ~(1<<2);
		i2c_send(data);
			_delay_us(50);
		
 			
	}

void send_byte(uint8_t c,uint8_t mode)
	{

		send_nibble((c >> 4) & 0x0F,mode); // H nibble
		send_nibble((c) & 0x0F,mode);	// L  nibble
	}

//----------------------------------------------------------

void send_lcd_char(uint8_t c) // отправка 1 символа
	{
		send_byte(c,1);
			_delay_ms(10);

	}

void set_lcd_pos(uint8_t x, uint8_t y) // установка позиции Х 0-15, У 0-1.
	{
		i2c_start();
		i2c_send_adress(ADDR_LCD); 


		uint8_t adress;

		adress=(0x40*y+x)|0b10000000; // адреса символов 2ой строки идут от 40, 8й бит передает команду установки позиции

		send_byte(adress, 0);
		i2c_stop(); 

	}


void send_lcd_ptr_str(uint8_t *str) // отправка строки по указателю массива
	{	
		i2c_start();
		i2c_send_adress(ADDR_LCD); 

		while (*str) send_lcd_char(*str++); //посимвольная передача до нуля

		i2c_stop(); 
	}


void create_symb(uint8_t index_symb, const uint8_t *data) 
	{

		i2c_start();
		i2c_send_adress(ADDR_LCD); 

		uint8_t adress;
		uint8_t i;

		adress=0x40|(index_symb << 3); //<< 3 = умножить на 8.

		send_byte(adress, 0);

		for (i = 0; i < 8; i++)
			{
				send_byte(data[i], 1);
			}
			i2c_stop(); 

	}

