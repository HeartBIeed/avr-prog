#ifndef I2C_H_
#define I2C_H_

#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

void i2c_init(void);
void i2c_start(void); // старт i2c
void i2c_stop(void); // стоп i2c
void i2c_send_adress(uint8_t adress); 
void i2c_send(uint8_t data);
uint8_t i2c_read_byte(void); // чтение 
uint8_t i2c_read_byte_NACK(void); // чтение последнего байта


#endif /* I2C_H_ */