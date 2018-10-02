CC = gcc

CFLAGS = -Wall -Wextra -Werror -ansi -pedantic

CPPFLAGS =

LDFLAGS =

DEBUG = -ggdb

INCLUDES =

TARGETS = \
container_static_array 

all: $(TARGETS)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(DEBUG) $(INCLUDES) -c $<

container_static_array: static_array.o main.o
	$(CC) $(LDFLAGS) $(DEBUG) -o $@ $^

clean:
	-$(RM) -f *.o $(TARGETS) >/dev/null 2>&1

.PHONY: clean

