#include <stdio.h>

int main(void){

	int *p, *q, age, temp;

	q = &age;
	p = &temp;  /* try compiling without this line! */
	age = 25;
	*p = *q;

	printf("value of '*p': %d\n", *p);

	return 0;
}
