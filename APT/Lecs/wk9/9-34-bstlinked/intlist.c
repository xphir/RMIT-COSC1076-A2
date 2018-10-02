/****************************************************************************
* intlist-BST.c
* Example of an interface for a binary search tree
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "intlist.h"

int MakeList(IntList* pil,int size)
{
   pil->root = NULL;
   pil->size = 0;
 
   return SUCCESS;
}

void postorderFree(IntBSTNodePtr pNode)
{
   if (pNode)
   {
      postorderFree(pNode->left);
      postorderFree(pNode->right);
      free(pNode);
   }
}

void FreeList(IntList* pil)
{
   postorderFree(pil->root);
   pil->root = NULL;
   pil->size = 0;
}

int AddList(IntList* pBST,int data)
{
   IntBSTNodePtr current, previous, newNode;

   previous = NULL;
   current = pBST->root;
	/* search for branch onto which to attach the new leaf node */

   while (current != NULL)
   {
      previous = current;
      if (data < current->num)
         current = current->left;
      else /* ie. data >= current->data */
         current = current->right;
   }
        /* create the new leaf node */

   if ((newNode = malloc(sizeof(IntBSTNode))) == NULL)
   {
      return FAILURE;
   }

   newNode->num = data;
   newNode->left = NULL;
   newNode->right = NULL;
   pBST->size += 1;

   /* Our seach (above) either revealed this insertion
    * is the first; hence a root node is being created
    * or we found the branch on which to attach our new
    * leaf node
    */

   if (previous == NULL)
   {
      pBST->root = newNode;
      return SUCCESS;
   }

   /* if attached to a branch, we need to know if it
    * is attached as a left or right sub-tree
    */

   if (data < previous->num)
      previous->left = newNode;
   else
      previous->right = newNode;

   return SUCCESS;
}

void inorderDisplay(IntBSTNodePtr pNode)
{
   if (pNode)
   {
      inorderDisplay(pNode->left);
      printf("%d\n", pNode->num);
      inorderDisplay(pNode->right);
   }
}

void DisplayList(IntList* pil)
{
   inorderDisplay(pil->root);
}

unsigned SizeList(IntList* pil)
{
   return pil->size;
}
