#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
	if (n <= 1)
		return 1;
	else
		return (n * factorial(n-1));
}

int factorialIterative(int n)
{
	int product = 1;
	for(; n > 1; --n)
		product *= n;

	return product;
}

int main(void)
{
	int n = 5;
	printf("factorial (recursive) of %d is %d\n",
		n,
		factorial(n));
	printf("factorial (iterative) of %d is %d\n",
		n,
		factorialIterative(n));
		
	return EXIT_SUCCESS;
}
