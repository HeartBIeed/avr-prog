#ifndef TM1638_H_
#define TM1638_H_

#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>





#define STB_UP PORTA|=(1<<PA2);
#define STB_DOWN PORTA &=~(1<<PA2);	

#define CLK_UP PORTA|=(1<<PA1);
#define CLK_DOWN PORTA &=~(1<<PA1);	

#define D1 PORTA|=(1<<PA0);
#define D0 PORTA &=~(1<<PA0);	






#endif /* TM1638_H_ */