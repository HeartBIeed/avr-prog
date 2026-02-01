#include "ssd1306.h"

void ssd1306_cmd(uint8_t cmd)
{
    i2c_start(); 
    i2c_send(0x00);
    i2c_send(cmd);
    i2c_stop();
}

void ssd1306_data(uint8_t data)
{
    i2c_start(); 
    i2c_send(0x40);
    i2c_send(data);
    i2c_stop();
}

static void ssd1306_begin()
    {
    i2c_send_adress(0x3c); 

    ssd1306_cmd(0xAE); // display off

    ssd1306_cmd(0xD5);    ssd1306_cmd(0x80);
    ssd1306_cmd(0xA8);    ssd1306_cmd(63); 
    ssd1306_cmd(0xD3);    ssd1306_cmd(0);
    ssd1306_cmd(0x40);    ssd1306_cmd(0x8D);

    ssd1306_cmd(0x10);
    ssd1306_cmd(0x20);
    ssd1306_cmd(0x00);

    ssd1306_cmd(0xA0);    ssd1306_cmd(0xC8);
    ssd1306_cmd(0xDA);    ssd1306_cmd(0x12);
    ssd1306_cmd(0x81);    ssd1306_cmd(0x9F);
    ssd1306_cmd(0x22);    ssd1306_cmd(0xD8);

    ssd1306_cmd(0x40);    ssd1306_cmd(0xA4);
    ssd1306_cmd(0xA6);    ssd1306_cmd(0x2E);

    ssd1306_cmd(0xAF); // display on

    }

static void ssd1306_fill(uint8_t b)
    {
        i2c_start(); 
        i2c_send_adress(0x3c); 

        ssd1306_cmd(0x21); 
        ssd1306_cmd(0x7F); 
        ssd1306_cmd(0x22);
        ssd1306_cmd(0x07);

        i2c_stop();


        for (uint16_t i = 0; i < (128*64/8); i++) 
            {
                ssd1306_data(b);
            }



    }


int main()
{
        _delay_ms(100);

    i2c_init();
        _delay_ms(10);

    ssd1306_begin();
        _delay_ms(10);


while(1)
    {

        ssd1306_fill(0xFF);
            _delay_ms(1000);
        ssd1306_fill(0x00);
            _delay_ms(1000);

    }
}