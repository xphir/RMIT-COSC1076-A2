#include <stdio.h>

int main(void){

	int num;
	char txt[10];

	printf("Enter integer: ");
	scanf("%d",&num);
	printf("Enter string: ");
	scanf("%s",txt);
	printf("You entered num %d string :%s:\n",num,txt);
	return 0;
}
