#include "uart.h"



void USART_init(uint16_t speed)
	{

	UBRRH =(speed>>8);	
	UBRRL = speed;

	UCSRB |= (1<<RXEN)|(1<<TXEN)|(1<<RXCIE); //RXCIE - innterr
	UCSRA |= (1<<U2X); // 8 MGc
	UCSRC |= (1<<URSEL)|(1<<USBS)|(1<<UCSZ1)|(1<<UCSZ0); //sel assync umsel non 2 uscz 11 - 8 bit 
	}

void USART_TX(unsigned char data)
	{
		while (!(UCSRA&(1<<UDRE))); //проверяем UDRE бит что он 0 - это готовность к записи
		
		UDR = data; // sendc data

	}


volatile uint8_t received_byte = 0;
volatile uint8_t data_ready = 0;

	ISR(USART_RXC_vect) 
	{
		received_byte = UDR;  // сохраняем байт в глобальную переменную
		data_ready = 1;
	}

void USART_echo()
	{
		USART_TX(received_byte);

	}

void USART_ptr_str(char *str) // 
	{
		while (*str) 
		{

		USART_TX(*str++); //
		
		}

	}


int main(void)
{
	
	
	sei();
	USART_init(103); //9600

	USART_TX('O');
	USART_TX('N');

	unsigned char mystr[10] = {"Hello/0"};
	USART_ptr_str(mystr);

	unsigned char str_get[6] = {"GET:/0"};

    while(1)
    {

		if (data_ready ==1)
		{

			USART_ptr_str(str_get);
			USART_echo();
			data_ready =0;
		}
					
    }
}
