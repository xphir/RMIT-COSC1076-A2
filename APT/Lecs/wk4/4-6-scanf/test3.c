#include <stdio.h>

int main(void){

	int num1, num2, num3, readCount;

	printf("Enter 3 integers on the same line: ");
	readCount = scanf("%d %d %d",&num1, &num2, &num3);
	printf("You entered %d %d %d\n",num1,num2,num3);
	printf("readCount was %d\n",readCount);
	return 0;
}
