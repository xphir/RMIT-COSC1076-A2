/****************************************************************************
* Steven Burrows
* sdb@cs.rmit.edu.au
* Example of an interface for dynamically allocated integer array.
****************************************************************************/

/* IntList
 * -- simple unordered array implementation that uses dynamic memory
 */

#include <stdio.h>
#include <stdlib.h>
#include "intlist.h"

int MakeList(IntList* pil,int size)
{
   if ((pil->array = malloc(sizeof(int) * size)) == NULL)
   {
      return FAILURE;
   }
   pil->size = 0;
   return SUCCESS;
}

void FreeList(IntList* pil)
{
   free(pil->array);
   pil->size = 0;
}

int AddList(IntList* pil,int num)
{
   if (pil->size >= INTLISTSIZE)
   {
      return FAILURE;
   }

   pil->array[pil->size] = num;
   pil->size += 1;

   return SUCCESS;
}

void DisplayList(IntList* pil)
{
   int i, size, *array;

   size = pil->size;
   array = pil->array;

   for(i=0; i<size; i++)
   {
      printf("%d\n", array[i]);
   }
}

unsigned SizeList(IntList* pil)
{
   return pil->size;
}
