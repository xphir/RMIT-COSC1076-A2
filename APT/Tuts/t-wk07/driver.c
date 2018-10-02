#include <stdio.h>
#include <stdlib.h>

#include "list.h"


/* Not performing user input validation as just showing list ADT */
int main(void)
{
	int num;
	IntList mylist;

	if (!list_init(&mylist))
		return EXIT_FAILURE;
	printf("Enter a sequence of numbers, one per line. Control-D to end\n");
	while (scanf("%d",&num) == 1)
	{
		if (!list_add(&mylist,num))
		{
			fprintf(stderr,"Unable to add to list\n");
			list_delete(&mylist);
			return EXIT_FAILURE;
		}
	}

	printf("List is :");
	list_printList(&mylist);
	list_delete(&mylist);

	return EXIT_SUCCESS;
}
