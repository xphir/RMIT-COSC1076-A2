#include <stdio.h>
#include <stdlib.h>

/* compile with -g flag, then
 * run with: valgrind --leak-check=full ./a.out
 * */

int main(void)
{
	int *myarray = NULL;
	int size, i;

	printf("What size array would you like? ");
	scanf("%d",&size);
	if ((myarray = calloc(size, sizeof(int))) == NULL)
	{
		fprintf(stderr,"calloc failed\n");
		return EXIT_FAILURE;
	}
	for(i = 0; i < size; i++)
	{
		printf("enter integer for element %d: ",i);
		scanf("%d",&myarray[i]);
	}

	for(i = 0; i < size; i++)
		printf("%d\n",myarray[i]);
	
	myarray = calloc(size, sizeof(int)); 
	free(myarray);

	return EXIT_SUCCESS;
}
