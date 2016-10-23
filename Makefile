CC=gcc
CFLAGS=-Wall -Werror -g
PROGRAM=example

all: $(PROGRAM)

example: main.o boolean.h list.h list.o
	$(CC) $(CFLAGS) -static main.o -Llib -llist -o example

main.o: main.c liblist.a boolean.h list.h
	$(CC) -c main.c

liblist.a: list.o boolean.h list.h
	ar rcs liblist.a list.o
	if [ ! -d ./lib ]; then mkdir lib; fi
	mv liblist.a lib

list.o: list.c boolean.h list.h
	$(CC) -c list.c -o list.o

clear:
	rm -f *.o *.a $(PROGRAM) &> /dev/null
	rm -r lib &> /dev/null
