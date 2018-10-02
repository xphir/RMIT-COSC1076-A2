CC = gcc
DEBUG = -g
CFLAGS = -ansi -Wall -pedantic $(DEBUG)
PROG = myprog
OBJS = driver.o io.o calc.o

all: $(OBJS)
	@echo "linking all object files"
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS)

%.o: %.c %.h
	@echo "compiling "
	$(CC) $(CFLAGS) -c $^

clean:
	@echo "cleaning"
	rm -f *.o $(PROG)
