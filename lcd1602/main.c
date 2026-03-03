#include "main.h"

void user_symbols()
{
// ------- Create user symbols -------
    
const uint8_t a[8] = {
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111
    };

const uint8_t b[8] = {
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111
    };
const uint8_t c[8] = {
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
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


for (uint8_t n = 0; n < 4; n++)
    {
        set_lcd_pos(n,1);
        send_lcd_char(n);
    }

}


int main(void)
{

	LCD1602_ini();
	
    set_lcd_pos(5,0);
    send_lcd_string("HELLO 3");

    set_lcd_pos(9,1);
    send_lcd_string("5345");

    set_lcd_pos(0,1);
    user_symbols();

while(1)
	{

 
	}
}