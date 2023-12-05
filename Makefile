CC=gcc
CFLAGS= -g -Wall -std=c99

all:
	${CC} main.c ${CFLAGS}
clean:
	rm a.out
