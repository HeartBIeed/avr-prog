#include "main.h"
#include "lcd1602.h"



int main(void)
{
	LCD1602_ini();
	
	set_lcd_pos(0,0);
	char mystr[] = {0xCF,0xF0,0xE8,0xE2,0xE5,0xF2};
	send_lcd_ptr_str(mystr); //отправка массива
	
	/*
	setpos(10,1);
	char mystr2[] = "text";
	send_ptr_str(mystr2);
	*/

const unsigned char d[8] = {
	0b00000,
    0b00000,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b00000,
    0b00000
};

const unsigned char i[8] = {
	0b00000,
    0b00000,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b00000,
    0b00000
};
const unsigned char m[8] = {
	0b00000,
    0b00000,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b00000,
    0b00000
};
const unsigned char a[8] = {
	0b10000,
    0b11000,
    0b11100,
    0b11111,
    0b11100,
    0b11000,
    0b10000,
    0b00000
};


	create_symb(0,d);
	create_symb(1,i);
	create_symb(2,m);
	create_symb(3,a);


for (uint8_t n = 0; n < 4; n++){
	
    set_lcd_pos(n,1);
    send_byte(n,1);

    }

//setpos(15,0);
//send(0b11111101,1);

	while(1)
	{
	
		


	}
}