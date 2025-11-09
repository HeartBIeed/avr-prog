#include "ssd1306.h"


static void ssd1306_begin()
    {
    i2c_start(); 
    i2c_send_adress(0x3c); 

    i2c_send(0xAE); // display off

    i2c_send(0x20);    i2c_send(0x10);
    i2c_send(0xB0);    i2c_send(0xC8); 
    i2c_send(0x00);    i2c_send(0x10);
    i2c_send(0x40);    i2c_send(0x81);

    i2c_send(0xFF);
    i2c_send(0xA1);
    i2c_send(0xA6);

    i2c_send(0xA8);    i2c_send(0x3F);
    i2c_send(0xA4);    i2c_send(0xD3);
    i2c_send(0x00);    i2c_send(0xD5);
    i2c_send(0xF0);    i2c_send(0xD9);

    i2c_send(0x22);    i2c_send(0xDA);
    i2c_send(0x12);    i2c_send(0xDB);
    i2c_send(0x20);    i2c_send(0x8D);


    i2c_send(0x14);
    i2c_send(0xAF); // display on

    i2c_stop();
    }

static void ssd1306_fill(uint8_t b)
    {
        i2c_start(); 
        i2c_send_adress(0x3c); 

        i2c_send(0x00);


        i2c_send(0x21); i2c_send(0x00); i2c_send(0x7F); 
        i2c_send(0x22); i2c_send(0x00); i2c_send(0x07);

        i2c_stop();


        for (uint16_t i = 0; i < (128*64/8); i++) 
            {
                i2c_start(); 
                i2c_send(0x40);
                i2c_send(b);
                i2c_stop();
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