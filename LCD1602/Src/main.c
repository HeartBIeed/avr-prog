#include "main.h"
#include "lcd1602.h"



void iniport(void)
{
	PORTA=0x00;
	DDRA=0xFF;

}





int main(void)
{
	iniport();
	LCD_ini();
	
	setpos(0,0);
	char mystr[] = "Hello World!";
	send_ptr_str(mystr); //отправка массива
	
	setpos(0,1);
	char mystr2[] = "random text";
	send_ptr_str(mystr2);

	
	
	while(1)
	{
		
	}
}