#include <stdio.h>
#include <stdlib.h>

static void func4(void)
{
	printf("this is func4\n");
}

void func5(void)
{
	printf("this is func5 calling func4\n");
	func4();
}


