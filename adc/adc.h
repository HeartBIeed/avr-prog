#ifndef ADC_H_
#define ADC_H_

#define F_CPU 8000000UL

#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void ADC_init(void);
uint16_t ADC_convert(void);
void ADC_interrupt(void);

extern uint16_t adc_value;

#endif /* ADC_H_ */