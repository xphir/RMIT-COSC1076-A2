/****************************************************************************
* Steven Burrows
* sdb@cs.rmit.edu.au
* 
* intlist-main.c
* Example of an interface for an integer array.
****************************************************************************/

/* file: intlist-main.c
 */
#include <stdio.h>
#include <stdlib.h>
#include "intlist.h"


#define SIZE 10

int main(void)
{
   IntList il;
   int i;

   if (MakeList(&il, SIZE) == FAILURE)
   {
      fprintf(stderr, "MakeList(): failed\n");
      return EXIT_FAILURE;
   }

   /* Fill the IntList with random numbers. */
   for(i=0; i<SIZE; i++)
   {
      if (AddList(&il, rand() % 10) == FAILURE)
      {
         fprintf(stderr, "AddList(): failed\n");
         break;
      }
   }

   printf("IntList size is %u\n", SizeList(&il));

   DisplayList(&il);

   FreeList(&il);

   return EXIT_SUCCESS;
}
