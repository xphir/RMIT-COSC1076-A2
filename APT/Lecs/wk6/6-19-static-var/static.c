/****************************************************************************
* Steven Burrows
* sdb@cs.rmit.edu.au
* 
* static.c
* Example of static storage class.
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void funct();
void staticFunct();

int main(void)
{
   printf("Calling funct() 3 times:\n");
   funct();
   funct();
   funct();
   
   printf("Calling staticFunct() 3 times:\n");
   staticFunct();
   staticFunct();
   staticFunct();
   
   return EXIT_SUCCESS;
}

void funct()
{
   int counter = 0;
   
   printf("Value of funct() counter: %d.\n", counter);
   
   counter++;
}

void staticFunct()
{
   static int counter = 0;
   
   printf("Value of staticFunct() counter: %d.\n", counter);
   
   counter++;
}
