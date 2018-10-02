/****************************************************************************
* Steven Burrows
* sdb@cs.rmit.edu.au
* 
* calloc.c
* Example of calloc function.
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
   int* ptr;
   const int numItems = 10;
   int i;
   
   ptr = calloc(numItems, sizeof(int));
   
   if (ptr == NULL)
   {
      printf("Unable to get %d bytes.\n", (int) (numItems * sizeof(int)));
      return EXIT_FAILURE;
   }
   

   for (i = 0; i < numItems; i++)
   {
      printf("Value at index %d is %d.\n", i, ptr[i]);
   }
   
	free(ptr);
   return EXIT_SUCCESS;
}

