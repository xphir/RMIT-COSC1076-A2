#include <stdio.h>
#include <string.h>

int main(void){

	char txt[10];
	char target[] = "BINGO";
	char *result;

	printf("Enter a line of up to 9 char of text: ");
	if ((result = fgets(txt,10,stdin)) == NULL)
		printf("\nEOF detected\n");
	else {
		printf("You entered :%s:\n",txt);
		if (strncmp(txt,target,strlen(target)) == 0)
			printf("You read in BINGO !!!\n");
	}
	return 0;
}
