# Author Karl Stiller
# Makefile for the Midnight-Console project
# 29/12/2017

SHELL = /bin/sh


OBJS = Pack.o Card.o main.o
CFLAG = -Wall -g
CC = g++
INCLUDE =

midnight:${OBJ}
	${CC} ${CFLAGS} ${INCLUDES} -o $@ ${OBJS} ${LIBS}

clean:
	-rm -f *.o
	
.cpp.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $<