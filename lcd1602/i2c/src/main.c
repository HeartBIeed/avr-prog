#include "main.h"



int main(void)
{


while(1)
	{
    i2c_init();
	LCD1602_ini();
	    _delay_ms(2);

	set_lcd_pos(0,0);
	send_lcd_ptr_str("HELLO");
	
    _delay_ms(1000);

    }
}