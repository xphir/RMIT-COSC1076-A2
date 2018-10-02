/* Based on ADT Stack p430, "A Book on C", Kelly & Pohl */
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void)
{
	stackType mystack;
	char	  str[] = "COSC1076 Advanced Programming Techniques";
	int	  i;

	reset(&mystack);
	printf("The string: %s\n",str);
	for(i = 0; str[i] != '\0'; i++)
	{
		if (!full(&mystack))
			push(str[i], &mystack);
	}
	printf("From the stack: ");
	while (!empty(&mystack))
		putchar(pop(&mystack));
	putchar('\n');
	return EXIT_SUCCESS;
}
