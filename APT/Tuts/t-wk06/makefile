# 
# This is a simple makefile for the complex data type example 
# When you learn more about make and makefiles you will discover 
# that it is possible to write considerably more 'concise' makefiles. 
# 
# A fully annotated version of the makefile can be found in 
# 'makefile.annotated' 
# 
all: main.o complex.o 
	gcc -o complex-main main.o complex.o 
main.o: main.c complex.h 
	gcc -Wall -ansi -pedantic -c main.c 
complex.o: complex.c complex.h 
	gcc -Wall -ansi -pedantic -c complex.c 
# 
# The End 
# 
