#include <stdio.h>
#include <stdlib.h>

#define QUANTITY 10

#if QUANTITY < 20
	#define SIZE 20
#else
	#define SIZE 200
#endif


int main(void)
{
	printf("%d\n",SIZE);
	return EXIT_SUCCESS;
}

