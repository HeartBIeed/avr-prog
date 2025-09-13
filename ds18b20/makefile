MCU     = atmega16
F_CPU   = 8000000UL
TARGET  = ds18b20

CC      = avr-gcc
OBJCOPY = avr-objcopy


SRC     = $(wildcard *.c)
HEADERS = $(wildcard inc/*.h)
OBJ     = $(SRC:.c=.o)

CFLAGS  = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Iinc

all: $(TARGET).hex

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET).elf: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

