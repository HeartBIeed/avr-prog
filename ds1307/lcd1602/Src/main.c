#include "main.h"
#include "lcd1602.h"



int main(void)
{
	LCD_ini_1602();
	
	setpos(0,0);
	char mystr[] = "Hello World!";
	send_ptr_str(mystr); //отправка массива
	
	
	setpos(10,1);
	char mystr2[] = "text";
	send_ptr_str(mystr2);
	
	
	while(1)
	{
	
		


	}
}