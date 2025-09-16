#include "main.h"
#include "lcd1602.h"



int main(void)
{
	LCD_ini_1602();
	
	setpos(0,0);
	char mystr[] = "Hello World!";
	send_ptr_str(mystr); //отправка массива
	
	/*
	setpos(10,1);
	char mystr2[] = "text";
	send_ptr_str(mystr2);
	*/

const unsigned char d[8] = {
	0b01111,
    0b01001,
    0b01001,
    0b01001,
    0b01001,
    0b11111,
    0b10001,
    0b10001
};

const unsigned char i[8] = {
	0b10001,
    0b11001,
    0b10101,
    0b10011,
    0b10001,
    0b10001,
    0b00000,
    0b00000
};
const unsigned char m[8] = {
	0b10001,
    0b11011,
    0b10101,
    0b10001,
    0b10001,
    0b10001,
    0b00000,
    0b00000
};
const unsigned char a[8] = {
    0b01110,
    0b10001,
    0b11111,
    0b10001,
    0b10001,
    0b10001,
    0b00000,
    0b00000
};


	create_symb(0,d);
	create_symb(1,i);
	create_symb(2,m);
	create_symb(3,a);


for (uint8_t n = 0; n < 4; n++){
	
setpos(n,1);
send(n,1);

}

setpos(15,0);
send(0b11111101,1);

	while(1)
	{
	
		


	}
}