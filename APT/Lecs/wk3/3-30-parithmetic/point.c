#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char c, *pChar;
	int i, *pInt;

	pChar =&c;
	pInt = &i;

	printf("size of c %ld, size of i %ld\n",sizeof(c),sizeof(i));
	printf("address of c %p, address stored in pChar %p\n",
		(void*) &c,
		(void *) pChar);
	printf("address of c %p, address (pChar + 1)     %p\n",
		(void*) &c,
		(void*) (pChar + 1));
	printf("address of i %p, address stored in pInt  %p\n",
		(void*) &i,
		(void *) pInt);
	printf("address of i %p address  (pInt + 1)      %p\n",
		(void*) &i,
		(void*) (pInt + 1));
	return EXIT_SUCCESS;
}

