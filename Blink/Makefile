CC=msp430-gcc
CFLAGS=-Wall -mmcu=msp430fr5739

OBJS=main.o

all: $(OBJS)
	$(CC) $(CFLAGS) -o main.elf $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -fr main.elf $(OBJS)

prog:
	mspdebug rf2500