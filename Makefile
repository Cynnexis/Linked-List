CC=gcc
CFLAGS=-Wall -Werror -g
LIB=liblist.a
PROGRAM=example

all: $(PROGRAM) $(LIB)

example: main.o boolean.h list.h list.o
	$(CC) $(CFLAGS) -static main.o -L. -llist -o example

main.o: main.c liblist.a boolean.h list.h
	$(CC) -c main.c

liblist.a: list.o boolean.h list.h
	ar rcs liblist.a list.o

list.o: list.c boolean.h list.h
	$(CC) -c list.c -o list.o

clean:
	rm -f *.o &> /dev/null
