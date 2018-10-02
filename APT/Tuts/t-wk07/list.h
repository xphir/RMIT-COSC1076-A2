#ifndef _LIST_H
#define _LIST_H

#include <stdio.h>

#define MAX_LEN 5

typedef enum boolean
{ 	FALSE = 0, 
	TRUE 
} Boolean;

typedef struct
{
	int data[MAX_LEN];
	int count;
} IntList;

/* places list in a safe state */
Boolean list_init(IntList *list);

/* Adds value to the list. Returns FALSE if unsuccessful */
Boolean list_add(IntList*, int value);

/* Prints the list */
void list_printList(IntList *list);

void list_delete(IntList *list);

#endif
