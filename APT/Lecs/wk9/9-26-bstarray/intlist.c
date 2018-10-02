/****************************************************************************
* intlist-BST.c
* Example of an interface for a binary search tree
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "intlist.h"

int MakeList(IntList* pil,int size)
{
   int i;
   pil->size = 0;
   for(i = 0; i < INTLISTSIZE; i++)
      pil->numArray[i] = EMPTY;
 
   return SUCCESS;
}

void FreeList(IntList* pil)
{
   int i;
   pil->size = 0;
   for(i = 0; i < INTLISTSIZE; i++)
      pil->numArray[i] = EMPTY;
}

int getLeftIndex(int i)
{
	return (2 * i) + 1;
}

int getRightIndex(int i)
{
	return (2 * i) + 2;
}

int AddList(IntList* pBST,int data)
{
   int current = 0;

   printf("Adding %d\n",data);

   if (pBST->size == 0)
   {
   	/* This insertion is the first */
      pBST->numArray[0] = data;
      pBST->size += 1;
      return SUCCESS;
   }

	/* search for branch onto which to attach the new leaf node */
   while (current < INTLISTSIZE && pBST->numArray[current] != EMPTY)
   {
      if (data < pBST->numArray[current])
         current = getLeftIndex(current);
      else /* ie. data >= current->data */
         current = getRightIndex(current);
   }

	/* are we off the end of the array? */
   if (current >= INTLISTSIZE)
      return FAILURE;

        /* create the new leaf node */
   pBST->numArray[current] = data;
   pBST->size += 1;

   return SUCCESS;
}

void inorderDisplay(IntList* pil, int current)
{
   if (current < INTLISTSIZE && pil->numArray[current] != EMPTY)
   {
      inorderDisplay(pil,getLeftIndex(current));
      printf("%d\n", pil->numArray[current]);
      inorderDisplay(pil,getRightIndex(current));
   }
}

void preorderDisplay(IntList* pil, int current)
{
   if (current < INTLISTSIZE && pil->numArray[current] != EMPTY)
   {
      printf("%d\n", pil->numArray[current]);
      preorderDisplay(pil,getLeftIndex(current));
      preorderDisplay(pil,getRightIndex(current));
   }
}

void postorderDisplay(IntList* pil, int current)
{
   if (current < INTLISTSIZE && pil->numArray[current] != EMPTY)
   {
      postorderDisplay(pil,getLeftIndex(current));
      postorderDisplay(pil,getRightIndex(current));
      printf("%d\n", pil->numArray[current]);
   }
}

void DisplayList(IntList* pil)
{
   /* inorderDisplay(pil,0); */
   /* preorderDisplay(pil,0); */
   /* postorderDisplay(pil,0); */
   preorderDisplay(pil,0);
}

unsigned SizeList(IntList* pil)
{
   return pil->size;
}
