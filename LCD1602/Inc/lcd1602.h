#ifndef LCD1602_H_
#define LCD1602_H_

#define RS1 PORTA |=(1 << 2) // установка линии RS в 1 (данные)
#define RS0 PORTA &=~(1 << 2) // установка линии RS в 0 (команда)

#define E1 PORTA |=(1 << 4) // установка линии E в 1 стробирующая шина
#define E0 PORTA &=~(1 << 4) // установка линии E в 0

void LCD_ini(void);
void send(unsigned char c,unsigned char mode); 
void sendbyte(unsigned char c);
void sendchar(unsigned char c); 
void setpos(unsigned char x, unsigned y); 
void send_ptr_str(char *str);

#endif /* LCD1602_H_ */
