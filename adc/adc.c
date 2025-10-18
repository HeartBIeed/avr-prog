#include "adc.h"

uint16_t adc_value =0;

void ADC_init(void)
{
// управляющ регистр
ADCSRA |= (1<<ADEN);//adc on
ADCSRA |= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);//Делитель 128 = 64 кГц

// управления каналами мультиплексора АЦП
ADMUX |= (1<<REFS1)|(1<<REFS0); //Внутренний Источник ОН 2,56в
//ADMUX |= 0x01; //каналы 

}

void ADC_interrupt(void)
{
ADCSRA |= (1<<ADSC); //при установке в 1  АЦП начинать преобразование.
ADCSRA |= (1<<ADATE)|(1<<ADIE);//непрерыв режим и вкл прерыв
sei();
}

uint16_t ADC_convert(void)
{

ADCSRA |= (1<<ADSC); 
while ((ADCSRA & (1<<ADSC))); // wait end
return (uint8_t)ADC;
}

ISR(ADC_vect)
{
adc_value = ADC;
}

int main(void)
{

adc_value = ADC_convert();
	
}

