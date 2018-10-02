#include <stdio.h>
#include <string.h>

int main(void){

	char str[10];
	char *result;
	char *token;

	printf("Enter a line of up to 9 char of text: ");
	if ((result = fgets(str,10,stdin)) == NULL)
		printf("\nEOF detected\n");
	else {
		printf("You entered :%s:\n",str);

		token = strtok(str,"/, ");
		while (token != NULL){
			printf(":%s:\n",token);
			token = strtok(NULL,"/, ");
		}
	}

	return 0;
}
