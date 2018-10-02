###############################################################################
# Steven Burrows
# sdb@cs.rmit.edu.au
#
###############################################################################

myprog: driver.o io.o calc.o
	gcc -ansi -Wall -pedantic -o myprog driver.o io.o calc.o

driver.o: driver.c driver.h 
	gcc -ansi -Wall -pedantic -c driver.c 

io.o: io.c io.h 
	gcc -ansi -Wall -pedantic -c io.c

calc.o: calc.c calc.h 
	gcc -ansi -Wall -pedantic -c calc.c
