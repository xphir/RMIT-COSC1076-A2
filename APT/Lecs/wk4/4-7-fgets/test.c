#include <stdio.h>
#include <string.h>

int main(void){

	char str[10];
	char *result;

	printf("Enter a line of up to 9 char of text: ");
	if ((result = fgets(str,10,stdin)) == NULL)
		printf("\nEOF detected\n");
	else {
		printf("You entered :%s:\n",str);
		printf("strlen %d\n",(int) strlen(str));
		if (str[strlen(str) - 1] == '\n')
			printf("String was shorter than 9 char\n");
		else
			printf("String was 9 char or greater in length\n");
	}
	return 0;
}
