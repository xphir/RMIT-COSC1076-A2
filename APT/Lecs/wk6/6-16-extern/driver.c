/****************************************************************************
* Steven Burrows
* sdb@cs.rmit.edu.au
* 
* driver.c
* Example of extern storage class.
* Compile with:
* gcc -ansi -Wall -pedantic -o driver driver.c f1.c
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   extern int a;
   
   printf("Value of a is %d.\n", a);
   
   return EXIT_SUCCESS;
}
