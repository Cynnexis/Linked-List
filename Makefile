CC=gcc
CFLAGS=-Wall -Werror -g

all: example

example: main.o boolean.h list.h list.o
	$(CC) $(CFLAGS) list.o main.o -o example

main.o: main.c boolean.h list.h
	$(CC) -c main.c

list.o: list.c boolean.h list.h
	$(CC) -c list.c
