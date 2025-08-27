#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

#endif /* MAIN_H_ */


void init_PWM(void)
{
TCCR2 = (1<<WGM20)|(1<<WGM21); //fast pwm mode 
TCCR2 = (1<<COM21); // non invert
TCCR2 = (1<<CS21)|(1<<CS22); //prescaler /256 

TCNT2= 0x00; // counter to zero
OCR2 = 0x00; // width  0 - 0 / FF -100

TIMSK |= 0x00;	
ASSR| =0x00;

}

int pwm_proc(int p) //num to procent
{
unsigned int result;
result = p/100*255;
return	result;
}

int main(void)
 {
init_PWM();
  
PORTB=0x00;
DDRB=0b00001000; // oc2 pin
 
   while(1)
 
   {
	OCR2 = pwm_proc(50);
   }
 }
