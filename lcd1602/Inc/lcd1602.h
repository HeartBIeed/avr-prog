#ifndef LCD1602_H_
#define LCD1602_H_

#include "main.h"

#define E1 PORTA|=0b00001000 // установка линии E в 1 стробирующая шина
#define E0 PORTA&=0b11110111 // установка линии E в 0
#define RS1 PORTA|=0b00000100 // установка линии RS в 1 (данные)
#define RS0 PORTA&=0b11111011 // установка линии RS в 0 (команда)

void iniport_LCD(void);
void LCD_ini(void);
void send(unsigned char c,unsigned char mode); 
void sendbyte(unsigned char c);
void sendchar(unsigned char c); 
void setpos(unsigned char x, unsigned y); 
void send_ptr_str(char *str);

#endif /* LCD1602_H_ */
