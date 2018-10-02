###############################################################################
# Another very simple makefile. Run as one of:
# make
# make clean
# make debug
#
###############################################################################

CC = gcc
CCFLAGS = -ansi -Wall -pedantic 
LIBS = -lm

all: myprog 

debug: CCFLAGS += -DDEBUG
debug: myprog

myprog: driver.o io.o calc.o
	$(CC) $(CCFLAGS) -o myprog driver.o io.o calc.o $(LIBS)

driver.o: driver.c driver.h 
	$(CC) $(CCFLAGS) -c driver.c $(LIBS)

io.o: io.c io.h 
	$(CC) $(CCFLAGS) -c io.c $(LIBS)

calc.o: calc.c calc.h 
	$(CC) $(CCFLAGS) -c calc.c $(LIBS)

clean:
	rm myprog *.o

