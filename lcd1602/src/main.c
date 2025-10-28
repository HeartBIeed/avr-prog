#include "main.h"
#include "lcd1602.h"



int main(void)
{
	LCD1602_ini();
	
	set_lcd_pos(0,0);
	uint8_t mystr[] = "HELLO";
	send_lcd_ptr_str(mystr); //отправка массива
	
	/*
	setpos(10,1);
	char mystr2[] = "text";
	send_ptr_str(mystr2);
	*/

// ------- Create user symbols -------
    
const uint8_t a[8] = {
    0b11111,
    0b11100,
    0b11100,
    0b11100,
    0b11100,
    0b11100,
    0b11100,
    0b11111
    };

const uint8_t b[8] = {
    0b11111,
    0b00000,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b00000,
    0b11111
    };
const uint8_t c[8] = {
    0b11111,
    0b00000,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b00000,
    0b11111
    };

const uint8_t d[8] = {
    0b11100,
    0b11100,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11100,
    0b11100
    };




	create_symb(0,a);
	create_symb(1,b);
	create_symb(2,c);
	create_symb(3,d);


for (uint8_t n = 0; n < 4; n++){
	
    set_lcd_pos(n,1);
    send_byte(n,1);

    }


	while(1)
	{
	
		


	}
}