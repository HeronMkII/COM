CC = avr-gcc
CFLAGS = -std=gnu99 -g -mmcu=atmega32m1 -Os -mcall-prologues
PROG = stk500 # the Pololu acts like the STK500
MCU = m32m1
PORT = /dev/tty.usbmodem00187462

INCLUDES = -I./lib-common/include/
LIB = -L./lib-common/lib/ -lspi -luart -lcan -ltimer

SRC = $(wildcard ./src/*.c)
OBJ = $(SRC:./src%.c=./build%.o)
DEP = $(OBJ:.o=.d)

com: $(OBJ)
	$(CC) $(CFLAGS) -o ./build/$@.elf $^ $(LIB)
	avr-objcopy -j .text -j .data -O ihex ./build/$@.elf ./build/$@.hex

./build/%.o: ./src/%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

-include $(DEP)

./build/%.d: ./src/%.c
	@$(CC) $(CFLAGS) $< -MM -MT $(@:.d=.o) >$@

.PHONY: clean upload

clean:
	rm -f $(OBJ)
	rm -f $(DEP)
	rm -f ./build/*.*

upload: com
	avrdude -p $(MCU) -c $(PROG) -P $(PORT) -U flash:w:./build/$^.hex
