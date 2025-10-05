#include "main.h"

volatile unsigned int received_byte = 0;
volatile unsigned int data_ready = 0;

void USART_init(uint16_t speed)
	{
		UBRRH =(speed>>8);	
		UBRRL = speed;

		UCSRB |= (1<<RXEN)|(1<<TXEN)|(1<<RXCIE); //RXCIE - innterr
		UCSRA |= (1<<U2X); // 8 MGc
		UCSRC |= (1<<URSEL)|(1<<USBS)|(1<<UCSZ1)|(1<<UCSZ0); //sel assync umsel non 2 uscz 11 - 8 bit 

		RE1
	}

void USART_TX(unsigned int data)
	{	
		RE0
		DE1
	
		while (!(UCSRA&(1<<UDRE))); //проверяем в усра удре бит что он 0 ибо это готовность к записи
	
		UDR = data; // sendc data
		UCSRA |= (1<<TXC); //ставим конец передачи

		DE0
		RE1
	}



ISR(USART_RXC_vect) 
	{
		received_byte = UDR;  // сохраняем байт в глобальную переменную
		data_ready = 1;
	}

void echo()
	{
		USART_TX(received_byte);

	}


int main(void)
{
	RS485_pin_en
	
	sei();
	USART_init(103);
	USART_TX('U');

	
    while(1)
    {
		
		
			if (data_ready ==1)
			{
				echo();
				data_ready =0;
			}
				
    }
}









