########################################################################
# Student name: 	...
# Student number: 	...
# Course: 			Advanced Programming Techniques - S2 2018
########################################################################
CC = gcc
RM = rm -rf
CFLAGS = -Wall -pedantic -ansi
LIBS = -lm

SOURCES=drive.c gene.c invector.c pop.c utility.c
HEADERS=drive.h gene.h invector.h pop.h utility.h
EXECUTABLES = ga
ARGS = 




all: $(SOURCES)
	$(CC) $(CFLAGS) -o $(EXECUTABLES) $(SOURCES) $(LIBS)

DEBUG: CFLAGS += -DDEBUG
DEBUG: all

PCBTEST: ARGS += pcbmill 12 20 50 pcbin.dat
PCBTEST: TEST

MINTEST: ARGS += minfn 4 20 50 minfnin.dat
MINTEST: TEST

TEST: $(SOURCES)
	valgrind --track-origins=yes ./$(EXECUTABLES) $(ARGS)

clean:
	$(RM) $(EXECUTABLES)