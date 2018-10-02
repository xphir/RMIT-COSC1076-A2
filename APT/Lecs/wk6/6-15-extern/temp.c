#include <stdio.h>

int main(void){
	extern int first, last;

	printf("%d %d\n",first,last);
	return 0;
}

int first = 10, last = 20;
