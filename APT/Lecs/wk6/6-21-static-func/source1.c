#include <stdio.h>
#include <stdlib.h>

void func1(void)
{
	printf("this is func1\n");
}

static void func2(void)
{
	printf("this is func2\n");
}

static int count;

void func3(void)
{
	printf("func3 calling func2\n");
	func2();
	count = 8;
	printf("func3 printing count %d\n",count);
}


