# ---- Настройки проекта ----
MCU     = atmega16
F_CPU   = 8000000UL
TARGET  = main

# ---- Инструменты ----
CC      = avr-gcc
OBJCOPY = avr-objcopy
AVRDUDE = avrdude

# ---- Папки ----
SRC_DIR = src
INC_DIR = inc

# ---- Файлы ----
SRC     = $(wildcard $(SRC_DIR)/*.c)
OBJ     = $(SRC:.c=.o)

# ---- Флаги компилятора ----
CFLAGS  = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -I$(INC_DIR)

# ---- Цели ----
all: $(TARGET).hex

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET).elf: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

clean:
	rm -f $(SRC_DIR)\*.o $(TARGET).elf 