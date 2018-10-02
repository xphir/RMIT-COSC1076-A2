###############################################################################
# Steven Burrows  
# sdb@cs.rmit.edu.au
#
# makefile:
###############################################################################

# Compile flags
CFLAGS = -ansi -Wall -pedantic -gstabs
# Complier
CC = gcc

intlist: intlist-main.o intlist-array.o
	$(CC) $(CFLAGS) -o intlist intlist-main.o intlist-array.o

intlist-main.o: intlist-main.c
	$(CC) $(CFLAGS) -c intlist-main.c

intlist-array.o: intlist-array.c intlist-array.h
	$(CC) $(CFLAGS) -c intlist-array.c
