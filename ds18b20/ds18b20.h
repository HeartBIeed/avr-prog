#ifndef DS18B20_H_
#define DS18B20_H_

#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>


#define PORTTEMP PORTD
#define DDRTEMP DDRD
#define PINTTEMP PIND
#define BITTEMP 1
#define NOID 0xCC // Skip Rom
#define TCONV 0x44 // Convert T 
#define READ 0xBE // Read Scratchpad


char search(void);
char readbit(void);
char readbyte(void);
void dt_sendbyte(unsigned char bt);
char sendbit(char bt);
int check(void);
char conv_temp(unsigned int tt);

#endif /* DS18B20_H_ */


