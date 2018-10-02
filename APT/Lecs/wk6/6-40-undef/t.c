#include <stdio.h>
#include <stdlib.h>

#define max(x,y)  (x>y?x:y)

void xyz(void)
{
	int a = 2, b = 5;
	a = max(a,b);
	printf("max was %d\n",a);
}

#undef max

int max(int x, int y)
{
	printf("In function max with x %d and y %d\n",x,y);
}

int main(void)
{
	xyz();
	max(2,5);
	return EXIT_SUCCESS;
}

