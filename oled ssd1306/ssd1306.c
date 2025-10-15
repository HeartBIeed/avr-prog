#include "ssd1307.h"


static void ssd1307_begin()
{
i2c_start(); 
i2c_send_adress(0x3c); 

i2c_send(0xAE); // display off

i2c_send(0x20); i2c_send(0x00);
i2c_send(0xD5); i2c_send(0x80); 
i2c_send(0xA8); i2c_send(0x27);
i2c_send(0xD3); i2c_send(0x00);

i2c_send(0x40);
i2c_send(0xA1);
i2c_send(0xC8);

i2c_send(0xDA); i2c_send(0x02);
i2c_send(0x81); i2c_send(0x7F);
i2c_send(0xD9); i2c_send(0xF1);
i2c_send(0xDB); i2c_send(0x40);

i2c_send(0xA4);
i2c_send(0xA6);

i2c_send(0xAF); // display on

i2c_stop();
}

static void ssd1307_fill(uint8_t b)
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
    i2c_init();

    _delay_ms(10);

ssd1307_begin();



    while(1){

ssd1307_fill(0xFF);
_delay_ms(1000);
ssd1307_fill(0x00);
_delay_ms(1000);

    }
}