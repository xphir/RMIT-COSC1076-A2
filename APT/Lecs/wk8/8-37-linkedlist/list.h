#ifndef _LIST_H_
#define _LIST_H_

typedef struct list_element  
{
   char data;
   struct list_element *next;
}  listElementType;


typedef struct list
{
	int count;
	listElementType *head;
} listType;

listType * createList(void);
void insertSorted(listType *list, char data);
void delete(listType *list, char data);
void reset(listType *list);
void display(listType *list);
#endif
