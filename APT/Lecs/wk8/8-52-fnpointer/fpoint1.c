
#include <stdio.h>
#include <stdlib.h>

	/* compareFn is a new type: a pointer to a function.
	 * The function must have an int return type and take two
	 * int parameters
	 */
typedef int (*compareFn)(int,int);

/* Function that returns 1 if a < b, else returns 0 */
int lessThan(int a, int b)
{
	if (a < b)
		return 1;
	return 0;
}

/* Function that returns 1 if a > b, else returns 0 */
int greaterThan(int a, int b)
{
	if (a > b)
		return 1;
	return 0;
}

int main(int argc, char *argv[])
{
	int choice, result;
		/* fpoint is of type compareFn - i.e. a pointer to a function */
	compareFn fpoint;

    printf("Enter 1 for using function lessThan, 2 for greaterThan: ");
	scanf("%d",&choice);
	switch (choice)
	{
		case 1:
			fpoint = lessThan;
			break;
		case 2:
			fpoint = greaterThan;
			break;
		default:
			return EXIT_FAILURE;
	}

	result = fpoint(9,5);
	printf("result was %d\n",result);
    return 0;
}

