#include "tm1638.h"

void tm1638_send(char data)
{
	
for (int i = 0; i < 8; i++)
	{
		
		if (data&(1<<0)) D1
		else			 D0

		CLK_UP
		CLK_DOWN
		
		data >>= 1; 
	}
}

int tm1638_read()
{

STB_DOWN
	tm1638_send(0x42); //read button
STB_UP	

	DDRA &= ~(1<<PA0); // PA0 input

	int data = 0;

STB_DOWN
	for (int i = 0; i < 8; i++)
	{
		
		if (PINA & (1<<PA0)) data |= 1; //+1 if pressed	
		data <<= 1;

		CLK_UP
		CLK_DOWN
	}
STB_UP

return data;
}



void tm1638_init()
{

	DDRA |= (1<<PA0)|(1<<PA1)|(1<<PA2); // output
	PORTA &= ~((1<<PA0)|(1<<PA1)|(1<<PA2)); // in low

	STB_DOWN	
	tm1638_send(0x88); //low brightness
	STB_UP
	
	STB_DOWN
	tm1638_send(0x44); //non increment address
	STB_UP

}




void tm1638_set_digit(char digit,char position, char dot)
{

const uint8_t digits[10] = {
		0x3F, // 0
		0x06, // 1
		0x5B, // 2
		0x4F, // 3
		0x66, // 4
		0x6D, // 5
		0x7D, // 6
		0x07, // 7
		0x7F, // 8
		0x6F  // 9
	};

char data = digits[digit];
	if (dot) data |= 0x80; // set dot under digit | 0b10000000;
	

STB_DOWN

	char digit_addr = position * 2;

	tm1638_send(0xC0 | digit_addr); // set position
	tm1638_send(data); // send digit

STB_UP

}

void tm1638_set_led(char state, char position)
{

STB_DOWN

char led_addr = position * 2 + 1;

	tm1638_send(0xC0 | led_addr); // set position
	tm1638_send(state); // send led state

STB_UP

}






//-------------------------------------------------------

int main(void)
{
	_delay_ms(1);

	tm1638_init(0);

	tm1638_set_digit(1,0,0);
	tm1638_set_digit(2,1,1);
	tm1638_set_digit(3,2,1);
	tm1638_set_digit(4,3,0);
	tm1638_set_digit(5,4,0);
	tm1638_set_digit(6,5,1);
	tm1638_set_digit(7,6,1);
	tm1638_set_digit(8,7,0);


	while (1)
	{
		_delay_ms(100);


	
		for (char i = 0; i < 8; i++)
	{
				tm1638_set_led(1, i);
				tm1638_set_led(0, i-1);
				_delay_ms(1000);

	}



	}
}


