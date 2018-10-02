#include <stdio.h>
#include <stdlib.h>
#include "list.h"


listType * createList(void)
{
		listType *list;
		
		if ((list = malloc(sizeof(listType))) == NULL)
			return NULL;
		list->count = 0;
		list->head = NULL;
		return list;
}

void insertSorted(listType *list, char data)
{
	/* not elegant, but easy to follow for teaching purposes */

	listElementType *current, *previous, *newElement;

	if ((newElement = malloc(sizeof(newElement))) == NULL)
	{
		fprintf(stderr,"insertSorted: unable to create new element\n");
		exit(EXIT_FAILURE);
	}

	newElement->data = data;
	newElement->next = NULL;

	current = list->head;
			
	if (current == NULL) /* empty list so insert at front */
		list->head = newElement;
	else	
	if (data <= current->data)  /* item comes before existing list, insert at front */
	{
		newElement->next = list->head;
		list->head = newElement;
	}
	else
	{	
		previous = current;	
		while (current != NULL)
		{
			if (data > current->data)    /* find location to insert (between previous and current) */
			{
				previous = current;
				current = current->next;
			}
			else
				break;
		}
		  
		previous->next = newElement;  /* insert the node */
		newElement->next = current;	
	}		
	list->count++;
}

void delete(listType *list, char data)
{
	/* not elegant, but easy to follow for teaching purposes */
	listElementType *current, *previous;
	current = list->head;
			
	if (current == NULL) /* empty list */
	{
		fprintf(stderr,"delete from empty list\n");
		exit(EXIT_FAILURE);
	}

	if (data == current->data)  /* item first thing in list */
	{
		list->head = list->head->next;
		free(current);
	}
	else
	{	
		previous = current;	/* find location to remove (pointed to by current) */
		while (current != NULL)
		{
			if (data == current->data) 
				break;
			else
			{
				previous = current;
				current = current->next;
			}
		}
		if (current == NULL)
		{
			fprintf(stderr,"delete: not found in list\n");
			exit(EXIT_FAILURE);
		}
		previous->next = current->next;
		free(current);	
	}		
	list->count--;
}

void reset(listType *list)
{
	listElementType *current;

	
	while (list->head != NULL)
	{
		current = list->head;
		list->head = list->head->next;
		free(current);
		
	}
	list->count = 0;
}

void display(listType *list)
{
	/* interative traversal of list. Will do recursive later later in semester */
	listElementType *current;
	current = list->head;
	printf("list size %d: ",list->count);
	while (current != NULL)
	{
		printf("%c ",current->data);
		current = current->next;
	}
	printf("\n");
}
