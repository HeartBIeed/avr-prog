#include "main.h"
#include "lcd1602.h"



void iniport(void)
{
	DDRA=0xFF;
	PORTA=0x01;

}




int main(void)
{
	iniport();
	LCD_ini();
	
	setpos(0,0);
	char mystr1[] = "random text 1";
	send_ptr_str(mystr1);	

	
	setpos(0,1);
	char mystr2[] = "random text 2";
	send_ptr_str(mystr2);


	
	while(1)
	{
		
	}
}