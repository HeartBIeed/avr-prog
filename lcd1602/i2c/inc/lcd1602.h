#ifndef LCD1602_H_
#define LCD1602_H_

#include "main.h"

// ------- Выбрать и настроить порт: ------- 

#define	ADDR_LCD 0x27

// ------- Конец настроек порта ------- 

void LCD1602_ini(void);
void send_byte(uint8_t c,uint8_t mode); 
void send_nibble(uint8_t nibble,uint8_t mode);

void send_lcd_char(uint8_t c); 
// отправка 1 символа
void set_lcd_pos(uint8_t x, uint8_t y); 
// установка позиции Х 0-15, У 0-1.
void send_lcd_ptr_str(uint8_t *str);
// отправка строки по указателю массива
void create_symb(uint8_t index_symb, const uint8_t *data); 
//пользовательский символ

#endif /* LCD1602_H_ */
