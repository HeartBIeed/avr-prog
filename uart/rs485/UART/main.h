#ifndef MAIN_H_
#define MAIN_H_


#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define RS485_pin_en DDRD |= (1<<PD2)|(1<<PD3);

#define RE1 PORTD|=(1<<PD2);
#define RE0 PORTD&=(1<<PD2);

#define DE1 PORTD|=(1<<PD3);
#define DE0 PORTD&=(1<<PD3);



#endif /* MAIN_H_ */

