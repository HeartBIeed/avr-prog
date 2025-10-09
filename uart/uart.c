#include "uart.h"

volatile uint8_t received_byte = 0;
volatile uint8_t data_ready = 0;

void USART_init(uint16_t speed)
	{

	UBRRH =(speed>>8);	
	UBRRL = speed;

	UCSRB = (1<<RXEN)|(1<<TXEN)|(1<<RXCIE); //RXCIE - interrupt
	UCSRA = (1<<U2X); // x2 (9600 -> 103 -> 8 MHz)
	UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0); //assync /8 bit 
	}

void USART_TX(uint8_t data)
	{
	
	while (!(UCSRA&(1<<UDRE))); //проверяем UDRE бит что он 0 - это готовность к записи	
	UDR = data; // send data

	}


ISR(USART_RXC_vect) 
	{
		received_byte = UDR;  // сохраняем байт в глобальную переменную
		data_ready = 1; //flag
	}

void USART_echo()
	{
		USART_TX(received_byte);

	}

void USART_ptr_str(char *str) // TX string
	{
		while (*str) 
		{

		USART_TX(*str++);
		
		}

	}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void USART_get_str() // 
	{
		while (data_ready == 1) 
		{

		received_byte //
		
		}

	}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
int main(void)
{
	
	
	sei();
	USART_init(103); //9600

	USART_TX('O');
	USART_TX('N');

	uint8_t mystr[] = {"Hello"};
	USART_ptr_str(mystr);

	uint8_t str_get[] = {"GET:"};

    while(1)
    {

		if (data_ready)
		{

			USART_ptr_str(str_get);
			USART_echo();
			data_ready =0;
		}
					
    }
}
