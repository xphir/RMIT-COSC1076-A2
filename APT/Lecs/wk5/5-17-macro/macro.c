/****************************************************************************
* Steven Burrows
* sdb@cs.rmit.edu.au
* 
* macro.c
* Example of a simple macro.
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define sq(x) ((x) * (x))

int main(void)
{
   int num = 3;
   int square;
   
   square = sq(3);
   
   printf("Square of %d is %d\n", num, square);
   
   return EXIT_SUCCESS;
}
