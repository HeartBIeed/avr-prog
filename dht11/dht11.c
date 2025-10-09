#include "dht11.h"

void dht_request() //start down-up
	{
		DDRD|= (1<<DHT_PIN);
		PORTD&=~(1<<DHT_PIN);
		_delay_ms(20);			
		PORTD|= (1<<DHT_PIN);

	}

void dht_response(void) //ответ - ждем up-down-up
	{
		DDRD&=~(1<<DHT_PIN);
		while (PIND &=(1<<DHT_PIN)); // ожидание 1
		while ((PIND &=(1<<DHT_PIN))==0); // ожидание 0
		while (PIND &=(1<<DHT_PIN));

	}

uint8_t dht_receive_data() //получаем байт
	{
	
	uint8_t c =0;

	for (int i = 0; i < 8; i++)
		{

		while ((PIND &=(1<<DHT_PIN))==0); // ждем появления 1. пока 0 - не выходим из цикла
			
		_delay_ms(50);			

		if (PIND &=(1<<DHT_PIN)) // если пин в 1 более 30 мс
			{
				c=(c<<1)|(0x01); // то сдвиг влево и пишем в конец 1
			}
		else 
			{
				c=(c<<1); // то сдвиг влево. в конце 0
			}

		}

	return c;
	}

void dht_write_data(char* data)
	{
		uint8_t I_RH,D_RH,I_TEMP,D_TEMP;
		uint8_t Temp,Humi;

		dht_request();
		dht_response();
		I_RH = dht_receive_data(); // целая часть
		D_RH = dht_receive_data(); // дробная
		I_TEMP = dht_receive_data();
		D_TEMP = dht_receive_data();

	sprintf(data, "RH:%d.%d % T:%d.%dC", I_RH, D_RH, I_TEMP, D_TEMP);

	}




int main(void)
{

	uint8_t data[16];
	dht_write_data(data);
	
}



