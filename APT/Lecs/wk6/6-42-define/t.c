#include <stdio.h>
#include <stdlib.h>

#define V1

#ifdef V1
void xyz(void)
{
	printf("version 1 of xyz\n");
}
#else
void xyz(void)
{
	printf("version 2 of xyz\n");
}
#endif


int main(void)
{
	xyz();
	return EXIT_SUCCESS;
}

