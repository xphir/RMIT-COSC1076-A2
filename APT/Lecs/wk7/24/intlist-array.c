/****************************************************************************
* Steven Burrows
* sdb@cs.rmit.edu.au
* 
* intlist-array.c
* Example of an interface for an integer array.
****************************************************************************/

/* file: intlist-array.c
 *
 * IntList -- simple unordered array implementation
 */
 
#include <stdio.h>
#include "intlist-array.h"

int MakeList(IntList* pil,int size)
{
   if (size > INTLISTSIZE)
   {
      return FAILURE;
   }
   pil->size = 0;
   return SUCCESS;
}

void FreeList(IntList* pil)
{
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

void SelectionSortList(IntList* pil)
{
   int i, j, smallestIndex, temp;

   for (i = 0; i < pil->size - 1; i++)
   {
      smallestIndex = i;

      for (j = i; j < pil->size; j++)
      {
         if (pil->array[j] < pil->array[smallestIndex])
         {
            smallestIndex = j; 
         }         
      }
      temp = pil->array[smallestIndex];
      pil->array[smallestIndex] = pil->array[i];
      pil->array[i] = temp; 
   } 
}
