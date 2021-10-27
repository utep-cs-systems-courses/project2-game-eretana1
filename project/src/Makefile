# makefile configuration
COMMON_OBJECTS  =
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: main.elf

#additional rules for files
main.elf: ${COMMON_OBJECTS} buzzer.o led.o switches.o stateMachines.o wdInterruptHandler.o main.o led-assy-c.o ../lib/libTimer.a
	${CC} ${CFLAGS} -o $@ $^

load: main.elf
	msp430loader.sh  $^

main-s.elf: ${COMMON_OBJECTS} buzzer.o led.o switches.o stateMachines.o wdInterruptHandler.o main.o led-assy-s.o ../lib/libTimer.a
	${CC} ${CFLAGS} -o $@ $^

load-s: main-s.elf
	msp430loader.sh  $^


clean: $^
	rm -f *.o *.elf *.c~ *.h~ *.c#

buzzer.o: buzzer.h
led.o: led.h
switches.o: switches.h led.h
stateMachines.o: stateMachines.h led.h
wdInterruptHandler.o: stateMachines.h switches.h buzzer.h led.h led-assy.h
led-assy-c.o: led.h led-assy.h
led-assy-s.o: led.h led-assy.h
