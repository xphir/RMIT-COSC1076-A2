
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char *argv[])
{
	listType *mylist;
	if ((mylist = createList()) == NULL)
	{
		fprintf(stderr,"Unable to create list\n");
		return EXIT_FAILURE;
	}
	display(mylist);
	insertSorted(mylist,'D');
	display(mylist);
	insertSorted(mylist,'A');
	display(mylist);
	insertSorted(mylist,'B');
	display(mylist);
	insertSorted(mylist,'Z');
	display(mylist);
	insertSorted(mylist,'E');
	display(mylist);
	delete(mylist,'A');
	display(mylist);
	delete(mylist,'Z');
	display(mylist);
	delete(mylist,'D');
	display(mylist);
	reset(mylist);
	display(mylist);
	
    return EXIT_SUCCESS;
}

