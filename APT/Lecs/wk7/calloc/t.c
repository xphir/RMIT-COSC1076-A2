#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void)
{
	int *myarray;
	int size, i;

	printf("What size array would you like? ");
	scanf("%d",&size);
	assert((myarray = calloc(size, sizeof(int))) != NULL);
	for(i = 0; i < size; i++)
	{
		printf("enter integer for element %d: ",i);
		scanf("%d",&myarray[i]);
	}

	for(i = 0; i < size; i++)
		printf("%d\n",myarray[i]);
	
	free(myarray);

	return EXIT_SUCCESS;
}
