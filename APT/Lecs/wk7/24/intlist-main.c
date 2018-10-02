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
#define INTLIST "intlist-array.h"

#ifdef INTLIST  
#include INTLIST
#else
#error INTLIST must be defined with the quoted string header file name
#endif

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

   /* fill the IntList with random numbers */
   for(i=0; i<SIZE; i++)
   {
      if (AddList(&il, rand()) == FAILURE)
      {
         fprintf(stderr, "AddList(): failed\n");
         break;
      }
   }

   printf("IntList size is %u\n", SizeList(&il));

   DisplayList(&il);
   SelectionSortList(&il);
   printf("Sorted data:\n");
   DisplayList(&il);

   FreeList(&il);

   return EXIT_SUCCESS;
}
