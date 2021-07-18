SHELL=/bin/sh

CC=g++
LDFLAGS+=-lX11 -lXcursor -lXext -lXrandr
CFLAGS= -g -Wall -Wextra -pedantic

all:clean build
clean:
	rm lde
build: main.cpp Makefile
	${CC} main.cpp ${CFLAGS} ${LDFLAGS} -o lde
