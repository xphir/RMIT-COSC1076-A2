#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
	char name[10];  /*yes, magic numbers are bad... */
	char address[20];
	struct person *next;
}Person;

Person *deletePerson(Person *listHead, char targetName[])
{
	Person *p, *top, *curr;

	top = listHead;
	curr = top;
	if (curr == NULL)
		return NULL;

	if (strcmp(top->name,targetName) == 0)
	{
		top = top->next;
		free(curr);
		return top;
	}
	while (curr->next != NULL && (strcmp(curr->next->name,targetName) != 0))
		curr = curr->next;

	if (curr->next == NULL)
		return NULL;

	p = curr->next;
	curr->next = curr->next->next;
	free(p);
	return top;
}

Person *addLast (char name[], char address[], Person *listHead)
{
	Person *p, *top, *curr;

	top = listHead;

	if ((p = malloc(sizeof(Person))) == NULL)
	{
		fprintf(stderr,"addLast failed to malloc\n");
		return NULL;
	}
	strcpy(p->name,name);
	strcpy(p->address,address);
	p->next = NULL;

	if (top == NULL)
		top = p;
	else
	{
		curr = top;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = p;
	}
	return top;
}


void displayIterative(Person *stk)
{
	Person *p;
	p = stk;
	while (p != NULL)
	{
		printf("name: %s address: %s\n",
			p->name,
			p->address);
		p = p->next;
	}
}


int main(void)
{
	Person *temp, *listhead;

	listhead = NULL;

	listhead = addLast("Rohini","1 Grape St",listhead);
	listhead = addLast("Shama","2 Apple St",listhead);
	listhead = addLast("Neil","3 Grange St",listhead);
	listhead = addLast("Lyn","4 Bear St",listhead);
	listhead = addLast("Cedrick","5 Otter St",listhead);

	displayIterative(listhead);
	printf("\n");
	printf("removing Rohini\n");
	temp = deletePerson(listhead,"Rohini");
	if (temp == NULL)
		printf("NULL: person not in list\n");
	else
	{
		listhead = temp;
		displayIterative(temp);
	}
	printf("removing Neil\n");
	temp = deletePerson(listhead,"Neil");
	if (temp == NULL)
		printf("NULL: person not in list\n");
	else
	{
		listhead = temp;
		displayIterative(temp);
	}
	printf("removing Cedrick\n");
	temp = deletePerson(listhead,"Cedrick");
	if (temp == NULL)
		printf("NULL: person not in list\n");
	else
	{
		listhead = temp;
		displayIterative(temp);
	}

	while (listhead != NULL)
	{
		temp = listhead;
		listhead = listhead->next;
		free(temp);
	}

	return EXIT_SUCCESS;
}
