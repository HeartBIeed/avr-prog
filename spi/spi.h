#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

#define CS_UP PORTB|=(1<<PB2);
#define CS_DOWN PORTB &=~(1<<PB2);	

#endif /* MAIN_H_ */