#include <stdio.h>
#include <stdlib.h>

/*
 * produces a Fibonacci number from the
 * Fibonacci sequence 
 * (0,1,1,2,3,5,8,13,21,34,55,89,144...)
 * F_0 = 0, F_1 = 1 and F_i+1 = F_i + F_i-1
 * For example, F_12 = F_10 + F_9 (i.e. 144 = 89 + 55)
 */

int fib(int n)
{
	if (n <= 1)
		return n;
	else
		return (fib(n-1) + fib(n-2));
}

int main(void)
{
	int n = 12;
	printf("fibonacci number of %d is %d\n",
		n,
		fib(n));
		
	return EXIT_SUCCESS;
}
