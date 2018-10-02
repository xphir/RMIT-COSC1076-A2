#include <stdio.h>
#include <stdlib.h>

int naturalSum(int n)
{
printf("doing naturalSum(%d)\n",n);
	if (n == 1)
		return 1;
	else
		return (n + naturalSum(n-1));
}

int main(void)
{
	int n = 4;
	printf("natural sum of %d is %d\n",
		n,
		naturalSum(n));
		
	return EXIT_SUCCESS;
}
