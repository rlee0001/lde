SHELL=/bin/sh

CC=g++
LDFLAGS+=-lXaw -lXt -lX11 -lXcursor -lXext -lXrandr -lcairo
CFLAGS=-std=c++2b -g -Wall -Wextra -pedantic
DIST=dist/
WM=${DIST}lde-wm
CALC=${DIST}lde-calc

all: ${WM} ${CALC}
clean:
	rm -rf ${DIST}*
${WM}: wm/main.cpp Makefile
	@mkdir -p $(@D)
	@${CC} $< ${CFLAGS} ${LDFLAGS} -o $@
${CALC}: calc/main.cpp Makefile
	@mkdir -p $(@D)
	@${CC} $< ${CFLAGS} ${LDFLAGS} -o $@