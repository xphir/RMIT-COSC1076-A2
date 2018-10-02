########################################################################
# Student name: 	...
# Student number: 	...
# Course: 			Advanced Programming Techniques - S2 2018
########################################################################
CC = gcc
RM = rm -rf
CFLAGS = -Wall -pedantic -ansi -g

SOURCES=drive.c gene.c invector.c pop.c utility.c
HEADERS=drive.h gene.h invector.h pop.h utility.h
README=ga_readme
MAKEFILE=Makefile
EXECUTABLES = ga

all: $(SOURCES)
	$(CC) $(CFLAGS) -o $(EXECUTABLES) $(SOURCES)

DEBUG: $(SOURCES)
	$(CC) $(CFLAGS) -o $(EXECUTABLES) $(SOURCES)

clean:
	$(RM) $(EXECUTABLES)


########################################################################
# Move this target to the end of the Makefile to zip up your code 
# when submitting. Do not submit your .dat files, or directories. 
# We only want the files that are part of your implementation.
########################################################################
	
archive:
	zip $(USER)-a2 $(SOURCES) $(HEADERS) $(README) $(MAKEFILE)