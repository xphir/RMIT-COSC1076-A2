#include <stdio.h>
#include <stdlib.h>

typedef void (*PrintFn)(int,int); /* 'PrintFn' can now be used as a type */

typedef struct coord
{
	PrintFn printfn;
} Coord;

void print1(int x, int y)
{
	printf("function print1 x = %d, y = %d\n",x,y);
}

void print2(int x, int y)
{
	printf("function print2 x = %d, y = %d\n",x,y);
}

int main(void)
{
	Coord *mycoord;
	int num;

	if ((mycoord = malloc(sizeof(Coord))) == NULL)
		return EXIT_FAILURE;

	printf("Which print function to use?\n");
	printf("Enter 1 for print1, 2 for print2\n");
	scanf("%d",&num);
	switch (num)
	{
		case 1: 
			mycoord->printfn = print1;
			break;
		case 2: 
			mycoord->printfn = print2;
			break;
		default:
			return EXIT_FAILURE;
	}
	mycoord->printfn(4,5);
	return EXIT_SUCCESS;
}
