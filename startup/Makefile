########################################################################
# Student name: 	Elliot Schot
# Student number: 	S3530160
# Course: 			Advanced Programming Techniques - S2 2018
########################################################################
CC = gcc
RM = rm -rf
CFLAGS = -Wall -pedantic -ansi
LIBS = -lm
ARGS =
VALOPS =
SOURCES=drive.c gene.c invector.c pop.c utility.c
HEADERS=drive.h gene.h invector.h pop.h utility.h
EXECUTABLES = ga


all: $(SOURCES)
	$(CC) $(CFLAGS) -o $(EXECUTABLES) $(SOURCES) $(LIBS)

DEBUG: CFLAGS += -DDEBUG
DEBUG: all

PCBTEST1: ARGS += pcbmill 12 20 50 pcbin.dat
PCBTEST1: VALOPS += --leak-check=full --show-reachable=yes
PCBTEST1: TEST

PCBTEST2: ARGS += pcbmill 12 20 50 pcbin.dat
PCBTEST2: VALOPS += --track-origins=yes
PCBTEST2: TEST

MINTEST1: ARGS += minfn 4 20 50 minfnin.dat
MINTEST1: VALOPS += --leak-check=full --show-reachable=yes
MINTEST1: TEST

MINTEST2: ARGS += minfn 4 20 50 minfnin.dat
MINTEST2: VALOPS += --track-origins=yes
MINTEST2: TEST

TEST: $(SOURCES)
	valgrind $(VALOPS) ./$(EXECUTABLES) $(ARGS)

clean:
	$(RM) $(EXECUTABLES)

########################################################################
# Move this target to the end of the Makefile to zip up your code 
# when submitting. Do not submit your .dat files, or directories. 
# We only want the files that are part of your implementation.
########################################################################
	
archive:
	zip $(USER)-a2 $(SOURCES) $(HEADERS) $(README) $(MAKEFILE)