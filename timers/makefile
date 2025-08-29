MCU     = atmega16
F_CPU   = 8000000UL
TARGET  = timer0

CC      = avr-gcc
OBJCOPY = avr-objcopy





SRC     = $(wildcard /*.c)
OBJ     = $(SRC:.c=.o)

CFLAGS  = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os 

all: $(TARGET).hex

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET).elf: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

