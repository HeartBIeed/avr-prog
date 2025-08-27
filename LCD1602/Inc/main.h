#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "lcd1602.h"


#define E1 PORTA|=0b00001000 // установка линии E в 1 стробирующая шина
#define E0 PORTA&=0b11110111 // установка линии E в 0
#define RS1 PORTA|=0b00000100 // установка линии RS в 1 (данные)
#define RS0 PORTA&=0b11111011 // установка линии RS в 0 (команда)



#endif /* MAIN_H_ */

