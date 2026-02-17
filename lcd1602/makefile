MCU     = atmega32
F_CPU   = 8000000UL
TARGET  = main

CC      = avr-gcc
OBJCOPY = avr-objcopy
AVRDUDE = avrdude


INC_DIR = inc

SRC     = $(wildcard *.c)
OBJ     = $(SRC:.c=.o)

CFLAGS  = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -I$(INC_DIR)

all: $(TARGET).hex

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET).elf: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

clean:
	rm -f $(SRC_DIR)\*.o $(TARGET).elf 
