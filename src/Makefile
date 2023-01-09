FAMILY=-mpic14
MCU=-p12f683
CC=sdcc
LD=sdcc
CFLAGS=-I. -I/usr/local/share/sdcc/non-free/include
TARGET=dado

SRCS = dado.c

all:
	${CC} --use-non-free ${FAMILY} ${MCU} ${CFLAGS} -o ${TARGET} ${SRCS}

clean:
	rm -f *.c~ *.h~ *.o *.elf *.hex *.asm
