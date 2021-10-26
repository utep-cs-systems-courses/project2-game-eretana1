# makefile configuration
COMMON_OBJECTS  =
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: main.elf

#additional rules for files
main.elf: ${COMMON_OBJECTS} buzzer.o led.o switches.o stateMachines.o wdInterruptHandler.o main.o ../lib/libTimer.a
	${CC} ${CFLAGS} -o $@ $^

load: main.elf
	msp430loader.sh  $^

clean: $^
	rm -f *.o *.elf *.c~ *.h~ *.c#

buzzer.c: buzzer.h
led.c: led.h
switches.c: switches.h led.h
stateMachines.c: stateMachines.h led.h
wdInterruptHandler.c: stateMachines.h switches.h buzzer.h led.h
