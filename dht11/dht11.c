#include "dht11.h"

void dht_request() //start down-up
	{
		DDRD|= (1<<DHT_PIN);
		PORTD&=~(1<<DHT_PIN);
		_delay_us(20);			
		PORTD|= (1<<DHT_PIN);
		USART_send_str("request \r\n"); 

	}

void dht_response(void) //ответ - ждем up-down-up
	{
		USART_send_str("start response \r\n"); 

		DDRD&=~(1<<DHT_PIN);
		while (PIND &(1<<DHT_PIN)); // ожидание 1
		while ((PIND &(1<<DHT_PIN))==0); // ожидание 0
		while (PIND &(1<<DHT_PIN));
		USART_send_str("response \r\n"); 

	}

uint8_t dht_receive_data() //получаем байт
	{
	
	uint8_t c =0;

	for (int i = 0; i < 8; i++)
		{

		while ((PIND &(1<<DHT_PIN))==0); // ждем появления 1. пока 0 - не выходим из цикла
			
		_delay_us(40);			

		if (PIND &(1<<DHT_PIN)) // если пин в 1 более 30 мс
			{
				c=(c<<1)|(0x01); // то сдвиг влево и пишем в конец 1
			}
		else 
			{
				c=(c<<1); // то сдвиг влево. в конце 0
			}

		}
		USART_send_str("receive \r\n"); 

	return c;
	}

void dht_write_data(char* data)
	{
		uint8_t I_RH,D_RH,I_TEMP,D_TEMP,C_SUMM_GET,CSUMM;
		uint8_t Temp,Humi;

		dht_request();
		dht_response();
		
		I_RH = dht_receive_data(); // целая часть
		D_RH = dht_receive_data(); // дробная
		I_TEMP = dht_receive_data();
		D_TEMP = dht_receive_data();

		C_SUMM_GET = dht_receive_data();
		CSUMM = ((I_RH + D_RH + I_TEMP + D_TEMP) & 0xFF);

		if (C_SUMM_GET == CSUMM) sprintf(data,"%d %d", I_RH,I_TEMP);
		else sprintf(data,"ERR");
	}




int main(void)
{
	USART_init(103);
	char data[16];
	USART_send_str("ENABLE \r\n"); 

while (1)
{
	_delay_ms(3000);
	dht_write_data(data);
	USART_send_str(data); 
	USART_send_str("uart \r\n"); 
}


}

//	sprintf(data, "RH:%d.%d % T:%d.%dC", I_RH, D_RH, I_TEMP, D_TEMP);

/*
	dht_request();
	dht_response();
	I_RH = dht_receive_data(); // целая часть
	D_RH = dht_receive_data(); // дробная*//*
	I_TEMP = dht_receive_data();
	D_TEMP = dht_receive_data();


*/