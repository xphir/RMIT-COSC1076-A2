#include <stdio.h>

int main(void){

	int age;
	int *intPointer;
	char grade;
	char *charPointer;

	printf("size of int variable 'age'    %ld, size of intPointer  %ld\n",
		sizeof(age), sizeof(intPointer));
	printf("size of char variable 'grade' %ld, size of charPointer %ld\n",
		sizeof(grade), sizeof(charPointer));

	intPointer = &age;
	charPointer = &grade;

	printf("address of age   %p, address stored in intPointer  %p\n",
		(void*) &age, (void*) intPointer);
	printf("address of grade %p, address stored in charPointer %p\n",
		(void*) &grade, (void*) charPointer);

	age = 21;
	printf("value of 'age':   %d, dereferencing intPointer: %d\n",
		age, *intPointer);

	*charPointer = 'H';
	printf("value of 'grade':  %c, dereferencing charPointer: %c\n",
		grade, *charPointer);

	return 0;
}
