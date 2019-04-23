#Контроллер, установленный на плате. Может быть другим, например atmega328
# DEVICE     = atmega168

# DEVICE     = atmega2560
DEVICE       = atmega328p
DEVICEF      = ATmega328P
TARGET       = doorbell

#Тактовая частота 16 МГц
CLOCK      = 16000000

#Команда запуска avrdude. Ее нужно скопировать из Arduino IDE.

AVRDUDE = sudo avrdude -v -c arduino -P `ls /dev/ttyU*` -p $(DEVICE) -b115200
USBASP = sudo avrdude -v -c usbasp -p $(DEVICE)

PCFDIR=libs/pcf8563

#SRCS=
OBJS=$(PCFDIR)/i2csoft.o $(PCFDIR)/PCF8563.o

CFLAGS= -w -ffreestanding -MD -Werror -Wl,--gc-sections -ffunction-sections -fdata-sections -I$(PCFDIR)
LIBS = -Wl,-u,vfprintf -lprintf_flt -lm


# //bin/avrdude -C//etc/avrdude.conf -v -patmega2560 -cwiring -P/dev/ttyACM0 -b115200 -D -Uflash:w:/tmp/arduino_build_439882/sketch_mar05a.ino.hex:i

OBJECTS    = $(TARGET).o $(OBJS)

COMPILE = avr-gcc $(CFLAGS) $(LIBS) -Wall -Os -DF_CPU=$(CLOCK) -mmcu=$(DEVICE)

all:	$(TARGET).hex

.c.o:
	$(COMPILE) -c $< -o $@

.S.o:
	$(COMPILE) -x assembler-with-cpp -c $< -o $@

.c.s:
	$(COMPILE) -S $< -o $@

flash:	all
	$(AVRDUDE) -U flash:w:$(TARGET).hex:i

asp: all
	$(USBASP) -U flash:w:$(TARGET).hex:i

readflash:
	$(AVRDUDE) -U flash:r:read.hex:i

clean:
	rm -f $(TARGET).hex $(TARGET).elf $(OBJECTS)

$(TARGET).elf: $(OBJECTS)
	$(COMPILE) -o $(TARGET).elf $(OBJECTS)

$(TARGET).hex: $(TARGET).elf
	rm -f $(TARGET).hex
	avr-objcopy -j .text -j .data -O ihex $(TARGET).elf $(TARGET).hex
	avr-size --format=avr --mcu=$(DEVICE) $(TARGET).elf


flashapp:
	make DEVICE=atmega328p all flash
