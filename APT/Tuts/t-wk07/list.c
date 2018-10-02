#include <stdio.h>
#include "list.h"

/* Initialise list */
Boolean list_init(IntList *list) {
	list->count = 0;
	return TRUE;
}

/* TRUE if list is full */
Boolean list_isFull(IntList *list){
	if (list->count < MAX_LEN)
		return FALSE;
	return TRUE;
}

/* returns the value at location 'index' */
static int  list_getInt(IntList *list, int index)
{
	return (list->data[index]);
}

/* inserts a value into location 'index' */
static void list_insert(IntList *list, int index, int value)
{
	list->data[index] = value;
} 

/* finds and returns the index of the location in the list to insert value */
static int list_findLocation(IntList *list, int value)
{
	/* assumes we have checked that list is not full */
	int pos;
	for (pos = 0; pos < list->count; pos++)
	{
		if (list->data[pos] >= value)
			break;
	}
	return pos;
}

/* Shuffles list contents 'up' to make room for inserting a new value */
static void list_shuffleUp(IntList *list, int pos)
{
	int i;
	for(i = list->count; i > pos; i--)
		list->data[i] = list->data[i - 1];
}

/* Adds a value to the list. Returns FALSE if add failed */
Boolean list_add(IntList *list, int value)
{
	int pos;

	if (list_isFull(list))
		return FALSE;

	pos = list_findLocation(list,value);
	list_shuffleUp(list, pos);
	list_insert(list,pos, value);
	list->count++;
	
	return TRUE;
}

void list_printList(IntList *list)
{
	int i;
	for(i = 0; i < list->count; i++)
		printf(" %d",list_getInt(list,i));
	printf("\n");
}

void list_delete(IntList *list)
{
	list->count = 0;
}
