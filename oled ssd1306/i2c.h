#ifndef I2C_H_
#define I2C_H_

#include "ssd1307.h"

void i2c_init(void);
void i2c_start(void);
void i2c_stop(void);
void i2c_send_adress(uint8_t adress);
void i2c_send(uint8_t data);
uint8_t i2c_read_byte(void);
uint8_t i2c_read_byte_NACK(void);


#endif /* I2C_H_ */