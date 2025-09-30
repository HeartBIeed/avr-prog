#ifndef LCD1602_H_
#define LCD1602_H_

#include "main.h"

//выбрать порт


#define E1 PORTA|=0x8; // установка линии E в 1 стробирующая шина
#define E0 PORTA&=0x4; // установка линии E в 0
#define RS1 PORTA|=0xF7; // установка линии RS в 1 (данные)
#define RS0 PORTA&=0xFB; // установка линии RS в 0 (команда)

void LCD1602_ini(void);
void send_byte(unsigned char c,unsigned char mode); 
void send_nibble(unsigned char c);

void send_lcd_char(unsigned char c); 
// отправка 1 символа
void set_lcd_pos(unsigned char x, unsigned y); 
// установка позиции Х 0-15, У 0-1.
void send_lcd_ptr_str(char *str);
// отправка строки по указателю массива
void create_symb(unsigned char index_symb, const unsigned char *data); 
//пользовательский символ

#endif /* LCD1602_H_ */
