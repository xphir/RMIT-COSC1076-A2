/****************************************************************************
* Steven Burrows
* sdb@cs.rmit.edu.au
* 
* intlist-linked-list.c
* Example of an interface for a linked list of integers.
****************************************************************************/

/*
 * IntList
 * -- simple unordered linked list 
 *  Uses recursion for printing
 */

#include <stdio.h>
#include <stdlib.h>

#include "intlist.h"

int MakeList(IntList* pil,int size)
{
   pil->head = NULL;
   pil->size = 0;
 
   return SUCCESS;
}

void FreeList(IntList* pil)
{
   IntListNodePtr current, next;

   current = pil->head;

   while (current != NULL)
   {
      next = current->next;
      free(current);
      current = next;
   }

   pil->head = NULL;
   pil->size = 0;
}

int AddList(IntList* pil,int num)
{
   IntListNodePtr newNode;
printf("AddList adding %d\n",num);

   if ((newNode = malloc(sizeof(IntListNode))) == NULL)
   {
      return FAILURE;
   }

   newNode->num = num;
   newNode->next = pil->head;
   pil->head = newNode;
   pil->size += 1;

   return SUCCESS;
}

void DisplayNodeList(IntListNode* current)
{
   if (current != NULL)
   {
      printf("%d\n",current->num);
      DisplayNodeList(current->next);
   }
}

void DisplayList(IntList* pil)
{
   DisplayNodeList(pil->head);
}

unsigned SizeList(IntList* pil)
{
   return pil->size;
}
