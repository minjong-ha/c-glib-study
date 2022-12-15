CFLAGS=-std=c99 -Wall -g
SRC=src


all: main.c
	gcc ${CFLAGS} -o run main.c ${SRC}/*.c `pkg-config --cflags --libs glib-2.0`

clean:
	rm run
