#include <stdio.h>

int main(void){

	int x,y, *ptr;

	x = 2;
	ptr = &x;
	y = *ptr + 3;
	printf("y is %d\n",y);
	return 0;
}
