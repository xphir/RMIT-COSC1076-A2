#include <stdio.h>
#include <stdlib.h>

typedef void (*printFn)(int,int); 

void print1(int x, int y)
{
	printf("this is print1 with x %d and y %d\n",x,y);
}

void print2(int x, int y)
{
	printf("this is print2 with x %d and y %d\n",x,y);
}


void doprint(printFn myFunct)
{
	int a = 2, b = 3;
	myFunct(a,b);  
}

int main(int argc, char *argv[])
{
   doprint(print1);  
   doprint(print2);
   printf("Bye!\n");
   return 0;
}
