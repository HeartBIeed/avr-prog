#ifndef LCD1602_H_
#define LCD1602_H_
#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

void LCD_ini(void);
void send(unsigned char c,unsigned char mode); 
void sendbyte(unsigned char c);
void sendchar(unsigned char c); 
void setpos(unsigned char x, unsigned y); 
void send_ptr_str(char *str);

#define E1 PORTA |=0b00001000// ��������� ����� E � 1 ������������ ����
#define E0 PORTA &=0b11110111 // ��������� ����� E � 0

#define RS1 PORTA |=0b00000010// ��������� ����� E � 1 ������������ ����
#define RS0 PORTA &=0b11111101 // ��������� ����� E � 0

#endif /* LCD1602_H_ */
