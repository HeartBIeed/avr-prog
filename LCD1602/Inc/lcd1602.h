#ifndef LCD1602_H_
#define LCD1602_H_

#include "main.h"


void LCD_ini(void);
void send(unsigned char c,unsigned char mode); 
void sendbyte(unsigned char c);
void sendchar(unsigned char c); 
void setpos(unsigned char x, unsigned y); 
void send_ptr_str(char *str);
//void load_my_char();

#endif /* LCD1602_H_ */
